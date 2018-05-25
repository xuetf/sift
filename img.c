#include "header.h"

ClImage* clLoadImage(const char* path)
{
	ClImage* bmpImg;
	FILE* pFile;
	unsigned short fileType;
	ClBitMapFileHeader bmpFileHeader;
	ClBitMapInfoHeader bmpInfoHeader;
	int channels = 1;
	int width = 0;
	int height = 0;
	int step = 0;
	int offset = 0;
	unsigned char pixVal;
	ClRgbQuad* quad;
	int i, j, k;

	bmpImg = (ClImage*)malloc(sizeof(ClImage));
	pFile = fopen(path, "rb");
	if (!pFile)
	{
		fclose(pFile);
		free(bmpImg);
		return NULL;
	}

	fread(&fileType, sizeof(unsigned short), 1, pFile);//2
	if (fileType == 0x4D42)
	{
		fread(&bmpFileHeader, sizeof(ClBitMapFileHeader), 1, pFile);//24
		fread(&bmpInfoHeader, sizeof(ClBitMapInfoHeader), 1, pFile);//80
		if (bmpInfoHeader.biBitCount == 8)
		{
			channels = 1;
			width = bmpInfoHeader.biWidth;
			height = bmpInfoHeader.biHeight;
			offset = (channels*width) % 4;
			if (offset != 0)
			{
				offset = 4 - offset;
			}
			bmpImg->width = width;
			bmpImg->height = height;
			bmpImg->channels = 1;
			bmpImg->imageData = (unsigned char*)malloc(sizeof(unsigned char)*width*height);
			step = channels*width;

			quad = (ClRgbQuad*)malloc(sizeof(ClRgbQuad) * 256);
			fread(quad, sizeof(ClRgbQuad), 256, pFile);
			free(quad);

			for (i = 0; i<height; i++)
			{
				for (j = 0; j<width; j++)
				{
					fread(&pixVal, sizeof(unsigned char), 1, pFile);
					bmpImg->imageData[(height - 1 - i)*step + j] = pixVal;
				}
				if (offset != 0)
				{
					for (j = 0; j<offset; j++)
					{
						fread(&pixVal, sizeof(unsigned char), 1, pFile);
					}
				}
			}
		}
		else if (bmpInfoHeader.biBitCount == 24)
		{
			channels = 3;
			width = bmpInfoHeader.biWidth;
			height = bmpInfoHeader.biHeight;

			bmpImg->width = width;
			bmpImg->height = height;
			bmpImg->channels = 3;
			bmpImg->imageData = (unsigned char*)malloc(sizeof(unsigned char)*width * 3 * height);
			step = channels*width;

			offset = (channels*width) % 4;
			if (offset != 0)
			{
				offset = 4 - offset;
			}

			for (i = 0; i<height; i++)
			{
				for (j = 0; j<width; j++)
				{
					for (k = 0; k<3; k++)
					{
						fread(&pixVal, sizeof(unsigned char), 1, pFile);
						bmpImg->imageData[(height - 1 - i)*step + j * 3 + k] = pixVal;
					}
				}
				if (offset != 0)
				{
					for (j = 0; j<offset; j++)
					{
						fread(&pixVal, sizeof(unsigned char), 1, pFile);
					}
				}
			}
		}
	}

	fclose(pFile);
	pFile = NULL;
	return bmpImg;
}
void bmp2Iplimg(const ClImage* bmpImg, IplImage* iplImage)
{
	iplImage->width = bmpImg->width;
	iplImage->height = bmpImg->height;
	iplImage->nChannels = bmpImg->channels;
	memcpy(iplImage->imageData, bmpImg->imageData, iplImage->height*iplImage->widthStep);
}
IplImage* loadImage(const char* path)
{
	ClImage* bmp = clLoadImage(path);
	Size s0;
	s0.width = bmp->width;
	s0.height = bmp->height;
	IplImage* img = createImage(s0, 8, 3);
	bmp2Iplimg(bmp, img);
	return img;
}

int invert(Mat* src, Mat* dst, int n)
{
	int i, j, k;
	double max, temp;
	//double t[N][N];

	double **t;
	t = (double **)malloc(sizeof(double *) * n);//����ָ������
	for (i = 0; i < n; i++)
	{
		t[i] = (double *)malloc(sizeof(double) * n);//����ÿ��ָ����ָ�������
	}
	//��ʱ����  
	//��A����������ʱ����t[n][n]��  
	for (i = 0; i < n; i++)
	{
		//t[i] = (double*)(src->data.ptr + n * src->step);
		for (j = 0; j < n; j++)
		{
			t[i][j] = src->data.db[i*n + j];
		}
	}
	//��ʼ��B����Ϊ��λ��  
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			dst->data.db[i*n + j] = (i == j) ? (float)1 : 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		//Ѱ����Ԫ  
		max = t[i][i];
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		//�����Ԫ�����в��ǵ�i�У������н���  
		if (k != i)
		{
			for (j = 0; j < n; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				//B���潻��  
				temp = dst->data.db[i*n + j];
				dst->data.db[i*n + j] = dst->data.db[k*n + j];
				dst->data.db[k*n + j] = temp;
			}
		}
		//�ж���Ԫ�Ƿ�Ϊ0, ����, �����A�������Ⱦ���,�����������  
		if (t[i][i] == 0)
		{
			//cout << "There is no inverse matrix!";
			for (i = 0; i < n; i++)
			{
				free(t[i]);
			}
			free(t);
			return 0;
		}
		//��ȥA�ĵ�i�г�ȥi������ĸ���Ԫ��  
		temp = t[i][i];
		for (j = 0; j < n; j++)
		{
			t[i][j] = t[i][j] / temp;        //���Խ����ϵ�Ԫ�ر�Ϊ1  
			dst->data.db[i*n + j] = dst->data.db[i*n + j] / temp;        //�������  
		}
		for (j = 0; j < n; j++)        //��0��->��n��  
		{
			if (j != i)                //���ǵ�i��  
			{
				temp = t[j][i];
				for (k = 0; k < n; k++)        //��j��Ԫ�� - i��Ԫ��*j��i��Ԫ��  
				{
					t[j][k] = t[j][k] - t[i][k] * temp;
					dst->data.db[j*n + k] = dst->data.db[j*n + k] - dst->data.db[i*n + k] * temp;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		free(t[i]);
	}
	free(t);
	return 1;
}
void imgSub(IplImage* src1, IplImage* src2, IplImage* dst0)
{
	float* src1Data = src1->imageData;	//���ݵ���ʼ��ַ
	float* src2Data = src2->imageData;
	float* dst0Data = dst0->imageData;

	int width = src1->width;				//ͼ����г��ȣ������ٸ��ֽ�
	int height = src1->height;
	int i, tmp;
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			i = row*width + col;
			dst0Data[i] = src1Data[i] > src2Data[i] ? src1Data[i] - src2Data[i] : src2Data[i] - src1Data[i];
		}
	}
}
void resizeImg(IplImage* src, IplImage* dst)
{
	float* srcData = src->imageData;	//���ݵ���ʼ��ַ
	float* dstData = dst->imageData;

	int srcStep = src->width;				//ͼ����г��ȣ������ٸ��ֽ�
	int dstStep = dst->width;

	float fw = (float)src->width / dst->width;
	float fh = (float)src->height / dst->height;
	for (int row = 0; row < dst->height; row++)
	{
		for (int col = 0; col < dst->width; col++)
		{
			dstData[row*dstStep + col] = srcData[(int)(row*fh)*srcStep + (int)(col*fw )];
		}
	}
}
IplImage* rgb2gray(const IplImage* src)
{
	Size s;
	s.height = src->height;
	s.width = src->width;
	IplImage* dst = createImage(s, 8, 1);
	uchar* srcData = (uchar*)src->imageData;	//���ݵ���ʼ��ַ
	uchar* dstData = (uchar*)dst->imageData;

	int srcStep = src->widthStep;				//ͼ����г��ȣ������ٸ��ֽ�
	int dstStep = dst->widthStep;

	for (int row = 0; row < dst->height; row++)
	{
		for (int col = 0; col < dst->width; col++)
		{
			dstData[row*dstStep + col] = (int)(
				srcData[row*srcStep + col * 3 + 0] * 0.114 + 
				srcData[row*srcStep + col * 3 + 1] * 0.587 + 
				srcData[row*srcStep + col * 3 + 2] * 0.299);
		}
	}
	return dst;
}
int iround(double value)
{
	return (int)(value + (value >= 0 ? 0.5 : -0.5));
}
void convertScale(IplImage* gray8, IplImage* gray32, float alpha)
{
	uchar* srcData = (uchar*)gray8->imageData;//���ݵ���ʼ��ַ
	float* dstData = (float*)gray32->imageData;

	int width = gray8->width;//ͼ����г��ȣ������ٸ��ֽ�
	int height = gray8->height;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			dstData[row*width + col] = srcData[row*width + col] * alpha;
		}
	}
}
void mSet(Mat* mat, int row, int col, double value)
{
	int type;
	type = CV_MAT_TYPE(mat->type);
	if ((unsigned)row >= (unsigned)mat->rows || (unsigned)col >= (unsigned)mat->cols)
		return;

	if (type == CV_32FC1)
		((float*)(void*)(mat->data.ptr + (size_t)mat->step*row))[col] = (float)value;
	else
	{
		if (type != CV_64FC1)
			return;
		((double*)(void*)(mat->data.ptr + (size_t)mat->step*row))[col] = value;
	}
}
char* getSeqElem(const Seq *seq, int index)
{
	SeqBlock *block;
	int count, total = seq->total;

	if ((unsigned)index >= (unsigned)total)
	{
		index += index < 0 ? total : 0;
		index -= index >= total ? total : 0;
		if ((unsigned)index >= (unsigned)total)
			return 0;
	}

	block = seq->first;
	if (index + index <= total)
	{
		while (index >= (count = block->count))
		{
			block = block->next;
			index -= count;
		}
	}
	else
	{
		do
		{
			block = block->prev;
			total -= block->count;
		} while (index < total);
		index -= total;
	}

	return block->data + index * seq->elem_size;
}
void GEMM(const Mat* src1, const Mat* src2, double alpha, Mat* dst0, int tABC)
{
	double a, b;
	for (int i = 0; i < dst0->rows; i++)
	{
		for (int j = 0; j < dst0->cols; j++)
		{
			dst0->data.db[i*dst0->cols + j] = 0.0;
			for (int k = 0; k < src2->rows; k++)
			{
				{
					a = src1->data.db[i*src1->rows + k];
					b = src2->data.db[k*src2->cols + j];
					dst0->data.db[i*dst0->cols + j] += alpha*a*b;
				}
			}
		}
	}
}
int iceil(double value)
{
	int i = iround(value);
	float diff = (float)(i - value);
	return i + (diff < 0);
}
int ifloor(double value)
{
	int i = iround(value);
	float diff = (float)(value - i);
	return i - (diff < 0);
}
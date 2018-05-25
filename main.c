#include "header.h"

void match()
{
	IplImage* img1, *img2, *stacked;
	Feature* feat1, *feat2, *feat;
	Feature** nbrs;
	KdNode* kd_root;
	Point pt1, pt2;
	double d0, d1;
	char* bmp1, *bmp2;
	int n1, n2, k, i, m = 0;
	img1 = loadImage("/Users/xuetf/workspace/c-workspace/sift2/finalmatch/img/3.bmp");
	img2 = loadImage("/Users/xuetf/workspace/c-workspace/sift2/finalmatch/img/33.bmp");
	//stacked = stack_imgs(img1, img2);
	
	n1 = sift_features(img1, &feat1);
	n2 = sift_features(img2, &feat2);

	kd_root = kdtree_build(feat2, n2);
	for (i = 0; i < n1; i++)
	{
		feat = feat1 + i;
		k = kdtree_bbf_knn(kd_root, feat, 2, &nbrs, KDTREE_BBF_MAX_NN_CHKS);
		if (k == 2)
		{
			d0 = descr_dist_sq(feat, nbrs[0]);
			d1 = descr_dist_sq(feat, nbrs[1]);
			if (d0 < d1 * NN_SQ_DIST_RATIO_THR)
			{
				pt1 = ipoint(iround(feat->x), iround(feat->y));
				pt2 = ipoint(iround(nbrs[0]->x), iround(nbrs[0]->y));
				pt2.y += img1->height;
				//cvLine(stacked, pt1, pt2, CV_RGB(255, 0, 255), 1, 8, 0);
				m++;
				feat1[i].fwd_match = nbrs[0];
			}
		}
		free(nbrs);
	}
	printf("n1=%d n2=%d mt = %d\n\n", n1, n2, m);

	//cvShowImage("s",stacked);
	//cvWaitKey(0);
	//releaseImage(&stacked);
	releaseImage(&img1);
	releaseImage(&img2);
	kdtree_release(kd_root);
	free(feat1);
	free(feat2);
}
int main(int argc, char** argv)
{
	match();
	while (1);
	return 0;
}

/*****************************************************
 * usage:<BMP file><r output><g output><b output><copy file>
 *****************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef unsigned char BYTE;

typedef struct tagBITMAPFILEHEADER
{
	WORD bfType; // 位图文件的类型，必须为BM(0-1字节）
	DWORD bfSize;  // 位图文件的大小，以字节为单位（2-5字节）
	WORD bfReserved1;  // 位图文件保留字，必须为0(6-7字节）
	WORD bfReserved2;  // 位图文件保留字，必须为0(8-9字节）
	DWORD bfOffBits;  // 位图数据的起始位置（10-13字节），以相对于
	// 位图文件头的偏移量表示，以字节为单位
} BITMAPFILEHEADER;


typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;  // 本结构所占用字节数（14-17字节）
	DWORD biWidth;  // 位图的宽度，以像素为单位（18-21字节）
	DWORD biHeight;  // 位图的高度，以像素为单位（22-25字节）
	WORD biPlanes;  // 目标设备的级别，必须为1(26-27字节）
	WORD biBitCount;  // 每个像素所需的位数，必须是1（双色），（28-29字节）
	// 4(16色），8(256色）或24（真彩色）之一
	DWORD biCompression;  // 位图压缩类型，必须是 0（不压缩），（30-33字节）
	// 1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
	DWORD biSizeImage;  // 位图的大小，以字节为单位（34-37字节）
	DWORD biXPelsPerMeter;  // 位图水平分辨率，每米像素数（38-41字节）
	DWORD biYPelsPerMeter;  // 位图垂直分辨率，每米像素数（42-45字节)
	DWORD biClrUsed;  // 位图实际使用的颜色表中的颜色数（46-49字节） 设为0的话，则说明使用所有调色板项，即2 biBitCount种颜色
	DWORD biClrImportant; // 位图显示过程中重要的颜色数（50-53字节）
}BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
	BYTE rgbBlue; // 蓝色的亮度（值范围为0-255)
	BYTE rgbGreen;  // 绿色的亮度（值范围为0-255)
	BYTE rgbRed;  // 红色的亮度（值范围为0-255)
	BYTE rgbReserved; // 保留字，必须为0
} RGBQUAD;
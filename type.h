#ifndef _CV_H_
#define _CV_H_
#define UNIX
#include "def.h"

enum feature_type
{
	FEATURE_LOWE=1
};
typedef unsigned char uchar;
typedef long long int64;

typedef struct Mat
{
	int type;
	int step;

	/* for internal use only */
	int* refcount;
	int hdr_refcount;

	union
	{
		uchar* ptr;
		double* db;
	} data;
	int rows;
	int cols;
}Mat;

typedef struct MatND
{
	int type;
	int dims;

	int* refcount;
	int hdr_refcount;

	uchar* data;

	struct
	{
		int size;
		int step;
	}dim[CV_MAX_DIM];
}MatND;

typedef struct Rect
{
	int x;
	int y;
	int width;
	int height;
}Rect;

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Size
{
	int width;
	int height;
}Size;

typedef struct MemBlock
{
	struct MemBlock*  prev;
	struct MemBlock*  next;
}MemBlock;

typedef struct MemStorage
{
	int signature;
	MemBlock* bottom;           /**< First allocated block.                   */
	MemBlock* top;              /**< Current memory block - top of the stack. */
	struct  MemStorage* parent; /**< We get new blocks from parent as needed. */
	int block_size;               /**< Block size.                              */
	int free_space;               /**< Remaining free space in current block.   */
}MemStorage;

typedef struct MemStoragePos
{
	MemBlock* top;
	int free_space;
}MemStoragePos;

typedef struct SeqBlock
{
	struct SeqBlock*  prev; /**< Previous sequence block.                   */
	struct SeqBlock*  next; /**< Next sequence block.                       */
	int    start_index;         /**< Index of the first element in the block +  */
	/**< sequence->first->start_index.              */
	int    count;             /**< Number of elements in the block.           */
	char* data;              /**< Pointer to the first element of the block. */
}SeqBlock;

typedef struct Seq
{
	int       flags;
	int       header_size;
	struct    Seq* h_prev;
	struct    Seq* h_next;
	struct    Seq* v_prev;
	struct    Seq* v_next;
	int       total;
	int       elem_size;
	char*    block_max;
	char*    ptr;
	int       delta_elems;
	MemStorage* storage;
	SeqBlock* free_blocks;
	SeqBlock* first;
}Seq;

typedef struct SeqReader
{
	int			header_size;											
	Seq*		seq;        /**< sequence, beign read */				
	SeqBlock*	block;      /**< current block */						
	char*       ptr;        /**< pointer to element be read next */		
	char*       block_min;  /**< pointer to the beginning of block */	
	char*       block_max;  /**< pointer to the end of block */			
	int			delta_index;/**< = seq->first->start_index   */
	char*       prev_elem;  /**< pointer to previous element */
}SeqReader;

typedef struct SeqReaderPos
{
	SeqBlock* block;
	char* ptr;
	char* block_min;
	char* block_max;
}SeqReaderPos;

/** holds feature data relevant to detection */
typedef struct detection_data
{
	int r;
	int c;
	int octv;
	int intvl;
	double subintvl;
	double scl_octv;
}DetectionData;

/** an element in a minimizing priority queue */
typedef struct pqnode
{
	void* data;
	int key;
}PqNode;

/** a minimizing priority queue */
typedef struct minpq
{
	PqNode* pq_array;    /* array containing priority queue */
	int nallocd;                 /* number of elements allocated */
	int n;                       /**< number of elements in pq */
}MinPq;



typedef struct Point2D64f
{
	double x;
	double y;
}Point2D64f;

typedef struct feature
{
	double x;                      /**< x coord */
	double y;                      /**< y coord */
	double a;                      /**< Oxford-type affine region parameter */
	double b;                      /**< Oxford-type affine region parameter */
	double c;                      /**< Oxford-type affine region parameter */
	double scl;                    /**< scale of a Lowe-style feature */
	double ori;                    /**< orientation of a Lowe-style feature */
	int d;                         /**< descriptor length */
	double descr[FEATURE_MAX_D];   /**< descriptor */
	int type;                      /**< feature type, OXFD or LOWE */
	int category;                  /**< all-purpose feature category */
	struct feature* fwd_match;     /**< matching feature from forward image */
	struct feature* bck_match;     /**< matching feature from backmward image */
	struct feature* mdl_match;     /**< matching feature from model */
	Point2D64f img_pt;           /**< location in image */
	Point2D64f mdl_pt;           /**< location in model */
	void* feature_data;            /**< user-definable data */
}Feature;

typedef struct kdnode
{
	int ki;                      /**< partition key index */
	double kv;                   /**< partition key value */
	int leaf;                    /**< 1 if node is a leaf, 0 otherwise */
	Feature* features;    /**< features at this node */
	int n;                       /**< number of features */
	struct kd_node* kd_left;     /**< left child */
	struct kd_node* kd_right;    /**< right child */
}KdNode;
typedef struct bbfdata
{
	double d;
	void* oldData;
}BbfData;



typedef unsigned char BYTE;  // 1字节
typedef unsigned short WORD;   //2字节

#ifdef UNIX
typedef unsigned int DWORD; // 4字节， unsigned long in window is 4, in mac is 8
#endif

#ifdef WIN
typedef unsigned long DWORD; // unsigned long in window is 4
#endif


typedef struct
{
	//WORD bfType;// 位图文件的类型，必须为BM(0-1字节）
	DWORD	bfSize; //// 位图文件的大小，以字节为单位（2-5字节,unsigned long
	WORD	bfReserved1; //位图文件保留字，必须为0(6-7字节,unsigned short
	WORD	bfReserved2; //位图文件保留字，必须为0(8-9字节,unsigned short
	DWORD	bfOffBits;
}ClBitMapFileHeader;

typedef struct
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
}ClBitMapInfoHeader;

typedef struct
{
	BYTE rgbBlue; // 蓝色的亮度（值范围为0-255)
	BYTE rgbGreen;  // 绿色的亮度（值范围为0-255)
	BYTE rgbRed;  // 红色的亮度（值范围为0-255)
	BYTE rgbReserved; // 保留字，必须为0
}ClRgbQuad;

typedef struct
{
	int width;
	int height;
	int channels;
	unsigned char* imageData;
}ClImage;

typedef struct _IplTileInfo IplTileInfo;

typedef struct _IplROI
{
	int  coi; /**< 0 - no COI (all channels are selected), 1 - 0th channel is selected ...*/
	int  xOffset;
	int  yOffset;
	int  width;
	int  height;
}IplROI;
typedef struct _IplImage
{
	int  nSize;             /**< sizeof(IplImage) */
	int  ID;                /**< version (=0)*/
	int  nChannels;         /**< Most of OpenCV functions support 1,2,3 or 4 channels */
	int  alphaChannel;      /**< Ignored by OpenCV */
	int  depth;             /**< Pixel depth in bits: IPL_DEPTH_8U, IPL_DEPTH_8S, IPL_DEPTH_16S,
							IPL_DEPTH_32S, IPL_DEPTH_32F and IPL_DEPTH_64F are supported.  */
	char colorModel[4];     /**< Ignored by OpenCV */
	char channelSeq[4];     /**< ditto */
	int  dataOrder;         /**< 0 - interleaved color channels, 1 - separate color channels.
							cvCreateImage can only create interleaved images */
	int  origin;            /**< 0 - top-left origin,
							1 - bottom-left origin (Windows bitmaps style).  */
	int  align;             /**< Alignment of image rows (4 or 8).
							OpenCV ignores it and uses widthStep instead.    */
	int  width;             /**< Image width in pixels.                           */
	int  height;            /**< Image height in pixels.                          */
	struct _IplROI *roi;    /**< Image ROI. If NULL, the whole image is selected. */
	struct _IplImage *maskROI;      /**< Must be NULL. */
	void  *imageId;                 /**< "           " */
	struct _IplTileInfo *tileInfo;  /**< "           " */
	int  imageSize;         /**< Image data size in bytes
							(==image->height*image->widthStep
							in case of interleaved data)*/
	char *imageData;        /**< Pointer to aligned image data.         */
	int  widthStep;         /**< Size of aligned image row in bytes.    */
	int  BorderMode[4];     /**< Ignored by OpenCV.                     */
	int  BorderConst[4];    /**< Ditto.                                 */
	char *imageDataOrigin;  /**< Pointer to very origin of image data
							(not necessarily aligned) -
							needed for correct deallocation */
}IplImage;
typedef struct Slice
{
	int  start_index, end_index;
}Slice;
typedef IplImage* (*Cv_iplCreateImageHeader)(int, int, int, char*, char*, int, int, int, int, int, IplROI*, IplImage*, void*, IplTileInfo*);
typedef void(*Cv_iplAllocateImageData)(IplImage*, int, int);
typedef void(*Cv_iplDeallocate)(IplImage*, int);
typedef IplROI* (*Cv_iplCreateROI)(int, int, int, int, int);
typedef IplImage* (*Cv_iplCloneImage)(const IplImage*);

static struct
{
	Cv_iplCreateImageHeader  createHeader;
	Cv_iplAllocateImageData  allocateData;
	Cv_iplDeallocate  deallocate;
	Cv_iplCreateROI  createROI;
	Cv_iplCloneImage  cloneImage;
}IPL;


typedef int(*CmpFunc)(const void* a, const void* b, void* userdata);
#endif 
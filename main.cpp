#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "EdgeDetection.h"//확장자가 다르다는 것을 알려줘야함 매크로로 정의?를 하면됨

#include <typeinfo>

//#include "EdgeDetection.h"
// yuv가 input인가...? 그럼 거기서 y field만 받는 방법은.....
using namespace std;
using namespace cv;

int main(void) {

	int ret = 0; 
	// read bmp file in gray scale
	Mat image = imread("D:\cat.bmp", 0);
	//Mat outimage = Mat(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC1); //
	// 
	//unsigned char outimage[IMAGEHEIGHT * IMAGEWIDTH] = { 0 }; //????
	// 
	//int width = image.cols;
	//int height = image.rows;

	//cout << typeid(outimage).name()  << endl; //unsigned char
	//cout << sizeof(outimage) << endl;		//IMAGEWIDTH * IMAGEHEIGHT
	uchar* img_data = image.data;
	//uchar* outimage = outimage.data;
	unsigned char inputimage[] = { 0, };


	//MAT to char array
	int bpp = image.channels();
	int imagesize = IMAGEWIDTH * IMAGEHEIGHT * bpp;
	//unsigned char* buffer = new unsigned char[imagesize];
	//memcpy(buffer, image.data, imagesize);

	//put image.data into uchar buffer without memcpy
	unsigned char* buffer = image.data;
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			buffer[row * IMAGEWIDTH + col] = image.data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			//printf("\t %d", inputimage);
		}
		//cout << "\n" << endl;
	}
	

	if (buffer == NULL) return -1;

	//unsigned char* outimage = EdgeDetect(buffer);
	unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT];
	//EdgeDetect(buffer, outimage);
	EdgeDetect(buffer, outimage);
	cout << typeid(image.data).name()<<"\n"; //image.data : unsigned char * __ptr64
	//cout << typeid(outimage.data).name() << "\n";  //outimage.data : unsigned char * __ptr64
	cout << sizeof(image.data) << "\n"; //8

	 
#if 0	 
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			unsigned char inputimage = img_data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			printf("\t %d", inputimage);
		}
		cout << "\n" << endl;
	}


	//Check the buffer
	cout << typeid(buffer).name() << "\n"; //unsigned char * __ptr64
	cout << sizeof(buffer) << "\n";   //8
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			
			printf("\t %c", buffer);
		}
		cout << "\n" << endl;
	}
	
	//pixel값을 unsigned char에 담아서? argument로 주기...
	int cnt = 1;
	uchar* pt = image.data;
	unsigned char imagepixel[600*754] = {0};

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			imagepixel[width * y + x] = *pt++;

		}
	}
	//unsigned char outputimage[IMAGEWIDTH * IMAGEHEIGHT] =  
	//EdgeDetect(image.data, outimage.data);
	//EdgeDetect(inputimage, outimage.data);
	//EdgeDetect(buffer, outimage);
	//cout << sizeof(imagepixel) << "\n";

	//1)	unsigned char output[] = EdgeDetect(inputimage)
	//2)  EdgeDetect(inputimage[], output[])
	//	2-1) void
	//	2-2) intype ::::   ret = EdgeDetect
#endif
	//EdgeDetect(buffer, outimage);
	//
	/*namedWindow("image");
	imshow("outputimage", outimage);*/
	 
	//EdgeDetection process
	// 
	//outimage = EdgeDetect(buffer);


	// show the result in window
	//namedWindow("outimage");
	//imshow("outimage", outimage);

	


	//buffer to MAT
	Mat outbuffer(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC1);
	//outbuffer.data = outimage;
	//memcpy(outbuffer.data, outimage, imagesize); //destination, source엔 class가 들어갈 수 없음
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			outbuffer.data[row * IMAGEWIDTH + col] = outimage[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			//printf("\t %d", inputimage);
		}
		//cout << "\n" << endl;
	}
	imshow("outbuffer", outbuffer);
	waitKey(0);


	

	return 0;
}


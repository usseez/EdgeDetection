#pragma once
#ifndef EDGEDETECT_H //header¿Ã∏ß_H
#define EDGEDETECT_H
#define IMAGEWIDTH 640
#define IMAGEHEIGHT 754

#ifdef __cplusplus 
		extern"C" {
#endif

	extern void EdgeDetect(unsigned char* image, unsigned char* outimage);

#ifdef __cplusplus

		} /*end of the 'externC' block*/
#endif


//extern int EdgeDetect(unsigned char image[IMAGEWIDTH * IMAGEHEIGHT], unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT]);
//extern void EdgeDetect(unsigned char *image, unsigned char *outimage);




#endif	// EDGEDETECT_H
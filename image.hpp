#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <sstream>


#define WIDTHBYTES(bits) (((bits) +31)/32*4)

typedef struct tagRGB{
  int rgbBlue;
  int rgbGreen;
  int rgbRed;
}Rgb;

class Image{
  private:
  BITMAPFILEHEADER fh;

  BITMAPINFOHEADER ih;
  RGBQUAD* rgb;
  BYTE* file=NULL;
  int size;
  int rgbquad;

  public:
  Image(char * filename);
  int isRunning();
  int printImage();
  int filterGrey();
  int filterGreySmall();
  friend Image operator+(Image img, int a);
  friend Image operator+(Image img, Rgb rgb);
  int sepia();
  int threshold();
  int printMatrix();
};

int power(int base, int p);
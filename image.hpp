#include <windows.h>
#include <stdio.h>
#include <stdint.h>

#define WIDTHBYTES(bits) (((bits) +31)/32*4)

class Image{
  private:
  BITMAPFILEHEADER fh;

  BITMAPINFOHEADER ih;
  RGBQUAD* rgb;
  BYTE* file=NULL;
  int size;
  int rwsize;

  public:
  Image(char * filename);
  int isRunning();
  int printImage();
  int filterGrey();
  //friend Image operator+(Image i, RGBQUAD rgb);
};

int power(int base, int p);
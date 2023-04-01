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
  int rgbquad;

  public:
  Image(char * filename);
  int isRunning();
  int printImage();
  int filterGrey();
  int filterGreySmall();
};

int power(int base, int p);
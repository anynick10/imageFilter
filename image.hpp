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
  friend Image operator+(Image img, int a);
  friend Image operator+(Image img, RGBQUAD rgb);
};

int power(int base, int p);
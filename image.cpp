#include "image.hpp"

int power(int base, int p){
  for(int i=0; i<p; i++){
    base*=p;
  }
  return base;
}

Image::Image(char * filename){
  FILE * fp = fopen(filename, "rb");
  if(fp==NULL){
    fclose(fp);
  }
  else{
    fread(&fh, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&ih, sizeof(BITMAPINFOHEADER), 1, fp);

    int rgbquad = power(2, ih.biBitCount);
    this->rgb = new RGBQUAD[rgbquad]();

    fread(rgb, sizeof(RGBQUAD), rgbquad, fp);

    size=ih.biWidth * ih.biHeight*3;

    file = (BYTE*)malloc(sizeof(BYTE)*size);
    fread(file, sizeof(BYTE), size, fp);
    printf("%d", (int)feof(fp));
    fclose(fp);

    rwsize = WIDTHBYTES(ih.biBitCount * ih.biWidth);
    Image::printImage();
  }
}

int Image::isRunning(){
  return ((this->file == NULL) ? 0:1);
}

int Image::printImage(){
  FILE * outFile = fopen("output.bmp", "wb");
  fwrite(&fh, sizeof(BITMAPFILEHEADER), 1, outFile);
  fwrite(&ih, sizeof(BITMAPINFOHEADER), 1, outFile);
  fwrite(rgb, sizeof(RGBQUAD), power(2, ih.biBitCount), outFile);

  fwrite(file, sizeof(BYTE), size, outFile);
  fclose(outFile);

  return 0;
}

int Image::filterGrey(){
  for(int i=0; i<ih.biHeight; i++){
    for(int j=0; j<ih.biWidth*3; j+=3){
      file[i*ih.biWidth*3 + j] = file[i*ih.biWidth*3 + j + 1] = file[i*ih.biWidth*3 + j + 2] = file[i*ih.biWidth*3 + j]*0.0722 + file[i*ih.biWidth*3 + j + 1]*0.7152  + file[i*ih.biWidth*3 + j + 2]*0.2126; // YCrCb방식
    }
  }
  return 0;
}
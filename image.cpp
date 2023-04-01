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

    rgbquad = power(ih.biBitCount, 2);
    this->rgb = new RGBQUAD[rgbquad]();

    fread(rgb, sizeof(RGBQUAD), rgbquad, fp);

    size=ih.biWidth * ih.biHeight*3;

    file = (BYTE*)malloc(sizeof(BYTE)*size);
    fread(file, sizeof(BYTE), size, fp);
    fclose(fp);
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
  fwrite(rgb, sizeof(RGBQUAD), rgbquad, outFile);

  fwrite(file, sizeof(BYTE), size, outFile);
  fclose(outFile);

  return 0;
}

int Image::filterGrey(){
  if(ih.biBitCount<=8){
    return 1;
  }
  for(int i=0; i<ih.biHeight; i++){
    for(int j=0; j<ih.biWidth*3; j+=3){
      file[i*ih.biWidth*3 + j] = file[i*ih.biWidth*3 + j + 1] = file[i*ih.biWidth*3 + j + 2] = file[i*ih.biWidth*3 + j]*0.0722 + file[i*ih.biWidth*3 + j + 1]*0.7152  + file[i*ih.biWidth*3 + j + 2]*0.2126; // YCrCb방식
    }
  }
  return 0;
}

Image operator+(Image img, int a){
  for(int i=0; i<img.ih.biHeight*3; i++){
    for(int j=0; j<img.ih.biWidth; j++){
      img.file[i*img.ih.biWidth + j] = (255-img.file[i*img.ih.biWidth + j]>a) ? img.file[i*img.ih.biWidth + j]+a : 255;
    }
  }
  return img;
}

Image operator+(Image img, RGBQUAD rgb){
  for(int i=0; i<img.ih.biHeight; i++){
    for(int j=0; j<img.ih.biWidth*3; j+=3){
      img.file[i*img.ih.biWidth*3 + j] = (255-img.file[i*img.ih.biWidth*3 + j]>rgb.rgbBlue) ? img.file[i*img.ih.biWidth*3 + j]+rgb.rgbBlue : 255;

      img.file[i*img.ih.biWidth*3 + j + 1] = (255-img.file[i*img.ih.biWidth*3 + j+1]>rgb.rgbGreen) ? img.file[i*img.ih.biWidth*3 + j+1]+rgb.rgbGreen : 255;

      img.file[i*img.ih.biWidth*3 + j + 2] = (255-img.file[i*img.ih.biWidth*3 + j+2]>rgb.rgbRed) ? img.file[i*img.ih.biWidth*3 + j+2]+rgb.rgbRed : 255;
    }
  }
  return img;
}
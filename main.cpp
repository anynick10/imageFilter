#include "image.hpp"
#include <iostream>

int main(int argc, char* argv[]){
  std::cout << "Filter BMP" << std::endl;
  std::cout << "open lena.bmp" << std::endl;

  Image lena((char*)"lena.bmp");
  lena.filterGrey();
  if(lena.isRunning()){
    lena.printImage();
    std::cout << "Success";
  }else{
    std::cout << "Error";
  }
  return 0;
}
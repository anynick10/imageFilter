#include "image.hpp"
#include <iostream>

int main(int argc, char* argv[]){
  int type;

  std::cout << "Filter BMP" << std::endl;
  std::cout << "Open lena.bmp" << std::endl;

  Image lena((char*)"lena.bmp");


  if(lena.isRunning()){
    std::cout << "Filter type" << std::endl << "1: grey" << std::endl << "(1~1):";
    std::cin >> type;
    if(type==1){
      lena.filterGrey();
      std::cout << "Proceeding" << std::endl;
      lena.printImage();
    }else{
      std::cout << "Undefined";
      return 0;
    }
    std::cout << "Success";
  }else{
    std::cout << "Error";
  }
  return 0;
}
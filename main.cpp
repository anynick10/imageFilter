#include "image.hpp"
#include <iostream>

int main(int argc, char* argv[]){
  int type;
  char filename[256];

  std::cout << "Filter BITMAP" << std::endl;
  std::cout << "Image name:";
  std::cin >> filename;
  Image lena(filename);


  if(lena.isRunning()){
    std::cout << "Filter type" << std::endl << "1: grey" << std::endl << "(1~1):";
    std::cin >> type;
    if(type==1){
      if(!lena.filterGrey()){
        std::cout << "Proceeding" << std::endl;
        lena.printImage();
      }
      else{
        std::cout << "Failed. It is too small.";
        return 0;
      }
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
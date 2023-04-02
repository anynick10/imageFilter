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
    std::cout << "Filter type" << std::endl << "1: grey" << std::endl << "2: int multipul" << std::endl << "3: rgb multipul" << std::endl << "4: sepia" << std::endl << "5: threshold" << std::endl << "(1~5):";
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
    }else if(type == 2){
      std::cout << "how much(int):";
      int k;
      std::cin >> k;
      lena = lena+k;
      std::cout << "Proceeding" << std::endl;
      lena.printImage();
    }else if(type == 3){
      int r,g,b;
      std::cout << "how much(int)R:";
      std::cin >> r;

      std::cout << "how much(int)G:";
      std::cin >> g;

      std::cout << "how much(int)B:";
      std::cin >> b;
      Rgb rgb = {b,g,r};

      lena = lena+rgb;
      std::cout << "Proceeding" << std::endl;
      lena.printImage();
    }else if(type == 4){
      if(!lena.sepia()){
        std::cout << "Proceeding" << std::endl;
        lena.printImage();
      }
      else{
        std::cout << "Failed. It is too small.";
        return 0;
      }
    }else if(type==5){
      if(!lena.threshold()){
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
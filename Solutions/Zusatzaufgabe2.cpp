#include <iostream>
#include "windowRasterized.hpp"
#include <iostream>
#include <random>
#include <string>
#include "bigInt.h"

BigInt::Rossi pascal[513][512];
BigInt::Rossi BigIntNull(0);
int main(int argc, char** argv){

    for(int i = 0; i < 513; i++){
        for(int j = 0; j < 512; j++){
            pascal[i][j] = BigIntNull;
        }
    }
    pascal[0][1] = BigInt::Rossi(1);

    for(int i = 1; i < 513; i++){
        for(int j = 1; j < 512; j++){
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }

    std::string imagePath;
    std::string LUT_path;
    if (argc < 3) {
        std::cout << "Usage for custom images/LUT's:\n1. console parameter: full iamge path\n2. console parameter: full *.pal path\n\n\n";

        imagePath = CHAOS_FILE_PATH;
        imagePath += "x1.png";

        LUT_path = CHAOS_FILE_PATH;
        LUT_path += "Mandel.pal";
    }
    else {
        imagePath = argv[1];
        LUT_path = argv[2];
    }

// read image and LUT file
    cf::WindowRasterized image(513, 512, "Zusatzaufgabe b (mod 10)", cf::Color::RED);

    // transform image into pseudo color image
     for (int y = 0; y < image.getHeight(); ++y){
        for (int x = 0; x < image.getHeight(); ++x){
            image.setColor(x, y, cf::Color::RED);
        }
     }

     BigInt::Rossi mod(10);
     for(int i = 1; i < 513; i++){
         for(int j = 1; j < 512; j++){
             if((pascal[i][j] % mod) == BigIntNull) {
                image.setColor(i, j, cf::Color::BLACK);
             }
         }
     }

    // scale image on function call "show", this has no effect on width/height/pixel of the actual image
    image.show();

    image.waitKey();
}

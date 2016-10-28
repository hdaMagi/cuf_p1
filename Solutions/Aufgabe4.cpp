#include <iostream>
#include "windowRasterized.hpp"
#include <iostream>
#include <random>
#include <string>

#define EXTENDED 0


int pascal[513][512];
int main(int argc, char** argv){
    std::string LUT_path = "/home/jannis/workspace_chaos_und_fraktale/chaos_files/Multcol.pal";

#if EXTENDED
//    printf("PATH: %s", LUT_path);
    std::vector<cf::Color> LUT = cf::readPaletteFromFile( "/home/jannis/workspace_chaos_und_fraktale/chaos_files/Multcol4.pal");
#endif
// read image and LUT file
    cf::WindowRasterized image(512, 512, "bla", cf::Color::BLACK);


     for(int i = 1; i < 513; i++){
         for(int j = 1; j < 512; j++){
#if !EXTENDED
             if((i & j) == 0)
             image.setColor(i, j, cf::Color::RED);

#else
                 image.setColor(i, j, LUT.at((i & j)%256));
#endif
}
     }
    image.show();

    image.waitKey();

}

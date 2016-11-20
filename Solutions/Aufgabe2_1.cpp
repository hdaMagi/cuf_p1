
#include "IFS.h"
#include "windowRasterized.hpp"
#include "windowVercorized.hpp"


int main(int argc, char** argv) {
    // receive file name/path
    std::string filePath;
    if (argc < 2){
        std::cout << "Please provide a .ifs file, if you want a different ifs file\n\n\n";
        filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files
        filePath += "Sierpinski.ifs";
    }
    else
        filePath = argv[1];

    // create IFS object
    // and read *.ifs file
    cf::IteratedFunctionSystem ifs; // alternative:    cf::IFS ifs;
    ifs.read(filePath);

    // output all parsed data of IFS file
    std::string align = " :  ";
    std::cout << "Name"               << align << ifs.getName()               << '\n'
              << "Num transformation" << align << ifs.getNumTransformations() << '\n'
              << "Interval X min"     << align << ifs.getRangeX().min         << '\n'
              << "Interval X max"     << align << ifs.getRangeX().max         << '\n'
              << "Interval Y min"     << align << ifs.getRangeY().min         << '\n'
              << "Interval Y max"     << align << ifs.getRangeY().max         << '\n'
              << "\n\n" << std::endl;



    cf::Interval range_x;
    range_x.min = 0.0;
    range_x.max = 1.0;

    cf::Interval range_y;
    range_y.min = 0.0;
    range_y.max = 1.0;

    cf::WindowVectorized Vec_Window1(800, range_x, range_y, "Hello world", cf::Color::WHITE);

    cf::WindowVectorized Vec_Window2(800, range_x, range_y, "Hello world", cf::Color::BLACK);

    cf::WindowVectorized FrmImage2D(800, range_x, range_y, "Hello world", cf::Color::BLACK);


    glm::vec3 test;

    test.x = 0.1;
    test.y = 0.4;
    test.z = 1.0;

//    for(float i = 0; i < 0.4; i= i + 0.001){
//        Vec_Window1.setColor(0.1 + i, 0.4, cf::Color::RED);

//    }


    Vec_Window1.show();

//    cf::Point point;


//

    std::cout << "Press enter to finish the process";
    cf::Console::waitKey();
    return 0;
}

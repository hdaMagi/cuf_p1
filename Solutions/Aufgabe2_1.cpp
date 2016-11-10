
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

    for (std::size_t i = 0; i < ifs.getNumTransformations(); ++i)
         std::cout << "Transformation " << i << ": \n" << ifs.getTransformation(i) << std::endl;


    cf::WindowRasterized window1(800, 600, "Chaos and Fractals", {0, 0, 0});
    cf::WindowRasterized window2(800, 600, "Chaos and Fractals", {0, 0, 0});

    cf::WindowRasterized FrmImage2D(800, 600, "Chaos and Fractals", {0, 0, 0});


    glm::vec2();

    cf::Point point;


point = window1.transformPoint_fromImage_toInterval(point);


    std::cout << "Press enter to finish the process";
    cf::Console::waitKey();
    return 0;
}

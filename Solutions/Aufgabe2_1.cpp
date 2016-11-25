
#include "IFS.h"
#include "windowRasterized.hpp"
#include "windowVercorized.hpp"
#include "globals.h"

int main(int argc, char** argv) {
    cf::Interval range_x;
    range_x.min = 0.0;
    range_x.max = 600.0;


    cf::Interval range_y;
    range_y.min = 0.0;
    range_y.max = 400.0;
    cf::WindowVectorized FrmImage2D(600,  range_x, range_y, "Eingabe", cf::Color::BLACK);

    cf::Point btnEingabeSize(199.0, 199.0);
    cf::Point btnEingabeRED(100.0, 100.0); // Punkt
    cf::Point btnEingabeBLUE(300.0, 100.0); // Quadrat
    cf::Point btnEingabeGREEN(100.0, 300.0); // waagrechte Line
    cf::Point btnEingabeYELLOW(300.0, 300.0); // senkrechte Line
    cf::Point btnEingabeMAGENTA(500.0, 100.0); // x1.png
    cf::Point btnEingabeORANGE(500.0, 300.0); // x2.png

    FrmImage2D.drawRectangle(btnEingabeRED,     btnEingabeRED,      200, cf::Color::RED);
    FrmImage2D.drawRectangle(btnEingabeBLUE,    btnEingabeBLUE,     200, cf::Color::BLUE);
    FrmImage2D.drawRectangle(btnEingabeGREEN,   btnEingabeGREEN,    200, cf::Color::GREEN);
    FrmImage2D.drawRectangle(btnEingabeYELLOW,  btnEingabeYELLOW,   200, cf::Color::YELLOW);

    FrmImage2D.drawRectangle(btnEingabeMAGENTA, btnEingabeMAGENTA,  200, cf::Color::MAGENTA);
    FrmImage2D.drawRectangle(btnEingabeORANGE,  btnEingabeORANGE,   200, cf::Color::ORANGE);
    std::cout << "ROT) Punkt\nBLAU) Quadrat\nGRUEN) waagrechte Strecke\nGELB) senkrechte Strecke\nMAGENTA) x1.png\nORANGE) x2.png" << std::endl;
    FrmImage2D.show();
    cf::Point user;
    FrmImage2D.waitMouseInput(user.x , user.y);
    cf::Color eingabe = FrmImage2D.getColor(user.x , user.y);
    FrmImage2D.clear();

    std::string filePath;
    filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files

    // create IFS object
    // and read *.ifs file
    cf::IteratedFunctionSystem ifs; // alternative:    cf::IFS ifs;
    ifs.read(filePath+"Sierpinski.ifs");

    cf::WindowVectorized oldImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Altes Bild", cf::Color::WHITE);
    cf::WindowVectorized image(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Altes Bild", cf::Color::WHITE);
    if (eingabe == cf::Color::RED) {
        oldImage.setColor(0.0, 0.0, cf::Color::BLACK);
    } else if (eingabe == cf::Color::BLUE) {;
        oldImage.drawRectangle(cf::Point(0.0, 0.0), cf::Point(1.0, 1.0), 1, cf::Color::BLACK);
    } else if (eingabe == cf::Color::GREEN) {
        oldImage.drawLine(cf::Point(0.0, 0.5), cf::Point(1.0, 0.5), 1, cf::Color::BLACK);
    } else if (eingabe == cf::Color::YELLOW) {
        oldImage.drawLine(cf::Point(0.5, 0.0), cf::Point(0.5, 1.0), 1, cf::Color::BLACK);
    } else if (eingabe == cf::Color::MAGENTA) {
        filePath += "x1.png";
        image = cf::WindowVectorized (filePath.c_str(), 400, ifs.getRangeX(), ifs.getRangeY());
        for (int row = 0; row < image.getWidth(); row++) {
            for (int col = 0; col < image.getHeight(); col++) {
                oldImage.setColor_imageSpace(row, col, image.getColor_imageSpace(row, col));
            }
        }
    } else if (eingabe == cf::Color::ORANGE) {
        filePath += "x2.png";
        image = cf::WindowVectorized (filePath.c_str(), 400, ifs.getRangeX(), ifs.getRangeY());
        for (int row = 0; row < image.getWidth(); row++) {
            for (int col = 0; col < image.getHeight(); col++) {
                oldImage.setColor_imageSpace(row, col, image.getColor_imageSpace(row, col));
            }
        }
    } else {
        return 0;
    }
    cf::WindowVectorized newImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Neues Bild", cf::Color::WHITE);

    cf::Point btn_length(396.0, 196.0);
    cf::Point btnClose_P1(1.0, 1.0);
    cf::Point btnNext_P1(1.0, 198.0);

    range_x.max = 400.0;
    FrmImage2D.setInterval(range_x, range_y, 400);
    FrmImage2D.drawRectangle(btnClose_P1, cf::Point(btnClose_P1.x + btn_length.x, btnClose_P1.y + btn_length.y), 1, cf::Color::RED);
    FrmImage2D.drawRectangle(btnNext_P1, cf::Point(btnNext_P1.x + btn_length.x, btnNext_P1.y + btn_length.y), 1, cf::Color::GREEN);
    FrmImage2D.show();
    oldImage.show();
    cf::Point p;
    do {
        cf::Color color = getRadomColor(cf::Color::WHITE);
        for (int row = 0; row < oldImage.getWidth(); row++) {
            for (int col = 0; col < oldImage.getHeight(); col++) {
                if (oldImage.getColor_imageSpace(row, col) != cf::Color::WHITE) {
                    for (int transformation = 0; transformation < ifs.getNumTransformations(); transformation++) {
                       p = oldImage.transformPoint_fromImage_toInterval(cf::Point(row, col));
                       glm::vec3 v(p.x, p.y, 1.0);
                       const glm::mat3x3& m = ifs.getTransformation(transformation);
                       v = m * v;
                       newImage.setColor(v.x, v.y, color);
                    }
                }
            }
        }
        newImage.show();
        FrmImage2D.waitMouseInput(user.x , user.y);

        for (int row = 0; row < newImage.getWidth(); row++) {
            for (int col = 0; col < newImage.getHeight(); col++) {
                cf::Color imageColor = newImage.getColor_imageSpace(row, col);
                if ((eingabe == cf::Color::MAGENTA) || (eingabe == cf::Color::ORANGE)) {
                    if (newImage.getColor_imageSpace(row, col) == cf::Color::WHITE) {
                        imageColor = image.getColor_imageSpace(row, col);
                    } else {
                        imageColor = cf::Color::WHITE;
                    }
                }
                oldImage.setColor_imageSpace(row, col, imageColor);
            }
        }
        oldImage.show();

        if ((eingabe == cf::Color::MAGENTA) || (eingabe == cf::Color::ORANGE)) {
            for (int row = 0; row < newImage.getWidth(); row++) {
                for (int col = 0; col < newImage.getHeight(); col++) {
                    oldImage.setColor_imageSpace(row, col, newImage.getColor_imageSpace(row, col));
                }
            }
        }
        newImage.clear();
    } while((user.x >  btnNext_P1.x) && (user.x < (btnNext_P1.x + btn_length.x)) && (user.y >  btnNext_P1.y) && (user.y < (btnNext_P1.y + btn_length.y)));
    return 0;
}

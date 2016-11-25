
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
    cf::WindowVectorized FrmImage2D(400,  range_x, range_y, "Eingabe", cf::Color::BLACK);

    int ImageSize = 512;
    std::string filePath;
    filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files

    cf::Point p, user;
    // create IFS object
    // and read *.ifs file
    cf::IteratedFunctionSystem ifs; // alternative:    cf::IFS ifs;
    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = 0; col < (FrmImage2D.getHeight() / 2); col++) {
            p = FrmImage2D.transformPoint_fromImage_toInterval(cf::Point(row, col));
            FrmImage2D.setColor(p.x, p.y, cf::Color::BLUE);
        }
    }

    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = (FrmImage2D.getHeight() / 2); col < FrmImage2D.getHeight(); col++) {
            p = FrmImage2D.transformPoint_fromImage_toInterval(cf::Point(row, col));
            FrmImage2D.setColor(p.x, p.y, cf::Color::MAGENTA);
        }
    }
    FrmImage2D.show();
    FrmImage2D.waitMouseInput(user.x , user.y);
    if (FrmImage2D.getColor(user.x , user.y) == cf::Color::BLUE) {
        ifs.read(filePath+"Invers.ifs");
    } else {
        ifs.read(filePath+"Invers.ifs");
    }

    cf::WindowVectorized oldImage(ImageSize, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Altes Bild", cf::Color::WHITE);
    cf::WindowVectorized newImage(ImageSize, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Neues Bild", cf::Color::WHITE);

    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = 0; col < (FrmImage2D.getHeight() / 2); col++) {
            p = FrmImage2D.transformPoint_fromImage_toInterval(cf::Point(row, col));
            FrmImage2D.setColor(p.x, p.y, cf::Color::GREEN);
        }
    }

    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = (FrmImage2D.getHeight() / 2); col < FrmImage2D.getHeight(); col++) {
            p = FrmImage2D.transformPoint_fromImage_toInterval(cf::Point(row, col));
            FrmImage2D.setColor(p.x, p.y, cf::Color::RED);
        }
    }
    FrmImage2D.show();
    oldImage.show();
    do {
        cf::Color color = getRadomColor(cf::Color::WHITE);
        for (int row = 0; row < oldImage.getWidth(); row++) {
            for (int col = 0; col < oldImage.getHeight(); col++) {
                p = oldImage.transformPoint_fromImage_toInterval(cf::Point(col, row));
                glm::vec3 v(p.x, p.y, 1.0);
                cf::Color newColor = cf::Color::BLACK;
                for (int i = 0; i < 15; i++) {
                    if ((v.x <= 0.5) && (v.y <= 0.5)) {
                        const glm::mat3x3& m = ifs.getTransformation(0);
                        v = m * v;
                    } else if ((v.x > 0.5) && (v.y <= 0.5)) {
                        const glm::mat3x3& m = ifs.getTransformation(1);
                        v = m * v;
                    } else {
                        const glm::mat3x3& m = ifs.getTransformation(2);
                        v = m * v;
                    }
                    if (((v.x*v.x) + (v.y*v.y)) > 10000.0) {
                        if ((i % 3) == 0) {
                            newColor = cf::Color::RED;
                        } else if ((i % 3) == 1) {
                            newColor = cf::Color::GREEN;
                        } else {
                            newColor = cf::Color::YELLOW;
                        }
                        break;
                    }
                }
                newImage.setColor(p.x, p.y, newColor);
            }
        }
        newImage.show();
        FrmImage2D.waitMouseInput(user.x , user.y);

        for (int row = 0; row < newImage.getWidth(); row++) {
            for (int col = 0; col < newImage.getHeight(); col++) {
                oldImage.setColor_imageSpace(row, col, newImage.getColor_imageSpace(row, col));
            }
        }
        oldImage.show();
        newImage.clear();
    } while(FrmImage2D.getColor(user.x , user.y) == cf::Color::GREEN);
    return 0;
}

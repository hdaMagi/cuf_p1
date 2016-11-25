
#include "IFS.h"
#include "windowRasterized.hpp"
#include "windowVercorized.hpp"
#include "globals.h"

int main(int argc, char** argv) {
    std::string filePath;
    filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files

    // create IFS object
    // and read *.ifs file
    cf::IteratedFunctionSystem ifs; // alternative:    cf::IFS ifs;
    ifs.read(filePath+"P34_A2.ifs");


    cf::WindowVectorized oldImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Altes Bild", cf::Color::WHITE);
    oldImage.setColor(0.0, 0.0, cf::Color::BLACK);
    cf::WindowVectorized newImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Neues Bild", cf::Color::WHITE);
    cf::WindowVectorized FrmImage2D(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Eingabe", cf::Color::WHITE);

    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = 0; col < (FrmImage2D.getHeight() / 2); col++) {
            FrmImage2D.setColor_imageSpace(col, row, cf::Color::GREEN);
        }
    }

    for (int row = 0; row < FrmImage2D.getWidth(); row++) {
        for (int col = (FrmImage2D.getHeight() / 2); col < FrmImage2D.getHeight(); col++) {
            FrmImage2D.setColor_imageSpace(col, row, cf::Color::RED);
        }
    }
    FrmImage2D.show();
    oldImage.show();
    cf::Point p, user;

    do {
        cf::Color color = getRadomColor(cf::Color::WHITE);
        for (int row = 0; row < oldImage.getWidth(); row++) {
            for (int col = 0; col < oldImage.getHeight(); col++) {
                if (oldImage.getColor_imageSpace(row, col) != cf::Color::WHITE) {
                    for (int transformation = 0; transformation < ifs.getNumTransformations(); transformation++) {
                       p = oldImage.transformPoint_fromImage_toInterval(cf::Point(col, row));
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
                oldImage.setColor_imageSpace(row, col, newImage.getColor_imageSpace(row, col));
            }
        }
        oldImage.show();
        newImage.clear();
    } while(FrmImage2D.getColor(user.x , user.y) == cf::Color::GREEN);
    return 0;
}

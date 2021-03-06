
#include "IFS.h"
#include "windowRasterized.hpp"
#include "windowVercorized.hpp"
#include "globals.h"

int main(int argc, char** argv) {
    cf::Interval range_x;
    range_x.min = 0.0;
    range_x.max = 300.0;


    cf::Interval range_y;
    range_y.min = 0.0;
    range_y.max = 400.0;
    cf::WindowVectorized FrmImage2D(300,  range_x, range_y, "Eingabe", cf::Color::WHITE);
    do {
        // KOCH_KURVE
        for (int row = 400; row > 300; row--) {
            for (int col = 0; col < 100; col++) {
                FrmImage2D.setColor(col, row, cf::Color::RED);
            }
        }
        // PEANO_KURVE
        for (int row = 400; row > 300; row--) {
            for (int col = 100; col < 200; col++) {
                FrmImage2D.setColor(col, row, cf::Color::BLUE);
            }
        }
        // BUSCH_1
        for (int row = 400; row > 300; row--) {
            for (int col = 200; col < 300; col++) {
                FrmImage2D.setColor(col, row, cf::Color::GREEN);
            }
        }

        // BUSCH_2
        for (int row = 300; row > 200; row--) {
            for (int col = 0; col < 100; col++) {
                FrmImage2D.setColor(col, row, cf::Color::YELLOW);
            }
        }
        // FARN_1
        for (int row = 300; row > 200; row--) {
            for (int col = 100; col < 200; col++) {
                FrmImage2D.setColor(col, row, cf::Color::MAGENTA);
            }
        }
        // STERN
        for (int row = 300; row > 200; row--) {
            for (int col = 200; col < 300; col++) {
                FrmImage2D.setColor(col, row, cf::Color::ORANGE);
            }
        }

        // DOPPELSPIRALE
        for (int row = 200; row > 100; row--) {
            for (int col = 0; col < 100; col++) {
                FrmImage2D.setColor(col, row, cf::Color::BLACK);
            }
        }
        // BAUM_3
        for (int row = 200; row > 100; row--) {
            for (int col = 100; col < 200; col++) {
                FrmImage2D.setColor(col, row, cf::Color::GREY);
            }
        }
        // DRACHENFLAECHE_4
        for (int row = 200; row > 100; row--) {
            for (int col = 200; col < 300; col++) {
                FrmImage2D.setColor(col, row, cf::Color::CYAN);
            }
        }

        // BEENDEN
        for (int row = 100; row > 0; row--) {
            for (int col = 0; col < 100; col++) {
                FrmImage2D.setColor(col, row, cf::Color::WHITE);
            }
        }
        // SIERPINSI_VERWANDTER_2
        for (int row = 100; row > 0; row--) {
            for (int col = 100; col < 200; col++) {
                FrmImage2D.setColor(col, row, cf::Color::PINK);
            }
        }
        // BEENDEN
        for (int row = 100; row > 0; row--) {
            for (int col = 200; col < 300; col++) {
                FrmImage2D.setColor(col, row, cf::Color::WHITE);
            }
        }

        std::cout << "RED     - Senkrechte Strecke - Koch_kurve_2\n" <<
                     "BLUE    - Senkrechte Strecke - Peano_kurve\n" <<
                     "GREEN   - Waagrechte Strecke - Busch_1\n" <<
                     "YELLOW  - Waagrechte Strecke - Busch_2\n" <<
                     "MAGENTA - n gefuellt Quadrat - Farn_1\n" <<
                     "ORANGE  - n gefuellt Quadrat - Stern\n" <<
                     "BLACK   - n gefuellt Quadrat - Doppelspirale\n" <<
                     "GREY    - n gefuellt Quadrat - Baum_3\n" <<
                     "CYAN    - n gefuellt Quadrat - Drachenflaeche_4\n" <<
                     "PINK    - n gefuellt Quadrat - Sierp_verwandter_1\n" <<
                     "WHITE   - Beenden" <<
                      std::endl;
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

        if (eingabe == cf::Color::WHITE) {
            return 0;
        } else if (eingabe == cf::Color::RED) {
            ifs.read(filePath+"Koch_kurve_2.ifs");
        } else if (eingabe == cf::Color::BLUE) {
            ifs.read(filePath+"Peano_kurve.ifs");
        } else if (eingabe == cf::Color::GREEN) {
            ifs.read(filePath+"Busch_1.ifs");
        } else if (eingabe == cf::Color::YELLOW) {
            ifs.read(filePath+"Busch_2.ifs");
        } else if (eingabe == cf::Color::MAGENTA) {
            ifs.read(filePath+"Farn_1.ifs");
        } else if (eingabe == cf::Color::ORANGE) {
            ifs.read(filePath+"Stern.ifs");
        } else if (eingabe == cf::Color::BLACK) {
            ifs.read(filePath+"Doppelspirale.ifs");
        } else if (eingabe == cf::Color::GREY) {
            ifs.read(filePath+"Baum_3.ifs");
        } else if (eingabe == cf::Color::CYAN) {
            ifs.read(filePath+"Drachenflaeche_4.ifs");
        } else if (eingabe == cf::Color::PINK) {
            ifs.read(filePath+"Sierp_verwandter_1.ifs");
        }

        cf::WindowVectorized oldImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Altes Bild", cf::Color::WHITE);
        if ((eingabe == cf::Color::RED) || (eingabe == cf::Color::BLUE)) {;
            oldImage.drawLine(cf::Point(0.0, 0.5), cf::Point(1.0, 0.5), 1, eingabe);
        } else if ((eingabe == cf::Color::GREEN) || (eingabe == cf::Color::YELLOW)) {
            oldImage.drawLine(cf::Point(0.5, 0.0), cf::Point(0.5, 1.0), 1, eingabe);
        } else {
            oldImage.drawRectangle(cf::Point(0.0, 0.0), cf::Point(1.0, 1.0), 1, cf::Color::BLACK);
        }
        cf::WindowVectorized newImage(400, ifs.getRangeX(), ifs.getRangeY(), "(P3+4 A1) Neues Bild", cf::Color::WHITE);
        range_y.max = 400.0;
        FrmImage2D.setInterval(range_x, range_y, 400);
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
        cf::Point p;

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
        range_y.max = 400.0;
        FrmImage2D.clear();
        FrmImage2D.setInterval(range_x, range_y, range_x.max);
    } while(true);
    return 0;
}

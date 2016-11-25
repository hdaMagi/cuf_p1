
#include "IFS.h"
#include "windowRasterized.hpp"
#include "windowVercorized.hpp"
#include "globals.h"

int main(int argc, char** argv) {
    cf::Interval range_x;
    range_x.min = 0.0;
    range_x.max = 400.0;


    cf::Interval range_y;
    range_y.min = 0.0;
    range_y.max = 500.0;
    cf::WindowVectorized FrmImage2D(500,  range_x, range_y, "Eingabe", cf::Color::WHITE);
    do {
        cf::Point btnA3_1(100.0, 400.0); // KOCH_KURVE
        cf::Point btnA3_2(200.0, 400.0); // PEANO_KURVE
        cf::Point btnA4_1(300.0, 400.0); // BUSCH_1

        cf::Point btnA4_2(100.0, 300.0); // BUSCH_2
        cf::Point btnA2_1(200.0, 300.0); // FARN_1
        cf::Point btnA2_2(300.0, 300.0); // STERN

        cf::Point btnA2_3(100.0, 200.0); // DOPPELSPIRALE
        cf::Point btnA2_4(200.0, 200.0); // BAUM_3
        cf::Point btnA2_5(300.0, 200.0); // DRACHENFLAECHE_4

        cf::Point btnA2_6(200.0, 100.0); // SIERPINSI_VERWANDTER_2

        int btnSize = 100;
        FrmImage2D.drawRectangle(btnA3_1, btnA3_1, btnSize, cf::Color::RED);
        FrmImage2D.drawRectangle(btnA3_2, btnA3_2, btnSize, cf::Color::BLUE);

        FrmImage2D.drawRectangle(btnA4_1, btnA4_1, btnSize, cf::Color::GREEN);
        FrmImage2D.drawRectangle(btnA4_2, btnA4_2, btnSize, cf::Color::YELLOW);

        FrmImage2D.drawRectangle(btnA2_1, btnA2_1, btnSize, cf::Color::MAGENTA);
        FrmImage2D.drawRectangle(btnA2_2, btnA2_2, btnSize, cf::Color::ORANGE);
        FrmImage2D.drawRectangle(btnA2_3, btnA2_3, btnSize, cf::Color::BLACK);
        FrmImage2D.drawRectangle(btnA2_4, btnA2_4, btnSize, cf::Color::GREY);
        FrmImage2D.drawRectangle(btnA2_5, btnA2_5, btnSize, cf::Color::CYAN);
        FrmImage2D.drawRectangle(btnA2_6, btnA2_6, btnSize, cf::Color::PINK);
        std::cout << "RED     - Senkrechte Strecke - Koch_kurve_2\n" <<
                     "BLUE    - Senkrechte Strecke - Peano_kurve\n" <<
                     "GREEN   - Waagrechte Strecke - Busch_1\n" <<
                     "YELLOW  - Waagrechte Strecke - Busch_2\n" <<
                     "MAGENTA - n gefuellt Quadrat - Farn_1\n" <<
                     "ORANGE  - n gefuellt Quadrat - Stern\n" <<
                     "WHITE   - n gefuellt Quadrat - Doppelspirale\n" <<
                     "GREY    - n gefuellt Quadrat - Baum_3\n" <<
                     "CYAN    - n gefuellt Quadrat - Drachenflaeche_4\n" <<
                     "PINK    - n gefuellt Quadrat - Sierp_verwandter_1\n" <<
                     "BLACK   - Beenden" <<
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

        cf::Point btn_length(396.0, 196.0);
        cf::Point btnClose_P1(1.0, 1.0);
        cf::Point btnNext_P1(1.0, 198.0);

        range_y.max = 400.0;
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
        } while((user.x >  btnNext_P1.x) && (user.x < (btnNext_P1.x + btn_length.x)) && (user.y >  btnNext_P1.y) && (user.y < (btnNext_P1.y + btn_length.y)));
        range_y.max = 500.0;
        FrmImage2D.clear();
        FrmImage2D.setInterval(range_x, range_y, 500);
    } while(true);
    return 0;
}

#include "LSystem.h"
#include "windowVercorized.hpp"
#include <math.h>

#define PI 3.14159265359

struct item {
    cf::Point p1;
    cf::Point p2;
    double winkel_in_rad;
};

int main(int argc, char** argv) {
    std::string next = "";

    do {
        std::cout << "Welche Datei soll geladen werden?" << std::endl;
        std::cout << "1) BUSCH_1.LIN" << std::endl;
        std::cout << "2) BUSCH_2.LIN" << std::endl;
        std::cout << "3) BUSCH_3.LIN" << std::endl;
        std::cout << "4) DRACHEN_KURVE_3.LIN" << std::endl;
        std::cout << "5) SIERPINSKI_2.LIN" << std::endl;
        std::cout << "6) BUSCH_4.LIN" << std::endl;
        std::cout << "7) HILBERT_KURVE.LIN" << std::endl;
        std::cout << "8) PYTHAGORAS_BAUM.LIN" << std::endl;
        std::cout << "Eingabe: ";
        int fileNumber;
        std::cin >> fileNumber;
        cf::Console::clearConsole();
        // receive file name/path
        std::string filePath;
        filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files
        switch (fileNumber) {
            case 1: {
                filePath += "Busch_1.lin";
                break;
            }
            case 2: {
                filePath += "Busch_2.lin";
                break;
            }
            case 3: {
                filePath += "Busch_3.lin";
                break;
            }
            case 4: {
                filePath += "Drachen_kurve_3.lin";
                break;
            }
            case 5: {
                filePath += "Sierpinski_2.lin";
                break;
            }
            case 6: {
                filePath += "Busch_4.lin";
                break;
            }
            case 7: {
                filePath += "Hilbert_kurve.lin";
                break;
            }
            default: {
                filePath += "Pythagoras_baum.lin";
                break;
            }
        }

        // create and parse *.lin file
        cf::LindenmayerSystem ls;   // alternative:     cf::LSystem ls;
        ls.read(filePath);

        // print all data found in *.lin file
        std::string align = " :  ";
        std::cout << "Name"                    << align << ls.getName()                              << '\n'
                  << "Axiom"                   << align << ls.getAxiom()                             << '\n'
                  << "Number of productions"   << align << ls.getNumProductions()                    << '\n'
                  << "Clear window each time?" << align << (ls.clearWindowEachTime() ? "yes" : "no") << '\n'
                  << "Start angle"             << align << ls.getStartAngle()                        << '\n'
                  << "Adjustment angle"        << align << ls.getAdjustmentAngle()                   << '\n'
                  << "Scale"                   << align << ls.getScale()                             << '\n'
                  << "Interval X"              << align << ls.getRangeX()                            << '\n'
                  << "Interval Y"              << align << ls.getRangeY()                            << '\n'
                  << std::endl;

        // print all productions
        std::cout << std::endl << std::endl << "All productions:" << std::endl << std::endl;
        for (const auto& e: ls.getAllProductions()){
            std::cout << "Symbol: " << e.first << "\nProduction: " << e.second << std::endl << std::endl;
        }


        std::cout << std::endl << "--------------------------------------------" << std::endl;
        cf::WindowVectorized image(1000, { -10.0, 10.0}, { -10.0, 10.0}, "(P5+6 A1) Turtel", cf::Color::WHITE);
        std::string str;
        str.push_back(ls.getAxiom());
        int generations = 0;
        std::cout << "Wieviele Generationen: ";
        std::cin >> generations;
        cf::Point p1;
        cf::Point p2;

        std::vector <item> vecState;
        p1.x = 0.0;
        p1.y = 0.0;
        double winkel_in_rad = cf::degree2radian(ls.getStartAngle()); //(cf::degree2radian(ls.getStartAngle()));

        p2.x = 0;
        p2.y = 0;

        std::cout << "Press Enter for next step....";
        cf::Console::waitKey();


        if (ls.clearWindowEachTime()) {
            image.clear();
            image.show();
        }

        for (int step = 1; step <= generations; step++) {
            std::string newStr = "";

            image.clear();

            p1.x = 0.0;
            p1.y = 0.0;
            p2.x = 0.0;
            p2.y = 0.0;
            double winkel_in_rad = cf::degree2radian(ls.getStartAngle()); //(cf::degree2radian(ls.getStartAngle()));


            std::cout <<"Generation "<< step << ": " << str << std::endl;
            for(std::string::size_type i = 0; i < str.size(); i++) {
                const std::string* pStr = ls.getProduction(str[i]);
                if (pStr != nullptr) {
                    newStr += *pStr;
                } else {
                    newStr += str[i];
                }

                if ((str[i] >= char('A')) && (str[i] <= char('Z'))) {
                    // Ein Großer Buchstabe gefunden
                    p1 = p2;
                    p2.x += cos(winkel_in_rad) * (ls.getScale() / (float) step);
                    p2.y += sin(winkel_in_rad) * (ls.getScale() / (float) step);

                    image.drawLine(p1, p2, 1, cf::Color::RED);
                    image.show();

                } else if ((str[i] >= char('a')) && (str[i] <= char('z'))) {
                    p1 = p2;
                    p2.x += cos(winkel_in_rad);
                    p2.y += sin(winkel_in_rad);
                } else if(str[i] == '+') {
                    winkel_in_rad += cf::degree2radian(ls.getAdjustmentAngle());

                } else if(str[i] == '-') {
                    winkel_in_rad -= cf::degree2radian(ls.getAdjustmentAngle());
                } else if(str[i] == '[') {
                    vecState.push_back({p1, p2, winkel_in_rad});
                } else if(str[i] == ']') {
                    item i = vecState.back();
                    p1 = i.p1;
                    p2 = i.p2;
                    winkel_in_rad = i.winkel_in_rad;
                    vecState.pop_back();
                }

            }
            str = newStr;
            image.show();

            std::cout << "Press Enter for next step....";
            cf::Console::waitKey();
        }

        std::cout << "Weiter [j,J]: ";
        std::cin >> next;
    } while((next == "j") || (next == "J"));
    return 0;
}

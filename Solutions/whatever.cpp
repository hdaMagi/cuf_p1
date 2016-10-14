#include "computerGeometry.hpp"
#include <iostream>
#include "math.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

int getRandom(int mod) {
    timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    return rand()%mod;
}

int main(int argc, char** argv){
    // receive file name/path
        std::string filePath;
        if (argc < 2){
            std::cout << "Please provide a .dat file, if you want a different ifs file\n\n\n";
            filePath = GEOMETRY_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/geometry_files/
            filePath += "FIRST.DAT";
        }
        else
            filePath = argv[1];

// create coordinate system and draw all points and lines
    cf::WindowCoordinateSystem coordinateSystem(800, {-10.f, 350.f}, {-10.f, 350.f});
    coordinateSystem.drawAxis(cf::Color::BLACK, 10.f, 10.f);

    // read dat file as cf::PointVector type
        std::vector<cf::PointVector> points = cf::readDATFile<cf::PointVector>(filePath);

    /*for (const auto& point : points){
        std::cout << point << std::endl;
        coordinateSystem.drawPoint(point);
    }

    // draw all lines
    for (size_t i = 1; i < points.size(); ++i)
        coordinateSystem.drawLine(points[i-1], points[i]);
    coordinateSystem.drawLine(points.front(), points.back());*/
    coordinateSystem.show();

// wait for user input and draw user points
    std::cout << "Please set a point\n\n";
    cf::PointVector pQ[3]; // default values of PointVector: (0 0 1)
    for (int i=0; i < 3; i++) {
        coordinateSystem.waitMouseInput(pQ[i][0], pQ[i][1]);
        coordinateSystem.drawPoint(pQ[i], cf::Color::RED);
        coordinateSystem.show();
    }

    cf::PointVector pAlt; // default values of PointVector: (0 0 1)
    coordinateSystem.waitMouseInput(pAlt[0], pAlt[1]);
    coordinateSystem.drawPoint(pAlt, cf::Color::RED);
    coordinateSystem.show();

    cf::Color color = cf::Color(0,0,1);
    for(int i=0; i < 10000; i++) {
        cf::PointVector pNeu;
        int idxR = getRandom(3);
        pNeu.setX((pQ[idxR].getX() + pAlt.getX()) / 2);
        pNeu.setY((pQ[idxR].getY() + pAlt.getY()) / 2);
        if ((i%100) == 0) {
            color = cf::Color((uint8_t)getRandom(255),(uint8_t)getRandom(255),(uint8_t)getRandom(255));
        }
        coordinateSystem.drawPoint(pNeu, color);
        coordinateSystem.show();
        usleep(1000);
        pAlt = pNeu;
    }

    std::cout << "Press enter to finish the process\n";
    coordinateSystem.waitKey();
    return 0;
}

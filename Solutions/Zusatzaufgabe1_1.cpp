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

int main(){


// create coordinate system and draw all points and lines
    cf::WindowCoordinateSystem coordinateSystem(800, {-10.f, 350.f}, {-10.f, 350.f});
    coordinateSystem.drawAxis(cf::Color::BLACK, 10.f, 10.f);
    coordinateSystem.show();

// wait for user input and draw user points
    std::cout << "Please set a point\n\n";
    cf::PointVector pQ[4]; // default values of PointVector: (0 0 1)
    for (int i=0; i < 4; i++) {
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
        int idxR = getRandom(4);
        pNeu.setX((pQ[idxR].getX() + pAlt.getX()) / 3);
        pNeu.setY((pQ[idxR].getY() + pAlt.getY()) / 3);
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

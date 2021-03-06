#include "computerGeometry.hpp"
#include <iostream>
#include "math.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "windowVercorized.hpp"
#include <vector>

#define MAXITERATIONS 1000

struct rectangle {
    cf::Point point;
    cf::Point tallness;
};

void recDevideSquare(std::vector<rectangle> rectangles, cf::WindowVectorized window, int iterations){
                rectangle r = rectangles.at(0);
                rectangles.erase(rectangles.begin());

                rectangle leftbottom;
                leftbottom.point.x = r.point.x;
                leftbottom.point.y = r.point.y;
                leftbottom.tallness.x = r.point.x + ((r.tallness.x - r.point.x) / 2);
                leftbottom.tallness.y = r.point.y + ((r.tallness.y - r.point.y) / 2);

                rectangle lefttop;
                lefttop.point.x =  r.point.x;
                lefttop.point.y = leftbottom.tallness.y;
                lefttop.tallness.x = leftbottom.tallness.x;
                lefttop.tallness.y = r.tallness.y;

                rectangle rigthbottom;
                rigthbottom.point.x = leftbottom.tallness.x;
                rigthbottom.point.y = r.point.y;
                rigthbottom.tallness.x = r.tallness.x;
                rigthbottom.tallness.y = leftbottom.tallness.y;

                rectangle rigthtop;
                rigthtop.point.x = leftbottom.tallness.x;
                rigthtop.point.y = leftbottom.tallness.y;
                rigthtop.tallness.x = r.tallness.x;
                rigthtop.tallness.y = r.tallness.y;
                window.drawRectangle(rigthtop.point, rigthtop.tallness, -1, cf::Color::BLACK);
                window.show();

                if ((lefttop.tallness.y - lefttop.point.y) > 2) {
                    rectangles.push_back(lefttop);
                    rectangles.push_back(leftbottom);
                    rectangles.push_back(rigthbottom);
                }

                if(iterations < MAXITERATIONS){
                recDevideSquare(rectangles, window, ++iterations);
                }
}



int main(int argc, char** argv){
    // read intervals from console
        cf::Interval range_x;
        std::cout << "Part 1: Demonstration of the correspondence between an \n";
        std::cout << "user defined float 2D-interval and an image matrix\n\n";

        std::cout << "Please provide a float interval for the x-axis:\n";
        std::cout << "(Min and max values between -10.0 and 10.0!)\n";
        std::cout << "Interval: x-min: "; range_x.min = 0.0;//cf::Console::readFloat();
        std::cout << "Interval: x-max: "; range_x.max = 400.0;//cf::Console::readFloat();
        std::cout << std::endl;

        cf::Interval range_y;
        std::cout << "Please provide a float interval for the y-axis:\n";
        std::cout << "(Min and max values between -10.0 and 10.0!)\n";
        std::cout << "Interval: y-min: "; range_y.min = 0.0;//cf::Console::readFloat();
        std::cout << "Interval: y-max: "; range_y.max = 400.0; //cf::Console::readFloat();
        cf::Console::clearConsole();

        // create window and print mouse input
            cf::WindowVectorized window(800, range_x, range_y, "Hello world", cf::Color::RED);
            std::cout << "Created window size:\n"
                      << "Width : " << window.getWidth()  << std::endl
                      << "Height: " << window.getHeight() << std::endl
                                                          << std::endl;
            window.show();

            cf::Point px = cf::Point(0, 0);
            cf::Point py = cf::Point(window.getWidth(), window.getHeight());

        std::vector<rectangle> rectangles;
        rectangle r;
        r.point.x = px.x;
        r.point.y = px.y;
        r.tallness.x = py.x;
        r.tallness.y = py.y;
        rectangles.push_back(r);
        recDevideSquare(rectangles, window, 1);
        printf("Everything is done. ");

        std::cout << "Enter to exit"; cf::Console::readString();

    return 0;
}

#include "computerGeometry.hpp"
#include <iostream>
#include "math.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "windowVercorized.hpp"
#include <vector>


int deadline = 10;

void recDevideSquare(cf::Point px, cf::Point py, cf::WindowVectorized window, int iterations){

    /*
     * __|_X
     *   |
     *
     */

    cf::Point pxSQ1 = px;
    cf::Point pySQ1 = py;
    pxSQ1.x = (py.x - px.x) / 2;
    pxSQ1.y = (py.y - px.y) / 2;
    window.drawRectangle(pxSQ1, pySQ1, -1, cf::Color::BLACK);

    /*
     * X_|__
     *   |
     *
     */
    cf::Point pxSQ2 = px;
    cf::Point pySQ2 = py;
    pySQ2.x = (py.x - px.x) / 2;
    pxSQ2.y = (py.y - px.y) / 2;
    window.drawRectangle(pxSQ2, pySQ2, -1, cf::Color::RED);

    /*
     * __|__
     * X |
     *
     */
    cf::Point pxSQ3 = px;
    cf::Point pySQ3 = py;
    pySQ3.x = (py.x - px.x) / 2;
    pySQ3.y = (py.x - px.y) / 2;
    window.drawRectangle(pySQ3, pxSQ3, -1, cf::Color::RED);

    /*
     * __|__
     *   | X
     *
     */
    cf::Point pxSQ4 = px;
    cf::Point pySQ4 = py;
    pxSQ4.x = (py.x - px.x) / 2;
    pySQ4.y = (py.y - px.y) / 2;
    window.drawRectangle(pySQ4, pxSQ4, -1, cf::Color::RED);
    window.show();
    recDevideSquare(pxSQ4, pySQ4, window, iterations++);
}

struct rectangle {
    cf::Point point;
    cf::Point tallness;
};

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
        do {
            rectangle leftbottom;
            leftbottom.point.x = r.point.x;
            leftbottom.point.y = r.point.y;
            leftbottom.tallness.x = r.point.x + ((r.tallness.x - r.point.x) / 2);
            leftbottom.tallness.y = r.point.y + ((r.tallness.y - r.point.y) / 2);

            rectangle lefttop;
            lefttop.point.x = leftbottom.point.x;
            lefttop.point.y = leftbottom.tallness.y;
            lefttop.tallness.x = leftbottom.tallness.x;
            lefttop.tallness.y = r.tallness.y;

            rectangle rigthbottom;
            rigthbottom.point.x = leftbottom.tallness.x;
            rigthbottom.point.y = leftbottom.point.y;
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
            r = rectangles[0];
            rectangles.erase(rectangles.begin());

        } while (rectangles.size() > 0);
        //recDevideSquare(px, py, window, 0);

//        for(int i = 1; i < 100; i++){
//            std::cout << "\n\n\nPress enter to draw a rectangle\n";
//            window.waitKey();

//            px = cf::Point(0, 0);
//            py = cf::Point(window.getWidth() / 2, window.getHeight() / 2);

//            window.drawRectangle(px, py, 2, cf::Color::RED);

//            window.show();
//        }
        std::cout << "Enter to exit"; cf::Console::readString();

    return 0;
}

#ifndef GLOBALS
#define GLOBALS

#include <utils.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

int getRandom(int mod) {
    timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    return rand()%mod;
}

cf::Color getRadomColor(cf::Color withoutColor) {
    cf::Color colors[] = {
                cf::Color::MAGENTA,
                cf::Color::ORANGE,
                cf::Color::WHITE,
                cf::Color::BLACK,
                cf::Color::GREEN,
                cf::Color::GREY,
                cf::Color::BLUE,
                cf::Color::CYAN,
                cf::Color::PINK,
                cf::Color::RED
    };
    int idx = getRandom(10);
    if (colors[idx] == withoutColor) {
        colors[(idx+1) % 10];
    } else {
        return colors[idx];
    }
}

#endif // GLOBALS


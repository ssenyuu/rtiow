// deals with outputting PPM files
#pragma once
#include <iostream>
#include "vec3.h"
#include "color.h"

#define MAX_COLOR 255

void outputPPM(int width, int height) {
    std::cout << "P3\n" << width << ' ' << height << '\n' << MAX_COLOR << '\n';

    for (int j = 0; j < height; ++j) {
        std::clog << "\rScanlines remaining: " << (height - j) << std::flush;
        for (int i = 0; i < width; ++i) {
            auto pixel_color = color(double(i) / (width - 1), double(j) / (height - 1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                                                  \n";
}
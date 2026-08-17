// deals with outputting PPM files
#pragma once
#include <iostream>

/*
 write rows top-down, each row written left-right
 +--1-->
 |
 2
 |
 V
*/

#define MAX_COLOR 255

void outputPPM(int width, int height) {
    std::cout << "P3\n" << width << ' ' << height << '\n' << MAX_COLOR << '\n';

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.0;

            int ir = int(r * 255.999);
            int ig = int(g * 255.999);
            int ib = int(b * 255.999);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
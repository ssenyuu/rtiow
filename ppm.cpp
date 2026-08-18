// deals with outputting PPM files
#pragma once
#include "vec3.h"
#include "color.h"

#define MAX_COLOR 255

void outputPreamble(std::ostream& out, int width, int height) {
    out << "P3\n" << width << ' ' << height << '\n' << MAX_COLOR << '\n';
}
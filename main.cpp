#include "ppm.cpp"

#define HEIGHT 900
#define WIDTH 1600

int main() {
    outputPreamble(std::cout, WIDTH, HEIGHT);

    for (int j = 0; j < HEIGHT; ++j) {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << std::flush;
        for (int i = 0; i < WIDTH; ++i) {
            auto pixel_color = color(double(i) / (WIDTH - 1), double(j) / (HEIGHT - 1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                                                  \n";
}
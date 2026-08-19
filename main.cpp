#include "ppm.cpp"
#include "ray.h"


color ray_color(const ray& r) {
    auto unit_vec = unit_vector(r.direction());
    // unit_vec.y \in [-1, 1] but we want to normalize to [0, 1] for lerp
    auto a = 0.5 * (unit_vec.y() + 1);
    // white when a=0, blue when a=1
    return (1.0-a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
    auto aspect_ratio = 16.0 / 9.0; // width / height
    int image_width = 400;

    // aspect ratio determines image dimensions
    int image_height = int(image_width / aspect_ratio);
    image_height = image_height > 1 ? image_height : 1;

    // image dimensions determine viewport dimensions
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * image_width / image_height;

    // camera
    auto focal_length = 1.0; // distance from camera to viewport
    auto camera_center = point3(0,0,0); // normal to center of viewport

    // horizontal and vertical viewport vectors (span entire edge)
    auto viewport_u = vect3(viewport_width, 0, 0);
    auto viewport_v = vect3(0, -viewport_height, 0);

    // horizontal and vertical delta vectors (from pixel to pixel)
    auto delta_u = viewport_u / image_width;
    auto delta_v = viewport_v / image_height;

    // location of upper left (1st) pixel
    auto viewport_ul_corner = camera_center - (viewport_u + viewport_v) * 0.5
                                + vect3(0, 0, -focal_length);
    auto first_pixel_position = viewport_ul_corner + (delta_u + delta_v) * 0.5;

    // render
    outputPreamble(std::cout, image_width, image_height);

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = first_pixel_position + i*delta_u + j*delta_v;
            auto ray_dir = pixel_center - camera_center;

            ray r(camera_center, ray_dir);
            color pixel_color = ray_color(r);

            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                                                  \n";
}
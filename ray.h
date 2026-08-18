#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {};
        ray(const point3 &orig, const vec3 &dir) : orig(orig), dir(dir) {};

        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        vec3 at(Float t) {
            return orig + t * dir;
        }

    private:
        point3 orig;
        vec3 dir;
};

#endif
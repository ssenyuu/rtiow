#pragma once

#include "vec3.h"

// I am not proud of this.
using vect3 = vec3<Vec3Type::Spatial>;

class ray {
    public:
        ray() {};
        ray(const point3 &orig, const vect3 &dir) : orig(orig), dir(dir) {};

        const point3& origin() const { return orig; }
        const vect3& direction() const { return dir; }

        vect3 at(Float t) {
            return orig + t * dir;
        }

    private:
        point3 orig;
        vect3 dir;
};

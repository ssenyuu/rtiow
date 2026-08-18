#ifndef VEC3_H
#define Vec3_H

#include <cmath>
#include <iostream>

using Float = double;

using point3 = vec3;

class vec3 {
    public:
        Float e[3];

        // constructors
        vec3() : e{0, 0, 0} {}
        vec3(Float e0, Float e1, Float e2) : e{e0, e1, e2} {}

        // getters
        Float x() const { return e[0]; }
        Float y() const { return e[1]; }
        Float z() const { return e[2]; }

        Float operator[](int i) const { return e[i]; }
        Float& operator[](int i) { return e[i]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        vec3& operator-=(const vec3& v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this; 
        }
        vec3& operator*=(Float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this; 
        }
        vec3& operator/=(Float t) {
            return *this *= 1/t;
        }

        Float length() const {
            return std::sqrt(length_squared());
        }

        Float length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(Float t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, Float t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, Float t) {
    return (1/t) * v;
}

inline Float dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}


#endif

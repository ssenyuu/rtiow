#pragma once

#include <cmath>
#include <iostream>

using Float = double;

enum class Vec3Type {
    Spatial,
    Color
};

// The use of templated vec3 objects provides compile-time safety against cross-type operations
//  - (e.g. attempting to add a color to a point)

template <Vec3Type T>
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

using point3 = vec3<Vec3Type::Spatial>;

template <Vec3Type T>
inline std::ostream& operator<<(std::ostream& out, const vec3<T>& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

template <Vec3Type T>
inline vec3<T> operator+(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

template <Vec3Type T>
inline vec3<T> operator-(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

template <Vec3Type T>
inline vec3<T> operator*(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

template <Vec3Type T>
inline vec3<T> operator*(Float t, const vec3<T>& v) {
    return vec3<T>(t*v.e[0], t*v.e[1], t*v.e[2]);
}

template <Vec3Type T>
inline vec3<T> operator*(const vec3<T>& v, Float t) {
    return t * v;
}

template <Vec3Type T>
inline vec3<T> operator/(const vec3<T>& v, Float t) {
    return (1/t) * v;
}

template <Vec3Type T>
inline Float dot(const vec3<T>& u, const vec3<T>& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

template <Vec3Type T>
inline vec3<T> cross(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

template <Vec3Type T>
inline vec3<T> unit_vector(const vec3<T>& v) {
    return v / v.length();
}

#include <cmath>
#include "vec3.h"
using T = double;
Vec3::Vec3(T x, T y, T z) :x(x), y(y), z(z) {}
Vec3::Vec3() : x(T()), y(T()), z(T()) {}

T Vec3::LenSqr() const {
    return x * x + y * y + z * z;
}

T Vec3::Len() const {
    return sqrt(LenSqr());
}

Vec3& Vec3::operator+=(const Vec3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3& Vec3::operator*=(T mul) {
    x *= mul;
    y *= mul;
    z *= mul;
    return *this;
}


Vec3& Vec3::operator/=(T div) {
    T inv = T(1.0) / div;
    x *= inv;
    y *= inv;
    z *= inv;
    return *this;
}

Vec3 Vec3::Norm() {
    return Vec3(*this) / Len();
}

Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
    return Vec3(lhs) += rhs;
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
    return Vec3(lhs) -= rhs;
}

Vec3 operator*(const Vec3& lhs, T rhs) {
    return Vec3(lhs) *= rhs;
}

Vec3 operator/(const Vec3& lhs, T rhs) {
    return Vec3(lhs) /= rhs;
}

Vec3 operator-(const Vec3& v) {
    return Vec3(-v.x, -v.y, -v.z);
}

T DistSqr(const Vec3& lhs, const Vec3& rhs) {
    return (lhs - rhs).LenSqr();
}

T Dist(const Vec3& lhs, const Vec3& rhs) {
    return (lhs - rhs).Len();
}

T Dot(const Vec3& lhs, const Vec3& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vec3 Cross(const Vec3& a, const Vec3& b) {
    return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
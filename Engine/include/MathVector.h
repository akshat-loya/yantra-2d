/* 
 * ====================================================================
 * A custom Vector file that lets users define and manipulate a
 * vector in 3D space. Can be used in 2D by passing z=0 (or constant).
 * ====================================================================
 */

// Read about #pragma once
#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <cmath>

class Vec3D
{
public:
    const double x, y, z;

    Vec3D() : x(0), y(0), z(0) {}

    Vec3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double dotProd(const Vec3D& vec) const
    {
        return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
    }

    Vec3D crossProd(const Vec3D& vec) const
    {
        return Vec3D( 
            this->y * vec.z - this->z * vec.y,
            this->z * vec.x - this->x * vec.z,
            this->x * vec.y - this->y * vec.x);
    }

    double magnitude() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    Vec3D unitVec() const
    {
        double mag = this->magnitude();
        if (mag == 0.0) return Vec3D(0,0,0);
        return Vec3D(x / mag, y / mag, z / mag);
    }

    Vec3D operator+(const Vec3D& vec) const
    {
        return Vec3D(
            this->x + vec.x,
            this->y + vec.y,
            this->z + vec.z);
    }

    Vec3D operator-(const Vec3D& vec) const
    {
        return Vec3D(
            this->x - vec.x,
            this->y - vec.y,
            this->z - vec.z);
    }

    Vec3D operator*(double factor) const
    {
        return Vec3D(
            this->x * factor,
            this->y * factor,
            this->z * factor);
    }

    bool operator==(const Vec3D& vec) const
    {
        const double diff = 1e-9;
        return (fabs(this->x - vec.x) < diff &&
                fabs(this->y - vec.y) < diff &&
                fabs(this->z - vec.z) < diff);
    }

    bool operator!=(const Vec3D& vec) const
    {
        return !(*this == vec);
    }
};

#endif // MATHVECTOR_H
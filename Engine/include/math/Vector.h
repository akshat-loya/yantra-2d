/* 
 * ====================================================================
 * A custom Vector file that lets users define and manipulate a
 * vector in 3D space. Can be used in 2D by passing z=0 (or constant).
 * ====================================================================
 */

// TODO Read about #pragma once
#ifndef ENGINE_MATH_VECTOR_H
#define ENGINE_MATH_VECTOR_H

#include <cmath>

class Vector3D
{
public:
    double x, y, z;

    Vector3D() : x(0), y(0), z(0) {}

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D(const Vector3D& vec) = default;
    Vector3D& operator=(const Vector3D& vec) = default;
    
    Vector3D(Vector3D&& vec) = default;
    Vector3D& operator=(Vector3D&& vec) = default;

    ~Vector3D() = default;

    static double dotProd(const Vector3D& vec1, const Vector3D& vec2)
    {
        return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
    }

    static Vector3D crossProd(const Vector3D& vec1, const Vector3D& vec2)
    {
        return Vector3D( 
            vec1.y * vec2.z - vec1.z * vec2.y,
            vec1.z * vec2.x - vec1.x * vec2.z,
            vec1.x * vec2.y - vec1.y * vec2.x);
    }

    double magnitude() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    Vector3D unitVec() const
    {
        double mag = this->magnitude();
        if (mag == 0.0) return Vector3D(0,0,0);
        return Vector3D(x / mag, y / mag, z / mag);
    }

    Vector3D operator+(const Vector3D& vec) const
    {
        return Vector3D(
            this->x + vec.x,
            this->y + vec.y,
            this->z + vec.z);
    }

    Vector3D operator-(const Vector3D& vec) const
    {
        return Vector3D(
            this->x - vec.x,
            this->y - vec.y,
            this->z - vec.z);
    }

    Vector3D operator*(double factor) const
    {
        return Vector3D(
            this->x * factor,
            this->y * factor,
            this->z * factor);
    }
    
    bool operator==(const Vector3D& vec) const
    {
        const double diff = 1e-9;
        return (fabs(this->x - vec.x) < diff &&
                fabs(this->y - vec.y) < diff &&
                fabs(this->z - vec.z) < diff);
    }

    bool operator!=(const Vector3D& vec) const
    {
        return !(*this == vec);
    }
};


#endif // ENGINE_MATH_VECTOR_H
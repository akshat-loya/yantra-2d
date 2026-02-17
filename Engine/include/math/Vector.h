/* 
 * ====================================================================
 * A custom Vector file that lets users define and manipulate a
 * vector in 3D space. Can be used in 2D by passing z=0 (or constant).
 * ====================================================================
 */

 // XXX : Read about #pragma once
#pragma once

#include <cmath>

class Vector3D
{
public:
    double x, y, z;

    constexpr Vector3D() noexcept : x(0), y(0), z(0) {}
    constexpr Vector3D(double x, double y, double z) noexcept : x(x), y(y), z(z) {}

    Vector3D(const Vector3D& vec) = default;
    Vector3D& operator=(const Vector3D& vec) = default;
    Vector3D(Vector3D&& vec) = default;
    Vector3D& operator=(Vector3D&& vec) = default;
    ~Vector3D() = default;

    inline double dot(const Vector3D& vec1, const Vector3D& vec2)
    {
        return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
    }

    inline Vector3D cross(const Vector3D& vec1, const Vector3D& vec2)
    {
        return Vector3D( 
            vec1.y * vec2.z - vec1.z * vec2.y,
            vec1.z * vec2.x - vec1.x * vec2.z,
            vec1.x * vec2.y - vec1.y * vec2.x);
    }

    double magnitude() const noexcept
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    Vector3D unitVec() const
    {
        double mag = this->magnitude();
        if (mag == 0.0) return Vector3D(0,0,0);
        return Vector3D(x / mag, y / mag, z / mag);
    }

    Vector3D operator+(const Vector3D& vec) const noexcept
    {
        return { x + vec.x, y + vec.y, z + vec.z };
    }

    Vector3D operator-(const Vector3D& vec) const noexcept
    {
        return { x - vec.x, y - vec.y, z - vec.z };
    }

    Vector3D operator*(double factor) const noexcept
    {
        return { x + factor, y + factor, z + factor };
    }
    
    bool operator==(const Vector3D& vec) const
    {
        const double diff = 1e-9;
        return (std::fabs(this->x - vec.x) < diff &&
                std::fabs(this->y - vec.y) < diff &&
                std::fabs(this->z - vec.z) < diff);
    }

    bool operator!=(const Vector3D& vec) const noexcept
    {
        return !(*this == vec);
    }
};
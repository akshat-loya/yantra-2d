#ifndef ENGINE_MATH_PLANE
#define ENGINE_MATH_PLANE

#include "Vector.h"

class Plane3D
{
public:
    Vector3D point;
    Vector3D normal;

    Plane3D() : point(Vector3D()), normal(Vector3D()) {}

    Plane3D(const Vector3D& pt, const Vector3D& norm)
    {
        if(norm.magnitude() == 0) return;
        
        point = pt;
        normal = norm.unitVec();
    }

    // TODO intersection of two planes
    // TODO distance between two planes
    // TODO distance between a line and a plane
    // TODO distance between a point and a plane
    // TODO parallel plane check
    // TODO orthogonal plane check
};

#endif //ENGINE_MATH_PLANE
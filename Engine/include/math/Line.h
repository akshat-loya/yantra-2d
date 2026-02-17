#pragma once

#include "Vector.h"

class Line3D
{
public:
    Vector3D point;
    Vector3D direction;

    Line3D() : point(Vector3D(0, 0 ,0)), direction(Vector3D(0, 0 ,0)) {};

    Line3D(const Vector3D& pt, const Vector3D& dir)
    {
        if(dir.magnitude() == 0) return;

        point = pt;
        direction = dir.unitVec();
    }

    // TODO : intersection of two line
    // TODO : distance of a point from a line (here or where?)
    // TODO : distance between two lines?
    // TODO : is_parallel/is_perpendicular/is_orthogonal check?
};
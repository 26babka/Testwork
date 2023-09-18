#pragma once

#include <cmath>

#include <curves/vector3d.h>

namespace curves
{
    class CurvesBase
    {
    protected:
        Vector3d pos_;

    public:
        CurvesBase(const double x, const double y, const double z) : pos_(x, y, z) { } ;
        virtual Vector3d get_point(const double t) = 0;
        virtual Vector3d get_derivative(const double t) = 0;
        virtual ~CurvesBase() = default;
    };
}
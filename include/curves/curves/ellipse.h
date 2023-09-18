#pragma once

#include <curves/curves_base.h>
#include <curves/vector3d.h>

namespace curves
{
    class Ellipse : public CurvesBase
    {
    private:
        double r1_;
        double r2_;
        
    public:
        Ellipse(const double x, const double y, const double r1, const double r2);
        Vector3d get_point(const double t) override;
        Vector3d get_derivative(const double t) override;
    };
}
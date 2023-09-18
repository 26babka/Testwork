#pragma once

#include <curves/curves_base.h>
#include <curves/vector3d.h>

namespace curves
{
    class Helix : public CurvesBase
    {
    private:
        double r_;
        double step_;
        
    public:
        Helix(const double x, const double y, const double z, const double r, const double step);
        Vector3d get_point(const double t) override;
        Vector3d get_derivative(const double t) override;
    };
}
#pragma once

#include <curves/curves_base.h>
#include <curves/vector3d.h>

namespace curves
{
    class Circle : public CurvesBase
    {
    private:
        double r_;
        
    public:
        Circle(const double x, const double y, const double r);
        Vector3d get_point(const double t) override;
        Vector3d get_derivative(const double t) override;
        double get_radius() const;
    };
}
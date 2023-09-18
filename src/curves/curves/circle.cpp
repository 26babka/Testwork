#include <curves/circle.h>

curves::Circle::Circle(const double x, const double y, const double r) : CurvesBase(x, y, 0), r_(r)
{
    if (r < 0) {
        throw std::invalid_argument("Radius must be greater than zero");
    }
}

curves::Vector3d curves::Circle::get_point(const double t)
{
    return Vector3d(r_ * std::cos(t) + pos_.x(), r_ * std::sin(t) + pos_.y(), pos_.z());
}

curves::Vector3d curves::Circle::get_derivative(const double t)
{
    return Vector3d(r_ * -std::sin(t), r_ * std::cos(t), 0);
}

double curves::Circle::get_radius() const
{
    return r_;
}


#include <curves/ellipse.h>

curves::Ellipse::Ellipse(const double x, const double y, const double r1, const double r2) : CurvesBase(x, y, 0), r1_(r1), r2_(r2) {
    if (r1 < 0 || r2 < 0) {
        throw std::invalid_argument("Radius must be greater than zero");
    }
}

curves::Vector3d curves::Ellipse::get_point(const double t)
{
    return Vector3d(r1_ * std::cos(t) + pos_.x(), r2_ * std::sin(t) + pos_.y(), pos_.z());
}

curves::Vector3d curves::Ellipse::get_derivative(const double t)
{
    return Vector3d(r1_ * -std::sin(t), r2_ * std::cos(t), 0);
}

#include <cmath>

#include <curves/helix.h>

curves::Helix::Helix(const double x, const double y, const double z, const double r, const double step) : CurvesBase(x, y, z), r_(r), step_(step) {
    if (r < 0) {
        throw std::invalid_argument("Radius must be greater than zero");
    }
}

curves::Vector3d curves::Helix::get_point(const double t)
{
    return Vector3d(r_ * std::cos(t) + pos_.x(), r_ * std::sin(t) + pos_.y(), step_ * t / (2 * M_PI) + pos_.z());
}

curves::Vector3d curves::Helix::get_derivative(const double t)
{
    return Vector3d(r_ * -std::sin(t), r_ * std::cos(t), step_ / (2 * M_PI));
}

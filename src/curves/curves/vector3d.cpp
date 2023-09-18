#include <curves/vector3d.h>
#include <iomanip>

curves::Vector3d::Vector3d(const double x, const double y, const double z) : x_(x), y_(y), z_(z) { }

double curves::Vector3d::x() const
{
    return x_;
}

double curves::Vector3d::y() const
{
    return y_;
}

double curves::Vector3d::z() const
{
    return z_;
}

std::ostream& operator<<(std::ostream &out, const curves::Vector3d &vector)
{
    out << std::setfill(' ') << "x: " <<  std::setw(6) << vector.x() 
                            << " y: " << std::setw(6) << vector.y() 
                            << " z: " << std::setw(6) <<  vector.z();
    return out;
}
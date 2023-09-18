#pragma once

#include <iostream>

namespace curves 
{
    class Vector3d
    {
    private:
        double x_;
        double y_;
        double z_;
    
    public:
        Vector3d(const double x, const double y, const double z);
        double x() const;
        double y() const;
        double z() const;
    };
}

std::ostream& operator<<(std::ostream &out, const curves::Vector3d &vector);
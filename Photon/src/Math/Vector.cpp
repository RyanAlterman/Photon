#include "Math/Vector.hpp"

namespace Photon
{
    Vector::Vector(float x, float y, float z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
        m_data[3] = 0.0f;
    }

    Vector::~Vector()
    {
        // NOTE: Currently does nothing
    }
}
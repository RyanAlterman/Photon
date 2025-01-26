#include "Math/Point.hpp"

namespace Photon
{
    Point::Point(float x, float y, float z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
        m_data[3] = 1.0f;
    }

    Point::~Point()
    {
        // NOTE: Currently does nothing
    }
}
#include "Collision/Ray.hpp"

namespace Photon
{
    Ray::Ray(const Point &origin, const Vector &direction)
    {
        m_origin = origin;
        m_direction = direction;
    }

    Ray::~Ray()
    {
        // NOTE: Currently does nothing
    }

    Point Ray::At(double t) const
    {
        return m_origin + t * m_direction;
    }
}
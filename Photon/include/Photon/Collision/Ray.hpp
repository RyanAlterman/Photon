#pragma once

#include "../Math/Point.hpp"
#include "../Math/Vector.hpp"

namespace Photon
{
    class Ray
    {
    public:
        Ray(const Point &origin, const Vector &direction);
        ~Ray();

        Point At(double t) const;

        const Point &Origin() const { return m_origin; }
        const Vector &Direction() const { return m_direction; }

    protected:
    private:
        Point m_origin;
        Vector m_direction;
    };
}
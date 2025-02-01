#include "Math/MathUtils.hpp"

#include <cmath>

namespace Photon
{
    float degToRad(float angle)
    {
        return (M_PI / 180.0f) * angle;
    }
}
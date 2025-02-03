#include "Color/Color.hpp"

namespace Photon
{
    Color::Color(float r, float g, float b)
    {
        m_data[0] = Clamp(r);
        m_data[1] = Clamp(g);
        m_data[2] = Clamp(b);
    }

    Color::Color(const Color &obj)
    {
        m_data[0] = Clamp(obj.m_data[0]);
        m_data[1] = Clamp(obj.m_data[1]);
        m_data[2] = Clamp(obj.m_data[2]);
    }

    Color::~Color()
    {
        // NOTE: Currently does nothing
    }
}
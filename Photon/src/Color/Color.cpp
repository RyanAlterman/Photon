#include "Color/Color.hpp"

namespace Photon
{
    Color::Color(float r, float g, float b)
    {
        m_data[0] = r;
        m_data[1] = g;
        m_data[2] = b;
    }

    Color::Color(const Color &obj)
    {
        m_data[0] = obj.m_data[0];
        m_data[1] = obj.m_data[1];
        m_data[2] = obj.m_data[2];
    }

    Color::~Color()
    {
        // NOTE: Currently does nothing
    }
}
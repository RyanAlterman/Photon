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

    Color &Color::operator+=(const Color &rhs)
    {
        m_data[0] += rhs.m_data[0];
        m_data[1] += rhs.m_data[1];
        m_data[2] += rhs.m_data[2];
        return *this;
    }

    Color &Color::operator-=(const Color &rhs)
    {
        m_data[0] -= rhs.m_data[0];
        m_data[1] -= rhs.m_data[1];
        m_data[2] -= rhs.m_data[2];
        return *this;
    }

    Color &Color::operator*=(const float rhs)
    {
        m_data[0] *= rhs;
        m_data[1] *= rhs;
        m_data[2] *= rhs;
        return *this;
    }

    Color &Color::operator*=(const Color &rhs)
    {
        m_data[0] *= rhs.m_data[0];
        m_data[1] *= rhs.m_data[1];
        m_data[2] *= rhs.m_data[2];
        return *this;
    }

    Color &operator+(Color lhs, const Color &rhs)
    {
        return lhs += rhs;
    }

    Color &operator-(Color lhs, const Color &rhs)
    {
        return lhs -= rhs;
    }

    Color &operator*(Color lhs, const float rhs)
    {
        return lhs *= rhs;
    }

    Color &operator*(const float lhs, Color rhs)
    {
        return rhs *= lhs;
    }

    Color &operator*(Color lhs, const Color &rhs)
    {
        return lhs *= rhs;
    }
}
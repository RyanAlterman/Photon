#include "Math/Point.hpp"

#include <cmath>

namespace Photon
{
    Point::Point(float x, float y, float z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    Point::Point(const Point &obj)
    {
        m_data[0] = obj.m_data[0];
        m_data[1] = obj.m_data[1];
        m_data[2] = obj.m_data[2];
    }

    Point::~Point()
    {
        // NOTE: Currently does nothing
    }

    float Point::Distance(const Point &obj)
    {
        return std::sqrtf(DistanceSquared(obj));
    }

    float Point::DistanceSquared(const Point &obj)
    {
        float x = (m_data[0] - obj.m_data[0]);
        float y = (m_data[1] - obj.m_data[1]);
        float z = (m_data[2] - obj.m_data[2]);
        return (x * x) + (y * y) + (z * z);
    }

    Point &Point::operator=(const Point &obj)
    {
        m_data[0] = obj.m_data[0];
        m_data[1] = obj.m_data[1];
        m_data[2] = obj.m_data[2];
        return *this;
    }

    Point &Point::operator+=(const Vector &rhs)
    {
        m_data[0] += rhs.GetX();
        m_data[1] += rhs.GetY();
        m_data[2] += rhs.GetZ();
        return *this;
    }

    Point &Point::operator-=(const Vector &rhs)
    {
        m_data[0] -= rhs.GetX();
        m_data[1] -= rhs.GetY();
        m_data[2] -= rhs.GetZ();
        return *this;
    }

    Point Point::operator*=(const float rhs)
    {
        m_data[0] *= rhs;
        m_data[1] *= rhs;
        m_data[2] *= rhs;
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const Point &rhs)
    {
        return out << "(" << rhs.GetX() << ", " << rhs.GetY() << ", " << rhs.GetZ() << ")";
    }

    Point operator+(Point lhs, const Vector &rhs)
    {
        return lhs += rhs;
    }

    Point operator-(Point lhs, const Vector &rhs)
    {
        return lhs -= rhs;
    }

    Vector operator-(Point lhs, const Point &rhs)
    {
        Vector vec;

        vec.SetX(lhs.GetX() - rhs.GetX());
        vec.SetY(lhs.GetY() - rhs.GetY());
        vec.SetZ(lhs.GetZ() - rhs.GetZ());

        return vec;
    }

    Point operator*(Point lhs, const float rhs)
    {
        return lhs *= rhs;
    }

    Point operator*(const float lhs, Point rhs)
    {
        return rhs *= lhs;
    }
}
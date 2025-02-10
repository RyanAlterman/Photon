#include "Math/Vector.hpp"

#include <cmath>

namespace Photon
{
    Vector::Vector(float x, float y, float z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    Vector::Vector(const Vector &obj)
    {
        m_data[0] = obj.m_data[0];
        m_data[1] = obj.m_data[1];
        m_data[2] = obj.m_data[2];
    }

    Vector::~Vector()
    {
        // NOTE: Currently does nothing
    }

    Vector &Vector::operator=(const Vector &obj)
    {
        m_data[0] = obj.m_data[0];
        m_data[1] = obj.m_data[1];
        m_data[2] = obj.m_data[2];
        return *this;
    }

    Vector &Vector::operator+=(const Vector &obj)
    {
        m_data[0] += obj.m_data[0];
        m_data[1] += obj.m_data[1];
        m_data[2] += obj.m_data[2];
        return *this;
    }

    Vector &Vector::operator-=(const Vector &obj)
    {
        m_data[0] -= obj.m_data[0];
        m_data[1] -= obj.m_data[1];
        m_data[2] -= obj.m_data[2];
        return *this;
    }

    Vector &Vector::operator*=(const float val)
    {
        m_data[0] *= val;
        m_data[1] *= val;
        m_data[2] *= val;
        return *this;
    }

    Vector &Vector::operator/=(const float val)
    {
        m_data[0] /= val;
        m_data[1] /= val;
        m_data[2] /= val;
        return *this;
    }

    Vector &Vector::operator-()
    {
        m_data[0] = -m_data[0];
        m_data[1] = -m_data[1];
        m_data[2] = -m_data[2];
        return *this;
    }

    float Vector::DotProduct(const Vector &obj)
    {
        return (m_data[0] * obj.m_data[0]) + (m_data[1] * obj.m_data[1]) + (m_data[2] * obj.m_data[2]);
    }

    Vector Vector::CrossProduct(const Vector &obj)
    {
        return Vector(
            (m_data[1] * obj.m_data[2]) - (m_data[2] * obj.m_data[1]),
            (m_data[2] * obj.m_data[0]) - (m_data[0] * obj.m_data[2]),
            (m_data[0] * obj.m_data[1]) - (m_data[1] * obj.m_data[0]));
    }

    float Vector::Magnitude()
    {
        return std::sqrtf(MagnitudeSquared());
    }

    float Vector::MagnitudeSquared()
    {
        return (m_data[0] * m_data[0]) + (m_data[1] * m_data[1]) + (m_data[2] * m_data[2]);
    }

    Vector &Vector::Normalize()
    {
        float mag = Magnitude();

        m_data[0] /= mag;
        m_data[1] /= mag;
        m_data[2] /= mag;
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const Vector &rhs)
    {
        return out << "(" << rhs.GetX() << ", " << rhs.GetY() << ", " << rhs.GetZ() << ")";
    }

    Vector operator+(Vector lhs, const Vector &rhs)
    {
        return lhs += rhs;
    }

    Vector operator-(Vector lhs, const Vector &rhs)
    {
        return lhs -= rhs;
    }

    Vector operator*(Vector lhs, const float val)
    {
        return lhs *= val;
    }

    Vector operator*(const float val, Vector rhs)
    {
        return rhs *= val;
    }

    Vector operator/(Vector lhs, const float val)
    {
        return lhs /= val;
    }
}
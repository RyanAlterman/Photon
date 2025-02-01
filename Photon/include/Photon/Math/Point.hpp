#pragma once

namespace Photon
{
    class Point
    {
    public:
        Point(float x = 0.0f, float y = 0.0f, float z = 0.0f);
        ~Point();

        inline float GetX() const { return m_data[0]; };
        inline void SetX(float val) { m_data[0] = val; };

        inline float GetY() const { return m_data[1]; };
        inline void SetY(float val) { m_data[1] = val; };

        inline float GetZ() { return m_data[2]; };
        inline void SetZ(float val) { m_data[2] = val; }

    protected:
    private:
        float m_data[3];
    };
}
#pragma once

#include "Vector.hpp"

namespace Photon
{
    /// @brief Represents a point in 3D cartesian space
    class Point
    {
    public:
        // ====================================================================
        //                          Constructors
        // ====================================================================
        /// @brief Constructs a new Point object
        /// @param x The x component of the point. Defaults to 0
        /// @param y The y component of the point. Defaults to 0
        /// @param z The z component of the point. Defaults to 0
        Point(float x = 0.0f, float y = 0.0f, float z = 0.0f);

        /// @brief Creates a new point object by copying the data from the
        ///         original point
        /// @param obj The original point that will be copied
        Point(const Point &obj);

        /// @brief Destroys a point object
        ~Point();

        // ====================================================================
        //                          Public Methods
        // ====================================================================
        /// @brief Returns the distance between two points. For calculations
        ///         where accuracy is less important, use the DistanceSquared
        ///         method
        /// @param obj The second point to find distance between
        /// @return The exact distance between two points
        float Distance(const Point &obj);

        /// @brief Returns the distance between two points without taking the
        ///         square root
        /// @param obj The second point to find the distance between
        /// @return The rough distance between two points
        float DistanceSquared(const Point &obj);

        // ====================================================================
        //                            Operators
        // ====================================================================
        Point &operator=(const Point &obj);

        // Point Vector Addition & Subtractions
        Point &operator+=(const Vector &rhs);
        Point &operator-=(const Vector &rhs);

        // Scalar Multiplication
        Point operator*=(const float rhs);

        // ====================================================================
        //                          Getters & Setters
        // ====================================================================
        /// @brief Retrieves the X component of the point
        /// @return The X component
        inline float GetX() const { return m_data[0]; };

        /// @brief Sets the X component of the point to the specified value
        /// @param val The value that will be set to
        inline void SetX(float val) { m_data[0] = val; };

        /// @brief Retrieves the Y component of the point
        /// @return The Y component
        inline float GetY() const { return m_data[1]; };

        /// @brief Sets the Y component of the point to the specified value
        /// @param val The value that will be set to
        inline void SetY(float val) { m_data[1] = val; };

        /// @brief Retrieves the Z component of the point
        /// @return The Z component
        inline float GetZ() const { return m_data[2]; };

        /// @brief Sets the Z component of the point to the specified value
        /// @param val The value that will be set to
        inline void SetZ(float val) { m_data[2] = val; }

    protected:
    private:
        float m_data[3];
    };

    // ========================================================================
    //                          Point Operators
    // ========================================================================
    std::ostream &operator<<(std::ostream &out, const Point &rhs);

    Point operator+(Point lhs, const Vector &rhs);
    Point operator-(Point lhs, const Vector &rhs);

    Vector operator-(Point lhs, const Point &rhs);

    Point operator*(Point lhs, const float rhs);
    Point operator*(const float lhs, Point rhs);
}
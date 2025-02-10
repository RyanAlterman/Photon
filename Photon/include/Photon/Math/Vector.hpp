#pragma once

#include <iostream>

namespace Photon
{
    /// @brief Represents a 3D vector in cartesian space
    class Vector
    {
    public:
        // ====================================================================
        //                              Constructors
        // ====================================================================
        /// @brief Constructs a new Vector object
        /// @param x The x component of the vector. Defaults to 0
        /// @param y The y component of the vector. Defaults to 0
        /// @param z The z component of the vector. Defaults to 0
        Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f);

        /// @brief Creates a new Vector object by copying the data from the
        ///         original vector
        /// @param obj The original vector that will be copied
        Vector(const Vector &obj);

        /// @brief Destroys a vector object
        ~Vector();

        // ====================================================================
        //                              Public Methods
        // ====================================================================
        /// @brief Finds the dot product of two vectors
        /// @param obj The second vector of the dot product
        /// @return A float representing the dot product
        float DotProduct(const Vector &obj);

        /// @brief Finds the cross product of two vectors
        /// @param obj The second vector of the cross product
        /// @return A vector representing the cross product
        Vector CrossProduct(const Vector &obj);

        /// @brief Calculates the magnitude of the Vector. For calculations
        ///        where accuracy is less important, use the MagnitudeSquared
        ///        method
        /// @return The exact magnitude of the vector
        float Magnitude();

        /// @brief Calculates the magnitude of a vector without taking the square root
        /// @return The rough magnitude of the vector
        float MagnitudeSquared();

        /// @brief Normalizes the vector
        /// @return The normalized vector
        Vector &Normalize();

        // ====================================================================
        //                              Operators
        // ====================================================================
        Vector &operator=(const Vector &obj);

        // Vector Addition & Subtraction
        Vector &operator+=(const Vector &obj);
        Vector &operator-=(const Vector &obj);

        // Scalar Multiplication
        Vector &operator*=(const float val);

        // Scalar Division
        Vector &operator/=(const float val);

        // Negation
        Vector &operator-();

        // ====================================================================
        //                          Getters & Setters
        // ====================================================================
        /// @brief Retreives the X component of the vector
        /// @return The X component
        inline float GetX() const { return m_data[0]; };

        /// @brief Sets the X component of the vector to the specified
        ///         value
        /// @param val The value that will be set to
        inline void SetX(float val) { m_data[0] = val; };

        /// @brief Retreives the Y component of the vector
        /// @return The Y component
        inline float GetY() const { return m_data[1]; };

        /// @brief Sets the Y component of the vector to the specified
        ///         value
        /// @param val The value that will be set to
        inline void SetY(float val) { m_data[1] = val; };

        /// @brief Retreives the Z component of the vector
        /// @return The Z component
        inline float GetZ() const { return m_data[2]; };

        /// @brief Sets the Z component of the vector to the specified
        ///         value
        /// @param val The value that will be set to
        inline void SetZ(float val) { m_data[2] = val; }

    protected:
    private:
        float m_data[3];
    };

    // ========================================================================
    //                            Vector Operators
    // ========================================================================
    std::ostream &operator<<(std::ostream &out, const Vector &rhs);

    Vector operator+(Vector lhs, const Vector &rhs);

    Vector operator-(Vector lhs, const Vector &rhs);

    Vector operator*(Vector lhs, const float val);
    Vector operator*(const float val, Vector rhs);

    Vector operator/(Vector lhs, const float val);
}
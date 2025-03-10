#pragma once

namespace Photon
{
    /// @brief Represents a color using RGB channels
    class Color
    {
    public:
        // ====================================================================
        //                          Constructors
        // ====================================================================
        /// @brief Constructs a new Color object
        /// @param r Represents the value of the red channel. Defaults to 0.
        ///          Expected range is 0-1
        /// @param g Represents the value of the green channel. Defaults to 0.
        ///          Expected range is 0-1
        /// @param b Represents the value of the blue channel. Defaults to 0.
        ///          Expected range is 0-1
        Color(float r = 0.0f, float g = 0.0f, float b = 0.0f);

        /// @brief Creates a new Color object by copying the data from the
        ///        original object
        /// @param obj The original object to copy
        Color(const Color &obj);

        /// @brief Destroys a Color object
        ~Color();

        // ====================================================================
        //                              Operators
        // ====================================================================
        Color &operator+=(const Color &rhs);
        Color &operator-=(const Color &rhs);
        Color &operator*=(const float rhs);
        Color &operator*=(const Color &rhs);

        // ====================================================================
        //                          Getters & Setters
        // ====================================================================
        /// @brief Returns the R channel of the color
        /// @return The R channel
        inline float GetR() const { return m_data[0]; }

        /// @brief Sets the value of the R channel of the color. The value is
        ///        clamped between 0 and 1
        /// @param r The value to be set
        inline void SetR(const float r) { m_data[0] = r; }

        /// @brief Returns the G channel of the color
        /// @return The G channel
        inline float GetG() const { return m_data[1]; }

        /// @brief Sets the value of the G channel of the color. The value is
        ///        clamped between 0 and 1
        /// @param g The value to be set
        inline void SetG(const float g) { m_data[1] = g; }

        /// @brief Returns the B channel of the color
        /// @return The B channel
        inline float GetB() const { return m_data[2]; }

        /// @brief Sets the value of the B channel of the color. The value is
        ///        clamped between 0 and 1
        /// @param b The value to be set
        inline void SetB(const float b) { m_data[2] = b; }

    protected:
    private:
        float m_data[3];
    };

    // ========================================================================
    //                          Point Operators
    // ========================================================================
    Color &operator+(Color lhs, const Color &rhs);
    Color &operator-(Color lhs, const Color &rhs);
    Color &operator*(Color lhs, const float rhs);
    Color &operator*(const float lhs, Color rhs);
    Color &operator*(Color lhs, const Color &rhs);
}
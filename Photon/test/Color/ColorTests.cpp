#include <Photon/Color/Color.hpp>
#include <gtest/gtest.h>

TEST(ColorTests, EmptyConstructor)
{
    Photon::Color color;

    EXPECT_FLOAT_EQ(0.0f, color.GetR());
    EXPECT_FLOAT_EQ(0.0f, color.GetG());
    EXPECT_FLOAT_EQ(0.0f, color.GetB());
}

TEST(ColorTests, Constructor)
{
    Photon::Color color(0.5f, 0.25f, 1.25f);

    EXPECT_FLOAT_EQ(color.GetR(), 0.5f);
    EXPECT_FLOAT_EQ(color.GetG(), 0.25f);
    EXPECT_FLOAT_EQ(color.GetB(), 1.25f);
}

TEST(ColorTests, CopyConstructor)
{
    Photon::Color c1(0.5f, 0.25f, 1.0f);
    Photon::Color c2(c1);

    EXPECT_FLOAT_EQ(c2.GetR(), 0.5f);
    EXPECT_FLOAT_EQ(c2.GetG(), 0.25f);
    EXPECT_FLOAT_EQ(c2.GetB(), 1.0f);
}

TEST(ColorTests, PartialConstructors)
{
    // Test only setting X
    Photon::Color c1(0.5f);

    EXPECT_FLOAT_EQ(c1.GetR(), 0.5f);
    EXPECT_FLOAT_EQ(c1.GetG(), 0.0f);
    EXPECT_FLOAT_EQ(c1.GetB(), 0.0f);

    // Test setting X and Y only
    Photon::Color c2(0.5f, 0.25f);

    EXPECT_FLOAT_EQ(c2.GetR(), 0.5f);
    EXPECT_FLOAT_EQ(c2.GetG(), 0.25f);
    EXPECT_FLOAT_EQ(c2.GetB(), 0.0f);
}

TEST(ColorTests, AddingColors)
{
    Photon::Color c1(0.9f, 0.6f, 0.75f);
    Photon::Color c2(0.7f, 0.1f, 0.25f);

    Photon::Color c3 = c1 + c2;
    EXPECT_FLOAT_EQ(c3.GetR(), 1.6f);
    EXPECT_FLOAT_EQ(c3.GetG(), 0.7f);
    EXPECT_FLOAT_EQ(c3.GetB(), 1.0f);

    c1 += c2;
    EXPECT_FLOAT_EQ(c1.GetR(), 1.6f);
    EXPECT_FLOAT_EQ(c1.GetG(), 0.7f);
    EXPECT_FLOAT_EQ(c1.GetB(), 1.0f);
}

TEST(ColorTests, SubtractingColors)
{
    Photon::Color c1(0.9f, 0.6f, 0.75f);
    Photon::Color c2(0.7f, 0.1f, 0.25f);

    Photon::Color c3 = c1 - c2;
    EXPECT_FLOAT_EQ(c3.GetR(), 0.2f);
    EXPECT_FLOAT_EQ(c3.GetG(), 0.5f);
    EXPECT_FLOAT_EQ(c3.GetB(), 0.5f);

    c1 -= c2;
    EXPECT_FLOAT_EQ(c1.GetR(), 0.2f);
    EXPECT_FLOAT_EQ(c1.GetG(), 0.5f);
    EXPECT_FLOAT_EQ(c1.GetB(), 0.5f);
}

TEST(ColorTests, ScalarColorMult)
{
    Photon::Color c1(0.2f, 0.3f, 0.4f);
    float scalar = 2.0f;

    Photon::Color c2 = c1 * scalar;
    EXPECT_FLOAT_EQ(c2.GetR(), 0.4f);
    EXPECT_FLOAT_EQ(c2.GetG(), 0.6f);
    EXPECT_FLOAT_EQ(c2.GetB(), 0.8f);

    c1 *= scalar;
    EXPECT_FLOAT_EQ(c1.GetR(), 0.4f);
    EXPECT_FLOAT_EQ(c1.GetG(), 0.6f);
    EXPECT_FLOAT_EQ(c1.GetB(), 0.8f);
}

TEST(ColorTests, ColorMultiplication)
{
    Photon::Color c1(1.0f, 0.2f, 0.4f);
    Photon::Color c2(0.9f, 1.0f, 0.1f);

    Photon::Color c3 = c1 * c2;
    EXPECT_FLOAT_EQ(c3.GetR(), 0.9f);
    EXPECT_FLOAT_EQ(c3.GetG(), 0.2f);
    EXPECT_FLOAT_EQ(c3.GetB(), 0.04f);

    c1 *= c2;
    EXPECT_FLOAT_EQ(c1.GetR(), 0.9f);
    EXPECT_FLOAT_EQ(c1.GetG(), 0.2f);
    EXPECT_FLOAT_EQ(c1.GetB(), 0.04f);
}
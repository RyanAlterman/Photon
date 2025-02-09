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
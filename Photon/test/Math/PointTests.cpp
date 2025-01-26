#include <Photon/Math/Point.hpp>
#include <gtest/gtest.h>

TEST(PointTests, EmptyConstructor)
{
    Photon::Point point;

    EXPECT_FLOAT_EQ(point.GetX(), 0.0f);
    EXPECT_FLOAT_EQ(point.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(point.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(point.GetW(), 1.0f);
}

TEST(PointTests, Constructor)
{
    Photon::Point point(4.3f, -4.2f, 3.1f);

    EXPECT_FLOAT_EQ(point.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(point.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(point.GetZ(), 3.1f);
    EXPECT_FLOAT_EQ(point.GetW(), 1.0f);
}

TEST(PointTests, PartialConstructors)
{
    // Test only setting X
    Photon::Point p1(4.3f);

    EXPECT_FLOAT_EQ(p1.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(p1.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(p1.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(p1.GetW(), 1.0f);

    // Test setting X and Y only
    Photon::Point p2(4.3f, -4.2f);

    EXPECT_FLOAT_EQ(p2.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(p2.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(p2.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(p2.GetW(), 1.0f);
}
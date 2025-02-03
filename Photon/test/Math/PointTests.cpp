#include <Photon/Math/Point.hpp>
#include <gtest/gtest.h>

TEST(PointTests, EmptyConstructor)
{
    Photon::Point point;

    EXPECT_FLOAT_EQ(point.GetX(), 0.0f);
    EXPECT_FLOAT_EQ(point.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(point.GetZ(), 0.0f);
}

TEST(PointTests, Constructor)
{
    Photon::Point point(4.3f, -4.2f, 3.1f);

    EXPECT_FLOAT_EQ(point.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(point.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(point.GetZ(), 3.1f);
}

TEST(PointTests, CopyConstructor)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Point p2(p1);

    EXPECT_FLOAT_EQ(4.3f, p2.GetX());
    EXPECT_FLOAT_EQ(-4.2f, p2.GetY());
    EXPECT_FLOAT_EQ(3.1f, p2.GetZ());
}

TEST(PointTests, PartialConstructors)
{
    // Test only setting X
    Photon::Point p1(4.3f);

    EXPECT_FLOAT_EQ(p1.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(p1.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(p1.GetZ(), 0.0f);

    // Test setting X and Y only
    Photon::Point p2(4.3f, -4.2f);

    EXPECT_FLOAT_EQ(p2.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(p2.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(p2.GetZ(), 0.0f);
}

TEST(PointTests, AssignmentOperator)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Point p2 = p1;

    EXPECT_FLOAT_EQ(4.3f, p2.GetX());
    EXPECT_FLOAT_EQ(-4.2f, p2.GetY());
    EXPECT_FLOAT_EQ(3.1f, p2.GetZ());
}

TEST(PointTests, PointVectorAddition)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Vector v1(7.2f, 3.1f, -1.5f);

    // Binary Addition
    Photon::Point p2 = p1 + v1;
    EXPECT_FLOAT_EQ(11.5f, p2.GetX());
    EXPECT_FLOAT_EQ(-1.1f, p2.GetY());
    EXPECT_FLOAT_EQ(1.6f, p2.GetZ());

    // Verify no change to p1...yet
    EXPECT_FLOAT_EQ(4.3f, p1.GetX());
    EXPECT_FLOAT_EQ(-4.2f, p1.GetY());
    EXPECT_FLOAT_EQ(3.1f, p1.GetZ());

    // Compound addition and assignment
    p1 += v1;
    EXPECT_FLOAT_EQ(11.5f, p1.GetX());
    EXPECT_FLOAT_EQ(-1.1f, p1.GetY());
    EXPECT_FLOAT_EQ(1.6f, p1.GetZ());
}

TEST(PointTests, PointVectorSubtraction)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Vector v1(7.2f, 3.1f, -1.5f);

    // Binary Addition
    Photon::Point p2 = p1 - v1;
    EXPECT_FLOAT_EQ(-2.9f, p2.GetX());
    EXPECT_FLOAT_EQ(-7.3f, p2.GetY());
    EXPECT_FLOAT_EQ(4.6f, p2.GetZ());

    // Verify no change to p1...yet
    EXPECT_FLOAT_EQ(4.3f, p1.GetX());
    EXPECT_FLOAT_EQ(-4.2f, p1.GetY());
    EXPECT_FLOAT_EQ(3.1f, p1.GetZ());

    // Compound addition and assignment
    p1 -= v1;
    EXPECT_FLOAT_EQ(-2.9f, p1.GetX());
    EXPECT_FLOAT_EQ(-7.3f, p1.GetY());
    EXPECT_FLOAT_EQ(4.6f, p1.GetZ());
}

TEST(PointTests, PointPointSubtraction)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Point p2(7.2f, 3.1f, -1.5f);

    // Binary Addition
    Photon::Vector v1 = p1 - p2;
    EXPECT_FLOAT_EQ(-2.9f, v1.GetX());
    EXPECT_FLOAT_EQ(-7.3f, v1.GetY());
    EXPECT_FLOAT_EQ(4.6f, v1.GetZ());
}

TEST(PointTests, ScalarMultiplication)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);

    Photon::Point p2 = p1 * 2.0f;
    EXPECT_FLOAT_EQ(p2.GetX(), 8.6);
    EXPECT_FLOAT_EQ(p2.GetY(), -8.4);
    EXPECT_FLOAT_EQ(p2.GetZ(), 6.2);

    Photon::Point p3 = 2.0f * p1;
    EXPECT_FLOAT_EQ(p3.GetX(), 8.6);
    EXPECT_FLOAT_EQ(p3.GetY(), -8.4);
    EXPECT_FLOAT_EQ(p3.GetZ(), 6.2);

    p1 *= 2.0f;
    EXPECT_FLOAT_EQ(p1.GetX(), 8.6);
    EXPECT_FLOAT_EQ(p1.GetY(), -8.4);
    EXPECT_FLOAT_EQ(p1.GetZ(), 6.2);
}

TEST(PointTests, Distance)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Point p2(7.2f, 3.1f, -1.5f);

    float dist = p1.Distance(p2);

    EXPECT_FLOAT_EQ(9.102747f, dist);
}

TEST(PointTests, DistanceSquared)
{
    Photon::Point p1(4.3f, -4.2f, 3.1f);
    Photon::Point p2(7.2f, 3.1f, -1.5f);

    float distSqrd = p1.DistanceSquared(p2);

    EXPECT_FLOAT_EQ(82.860002946009f, distSqrd);
}
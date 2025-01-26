#include <Photon/Math/Vector.hpp>
#include <gtest/gtest.h>

TEST(VectorTests, EmptyConstructor)
{
    Photon::Vector vector;

    EXPECT_FLOAT_EQ(vector.GetX(), 0.0f);
    EXPECT_FLOAT_EQ(vector.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(vector.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(vector.GetW(), 0.0f);
}

TEST(VectorTests, Constructor)
{
    Photon::Vector vector(4.3f, -4.2f, 3.1f);

    EXPECT_FLOAT_EQ(vector.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(vector.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(vector.GetZ(), 3.1f);
    EXPECT_FLOAT_EQ(vector.GetW(), 0.0f);
}

TEST(VectorTests, PartialConstructors)
{
    // Test only setting X
    Photon::Vector v1(4.3f);

    EXPECT_FLOAT_EQ(v1.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(v1.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(v1.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(v1.GetW(), 0.0f);

    // Test setting X and Y only
    Photon::Vector v2(4.3f, -4.2f);

    EXPECT_FLOAT_EQ(v2.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(v2.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(v2.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(v2.GetW(), 0.0f);
}
#include <Photon/Math/Vector.hpp>
#include <gtest/gtest.h>

TEST(VectorTests, EmptyConstructor)
{
    Photon::Vector vector;

    EXPECT_FLOAT_EQ(vector.GetX(), 0.0f);
    EXPECT_FLOAT_EQ(vector.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(vector.GetZ(), 0.0f);
}

TEST(VectorTests, Constructor)
{
    Photon::Vector vector(4.3f, -4.2f, 3.1f);

    EXPECT_FLOAT_EQ(vector.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(vector.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(vector.GetZ(), 3.1f);
}

TEST(VectorTests, CopyConstructor)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);
    Photon::Vector v2(v1);

    EXPECT_FLOAT_EQ(4.3f, v2.GetX());
    EXPECT_FLOAT_EQ(-4.2f, v2.GetY());
    EXPECT_FLOAT_EQ(3.1f, v2.GetZ());
}

TEST(VectorTests, PartialConstructors)
{
    // Test only setting X
    Photon::Vector v1(4.3f);

    EXPECT_FLOAT_EQ(v1.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(v1.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(v1.GetZ(), 0.0f);

    // Test setting X and Y only
    Photon::Vector v2(4.3f, -4.2f);

    EXPECT_FLOAT_EQ(v2.GetX(), 4.3f);
    EXPECT_FLOAT_EQ(v2.GetY(), -4.2f);
    EXPECT_FLOAT_EQ(v2.GetZ(), 0.0f);
}

TEST(VectorTests, AssignmentOperator)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);
    Photon::Vector v2 = v1;

    EXPECT_FLOAT_EQ(4.3f, v2.GetX());
    EXPECT_FLOAT_EQ(-4.2f, v2.GetY());
    EXPECT_FLOAT_EQ(3.1f, v2.GetZ());
}

TEST(VectorTests, VectorAddition)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);
    Photon::Vector v2(7.2f, 3.1f, -1.5f);

    // Binary Addition
    Photon::Vector v3 = v1 + v2;
    EXPECT_FLOAT_EQ(11.5f, v3.GetX());
    EXPECT_FLOAT_EQ(-1.1f, v3.GetY());
    EXPECT_FLOAT_EQ(1.6f, v3.GetZ());

    // Verify no change to v1...yet
    EXPECT_FLOAT_EQ(4.3f, v1.GetX());
    EXPECT_FLOAT_EQ(-4.2f, v1.GetY());
    EXPECT_FLOAT_EQ(3.1f, v1.GetZ());

    // Compound addition and assignment
    v1 += v2;
    EXPECT_FLOAT_EQ(11.5f, v1.GetX());
    EXPECT_FLOAT_EQ(-1.1f, v1.GetY());
    EXPECT_FLOAT_EQ(1.6f, v1.GetZ());
}

TEST(VectorTests, VectorSubtraction)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);
    Photon::Vector v2(7.2f, 3.1f, -1.5f);

    // Binary Addition
    Photon::Vector v3 = v1 - v2;
    EXPECT_FLOAT_EQ(-2.9f, v3.GetX());
    EXPECT_FLOAT_EQ(-7.3f, v3.GetY());
    EXPECT_FLOAT_EQ(4.6f, v3.GetZ());

    // Verify no change to v1...yet
    EXPECT_FLOAT_EQ(4.3f, v1.GetX());
    EXPECT_FLOAT_EQ(-4.2f, v1.GetY());
    EXPECT_FLOAT_EQ(3.1f, v1.GetZ());

    // Compound addition and assignment
    v1 -= v2;
    EXPECT_FLOAT_EQ(-2.9f, v1.GetX());
    EXPECT_FLOAT_EQ(-7.3f, v1.GetY());
    EXPECT_FLOAT_EQ(4.6f, v1.GetZ());
}

TEST(VectorTests, ScalarMultiplication)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);

    Photon::Vector v2 = v1 * 2.0f;
    EXPECT_FLOAT_EQ(v2.GetX(), 8.6);
    EXPECT_FLOAT_EQ(v2.GetY(), -8.4);
    EXPECT_FLOAT_EQ(v2.GetZ(), 6.2);

    Photon::Vector v3 = 2.0f * v1;
    EXPECT_FLOAT_EQ(v3.GetX(), 8.6);
    EXPECT_FLOAT_EQ(v3.GetY(), -8.4);
    EXPECT_FLOAT_EQ(v3.GetZ(), 6.2);

    v1 *= 2.0f;
    EXPECT_FLOAT_EQ(v1.GetX(), 8.6);
    EXPECT_FLOAT_EQ(v1.GetY(), -8.4);
    EXPECT_FLOAT_EQ(v1.GetZ(), 6.2);
}

TEST(VectorTests, ScalarDivision)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);

    Photon::Vector v2 = v1 / 4.3f;
    EXPECT_FLOAT_EQ(v2.GetX(), 1.0);
    EXPECT_FLOAT_EQ(v2.GetY(), -0.97674418604651162790697674418605);
    EXPECT_FLOAT_EQ(v2.GetZ(), 0.72093023255813953488372093023256);

    v1 /= 4.3f;
    EXPECT_FLOAT_EQ(v1.GetX(), 1.0);
    EXPECT_FLOAT_EQ(v1.GetY(), -0.97674418604651162790697674418605);
    EXPECT_FLOAT_EQ(v1.GetZ(), 0.72093023255813953488372093023256);
}

TEST(VectorTests, Negation)
{
    Photon::Vector v1(4.3f, -4.2f, 3.1f);
    v1 = -v1;

    EXPECT_FLOAT_EQ(v1.GetX(), -4.3f);
    EXPECT_FLOAT_EQ(v1.GetY(), 4.2f);
    EXPECT_FLOAT_EQ(v1.GetZ(), -3.1f);
}

TEST(VectorTests, Magnitude)
{
    Photon::Vector v1(2.0f, 4.0f, -2.0f);

    EXPECT_FLOAT_EQ(v1.Magnitude(), 4.8989794855663561963945681494118);
    EXPECT_FLOAT_EQ(v1.MagnitudeSquared(), 24.0f);
}

TEST(VectorTests, DotProduct)
{
    Photon::Vector v1(1.0f, 2.0f, 3.0f);
    Photon::Vector v2(1.0f, 5.0f, 7.0f);

    EXPECT_FLOAT_EQ(v1.DotProduct(v2), 32.0f);
}

TEST(VectorTests, CrossProduct)
{
    Photon::Vector v1(1.0f, 2.0f, 3.0f);
    Photon::Vector v2(1.0f, 5.0f, 7.0f);

    Photon::Vector v3 = v1.CrossProduct(v2);

    EXPECT_FLOAT_EQ(v3.GetX(), -1.0f);
    EXPECT_FLOAT_EQ(v3.GetY(), -4.0f);
    EXPECT_FLOAT_EQ(v3.GetZ(), 3.0f);
}

TEST(VectorTests, Normalization)
{
    Photon::Vector v1(4.0f, 0.0f, 0.0f);

    v1.Normalize();
    EXPECT_FLOAT_EQ(v1.GetX(), 1.0f);
    EXPECT_FLOAT_EQ(v1.GetY(), 0.0f);
    EXPECT_FLOAT_EQ(v1.GetZ(), 0.0f);
    EXPECT_FLOAT_EQ(v1.Magnitude(), 1.0f);

    Photon::Vector v2(1.0f, 2.0f, 3.0f);

    v2.Normalize();
    EXPECT_FLOAT_EQ(v2.GetX(), 0.26726124191242438468455348087975);
    EXPECT_FLOAT_EQ(v2.GetY(), 0.53452248382484876936910696175951);
    EXPECT_FLOAT_EQ(v2.GetZ(), 0.80178372573727315405366044263926);
    EXPECT_FLOAT_EQ(v2.Magnitude(), 1.0f);
}
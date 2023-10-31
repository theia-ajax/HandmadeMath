#include "../HandmadeTest.h"

TEST(ScalarMath, Trigonometry)
{
    // We have to be a little looser with our equality constraint
    // because of floating-point precision issues.
    const float trigAbsError = 0.0001f;

    EXPECT_NEAR(SinF(0.0f), 0.0f, trigAbsError);
    EXPECT_NEAR(SinF(KPi32 / 2), 1.0f, trigAbsError);
    EXPECT_NEAR(SinF(KPi32), 0.0f, trigAbsError);
    EXPECT_NEAR(SinF(3 * KPi32 / 2), -1.0f, trigAbsError);
    EXPECT_NEAR(SinF(-KPi32 / 2), -1.0f, trigAbsError);

    EXPECT_NEAR(CosF(0.0f), 1.0f, trigAbsError);
    EXPECT_NEAR(CosF(KPi32 / 2), 0.0f, trigAbsError);
    EXPECT_NEAR(CosF(KPi32), -1.0f, trigAbsError);
    EXPECT_NEAR(CosF(3 * KPi32 / 2), 0.0f, trigAbsError);
    EXPECT_NEAR(CosF(-KPi32), -1.0f, trigAbsError);

    EXPECT_NEAR(TanF(0.0f), 0.0f, trigAbsError);
    EXPECT_NEAR(TanF(KPi32 / 4), 1.0f, trigAbsError);
    EXPECT_NEAR(TanF(3 * KPi32 / 4), -1.0f, trigAbsError);
    EXPECT_NEAR(TanF(KPi32), 0.0f, trigAbsError);
    EXPECT_NEAR(TanF(-KPi32 / 4), -1.0f, trigAbsError);

    // This isn't the most rigorous because we're really just sanity-
    // checking that things work by default.
}

TEST(ScalarMath, SquareRoot)
{
    EXPECT_FLOAT_EQ(SqrtF(16.0f), 4.0f);
}

TEST(ScalarMath, RSquareRootF)
{
    EXPECT_NEAR(InvSqrtF(10.0f), 0.31616211f, 0.0001f);
}

TEST(ScalarMath, Min)
{
    float A = -2.0f, B = 0.0f, C = 5.0f;
    EXPECT_FLOAT_EQ(Min(A, B), A);
    EXPECT_FLOAT_EQ(Min(B, C), B);
    EXPECT_FLOAT_EQ(Min(A, C), A);
}

TEST(ScalarMath, Max)
{
    float A = -2.0f, B = 0.0f, C = 5.0f;
    EXPECT_FLOAT_EQ(Max(A, B), B);
    EXPECT_FLOAT_EQ(Max(B, C), C);
    EXPECT_FLOAT_EQ(Max(A, C), C);
}

TEST(ScalarMath, Abs)
{
    EXPECT_FLOAT_EQ(Abs(-1.0f), 1.0f);
    EXPECT_FLOAT_EQ(Abs(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(Abs(2.0f), 2.0f);
}

TEST(ScalarMath, Lerp)
{
    EXPECT_FLOAT_EQ(Lerp(-2.0f, 2.0f, 0.0f), -2.0f);
    EXPECT_FLOAT_EQ(Lerp(-2.0f, 2.0f, 0.5f), 0.0f);
    EXPECT_FLOAT_EQ(Lerp(-2.0f, 2.0f, 1.0f), 2.0f);
}

TEST(ScalarMath, Clamp)
{
    EXPECT_FLOAT_EQ(Clamp(0.0f, -2.0f, 2.0f), 0.0f);
    EXPECT_FLOAT_EQ(Clamp(-3.0f, -2.0f, 2.0f), -2.0f);
    EXPECT_FLOAT_EQ(Clamp(3.0f, -2.0f, 2.0f), 2.0f);
}

TEST(ScalarMath, IsFinite)
{
    EXPECT_TRUE(IsFinite(-5.0f));
    EXPECT_TRUE(IsFinite(239));
    EXPECT_TRUE(IsFinite(3059.32f));
    EXPECT_FALSE(IsFinite(NAN));
    EXPECT_FALSE(IsFinite(INFINITY));
    EXPECT_FALSE(IsFinite(-INFINITY));
    EXPECT_FALSE(IsFinite(-NAN));
}

TEST(ScalarMath, Approx)
{
    EXPECT_TRUE(Approx(0.0f, 0.0f));
    EXPECT_TRUE(Approx(0.0f, KEpsilonFloat32));
    EXPECT_TRUE(Approx(0.0f, -KEpsilonFloat32));
    EXPECT_FALSE(Approx(0.0f, KEpsilonFloat32 * 2));
    EXPECT_FALSE(Approx(-1.0f, 1.0f));
}
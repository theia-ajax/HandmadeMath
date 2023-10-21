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

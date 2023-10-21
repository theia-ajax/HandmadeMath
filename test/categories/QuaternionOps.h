#include "../HandmadeTest.h"

TEST(QuaternionOps, Inverse)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat inverse = InvQ(q1);

    Quat result = MulQ(q1, inverse);

    EXPECT_FLOAT_EQ(result.X, 0.0f);
    EXPECT_FLOAT_EQ(result.Y, 0.0f);
    EXPECT_FLOAT_EQ(result.Z, 0.0f);
    EXPECT_FLOAT_EQ(result.W, 1.0f);
}

TEST(QuaternionOps, Dot)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        float result = DotQ(q1, q2);
        EXPECT_FLOAT_EQ(result, 70.0f);
    }
#ifdef __cplusplus
    {
        float result = Dot(q1, q2);
        EXPECT_FLOAT_EQ(result, 70.0f);
    }
#endif
}

TEST(QuaternionOps, Normalize)
{
    Quat q = Q(1.0f, 2.0f, 3.0f, 4.0f);

    {
        Quat result = NormQ(q);
        EXPECT_NEAR(result.X, 0.1825741858f, 0.001f);
        EXPECT_NEAR(result.Y, 0.3651483717f, 0.001f);
        EXPECT_NEAR(result.Z, 0.5477225575f, 0.001f);
        EXPECT_NEAR(result.W, 0.7302967433f, 0.001f);
    }
#ifdef __cplusplus
    {
        Quat result = Norm(q);
        EXPECT_NEAR(result.X, 0.1825741858f, 0.001f);
        EXPECT_NEAR(result.Y, 0.3651483717f, 0.001f);
        EXPECT_NEAR(result.Z, 0.5477225575f, 0.001f);
        EXPECT_NEAR(result.W, 0.7302967433f, 0.001f);
    }
#endif
}

TEST(QuaternionOps, NLerp)
{
    Quat from = Q(0.0f, 0.0f, 0.0f, 1.0f);
    Quat to = Q(0.5f, 0.5f, -0.5f, 0.5f);

    Quat result = NLerp(from, to, 0.5f);
    EXPECT_NEAR(result.X, 0.28867513f, 0.001f);
    EXPECT_NEAR(result.Y, 0.28867513f, 0.001f);
    EXPECT_NEAR(result.Z, -0.28867513f, 0.001f);
    EXPECT_NEAR(result.W, 0.86602540f, 0.001f);
}

TEST(QuaternionOps, SLerp)
{
    Quat from = Q(0.0f, 0.0f, 0.0f, 1.0f);
    Quat to = Q(0.5f, 0.5f, -0.5f, 0.5f);

    {
        Quat result = SLerp(from, to, 0.0f);
        EXPECT_NEAR(result.X, 0.0f, 0.001f);
        EXPECT_NEAR(result.Y, 0.0f, 0.001f);
        EXPECT_NEAR(result.Z, 0.0f, 0.001f);
        EXPECT_NEAR(result.W, 1.0, 0.001f);
    }
    {
        Quat result = SLerp(from, to, 0.25f);
        EXPECT_NEAR(result.X, 0.149429246f, 0.001f);
        EXPECT_NEAR(result.Y, 0.149429246f, 0.001f);
        EXPECT_NEAR(result.Z, -0.149429246f, 0.001f);
        EXPECT_NEAR(result.W, 0.965925812f, 0.001f);
    }
    {
        Quat result = SLerp(from, to, 0.5f);
        EXPECT_NEAR(result.X, 0.28867513f, 0.001f);
        EXPECT_NEAR(result.Y, 0.28867513f, 0.001f);
        EXPECT_NEAR(result.Z, -0.28867513f, 0.001f);
        EXPECT_NEAR(result.W, 0.86602540f, 0.001f);
    }
    {
        Quat result = SLerp(from, to, 0.75f);
        EXPECT_NEAR(result.X, 0.40824830f, 0.001f);
        EXPECT_NEAR(result.Y, 0.40824830f, 0.001f);
        EXPECT_NEAR(result.Z, -0.40824830f, 0.001f);
        EXPECT_NEAR(result.W, 0.70710676f, 0.001f);
    }
        {
        Quat result = SLerp(from, to, 1.0f);
        EXPECT_NEAR(result.X, 0.5f, 0.001f);
        EXPECT_NEAR(result.Y, 0.5f, 0.001f);
        EXPECT_NEAR(result.Z, -0.5f, 0.001f);
        EXPECT_NEAR(result.W, 0.5f, 0.001f);
    }
}

TEST(QuaternionOps, QuatToMat4)
{
    const float abs_error = 0.001f;

    Quat rot = Q(0.707107f, 0.0f, 0.0f, 0.707107f);

    Mat4 result = M4FromQ(rot);

    EXPECT_NEAR(result.Elements[0][0], 1.0f, abs_error);
    EXPECT_NEAR(result.Elements[0][1], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[0][2], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[0][3], 0.0f, abs_error);

    EXPECT_NEAR(result.Elements[1][0], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[1][1], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[1][2], 1.0f, abs_error);
    EXPECT_NEAR(result.Elements[1][3], 0.0f, abs_error);

    EXPECT_NEAR(result.Elements[2][0], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[2][1], -1.0f, abs_error);
    EXPECT_NEAR(result.Elements[2][2], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[2][3], 0.0f, abs_error);

    EXPECT_NEAR(result.Elements[3][0], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[3][1], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[3][2], 0.0f, abs_error);
    EXPECT_NEAR(result.Elements[3][3], 1.0f, abs_error);
}

TEST(QuaternionOps, Mat4ToQuat)
{
    const float abs_error = 0.0001f;

    // Rotate 90 degrees on the X axis
    {
        Mat4 m = Rotate_RH(AngleDeg(90.0f), V3(1, 0, 0));
        Quat result = M4ToQ_RH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, sinf, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 90 degrees on the Y axis (axis not normalized, just for fun)
    {
        Mat4 m = Rotate_RH(AngleDeg(90.0f), V3(0, 2, 0));
        Quat result = M4ToQ_RH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, 0.0f, abs_error);
        EXPECT_NEAR(result.Y, sinf, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 90 degrees on the Z axis
    {
        Mat4 m = Rotate_RH(AngleDeg(90.0f), V3(0, 0, 1));
        Quat result = M4ToQ_RH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, 0.0f, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, sinf, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 45 degrees on the X axis (this hits case 4)
    {
        Mat4 m = Rotate_RH(AngleDeg(45.0f), V3(1, 0, 0));
        Quat result = M4ToQ_RH(m);

        float cosf = 0.9238795325f; // cos(90/2 degrees)
        float sinf = 0.3826834324f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, sinf, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    /* NOTE(lcf): Left-handed cases. Since both Rotate and M4ToQ are LH results should be
        the same with no changes to input. */
    // Rotate 90 degrees on the X axis
    {
        Mat4 m = Rotate_LH(AngleDeg(90.0f), V3(1, 0, 0));
        Quat result = M4ToQ_LH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, sinf, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 90 degrees on the Y axis (axis not normalized, just for fun)
    {
        Mat4 m = Rotate_LH(AngleDeg(90.0f), V3(0, 2, 0));
        Quat result = M4ToQ_LH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, 0.0f, abs_error);
        EXPECT_NEAR(result.Y, sinf, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 90 degrees on the Z axis
    {
        Mat4 m = Rotate_LH(AngleDeg(90.0f), V3(0, 0, 1));
        Quat result = M4ToQ_LH(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, 0.0f, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, sinf, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }

    // Rotate 45 degrees on the X axis (this hits case 4)
    {
        Mat4 m = Rotate_LH(AngleDeg(45.0f), V3(1, 0, 0));
        Quat result = M4ToQ_LH(m);

        float cosf = 0.9238795325f; // cos(90/2 degrees)
        float sinf = 0.3826834324f; // sin(90/2 degrees)

        EXPECT_NEAR(result.X, sinf, abs_error);
        EXPECT_NEAR(result.Y, 0.0f, abs_error);
        EXPECT_NEAR(result.Z, 0.0f, abs_error);
        EXPECT_NEAR(result.W, cosf, abs_error);
    }
}

TEST(QuaternionOps, FromAxisAngle)
{
    Vec3 axis = V3(1.0f, 0.0f, 0.0f);
    float angle = KPi32 / 2.0f;

    {
        Quat result = QFromAxisAngle_RH(axis, angle);
        EXPECT_NEAR(result.X, 0.707107f, 0.001f);
        EXPECT_NEAR(result.Y, 0.0f, 0.001f);
        EXPECT_NEAR(result.Z, 0.0f, 0.001f);
        EXPECT_NEAR(result.W, 0.707107f, 0.001f);
    }
    {
        Quat result = QFromAxisAngle_LH(axis, angle);
        EXPECT_NEAR(result.X, -0.707107f, 0.001f);
        EXPECT_NEAR(result.Y, 0.0f, 0.001f);
        EXPECT_NEAR(result.Z, 0.0f, 0.001f);
        EXPECT_NEAR(result.W, 0.707107f, 0.001f);
    }
}

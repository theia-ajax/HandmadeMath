#include "../HandmadeTest.h"

TEST(Transformations, Translate)
{
    Mat4 translate = Translate(V3(1.0f, -3.0f, 6.0f));

    Vec3 original = V3(1.0f, 2.0f, 3.0f);
    Vec4 translated = MulM4V4(translate, V4V(original, 1));

    EXPECT_NEAR(translated.X, 2.0f, 0.001f);
    EXPECT_NEAR(translated.Y, -1.0f, 0.001f);
    EXPECT_NEAR(translated.Z, 9.0f, 0.001f);
    EXPECT_NEAR(translated.W, 1.0f, 0.001f);
}

TEST(Transformations, Rotate)
{
    Vec3 original = V3(1.0f, 1.0f, 1.0f);

    Mat4 rotateX = Rotate_RH(AngleDeg(90.0f), V3(1, 0, 0));
    Vec4 rotatedX = MulM4V4(rotateX, V4V(original, 1));
    EXPECT_NEAR(rotatedX.X, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.Y, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.Z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.W, 1.0f, 0.001f);

    Mat4 rotateY = Rotate_RH(AngleDeg(90.0f), V3(0, 1, 0));
    Vec4 rotatedY = MulM4V4(rotateY, V4V(original, 1));
    EXPECT_NEAR(rotatedY.X, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.Y, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.Z, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.W, 1.0f, 0.001f);

    Mat4 rotateZ = Rotate_RH(AngleDeg(90.0f), V3(0, 0, 1));
    Vec4 rotatedZ = MulM4V4(rotateZ, V4V(original, 1));
    EXPECT_NEAR(rotatedZ.X, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.Y, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.Z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.W, 1.0f, 0.001f);

    Mat4 rotateZLH = Rotate_LH(AngleDeg(90.0f), V3(0, 0, 1));
    Vec4 rotatedZLH = MulM4V4(rotateZLH, V4V(original, 1));
    EXPECT_NEAR(rotatedZLH.X, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.Y, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.Z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.W, 1.0f, 0.001f);
}

TEST(Transformations, Scale)
{
    Mat4 scale = Scale(V3(2.0f, -3.0f, 0.5f));

    Vec3 original = V3(1.0f, 2.0f, 3.0f);
    Vec4 scaled = MulM4V4(scale, V4V(original, 1));

    EXPECT_NEAR(scaled.X, 2.0f, 0.001f);
    EXPECT_NEAR(scaled.Y, -6.0f, 0.001f);
    EXPECT_NEAR(scaled.Z, 1.5f, 0.001f);
    EXPECT_NEAR(scaled.W, 1.0f, 0.001f);
}

TEST(Transformations, LookAt)
{
    const float abs_error = 0.001f;

    {    Mat4 result = LookAt_RH(V3(1.0f, 0.0f, 0.0f), V3(0.0f, 2.0f, 1.0f), V3(2.0f, 1.0f, 1.0f));

        EXPECT_NEAR(result.Elements[0][0], 0.169031f, abs_error);
        EXPECT_NEAR(result.Elements[0][1], 0.897085f, abs_error);
        EXPECT_NEAR(result.Elements[0][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[0][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[1][0], 0.507093f, abs_error);
        EXPECT_NEAR(result.Elements[1][1], 0.276026f, abs_error);
        EXPECT_NEAR(result.Elements[1][2], -0.816497f, abs_error);
        EXPECT_NEAR(result.Elements[1][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[2][0], -0.845154f, abs_error);
        EXPECT_NEAR(result.Elements[2][1], 0.345033f, abs_error);
        EXPECT_NEAR(result.Elements[2][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[2][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[3][0], -0.169031f, abs_error);
        EXPECT_NEAR(result.Elements[3][1], -0.897085f, abs_error);
        EXPECT_NEAR(result.Elements[3][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[3][3], 1.0f, abs_error);
    }
    {    
        Mat4 result = LookAt_LH(V3(1.0f, 0.0f, 0.0f), V3(0.0f, 2.0f, 1.0f), V3(2.0f, 1.0f, 1.0f));

        EXPECT_NEAR(result.Elements[0][0], -0.169031f, abs_error);
        EXPECT_NEAR(result.Elements[0][1], 0.897085f, abs_error);
        EXPECT_NEAR(result.Elements[0][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[0][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[1][0], -0.507093f, abs_error);
        EXPECT_NEAR(result.Elements[1][1], 0.276026f, abs_error);
        EXPECT_NEAR(result.Elements[1][2], 0.816497f, abs_error);
        EXPECT_NEAR(result.Elements[1][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[2][0], 0.845154f, abs_error);
        EXPECT_NEAR(result.Elements[2][1], 0.345033f, abs_error);
        EXPECT_NEAR(result.Elements[2][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[2][3], 0.0f, abs_error);
        EXPECT_NEAR(result.Elements[3][0], 0.169031f, abs_error);
        EXPECT_NEAR(result.Elements[3][1], -0.897085f, abs_error);
        EXPECT_NEAR(result.Elements[3][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.Elements[3][3], 1.0f, abs_error);
    }
}

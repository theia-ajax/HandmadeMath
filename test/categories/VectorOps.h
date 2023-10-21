#include "../HandmadeTest.h"

TEST(VectorOps, LengthSquared)
{
    Vec2 v2 = V2(1.0f, -2.0f);
    Vec3 v3 = V3(1.0f, -2.0f, 3.0f);
    Vec4 v4 = V4(1.0f, -2.0f, 3.0f, 1.0f);

    EXPECT_FLOAT_EQ(LenSqrV2(v2), 5.0f);
    EXPECT_FLOAT_EQ(LenSqrV3(v3), 14.0f);
    EXPECT_FLOAT_EQ(LenSqrV4(v4), 15.0f);

#ifdef __cplusplus
    EXPECT_FLOAT_EQ(LenSqr(v2), 5.0f);
    EXPECT_FLOAT_EQ(LenSqr(v3), 14.0f);
    EXPECT_FLOAT_EQ(LenSqr(v4), 15.0f);
#endif
}

TEST(VectorOps, Length)
{
    Vec2 v2 = V2(1.0f, -9.0f);
    Vec3 v3 = V3(2.0f, -3.0f, 6.0f);
    Vec4 v4 = V4(2.0f, -3.0f, 6.0f, 12.0f);

    EXPECT_FLOAT_EQ(LenV2(v2), 9.0553856f);
    EXPECT_FLOAT_EQ(LenV3(v3), 7.0f);
    EXPECT_FLOAT_EQ(LenV4(v4), 13.892444f);

#ifdef __cplusplus
    EXPECT_FLOAT_EQ(Len(v2), 9.0553856f);
    EXPECT_FLOAT_EQ(Len(v3), 7.0f);
    EXPECT_FLOAT_EQ(Len(v4), 13.892444f);
#endif
}

TEST(VectorOps, Normalize)
{
    Vec2 v2 = V2(1.0f, -2.0f);
    Vec3 v3 = V3(1.0f, -2.0f, 3.0f);
    Vec4 v4 = V4(1.0f, -2.0f, 3.0f, -1.0f);

    {
        Vec2 result = NormV2(v2);
        EXPECT_NEAR(LenV2(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
    }
    {
        Vec3 result = NormV3(v3);
        EXPECT_NEAR(LenV3(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
        EXPECT_GT(result.Z, 0.0f);
    }
    {
        Vec4 result = NormV4(v4);
        EXPECT_NEAR(LenV4(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
        EXPECT_GT(result.Z, 0.0f);
        EXPECT_LT(result.W, 0.0f);
    }

#ifdef __cplusplus
    {
        Vec2 result = Norm(v2);
        EXPECT_NEAR(LenV2(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
    }
    {
        Vec3 result = Norm(v3);
        EXPECT_NEAR(LenV3(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
        EXPECT_GT(result.Z, 0.0f);
    }
    {
        Vec4 result = Norm(v4);
        EXPECT_NEAR(LenV4(result), 1.0f, 0.001f);
        EXPECT_GT(result.X, 0.0f);
        EXPECT_LT(result.Y, 0.0f);
        EXPECT_GT(result.Z, 0.0f);
        EXPECT_LT(result.W, 0.0f);
    }
#endif
}

TEST(VectorOps, NormalizeZero)
{
    Vec2 v2 = V2(0.0f, 0.0f);
    Vec3 v3 = V3(0.0f, 0.0f, 0.0f);
    Vec4 v4 = V4(0.0f, 0.0f, 0.0f, 0.0f);

    {
        Vec2 result = NormV2(v2);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
    }
    {
        Vec3 result = NormV3(v3);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.0f);
    }
    {
        Vec4 result = NormV4(v4);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.0f);
        EXPECT_FLOAT_EQ(result.W, 0.0f);
    }

#ifdef __cplusplus
    {
        Vec2 result = Norm(v2);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
    }
    {
        Vec3 result = Norm(v3);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.0f);
    }
    {
        Vec4 result = Norm(v4);
        EXPECT_FLOAT_EQ(result.X, 0.0f);
        EXPECT_FLOAT_EQ(result.Y, 0.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.0f);
        EXPECT_FLOAT_EQ(result.W, 0.0f);
    }
#endif
}

TEST(VectorOps, Cross)
{
    Vec3 v1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v2 = V3(4.0f, 5.0f, 6.0f);

    Vec3 result = Cross(v1, v2);

    EXPECT_FLOAT_EQ(result.X, -3.0f);
    EXPECT_FLOAT_EQ(result.Y, 6.0f);
    EXPECT_FLOAT_EQ(result.Z, -3.0f);
}

TEST(VectorOps, DotVec2)
{
    Vec2 v1 = V2(1.0f, 2.0f);
    Vec2 v2 = V2(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(DotV2(v1, v2), 11.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(Dot(v1, v2), 11.0f);
#endif
}

TEST(VectorOps, DotVec3)
{
    Vec3 v1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v2 = V3(4.0f, 5.0f, 6.0f);

    EXPECT_FLOAT_EQ(DotV3(v1, v2), 32.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(Dot(v1, v2), 32.0f);
#endif
}

TEST(VectorOps, DotVec4)
{
    Vec4 v1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    EXPECT_FLOAT_EQ(DotV4(v1, v2), 70.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(Dot(v1, v2), 70.0f);
#endif
}

TEST(VectorOps, LerpV2)
{
    Vec2 v1 = V2(1.0f, 0.0f);
    Vec2 v2 = V2(0.0f, 1.0f);

    {
        Vec2 result = LerpV2(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 0.5f);
    }
#ifdef __cplusplus
    {
        Vec2 result = Lerp(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 0.5f);
    }
#endif
}

TEST(VectorOps, LerpV3)
{
    Vec3 v1 = V3(1.0f, 1.0f, 0.0f);
    Vec3 v2 = V3(0.0f, 1.0f, 1.0f);

    {
        Vec3 result = LerpV3(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 1.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.5f);
    }
#ifdef __cplusplus
    {
        Vec3 result = Lerp(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 1.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.5f);
    }
#endif
}

TEST(VectorOps, LerpV4)
{
    Vec4 v1 = V4(1.0f, 1.0f, 0.0f, 1.0f);
    Vec4 v2 = V4(0.0f, 1.0f, 1.0f, 1.0f);

    {
        Vec4 result = LerpV4(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 1.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.5f);
        EXPECT_FLOAT_EQ(result.W, 1.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = Lerp(v1, v2, 0.5);
        EXPECT_FLOAT_EQ(result.X, 0.5f);
        EXPECT_FLOAT_EQ(result.Y, 1.0f);
        EXPECT_FLOAT_EQ(result.Z, 0.5f);
        EXPECT_FLOAT_EQ(result.W, 1.0f);
    }
#endif
}

/*
 * MatrixOps tests
 */

TEST(MatrixOps, TransposeM4)
{
    Mat4 m4 = M4(); // will have 1 - 16

    // Fill the matrix
    int Counter = 1;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4.Elements[Column][Row] = Counter;
            ++Counter;
        }
    }

    // Test the matrix
    Mat4 result = TransposeM4(m4);
    EXPECT_FLOAT_EQ(result.Elements[0][0], 1.0f);
    EXPECT_FLOAT_EQ(result.Elements[0][1], 5.0f);
    EXPECT_FLOAT_EQ(result.Elements[0][2], 9.0f);
    EXPECT_FLOAT_EQ(result.Elements[0][3], 13.0f);
    EXPECT_FLOAT_EQ(result.Elements[1][0], 2.0f);
    EXPECT_FLOAT_EQ(result.Elements[1][1], 6.0f);
    EXPECT_FLOAT_EQ(result.Elements[1][2], 10.0f);
    EXPECT_FLOAT_EQ(result.Elements[1][3], 14.0f);
    EXPECT_FLOAT_EQ(result.Elements[2][0], 3.0f);
    EXPECT_FLOAT_EQ(result.Elements[2][1], 7.0f);
    EXPECT_FLOAT_EQ(result.Elements[2][2], 11.0f);
    EXPECT_FLOAT_EQ(result.Elements[2][3], 15.0f);
    EXPECT_FLOAT_EQ(result.Elements[3][0], 4.0f);
    EXPECT_FLOAT_EQ(result.Elements[3][1], 8.0f);
    EXPECT_FLOAT_EQ(result.Elements[3][2], 12.0f);
    EXPECT_FLOAT_EQ(result.Elements[3][3], 16.0f);
}

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

TEST(VectorOps, MinV2)
{
    Vec2 v1 = V2(1.0f, 0.0f);
    Vec2 v2 = V2(0.0f, 1.0f);
    Vec2 m = MinV2(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 0.0f);
    EXPECT_FLOAT_EQ(m.Y, 0.0f);
#ifdef __cplusplus
    {
        Vec2 m = Min(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 0.0f);
        EXPECT_FLOAT_EQ(m.Y, 0.0f);
    }
#endif
}

TEST(VectorOps, MinV3)
{
    Vec3 v1 = V3(1.0f, 0.0f, 1.0f);
    Vec3 v2 = V3(0.0f, 1.0f, 0.0f);
    Vec3 m = MinV3(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 0.0f);
    EXPECT_FLOAT_EQ(m.Y, 0.0f);
    EXPECT_FLOAT_EQ(m.Z, 0.0f);
#ifdef __cplusplus
    {
        Vec3 m = Min(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 0.0f);
        EXPECT_FLOAT_EQ(m.Y, 0.0f);
        EXPECT_FLOAT_EQ(m.Z, 0.0f);
    }
#endif
}

TEST(VectorOps, MinV4)
{
    Vec4 v1 = V4(1.0f, 0.0f, 1.0f, 0.0f);
    Vec4 v2 = V4(0.0f, 1.0f, 0.0f, 1.0f);
    Vec4 m = MinV4(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 0.0f);
    EXPECT_FLOAT_EQ(m.Y, 0.0f);
    EXPECT_FLOAT_EQ(m.Z, 0.0f);
    EXPECT_FLOAT_EQ(m.W, 0.0f);
#ifdef __cplusplus
    {
        Vec4 m = Min(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 0.0f);
        EXPECT_FLOAT_EQ(m.Y, 0.0f);
        EXPECT_FLOAT_EQ(m.Z, 0.0f);
        EXPECT_FLOAT_EQ(m.W, 0.0f);
    }
#endif
}

TEST(VectorOps, MaxV2)
{
    Vec2 v1 = V2(1.0f, 0.0f);
    Vec2 v2 = V2(0.0f, 1.0f);
    Vec2 m = MaxV2(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 1.0f);
    EXPECT_FLOAT_EQ(m.Y, 1.0f);
#ifdef __cplusplus
    {
        Vec2 m = Max(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 1.0f);
        EXPECT_FLOAT_EQ(m.Y, 1.0f);
    }
#endif
}

TEST(VectorOps, MaxV3)
{
    Vec3 v1 = V3(1.0f, 0.0f, 1.0f);
    Vec3 v2 = V3(0.0f, 1.0f, 0.0f);
    Vec3 m = MaxV3(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 1.0f);
    EXPECT_FLOAT_EQ(m.Y, 1.0f);
    EXPECT_FLOAT_EQ(m.Z, 1.0f);
#ifdef __cplusplus
    {
        Vec3 m = Max(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 1.0f);
        EXPECT_FLOAT_EQ(m.Y, 1.0f);
        EXPECT_FLOAT_EQ(m.Z, 1.0f);
    }
#endif
}

TEST(VectorOps, MaxV4)
{
    Vec4 v1 = V4(1.0f, 0.0f, 1.0f, 0.0f);
    Vec4 v2 = V4(0.0f, 1.0f, 0.0f, 1.0f);
    Vec4 m = MaxV4(v1, v2);
    EXPECT_FLOAT_EQ(m.X, 1.0f);
    EXPECT_FLOAT_EQ(m.Y, 1.0f);
    EXPECT_FLOAT_EQ(m.Z, 1.0f);
    EXPECT_FLOAT_EQ(m.W, 1.0f);
#ifdef __cplusplus
    {
        Vec4 m = Max(v1, v2);
        EXPECT_FLOAT_EQ(m.X, 1.0f);
        EXPECT_FLOAT_EQ(m.Y, 1.0f);
        EXPECT_FLOAT_EQ(m.Z, 1.0f);
        EXPECT_FLOAT_EQ(m.W, 1.0f);
    }
#endif
}

TEST(VectorOps, AbsV2)
{
    Vec2 v1 = AbsV2(V2(1.0f, 2.0f));
    Vec2 v2 = AbsV2(V2(-1.0f, -2.0f));
    EXPECT_FLOAT_EQ(v1.X, 1.0f);
    EXPECT_FLOAT_EQ(v1.Y, 2.0f);
    EXPECT_FLOAT_EQ(v2.X, 1.0f);
    EXPECT_FLOAT_EQ(v2.Y, 2.0f);
#ifdef __cplusplus
    {
        Vec2 v1 = Abs(V2(1.0f, 2.0f));
        Vec2 v2 = Abs(V2(-1.0f, -2.0f));
        EXPECT_FLOAT_EQ(v1.X, 1.0f);
        EXPECT_FLOAT_EQ(v1.Y, 2.0f);
        EXPECT_FLOAT_EQ(v2.X, 1.0f);
        EXPECT_FLOAT_EQ(v2.Y, 2.0f);
    }
#endif
}

TEST(VectorOps, AbsV3)
{
    Vec3 v1 = AbsV3(V3(1.0f, 2.0f, 3.0f));
    Vec3 v2 = AbsV3(V3(-1.0f, -2.0f, -3.0f));
    EXPECT_FLOAT_EQ(v1.X, 1.0f);
    EXPECT_FLOAT_EQ(v1.Y, 2.0f);
    EXPECT_FLOAT_EQ(v1.Z, 3.0f);
    EXPECT_FLOAT_EQ(v2.X, 1.0f);
    EXPECT_FLOAT_EQ(v2.Y, 2.0f);
    EXPECT_FLOAT_EQ(v2.Z, 3.0f);
#ifdef __cplusplus
    {
        Vec3 v1 = Abs(V3(1.0f, 2.0f, 3.0f));
        Vec3 v2 = Abs(V3(-1.0f, -2.0f, -3.0f));
        EXPECT_FLOAT_EQ(v1.X, 1.0f);
        EXPECT_FLOAT_EQ(v1.Y, 2.0f);
        EXPECT_FLOAT_EQ(v1.Z, 3.0f);
        EXPECT_FLOAT_EQ(v2.X, 1.0f);
        EXPECT_FLOAT_EQ(v2.Y, 2.0f);
        EXPECT_FLOAT_EQ(v2.Z, 3.0f);
    }
#endif
}

TEST(VectorOps, AbsV4)
{
    Vec4 v1 = AbsV4(V4(1.0f, 2.0f, 3.0f, 4.0f));
    Vec4 v2 = AbsV4(V4(-1.0f, -2.0f, -3.0f, -4.0f));
    EXPECT_FLOAT_EQ(v1.X, 1.0f);
    EXPECT_FLOAT_EQ(v1.Y, 2.0f);
    EXPECT_FLOAT_EQ(v1.Z, 3.0f);
    EXPECT_FLOAT_EQ(v1.W, 4.0f);
    EXPECT_FLOAT_EQ(v2.X, 1.0f);
    EXPECT_FLOAT_EQ(v2.Y, 2.0f);
    EXPECT_FLOAT_EQ(v2.Z, 3.0f);
    EXPECT_FLOAT_EQ(v2.W, 4.0f);
#ifdef __cplusplus
    {
        Vec4 v1 = Abs(V4(1.0f, 2.0f, 3.0f, 4.0f));
        Vec4 v2 = Abs(V4(-1.0f, -2.0f, -3.0f, -4.0f));
        EXPECT_FLOAT_EQ(v1.X, 1.0f);
        EXPECT_FLOAT_EQ(v1.Y, 2.0f);
        EXPECT_FLOAT_EQ(v1.Z, 3.0f);
        EXPECT_FLOAT_EQ(v1.W, 4.0f);
        EXPECT_FLOAT_EQ(v2.X, 1.0f);
        EXPECT_FLOAT_EQ(v2.Y, 2.0f);
        EXPECT_FLOAT_EQ(v2.Z, 3.0f);
        EXPECT_FLOAT_EQ(v2.W, 4.0f);
    }
#endif
}

TEST(VectorOps, IsFiniteV2)
{
    EXPECT_TRUE(IsFiniteV2(V2(0, 0)));
    EXPECT_FALSE(IsFiniteV2(V2(0, INFINITY)));
    EXPECT_FALSE(IsFiniteV2(V2(INFINITY, 0)));
    EXPECT_FALSE(IsFiniteV2(V2(INFINITY, INFINITY)));
#ifdef __cplusplus
    {
        EXPECT_TRUE(IsFinite(V2(0, 0)));
        EXPECT_FALSE(IsFinite(V2(0, INFINITY)));
        EXPECT_FALSE(IsFinite(V2(INFINITY, 0)));
        EXPECT_FALSE(IsFinite(V2(INFINITY, INFINITY)));
    }
#endif
}

TEST(VectorOps, IsFiniteV3)
{
    EXPECT_TRUE(IsFiniteV3(V3(0, 0, 0)));
    EXPECT_FALSE(IsFiniteV3(V3(INFINITY, 0, 0)));
    EXPECT_FALSE(IsFiniteV3(V3(0, INFINITY, 0)));
    EXPECT_FALSE(IsFiniteV3(V3(0, 0, INFINITY)));
    EXPECT_FALSE(IsFiniteV3(V3(INFINITY, INFINITY, INFINITY)));
#ifdef __cplusplus
    {
        EXPECT_TRUE(IsFinite(V3(0, 0, 0)));
        EXPECT_FALSE(IsFinite(V3(INFINITY, 0, 0)));
        EXPECT_FALSE(IsFinite(V3(0, INFINITY, 0)));
        EXPECT_FALSE(IsFinite(V3(0, 0, INFINITY)));
        EXPECT_FALSE(IsFinite(V3(INFINITY, INFINITY, INFINITY)));
    }
#endif
}

TEST(VectorOps, IsFiniteV4)
{
    EXPECT_TRUE(IsFiniteV4(V4(0, 0, 0, 0)));
    EXPECT_FALSE(IsFiniteV4(V4(INFINITY, 0, 0, 0)));
    EXPECT_FALSE(IsFiniteV4(V4(0, INFINITY, 0, 0)));
    EXPECT_FALSE(IsFiniteV4(V4(0, 0, INFINITY, 0)));
    EXPECT_FALSE(IsFiniteV4(V4(0, 0, 0, INFINITY)));
    EXPECT_FALSE(IsFiniteV4(V4(INFINITY, INFINITY, INFINITY, INFINITY)));
#ifdef __cplusplus
    {
        EXPECT_TRUE(IsFinite(V4(0, 0, 0, 0)));
        EXPECT_FALSE(IsFinite(V4(INFINITY, 0, 0, 0)));
        EXPECT_FALSE(IsFinite(V4(0, INFINITY, 0, 0)));
        EXPECT_FALSE(IsFinite(V4(0, 0, INFINITY, 0)));
        EXPECT_FALSE(IsFinite(V4(0, 0, 0, INFINITY)));
        EXPECT_FALSE(IsFinite(V4(INFINITY, INFINITY, INFINITY, INFINITY)));
    }
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

TEST(VectorOps, ClampV2)
{
    Vec2 v1 = V2(-1.0f, -1.25f);
    Vec2 v2 = V2(1.0f, 1.25f);

    {
        Vec2 result1 = ClampV2(V2(-2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);

        Vec2 result2 = ClampV2(V2(2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);

        Vec2 result3 = ClampV2(V2(0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result1 = Clamp(V2(-2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);

        Vec2 result2 = Clamp(V2(2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);

        Vec2 result3 = Clamp(V2(0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
    }
#endif
}

TEST(VectorOps, ClampV3)
{
    Vec3 v1 = V3(-1.0f, -1.25f, -1.5f);
    Vec3 v2 = V3(1.0f, 1.25f, 1.5f);

    {
        Vec3 result1 = ClampV3(V3(-2.0f, -2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);
        EXPECT_FLOAT_EQ(result1.Z, v1.Z);

        Vec3 result2 = ClampV3(V3(2.0f, 2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);
        EXPECT_FLOAT_EQ(result2.Z, v2.Z);

        Vec3 result3 = ClampV3(V3(0.0f, 0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
        EXPECT_FLOAT_EQ(result3.Z, 0.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result1 = Clamp(V3(-2.0f, -2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);
        EXPECT_FLOAT_EQ(result1.Z, v1.Z);

        Vec3 result2 = Clamp(V3(2.0f, 2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);
        EXPECT_FLOAT_EQ(result2.Z, v2.Z);

        Vec3 result3 = Clamp(V3(0.0f, 0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
        EXPECT_FLOAT_EQ(result3.Z, 0.0f);
    }
#endif
}

TEST(VectorOps, ClampV4)
{
    Vec4 v1 = V4(-1.0f, -1.25f, -1.5f, -1.75f);
    Vec4 v2 = V4(1.0f, 1.25f, 1.5f, 1.75f);

    {
        Vec4 result1 = ClampV4(V4(-2.0f, -2.0f, -2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);
        EXPECT_FLOAT_EQ(result1.Z, v1.Z);
        EXPECT_FLOAT_EQ(result1.W, v1.W);

        Vec4 result2 = ClampV4(V4(2.0f, 2.0f, 2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);
        EXPECT_FLOAT_EQ(result2.Z, v2.Z);
        EXPECT_FLOAT_EQ(result2.W, v2.W);

        Vec4 result3 = ClampV4(V4(0.0f, 0.0f, 0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
        EXPECT_FLOAT_EQ(result3.Z, 0.0f);
        EXPECT_FLOAT_EQ(result3.W, 0.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result1 = Clamp(V4(-2.0f, -2.0f, -2.0f, -2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result1.X, v1.X);
        EXPECT_FLOAT_EQ(result1.Y, v1.Y);
        EXPECT_FLOAT_EQ(result1.Z, v1.Z);
        EXPECT_FLOAT_EQ(result1.W, v1.W);

        Vec4 result2 = Clamp(V4(2.0f, 2.0f, 2.0f, 2.0f), v1, v2);
        EXPECT_FLOAT_EQ(result2.X, v2.X);
        EXPECT_FLOAT_EQ(result2.Y, v2.Y);
        EXPECT_FLOAT_EQ(result2.Z, v2.Z);
        EXPECT_FLOAT_EQ(result2.W, v2.W);

        Vec4 result3 = Clamp(V4(0.0f, 0.0f, 0.0f, 0.0f), v1, v2);
        EXPECT_FLOAT_EQ(result3.X, 0.0f);
        EXPECT_FLOAT_EQ(result3.Y, 0.0f);
        EXPECT_FLOAT_EQ(result3.Z, 0.0f);
        EXPECT_FLOAT_EQ(result3.W, 0.0f);
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
            m4.Data[Column][Row] = Counter;
            ++Counter;
        }
    }

    // Test the matrix
    Mat4 result = TransposeM4(m4);
    EXPECT_FLOAT_EQ(result.Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(result.Data[0][1], 5.0f);
    EXPECT_FLOAT_EQ(result.Data[0][2], 9.0f);
    EXPECT_FLOAT_EQ(result.Data[0][3], 13.0f);
    EXPECT_FLOAT_EQ(result.Data[1][0], 2.0f);
    EXPECT_FLOAT_EQ(result.Data[1][1], 6.0f);
    EXPECT_FLOAT_EQ(result.Data[1][2], 10.0f);
    EXPECT_FLOAT_EQ(result.Data[1][3], 14.0f);
    EXPECT_FLOAT_EQ(result.Data[2][0], 3.0f);
    EXPECT_FLOAT_EQ(result.Data[2][1], 7.0f);
    EXPECT_FLOAT_EQ(result.Data[2][2], 11.0f);
    EXPECT_FLOAT_EQ(result.Data[2][3], 15.0f);
    EXPECT_FLOAT_EQ(result.Data[3][0], 4.0f);
    EXPECT_FLOAT_EQ(result.Data[3][1], 8.0f);
    EXPECT_FLOAT_EQ(result.Data[3][2], 12.0f);
    EXPECT_FLOAT_EQ(result.Data[3][3], 16.0f);
}

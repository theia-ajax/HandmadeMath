#include "../HandmadeTest.h"

TEST(Subtraction, Vec2)
{
    Vec2 v2_1 = V2(1.0f, 2.0f);
    Vec2 v2_2 = V2(3.0f, 4.0f);

    {
        Vec2 result = SubV2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.X, -2.0f);
        EXPECT_FLOAT_EQ(result.Y, -2.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = Sub(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.X, -2.0f);
        EXPECT_FLOAT_EQ(result.Y, -2.0f);
    }
    {
        Vec2 result = v2_1 - v2_2;
        EXPECT_FLOAT_EQ(result.X, -2.0f);
        EXPECT_FLOAT_EQ(result.Y, -2.0f);
    }

    v2_1 -= v2_2;
    EXPECT_FLOAT_EQ(v2_1.X, -2.0f);
    EXPECT_FLOAT_EQ(v2_1.Y, -2.0f);
#endif
}

TEST(Subtraction, Vec3)
{
    Vec3 v3_1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v3_2 = V3(4.0f, 5.0f, 6.0f);

    {
        Vec3 result = SubV3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.X, -3.0f);
        EXPECT_FLOAT_EQ(result.Y, -3.0f);
        EXPECT_FLOAT_EQ(result.Z, -3.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = Sub(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.X, -3.0f);
        EXPECT_FLOAT_EQ(result.Y, -3.0f);
        EXPECT_FLOAT_EQ(result.Z, -3.0f);
    }
    {
        Vec3 result = v3_1 - v3_2;
        EXPECT_FLOAT_EQ(result.X, -3.0f);
        EXPECT_FLOAT_EQ(result.Y, -3.0f);
        EXPECT_FLOAT_EQ(result.Z, -3.0f);
    }

    v3_1 -= v3_2;
    EXPECT_FLOAT_EQ(v3_1.X, -3.0f);
    EXPECT_FLOAT_EQ(v3_1.Y, -3.0f);
    EXPECT_FLOAT_EQ(v3_1.Z, -3.0f);
#endif
}

TEST(Subtraction, Vec4)
{
    Vec4 v4_1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4_2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Vec4 result = SubV4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = Sub(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }
    {
        Vec4 result = v4_1 - v4_2;
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }

    v4_1 -= v4_2;
    EXPECT_FLOAT_EQ(v4_1.X, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.Y, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.Z, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.W, -4.0f);
#endif
}

TEST(Subtraction, Mat2)
{
    Mat2 a = M2();
    Mat2 b = M2();
    
    int Counter = 1;
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            a.Elements[Column][Row] = Counter++;
        }
    }
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            b.Elements[Column][Row] = Counter++;
        }
    }

    {
        Mat2 result = SubM2(b,a);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][1], 4.0);
    }
#ifdef __cplusplus
    {
        Mat2 result = Sub(b,a);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][1], 4.0);
    }

    {
        Mat2 result = b - a;
        EXPECT_FLOAT_EQ(result.Elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.Elements[1][1], 4.0);
    }

    b -= a;
    EXPECT_FLOAT_EQ(b.Elements[0][0], 4.0);
    EXPECT_FLOAT_EQ(b.Elements[0][1], 4.0);
    EXPECT_FLOAT_EQ(b.Elements[1][0], 4.0);
    EXPECT_FLOAT_EQ(b.Elements[1][1], 4.0);
#endif
}


TEST(Subtraction, Mat3)
{
    Mat3 a = M3();
    Mat3 b = M3();
    
    int Counter = 1;
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            a.Elements[Column][Row] = Counter++;
        }
    }
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            b.Elements[Column][Row] = Counter++;
        }
    }

    {
        Mat3 result = SubM3(b,a);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[0][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[0][2], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][2], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][2], 9.0);
    }
#ifdef __cplusplus
    {
        Mat3 result = Sub(b,a);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[0][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[0][2], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[1][2], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][0], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][1], 9.0);
        EXPECT_FLOAT_EQ(result.Elements[2][2], 9.0);
    }

    b -= a;
    EXPECT_FLOAT_EQ(b.Elements[0][0], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[0][1], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[0][2], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[1][0], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[1][1], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[1][2], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[2][0], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[2][1], 9.0);
    EXPECT_FLOAT_EQ(b.Elements[2][2], 9.0);
#endif
}

TEST(Subtraction, Mat4)
{
    Mat4 m4_1 = M4(); // will have 1 - 16
    Mat4 m4_2 = M4(); // will have 17 - 32

    // Fill the matrices
    int Counter = 1;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4_1.Elements[Column][Row] = Counter;
            ++Counter;
        }
    }
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4_2.Elements[Column][Row] = Counter;
            ++Counter;
        }
    }

    // Test the results
    {
        Mat4 result = SubM4(m4_1, m4_2);
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], -16.0f);
            }
        }
    }
#ifdef __cplusplus
    {
        Mat4 result = Sub(m4_1, m4_2);
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], -16.0f);
            }
        }
    }
    {
        Mat4 result = m4_1 - m4_2;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], -16.0f);
            }
        }
    }

    m4_1 -= m4_2;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            EXPECT_FLOAT_EQ(m4_1.Elements[Column][Row], -16.0f);
        }
    }
#endif
}

TEST(Subtraction, Quaternion)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Quat result = SubQ(q1, q2);
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }
#ifdef __cplusplus
    {
        Quat result = Sub(q1, q2);
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }
    {
        Quat result = q1 - q2;
        EXPECT_FLOAT_EQ(result.X, -4.0f);
        EXPECT_FLOAT_EQ(result.Y, -4.0f);
        EXPECT_FLOAT_EQ(result.Z, -4.0f);
        EXPECT_FLOAT_EQ(result.W, -4.0f);
    }

    q1 -= q2;
    EXPECT_FLOAT_EQ(q1.X, -4.0f);
    EXPECT_FLOAT_EQ(q1.Y, -4.0f);
    EXPECT_FLOAT_EQ(q1.Z, -4.0f);
    EXPECT_FLOAT_EQ(q1.W, -4.0f);
#endif
}

#ifdef __cplusplus
TEST(UnaryMinus, Vec2)
{
    Vec2 VectorOne = {1.0f, 2.0f};
    Vec2 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.X, -1.0f);
    EXPECT_FLOAT_EQ(Result.Y, -2.0f);
}

TEST(UnaryMinus, Vec3)
{
    Vec3 VectorOne = {1.0f, 2.0f, 3.0f};
    Vec3 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.X, -1.0f);
    EXPECT_FLOAT_EQ(Result.Y, -2.0f);
    EXPECT_FLOAT_EQ(Result.Z, -3.0f);
}

TEST(UnaryMinus, Vec4)
{
    Vec4 VectorOne = {1.0f, 2.0f, 3.0f, 4.0f};
    Vec4 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.X, -1.0f);
    EXPECT_FLOAT_EQ(Result.Y, -2.0f);
    EXPECT_FLOAT_EQ(Result.Z, -3.0f);
    EXPECT_FLOAT_EQ(Result.W, -4.0f);
}
#endif

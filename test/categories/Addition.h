#include "../HandmadeTest.h"

TEST(Addition, Vec2)
{
    Vec2 v2_1 = V2(1.0f, 2.0f);
    Vec2 v2_2 = V2(3.0f, 4.0f);

    {
        Vec2 result = AddV2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.X, 4.0f);
        EXPECT_FLOAT_EQ(result.Y, 6.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = Add(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.X, 4.0f);
        EXPECT_FLOAT_EQ(result.Y, 6.0f);
    }
    {
        Vec2 result = v2_1 + v2_2;
        EXPECT_FLOAT_EQ(result.X, 4.0f);
        EXPECT_FLOAT_EQ(result.Y, 6.0f);
    }

    v2_1 += v2_2;
    EXPECT_FLOAT_EQ(v2_1.X, 4.0f);
    EXPECT_FLOAT_EQ(v2_1.Y, 6.0f);
#endif
}

TEST(Addition, Vec3)
{
    Vec3 v3_1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v3_2 = V3(4.0f, 5.0f, 6.0f);

    {
        Vec3 result = AddV3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.X, 5.0f);
        EXPECT_FLOAT_EQ(result.Y, 7.0f);
        EXPECT_FLOAT_EQ(result.Z, 9.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = Add(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.X, 5.0f);
        EXPECT_FLOAT_EQ(result.Y, 7.0f);
        EXPECT_FLOAT_EQ(result.Z, 9.0f);
    }
    {
        Vec3 result = v3_1 + v3_2;
        EXPECT_FLOAT_EQ(result.X, 5.0f);
        EXPECT_FLOAT_EQ(result.Y, 7.0f);
        EXPECT_FLOAT_EQ(result.Z, 9.0f);
    }

    v3_1 += v3_2;
    EXPECT_FLOAT_EQ(v3_1.X, 5.0f);
    EXPECT_FLOAT_EQ(v3_1.Y, 7.0f);
    EXPECT_FLOAT_EQ(v3_1.Z, 9.0f);
#endif
}

TEST(Addition, Vec4)
{
    Vec4 v4_1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4_2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Vec4 result = AddV4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = Add(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }
    {
        Vec4 result = v4_1 + v4_2;
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }

    v4_1 += v4_2;
    EXPECT_FLOAT_EQ(v4_1.X, 6.0f);
    EXPECT_FLOAT_EQ(v4_1.Y, 8.0f);
    EXPECT_FLOAT_EQ(v4_1.Z, 10.0f);
    EXPECT_FLOAT_EQ(v4_1.W, 12.0f);
#endif
}

TEST(Addition, Mat2)
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
        Mat2 result = AddM2(a, b);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 12.0f); 
    }

#ifdef __cplusplus
    {
        Mat2 result = Add(a, b);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 12.0f); 
    }
    {
        Mat2 result = a + b;
        EXPECT_FLOAT_EQ(result.Elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 12.0f); 
    }
    a += b;
    EXPECT_FLOAT_EQ(a.Elements[0][0], 6.0f); 
    EXPECT_FLOAT_EQ(a.Elements[0][1], 8.0f); 
    EXPECT_FLOAT_EQ(a.Elements[1][0], 10.0f); 
    EXPECT_FLOAT_EQ(a.Elements[1][1], 12.0f); 
#endif
}

TEST(Addition, Mat3) 
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
        Mat3 result = AddM3(a, b);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.Elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.Elements[2][2], 27.0f);   
    }

#ifdef __cplusplus
    {
        Mat3 result = Add(a, b);
        EXPECT_FLOAT_EQ(result.Elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.Elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.Elements[2][2], 27.0f);   
    }
    {
        Mat3 result = a + b;
        EXPECT_FLOAT_EQ(result.Elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.Elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.Elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.Elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.Elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.Elements[2][2], 27.0f);   
    }
    a += b;
    EXPECT_FLOAT_EQ(a.Elements[0][0], 11.0f); 
    EXPECT_FLOAT_EQ(a.Elements[0][1], 13.0f); 
    EXPECT_FLOAT_EQ(a.Elements[0][2], 15.0f); 
    EXPECT_FLOAT_EQ(a.Elements[1][0], 17.0f); 
    EXPECT_FLOAT_EQ(a.Elements[1][1], 19.0f);
    EXPECT_FLOAT_EQ(a.Elements[1][2], 21.0f); 
    EXPECT_FLOAT_EQ(a.Elements[2][0], 23.0f); 
    EXPECT_FLOAT_EQ(a.Elements[2][1], 25.0f);
    EXPECT_FLOAT_EQ(a.Elements[2][2], 27.0f);   
#endif  
}

TEST(Addition, Mat4)
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
        Mat4 result = AddM4(m4_1, m4_2);
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }
#ifdef __cplusplus
    {
        Mat4 result = Add(m4_1, m4_2);
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }
    {
        Mat4 result = m4_1 + m4_2;
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.Elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }

    m4_1 += m4_2;
    float Expected = 18.0f;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            EXPECT_FLOAT_EQ(m4_1.Elements[Column][Row], Expected);
            Expected += 2.0f;
        }
    }
#endif
}

TEST(Addition, Quaternion)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Quat result = AddQ(q1, q2);
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }
#ifdef __cplusplus
    {
        Quat result = Add(q1, q2);
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }
    {
        Quat result = q1 + q2;
        EXPECT_FLOAT_EQ(result.X, 6.0f);
        EXPECT_FLOAT_EQ(result.Y, 8.0f);
        EXPECT_FLOAT_EQ(result.Z, 10.0f);
        EXPECT_FLOAT_EQ(result.W, 12.0f);
    }

    q1 += q2;
    EXPECT_FLOAT_EQ(q1.X, 6.0f);
    EXPECT_FLOAT_EQ(q1.Y, 8.0f);
    EXPECT_FLOAT_EQ(q1.Z, 10.0f);
    EXPECT_FLOAT_EQ(q1.W, 12.0f);
#endif
}

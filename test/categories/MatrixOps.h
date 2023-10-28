#include "../HandmadeTest.h"

TEST(InvMatrix, Transpose)
{
    {
        Mat2 Matrix = {
            1.0f, 3.0f,
            2.0f, 4.0f,
        };
        Mat2 Expect = {
            1.0f, 2.0f,
            3.0f, 4.0f,
        };

        {
            Mat2 result = TransposeM2(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
        }
#ifdef __cplusplus
        {
            Mat2 result = Transpose(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
        }
#endif
    }

    {
        Mat3 Matrix = {
            1.0f, 4.0f, 7.0f,
            2.0f, 5.0f, 8.0f,
            3.0f, 6.0f, 9.0f,
        };
        Mat3 Expect = {
            1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            7.0f, 8.0f, 9.0f
        };

        {
            Mat3 result = TransposeM3(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[0][2], Expect.Data[0][2]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
            EXPECT_FLOAT_EQ(result.Data[1][2], Expect.Data[1][2]);
            EXPECT_FLOAT_EQ(result.Data[2][0], Expect.Data[2][0]);
            EXPECT_FLOAT_EQ(result.Data[2][1], Expect.Data[2][1]);
            EXPECT_FLOAT_EQ(result.Data[2][2], Expect.Data[2][2]);
        }
#ifdef __cplusplus
        {
            Mat3 result = Transpose(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[0][2], Expect.Data[0][2]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
            EXPECT_FLOAT_EQ(result.Data[1][2], Expect.Data[1][2]);
            EXPECT_FLOAT_EQ(result.Data[2][0], Expect.Data[2][0]);
            EXPECT_FLOAT_EQ(result.Data[2][1], Expect.Data[2][1]);
            EXPECT_FLOAT_EQ(result.Data[2][2], Expect.Data[2][2]);
        }
#endif
    }
    {
        Mat4 Matrix = {
            1.0f, 5.0f,  9.0f, 13.0f,
            2.0f, 6.0f, 10.0f, 14.0f, 
            3.0f, 7.0f, 11.0f, 15.0f,
            4.0f, 8.0f, 12.0f, 16.0f
        };
        Mat4 Expect = {
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f,
        };
        {
            Mat4 result = TransposeM4(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[0][2], Expect.Data[0][2]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
            EXPECT_FLOAT_EQ(result.Data[1][2], Expect.Data[1][2]);
            EXPECT_FLOAT_EQ(result.Data[2][0], Expect.Data[2][0]);
            EXPECT_FLOAT_EQ(result.Data[2][1], Expect.Data[2][1]);
            EXPECT_FLOAT_EQ(result.Data[2][2], Expect.Data[2][2]);
        }
#ifdef __cplusplus
        {
            Mat4 result = Transpose(Matrix);
            EXPECT_FLOAT_EQ(result.Data[0][0], Expect.Data[0][0]);
            EXPECT_FLOAT_EQ(result.Data[0][1], Expect.Data[0][1]);
            EXPECT_FLOAT_EQ(result.Data[0][2], Expect.Data[0][2]);
            EXPECT_FLOAT_EQ(result.Data[1][0], Expect.Data[1][0]);
            EXPECT_FLOAT_EQ(result.Data[1][1], Expect.Data[1][1]);
            EXPECT_FLOAT_EQ(result.Data[1][2], Expect.Data[1][2]);
            EXPECT_FLOAT_EQ(result.Data[2][0], Expect.Data[2][0]);
            EXPECT_FLOAT_EQ(result.Data[2][1], Expect.Data[2][1]);
            EXPECT_FLOAT_EQ(result.Data[2][2], Expect.Data[2][2]);
        }
#endif
    }

}

TEST(InvMatrix, InvGeneral)
{
    {
        Mat4 Matrix = {
            12.0f, 2.0f, 1.0f, 1.0f,
            0.0f, 0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 5.0f, 1.0f,
            11.0f, 1.0f, 0.0f, 10.0f
        };

        Mat4 Expect = M4D(1.0);
        Mat4 Inverse = InvGeneralM4(Matrix);
        Mat4 Result = MulM4(Matrix, Inverse);
        
        float Det = DeterminantM4(Matrix);
        EXPECT_FLOAT_EQ(Det, -80.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[0][2], Expect.Data[0][2]);
        EXPECT_FLOAT_EQ(Result.Data[0][3], Expect.Data[0][3]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][2], Expect.Data[1][2]);
        EXPECT_FLOAT_EQ(Result.Data[1][3], Expect.Data[1][3]);
        EXPECT_FLOAT_EQ(Result.Data[2][0], Expect.Data[2][0]);
        EXPECT_FLOAT_EQ(Result.Data[2][1], Expect.Data[2][1]);
        EXPECT_FLOAT_EQ(Result.Data[2][2], Expect.Data[2][2]);
        EXPECT_FLOAT_EQ(Result.Data[2][3], Expect.Data[2][3]);
        EXPECT_FLOAT_EQ(Result.Data[3][0], Expect.Data[3][0]);
        EXPECT_FLOAT_EQ(Result.Data[3][1], Expect.Data[3][1]);
        EXPECT_FLOAT_EQ(Result.Data[3][2], Expect.Data[3][2]);
        EXPECT_FLOAT_EQ(Result.Data[3][3], Expect.Data[3][3]);

#ifdef __cplusplus
        Inverse = InvGeneral(Matrix);
        Result = Mul(Matrix, Inverse);
        
        Det = Determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, -80.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[0][2], Expect.Data[0][2]);
        EXPECT_FLOAT_EQ(Result.Data[0][3], Expect.Data[0][3]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][2], Expect.Data[1][2]);
        EXPECT_FLOAT_EQ(Result.Data[1][3], Expect.Data[1][3]);
        EXPECT_FLOAT_EQ(Result.Data[2][0], Expect.Data[2][0]);
        EXPECT_FLOAT_EQ(Result.Data[2][1], Expect.Data[2][1]);
        EXPECT_FLOAT_EQ(Result.Data[2][2], Expect.Data[2][2]);
        EXPECT_FLOAT_EQ(Result.Data[2][3], Expect.Data[2][3]);
        EXPECT_FLOAT_EQ(Result.Data[3][0], Expect.Data[3][0]);
        EXPECT_FLOAT_EQ(Result.Data[3][1], Expect.Data[3][1]);
        EXPECT_FLOAT_EQ(Result.Data[3][2], Expect.Data[3][2]);
        EXPECT_FLOAT_EQ(Result.Data[3][3], Expect.Data[3][3]);
#endif
    }

    {
        Mat3 Matrix = {
            12.0f, 2.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 5.0f
        };

        Mat3 Expect = M3D(1.0);
        Mat3 Inverse = InvGeneralM3(Matrix);
        Mat3 Result = MulM3(Matrix, Inverse);
        
        float Det = DeterminantM3(Matrix);
        EXPECT_FLOAT_EQ(Det, -12.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[0][2], Expect.Data[0][2]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][2], Expect.Data[1][2]);
        EXPECT_FLOAT_EQ(Result.Data[2][0], Expect.Data[2][0]);
        EXPECT_FLOAT_EQ(Result.Data[2][1], Expect.Data[2][1]);
        EXPECT_FLOAT_EQ(Result.Data[2][2], Expect.Data[2][2]);

#ifdef __cplusplus
        Inverse = InvGeneral(Matrix);
        Result = Mul(Matrix, Inverse);
        Det = Determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, -12.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[0][2], Expect.Data[0][2]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][2], Expect.Data[1][2]);
        EXPECT_FLOAT_EQ(Result.Data[2][0], Expect.Data[2][0]);
        EXPECT_FLOAT_EQ(Result.Data[2][1], Expect.Data[2][1]);
        EXPECT_FLOAT_EQ(Result.Data[2][2], Expect.Data[2][2]);
#endif
    }

    {
        Mat2 Matrix = {
            12.0f, 2.0f, 
             1.0f, 5.0f
        };

        Mat2 Expect = M2D(1.0);
        Mat2 Inverse = InvGeneralM2(Matrix);
        Mat2 Result = MulM2(Matrix, Inverse);
        
        float Det = DeterminantM2(Matrix);
        EXPECT_FLOAT_EQ(Det, 58.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);

#ifdef __cplusplus
        Inverse = InvGeneral(Matrix);
        Result = Mul(Matrix, Inverse);
        Det = Determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, 58.0f);

        EXPECT_FLOAT_EQ(Result.Data[0][0], Expect.Data[0][0]);
        EXPECT_FLOAT_EQ(Result.Data[0][1], Expect.Data[0][1]);
        EXPECT_FLOAT_EQ(Result.Data[1][0], Expect.Data[1][0]);
        EXPECT_FLOAT_EQ(Result.Data[1][1], Expect.Data[1][1]);
#endif
    }    
}

TEST(InvMatrix, InvOrthographic)
{
    {
        Mat4 Matrix = Orthographic_RH_NO(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = InvOrthographic(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Orthographic_RH_ZO(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = InvOrthographic(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Orthographic_LH_NO(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = InvOrthographic(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Orthographic_LH_ZO(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = InvOrthographic(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
}

TEST(InvMatrix, InvPerspective)
{
    {
        Mat4 Matrix = Perspective_RH_NO(AngleDeg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = InvPerspective_RH(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Perspective_RH_ZO(AngleDeg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = InvPerspective_RH(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Perspective_LH_NO(AngleDeg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = InvPerspective_LH(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = Perspective_LH_ZO(AngleDeg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = InvPerspective_LH(Matrix);
        EXPECT_M4_EQ(MulM4(Matrix, Inverse), M4D(1.0f));
    }
}

TEST(InvMatrix, InvLookAt)
{
    {
        Vec3 Eye = {10.0f, 10.0f, 10.0f};
        Vec3 Center = {100.0f, 200.0f, 30.0f};
        Vec3 Up = {0.0f, 0.0f, 1.0f};
        Mat4 Matrix = LookAt_RH(Eye, Center, Up);
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = InvLookAt(Matrix);
        Mat4 Result = MulM4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
    {
        Vec3 Eye = {10.0f, 10.0f, 10.0f};
        Vec3 Center = {100.0f, 200.0f, 30.0f};
        Vec3 Up = {0.0f, 0.0f, 1.0f};
        Mat4 Matrix = LookAt_LH(Eye, Center, Up);
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = InvLookAt(Matrix);
        Mat4 Result = MulM4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
}

TEST(InvMatrix, InvRotate)
{
    {
        Vec3 Axis = {1.0f, -1.0f, 0.5f};
        Mat4 Matrix = Rotate_RH(AngleDeg(30), NormV3(Axis));
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = InvRotate(Matrix);
        Mat4 Result = MulM4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
    {
        Vec3 Axis = {1.0f, -1.0f, 0.5f};
        Mat4 Matrix = Rotate_LH(AngleDeg(30), NormV3(Axis));
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = InvRotate(Matrix);
        Mat4 Result = MulM4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
}

TEST(InvMatrix, InvScale)
{
    Vec3 Scale  = {1.0f, -1.0f, 0.5f};
    Mat4 Matrix = ScaleV3(Scale);
    Mat4 Expect = M4D(1.0f);
    Mat4 Inverse = InvScale(Matrix);
    Mat4 Result = MulM4(Matrix, Inverse);
    EXPECT_M4_EQ(Result, Expect);
}

TEST(InvMatrix, InvTranslate)
{
    Vec3 Move  = {1.0f, -1.0f, 0.5f};
    Mat4 Matrix = TranslateV3(Move);
    Mat4 Expect = M4D(1.0f);
    Mat4 Inverse = InvTranslate(Matrix);
    Mat4 Result = MulM4(Matrix, Inverse);
    EXPECT_M4_EQ(Result, Expect);
}

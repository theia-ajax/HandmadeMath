#include "../HandmadeTest.h"

TEST(Projection, Orthographic)
{
#define ORTHO_BOUNDS -8.0f, 12.0f, 5.0f, 10.0f, 1.0f, 100.0f

    // Right-handed
    {
        // Near and far distances correspond to negative Z, hence the Z coordinates here are negative.
        Vec4 minCorner = V4(-8.0f, 5.0f, -1.0f, 1.0);
        Vec4 maxCorner = V4(12.0f, 10.0f, -100.0f, 1.0);

        // Z from -1 to 1 (GL convention)
        {
            Mat4 projection = Orthographic_RH_NO(ORTHO_BOUNDS);
            EXPECT_V4_EQ(MulM4V4(projection, minCorner), V4(-1.0f, -1.0f, -1.0f, 1.0f));
            EXPECT_V4_EQ(MulM4V4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }

        // Z from 0 to 1 (DX convention)
        {
            Mat4 projection = Orthographic_RH_ZO(ORTHO_BOUNDS);
            EXPECT_V4_EQ(MulM4V4(projection, minCorner), V4(-1.0f, -1.0f, 0.0f, 1.0f));
            EXPECT_V4_EQ(MulM4V4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }
    }

    // Left-handed
    {
        // Near and far distances correspond to positive Z, hence the Z coordinates here are positive.
        Vec4 minCorner = V4(-8.0f, 5.0f, 1.0f, 1.0);
        Vec4 maxCorner = V4(12.0f, 10.0f, 100.0f, 1.0);

        // Z from -1 to 1 (GL convention)
        {
            Mat4 projection = Orthographic_LH_NO(ORTHO_BOUNDS);
            EXPECT_V4_EQ(MulM4V4(projection, minCorner), V4(-1.0f, -1.0f, -1.0f, 1.0f));
            EXPECT_V4_EQ(MulM4V4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }

        // Z from 0 to 1 (DX convention)
        {
            Mat4 projection = Orthographic_LH_ZO(ORTHO_BOUNDS);
            EXPECT_V4_EQ(MulM4V4(projection, minCorner), V4(-1.0f, -1.0f, 0.0f, 1.0f));
            EXPECT_V4_EQ(MulM4V4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }
    }
}

TEST(Projection, Perspective)
{
    // Right-handed
    {
        // Z from -1 to 1 (GL convention)
        {
            Mat4 projection = Perspective_RH_NO(AngleDeg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, -1.0f, 1.0f);
            EXPECT_V4_EQ(MulM4V4(projection, original), V4(2.5f, 5.0f, -1.0f, 1.0f));
        }

        // Z from 0 to 1 (DX convention)
        {
            Mat4 projection = Perspective_RH_ZO(AngleDeg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, -1.0f, 1.0f);
            EXPECT_V4_EQ(MulM4V4(projection, original), V4(2.5f, 5.0f, 0.0f, 1.0f));
        }
    }

    // Left-handed
    {
        // Z from -1 to 1 (GL convention)
        {
            Mat4 projection = Perspective_LH_NO(AngleDeg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, 1.0f, 1.0f);
            EXPECT_V4_EQ(MulM4V4(projection, original), V4(2.5f, 5.0f, -1.0f, 1.0f));
        }

        // Z from 0 to 1 (DX convention)
        {
            Mat4 projection = Perspective_LH_ZO(AngleDeg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, 1.0f, 1.0f);
            EXPECT_V4_EQ(MulM4V4(projection, original), V4(2.5f, 5.0f, 0.0f, 1.0f));
        }
    }
}



namespace nn {
namespace math {

/* ------------------------------------------------------------------------
        VEC2
   ------------------------------------------------------------------------ */
NN_MATH_INLINE bool
VEC2IsZero(const VEC2* p)
{
    return p->x == 0.f && p->y == 0.f;
}

NN_MATH_INLINE VEC2*
VEC2Maximize(VEC2* pOut, const VEC2* p1, const VEC2* p2)
{
    pOut->x = (p1->x > p2->x) ? p1->x : p2->x;
    pOut->y = (p1->y > p2->y) ? p1->y : p2->y;

    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2Minimize(VEC2* pOut, const VEC2* p1, const VEC2* p2)
{
    pOut->x = (p1->x < p2->x) ? p1->x : p2->x;
    pOut->y = (p1->y < p2->y) ? p1->y : p2->y;

    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2Normalize(VEC2* pOut, const VEC2* p)
{
    (void)VEC2Scale(pOut, p, FrSqrt(p->x * p->x + p->y * p->y));

    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2SafeNormalize(VEC2* pOut, const VEC2* p, const VEC2& alt)
{
    NN_NULL_ASSERT(pOut);
    NN_NULL_ASSERT(p);

    f32 mag = (p->x * p->x) + (p->y * p->y);

    if (mag == 0)
    {
        *pOut = alt;

        return pOut;
    }

    (void)VEC2Scale(pOut, p, FrSqrt(mag));

    return pOut;
}

}  // namespace math
}  // namespace nn

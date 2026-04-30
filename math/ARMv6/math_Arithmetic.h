#ifndef NN_MATH_ARMV6_MATH_ARITHMETIC_H_
#define NN_MATH_ARMV6_MATH_ARITHMETIC_H_

#include <nn/assert.h>
#include <nn/math/math_Config.h>
#include <nn/math/math_Constant.h>

#include <cmath>

namespace nn {
namespace math {
namespace ARMv6 {

/* =======================================================================
Arithmetic Functions Specific to Floating-Point Numbers
   ======================================================================== */

/*!
@name Arithmetic functions specific to floating-point numbers.
    @{
*/

//! @details :private
f32 HermiteAsm(f32 v0, f32 t0, f32 v1, f32 t1, f32 s);
f32 HermiteAsm(f32 v0, f32 t0, f32 v1, f32 t1, f32 p, f32 d);

/*!--------------------------------------------------------------------------*
@brief Performs Hermite interpolation.

@param[in] v0  Value at point 1.
@param[in] t0  Slope at point 1.
@param[in] v1  Value at point 2.
@param[in] t1  Slope at point 2.
@param[in] s  Interpolation target position. (Point 1: 0.0-1.0 :Point 2)

@return Value of the interpolated result.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 
HermiteC(f32 v0, f32 t0, f32 v1, f32 t1, f32 s)
{
    f32 SS   = s * s;
    f32 SS_S = s * s - s;
    f32 b1 = SS_S * s - SS_S;
    f32 b2 = SS_S * s;
    f32 a2 = SS - 2.f * b2;
    
    return v0 - a2 * v0 + a2 * v1 + b1 * t0 + b2 * t1;
}
NN_MATH_INLINE f32
HermiteC_FAST(f32 v0, f32 t0, f32 v1, f32 t1, f32 s)
{
    f32 SS;
    f32 SS_S;
    f32 b1;
    f32 b2;
    f32 a2;

    SS   = s * s;
    SS_S = s * s - s;
    b2 = SS_S * s;
    b1 = b2 - SS_S;
    a2 = SS - 2.f * b2;
    
    return v0 - a2 * v0 + a2 * v1 + b1 * t0 + b2 * t1;
}


/*!--------------------------------------------------------------------------*
@brief Hermite interpolation calculation.

@param[in] v0  Value at point 1.
@param[in] t0  Slope at point 1.
@param[in] v1  Value at point 2.
@param[in] t1  Slope at point 2.
@param[in] p  Distance from point 1 to the interpolation target position.
@param[in] d  Distance between point 1 and point 2.

@return Result of Hermite interpolation.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32
HermiteC(f32 v0, f32 t0, f32 v1, f32 t1, f32 p, f32 d)
{
    f32 inv_d = 1 / d;
    f32 s = p * inv_d;
    f32 s_1 = s - 1;
    return v0 + (v0 - v1) * (2 * s - 3) * s * s + p * s_1 * (s_1 * t0 + s * t1);
}

NN_MATH_INLINE f32
HermiteC_FAST(f32 v0, f32 t0, f32 v1, f32 t1, f32 p, f32 d)
{

    f32 s = p / d;
    f32 s_1 = s - 1;
    f32 tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, ret;
    
    tmp1 = (v0 - v1);
    tmp2 = (2 * s - 3);
    tmp3 = s * s;
    tmp4 = p * s_1;
    tmp5 = s_1 * t0;
    tmp6 = s * t1;
    
    ret = v0 + tmp1 * tmp2 * tmp3 + tmp4 * (tmp5 + tmp6);
    return ret;
}

/*!
    @}
*/


}}}  // nn::math::ARMv6

/* NN_MATH_ARMV6_MATH_ARITHMETIC_H_ */
#endif

/*---------------------------------------------------------------------------*
Project: Horizon

Copyright (C)Nintendo Co., Ltd.  All rights reserved.

These coded instructions, statements, and computer programs contain
proprietary information of Nintendo of America Inc. and/or Nintendo
Company Ltd., and are protected by Federal copyright law.  They may
not be disclosed to third parties or copied or duplicated in any form,
in whole or in part, without the prior written consent of Nintendo.

$Rev: 58466 $
 *---------------------------------------------------------------------------*/

#ifndef NN_MATH_MATH_TRIANGULAR_H_
#define NN_MATH_MATH_TRIANGULAR_H_

#include <nn/math/math_Config.h>
#include <nn/math/math_Constant.h>
#include <nn/math/math_Arithmetic.h>
#include <nn/math/ARMv6/math_Triangular.h>

#include <cmath>


namespace nn { 
namespace math { 
namespace internal {

    struct SinCosSample
    {
        f32 sin_val;
        f32 cos_val;
        f32 sin_delta; // Difference from the next <tt>sin_val</tt>.
        f32 cos_delta; // Difference from the next <tt>cos_val</tt>.
    };

    extern const SinCosSample gSinCosTbl[256 + 1];

} // namespace internal
} // namespace math
} // namespace nn


namespace nn { 
namespace math {


/* =======================================================================
sin/cos/tan
   ======================================================================== */
/*!
@name Trigonometric Functions
    @{
*/

#define NN_MATH_RAD_TO_FIDX(rad)  ((rad)  * (256.f / (2.0f * ::nn::math::F_PI)))
#define NN_MATH_DEG_TO_FIDX(deg)  ((deg)  * (256.f / 360.f)   )
#define NN_MATH_DEG_TO_RAD(deg)   ((deg)  * (::nn::math::F_PI / 180.0f)   )
#define NN_MATH_RAD_TO_DEG(rad)   ((rad)  * (180.0f / ::nn::math::F_PI)   )
#define NN_MATH_FIDX_TO_RAD(fidx) ((fidx) * ((2.0f * ::nn::math::F_PI) / 256.f))
#define NN_MATH_FIDX_TO_DEG(fidx) ((fidx) * (360.f / 256.f)   )


/*!--------------------------------------------------------------------------*
@brief Finds the sine value.

@param[in] fidx  Angle measured in units of 1/256th of a circle.

@return Returns the value of the sine for <span class="argument">fidx</span>.
 *---------------------------------------------------------------------------*/
f32 SinFIdx(f32 fidx);

/*!--------------------------------------------------------------------------*
@brief Finds the cosine value.

@param[in] fidx  Angle measured in units of 1/256th of a circle.

@return Returns the value of the cosine for <span class="argument">fidx</span>.
 *---------------------------------------------------------------------------*/
f32 CosFIdx(f32 fidx);

/*!--------------------------------------------------------------------------*
@brief Finds the sine and cosine.

@param[out] pSin  Pointer to the buffer that stores the sine.
@param[out] pCos  Pointer to the buffer that stores the cosine.
@param[in] fidx  Angle measured in units of 1/256th of a circle.

@return  None.
 *---------------------------------------------------------------------------*/
void SinCosFIdx(f32* pSin, f32* pCos, f32 fidx);

/*!--------------------------------------------------------------------------*
@brief Finds the tangent value.

@param[in] fidx  Angle measured in units of 1/256th of a circle.

@return Returns the value of the tangent for <span class="argument">fidx</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32
TanFIdx(f32 fidx)
{
    f32 sin, cos;
    SinCosFIdx( &sin, &cos, fidx );
    return sin / cos;
}


/*!--------------------------------------------------------------------------*
@brief Finds the sine value.

@param[in] rad  Angle in radians.

@return Returns the value of the sine for <span class="argument">rad</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 SinRad(f32 rad)  { return SinFIdx(NN_MATH_RAD_TO_FIDX(rad)); }

/*!--------------------------------------------------------------------------*
@brief Finds the cosine value.

@param[in] rad  Angle in radians.

@return Returns the value of the cosine for <span class="argument">rad</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 CosRad(f32 rad)  { return CosFIdx(NN_MATH_RAD_TO_FIDX(rad)); }

/*!--------------------------------------------------------------------------*
@brief Finds the sine and cosine value.

@param[out] s  Pointer to the buffer that stores the sine.
@param[out] c  Pointer to the buffer that stores the cosine.
@param[in] rad  Angle in radians.

@return  None.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE void SinCosRad(f32* s, f32* c, f32 rad) { SinCosFIdx(s, c, NN_MATH_RAD_TO_FIDX(rad)); }

/*!--------------------------------------------------------------------------*
@brief Finds the tangent value.

@param[in] rad  Angle in radians.

@return Returns the value of the tangent for <span class="argument">rad</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 TanRad(f32 rad)  { return TanFIdx(NN_MATH_RAD_TO_FIDX(rad)); }




/*!--------------------------------------------------------------------------*
@brief Finds the sine value.

@param[in] deg  Angle measured in degrees.

@return Returns the value of the sine for <span class="argument">deg</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 SinDeg(f32 deg)  { return SinFIdx(NN_MATH_DEG_TO_FIDX(deg)); }

/*!--------------------------------------------------------------------------*
@brief Finds the cosine value.

@param[in] deg  Angle measured in degrees.

@return Returns the value of the cosine for <span class="argument">deg</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 CosDeg(f32 deg)  { return CosFIdx(NN_MATH_DEG_TO_FIDX(deg)); }

/*!--------------------------------------------------------------------------*
@brief Finds the sine and cosine value.

@param[out] s  Pointer to the buffer that stores the sine.
@param[out] c  Pointer to the buffer that stores the cosine.
@param[in] deg  Angle measured in degrees.

@return  None.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE void SinCosDeg(f32* s, f32* c, f32 deg) { SinCosFIdx(s, c, NN_MATH_DEG_TO_FIDX(deg)); }

/*!--------------------------------------------------------------------------*
@brief Finds the tangent value.

@param[in] deg  Angle measured in degrees.

@return Returns the value of the tangent for <span class="argument">deg</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 TanDeg(f32 deg)  { return TanFIdx(NN_MATH_DEG_TO_FIDX(deg)); }

#if 1
/* When we introduce a function with a 16-bit index, the implementation of this function will be replaced. */

/*!--------------------------------------------------------------------------*
@brief Finds the sine value.

@param[in] idx  Angle measured in units of 1/65536th of a circle.

@return Returns the value of the sine for <span class="argument">idx</span>.
 *---------------------------------------------------------------------------*/
f32 SinIdx(u16 idx);

/*!--------------------------------------------------------------------------*
@brief Finds the cosine value.

@param[in] idx  Angle measured in units of 1/65536th of a circle.

@return Returns the value of the cosine for <span class="argument">fidx</span>.
 *---------------------------------------------------------------------------*/
f32 CosIdx(u16 idx);

/*!--------------------------------------------------------------------------*
@brief Finds the sine and cosine value.

@param[out] s  Pointer to the buffer that stores the sine.
@param[out] c  Pointer to the buffer that stores the cosine.
@param[in] idx  Angle measured in units of 1/65536th of a circle.

@return  None.
 *---------------------------------------------------------------------------*/
void SinCosIdx(f32* s, f32* c, u16 idx);

/*!--------------------------------------------------------------------------*
@brief Finds the tangent value.

@param[in] idx  Angle measured in units of 1/65536th of a circle.

@return Returns the value of the tangent for <span class="argument">idx</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 TanIdx(u16 idx)
{
    f32 sin, cos;
    SinCosIdx( &sin, &cos, idx );
    return sin / cos;
}
#endif

/*!--------------------------------------------------------------------------*
@brief Finds the arccosine value. In contrast with <tt>AcosRad</tt>, no warning message is displayed.

@param[in] x  Value whose inverse cosine (arccosine) you want to find.

@return Returns the value of the arccosine for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 NN_fAcos(f32 x) { return ::std::acosf(x); }
/*!--------------------------------------------------------------------------*
@brief Finds the arcsine value. In contrast with <tt>AsinRad</tt>, no warning message is displayed.

@param[in] x  Value whose inverse sine (arcsine) you want to find.

@return Returns the value of the arcsine for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 NN_fAsin(f32 x) { return ::std::asinf(x); }
/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] x  Value whose inverse tangent (arctangent) you want to find.

@return Returns the value of the arctangent for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 NN_fAtan(f32 x) { return ::std::atanf(x); }
/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] y  Numerator of the tangent value.
@param[in] x  Denominator of the tangent value.

@return Returns the value of the arctangent for <span class="argument">y</span>/<span class="argument">x</span> in radians.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 NN_fAtan2(f32 y, f32 x) { return ::std::atan2f(y, x); }


/*!--------------------------------------------------------------------------*
@brief Finds the arcsine value.

@param[in] x  Value whose inverse sine (arcsine) you want to find.

@return Returns the arcsine for the angle measured in units of 1/256th of a circle.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32
AsinFIdx(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AsinFIdx: Input is out of the domain.");
    return NN_MATH_RAD_TO_FIDX(::std::asin(x));
}

/*!--------------------------------------------------------------------------*
@brief Finds the arccosine value.

@param[in] x  Value whose inverse cosine (arccosine) you want to find.

@return Returns the arccosine for the angle measured in units of 1/256th of a circle.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32
AcosFIdx(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AcosFIdx: Input is out of the domain.");
    return NN_MATH_RAD_TO_FIDX(::std::acosf(x));
}

/*!--------------------------------------------------------------------------*
Name: AtanFIdx

@brief Finds the arctangent by table lookup.

@param[in] x  Value whose inverse tangent (arctangent) you want to find.

@return Returns the arctangent for the angle measured in units of 1/256th of a circle.
 *---------------------------------------------------------------------------*/
f32 AtanFIdx(f32 x);
/*!--------------------------------------------------------------------------*
Name: Atan2FIdx

@brief Finds the arctangent value.

@param[in] y  Numerator of the tangent value.
@param[in] x  Denominator of the tangent value.

@return Returns the inverse tangent of <span class="argument">y</span>/<span class="argument">x</span> in angle units for which one complete revolution is defined as equal to 256.0 units.
 *---------------------------------------------------------------------------*/
f32 Atan2FIdx(f32 y, f32 x);


/*!--------------------------------------------------------------------------*
@brief Finds the arcsine value. In contrast with <tt>NN_fAsin</tt>, a warning is displayed depending on the arguments that are used.

@param[in] x  Value whose inverse sine (arcsine) you want to find.

@return Returns the value of the arcsine for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AsinRad(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AsinRad: Input is out of the domain.");
    return ::std::asin(x);
}

/*!--------------------------------------------------------------------------*
@brief Finds the arccosine value. In contrast with <tt>NN_Acos</tt>, a warning is displayed depending on the arguments that are used.

@param[in] x  Value whose inverse cosine (arccosine) you want to find.

@return Returns the value of the arccosine for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AcosRad(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AcosRad: Input is out of the domain.");
    return ::std::acos(x);
}

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent by table lookup.

@param[in] x  Value whose inverse tangent (arctangent) you want to find.

@return Returns the value of the arctangent for <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AtanRad(f32 x)  { return NN_MATH_FIDX_TO_RAD(AtanFIdx(x)); }

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] y  Numerator of the tangent value.
@param[in] x  Denominator of the tangent value.

@return Returns the value of the arctangent for <span class="argument">y</span>/<span class="argument">x</span> in radians.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 Atan2Rad(f32 y, f32 x)  { return NN_MATH_FIDX_TO_RAD(Atan2FIdx(y, x)); }






/*!--------------------------------------------------------------------------*
@brief Finds the arcsine value.

@param[in] x  Value whose inverse sine (arcsine) you want to find.

@return Returns the value of the arcsine of <span class="argument">x</span> in units of 1/360.0 of a circle.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AsinDeg(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AsinDeg: Input is out of the domain.");
    return NN_MATH_RAD_TO_DEG(::std::asin(x));
}

/*!--------------------------------------------------------------------------*
@brief Finds the arccosine value.

@param[in] x  Value whose inverse cosine (arccosine) you want to find.

@return Returns the value of the arccosine of <span class="argument">x</span> in units of 1/360.0 of a circle.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AcosDeg(f32 x)
{
    NN_MATH_WARNING(x <= 1.f && x >= -1.f, "AcosDeg: Input is out of the domain.");
    return NN_MATH_RAD_TO_DEG(::std::acos(x));
}

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] x  Value whose inverse tangent (arctangent) you want to find.

@return Returns the value of the arctangent of <span class="argument">x</span> in units of 1/360.0 of a circle.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 AtanDeg(f32 x)  { return NN_MATH_FIDX_TO_DEG(AtanFIdx(x)); }

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] y  Numerator of the tangent value.
@param[in] x  Denominator of the tangent value.

@return Returns the inverse tangent of <span class="argument">y</span>/<span class="argument">x</span> in angle units for which one complete revolution is defined as equal to 360.0 units.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 Atan2Deg(f32 y, f32 x)  { return NN_MATH_FIDX_TO_DEG(Atan2FIdx(y, x)); }

#if 1
/* When we introduce a function with a 16-bit index, the implementation of this function will be replaced. */


/*!--------------------------------------------------------------------------*
@brief Finds the arcsine value.

@param[in] x  Value whose inverse sine (arcsine) you want to find.

@return Returns the value of the arcsine of <span class="argument">x</span> in units of 1/65536 of a circle.
 *---------------------------------------------------------------------------*/
//        Returns an index in the range from 0 to 90 degrees and 270 to 360 degrees.
NN_MATH_INLINE u16 AsinIdx(f32 x)  { f32 fidx = AsinFIdx(x); return F32ToU16((fidx < 0 ? fidx + 256.f : fidx) * 256.f); }

/*!--------------------------------------------------------------------------*
@brief Finds the arccosine value.

@param[in] x  Value whose inverse cosine (arccosine) you want to find.

@return Returns the value of the arccosine of <span class="argument">x</span> in units of 1/65536 of a circle.
 *---------------------------------------------------------------------------*/
//        Returns an index in the range from 0 to pi.
NN_MATH_INLINE u16 AcosIdx(f32 x)  { return F32ToU16(AcosFIdx(x) * 256.f); }

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] x  Value whose inverse tangent (arctangent) you want to find.

@return Returns the value of the arctangent of <span class="argument">x</span> in units of 1/65536 of a circle.
 *---------------------------------------------------------------------------*/
//        Returns an index in the range from 0 to 90 degrees and 270 to 360 degrees.
u16 AtanIdx(f32 x);

/*!--------------------------------------------------------------------------*
@brief Finds the arctangent value.

@param[in] y  Numerator of the tangent value.
@param[in] x  Denominator of the tangent value.

@return Returns the inverse tangent of <span class="argument">y</span>/<span class="argument">x</span> in angle units for which one complete revolution is defined as equal to 65536 units.
 *---------------------------------------------------------------------------*/
//        Returns an index in the range from 0 to 360 degrees.
u16 Atan2Idx(f32 y, f32 x);
#endif

/*!
    @}
*/

} // namespace math
} // namespace nn


/* NN_MATH_MATH_TRIANGULAR_H_ */
#endif

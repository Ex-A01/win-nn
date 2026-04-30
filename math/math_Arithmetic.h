#ifndef NN_MATH_MATH_ARITHMETIC_H_
#define NN_MATH_MATH_ARITHMETIC_H_

#include <nn/assert.h>
#include <nn/math/math_Config.h>
#include <nn/math/math_Constant.h>
#include <nn/math/ARMv6/math_Arithmetic.h>

#include <cmath>

#pragma push
#pragma Otime

namespace nn { namespace math {



/* =======================================================================
Arithmetic Functions Specific to Floating-point Numbers
   ======================================================================== */

/*!
@name Arithmetic Functions Specific to Floating-point Numbers
    @{
*/

// u32 F32AsU32(f32 x)
//
// Description: Converts an <tt>32</tt> type into a <tt>u32</tt> type without changing the bit array.
// Arguments: x: The value to convert to a <tt>u32</tt> type.
// Return value: A <tt>u32</tt>-type value that has a bit expression equivalent to x.
inline u32
F32AsU32(f32 x)
{
    return *reinterpret_cast<u32*>(&x);
}



/*!--------------------------------------------------------------------------*
@brief Converts a <tt>u32</tt> type into an <tt>f32</tt> type without changing the bit array

@param[in] x  Value to convert to <tt>f32</tt> format.

@return An <tt>f32</tt>-type value that has a bit expression equivalent to x.
 *---------------------------------------------------------------------------*/
inline f32
U32AsF32(u32 x)
{
    return *reinterpret_cast<f32*>(&x);
}


/*!--------------------------------------------------------------------------*
@brief Gets the exponent portion of a floating-point number.

@param[in] f  Number whose exponential part you want to get.

@return Returns the exponential part of <span class="argument">f</span>. However, negative values are not offset expressions, but rather complement expressions of 2.
 *---------------------------------------------------------------------------*/
inline s32
FGetExpPart(f32 f)
{
    s32 s = static_cast<s32>((F32AsU32(f) >> 23) & 0xFF);
    return s - 127;
}


/*!--------------------------------------------------------------------------*
@brief Finds the mantissa portion of a floating-point number.

@param[in] f  Number whose mantissa you want to get.

@return Returns the mantissa of <span class="argument">f</span>. The return value has the same sign as <span class="argument">f</span>.
 *---------------------------------------------------------------------------*/
inline f32
FGetMantPart(f32 f)
{
    // Sets the exponent portion to 127.
    u32 u = (F32AsU32(f) & 0x807FFFFF) | 0x3F800000;
    return U32AsF32(u);
}


/*!--------------------------------------------------------------------------*
@brief Selects a value depending on whether a number is positive or negative.

@param[in] cond  Condition for selecting a return value.
@param[in] ifPos  The return value if cond is 0 or greater.
@param[in] ifNeg  The return value if cond is negative.

@return Returns <span class="argument">ifPos</span> if <span class="argument">cond</span> is 0 or more; otherwise, returns <span class="argument">ifNeg</span>.
 *---------------------------------------------------------------------------*/
inline f32
FSelect(f32 cond, f32 ifPos, f32 ifNeg)
{
    f32 ret;

    ret = (cond >= 0) ? ifPos: ifNeg;


    return ret;
}


/*!--------------------------------------------------------------------------*
@brief Finds the absolute value.

@param[in] x  Value whose absolute value you want to find.

@return Returns the absolute value of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FAbs(f32 x)
{
    f32 ret;

    ret = ::std::fabsf(x);


    return ret;
}


/*!--------------------------------------------------------------------------*
@brief Finds a number with the same absolute value but whose sign is negative.

@param[in] x  Original number.

@return Returns a number with the same absolute value as <span class="argument">x</span> but with a negative sign.
 *---------------------------------------------------------------------------*/
inline f32
FNAbs(f32 x)
{
    f32 ret;

    ret = - FAbs(x);


    return ret;
}


/*!--------------------------------------------------------------------------*
@brief Copies the sign of one number to another number.

@param[in] abs  Number to use for the absolute value.
@param[in] sign  Number to use for the sign.

@return Returns a number that has the absolute value of <span class="argument">abs</span> and the sign of <span class="argument">sign</span>.
 *---------------------------------------------------------------------------*/
inline f32
FCopySign(f32 abs, f32 sign)
{
    f32 pos = FAbs(abs);
    f32 neg = FNAbs(abs);

    return FSelect(sign, pos, neg);
}

namespace internal
{
    f32 FExp(f32 x);
    f32 FLog(f32 x);
}


/*!--------------------------------------------------------------------------*
@brief Finds e^x.

@param[in] x  Exponent value.

@return Returns e^<span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FExp(f32 x)
{
    return ::std::expf(x);

}


/*!--------------------------------------------------------------------------*
@brief Finds the natural logarithm.

@param[in] x  Value whose natural logarithm you want to find.

@return Returns the natural logarithm of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FLog(f32 x)
{
    NN_MATH_WARNING(x > 0, "FLog: Input is out of the domain.");

    return ::std::logf(x);

}


/*!--------------------------------------------------------------------------*
@brief Finds the common logarithm.

@param[in] x  Value whose common logarithm you want to find.

@return Returns the common logarithm of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FLog10(f32 x)
{
    NN_MATH_WARNING(x > 0, "FLog10: Input is out of the domain.");

    return ::std::log10f(x);
}


/*!--------------------------------------------------------------------------*
@brief Calculates the remainder.

@param[in] x  Number to be divided (dividend).
@param[in] y  Number to divide by (divisor).

@return Returns the remainder of <span class="argument">x</span>/<span class="argument">y</span>.
 *---------------------------------------------------------------------------*/
inline f32
FMod(f32 x, f32 y)
{
    return ::std::fmodf(x, y);
}


/*!--------------------------------------------------------------------------*
@brief Separates a floating-point number into an integer part and a decimal part. The integer part and the decimal part both have the same sign as <span class="argument">x</span>.

@param[in] x  Original floating-point number.
@param[out] y  Pointer to the buffer that stores the integer part.

@return Returns the fractional part.
 *---------------------------------------------------------------------------*/
inline f32
FModf(f32 x, f32* y)
{
    return ::std::modff(x, y);
}


/*!--------------------------------------------------------------------------*
@brief Finds the smallest integer value not less than <span class="argument">x</span>.

@param[in] x  Value to operate on.

@return Returns the smallest integer value not less than <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FCeil(f32 x)
{
    return ::std::ceilf(x);
}


/*!--------------------------------------------------------------------------*
@brief Finds the largest integer value less than or equal to <span class="argument">x</span>.

@param[in] x  Value to operate on.

@return Returns the largest integer value less than or equal to <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FFloor(f32 x)
{
    return ::std::floorf(x);
}


/*!--------------------------------------------------------------------------*
@brief Converts an <tt>f32</tt> type into an <tt>s16</tt> type.

@param[in] x  Value to be converted to <tt>s16</tt>-type.

@return Returns the value of an <tt>s16</tt> type that has the same value as <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline s16
F32ToS16(f32 x)
{
    return s16(x);

}


/*!--------------------------------------------------------------------------*
@brief Converts an <tt>f32</tt> type into a <tt>u16</tt> type.

@param[in] x  Value to convert to <tt>u16</tt>-type.

@return Returns the value of a <tt>u16</tt> type that has the same value as <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline u16
F32ToU16(f32 x)
{
    return u16(x);

}


/*!--------------------------------------------------------------------------*
@brief Converts a <tt>u16</tt> type into an <tt>f32</tt> type.

@param[in] x  Value to convert to <tt>f32</tt> format.

@return Returns the value of an <tt>f32</tt> type that has the same value as <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
U16ToF32(u16 x)
{
    return f32(x);

}


/*!--------------------------------------------------------------------------*
@brief Converts an <tt>s16</tt> type into an <tt>f32</tt> type.

@param[in] x  Value to convert to <tt>f32</tt> format.

@return Returns the value of an <tt>f32</tt> type that has the same value as <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
S16ToF32(s16 x)
{
    return f32(x);

}



/*!--------------------------------------------------------------------------*
@brief Finds the inverse.

@param[in] x  Value to find the inverse for.

@return Returns the inverse of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FInv(f32 x)
{
    f32 ix;

    ix = 1.0f / x;


    return ix;
}


/*!--------------------------------------------------------------------------*
@brief Finds the inverse of the square root

@param[in] x  Value whose inverse square root is to be found.

@return Returns the inverse of the square root of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32 
FrSqrt(f32 x)
{
    NN_MATH_WARNING(x > 0, "FrSqrt: Input is out of the domain.");

    return 1.f / ::std::sqrtf(x);
}


/*!--------------------------------------------------------------------------*
@brief Finds the square root

@param[in] x  Value whose square root you want to find.

@return Returns the square root of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FSqrt(f32 x)
{
    NN_MATH_WARNING(x >= 0, "FSqrt: Input is out of the domain.");

    return ::std::sqrtf(x);
}


/*!--------------------------------------------------------------------------*
@brief Finds the cubic root

@param[in] x  Value whose cube root you want to find.

@return Returns the cubic root of <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline f32
FCbrt(f32 x)
{
#if defined(NN_CW3)
    return ::std::cbrtf(x);
#else
    return ::std::pow(x, 1/3.f);
#endif
}


/*!--------------------------------------------------------------------------*
@brief Performs Hermite interpolation.

@param[in] v0  Value at point 1.
@param[in] t0  Slope at point 1.
@param[in] v1  Value at point 2.
@param[in] t1  Slope at point 2.
@param[in] s  Interpolation target position. (Point 1: 0.0-1.0 :Point 2)

@return Value of the interpolated result.
 *---------------------------------------------------------------------------*/
inline f32 
Hermite(f32 v0, f32 t0, f32 v1, f32 t1, f32 s)
{
#if defined( NN_HARDWARE_CTR )
    #if (HERMITE_5_CONFIG == D_ORG)
        return ARMv6::HermiteC(v0, t0, v1, t1, s);
    #elif (HERMITE_5_CONFIG == D_FAST_C)
        return ARMv6::HermiteC_FAST(v0, t0, v1, t1, s);
    #elif (HERMITE_5_CONFIG == D_FAST_ASM)
    #elif (HERMITE_5_CONFIG == D_FAST_C_ALGO)
    #elif (HERMITE_5_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
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
NN_FORCE_INLINE f32
Hermite(f32 v0, f32 t0, f32 v1, f32 t1, f32 p, f32 d)
{
#if defined( NN_HARDWARE_CTR )
    #if (HERMITE_6_CONFIG == D_ORG)
        return ARMv6::HermiteC(v0, t0, v1, t1, p, d);
    #elif (HERMITE_6_CONFIG == D_FAST_C)
        return ARMv6::HermiteC_FAST(v0, t0, v1, t1, p, d);
    #elif (HERMITE_6_CONFIG == D_FAST_ASM)
        return ARMv6::HermiteAsm(v0, t0, v1, t1, p, d);
    #elif (HERMITE_6_CONFIG == D_FAST_C_ALGO)
    #elif (HERMITE_6_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}


f32 Bezier(f32 p1, f32 p2, f32 p3, f32 p4, f32 s);
f32 CatmullRom(f32 p0, f32 p1, f32 p2, f32 p3, f32 s);

/*!
    @}
*/

/* =======================================================================
Integer-related
   ======================================================================== */

/*!
@name Integer Math Functions
    @{
*/

// Non-Inline Functions

u32 CntBit1(u32 x);
u32 CntBit1(const u32* first, const u32* last);
u32 DistBit(const u32* first1, const u32* last1, const u32* first2);
u32 RevBit(u32 x);
int IExp(int x, u32 n);
u32 ILog10(u32 x);

#ifndef NN_PROCESSOR_ARM
namespace internal
{
u32 CntLz_(u32 x);
}
#endif

/*!--------------------------------------------------------------------------*
@brief Counts the number of contiguous 0 bits from the MSB.

@param[in] x  Bit array.

@return Returns the number of contiguous 0 bits from the MSB.
 *---------------------------------------------------------------------------*/
inline u32
CntLz(u32 x)
{
#ifdef NN_PROCESSOR_ARM
    return __clz(x);
#else
    return internal::CntLz_(x);
#endif
}


/*!--------------------------------------------------------------------------*
@brief Determines if an integer value is a power of two.

@param[in] x  Integer value to evaluate.

@return Returns <tt>true</tt> if <span class="argument">x</span> is a power of two; otherwise, returns <tt>false</tt>.
 *---------------------------------------------------------------------------*/
//          However, the function returns <tt>true</tt> if <span class="argument">x</span> is <tt>0</tt>.
inline bool IsPwr2(int x) { return 0 == (x & (x - 1)); }

/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is one.

@param[in] x  Target bit string.

@return Returns the bit array whose only 1 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline int Rightmost1(int x) { return x & (-x); }
/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is one.

@param[in] x  Target bit string.

@return Returns the bit array whose only 1 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline bit32 Rightmost1(bit32 x) { return x & (-x); }
/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is one.

@param[in] x  Target bit string.

@return Returns the bit array whose only 1 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline bit64 Rightmost1(bit64 x) { return x & (-x); }

/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is zero.

@param[in] x  Target bit string.

@return Returns the bit array whose only 0 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline int Rightmost0(int x) { return ~x & (x + 1); }
/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is zero.

@param[in] x  Target bit string.

@return Returns the bit array whose only 0 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline bit32 Rightmost0(bit32 x) { return ~x & (x + 1); }
/*!--------------------------------------------------------------------------*
@brief Gets the rightmost bit (on the LSB side) whose value is zero.

@param[in] x  Target bit string.

@return Returns the bit array whose only 0 is the bit position of the rightmost 1 in <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline bit64 Rightmost0(bit64 x) { return ~x & (x + 1); }

/*!--------------------------------------------------------------------------*
@brief Calculates the distance between two bit strings.

@param[in] x  Bit array 1.
@param[in] y  Bit array 2.

@return Returns the distance between bit string 1 and bit string 2.
 *---------------------------------------------------------------------------*/
inline u32 DistBit(u32 x, u32 y) { return CntBit1(x ^ y); }

/*!--------------------------------------------------------------------------*
@brief Counts the number of contiguous 0 bits from the LSB.

@param[in] x  Bit array.

@return Returns the number of contiguous 0 bits from the LSB.
 *---------------------------------------------------------------------------*/
inline u32 CntTz(u32 x) { return 32 - CntLz(~x & (x - 1)); }

/*!--------------------------------------------------------------------------*
@brief Calculates the base 2 logarithm of an integer and returns the result as an integer.

@param[in] x  Real number.

@return Returns the log base 2 of an integer as an integer.
 *---------------------------------------------------------------------------*/
inline u32 ILog2(u32 x) { return 31 - CntLz(x); }

/*!--------------------------------------------------------------------------*
@brief Calculates the largest power of 2 that is equal to or smaller than the provided integer.

@param[in] x  Integer value.

@return Returns the largest power of 2 that is equal to or smaller than <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline u32 FloorPwr2(u32 x) { return 0x80000000 >> CntLz(x); }

/*!--------------------------------------------------------------------------*
@brief Calculates the smallest power of 2 that is larger than the provided integer.

@param[in] x  Integer value.

@return Returns the smallest power of 2 that is larger than <span class="argument">x</span>.
 *---------------------------------------------------------------------------*/
inline u32 CeilPwr2(u32 x) { return 0x80000000 >> (CntLz(x - 1) - 1); }

/*!
    @}
*/

}}  // nn::math

#pragma pop

/* NN_MATH_MATH_ARITHMETIC_H_ */
#endif

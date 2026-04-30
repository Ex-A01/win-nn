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

#ifndef NN_MATH_MATH_UTILITY_H_
#define NN_MATH_MATH_UTILITY_H_

#include <nn/types.h>

namespace nn { namespace math {

/*!
@name Math Functions
    @{
*/

    /*!
@brief Finds the absolute value.
    
@tparam T  A type representing a numerical value.
@param[in] x  Number for evaluation.
@return Returns the absolute value of <span class="argument">x</span>.
    */
    template <typename T>
    inline T Abs(T x)
    {
        return (x >= 0) ? x: -x;
    }

    /*!
:overload   different_type
@brief Finds the maximum value.
    
@tparam T  A type representing a numerical value.
@tparam U  A type representing a numerical value.
@tparam S  Return value type.
@param[in] a  Value to compare to the <span class="argument">b</span> argument.
@param[in] b  Value to compare to the <span class="argument">a</span> argument.
@return Compares <span class="argument">a</span> and <span class="argument">b</span> and returns the larger value.
    */
    template <typename T, typename U, typename S>
    inline S Max(T a, U b)
    {
        return (a >= b) ? a: b;
    }

    /*!
:overload   same_type
@brief Finds the maximum value.
    
@tparam T  A type representing a numerical value.
@param[in] a  Value to compare to the <span class="argument">b</span> argument.
@param[in] b  Value to compare to the <span class="argument">a</span> argument.
@return Compares <span class="argument">a</span> and <span class="argument">b</span> and returns the larger value.
    */
    template <typename T>
    inline T Max(T a, T b)
    {
        return (a >= b) ? a: b;
    }

    /*!
:overload   different_type
@brief Finds the minimum value.
    
@tparam T  A type representing a numerical value.
@tparam U  A type representing a numerical value.
@tparam S  Return value type.
@param[in] a  Value to compare to the <span class="argument">b</span> argument.
@param[in] b  Value to compare to the <span class="argument">a</span> argument.
@return Compares <span class="argument">a</span> and <span class="argument">b</span> and returns the smaller value.
    */
    template <typename T, typename U, typename S>
    inline S Min(T a, U b)
    {
        return (a <= b) ? a: b;
    }

    /*!
:overload   same_type
@brief Finds the minimum value.
    
@tparam T  A type representing a numerical value.
@param[in] a  Value to compare to the <span class="argument">b</span> argument.
@param[in] b  Value to compare to the <span class="argument">a</span> argument.
@return Compares <span class="argument">a</span> and <span class="argument">b</span> and returns the smaller value.
    */
    template <typename T>
    inline T Min(T a, T b)
    {
        return (a <= b) ? a: b;
    }

    /*!
:overload   three_different_type
@brief Finds the maximum value.
    
@tparam T  A type representing a numerical value.
@tparam U  A type representing a numerical value.
@tparam R  A type representing a numerical value.
@tparam S  Return value type.
@param[in] a  Value to compare to other arguments.
@param[in] b  Value to compare to other arguments.
@param[in] c  Value to compare to other arguments.
@return Compares <span class="argument">a</span>, <span class="argument">b</span>, and <span class="argument">c</span> and returns the largest value.
    */
    template <typename T, typename U, typename R, typename S>
    inline S Max(T a, U b, R c)
    {
        return (a >= b) ? ((a >= c) ? a: c) : ((b >= c) ? b: c);
    }

    /*!
:overload   three_same_type
@brief Finds the maximum value.
    
@tparam T  A type representing a numerical value.
@param[in] a  Value to compare to other arguments.
@param[in] b  Value to compare to other arguments.
@param[in] c  Value to compare to other arguments.
@return Compares <span class="argument">a</span>, <span class="argument">b</span>, and <span class="argument">c</span> and returns the largest value.
    */
    template <typename T>
    inline T Max(T a, T b, T c)
    {
        return (a >= b) ? ((a >= c) ? a: c) : ((b >= c) ? b: c);
    }

    /*!
:overload   three_different_type
@brief Finds the minimum value.
    
@tparam T  A type representing a numerical value.
@tparam U  A type representing a numerical value.
@tparam R  A type representing a numerical value.
@tparam S  Return value type.
@param[in] a  Value to compare to other arguments.
@param[in] b  Value to compare to other arguments.
@param[in] c  Value to compare to other arguments.
@return Compares <span class="argument">a</span>, <span class="argument">b</span>, and <span class="argument">c</span> and returns the smallest value.
    */
    template <typename T, typename U, typename R, typename S>
    inline S Min(T a, U b, R c)
    {
        return (a <= b) ? ((a <= c) ? a: c) : ((b <= c) ? b: c);
    }

    /*!
:overload   three_same_type
@brief Finds the minimum value.
    
@tparam T  A type representing a numerical value.
@param[in] a  Value to compare to other arguments.
@param[in] b  Value to compare to other arguments.
@param[in] c  Value to compare to other arguments.
@return Compares <span class="argument">a</span>, <span class="argument">b</span>, and <span class="argument">c</span> and returns the smallest value.
    */
    template <typename T>
    inline T Min(T a, T b, T c)
    {
        return (a <= b) ? ((a <= c) ? a: c) : ((b <= c) ? b: c);
    }

    /*!
@brief Clamps a value to the specified range.
    
If <span class="argument">x</span> is not between <span class="argument">low</span> and <span class="argument">high</span>, this function returns the value (either <span class="argument">low</span> or <span class="argument">high</span>) that is closer to <span class="argument">x</span>.
    
@tparam T  A type representing a numerical value.
@param[in] x  Value to operate on.
@param[in] low  Low threshold value.
@param[in] high  High threshold value.
@return If <span class="argument">x</span> is in the range [<span class="argument">low</span>, <span class="argument">high</span>], this function returns <span class="argument">x</span>; if <span class="argument">x</span> is outside the range, this function returns either <span class="argument">low</span> or <span class="argument">high</span>.
    */
    template <typename T>
    inline T Clamp(T x, T low, T high)
    {
        return (x >= high) ? high : ((x <= low) ? low: x);
    }

    /*!
:overload   value
@brief Rounds a value up so that it is a multiple of the specified value.
    
@tparam T  A type representing a numerical value.
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the minimum value that is a multiple of <span class="argument">base</span> and greater than or equal to <span class="argument">x</span>.
    */
    template <typename T>
    inline T RoundUp(T x, u32 base)
    {
        return static_cast<T>( (x + (base - 1)) & ~(base - 1) );
    }

    /*!
:overload   pointer
@brief Rounds up a value so that it is a multiple of the specified value.
    
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the minimum value that is a multiple of <span class="argument">base</span> and greater than or equal to <span class="argument">x</span>.
    */
    template <>
    inline void* RoundUp(void* x, u32 base)
    {
        return reinterpret_cast<void*>( RoundUp(reinterpret_cast<uptr>(x), base) );
    }

    /*!
:overload   const_pointer
@brief Rounds up a value so that it is a multiple of the specified value.
    
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the minimum value that is a multiple of <span class="argument">base</span> and greater than or equal to <span class="argument">x</span>.
    */
    template <>
    inline const void* RoundUp(const void* x, u32 base)
    {
        return reinterpret_cast<const void*>( RoundUp(reinterpret_cast<uptr>(x), base) );
    }

    /*!
:overload   value
@brief Rounds a value down so it is a multiple of the specified value.
    
@tparam T  A type representing a numerical value.
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the maximum value that is a multiple of <span class="argument">base</span> and less than or equal to <span class="argument">x</span>.
    */
    template <typename T>
    inline T RoundDown(T x, u32 base)
    {
        return static_cast<T>( x & ~(base - 1) );
    }

    /*!
:overload   pointer
@brief Rounds down a value so that it is a multiple of the specified value.
    
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the maximum value that is a multiple of <span class="argument">base</span> and less than or equal to <span class="argument">x</span>.
    */
    template <>
    inline void* RoundDown(void* x, u32 base)
    {
        return reinterpret_cast<void*>( RoundDown(reinterpret_cast<uptr>(x), base) );
    }

    /*!
:overload   const_pointer
@brief Rounds down a value so that it is a multiple of the specified value.
    
@param[in] x  Value to operate on.
@param[in] base  Standard value (a power of two).
@return Returns the maximum value that is a multiple of <span class="argument">base</span> and less than or equal to <span class="argument">x</span>.
    */
    template <>
    inline const void* RoundDown(const void* x, u32 base)
    {
        return reinterpret_cast<const void*>( RoundDown(reinterpret_cast<uptr>(x), base) );
    }

    /*!
@brief Finds the quotient of a division operation that takes two values. The remainder is rounded up.
    
@tparam T  A type representing a numerical value.
@param[in] x  Value to divide by <span class="argument">y</span>.
@param[in] y  Value by which to divide <span class="argument">x</span>.
@return Returns the result of dividing <span class="argument">x</span> by <span class="argument">y</span>, with the remainder rounded up.
    */
    template <typename T>
    inline T DivUp(T x, T y)
    {
        return static_cast<T>( (x + (y - 1)) / y );
    }
/*!
    }
*/

/*!
@name Bit Operations
    @{
*/

    /*!
:overload   bit32

@brief Extracts the bitstring used to maintain the position.

Extracts the number of bits specified by <span class="argument">len</span>, starting from the bit specified by <span class="argument">pos</span> ([<span class="argument">pos</span>+<span class="argument">len</span>-1,<span class="argument">pos</span>]) from the low-order bits of <span class="argument">v</span>.

You can also make it so that 0s are created for bits other than those specified by <span class="argument">len</span> starting from the bit given by <span class="argument">pos</span> from the low-order bits of <span class="argument">v</span>.

@tparam T  Return value type.
@param[in] v  Value to operate on.
@param[in] pos  A position relative to the lowest bit.
@param[in] len  The bit length of the bit string to be extracted.

@return Returns the extracted bit string.
    
*/
    template <typename T>
    inline T ExtractBits(bit32 v, int pos, int len)
    {
        return static_cast<T>( v & (((1u << len) - 1) << pos) );
    }

    /*!
:overload   bit64

@brief Extracts the bitstring used to maintain the position.

Extracts the number of bits specified by <span class="argument">len</span>, starting from the bit specified by <span class="argument">pos</span> ([<span class="argument">pos</span>+<span class="argument">len</span>-1,<span class="argument">pos</span>]) from the low-order bits of <span class="argument">v</span>.

You can also make it so that 0s are created for bits other than those specified by <span class="argument">len</span>, starting from the bit given by <span class="argument">pos</span> from the low-order bits of <span class="argument">v</span>.
    
@tparam T  Return value type.
@param[in] v  Value to operate on.
@param[in] pos  A position relative to the lowest bit.
@param[in] len  Range to extract.

@return Returns the extracted bit string.
    
*/
    template <typename T>
    inline T ExtractBits(bit64 v, int pos, int len)
    {
        return static_cast<T>( v & (((1ull << len) - 1) << pos) );
    }
    
    /*!
:overload   bit32

@brief Gets a bit string.

Extracts the number of bits specified by <span class="argument">len</span>, starting from the bit specified by <span class="argument">pos</span> ([<span class="argument">pos</span>+<span class="argument">len</span>-1,<span class="argument">pos</span>]) from the low-order bits of <span class="argument">v</span>.
The bit position in <span class="argument">v</span> specified by <span class="argument">pos</span> is taken as the 0th bit.
    
@tparam T  Return value type.
@param[in] v  Value to operate on.
@param[in] pos  A position relative to the lowest bit.
@param[in] len  Range to extract.

@return Returns the extracted bit string.
    
*/
    template <typename T>
    inline T GetBits(bit32 v, int pos, int len)
    {
        return static_cast<T>( (v >> pos) & ((1u << len) - 1) );
    }
    
    /*!
:overload   bit64

@brief Gets a bit string.

Extracts the number of bits specified by <span class="argument">len</span>, starting from the bit specified by <span class="argument">pos</span> ([<span class="argument">pos</span>+<span class="argument">len</span>-1,<span class="argument">pos</span>]) from the low-order bits of <span class="argument">v</span>.
The bit position in <span class="argument">v</span> specified by <span class="argument">pos</span> is taken as the 0th bit.
    
@tparam T  Return value type.
@param[in] v  Value to operate on.
@param[in] pos  Position from which to start extracting, relative to the lowest bit.
@param[in] len  Range to extract.

@return Returns the extracted bit string.
    
*/
    template <typename T>
    inline T GetBits(bit64 v, int pos, int len)
    {
        return static_cast<T>( (v >> pos) & ((1ull << len) - 1) );
    }

    /*!
@brief Formats a bit string.

Extracts the low-order <span class="argument">width</span> bit of <span class="argument">v</span> and creates a value shifted left by the number of bits specified by <span class="argument">shift</span>.

You can basically think of it as reversing the processing of <tt>GetBits</tt>.

@tparam T  Type representing a bit array.
@param[in] v  Value to operate on.
@param[in] width  Range to extract.
@param[in] shift  A position relative to the lowest bit.

@return Returns the created bit string.
    */
    template <typename T>
    inline bit32 MakeBits(T v, int width, int shift)
    {
        return (static_cast<bit32>(v) & ((1u << width) - 1)) << shift;
    }

/*!
    @}
*/
}}


#endif  // ifndef NN_MATH_MATH_UTILITY_H_

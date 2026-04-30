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

/*! @file
@brief API declarations for the <tt>TinyMt</tt> library.

:include nn/math.h
*/

#ifndef NN_MATH_MATH_TINY_MT_H_
#define NN_MATH_MATH_TINY_MT_H_

#include <nn/types.h>

namespace nn { namespace math {

    /* ------------------------------------------------------------------------
Class Definitions
       ------------------------------------------------------------------------ */

    //----------------------------------------------------------------------
    //! :category Pseudorandom Number Generator
    //!
    //! @brief A random number generator class that uses TinyMT.
    //!
    //! Although Tiny Mersenne Twister (TinyMT) suffers in comparison to the Mersenne Twister, it is still a random number generating algorithm that produces good pseudo-random numbers.
    //! 
    //! Compared to the 2.5 KB of internal state required for the Mersenne Twister, TinyMT only needs an internal state of 16 bytes.
    //! 
    //!
    //! The parameters for this class (<tt>mat1</tt>, <tt>mat2</tt>, <tt>tmat</tt>) are hard-coded (<tt>0x8f7011ee</tt>, <tt>0xfc78ff1f</tt>, <tt>0x3793fdff</tt>).
    //! 
    //!
    //! The random number cycle is 2^127 - 1.
    //! Normally, the random number series does not cycle.
    //!
    //----------------------------------------------------------------------
    class TinyMt
    {
    private:
        static const int   PARAMETER_N   =  4;
        static const bit32 PARAMETER_MAT1 = 0x8f7011ee;
        static const bit32 PARAMETER_MAT2 = 0xfc78ff1f;
        static const bit32 PARAMETER_TMAT = 0x3793fdff;

        static const int MIN_LOOP = 8;
        static const int NUM_SKIP = 8;

        static const bit32 BIT31_MASK = ~0u >> 1;

    public:
        //----------------------------------------------------------------------
        //! @brief Structure for saving the internal state of random number generation.
        //----------------------------------------------------------------------
        struct State
        {
            //----------------------------------------------------------------------
            //! @brief The internal state.
            //----------------------------------------------------------------------
            bit32 state[PARAMETER_N];
        };

    private:
        bit32   m_State[PARAMETER_N];

    public:

    //! @name Initialization and Termination
    //! @{

        //----------------------------------------------------------------------
        //! :overload   arg0
        //!
        //! @brief      Initialization.
        //!
        //! Performs initialization using <tt>@ref crypto::GenerateRandomBytes</tt>.
        //----------------------------------------------------------------------
        void Initialize();

        //----------------------------------------------------------------------
        //! :overload   arg1
        //!
        //! @brief Initializes with a 32-bit seed.
        //!
        //! @param[in] seed  Value used as a random number seed.
        //----------------------------------------------------------------------
        void Initialize(bit32 seed);

        //----------------------------------------------------------------------
        //! :overload   arg2
        //!
        //! @brief Initializes with a 32-bit series as a seed.
        //!
        //! @param[in] pSeed  Pointer to the 32-bit data series used as a seed.
        //! @param[in] numSeed  The number of array elements indicated by <span class="argument">pSeed</span>.
        //----------------------------------------------------------------------
        void Initialize(const bit32* pSeed, int numSeed);

        //----------------------------------------------------------------------
        //! @brief Finalizes the object.
        //----------------------------------------------------------------------
        void Finalize(){}

    //! @}

    //! @name State Saving and Restoration
    //! @{

        //----------------------------------------------------------------------
        //! @brief Saves the internal state.
        //!
        //! Saves the internal state to the specified buffer.
        //! The saved internal state can be restored by using <tt>@ref RestoreState</tt>.
        //! 
        //!
        //! By saving the values obtained with this function, you can restart random number generation at a later time.
        //! 
        //! You can also use it to reproduce the same series of random numbers.
        //!
        //! @param[in] pStateBuffer  Buffer where the internal state is saved.
        //----------------------------------------------------------------------
        void SaveState(TinyMt::State* pStateBuffer);

        //----------------------------------------------------------------------
        //! @brief Restores the internal state.
        //!
        //! Restores the internal state saved with the <tt>@ref SaveState</tt> function.
        //! By doing so, you can re-start the generation of random numbers from the saved state.
        //!
        //! This function can be used instead of the <tt>@ref Initialize</tt> function.
        //!
        //! @param[in] pStateBuffer  The number of array elements indicated by <span class="argument">pSeed</span>.
        //----------------------------------------------------------------------
        void RestoreState(const TinyMt::State* pStateBuffer);

    //! @}

    //! @name Random Number Generation
    //! @{

        //----------------------------------------------------------------------
        //! @brief Generates an unsigned 32-bit random integer.
        //!
        //! Generates a random number in the range from 0x00000000 to 0xFFFFFFFF.
        //!
        //! @return Returns an unsigned 32-bit random integer.
        //----------------------------------------------------------------------
        u32 GenerateRandomU32();

        //----------------------------------------------------------------------
        //! @brief Generates an unsigned 64-bit random integer.
        //!
        //! Generates a random number in the range from 0x00000000 00000000 to 0xFFFFFFFF FFFFFFFF.
        //!
        //! @return Returns an unsigned 64-bit random integer.
        //----------------------------------------------------------------------
        u64 GenerateRandomU64();

        //----------------------------------------------------------------------
        //! @brief Generates a single, precision floating-point random number.
        //!
        //! @return Returns a single, precision floating-point random number.
        //----------------------------------------------------------------------
        f32 GenerateRandomF32();

        //----------------------------------------------------------------------
        //! @brief Generates a double, precision floating-point random number.
        //!
        //! @return Returns a double, precision floating-point random number.
        //----------------------------------------------------------------------
        f64 GenerateRandomF64();

        //----------------------------------------------------------------------
        //! @brief Generates a random number that is less than the specified number.
        //!
        //! Generates a random number in the range of integers from 0 to less than <tt>num</tt>.
        //! The return value type is the type of <tt>num</tt>.
        //!
        //! Note that the return rate of each value is not completely equal.
        //! For example, when 6 is specified for <span class="argument">num</span>, the probability that 0, 1, 3, or 4 is returned is 0x2AAAAAAB / 0x100000000 but the probability that 2 or 5 is returned is 0x2AAAAAAA / 0x100000000; the probability that 2 or 5 appears is 0x2AAAAAAA / 0x2AAAAAAB times the probability that 0, 1, 3, or 4 appears.
        //! 
        //! 
        //! 
        //! 
        //!
        //! The bias in the probability increases with a larger <span class="argument">num</span>; when the maximum value 0xFFFF is specified for <span class="argument">num</span>, the probability that 0 appears is 65538 / 65537 times (1.0000153 times) the probability that a nonzero number appears. 
        //! 
        //! 
        //! 
        //!
        //! The bias does not occur when <span class="argument">num</span> is a power of 2.
        //!
        //! @param[in] num  Specifies the type of return value.
        //!
        //! @return Returns a random integer in the specified range.
        //----------------------------------------------------------------------
        u32 GenerateRandomN(u16 num);

        //----------------------------------------------------------------------
        //! @brief Generates a series of random bytes.
        //!
        //! Generates a series of random bytes with <span class="argument">size</span> bytes in size, and stores it in the buffer specified by <span class="argument">p</span>.
        //! 
        //!
        //! @param[in] p  Specifies a buffer storing a series of random bytes.
        //! @param[in] size  Specifies the byte size of the random byte series stored in <span class="argument">p</span>.
        //----------------------------------------------------------------------
        void GenerateRandomBytes(void* p, size_t size);

    //! @}

    private:
        u32 GenerateRandomU24()
        {
            return GenerateRandomU32() >> 8;
        }

        void FinalizeInitialization();

        static void GenerateInitialValuePlus(bit32* p, int d, bit32 k);
        static void GenerateInitialValueXor(bit32* p, int d);
    };



    /* ------------------------------------------------------------------------
Inline Member Function Definitions
       ------------------------------------------------------------------------ */

    inline u64 TinyMt::GenerateRandomU64()
    {
        const u32 lo = GenerateRandomU32();
        const u32 hi = GenerateRandomU32();
        return (static_cast<u64>(hi) << 32) | lo;
    }

    inline f32 TinyMt::GenerateRandomF32()
    {
        return GenerateRandomU24() * (1.0f / (1ull << 24));
    }

    inline f64 TinyMt::GenerateRandomF64()
    {
        static const int RESOLUTION = 53;
        static const int U32_BITS   = 32;
        static const int A_SHIFT    = (2 * U32_BITS - RESOLUTION) / 2;
        static const int B_SHIFT    = (2 * U32_BITS - RESOLUTION) - A_SHIFT;
        //static const int A_BITS     = U32_BITS - A_SHIFT;
        static const int B_BITS     = U32_BITS - B_SHIFT;

        u32 a = (GenerateRandomU32() >> A_SHIFT);
        u32 b = (GenerateRandomU32() >> B_SHIFT);

        return (1.0 * a * (1u << B_BITS) + b) * (1.0 / (1ull << RESOLUTION));
    }

    inline u32 TinyMt::GenerateRandomN(u16 max)
    {
        return static_cast<u32>((static_cast<u64>(GenerateRandomU32()) * max) >> 32);
    }



}}


/* NN_MATH_MATH_TINY_MT_H_ */
#endif

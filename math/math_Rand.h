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

#ifndef NN_MATH_MATH_RAND_H_
#define NN_MATH_MATH_RAND_H_

#include <nn/math/math_Config.h>

namespace nn { 
namespace math {
/*!
:category Pseudorandom Number Generator

@brief The class for generating 32-bit random numbers using the linear congruential method.

The random number cycle is 2^32 - 1.
When 4G random numbers are generated, the series of random numbers cycles.
*/
class RandomGenerator
{
public:
/*!
@brief Instantiates the object with default parameters (default constructor). We recommend NOT using this function normally.

If you plan to use it, be sure to run <tt>@ref SetSeed</tt> and set the pseudorandom number seed value, before generating random numbers.
 */
    RandomGenerator(){}
/*!
@brief The constructor for specifying a random number seed value. Normally use this function.

@param[in] seed  The seed value.
 */
    RandomGenerator(u64 seed){this->SetSeed(seed);}
/*!
@brief Destructor.
 */
    ~RandomGenerator(){}

/*!
@brief Resets the pseudorandom number seed value.

@param[in] seed  The seed value.
 */
    void SetSeed(u64 seed);

/*!
@brief Gets a pseudorandom number. A different random number can be obtained each time the function runs.

@param[in] max  The maximum value in the range of numbers to get. Can get numbers in the range from <tt>0</tt> through (<span class="argument">max</span> - 1). If 0 has been specified, the entire range of 32-bit values is used.
@return A 32-bit random number.
 */
    u32 Generate(u32 max=0);
private:
    u64     m_x;    // Random number value.
    u64     m_mul;  // Multiplier.
    u64     m_add;  // The number to add.
};

// This class is a private class for maintaining compatibility with CTR-SDK 3.3.
// Do not use it, because it may be removed in the future.
class RamdomGenerator
{
public:
    RamdomGenerator() NN_ATTRIBUTE_DEPRECATED {}
    RamdomGenerator(u64 seed) NN_ATTRIBUTE_DEPRECATED {this->SetSeed(seed);}

    ~RamdomGenerator(){}

    void SetSeed(u64 seed) NN_ATTRIBUTE_DEPRECATED;
    u32 Generate(u32 max=0) NN_ATTRIBUTE_DEPRECATED;
private:
    u64     m_x;    // Random number value.
    u64     m_mul;  // Multiplier.
    u64     m_add;  // The number to add.
};

}}

#endif //NN_MATH_RAND_H

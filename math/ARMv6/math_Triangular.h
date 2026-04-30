#ifndef NN_MATH_ARMV6_MATH_TRIANGULAR_H_
#define NN_MATH_ARMV6_MATH_TRIANGULAR_H_

#include <nn/math/math_Config.h>

namespace nn { 
namespace math {
namespace ARMv6 {

void SinCosIdxAsm(f32* pSin, f32* pCos, u16 idx);

}  //namespace ARMv6
}  // namespace math
}  // namespace nn


#endif

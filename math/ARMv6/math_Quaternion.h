#ifndef NN_MATH_ARMV6_MATH_QUATERNION_H_
#define NN_MATH_ARMV6_MATH_QUATERNION_H_

#include <nn/math/math_Config.h>

namespace nn { 
namespace math {
namespace ARMv6 {

NN_MATH_INLINE QUAT* QUATMultC(QUAT* pOut, const QUAT* __restrict q1, const QUAT* __restrict q2);
NN_MATH_INLINE QUAT* QUATMultC_FAST(QUAT* pOut, const QUAT* __restrict q1, const QUAT* __restrict q2);
NN_MATH_INLINE QUAT* QUATNormalizeC(QUAT* pOut, const QUAT* __restrict q);
NN_MATH_INLINE QUAT* QUATNormalizeC_FAST(QUAT* pOut, const QUAT* __restrict q);
NN_MATH_INLINE QUAT* QUATInverseC(QUAT* pOut, const QUAT* __restrict q);
NN_MATH_INLINE QUAT* QUATInverseC_FAST(QUAT* pOut, const QUAT* __restrict q);

QUAT* QUATMultAsm(QUAT* pOut, const QUAT* __restrict q1, const QUAT* __restrict q2);

}  //namespace ARMv6
}  // namespace math
}  // namespace nn


#endif

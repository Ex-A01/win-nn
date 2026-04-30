#ifndef NN_MATH_ARMV6_MATH_VECTOR3_H_
#define NN_MATH_ARMV6_MATH_VECTOR3_H_

#include <nn/math/math_Config.h>
#include <nn/math/math_Constant.h>

namespace nn { 
namespace math {
namespace ARMv6 {

NN_MATH_INLINE VEC3* VEC3NormalizeC(VEC3* pOut, const VEC3* p);
NN_MATH_INLINE VEC3* VEC3NormalizeC_FAST(VEC3* pOut, const VEC3* p);

}  // namespace ARMv6
}  // namespace math
}  // namespace nn

#endif

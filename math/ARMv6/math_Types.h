#ifndef NN_MATH_ARMV6_MATH_TYPES_H_
#define NN_MATH_ARMV6_MATH_TYPES_H_

#include <nn/types.h>
#include <nn/math/math_Config.h>
#include <nn/math/math_Triangular.h>
#include <nn/math/math_Vector2.h>
#include <nn/math/math_Vector3.h>
#include <nn/math/math_Vector4.h>
#include <nn/math/math_Quaternion.h>
#include <nn/math/math_Matrix22.h>
#include <nn/math/math_Matrix23.h>
#include <nn/math/math_Matrix33.h>
#include <nn/math/math_Matrix34.h>
#include <nn/math/math_Matrix44.h>
#include <nn/math/math_Matrix43.h>
#include <nn/math/math_Transform.h>

#include <cstring>

namespace nn { 
namespace math {
namespace ARMv6 {


NN_MATH_INLINE MTX33* MTX34ToMTX33C(MTX33* pOut, const MTX34* pM);
NN_MATH_INLINE MTX34* MTX33ToMTX34C(MTX34* pOut, const MTX33* pM);
NN_MATH_INLINE QUAT*  MTX34ToQUATC(QUAT* pOut, const MTX34* pMtx);
NN_MATH_INLINE MTX43* MTX34TransposeC(MTX43* pOut, const MTX34* p);
NN_MATH_INLINE MTX34* MTX43TransposeC(MTX34* pOut, const MTX43* p);

MTX33* MTX34ToMTX33Asm(MTX33* pOut, const MTX34* pM);
MTX33* MTX34ToMTX33Asm(MTX33* pOut, const MTX34* pM);
MTX43* MTX34TransposeAsm(MTX43* pOut, const MTX34* p);
MTX34* MTX43TransposeAsm(MTX34* pOut, const MTX43* p);

NN_MATH_INLINE MTX34* MTX33ToMTX34C_FAST(MTX34* pOut, const MTX33* pM);
NN_MATH_INLINE QUAT*  MTX34ToQUATC_FAST(QUAT* pOut, const MTX34* pMtx);

}  // namespace ARMv6
}  // namespace math
}  // namespace nn


#endif


#ifndef NN_MATH_ARMV6_MATH_MATRIX33_H_
#define NN_MATH_ARMV6_MATH_MATRIX33_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn { 
namespace math {
namespace ARMv6 {

template<typename TMatrix> inline TMatrix* 
    MTX33MultC(TMatrix* pOut, const TMatrix* __restrict p1, const TMatrix* __restrict p2);

NN_MATH_INLINE MTX33* MTX33CopyC(MTX33* pOut, const MTX33* p);
NN_MATH_INLINE MTX33* MTX33MAddC(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2);
NN_MATH_INLINE MTX33* MTX33MAddC_FAST(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2);
NN_MATH_INLINE VEC3* VEC3TransformC(VEC3* pOut, const MTX33* pM, const VEC3* pV);

MTX33* MTX33CopyAsm(MTX33* pOut, const MTX33* p);
MTX33* MTX33MAddAsm(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2);
MTX33* MTX33MAddAsm(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2);
VEC3* VEC3TransformAsm(VEC3* pOut, const MTX33* pM, const VEC3* pV);

template<typename TMatrix> inline asm TMatrix* 
    MTX33MultAsm_ORG(TMatrix* pOut, const TMatrix* p1, const TMatrix* p2);

template<typename TMatrix> inline asm TMatrix* 
    MTX33MultAsm(TMatrix* pOut, const TMatrix* p1, const TMatrix* p2);

}  // namespace ARMv6
}  // namespace math
}  // namespace nn

#pragma pop

/* NN_MATH_ARMV6_MATH_MATRIX33_H_ */
#endif

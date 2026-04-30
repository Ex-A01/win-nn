#ifndef NN_MATH_ARMV6_MATH_MATRIX43_H_
#define NN_MATH_ARMV6_MATH_MATRIX43_H_

#include <nn/math/math_Config.h>

//namespace nn { 
//namespace math {
namespace ARMv6 {

/* ------------------------------------------------------------------------
Function for MTX43
   ------------------------------------------------------------------------ */

NN_MATH_INLINE MTX43* MTX43CopyC(MTX43* pOut, const MTX43* p);
NN_MATH_INLINE MTX43* MTX43AddC(MTX43* pOut, const MTX43* p1, const MTX43* p2);
NN_MATH_INLINE MTX43* MTX43MultC(MTX43* pOut, const MTX43* p1, const MTX43* p2);
NN_MATH_INLINE MTX43* MTX43MultC(MTX43* pOut, const MTX43* p, f32 f);

MTX43* MTX43CopyAsm(MTX43* pOut, const MTX43* p);
MTX43* MTX43AddAsm(MTX43* pOut, const MTX43* p1, const MTX43* p2);
MTX43* MTX43MultAsm(MTX43* pOut, const MTX43* p1, const MTX43* p2);
MTX43* MTX43MultAsm(MTX43* pOut, const MTX43* p, f32 f);

}  // namespace ARMv6
//}  // namespace math
//}  // namespace nn


#endif

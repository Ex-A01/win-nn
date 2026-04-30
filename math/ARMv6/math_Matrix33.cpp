#include <nn/math/ARMv6/math_Matrix33.h>

namespace nn {
    namespace math {
        namespace ARMv6 {

            // On redirige les implémentations assembleur vers les fonctions C standard.

            MTX33* MTX33CopyAsm(MTX33* pOut, const MTX33* p)
            {
                return MTX33CopyC(pOut, p);
            }

            MTX33* MTX33MAddAsm(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2)
            {
                return MTX33MAddC(pOut, t, p1, p2);
            }

            VEC3* VEC3TransformAsm(VEC3* pOut, const MTX33* pM, const VEC3* pV)
            {
                return VEC3TransformC(pOut, pM, pV);
            }

        }  // namespace ARMv6
    }  // namespace math
}  // namespace nn
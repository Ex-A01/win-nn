#include <nn/math/ARMv6/math_Arithmetic.h>
namespace nn {
    namespace math {
        namespace ARMv6 {

            // Sous Windows (x86/x64), nous n'avons pas accès aux instructions assembleur ARM.
            // On implémente donc les prototypes HermiteAsm en redirigeant les appels
            // vers l'implémentation C standard (HermiteC) définie en inline dans le header.

            f32 HermiteAsm(f32 v0, f32 t0, f32 v1, f32 t1, f32 s)
            {
                // Appel de la fonction de base définie dans math_Arithmetic.h
                return HermiteC(v0, t0, v1, t1, s);
            }

            f32 HermiteAsm(f32 v0, f32 t0, f32 v1, f32 t1, f32 p, f32 d)
            {
                // Appel de la surcharge définie dans math_Arithmetic.h
                return HermiteC(v0, t0, v1, t1, p, d);
            }

        }
    }
}  // namespace nn::math::ARMv6
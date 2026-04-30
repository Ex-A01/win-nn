#include <nn/math/math_Matrix33.h>
#include <windows.h>
#include <cstdio>

namespace nn {
    namespace math {

        //------------------------------------------------------------------------
        // Implémentation de MTX33::Report pour Windows
        // Affiche le contenu de la matrice dans le débogueur (Visual Studio)
        //------------------------------------------------------------------------
        void MTX33::Report(bool bNewline, const char* name) const
        {
            char buffer[512];
            int offset = 0;

            // En-tête du dump de la matrice
            if (name != nullptr)
            {
                offset += snprintf(buffer + offset, sizeof(buffer) - offset, "[nn::math] MTX33 '%s':\n", name);
            }
            else
            {
                offset += snprintf(buffer + offset, sizeof(buffer) - offset, "[nn::math] MTX33:\n");
            }

            // Affichage des 3 lignes et 3 colonnes
            for (int i = 0; i < ROW_COUNT; ++i)
            {
                offset += snprintf(buffer + offset, sizeof(buffer) - offset,
                    "  [%9.4f, %9.4f, %9.4f]\n",
                    m[i][0], m[i][1], m[i][2]);
            }

            // Saut de ligne final optionnel
            if (bNewline)
            {
                snprintf(buffer + offset, sizeof(buffer) - offset, "\n");
            }

            // Envoi de la chaîne formatée au débogueur Windows
            OutputDebugStringA(buffer);
        }

        namespace ARMv6 {

            //------------------------------------------------------------------------
            // Fallbacks ARMv6 -> C standard (si appelés explicitement par le jeu)
            //------------------------------------------------------------------------
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
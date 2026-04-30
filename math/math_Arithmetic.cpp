#include <nn/math/math_Arithmetic.h>
#include <intrin.h> // Header intrinsèque de MSVC pour la manipulation de bits

namespace nn {
    namespace math {

        //------------------------------------------------------------------------
        // Interpolations
        //------------------------------------------------------------------------

        f32 Bezier(f32 p1, f32 p2, f32 p3, f32 p4, f32 s)
        {
            // Formule standard de la courbe de Bézier cubique : 
            // B(s) = (1-s)^3 * p1 + 3(1-s)^2 * s * p2 + 3(1-s) * s^2 * p3 + s^3 * p4
            f32 inv_s = 1.0f - s;
            f32 inv_s2 = inv_s * inv_s;
            f32 inv_s3 = inv_s2 * inv_s;
            f32 s2 = s * s;
            f32 s3 = s2 * s;

            return (inv_s3 * p1) + (3.0f * inv_s2 * s * p2) + (3.0f * inv_s * s2 * p3) + (s3 * p4);
        }

        f32 CatmullRom(f32 p0, f32 p1, f32 p2, f32 p3, f32 s)
        {
            // Formule d'interpolation spline de Catmull-Rom
            f32 s2 = s * s;
            f32 s3 = s2 * s;

            return 0.5f * (
                (2.0f * p1) +
                (-p0 + p2) * s +
                (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * s2 +
                (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * s3
                );
        }

        //------------------------------------------------------------------------
        // Fonctions entières (Bits et Maths)
        //------------------------------------------------------------------------

        // Compte le nombre de bits à 1 dans un entier (Popcount)
        u32 CntBit1(u32 x)
        {
            // Utilise l'instruction processeur très rapide disponible sous Windows
            return __popcnt(x);
        }

        // Compte le nombre de bits à 1 dans un tableau d'entiers
        u32 CntBit1(const u32* first, const u32* last)
        {
            u32 count = 0;
            for (const u32* p = first; p != last; ++p)
            {
                count += CntBit1(*p);
            }
            return count;
        }

        // Calcule la distance de Hamming (nombre de bits différents) entre deux tableaux
        u32 DistBit(const u32* first1, const u32* last1, const u32* first2)
        {
            u32 count = 0;
            const u32* p1 = first1;
            const u32* p2 = first2;

            while (p1 != last1)
            {
                count += CntBit1((*p1) ^ (*p2));
                ++p1;
                ++p2;
            }
            return count;
        }

        // Inverse l'ordre des bits d'un entier 32 bits (Bit Reversal)
        u32 RevBit(u32 x)
        {
            x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
            x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
            x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
            x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
            x = (x << 16) | (x >> 16);
            return x;
        }

        // Exponentiation entière (x puissance n)
        int IExp(int x, u32 n)
        {
            int result = 1;
            int base = x;
            while (n > 0)
            {
                if (n & 1) result *= base;
                base *= base;
                n >>= 1;
            }
            return result;
        }

        // Logarithme en base 10 entier rapide
        u32 ILog10(u32 x)
        {
            if (x >= 1000000000) return 9;
            if (x >= 100000000)  return 8;
            if (x >= 10000000)   return 7;
            if (x >= 1000000)    return 6;
            if (x >= 100000)     return 5;
            if (x >= 10000)      return 4;
            if (x >= 1000)       return 3;
            if (x >= 100)        return 2;
            if (x >= 10)         return 1;
            return 0;
        }

        //------------------------------------------------------------------------
        // Fonctions internes du SDK
        //------------------------------------------------------------------------

        namespace internal
        {
            f32 FExp(f32 x) { return ::std::expf(x); }
            f32 FLog(f32 x) { return ::std::logf(x); }

            // Compte le nombre de 0 initiaux (Count Leading Zeros) pour plateforme non-ARM
            u32 CntLz_(u32 x)
            {
                unsigned long index;
                // _BitScanReverse trouve le bit à 1 le plus à gauche.
                if (_BitScanReverse(&index, x))
                {
                    return 31 - index;
                }
                return 32; // Cas spécial : x est 0
            }
        }

    }
} // namespace nn::math
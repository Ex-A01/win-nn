#ifndef NN_MATH_MATH_TYPES_H_
#define NN_MATH_MATH_TYPES_H_

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

#include <nn/math/ARMv6/math_Types.h>

#include <cstring>

namespace nn { 
namespace math {

/* =======================================================================
Class Definitions
   ======================================================================== */
struct VEC2;
struct VEC3;
struct VEC4;
struct QUAT;
struct MTX34;
struct MTX43;

/*!
@name Utilities
    @{
*/

/* ------------------------------------------------------------------------
MatrixUtility
   ------------------------------------------------------------------------ */

/*!--------------------------------------------------------------------------*
@brief Copies a 2x3 matrix to a 2x2 matrix.

@param[out] pOut  Pointer to the matrix to copy the data to.
@param[in] pM  Pointer to the matrix to copy the data from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX22* MTX23ToMTX22(MTX22* pOut, const MTX23* pM);

/*!--------------------------------------------------------------------------*
@brief Copies a 2x2 matrix to a 2x3 matrix.

@param[out] pOut  Pointer to the matrix to copy the data to.
@param[in] pM  Pointer to the matrix to copy the data from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX22ToMTX23(MTX23* pOut, const MTX22* pM);

/*!--------------------------------------------------------------------------*
@brief Copies a 3x3 matrix to a 3x4 matrix.

@param[out] pOut  Pointer to the matrix to copy the data to.
@param[in] pM  Pointer to the matrix to copy from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX33ToMTX34(MTX34* pOut, const MTX33* pM);

/*!--------------------------------------------------------------------------*
@brief Copies a 3x4 matrix to a 3x3 matrix.

@param[out] pOut  Pointer to the matrix to copy the data to.
@param[in] pM  Pointer to the matrix to copy from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX33* MTX34ToMTX33(MTX33* pOut, const MTX34* pM);

/*!--------------------------------------------------------------------------*
@brief ---- Generates a rotation matrix from a quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pQ  Pointer to the original quaternion.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* QUATToMTX34(MTX34* pOut, const QUAT* pQ);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix from a quaternion and applies only the rotation-related elements of the specified matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pQ  Pointer to the original quaternion.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* QUATToMTX34Partially(MTX34* pOut, const QUAT* pQ);

/*!--------------------------------------------------------------------------*
@brief Creates a quaternion based on a rotation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pMtx  Pointer to the rotation matrix used as the source of the quaternion.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE QUAT* MTX34ToQUAT(QUAT* pOut, const MTX34* pMtx);

/*!
    @}
*/
/*!
@name 3x4 Matrices
    @{
*/

/*!--------------------------------------------------------------------------*
:overload tomtx43

@brief Gets the transpose of a 3x4 matrix, resulting in a 4x3 matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] p  Pointer to the original matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX43* MTX34Transpose(MTX43* pOut, const MTX34* p);

/*!
    @}
*/
/*!
@name 4x3 Matrices
    @{
*/


/*!--------------------------------------------------------------------------*
@brief Gets the transpose of a 4x3 matrix, resulting in a 3x4 matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] p  Pointer to the original matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX43Transpose(MTX34* pOut, const MTX43* p);

/*!
    @}
*/

NN_FORCE_INLINE MTX34*
MTX33ToMTX34(MTX34* pOut, const MTX33* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX33TOMTX34_CONFIG == D_ORG)
        return ARMv6::MTX33ToMTX34C(pOut, pM);
    #elif (MTX33TOMTX34_CONFIG == D_FAST_C)
        return ARMv6::MTX33ToMTX34C_FAST(pOut, pM);
    #elif (MTX33TOMTX34_CONFIG == D_FAST_ASM)
    #elif (MTX33TOMTX34_CONFIG == D_FAST_C_ALGO)
    #elif (MTX33TOMTX34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}

NN_FORCE_INLINE MTX33* 
MTX34ToMTX33(MTX33* pOut, const MTX34* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34TOMTX33_CONFIG == D_ORG)
        return ARMv6::MTX34ToMTX33C(pOut, pM);
    #elif (MTX34TOMTX33_CONFIG == D_FAST_C)
    #elif (MTX34TOMTX33_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34ToMTX33Asm(pOut, pM);
    #elif (MTX34TOMTX33_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34TOMTX33_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}

NN_FORCE_INLINE QUAT*
MTX34ToQUAT(QUAT* pOut, const MTX34* pMtx)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34TOQUAT_CONFIG == D_ORG)
        return ARMv6::MTX34ToQUATC(pOut, pMtx);
    #elif (MTX34TOQUAT_CONFIG == D_FAST_C)
        return ARMv6::MTX34ToQUATC_FAST(pOut, pMtx);
    #elif (MTX34TOQUAT_CONFIG == D_FAST_ASM)
    #elif (MTX34TOQUAT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34TOQUAT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}

NN_FORCE_INLINE MTX34*
QUATToMTX34(MTX34* pOut, const QUAT* pQ)
{
#if defined( NN_HARDWARE_CTR )
    #if (QUATTOMTX34_CONFIG == D_ORG)
        return ARMv6::QUATToMTX34C(pOut, pQ);
    #elif (QUATTOMTX34_CONFIG == D_FAST_C)
        return ARMv6::QUATToMTX34C_FAST(pOut, pQ);
    #elif (QUATTOMTX34_CONFIG == D_FAST_ASM)
    #elif (QUATTOMTX34_CONFIG == D_FAST_C_ALGO)
    #elif (QUATTOMTX34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
QUATToMTX34Partially(MTX34* pOut, const QUAT* pQ)
{
#if defined( NN_HARDWARE_CTR )
    #if (QUATTOMTX34_CONFIG == D_ORG)
        return ARMv6::QUATToMTX34C(pOut, pQ, false);
    #elif (QUATTOMTX34_CONFIG == D_FAST_C)
        return ARMv6::QUATToMTX34C_FAST(pOut, pQ, false);
    #elif (QUATTOMTX34_CONFIG == D_FAST_ASM)
    #elif (QUATTOMTX34_CONFIG == D_FAST_C_ALGO)
    #elif (QUATTOMTX34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX43*
MTX34Transpose(MTX43* pOut, const MTX34* p) 
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34TRANSPOSE_34TO43_CONFIG == D_ORG)
        return ARMv6::MTX34TransposeC(pOut, p);
    #elif (MTX34TRANSPOSE_34TO43_CONFIG == D_FAST_C)
    #elif (MTX34TRANSPOSE_34TO43_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34TransposeAsm(pOut, p);
    #elif (MTX34TRANSPOSE_34TO43_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34TRANSPOSE_34TO43_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}

NN_FORCE_INLINE MTX34*
MTX43Transpose(MTX34* pOut, const MTX43* p) 
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX43TRANSPOSE_CONFIG == D_ORG)
        return ARMv6::MTX43TransposeC(pOut, p);
    #elif (MTX43TRANSPOSE_CONFIG == D_FAST_C)
    #elif (MTX43TRANSPOSE_CONFIG == D_FAST_ASM)
        return ARMv6::MTX43TransposeAsm(pOut, p);
    #elif (MTX43TRANSPOSE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX43TRANSPOSE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif

}

}  // namespace math
}  // namespace nn


#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Types.ipp>
#include <nn/math/ARMv6/inline/math_Types.ipp>
#endif

namespace nn { 
namespace math {

//Overload referencing the -- const argument.
inline MTX22* MTX23ToMTX22(MTX22* pOut, const MTX23& m) { return MTX23ToMTX22(pOut, &m); }
inline MTX23* MTX22ToMTX23(MTX23* pOut, const MTX22& m) { return MTX22ToMTX23( pOut, &m ); }
inline MTX33* MTX34ToMTX33(MTX33* pOut, const MTX34& m) { return MTX34ToMTX33( pOut, &m ); }
inline MTX34* MTX33ToMTX34(MTX34* pOut, const MTX33& m) { return MTX33ToMTX34( pOut, &m ); }
inline QUAT*  MTX34ToQUAT(QUAT* pOut, const MTX34& mtx) { return MTX34ToQUAT( pOut, &mtx ); }
inline MTX34* QUATToMTX34(MTX34* pOut, const QUAT& q) { return QUATToMTX34( pOut, &q ); }
inline MTX34* MTX43Transpose(MTX34* pOut, const MTX43& m) { return MTX43Transpose( pOut, &m ); }
inline MTX43* MTX34Transpose(MTX43* pOut, const MTX34& m) { return MTX34Transpose( pOut, &m ); }

}  // namespace math
}  // namespace nn

#endif



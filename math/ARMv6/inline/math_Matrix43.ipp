/*---------------------------------------------------------------------------*
Project: Horizon
File: math_Matrix43.ipp

Copyright (C)2009-2010 Nintendo Co., Ltd.  All rights reserved.

These coded instructions, statements, and computer programs contain
proprietary information of Nintendo of America Inc. and/or Nintendo
Company Ltd., and are protected by Federal copyright law.  They may
not be disclosed to third parties or copied or duplicated in any form,
in whole or in part, without the prior written consent of Nintendo.

$Revision: 13623 $
 *---------------------------------------------------------------------------*/

namespace nn {
namespace math {
namespace ARMv6 {
/*!
@name Matrices
    @{
*/

/*!--------------------------------------------------------------------------*
@brief Copies a matrix.
@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix to copy from.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX43*
MTX43CopyC(MTX43* pOut, const MTX43* p) 
{ 
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p );
    
    if (pOut != p)
    {
        *pOut = *p;
    }
    
    return pOut; 
}

/*!--------------------------------------------------------------------------*
@brief Calculates the sum of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both p1 and p2.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX43* 
MTX43AddC(MTX43* pOut, const MTX43* p1, const MTX43* p2)
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );
    
    pOut->f._00 = p1->f._00 + p2->f._00;
    pOut->f._01 = p1->f._01 + p2->f._01;
    pOut->f._02 = p1->f._02 + p2->f._02;

    pOut->f._10 = p1->f._10 + p2->f._10;
    pOut->f._11 = p1->f._11 + p2->f._11;
    pOut->f._12 = p1->f._12 + p2->f._12;

    pOut->f._20 = p1->f._20 + p2->f._20;
    pOut->f._21 = p1->f._21 + p2->f._21;
    pOut->f._22 = p1->f._22 + p2->f._22;
    
    pOut->f._30 = p1->f._30 + p2->f._30;
    pOut->f._31 = p1->f._31 + p2->f._31;
    pOut->f._32 = p1->f._32 + p2->f._32;
    
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX43*
MTX43MultC(MTX43* pOut, const MTX43* __restrict p1, const MTX43* __restrict p2) 
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );
    
    MTX43 mTmp;
    
    MTX43* __restrict pDst = ( pOut == p1 || pOut == p2 ) ? &mTmp : pOut;
    
    pDst->f._00 = p1->f._00 * p2->f._00 + p1->f._01 * p2->f._10 + p1->f._02 * p2->f._20;
    pDst->f._01 = p1->f._00 * p2->f._01 + p1->f._01 * p2->f._11 + p1->f._02 * p2->f._21;
    pDst->f._02 = p1->f._00 * p2->f._02 + p1->f._01 * p2->f._12 + p1->f._02 * p2->f._22;
    
    pDst->f._10 = p1->f._10 * p2->f._00 + p1->f._11 * p2->f._10 + p1->f._12 * p2->f._20;
    pDst->f._11 = p1->f._10 * p2->f._01 + p1->f._11 * p2->f._11 + p1->f._12 * p2->f._21;
    pDst->f._12 = p1->f._10 * p2->f._02 + p1->f._11 * p2->f._12 + p1->f._12 * p2->f._22;
    
    pDst->f._20 = p1->f._20 * p2->f._00 + p1->f._21 * p2->f._10 + p1->f._22 * p2->f._20;
    pDst->f._21 = p1->f._20 * p2->f._01 + p1->f._21 * p2->f._11 + p1->f._22 * p2->f._21;
    pDst->f._22 = p1->f._20 * p2->f._02 + p1->f._21 * p2->f._12 + p1->f._22 * p2->f._22;

    pDst->f._30 = p1->f._30 * p2->f._00 + p1->f._31 * p2->f._10 + p1->f._32 * p2->f._20 + p2->f._30;
    pDst->f._31 = p1->f._30 * p2->f._01 + p1->f._31 * p2->f._11 + p1->f._32 * p2->f._21 + p2->f._31;
    pDst->f._32 = p1->f._30 * p2->f._02 + p1->f._31 * p2->f._12 + p1->f._32 * p2->f._22 + p2->f._32;
    
    if ( pDst != pOut )
    {
        MTX43Copy( pOut, pDst );
    }
    
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a scalar value.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as p.
@param[in] p  Pointer to the original matrix.
@param[in] f  Scalar value by which to multiply.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX43* 
MTX43MultC(MTX43* pOut, const MTX43* p, f32 f)
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p );
    
    pOut->f._00 = p->f._00 * f;
    pOut->f._01 = p->f._01 * f;
    pOut->f._02 = p->f._02 * f;

    pOut->f._10 = p->f._10 * f;
    pOut->f._11 = p->f._11 * f;
    pOut->f._12 = p->f._12 * f;

    pOut->f._20 = p->f._20 * f;
    pOut->f._21 = p->f._21 * f;
    pOut->f._22 = p->f._22 * f;

    pOut->f._30 = p->f._30 * f;
    pOut->f._31 = p->f._31 * f;
    pOut->f._32 = p->f._32 * f;
    
    return pOut;
}

/*!
    @}
*/
}  // namespace ARMv6
}  // namespace math
}  // namespace nn

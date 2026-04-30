/*---------------------------------------------------------------------------*
Project: Horizon
File: math_Matrix44.ipp

Copyright (C)2009-2010 Nintendo Co., Ltd.  All rights reserved.

These coded instructions, statements, and computer programs contain
proprietary information of Nintendo of America Inc. and/or Nintendo
Company Ltd., and are protected by Federal copyright law.  They may
not be disclosed to third parties or copied or duplicated in any form,
in whole or in part, without the prior written consent of Nintendo.

$Revision: 13623 $
 *---------------------------------------------------------------------------*/

#include <cmath>
#include <nn/math/math_Vector3.h>

namespace nn { 
namespace math {
namespace ARMv6 {
/*!
@name Utilities
    @{
*/

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix. The fourth element of the vector is calculated as 1.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE VEC4*
VEC3TransformC(VEC4* pOut, const MTX44* pM, const VEC3* pV)
{
    VEC4 tmp;
    tmp.x = pM->f._00 * pV->x + pM->f._01 * pV->y + pM->f._02 * pV->z + pM->f._03;
    tmp.y = pM->f._10 * pV->x + pM->f._11 * pV->y + pM->f._12 * pV->z + pM->f._13;
    tmp.z = pM->f._20 * pV->x + pM->f._21 * pV->y + pM->f._22 * pV->z + pM->f._23;
    tmp.w = pM->f._30 * pV->x + pM->f._31 * pV->y + pM->f._32 * pV->z + pM->f._33;

    pOut->x = tmp.x;
    pOut->y = tmp.y;
    pOut->z = tmp.z;
    pOut->w = tmp.w;

    return pOut;
}

/*!
    @}
*/

/* ------------------------------------------------------------------------
MTX44
   ------------------------------------------------------------------------ */

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
NN_MATH_INLINE MTX44*
MTX44CopyC(MTX44* pOut, const MTX44* p)
{
    if (pOut != p)
    {
        *pOut = *p;
    }
    
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Calculates the sum of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44AddC(MTX44* pOut, const MTX44* p1, const MTX44* p2)
{
    pOut->f._00 = p1->f._00 + p2->f._00;
    pOut->f._01 = p1->f._01 + p2->f._01;
    pOut->f._02 = p1->f._02 + p2->f._02;
    pOut->f._03 = p1->f._03 + p2->f._03;

    pOut->f._10 = p1->f._10 + p2->f._10;
    pOut->f._11 = p1->f._11 + p2->f._11;
    pOut->f._12 = p1->f._12 + p2->f._12;
    pOut->f._13 = p1->f._13 + p2->f._13;

    pOut->f._20 = p1->f._20 + p2->f._20;
    pOut->f._21 = p1->f._21 + p2->f._21;
    pOut->f._22 = p1->f._22 + p2->f._22;
    pOut->f._23 = p1->f._23 + p2->f._23;

    pOut->f._30 = p1->f._30 + p2->f._30;
    pOut->f._31 = p1->f._31 + p2->f._31;
    pOut->f._32 = p1->f._32 + p2->f._32;
    pOut->f._33 = p1->f._33 + p2->f._33;

    return pOut;
}



/*!--------------------------------------------------------------------------*
@brief Calculates a scalar product of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.
@param[in] f  Number to multiply by.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultC(MTX44* pOut, const MTX44* p, f32 f)
{
    pOut->f._00 = p->f._00 * f;
    pOut->f._01 = p->f._01 * f;
    pOut->f._02 = p->f._02 * f;
    pOut->f._03 = p->f._03 * f;

    pOut->f._10 = p->f._10 * f;
    pOut->f._11 = p->f._11 * f;
    pOut->f._12 = p->f._12 * f;
    pOut->f._13 = p->f._13 * f;

    pOut->f._20 = p->f._20 * f;
    pOut->f._21 = p->f._21 * f;
    pOut->f._22 = p->f._22 * f;
    pOut->f._23 = p->f._23 * f;

    pOut->f._30 = p->f._30 * f;
    pOut->f._31 = p->f._31 * f;
    pOut->f._32 = p->f._32 * f;
    pOut->f._33 = p->f._33 * f;

    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Creates the transpose of a matrix.
@param[in] pOut  Pointer to the buffer that receives the calculation results. It is not a problem if this points to the same matrix as <SPAN class="argument">pSrc</SPAN>.
@param[in] pSrc  Pointer to the original matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* 
MTX44TransposeC(MTX44* pOut, const MTX44 *pSrc)
{
    MTX44 tmp;
    const MTX44 *pMtx;
    
    if (pOut != pSrc)
    {
        pMtx = pSrc;
        pOut->f._00 = pSrc->f._00;
        pOut->f._11 = pSrc->f._11;
        pOut->f._22 = pSrc->f._22;
        pOut->f._33 = pSrc->f._33;
    }
    else
    {
        pMtx = &tmp;
        tmp.f._01 = pSrc->f._01;
        tmp.f._02 = pSrc->f._02;
        tmp.f._03 = pSrc->f._03;
        tmp.f._12 = pSrc->f._12;
        tmp.f._13 = pSrc->f._13;
        tmp.f._23 = pSrc->f._23;
    }
    
    pOut->f._01 = pSrc->f._10;
    pOut->f._02 = pSrc->f._20;
    pOut->f._03 = pSrc->f._30;
    pOut->f._12 = pSrc->f._21;
    pOut->f._13 = pSrc->f._31;
    pOut->f._23 = pSrc->f._32;
    
    pOut->f._10 = pMtx->f._01;
    pOut->f._20 = pMtx->f._02;
    pOut->f._30 = pMtx->f._03;
    pOut->f._21 = pMtx->f._12;
    pOut->f._31 = pMtx->f._13;
    pOut->f._32 = pMtx->f._23;
    
    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Creates a perspective matrix based on the viewing angle and aspect ratio.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] fovy  Vertical field-of-view angle (in radians).
@param[in] aspect  View aspect ratio (width:height).
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44PerspectiveRadC(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f)
{
    NN_NULL_ASSERT(pOut);

    f32 (*const m)[4] = pOut->m;

    // Find the cotangent of half the (YZ) field of view.
    
    const f32 angle = fovy * 0.5f;

    const f32 cot = 1.0f / ::std::tanf(angle);

    m[0][0] =  cot / aspect;
    m[0][1] =  0.0f;
    m[0][2] =  0.0f;
    m[0][3] =  0.0f;
              
    m[1][0] =  0.0f;
    m[1][1] =   cot;
    m[1][2] =  0.0f;
    m[1][3] =  0.0f;
              
    m[2][0] =  0.0f;
    m[2][1] =  0.0f;

    const f32 tmp = 1.0f / (f - n);
    m[2][2] = f * tmp;
    m[2][3] = f * n * tmp;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] = -1.0f;
    m[3][3] =  0.0f;
    
    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44PerspectiveRadC_FAST(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f)
{
    NN_NULL_ASSERT(pOut);

    f32 (*const m)[4] = pOut->m;

    // Find the cotangent of half the (YZ) field of view.
    
    const f32 angle = fovy * 0.5f;
#if (MTX44PERSPECTIVERAD_CONFIG == D_FAST_C_ALGO)
    f32 sin, cos;
    SinCosFIdx(&sin, &cos, NN_MATH_RAD_TO_FIDX(angle));
    const f32 cot = cos/sin;
#else
    const f32 cot = 1.0f / ::std::tanf(angle);
#endif
    const f32 tmp = 1.0f / (f - n);
    
    register f32 m00, m11, m22, m23;

    m00 =  cot / aspect;
    m11 =  cot;
    m22 = f * tmp;
    m23 = f * n * tmp;

    m[0][1] =  0.0f;
    m[0][2] =  0.0f;
    m[0][3] =  0.0f;
    m[1][0] =  0.0f;
    m[1][2] =  0.0f;
    m[1][3] =  0.0f;
    m[2][0] =  0.0f;
    m[2][1] =  0.0f;
    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] = -1.0f;
    m[3][3] =  0.0f;

    m[0][0] = m00;
    m[1][1] = m11;
    m[2][2] = m22;
    m[2][3] = m23;

    
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix based on the view frustum at the near clipping plane.
<BR><BR><B>Note:</B> The order of the arguments follows the OpenGL standard.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------</BR>
  <code ln="0320">
</code>
  <code ln="0321">NN_MATH_INLINE MTX44*
</code>
  <code ln="0322">MTX44FrustumC(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0323">{
</code>
  <code ln="0324">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0325">
</code>
  <code ln="0326">    </code>
<slashcomment ln="0326"> NOTE: Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0326">
</code>
  <code ln="0327">
</code>
  <code ln="0328">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0329">    f32 tmp     =  1.0f / (r - l);
</code>
  <code ln="0330">    m[0][0] =  (2*n) * tmp;
</code>
  <code ln="0331">    m[0][1] =  0.0f;
</code>
  <code ln="0332">    m[0][2] =  (r + l) * tmp;
</code>
  <code ln="0333">    m[0][3] =  0.0f;
</code>
  <code ln="0334">
</code>
  <code ln="0335">    tmp     =  1.0f / (t - b);
</code>
  <code ln="0336">    m[1][0] =  0.0f;
</code>
  <code ln="0337">    m[1][1] =  (2*n) * tmp;
</code>
  <code ln="0338">    m[1][2] =  (t + b) * tmp;
</code>
  <code ln="0339">    m[1][3] =  0.0f;
</code>
  <code ln="0340">
</code>
  <code ln="0341">    m[2][0] =  0.0f;
</code>
  <code ln="0342">    m[2][1] =  0.0f;
</code>
  <code ln="0343">
</code>
  <code ln="0344">    tmp = 1.0f / (f - n);
</code>
  <code ln="0345">
</code>
  <code ln="0346">    m[2][2] = f * tmp;
</code>
  <code ln="0347">    m[2][3] = f * n * tmp;
</code>
  <code ln="0348">
</code>
  <code ln="0349">    m[3][0] =  0.0f;
</code>
  <code ln="0350">    m[3][1] =  0.0f;
</code>
  <code ln="0351">    m[3][2] = -1.0f;
</code>
  <code ln="0352">    m[3][3] =  0.0f;
</code>
  <code ln="0353">    
</code>
  <code ln="0354">    return pOut;
</code>
  <code ln="0355">}
</code>
  <code ln="0356">NN_MATH_INLINE MTX44*
</code>
  <code ln="0357">MTX44FrustumC_FAST(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0358">{
</code>
  <code ln="0359">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0360">
</code>
  <code ln="0361">    </code>
<slashcomment ln="0361"> bNote:/b Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0361">
</code>
  <code ln="0362">
</code>
  <code ln="0363">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0364">    f32 tmp1 =  1.0f / (r - l);
</code>
  <code ln="0365">    f32 tmp3 =  1.0f / (f - n);
</code>
  <code ln="0366">    f32 tmp2 =  1.0f / (t - b);
</code>
  <code ln="0367">    
</code>
  <code ln="0368">    register f32 m00, m02, m11, m12, m22, m23;
</code>
  <code ln="0369">
</code>
  <code ln="0370">    m00 =  (2*n) * tmp1;
</code>
  <code ln="0371">    m02 =  (r + l) * tmp1;
</code>
  <code ln="0372">
</code>
  <code ln="0373">    m11 =  (2*n) * tmp2;
</code>
  <code ln="0374">    m12 =  (t + b) * tmp2;
</code>
  <code ln="0375">
</code>
  <code ln="0376">    m22 = f * tmp3;
</code>
  <code ln="0377">    m23 = f * n * tmp3;
</code>
  <code ln="0378">
</code>
  <code ln="0379">    m[0][1] =  0.0f;
</code>
  <code ln="0380">    m[0][3] =  0.0f;
</code>
  <code ln="0381">
</code>
  <code ln="0382">    m[1][0] =  0.0f;
</code>
  <code ln="0383">    m[1][3] =  0.0f;
</code>
  <code ln="0384">
</code>
  <code ln="0385">    m[2][0] =  0.0f;
</code>
  <code ln="0386">    m[2][1] =  0.0f;
</code>
  <code ln="0387">
</code>
  <code ln="0388">    m[3][0] =  0.0f;
</code>
  <code ln="0389">    m[3][1] =  0.0f;
</code>
  <code ln="0390">    m[3][2] = -1.0f;
</code>
  <code ln="0391">    m[3][3] =  0.0f;
</code>
  <code ln="0392">
</code>
  <code ln="0393">    m[0][0] =  m00;
</code>
  <code ln="0394">    m[0][2] =  m02;
</code>
  <code ln="0395">
</code>
  <code ln="0396">    m[1][1] =  m11;
</code>
  <code ln="0397">    m[1][2] =  m12;
</code>
  <code ln="0398">
</code>
  <code ln="0399">    m[2][2] =  m22;
</code>
  <code ln="0400">    m[2][3] =  m23;
</code>
  <code ln="0401">
</code>
  <code ln="0402">    return pOut;
</code>
  <code ln="0403">}
</code>
  <code ln="0404">
</code>
  <code ln="0405">
</code>
  <multilinecomment ln="0406" lc="14">!--------------------------------------------------------------------------*
@brief Creates an orthogonal matrix.
<BR><BR><B>Note:</B> The order of the arguments follows the OpenGL standard.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</BR>
  <code ln="0419">
</code>
  <code ln="0420">NN_MATH_INLINE MTX44*
</code>
  <code ln="0421">MTX44OrthoC(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0422">{
</code>
  <code ln="0423">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0424">
</code>
  <code ln="0425">    </code>
<slashcomment ln="0425"> bNote:/b Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0425">
</code>
  <code ln="0426">
</code>
  <code ln="0427">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0428">    f32 tmp     =  1.0f / (r - l);
</code>
  <code ln="0429">    m[0][0] =  2.0f * tmp;
</code>
  <code ln="0430">    m[0][1] =  0.0f;
</code>
  <code ln="0431">    m[0][2] =  0.0f;
</code>
  <code ln="0432">    m[0][3] = -(r + l) * tmp;
</code>
  <code ln="0433">
</code>
  <code ln="0434">    tmp     =  1.0f / (t - b);
</code>
  <code ln="0435">    m[1][0] =  0.0f;
</code>
  <code ln="0436">    m[1][1] =  2.0f * tmp;
</code>
  <code ln="0437">    m[1][2] =  0.0f;
</code>
  <code ln="0438">    m[1][3] = -(t + b) * tmp;
</code>
  <code ln="0439">
</code>
  <code ln="0440">    m[2][0] =  0.0f;
</code>
  <code ln="0441">    m[2][1] =  0.0f;
</code>
  <code ln="0442">
</code>
  <code ln="0443">    tmp     =  1.0f / (f - n);
</code>
  <code ln="0444">
</code>
  <code ln="0445">    m[2][2] = tmp;
</code>
  <code ln="0446">    m[2][3] = n * tmp;
</code>
  <code ln="0447">
</code>
  <code ln="0448">    m[3][0] =  0.0f;
</code>
  <code ln="0449">    m[3][1] =  0.0f;
</code>
  <code ln="0450">    m[3][2] =  0.0f;
</code>
  <code ln="0451">    m[3][3] =  1.0f;
</code>
  <code ln="0452">    
</code>
  <code ln="0453">    return pOut;
</code>
  <code ln="0454">}
</code>
  <code ln="0455">NN_MATH_INLINE MTX44*
</code>
  <code ln="0456">MTX44OrthoC_FAST(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0457">{
</code>
  <code ln="0458">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0459">
</code>
  <code ln="0460">    </code>
<slashcomment ln="0460"> bNote:/b Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0460">
</code>
  <code ln="0461">
</code>
  <code ln="0462">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0463">    register f32 tmp1     =  1.0f / (r - l);
</code>
  <code ln="0464">    register f32 tmp2     =  1.0f / (t - b);
</code>
  <code ln="0465">    register f32 tmp3     =  1.0f / (f - n);
</code>
  <code ln="0466">    register f32 m00, m03, m11, m13, m22, m23;
</code>
  <code ln="0467">
</code>
  <code ln="0468">    m00 =  2.0f * tmp1;
</code>
  <code ln="0469">    m03 = -(r + l) * tmp1;
</code>
  <code ln="0470">
</code>
  <code ln="0471">    m11 =  2.0f * tmp2;
</code>
  <code ln="0472">    m13 = -(t + b) * tmp2;
</code>
  <code ln="0473">
</code>
  <code ln="0474">    m22 = tmp3;
</code>
  <code ln="0475">    m23 = n * tmp3;
</code>
  <code ln="0476">
</code>
  <code ln="0477">    m[0][1] =  0.0f;
</code>
  <code ln="0478">    m[0][2] =  0.0f;
</code>
  <code ln="0479">
</code>
  <code ln="0480">    m[1][0] =  0.0f;
</code>
  <code ln="0481">    m[1][2] =  0.0f;
</code>
  <code ln="0482">
</code>
  <code ln="0483">    m[2][0] =  0.0f;
</code>
  <code ln="0484">    m[2][1] =  0.0f;
</code>
  <code ln="0485">
</code>
  <code ln="0486">    m[3][0] =  0.0f;
</code>
  <code ln="0487">    m[3][1] =  0.0f;
</code>
  <code ln="0488">    m[3][2] =  0.0f;
</code>
  <code ln="0489">    m[3][3] =  1.0f;
</code>
  <code ln="0490">
</code>
  <code ln="0491">    m[0][0] =  m00;
</code>
  <code ln="0492">    m[0][3] =  m03;
</code>
  <code ln="0493">    m[1][1] =  m11;
</code>
  <code ln="0494">    m[1][3] =  m13;
</code>
  <code ln="0495">    m[2][2] =  m22;
</code>
  <code ln="0496">    m[2][3] =  m23;
</code>
  <code ln="0497">    
</code>
  <code ln="0498">    return pOut;
</code>
  <code ln="0499">}
</code>
  <code ln="0500">
</code>
  <code ln="0501">
</code>
  <code ln="0502">    </code>
  <multilinecomment ln="0502" lc="08">---------------------------------------------------------------------------*
Description: Faces toward the direction of the screen and rotates the projection matrix.
Arguments: pOut    Pointer to the matrix to rotate.
pivot   
Returns:      
     *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0509">
</code>
  <code ln="0510">    inline MTX44*
</code>
  <code ln="0511">    MTX44PivotC( MTX44* pOut, PivotDirection pivot )
</code>
  <code ln="0512">    {
</code>
  <code ln="0513">        </code>
<slashcomment ln="0513"> TODO: The process must be optimized.</slashcomment>
  <code ln="0513">
</code>
  <code ln="0514">        
</code>
  <code ln="0515">        const f32 PIVOT_ROTATION_SIN_COS[ PIVOT_NUM ][ 2 ] = 
</code>
  <code ln="0516">        {
</code>
  <code ln="0517">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0518">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0518"> NONE</slashcomment>
  <code ln="0518">
</code>
  <code ln="0519">            { -1.0f, 0.0f }, </code>
<slashcomment ln="0519"> TO_UP</slashcomment>
  <code ln="0519">
</code>
  <code ln="0520">            { 0.0f, -1.0f }, </code>
<slashcomment ln="0520"> TO_RIGHT</slashcomment>
  <code ln="0520">
</code>
  <code ln="0521">            { 1.0f,  0.0f }, </code>
<slashcomment ln="0521"> TO_BOTTOM</slashcomment>
  <code ln="0521">
</code>
  <code ln="0522">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0522"> TO_LEFT</slashcomment>
  <code ln="0522">
</code>
  <code ln="0523">        #else
</code>
  <code ln="0524">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0524"> NONE</slashcomment>
  <code ln="0524">
</code>
  <code ln="0525">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0525"> TO_UP</slashcomment>
  <code ln="0525">
</code>
  <code ln="0526">            { -1.0f, 0.0f }, </code>
<slashcomment ln="0526"> TO_RIGHT</slashcomment>
  <code ln="0526">
</code>
  <code ln="0527">            { 0.0f, -1.0f }, </code>
<slashcomment ln="0527"> TO_BOTTOM</slashcomment>
  <code ln="0527">
</code>
  <code ln="0528">            { 1.0f,  0.0f }, </code>
<slashcomment ln="0528"> TO_LEFT</slashcomment>
  <code ln="0528">
</code>
  <code ln="0529">        #endif
</code>
  <code ln="0530">        };
</code>
  <code ln="0531">        
</code>
  <code ln="0532">        if ( pivot == PIVOT_NONE )
</code>
  <code ln="0533">        {
</code>
  <code ln="0534">            return pOut;
</code>
  <code ln="0535">        }
</code>
  <code ln="0536">        
</code>
  <code ln="0537">        f32 sin = PIVOT_ROTATION_SIN_COS[ pivot ][ 0 ];
</code>
  <code ln="0538">        f32 cos = PIVOT_ROTATION_SIN_COS[ pivot ][ 1 ];
</code>
  <code ln="0539">        
</code>
  <code ln="0540">        f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0541">        
</code>
  <code ln="0542">        if ( sin == 0.0f )
</code>
  <code ln="0543">        {
</code>
  <code ln="0544">            m[0][0] = cos * m[0][0];
</code>
  <code ln="0545">            m[0][1] = cos * m[0][1];
</code>
  <code ln="0546">            m[0][2] = cos * m[0][2];
</code>
  <code ln="0547">            m[0][3] = cos * m[0][3];
</code>
  <code ln="0548">            
</code>
  <code ln="0549">            m[1][0] = cos * m[1][0];
</code>
  <code ln="0550">            m[1][1] = cos * m[1][1];
</code>
  <code ln="0551">            m[1][2] = cos * m[1][2];
</code>
  <code ln="0552">            m[1][3] = cos * m[1][3];
</code>
  <code ln="0553">        }
</code>
  <code ln="0554">        else </code>
<slashcomment ln="0554"> if ( cos == 0.0f )</slashcomment>
  <code ln="0554">
</code>
  <code ln="0555">        {
</code>
  <code ln="0556">            f32 tmp = m[0][0];
</code>
  <code ln="0557">            m[0][0] = -sin * m[1][0];
</code>
  <code ln="0558">            m[1][0] = sin * tmp;
</code>
  <code ln="0559">            
</code>
  <code ln="0560">            tmp = m[0][1];
</code>
  <code ln="0561">            m[0][1] = -sin * m[1][1];
</code>
  <code ln="0562">            m[1][1] = sin * tmp;
</code>
  <code ln="0563">
</code>
  <code ln="0564">            tmp = m[0][2];
</code>
  <code ln="0565">            m[0][2] = -sin * m[1][2];
</code>
  <code ln="0566">            m[1][2] = sin * tmp;
</code>
  <code ln="0567">
</code>
  <code ln="0568">            tmp = m[0][3];
</code>
  <code ln="0569">            m[0][3] = -sin * m[1][3];
</code>
  <code ln="0570">            m[1][3] = sin * tmp;
</code>
  <code ln="0571">        }
</code>
  <code ln="0572">        
</code>
  <code ln="0573">        return pOut;
</code>
  <code ln="0574">
</code>
  <code ln="0575">    }
</code>
  <code ln="0576">    inline MTX44*
</code>
  <code ln="0577">    MTX44PivotC_FAST( MTX44* pOut, PivotDirection pivot )
</code>
  <code ln="0578">    {
</code>
  <code ln="0579">        f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0580">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0581">        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_LEFT ) )
</code>
  <code ln="0582">        #else
</code>
  <code ln="0583">        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_TOP ) )      
</code>
  <code ln="0584">        #endif
</code>
  <code ln="0585">        {
</code>
  <code ln="0586">            return pOut;
</code>
  <code ln="0587">        }
</code>
  <code ln="0588">
</code>
  <code ln="0589">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0590">        if ( pivot == PIVOT_UPSIDE_TO_RIGHT )
</code>
  <code ln="0591">        #else
</code>
  <code ln="0592">        if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
</code>
  <code ln="0593">        #endif
</code>
  <code ln="0594">        {
</code>
  <code ln="0595">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0596">
</code>
  <code ln="0597">            m00 = -m[0][0];
</code>
  <code ln="0598">            m01 = -m[0][1];
</code>
  <code ln="0599">            m02 = -m[0][2];
</code>
  <code ln="0600">            m03 = -m[0][3];
</code>
  <code ln="0601">
</code>
  <code ln="0602">            m10 = -m[1][0];
</code>
  <code ln="0603">            m11 = -m[1][1];
</code>
  <code ln="0604">            m12 = -m[1][2];
</code>
  <code ln="0605">            m13 = -m[1][3];
</code>
  <code ln="0606">
</code>
  <code ln="0607">            m[0][0] = m00;
</code>
  <code ln="0608">            m[0][1] = m01;
</code>
  <code ln="0609">            m[0][2] = m02;
</code>
  <code ln="0610">            m[0][3] = m03;
</code>
  <code ln="0611">            
</code>
  <code ln="0612">            m[1][0] = m10;
</code>
  <code ln="0613">            m[1][1] = m11;
</code>
  <code ln="0614">            m[1][2] = m12;
</code>
  <code ln="0615">            m[1][3] = m13;
</code>
  <code ln="0616">        }
</code>
  <code ln="0617">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0618">        else if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
</code>
  <code ln="0619">        #else
</code>
  <code ln="0620">        else if ( pivot == PIVOT_UPSIDE_TO_LEFT )
</code>
  <code ln="0621">        #endif
</code>
  <code ln="0622">        {
</code>
  <code ln="0623">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0624">
</code>
  <code ln="0625">            m10 = m[0][0];
</code>
  <code ln="0626">            m11 = m[0][1];
</code>
  <code ln="0627">            m12 = m[0][2];
</code>
  <code ln="0628">            m13 = m[0][3];
</code>
  <code ln="0629">
</code>
  <code ln="0630">            m00 = -m[1][0];
</code>
  <code ln="0631">            m01 = -m[1][1];
</code>
  <code ln="0632">            m02 = -m[1][2];
</code>
  <code ln="0633">            m03 = -m[1][3];
</code>
  <code ln="0634">
</code>
  <code ln="0635">            m[0][0] = m00;
</code>
  <code ln="0636">            m[0][1] = m01;
</code>
  <code ln="0637">            m[0][2] = m02;
</code>
  <code ln="0638">            m[0][3] = m03;
</code>
  <code ln="0639">            
</code>
  <code ln="0640">            m[1][0] = m10;
</code>
  <code ln="0641">            m[1][1] = m11;
</code>
  <code ln="0642">            m[1][2] = m12;
</code>
  <code ln="0643">            m[1][3] = m13;
</code>
  <code ln="0644">        }
</code>
  <code ln="0645">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0646">        else </code>
<slashcomment ln="0646"> if ( pivot == PIVOT_UPSIDE_TO_TOP )</slashcomment>
  <code ln="0646">
</code>
  <code ln="0647">        #else
</code>
  <code ln="0648">        else </code>
<slashcomment ln="0648"> if ( pivot == PIVOT_UPSIDE_TO_RIGHT )</slashcomment>
  <code ln="0648">
</code>
  <code ln="0649">        #endif
</code>
  <code ln="0650">        {
</code>
  <code ln="0651">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0652">
</code>
  <code ln="0653">            m10 = -m[0][0];
</code>
  <code ln="0654">            m11 = -m[0][1];
</code>
  <code ln="0655">            m12 = -m[0][2];
</code>
  <code ln="0656">            m13 = -m[0][3];
</code>
  <code ln="0657">
</code>
  <code ln="0658">            m00 = m[1][0];
</code>
  <code ln="0659">            m01 = m[1][1];
</code>
  <code ln="0660">            m02 = m[1][2];
</code>
  <code ln="0661">            m03 = m[1][3];
</code>
  <code ln="0662">
</code>
  <code ln="0663">            m[0][0] = m00;
</code>
  <code ln="0664">            m[0][1] = m01;
</code>
  <code ln="0665">            m[0][2] = m02;
</code>
  <code ln="0666">            m[0][3] = m03;
</code>
  <code ln="0667">            
</code>
  <code ln="0668">            m[1][0] = m10;
</code>
  <code ln="0669">            m[1][1] = m11;
</code>
  <code ln="0670">            m[1][2] = m12;
</code>
  <code ln="0671">            m[1][3] = m13;
</code>
  <code ln="0672">        }
</code>
  <code ln="0673">        return pOut;
</code>
  <code ln="0674">    }    
</code>
  <code ln="0675">
</code>
  <code ln="0676">
</code>
  <multilinecomment ln="0677" lc="09">!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both span class=argumentp1/span and span class=argumentp2/span.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0685">
</code>
  <code ln="0686">NN_MATH_INLINE MTX44*
</code>
  <code ln="0687">MTX44MultC(MTX44* pOut, const MTX44* __restrict p1, const MTX44* __restrict p2) 
</code>
  <code ln="0688">{
</code>
  <code ln="0689">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0690">    NN_NULL_ASSERT( p1 );
</code>
  <code ln="0691">    NN_NULL_ASSERT( p2 );
</code>
  <code ln="0692">    
</code>
  <code ln="0693">    MTX44 mTmp;
</code>
  <code ln="0694">    
</code>
  <code ln="0695">    MTX44* __restrict pDst = ( pOut == p1 || pOut == p2 ) ? &mTmp : pOut;
</code>
  <code ln="0696">    
</code>
  <code ln="0697">    pDst->f._00 = p1->f._00 * p2->f._00 + p1->f._01 * p2->f._10 + p1->f._02 * p2->f._20 + p1->f._03 * p2->f._30;
</code>
  <code ln="0698">    pDst->f._01 = p1->f._00 * p2->f._01 + p1->f._01 * p2->f._11 + p1->f._02 * p2->f._21 + p1->f._03 * p2->f._31;
</code>
  <code ln="0699">    pDst->f._02 = p1->f._00 * p2->f._02 + p1->f._01 * p2->f._12 + p1->f._02 * p2->f._22 + p1->f._03 * p2->f._32;
</code>
  <code ln="0700">    pDst->f._03 = p1->f._00 * p2->f._03 + p1->f._01 * p2->f._13 + p1->f._02 * p2->f._23 + p1->f._03 * p2->f._33;
</code>
  <code ln="0701">    
</code>
  <code ln="0702">    pDst->f._10 = p1->f._10 * p2->f._00 + p1->f._11 * p2->f._10 + p1->f._12 * p2->f._20 + p1->f._13 * p2->f._30;
</code>
  <code ln="0703">    pDst->f._11 = p1->f._10 * p2->f._01 + p1->f._11 * p2->f._11 + p1->f._12 * p2->f._21 + p1->f._13 * p2->f._31;
</code>
  <code ln="0704">    pDst->f._12 = p1->f._10 * p2->f._02 + p1->f._11 * p2->f._12 + p1->f._12 * p2->f._22 + p1->f._13 * p2->f._32;
</code>
  <code ln="0705">    pDst->f._13 = p1->f._10 * p2->f._03 + p1->f._11 * p2->f._13 + p1->f._12 * p2->f._23 + p1->f._13 * p2->f._33;
</code>
  <code ln="0706">    
</code>
  <code ln="0707">    pDst->f._20 = p1->f._20 * p2->f._00 + p1->f._21 * p2->f._10 + p1->f._22 * p2->f._20 + p1->f._23 * p2->f._30;
</code>
  <code ln="0708">    pDst->f._21 = p1->f._20 * p2->f._01 + p1->f._21 * p2->f._11 + p1->f._22 * p2->f._21 + p1->f._23 * p2->f._31;
</code>
  <code ln="0709">    pDst->f._22 = p1->f._20 * p2->f._02 + p1->f._21 * p2->f._12 + p1->f._22 * p2->f._22 + p1->f._23 * p2->f._32;
</code>
  <code ln="0710">    pDst->f._23 = p1->f._20 * p2->f._03 + p1->f._21 * p2->f._13 + p1->f._22 * p2->f._23 + p1->f._23 * p2->f._33;
</code>
  <code ln="0711">
</code>
  <code ln="0712">    pDst->f._30 = p1->f._30 * p2->f._00 + p1->f._31 * p2->f._10 + p1->f._32 * p2->f._20 + p1->f._33 * p2->f._30;
</code>
  <code ln="0713">    pDst->f._31 = p1->f._30 * p2->f._01 + p1->f._31 * p2->f._11 + p1->f._32 * p2->f._21 + p1->f._33 * p2->f._31;
</code>
  <code ln="0714">    pDst->f._32 = p1->f._30 * p2->f._02 + p1->f._31 * p2->f._12 + p1->f._32 * p2->f._22 + p1->f._33 * p2->f._32;
</code>
  <code ln="0715">    pDst->f._33 = p1->f._30 * p2->f._03 + p1->f._31 * p2->f._13 + p1->f._32 * p2->f._23 + p1->f._33 * p2->f._33;
</code>
  <code ln="0716">    
</code>
  <code ln="0717">    if ( pDst != pOut )
</code>
  <code ln="0718">    {
</code>
  <code ln="0719">        MTX44Copy( pOut, pDst );
</code>
  <code ln="0720">    }
</code>
  <code ln="0721">    
</code>
  <code ln="0722">    return pOut;
</code>
  <code ln="0723">}
</code>
  <code ln="0724">
</code>
  <code ln="0725">namespace {
</code>
  <code ln="0726">    inline void SwapF(f32 &a, f32 &b)
</code>
  <code ln="0727">    {
</code>
  <code ln="0728">        f32 tmp;
</code>
  <code ln="0729">        tmp = a;
</code>
  <code ln="0730">        a = b;
</code>
  <code ln="0731">        b = tmp;
</code>
  <code ln="0732">    }
</code>
  <code ln="0733">} </code>
<slashcomment ln="0733"> namespace (unnamed)</slashcomment>
  <code ln="0733">
</code>
  <code ln="0734">
</code>
  <code ln="0735">
</code>
  <multilinecomment ln="0736" lc="08">!--------------------------------------------------------------------------*
@brief Calculates the inverse of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentp/span.
@param[in] p  Pointer to the original matrix.
@return Returns 1 if the inverse matrix exists; otherwise, returns 0.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0743">
</code>
  <code ln="0744">NN_MATH_INLINE u32
</code>
  <code ln="0745">MTX44InverseC(MTX44* pOut, const MTX44* p)
</code>
  <code ln="0746">{
</code>
  <code ln="0747">    MTX44 mTmp;
</code>
  <code ln="0748">    f32 (*src)[4];
</code>
  <code ln="0749">    f32 (*inv)[4];
</code>
  <code ln="0750">    f32   w;
</code>
  <code ln="0751">    
</code>
  <code ln="0752">    NN_NULL_ASSERT( p );
</code>
  <code ln="0753">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0754">
</code>
  <code ln="0755">    MTX44Copy(&mTmp, p);
</code>
  <code ln="0756">    MTX44Identity(pOut);
</code>
  <code ln="0757">    
</code>
  <code ln="0758">    src = mTmp.m;
</code>
  <code ln="0759">    inv = pOut->m;
</code>
  <code ln="0760">    
</code>
  <code ln="0761">    for (int i = 0; i < 4; ++i)
</code>
  <code ln="0762">    {
</code>
  <code ln="0763">        f32 max = 0.0f;
</code>
  <code ln="0764">        s32 swp = i;
</code>
  <code ln="0765">        
</code>
  <code ln="0766">        </code>
<slashcomment ln="0766"> ---- Partial Pivoting -----</slashcomment>
  <code ln="0766">
</code>
  <code ln="0767">        for(int k = i ; k < 4 ; k++ )
</code>
  <code ln="0768">        {
</code>
  <code ln="0769">            f32 ftmp;
</code>
  <code ln="0770">            ftmp = ::std::fabs(src[k][i]);
</code>
  <code ln="0771">            if ( ftmp > max )
</code>
  <code ln="0772">            {
</code>
  <code ln="0773">                max = ftmp;
</code>
  <code ln="0774">                swp = k;
</code>
  <code ln="0775">            }
</code>
  <code ln="0776">        }
</code>
  <code ln="0777">        
</code>
  <code ln="0778">        </code>
<slashcomment ln="0778"> Check the singular matrix.</slashcomment>
  <code ln="0778">
</code>
  <code ln="0779">        </code>
<slashcomment ln="0779">(Alternatively, cant solve the inverse matrix with this algorithm.)</slashcomment>
  <code ln="0779">
</code>
  <code ln="0780">        if ( max == 0.0f )
</code>
  <code ln="0781">        {
</code>
  <code ln="0782">            return 0;
</code>
  <code ln="0783">        }
</code>
  <code ln="0784">        
</code>
  <code ln="0785">        </code>
<slashcomment ln="0785"> Swap the row.</slashcomment>
  <code ln="0785">
</code>
  <code ln="0786">        if ( swp != i )
</code>
  <code ln="0787">        {
</code>
  <code ln="0788">            for (int k = 0; k < 4; k++)
</code>
  <code ln="0789">            {
</code>
  <code ln="0790">                SwapF(src[i][k], src[swp][k]);
</code>
  <code ln="0791">                SwapF(inv[i][k], inv[swp][k]);
</code>
  <code ln="0792">            }
</code>
  <code ln="0793">        }
</code>
  <code ln="0794">        
</code>
  <code ln="0795">        </code>
<slashcomment ln="0795"> ---- Pivoting End ----</slashcomment>
  <code ln="0795">
</code>
  <code ln="0796">        
</code>
  <code ln="0797">        w = 1.0f / src[i][i];
</code>
  <code ln="0798">        for (int j = 0; j < 4; ++j)
</code>
  <code ln="0799">        {
</code>
  <code ln="0800">            src[i][j] *= w;
</code>
  <code ln="0801">            inv[i][j] *= w;
</code>
  <code ln="0802">        }
</code>
  <code ln="0803">        
</code>
  <code ln="0804">        for (int k = 0; k < 4; ++k )
</code>
  <code ln="0805">        {
</code>
  <code ln="0806">            if ( k == i )
</code>
  <code ln="0807">                continue;
</code>
  <code ln="0808">            
</code>
  <code ln="0809">            w = src[k][i];
</code>
  <code ln="0810">            for (int j = 0; j < 4; ++j)
</code>
  <code ln="0811">            {
</code>
  <code ln="0812">                src[k][j] -= src[i][j] * w;
</code>
  <code ln="0813">                inv[k][j] -= inv[i][j] * w;
</code>
  <code ln="0814">            }
</code>
  <code ln="0815">        }
</code>
  <code ln="0816">    }
</code>
  <code ln="0817">    
</code>
  <code ln="0818">    return 1;
</code>
  <code ln="0819">}
</code>
  <code ln="0820">NN_MATH_INLINE u32
</code>
  <code ln="0821">MTX44InverseC_FAST_ALGO(MTX44* pOut, const MTX44* p)
</code>
  <code ln="0822">{
</code>
  <code ln="0823">    const f32 (*src)[4];
</code>
  <code ln="0824">    f32 (*inv)[4];
</code>
  <code ln="0825">    
</code>
  <code ln="0826">    NN_NULL_ASSERT( p );
</code>
  <code ln="0827">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0828">
</code>
  <code ln="0829">    src = p->m;
</code>
  <code ln="0830">    inv = pOut->m;
</code>
  <code ln="0831">
</code>
  <code ln="0832">    f32 a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
</code>
  <code ln="0833">    f32 b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44;
</code>
  <code ln="0834">    f32 det;
</code>
  <code ln="0835">    
</code>
  <code ln="0836">    a11 = src[0][0];
</code>
  <code ln="0837">    a12 = src[0][1];
</code>
  <code ln="0838">    a13 = src[0][2];
</code>
  <code ln="0839">    a14 = src[0][3];
</code>
  <code ln="0840">
</code>
  <code ln="0841">    a21 = src[1][0];
</code>
  <code ln="0842">    a22 = src[1][1];
</code>
  <code ln="0843">    a23 = src[1][2];
</code>
  <code ln="0844">    a24 = src[1][3];
</code>
  <code ln="0845">
</code>
  <code ln="0846">    a31 = src[2][0];
</code>
  <code ln="0847">    a32 = src[2][1];
</code>
  <code ln="0848">    a33 = src[2][2];
</code>
  <code ln="0849">    a34 = src[2][3];
</code>
  <code ln="0850">
</code>
  <code ln="0851">    a41 = src[3][0];
</code>
  <code ln="0852">    a42 = src[3][1];
</code>
  <code ln="0853">    a43 = src[3][2];
</code>
  <code ln="0854">    a44 = src[3][3];
</code>
  <code ln="0855">    
</code>
  <code ln="0856">    det = a11*(a22*a33*a44 + a23*a34*a42 + a24*a32*a43)
</code>
  <code ln="0857">        + a12*(a21*a34*a43 + a23*a31*a44 + a24*a33*a41)
</code>
  <code ln="0858">        + a13*(a21*a32*a44 + a22*a34*a41 + a24*a31*a42)
</code>
  <code ln="0859">        + a14*(a21*a33*a42 + a22*a31*a43 + a23*a32*a41)
</code>
  <code ln="0860">        - a11*(a22*a34*a43 + a23*a32*a44 + a24*a33*a42)
</code>
  <code ln="0861">        - a12*(a21*a33*a44 + a23*a34*a41 + a24*a31*a43)
</code>
  <code ln="0862">        - a13*(a21*a34*a42 + a22*a31*a44 + a24*a32*a41)
</code>
  <code ln="0863">        - a14*(a21*a32*a43 + a22*a33*a41 + a23*a31*a42);
</code>
  <code ln="0864">        
</code>
  <code ln="0865">    if(det==0.0f)
</code>
  <code ln="0866">        return 0;
</code>
  <code ln="0867">
</code>
  <code ln="0868">    det = 1.0f / det;
</code>
  <code ln="0869">
</code>
  <code ln="0870">    f32 a33xa44_a34xa43, a32xa44_a34xa42, a33xa42_a32xa43,
</code>
  <code ln="0871">        a33xa41_a31xa43, a31xa44_a34xa41, a32xa41_a31xa42;
</code>
  <code ln="0872">    
</code>
  <code ln="0873">    a33xa44_a34xa43 = a33*a44 - a34*a43;
</code>
  <code ln="0874">    a32xa44_a34xa42 = a32*a44 - a34*a42;
</code>
  <code ln="0875">    a33xa42_a32xa43 = a33*a42 - a32*a43;
</code>
  <code ln="0876">    a33xa41_a31xa43 = a33*a41 - a31*a43;
</code>
  <code ln="0877">    a31xa44_a34xa41 = a31*a44 - a34*a41;
</code>
  <code ln="0878">    a32xa41_a31xa42 = a32*a41 - a31*a42;
</code>
  <code ln="0879">    
</code>
  <code ln="0880">    f32 a23xa44_a24xa43, a24xa33_a23xa34, a24xa42_a22xa44, a22xa43_a23xa42,
</code>
  <code ln="0881">        a22xa34_a24xa32, a23xa32_a22xa33, a21xa44_a24xa41, a23xa41_a21xa43,
</code>
  <code ln="0882">        a24xa31_a21xa34, a21xa33_a23xa31, a21xa42_a22xa41, a22xa31_a21xa32;
</code>
  <code ln="0883">    
</code>
  <code ln="0884">    a23xa44_a24xa43 = a23*a44 - a24*a43;
</code>
  <code ln="0885">    a24xa33_a23xa34 = a24*a33 - a23*a34;
</code>
  <code ln="0886">    a24xa42_a22xa44 = a24*a42 - a22*a44;
</code>
  <code ln="0887">    a22xa43_a23xa42 = a22*a43 - a23*a42;
</code>
  <code ln="0888">    a22xa34_a24xa32 = a22*a34 - a24*a32;
</code>
  <code ln="0889">    a23xa32_a22xa33 = a23*a32 - a22*a33;
</code>
  <code ln="0890">    a21xa44_a24xa41 = a21*a44 - a24*a41;
</code>
  <code ln="0891">    a23xa41_a21xa43 = a23*a41 - a21*a43;
</code>
  <code ln="0892">    a24xa31_a21xa34 = a24*a31 - a21*a34;
</code>
  <code ln="0893">    a21xa33_a23xa31 = a21*a33 - a23*a31;
</code>
  <code ln="0894">    a21xa42_a22xa41 = a21*a42 - a22*a41;
</code>
  <code ln="0895">    a22xa31_a21xa32 = a22*a31 - a21*a32;
</code>
  <code ln="0896">    
</code>
  <code ln="0897">    b11 =( a22*a33xa44_a34xa43) - (a23*a32xa44_a34xa42) - (a24*a33xa42_a32xa43);
</code>
  <code ln="0898">    b12 =( a13*a32xa44_a34xa42) + (a14*a33xa42_a32xa43) - (a12*a33xa44_a34xa43);
</code>
  <code ln="0899">    b13 =( a12*a23xa44_a24xa43) + (a13*a24xa42_a22xa44) + (a14*a22xa43_a23xa42);
</code>
  <code ln="0900">    b14 =( a12*a24xa33_a23xa34) + (a13*a22xa34_a24xa32) + (a14*a23xa32_a22xa33);
</code>
  <code ln="0901">    b21 =( a23*a31xa44_a34xa41) + (a24*a33xa41_a31xa43) - (a21*a33xa44_a34xa43);
</code>
  <code ln="0902">    b22 =( a11*a33xa44_a34xa43) - (a13*a31xa44_a34xa41) - (a14*a33xa41_a31xa43);
</code>
  <code ln="0903">    b23 =( a13*a21xa44_a24xa41) + (a14*a23xa41_a21xa43) - (a11*a23xa44_a24xa43);
</code>
  <code ln="0904">    b24 =( a13*a24xa31_a21xa34) + (a14*a21xa33_a23xa31) - (a11*a24xa33_a23xa34);
</code>
  <code ln="0905">    b31 =( a21*a32xa44_a34xa42) - (a22*a31xa44_a34xa41) - (a24*a32xa41_a31xa42);
</code>
  <code ln="0906">    b32 =( a12*a31xa44_a34xa41) + (a14*a32xa41_a31xa42) - (a11*a32xa44_a34xa42);
</code>
  <code ln="0907">    b33 =( a14*a21xa42_a22xa41) - (a11*a24xa42_a22xa44) - (a12*a21xa44_a24xa41);
</code>
  <code ln="0908">    b34 =( a14*a22xa31_a21xa32) - (a11*a22xa34_a24xa32) - (a12*a24xa31_a21xa34);
</code>
  <code ln="0909">    b41 =( a21*a33xa42_a32xa43) - (a22*a33xa41_a31xa43) + (a23*a32xa41_a31xa42);
</code>
  <code ln="0910">    b42 =( a12*a33xa41_a31xa43) - (a13*a32xa41_a31xa42) - (a11*a33xa42_a32xa43);
</code>
  <code ln="0911">    b43 =(-a13*a21xa42_a22xa41) - (a11*a22xa43_a23xa42) - (a12*a23xa41_a21xa43);
</code>
  <code ln="0912">    b44 =(-a13*a22xa31_a21xa32) - (a11*a23xa32_a22xa33) - (a12*a21xa33_a23xa31);
</code>
  <code ln="0913">
</code>
  <code ln="0914">    b11 = b11 * det;
</code>
  <code ln="0915">    b12 = b12 * det;
</code>
  <code ln="0916">    b13 = b13 * det;
</code>
  <code ln="0917">    b14 = b14 * det;
</code>
  <code ln="0918">    b21 = b21 * det;
</code>
  <code ln="0919">    b22 = b22 * det;
</code>
  <code ln="0920">    b23 = b23 * det;
</code>
  <code ln="0921">    b24 = b24 * det;
</code>
  <code ln="0922">    b31 = b31 * det;
</code>
  <code ln="0923">    b32 = b32 * det;
</code>
  <code ln="0924">    b33 = b33 * det;
</code>
  <code ln="0925">    b34 = b34 * det;
</code>
  <code ln="0926">    b41 = b41 * det;
</code>
  <code ln="0927">    b42 = b42 * det;
</code>
  <code ln="0928">    b43 = b43 * det;
</code>
  <code ln="0929">    b44 = b44 * det;
</code>
  <code ln="0930">
</code>
  <code ln="0931">    inv[0][0] = b11;
</code>
  <code ln="0932">    inv[0][1] = b12;
</code>
  <code ln="0933">    inv[0][2] = b13;
</code>
  <code ln="0934">    inv[0][3] = b14;
</code>
  <code ln="0935">
</code>
  <code ln="0936">    inv[1][0] = b21;
</code>
  <code ln="0937">    inv[1][1] = b22;
</code>
  <code ln="0938">    inv[1][2] = b23;
</code>
  <code ln="0939">    inv[1][3] = b24;
</code>
  <code ln="0940">
</code>
  <code ln="0941">    inv[2][0] = b31;
</code>
  <code ln="0942">    inv[2][1] = b32;
</code>
  <code ln="0943">    inv[2][2] = b33;
</code>
  <code ln="0944">    inv[2][3] = b34;
</code>
  <code ln="0945">
</code>
  <code ln="0946">    inv[3][0] = b41;
</code>
  <code ln="0947">    inv[3][1] = b42;
</code>
  <code ln="0948">    inv[3][2] = b43;
</code>
  <code ln="0949">    inv[3][3] = b44;
</code>
  <code ln="0950">
</code>
  <code ln="0951">    return 1;
</code>
  <code ln="0952">}
</code>
  <code ln="0953">
</code>
  <code ln="0954">
</code>
  <multilinecomment ln="0955" lc="09">!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0963">
</code>
  <code ln="0964">NN_MATH_INLINE MTX44*
</code>
  <code ln="0965">MTX44RotAxisRad_C( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
</code>
  <code ln="0966">{
</code>
  <code ln="0967">    VEC3 vN;
</code>
  <code ln="0968">    f32 s, c;             </code>
<slashcomment ln="0968"> sinTheta, cosTheta</slashcomment>
  <code ln="0968">
</code>
  <code ln="0969">    f32 t;                </code>
<slashcomment ln="0969"> ( 1 - cosTheta )</slashcomment>
  <code ln="0969">
</code>
  <code ln="0970">    f32 x, y, z;          </code>
<slashcomment ln="0970"> The x, y, z components of the normalized axis.</slashcomment>
  <code ln="0970">
</code>
  <code ln="0971">    f32 xSq, ySq, zSq;    </code>
<slashcomment ln="0971"> x, y, z squared</slashcomment>
  <code ln="0971">
</code>
  <code ln="0972">
</code>
  <code ln="0973">
</code>
  <code ln="0974">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0975">    NN_NULL_ASSERT( pAxis );
</code>
  <code ln="0976">
</code>
  <code ln="0977">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0978">
</code>
  <code ln="0979">    s = ::std::sinf(fRad);
</code>
  <code ln="0980">    c = ::std::cosf(fRad);
</code>
  <code ln="0981">    t = 1.0f - c;
</code>
  <code ln="0982">
</code>
  <code ln="0983">    VEC3Normalize( &vN, pAxis );
</code>
  <code ln="0984">
</code>
  <code ln="0985">    x = vN.x;
</code>
  <code ln="0986">    y = vN.y;
</code>
  <code ln="0987">    z = vN.z;
</code>
  <code ln="0988">
</code>
  <code ln="0989">    xSq = x * x;
</code>
  <code ln="0990">    ySq = y * y;
</code>
  <code ln="0991">    zSq = z * z;
</code>
  <code ln="0992">
</code>
  <code ln="0993">    m[0][0] = ( t * xSq )   + ( c );
</code>
  <code ln="0994">    m[0][1] = ( t * x * y ) - ( s * z );
</code>
  <code ln="0995">    m[0][2] = ( t * x * z ) + ( s * y );
</code>
  <code ln="0996">    m[0][3] = 0.0f;
</code>
  <code ln="0997">
</code>
  <code ln="0998">    m[1][0] = ( t * x * y ) + ( s * z );
</code>
  <code ln="0999">    m[1][1] = ( t * ySq )   + ( c );
</code>
  <code ln="1000">    m[1][2] = ( t * y * z ) - ( s * x );
</code>
  <code ln="1001">    m[1][3] = 0.0f;
</code>
  <code ln="1002">
</code>
  <code ln="1003">    m[2][0] = ( t * x * z ) - ( s * y );
</code>
  <code ln="1004">    m[2][1] = ( t * y * z ) + ( s * x );
</code>
  <code ln="1005">    m[2][2] = ( t * zSq )   + ( c );
</code>
  <code ln="1006">    m[2][3] = 0.0f;
</code>
  <code ln="1007">    
</code>
  <code ln="1008">    m[3][0] = 0.0f;
</code>
  <code ln="1009">    m[3][1] = 0.0f;
</code>
  <code ln="1010">    m[3][2] = 0.0f;
</code>
  <code ln="1011">    m[3][3] = 1.0f;
</code>
  <code ln="1012">    
</code>
  <code ln="1013">    return pOut;
</code>
  <code ln="1014">}
</code>
  <code ln="1015">NN_MATH_INLINE MTX44*
</code>
  <code ln="1016">MTX44RotAxisRad_C_FAST( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
</code>
  <code ln="1017">{
</code>
  <code ln="1018">    VEC3 vN;
</code>
  <code ln="1019">    f32 s, c;             </code>
<slashcomment ln="1019"> sinTheta, cosTheta</slashcomment>
  <code ln="1019">
</code>
  <code ln="1020">    f32 t;                </code>
<slashcomment ln="1020"> ( 1 - cosTheta )</slashcomment>
  <code ln="1020">
</code>
  <code ln="1021">    f32 x, y, z;          </code>
<slashcomment ln="1021"> The x, y, and z components of the normalized axis.</slashcomment>
  <code ln="1021">
</code>
  <code ln="1022">    f32 xSq, ySq, zSq;    </code>
<slashcomment ln="1022"> x, y, z squared</slashcomment>
  <code ln="1022">
</code>
  <code ln="1023">    f32 m00, m01, m02, m10, m11, m12, m20, m21, m22;
</code>
  <code ln="1024">
</code>
  <code ln="1025">
</code>
  <code ln="1026">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1027">    NN_NULL_ASSERT( pAxis );
</code>
  <code ln="1028">
</code>
  <code ln="1029">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1030">
</code>
  <code ln="1031">#if (MTX44ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
</code>
  <code ln="1032">    SinCosFIdx(&s, &c, NN_MATH_RAD_TO_FIDX(fRad));
</code>
  <code ln="1033">#else
</code>
  <code ln="1034">    s = ::std::sinf(fRad);
</code>
  <code ln="1035">    c = ::std::cosf(fRad);
</code>
  <code ln="1036">#endif
</code>
  <code ln="1037">    t = 1.0f - c;
</code>
  <code ln="1038">
</code>
  <code ln="1039">    VEC3Normalize( &vN, pAxis );
</code>
  <code ln="1040">
</code>
  <code ln="1041">    x = vN.x;
</code>
  <code ln="1042">    y = vN.y;
</code>
  <code ln="1043">    z = vN.z;
</code>
  <code ln="1044">
</code>
  <code ln="1045">    xSq = x * x;
</code>
  <code ln="1046">    ySq = y * y;
</code>
  <code ln="1047">    zSq = z * z;
</code>
  <code ln="1048">
</code>
  <code ln="1049">    m00 = ( t * xSq )   + ( c );
</code>
  <code ln="1050">    m01 = ( t * x * y ) - ( s * z );
</code>
  <code ln="1051">    m02 = ( t * x * z ) + ( s * y );
</code>
  <code ln="1052">
</code>
  <code ln="1053">    m10 = ( t * x * y ) + ( s * z );
</code>
  <code ln="1054">    m11 = ( t * ySq )   + ( c );
</code>
  <code ln="1055">    m12 = ( t * y * z ) - ( s * x );
</code>
  <code ln="1056">
</code>
  <code ln="1057">    m20 = ( t * x * z ) - ( s * y );
</code>
  <code ln="1058">    m21 = ( t * y * z ) + ( s * x );
</code>
  <code ln="1059">    m22 = ( t * zSq )   + ( c );
</code>
  <code ln="1060">
</code>
  <code ln="1061">
</code>
  <code ln="1062">    m[0][0] = m00;
</code>
  <code ln="1063">    m[0][1] = m01;
</code>
  <code ln="1064">    m[0][2] = m02;
</code>
  <code ln="1065">    m[0][3] = 0.0f;
</code>
  <code ln="1066">
</code>
  <code ln="1067">    m[1][0] = m10;
</code>
  <code ln="1068">    m[1][1] = m11;
</code>
  <code ln="1069">    m[1][2] = m12;
</code>
  <code ln="1070">    m[1][3] = 0.0f;
</code>
  <code ln="1071">
</code>
  <code ln="1072">    m[2][0] = m20;
</code>
  <code ln="1073">    m[2][1] = m21;
</code>
  <code ln="1074">    m[2][2] = m22;
</code>
  <code ln="1075">    m[2][3] = 0.0f;
</code>
  <code ln="1076">    
</code>
  <code ln="1077">    m[3][0] = 0.0f;
</code>
  <code ln="1078">    m[3][1] = 0.0f;
</code>
  <code ln="1079">    m[3][2] = 0.0f;
</code>
  <code ln="1080">    m[3][3] = 1.0f;
</code>
  <code ln="1081">    
</code>
  <code ln="1082">    return pOut;
</code>
  <code ln="1083">}
</code>
  <code ln="1084">
</code>
  <code ln="1085">
</code>
  <multilinecomment ln="1086" lc="10">!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the X axis in units of 1/256th of a circle
@param[in] fIdxY  Angle around the Y axis in units of 1/256th of a circle
@param[in] fIdxZ  Angle around the Z axis in units of 1/256th of a circle
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1095">
</code>
  <code ln="1096">NN_MATH_INLINE MTX44*
</code>
  <code ln="1097">MTX44RotXYZFIdxC(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
</code>
  <code ln="1098">{
</code>
  <code ln="1099">    NN_FLOAT_ASSERT(fIdxX);
</code>
  <code ln="1100">    NN_FLOAT_ASSERT(fIdxY);
</code>
  <code ln="1101">    NN_FLOAT_ASSERT(fIdxZ);
</code>
  <code ln="1102">
</code>
  <code ln="1103">    f32 sinx, cosx;
</code>
  <code ln="1104">    f32 siny, cosy;
</code>
  <code ln="1105">    f32 sinz, cosz;
</code>
  <code ln="1106">    f32 f1, f2;
</code>
  <code ln="1107">
</code>
  <code ln="1108">    SinCosFIdx(&sinx, &cosx, fIdxX);
</code>
  <code ln="1109">    SinCosFIdx(&siny, &cosy, fIdxY);
</code>
  <code ln="1110">    SinCosFIdx(&sinz, &cosz, fIdxZ);
</code>
  <code ln="1111">
</code>
  <code ln="1112">    pOut->f._20 = -siny;
</code>
  <code ln="1113">    pOut->f._00 = cosz * cosy;
</code>
  <code ln="1114">    pOut->f._10 = sinz * cosy;
</code>
  <code ln="1115">    pOut->f._21 = cosy * sinx;
</code>
  <code ln="1116">    pOut->f._22 = cosy * cosx;
</code>
  <code ln="1117">
</code>
  <code ln="1118">    f1 = cosx * sinz;
</code>
  <code ln="1119">    f2 = sinx * cosz;
</code>
  <code ln="1120">
</code>
  <code ln="1121">    pOut->f._01 = f2 * siny - f1;
</code>
  <code ln="1122">    pOut->f._12 = f1 * siny - f2;
</code>
  <code ln="1123">
</code>
  <code ln="1124">    f1 = sinx * sinz;
</code>
  <code ln="1125">    f2 = cosx * cosz;
</code>
  <code ln="1126">    pOut->f._02 = f2 * siny + f1;
</code>
  <code ln="1127">    pOut->f._11 = f1 * siny + f2;
</code>
  <code ln="1128">
</code>
  <code ln="1129">    pOut->f._03 = 0.f;
</code>
  <code ln="1130">    pOut->f._13 = 0.f;
</code>
  <code ln="1131">    pOut->f._23 = 0.f;
</code>
  <code ln="1132">    
</code>
  <code ln="1133">    pOut->f._30 = 0.0f;
</code>
  <code ln="1134">    pOut->f._31 = 0.0f;
</code>
  <code ln="1135">    pOut->f._32 = 0.0f;
</code>
  <code ln="1136">    pOut->f._33 = 1.0f;
</code>
  <code ln="1137">    
</code>
  <code ln="1138">    return pOut;
</code>
  <code ln="1139">}
</code>
  <code ln="1140">NN_MATH_INLINE MTX44*
</code>
  <code ln="1141">MTX44RotXYZFIdxC_FAST(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
</code>
  <code ln="1142">{
</code>
  <code ln="1143">    NN_FLOAT_ASSERT(fIdxX);
</code>
  <code ln="1144">    NN_FLOAT_ASSERT(fIdxY);
</code>
  <code ln="1145">    NN_FLOAT_ASSERT(fIdxZ);
</code>
  <code ln="1146">
</code>
  <code ln="1147">    f32 sinx, cosx;
</code>
  <code ln="1148">    f32 siny, cosy;
</code>
  <code ln="1149">    f32 sinz, cosz;
</code>
  <code ln="1150">    f32 f1, f2, f3, f4;
</code>
  <code ln="1151">    f32 f00, f10, f21, f22;
</code>
  <code ln="1152">    f32 f01, f11, f02, f12;
</code>
  <code ln="1153">
</code>
  <code ln="1154">
</code>
  <code ln="1155">
</code>
  <code ln="1156">    {
</code>
  <code ln="1157">
</code>
  <code ln="1158">        u16 idxx;
</code>
  <code ln="1159">        f32 abs_fidxx;
</code>
  <code ln="1160">        f32 rx;
</code>
  <code ln="1161">     
</code>
  <code ln="1162">        u16 idxy;
</code>
  <code ln="1163">        f32 abs_fidxy;
</code>
  <code ln="1164">        f32 ry;
</code>
  <code ln="1165">
</code>
  <code ln="1166">        u16 idxz;
</code>
  <code ln="1167">        f32 abs_fidxz;
</code>
  <code ln="1168">        f32 rz;
</code>
  <code ln="1169">
</code>
  <code ln="1170">        int negx, negy, negz;
</code>
  <code ln="1171">
</code>
  <code ln="1172">        negx = (fIdxX < 0.0f) ? 1 : 0;
</code>
  <code ln="1173">        abs_fidxx = FAbs(fIdxX);
</code>
  <code ln="1174">        negy = (fIdxY < 0.0f) ? 1 : 0;
</code>
  <code ln="1175">        abs_fidxy = FAbs(fIdxY);
</code>
  <code ln="1176">        negz = (fIdxZ < 0.0f) ? 1 : 0;
</code>
  <code ln="1177">        abs_fidxz = FAbs(fIdxZ);
</code>
  <code ln="1178">
</code>
  <code ln="1179">
</code>
  <code ln="1180">        while ( abs_fidxx >= 65536.0f )
</code>
  <code ln="1181">        {
</code>
  <code ln="1182">            abs_fidxx -= 65536.0f;
</code>
  <code ln="1183">        }
</code>
  <code ln="1184">        while ( abs_fidxy >= 65536.0f )
</code>
  <code ln="1185">        {
</code>
  <code ln="1186">            abs_fidxy -= 65536.0f;
</code>
  <code ln="1187">        }
</code>
  <code ln="1188">        while ( abs_fidxz >= 65536.0f )
</code>
  <code ln="1189">        {
</code>
  <code ln="1190">            abs_fidxz -= 65536.0f;
</code>
  <code ln="1191">        }
</code>
  <code ln="1192">
</code>
  <code ln="1193">        idxx = F32ToU16(abs_fidxx);
</code>
  <code ln="1194">        idxy = F32ToU16(abs_fidxy);
</code>
  <code ln="1195">        idxz = F32ToU16(abs_fidxz);
</code>
  <code ln="1196">        {
</code>
  <code ln="1197">            f32 idxxf, idxyf, idxzf;
</code>
  <code ln="1198">            
</code>
  <code ln="1199">            idxxf = U16ToF32(idxx);
</code>
  <code ln="1200">            idxyf = U16ToF32(idxy);
</code>
  <code ln="1201">            idxzf = U16ToF32(idxz);
</code>
  <code ln="1202">            
</code>
  <code ln="1203">            rx = abs_fidxx - idxxf;
</code>
  <code ln="1204">            ry = abs_fidxy - idxyf;
</code>
  <code ln="1205">            rz = abs_fidxz - idxzf;
</code>
  <code ln="1206">            
</code>
  <code ln="1207">
</code>
  <code ln="1208">        }
</code>
  <code ln="1209">
</code>
  <code ln="1210">        idxx &= 0xff;
</code>
  <code ln="1211">        idxy &= 0xff;
</code>
  <code ln="1212">        idxz &= 0xff;
</code>
  <code ln="1213">
</code>
  <code ln="1214">        {
</code>
  <code ln="1215">            f32 sinx_val, sinx_delta, cosx_val, cosx_delta;
</code>
  <code ln="1216">            f32 siny_val, siny_delta, cosy_val, cosy_delta;
</code>
  <code ln="1217">            f32 sinz_val, sinz_delta, cosz_val, cosz_delta;
</code>
  <code ln="1218">            
</code>
  <code ln="1219">            sinx_val = internal::gSinCosTbl[idxx].sin_val;
</code>
  <code ln="1220">            cosx_val = internal::gSinCosTbl[idxx].cos_val;
</code>
  <code ln="1221">            sinx_delta = internal::gSinCosTbl[idxx].sin_delta;
</code>
  <code ln="1222">            cosx_delta = internal::gSinCosTbl[idxx].cos_delta;
</code>
  <code ln="1223">
</code>
  <code ln="1224">            sinx = sinx_val + rx * sinx_delta;
</code>
  <code ln="1225">            cosx = cosx_val + rx * cosx_delta;
</code>
  <code ln="1226">
</code>
  <code ln="1227">            siny_val = internal::gSinCosTbl[idxy].sin_val;
</code>
  <code ln="1228">            cosy_val = internal::gSinCosTbl[idxy].cos_val;
</code>
  <code ln="1229">            siny_delta = internal::gSinCosTbl[idxy].sin_delta;
</code>
  <code ln="1230">            cosy_delta = internal::gSinCosTbl[idxy].cos_delta;
</code>
  <code ln="1231">
</code>
  <code ln="1232">            siny = siny_val + ry * siny_delta;
</code>
  <code ln="1233">            cosy = cosy_val + ry * cosy_delta;
</code>
  <code ln="1234">
</code>
  <code ln="1235">            sinz_val = internal::gSinCosTbl[idxz].sin_val;
</code>
  <code ln="1236">            cosz_val = internal::gSinCosTbl[idxz].cos_val;
</code>
  <code ln="1237">            sinz_delta = internal::gSinCosTbl[idxz].sin_delta;
</code>
  <code ln="1238">            cosz_delta = internal::gSinCosTbl[idxz].cos_delta;
</code>
  <code ln="1239">
</code>
  <code ln="1240">            sinz = sinz_val + rz * sinz_delta;
</code>
  <code ln="1241">            cosz = cosz_val + rz * cosz_delta;
</code>
  <code ln="1242">
</code>
  <code ln="1243">        }
</code>
  <code ln="1244">
</code>
  <code ln="1245">        sinx = (negx) ? -sinx : sinx;
</code>
  <code ln="1246">        siny = (negy) ? -siny : siny;
</code>
  <code ln="1247">        sinz = (negz) ? -sinz : sinz;
</code>
  <code ln="1248">
</code>
  <code ln="1249">    }
</code>
  <code ln="1250">
</code>
  <code ln="1251">    f00 = cosz * cosy;
</code>
  <code ln="1252">    f10 = sinz * cosy;
</code>
  <code ln="1253">    f21 = sinx * cosy;
</code>
  <code ln="1254">    f22 = cosx * cosy;
</code>
  <code ln="1255">
</code>
  <code ln="1256">    f1 = cosx * sinz;
</code>
  <code ln="1257">    f2 = sinx * cosz;
</code>
  <code ln="1258">
</code>
  <code ln="1259">    f01 = f2 * siny - f1;
</code>
  <code ln="1260">    f12 = f1 * siny - f2;
</code>
  <code ln="1261">
</code>
  <code ln="1262">    f3 = sinx * sinz;
</code>
  <code ln="1263">    f4 = cosx * cosz;
</code>
  <code ln="1264">
</code>
  <code ln="1265">    f02 = f4 * siny + f3;
</code>
  <code ln="1266">    f11 = f3 * siny + f4;
</code>
  <code ln="1267">
</code>
  <code ln="1268">    pOut->f._00 = f00;
</code>
  <code ln="1269">    pOut->f._10 = f10;
</code>
  <code ln="1270">    pOut->f._21 = f21;
</code>
  <code ln="1271">    pOut->f._22 = f22;
</code>
  <code ln="1272">
</code>
  <code ln="1273">    pOut->f._01 = f01;
</code>
  <code ln="1274">    pOut->f._12 = f12;
</code>
  <code ln="1275">    pOut->f._02 = f02;
</code>
  <code ln="1276">    pOut->f._11 = f11;
</code>
  <code ln="1277">    pOut->f._20 = -siny;
</code>
  <code ln="1278">
</code>
  <code ln="1279">    *(unsigned int*)&pOut->f._03 = 0x00000000;
</code>
  <code ln="1280">    *(unsigned int*)&pOut->f._13 = 0x00000000;
</code>
  <code ln="1281">    *(unsigned int*)&pOut->f._23 = 0x00000000;
</code>
  <code ln="1282">
</code>
  <code ln="1283">    *(unsigned int*)&pOut->f._30 = 0x00000000;
</code>
  <code ln="1284">    *(unsigned int*)&pOut->f._31 = 0x00000000;
</code>
  <code ln="1285">    *(unsigned int*)&pOut->f._32 = 0x00000000;
</code>
  <code ln="1286">    *(unsigned int*)&pOut->f._33 = 0x3F800000;
</code>
  <code ln="1287">    
</code>
  <code ln="1288">    return pOut;
</code>
  <code ln="1289">}
</code>
  <code ln="1290">
</code>
  <multilinecomment ln="1291" lc="08">!--------------------------------------------------------------------------*
@brief Creates a matrix to use for scaling transformations.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1298">
</code>
  <code ln="1299">NN_MATH_INLINE MTX44*
</code>
  <code ln="1300">MTX44ScaleC(MTX44* pOut, const VEC3* pS)
</code>
  <code ln="1301">{
</code>
  <code ln="1302">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1303">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1304">
</code>
  <code ln="1305">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1306">
</code>
  <code ln="1307">    m[0][0] = pS->x;    m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = 0.0f;
</code>
  <code ln="1308">    m[1][0] = 0.0f;     m[1][1] = pS->y; m[1][2] = 0.0f;  m[1][3] = 0.0f;
</code>
  <code ln="1309">    m[2][0] = 0.0f;     m[2][1] = 0.0f;  m[2][2] = pS->z; m[2][3] = 0.0f;
</code>
  <code ln="1310">    m[3][0] = 0.0f;     m[3][1] = 0.0f;  m[3][2] = 0.0f; m[3][3] = 1.0f;
</code>
  <code ln="1311">
</code>
  <code ln="1312">    return pOut;
</code>
  <code ln="1313">}
</code>
  <code ln="1314">NN_MATH_INLINE MTX44*
</code>
  <code ln="1315">MTX44ScaleC_FAST(MTX44* pOut, const VEC3* pS)
</code>
  <code ln="1316">{
</code>
  <code ln="1317">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1318">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1319">
</code>
  <code ln="1320">    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);
</code>
  <code ln="1321">
</code>
  <code ln="1322">    f32 f1 = 1.0f;
</code>
  <code ln="1323">    f32 f0 = 0.0f;
</code>
  <code ln="1324">    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
</code>
  <code ln="1325">    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
</code>
  <code ln="1326">    const unsigned int *p = reinterpret_cast<const unsigned int*>(pS);
</code>
  <code ln="1327">
</code>
  <code ln="1328">    m[ 0] =  p[0];  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = f32_0;
</code>
  <code ln="1329">    m[ 4] = f32_0;  m[ 5] =  p[1];  m[ 6] = f32_0;  m[ 7] = f32_0;
</code>
  <code ln="1330">    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] =  p[2];  m[11] = f32_0;
</code>
  <code ln="1331">    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;
</code>
  <code ln="1332">
</code>
  <code ln="1333">    return pOut;
</code>
  <code ln="1334">}
</code>
  <code ln="1335">
</code>
  <code ln="1336">
</code>
  <multilinecomment ln="1337" lc="09">!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1345">
</code>
  <code ln="1346">NN_MATH_INLINE MTX44*
</code>
  <code ln="1347">MTX44MultScaleC(MTX44* pOut, const MTX44* pM, const VEC3* pS)
</code>
  <code ln="1348">{
</code>
  <code ln="1349">    </code>
<slashcomment ln="1349"> Version where the scale matrix is applied from the right.</slashcomment>
  <code ln="1349">
</code>
  <code ln="1350">    pOut->f._00 = pM->f._00 * pS->x;
</code>
  <code ln="1351">    pOut->f._10 = pM->f._10 * pS->x;
</code>
  <code ln="1352">    pOut->f._20 = pM->f._20 * pS->x;
</code>
  <code ln="1353">
</code>
  <code ln="1354">    pOut->f._01 = pM->f._01 * pS->y;
</code>
  <code ln="1355">    pOut->f._11 = pM->f._11 * pS->y;
</code>
  <code ln="1356">    pOut->f._21 = pM->f._21 * pS->y;
</code>
  <code ln="1357">
</code>
  <code ln="1358">    pOut->f._02 = pM->f._02 * pS->z;
</code>
  <code ln="1359">    pOut->f._12 = pM->f._12 * pS->z;
</code>
  <code ln="1360">    pOut->f._22 = pM->f._22 * pS->z;
</code>
  <code ln="1361">
</code>
  <code ln="1362">    if (pOut != pM)
</code>
  <code ln="1363">    {
</code>
  <code ln="1364">        pOut->f._03 = pM->f._03;
</code>
  <code ln="1365">        pOut->f._13 = pM->f._13;
</code>
  <code ln="1366">        pOut->f._23 = pM->f._23;
</code>
  <code ln="1367">    }
</code>
  <code ln="1368">
</code>
  <code ln="1369">    return pOut;
</code>
  <code ln="1370">}
</code>
  <code ln="1371">
</code>
  <code ln="1372">
</code>
  <multilinecomment ln="1373" lc="09">!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1381">
</code>
  <code ln="1382">NN_MATH_INLINE MTX44*
</code>
  <code ln="1383">MTX44MultScaleC(MTX44* pOut, const VEC3* pS, const MTX44* pM)
</code>
  <code ln="1384">{
</code>
  <code ln="1385">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1386">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1387">    NN_NULL_ASSERT( pM  );
</code>
  <code ln="1388">
</code>
  <code ln="1389">    const f32 (*const src)[4] = pM->m;
</code>
  <code ln="1390">    f32 (*const dst)[4] = pOut->m;
</code>
  <code ln="1391">
</code>
  <code ln="1392">    dst[0][0] = src[0][0] * pS->x;     dst[0][1] = src[0][1] * pS->x;
</code>
  <code ln="1393">    dst[0][2] = src[0][2] * pS->x;     dst[0][3] = src[0][3] * pS->x;
</code>
  <code ln="1394">
</code>
  <code ln="1395">    dst[1][0] = src[1][0] * pS->y;     dst[1][1] = src[1][1] * pS->y;
</code>
  <code ln="1396">    dst[1][2] = src[1][2] * pS->y;     dst[1][3] = src[1][3] * pS->y;
</code>
  <code ln="1397">
</code>
  <code ln="1398">    dst[2][0] = src[2][0] * pS->z;     dst[2][1] = src[2][1] * pS->z;
</code>
  <code ln="1399">    dst[2][2] = src[2][2] * pS->z;     dst[2][3] = src[2][3] * pS->z;
</code>
  <code ln="1400">    
</code>
  <code ln="1401">    return pOut;
</code>
  <code ln="1402">}
</code>
  <code ln="1403">
</code>
  <code ln="1404">
</code>
  <multilinecomment ln="1405" lc="08">!--------------------------------------------------------------------------*
@brief Creates a translation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1412">
</code>
  <code ln="1413">NN_MATH_INLINE MTX44*
</code>
  <code ln="1414">MTX44TranslateC(MTX44* pOut, const VEC3* pT)
</code>
  <code ln="1415">{
</code>
  <code ln="1416">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1417">    NN_NULL_ASSERT( pT );
</code>
  <code ln="1418">
</code>
  <code ln="1419">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1420">
</code>
  <code ln="1421">    m[0][0] = 1.0f;  m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = pT->x;
</code>
  <code ln="1422">    m[1][0] = 0.0f;  m[1][1] = 1.0f;  m[1][2] = 0.0f;  m[1][3] = pT->y;
</code>
  <code ln="1423">    m[2][0] = 0.0f;  m[2][1] = 0.0f;  m[2][2] = 1.0f;  m[2][3] = pT->z;
</code>
  <code ln="1424">    m[3][0] = 0.0f;  m[3][1] = 0.0f;  m[3][2] = 0.0f;  m[3][3] = 1.0f;
</code>
  <code ln="1425">
</code>
  <code ln="1426">    return pOut;
</code>
  <code ln="1427">}
</code>
  <code ln="1428">NN_MATH_INLINE MTX44*
</code>
  <code ln="1429">MTX44TranslateC_FAST(MTX44* pOut, const VEC3* pT)
</code>
  <code ln="1430">{
</code>
  <code ln="1431">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1432">    NN_NULL_ASSERT( pT );
</code>
  <code ln="1433">
</code>
  <code ln="1434">    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);
</code>
  <code ln="1435">
</code>
  <code ln="1436">    f32 f1 = 1.0f;
</code>
  <code ln="1437">    f32 f0 = 0.0f;
</code>
  <code ln="1438">    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
</code>
  <code ln="1439">    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
</code>
  <code ln="1440">    const unsigned int *p = reinterpret_cast<const unsigned int*>(pT);
</code>
  <code ln="1441">
</code>
  <code ln="1442">    m[ 0] = f32_1;  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = p[0];
</code>
  <code ln="1443">    m[ 4] = f32_0;  m[ 5] = f32_1;  m[ 6] = f32_0;  m[ 7] = p[1];
</code>
  <code ln="1444">    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] = f32_1;  m[11] = p[2];
</code>
  <code ln="1445">    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;
</code>
  <code ln="1446">
</code>
  <code ln="1447">    return pOut;
</code>
  <code ln="1448">}
</code>
  <code ln="1449">
</code>
  <code ln="1450">
</code>
  <multilinecomment ln="1451" lc="09">!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiplies the translation matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1459">
</code>
  <code ln="1460">NN_MATH_INLINE MTX44*
</code>
  <code ln="1461">MTX44MultTranslateC(MTX44* pOut, const VEC3* pT, const MTX44* pM)
</code>
  <code ln="1462">{
</code>
  <code ln="1463">    NN_NULL_ASSERT(pOut);
</code>
  <code ln="1464">    NN_NULL_ASSERT(pT);
</code>
  <code ln="1465">    NN_NULL_ASSERT(pM);
</code>
  <code ln="1466">
</code>
  <code ln="1467">    const f32 (*const src)[4] = pM->m;
</code>
  <code ln="1468">    f32 (*const dst)[4] = pOut->m;
</code>
  <code ln="1469">
</code>
  <code ln="1470">    if ( src != dst )
</code>
  <code ln="1471">    {
</code>
  <code ln="1472">        (void)MTX44Copy(pOut, pM);
</code>
  <code ln="1473">    }
</code>
  <code ln="1474">
</code>
  <code ln="1475">    dst[0][3] = src[0][3] + pT->x;
</code>
  <code ln="1476">    dst[1][3] = src[1][3] + pT->y;
</code>
  <code ln="1477">    dst[2][3] = src[2][3] + pT->z;
</code>
  <code ln="1478">
</code>
  <code ln="1479">    return pOut;
</code>
  <code ln="1480">}
</code>
  <code ln="1481">
</code>
  <multilinecomment ln="1482" lc="09">!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiply the translation matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1490">
</code>
  <code ln="1491">NN_MATH_INLINE MTX44*
</code>
  <code ln="1492">MTX44MultTranslateC(MTX44* pOut, const MTX44* pM, const VEC3* pT)
</code>
  <code ln="1493">{
</code>
  <code ln="1494">    NN_NULL_ASSERT(pOut);
</code>
  <code ln="1495">    NN_NULL_ASSERT(pT);
</code>
  <code ln="1496">    NN_NULL_ASSERT(pM);
</code>
  <code ln="1497">
</code>
  <code ln="1498">    </code>
<slashcomment ln="1498"> pOut = pM * pT</slashcomment>
  <code ln="1498">
</code>
  <code ln="1499">    if (pOut != pM)
</code>
  <code ln="1500">    {
</code>
  <code ln="1501">        (void)MTX44Copy(pOut, pM);
</code>
  <code ln="1502">    }
</code>
  <code ln="1503">
</code>
  <code ln="1504">    VEC4 tmp;
</code>
  <code ln="1505">    VEC3Transform(&tmp, pM, pT);
</code>
  <code ln="1506">
</code>
  <code ln="1507">    pOut->f._03 = tmp.x;
</code>
  <code ln="1508">    pOut->f._13 = tmp.y;
</code>
  <code ln="1509">    pOut->f._23 = tmp.z;
</code>
  <code ln="1510">
</code>
  <code ln="1511">    return pOut;
</code>
  <code ln="1512">}
</code>
  <code ln="1513">
</code>
  <multilinecomment ln="1514" lc="03">!
    @}
</multilinecomment>
  <code ln="1516">
</code>
  <code ln="1517">
</code>
  <code ln="1518">}  </code>
<slashcomment ln="1518"> namespace ARMv6</slashcomment>
  <code ln="1518">
</code>
  <code ln="1519">}  </code>
<slashcomment ln="1519"> namespace math</slashcomment>
  <code ln="1519">
</code>
  <code ln="1520">}  </code>
<slashcomment ln="1520"> namespace nn</slashcomment>
  <code ln="1520">
</code>
</BR>
</multilinecomment></BR>*/
NN_MATH_INLINE MTX44*
MTX44FrustumC(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
    NN_NULL_ASSERT( pOut );

    // NOTE: Be careful about l vs. 1 below!!!

    f32 (*const m)[4] = pOut->m;
    f32 tmp     =  1.0f / (r - l);
    m[0][0] =  (2*n) * tmp;
    m[0][1] =  0.0f;
    m[0][2] =  (r + l) * tmp;
    m[0][3] =  0.0f;

    tmp     =  1.0f / (t - b);
    m[1][0] =  0.0f;
    m[1][1] =  (2*n) * tmp;
    m[1][2] =  (t + b) * tmp;
    m[1][3] =  0.0f;

    m[2][0] =  0.0f;
    m[2][1] =  0.0f;

    tmp = 1.0f / (f - n);

    m[2][2] = f * tmp;
    m[2][3] = f * n * tmp;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] = -1.0f;
    m[3][3] =  0.0f;
    
    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44FrustumC_FAST(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
    NN_NULL_ASSERT( pOut );

    // bNote:/b Be careful about l vs. 1 below!!!

    f32 (*const m)[4] = pOut->m;
    f32 tmp1 =  1.0f / (r - l);
    f32 tmp3 =  1.0f / (f - n);
    f32 tmp2 =  1.0f / (t - b);
    
    register f32 m00, m02, m11, m12, m22, m23;

    m00 =  (2*n) * tmp1;
    m02 =  (r + l) * tmp1;

    m11 =  (2*n) * tmp2;
    m12 =  (t + b) * tmp2;

    m22 = f * tmp3;
    m23 = f * n * tmp3;

    m[0][1] =  0.0f;
    m[0][3] =  0.0f;

    m[1][0] =  0.0f;
    m[1][3] =  0.0f;

    m[2][0] =  0.0f;
    m[2][1] =  0.0f;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] = -1.0f;
    m[3][3] =  0.0f;

    m[0][0] =  m00;
    m[0][2] =  m02;

    m[1][1] =  m11;
    m[1][2] =  m12;

    m[2][2] =  m22;
    m[2][3] =  m23;

    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Creates an orthogonal matrix.
<BR><BR><B>Note:</B> The order of the arguments follows the OpenGL standard.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</BR>
  <code ln="0419">
</code>
  <code ln="0420">NN_MATH_INLINE MTX44*
</code>
  <code ln="0421">MTX44OrthoC(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0422">{
</code>
  <code ln="0423">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0424">
</code>
  <code ln="0425">    </code>
<slashcomment ln="0425"> bNote:/b Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0425">
</code>
  <code ln="0426">
</code>
  <code ln="0427">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0428">    f32 tmp     =  1.0f / (r - l);
</code>
  <code ln="0429">    m[0][0] =  2.0f * tmp;
</code>
  <code ln="0430">    m[0][1] =  0.0f;
</code>
  <code ln="0431">    m[0][2] =  0.0f;
</code>
  <code ln="0432">    m[0][3] = -(r + l) * tmp;
</code>
  <code ln="0433">
</code>
  <code ln="0434">    tmp     =  1.0f / (t - b);
</code>
  <code ln="0435">    m[1][0] =  0.0f;
</code>
  <code ln="0436">    m[1][1] =  2.0f * tmp;
</code>
  <code ln="0437">    m[1][2] =  0.0f;
</code>
  <code ln="0438">    m[1][3] = -(t + b) * tmp;
</code>
  <code ln="0439">
</code>
  <code ln="0440">    m[2][0] =  0.0f;
</code>
  <code ln="0441">    m[2][1] =  0.0f;
</code>
  <code ln="0442">
</code>
  <code ln="0443">    tmp     =  1.0f / (f - n);
</code>
  <code ln="0444">
</code>
  <code ln="0445">    m[2][2] = tmp;
</code>
  <code ln="0446">    m[2][3] = n * tmp;
</code>
  <code ln="0447">
</code>
  <code ln="0448">    m[3][0] =  0.0f;
</code>
  <code ln="0449">    m[3][1] =  0.0f;
</code>
  <code ln="0450">    m[3][2] =  0.0f;
</code>
  <code ln="0451">    m[3][3] =  1.0f;
</code>
  <code ln="0452">    
</code>
  <code ln="0453">    return pOut;
</code>
  <code ln="0454">}
</code>
  <code ln="0455">NN_MATH_INLINE MTX44*
</code>
  <code ln="0456">MTX44OrthoC_FAST(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
</code>
  <code ln="0457">{
</code>
  <code ln="0458">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0459">
</code>
  <code ln="0460">    </code>
<slashcomment ln="0460"> bNote:/b Be careful about l vs. 1 below!!!</slashcomment>
  <code ln="0460">
</code>
  <code ln="0461">
</code>
  <code ln="0462">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0463">    register f32 tmp1     =  1.0f / (r - l);
</code>
  <code ln="0464">    register f32 tmp2     =  1.0f / (t - b);
</code>
  <code ln="0465">    register f32 tmp3     =  1.0f / (f - n);
</code>
  <code ln="0466">    register f32 m00, m03, m11, m13, m22, m23;
</code>
  <code ln="0467">
</code>
  <code ln="0468">    m00 =  2.0f * tmp1;
</code>
  <code ln="0469">    m03 = -(r + l) * tmp1;
</code>
  <code ln="0470">
</code>
  <code ln="0471">    m11 =  2.0f * tmp2;
</code>
  <code ln="0472">    m13 = -(t + b) * tmp2;
</code>
  <code ln="0473">
</code>
  <code ln="0474">    m22 = tmp3;
</code>
  <code ln="0475">    m23 = n * tmp3;
</code>
  <code ln="0476">
</code>
  <code ln="0477">    m[0][1] =  0.0f;
</code>
  <code ln="0478">    m[0][2] =  0.0f;
</code>
  <code ln="0479">
</code>
  <code ln="0480">    m[1][0] =  0.0f;
</code>
  <code ln="0481">    m[1][2] =  0.0f;
</code>
  <code ln="0482">
</code>
  <code ln="0483">    m[2][0] =  0.0f;
</code>
  <code ln="0484">    m[2][1] =  0.0f;
</code>
  <code ln="0485">
</code>
  <code ln="0486">    m[3][0] =  0.0f;
</code>
  <code ln="0487">    m[3][1] =  0.0f;
</code>
  <code ln="0488">    m[3][2] =  0.0f;
</code>
  <code ln="0489">    m[3][3] =  1.0f;
</code>
  <code ln="0490">
</code>
  <code ln="0491">    m[0][0] =  m00;
</code>
  <code ln="0492">    m[0][3] =  m03;
</code>
  <code ln="0493">    m[1][1] =  m11;
</code>
  <code ln="0494">    m[1][3] =  m13;
</code>
  <code ln="0495">    m[2][2] =  m22;
</code>
  <code ln="0496">    m[2][3] =  m23;
</code>
  <code ln="0497">    
</code>
  <code ln="0498">    return pOut;
</code>
  <code ln="0499">}
</code>
  <code ln="0500">
</code>
  <code ln="0501">
</code>
  <code ln="0502">    </code>
  <multilinecomment ln="0502" lc="08">---------------------------------------------------------------------------*
Description: Faces toward the direction of the screen and rotates the projection matrix.
Arguments: pOut    Pointer to the matrix to rotate.
pivot   
Returns:      
     *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0509">
</code>
  <code ln="0510">    inline MTX44*
</code>
  <code ln="0511">    MTX44PivotC( MTX44* pOut, PivotDirection pivot )
</code>
  <code ln="0512">    {
</code>
  <code ln="0513">        </code>
<slashcomment ln="0513"> TODO: The process must be optimized.</slashcomment>
  <code ln="0513">
</code>
  <code ln="0514">        
</code>
  <code ln="0515">        const f32 PIVOT_ROTATION_SIN_COS[ PIVOT_NUM ][ 2 ] = 
</code>
  <code ln="0516">        {
</code>
  <code ln="0517">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0518">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0518"> NONE</slashcomment>
  <code ln="0518">
</code>
  <code ln="0519">            { -1.0f, 0.0f }, </code>
<slashcomment ln="0519"> TO_UP</slashcomment>
  <code ln="0519">
</code>
  <code ln="0520">            { 0.0f, -1.0f }, </code>
<slashcomment ln="0520"> TO_RIGHT</slashcomment>
  <code ln="0520">
</code>
  <code ln="0521">            { 1.0f,  0.0f }, </code>
<slashcomment ln="0521"> TO_BOTTOM</slashcomment>
  <code ln="0521">
</code>
  <code ln="0522">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0522"> TO_LEFT</slashcomment>
  <code ln="0522">
</code>
  <code ln="0523">        #else
</code>
  <code ln="0524">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0524"> NONE</slashcomment>
  <code ln="0524">
</code>
  <code ln="0525">            { 0.0f,  1.0f }, </code>
<slashcomment ln="0525"> TO_UP</slashcomment>
  <code ln="0525">
</code>
  <code ln="0526">            { -1.0f, 0.0f }, </code>
<slashcomment ln="0526"> TO_RIGHT</slashcomment>
  <code ln="0526">
</code>
  <code ln="0527">            { 0.0f, -1.0f }, </code>
<slashcomment ln="0527"> TO_BOTTOM</slashcomment>
  <code ln="0527">
</code>
  <code ln="0528">            { 1.0f,  0.0f }, </code>
<slashcomment ln="0528"> TO_LEFT</slashcomment>
  <code ln="0528">
</code>
  <code ln="0529">        #endif
</code>
  <code ln="0530">        };
</code>
  <code ln="0531">        
</code>
  <code ln="0532">        if ( pivot == PIVOT_NONE )
</code>
  <code ln="0533">        {
</code>
  <code ln="0534">            return pOut;
</code>
  <code ln="0535">        }
</code>
  <code ln="0536">        
</code>
  <code ln="0537">        f32 sin = PIVOT_ROTATION_SIN_COS[ pivot ][ 0 ];
</code>
  <code ln="0538">        f32 cos = PIVOT_ROTATION_SIN_COS[ pivot ][ 1 ];
</code>
  <code ln="0539">        
</code>
  <code ln="0540">        f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0541">        
</code>
  <code ln="0542">        if ( sin == 0.0f )
</code>
  <code ln="0543">        {
</code>
  <code ln="0544">            m[0][0] = cos * m[0][0];
</code>
  <code ln="0545">            m[0][1] = cos * m[0][1];
</code>
  <code ln="0546">            m[0][2] = cos * m[0][2];
</code>
  <code ln="0547">            m[0][3] = cos * m[0][3];
</code>
  <code ln="0548">            
</code>
  <code ln="0549">            m[1][0] = cos * m[1][0];
</code>
  <code ln="0550">            m[1][1] = cos * m[1][1];
</code>
  <code ln="0551">            m[1][2] = cos * m[1][2];
</code>
  <code ln="0552">            m[1][3] = cos * m[1][3];
</code>
  <code ln="0553">        }
</code>
  <code ln="0554">        else </code>
<slashcomment ln="0554"> if ( cos == 0.0f )</slashcomment>
  <code ln="0554">
</code>
  <code ln="0555">        {
</code>
  <code ln="0556">            f32 tmp = m[0][0];
</code>
  <code ln="0557">            m[0][0] = -sin * m[1][0];
</code>
  <code ln="0558">            m[1][0] = sin * tmp;
</code>
  <code ln="0559">            
</code>
  <code ln="0560">            tmp = m[0][1];
</code>
  <code ln="0561">            m[0][1] = -sin * m[1][1];
</code>
  <code ln="0562">            m[1][1] = sin * tmp;
</code>
  <code ln="0563">
</code>
  <code ln="0564">            tmp = m[0][2];
</code>
  <code ln="0565">            m[0][2] = -sin * m[1][2];
</code>
  <code ln="0566">            m[1][2] = sin * tmp;
</code>
  <code ln="0567">
</code>
  <code ln="0568">            tmp = m[0][3];
</code>
  <code ln="0569">            m[0][3] = -sin * m[1][3];
</code>
  <code ln="0570">            m[1][3] = sin * tmp;
</code>
  <code ln="0571">        }
</code>
  <code ln="0572">        
</code>
  <code ln="0573">        return pOut;
</code>
  <code ln="0574">
</code>
  <code ln="0575">    }
</code>
  <code ln="0576">    inline MTX44*
</code>
  <code ln="0577">    MTX44PivotC_FAST( MTX44* pOut, PivotDirection pivot )
</code>
  <code ln="0578">    {
</code>
  <code ln="0579">        f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0580">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0581">        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_LEFT ) )
</code>
  <code ln="0582">        #else
</code>
  <code ln="0583">        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_TOP ) )      
</code>
  <code ln="0584">        #endif
</code>
  <code ln="0585">        {
</code>
  <code ln="0586">            return pOut;
</code>
  <code ln="0587">        }
</code>
  <code ln="0588">
</code>
  <code ln="0589">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0590">        if ( pivot == PIVOT_UPSIDE_TO_RIGHT )
</code>
  <code ln="0591">        #else
</code>
  <code ln="0592">        if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
</code>
  <code ln="0593">        #endif
</code>
  <code ln="0594">        {
</code>
  <code ln="0595">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0596">
</code>
  <code ln="0597">            m00 = -m[0][0];
</code>
  <code ln="0598">            m01 = -m[0][1];
</code>
  <code ln="0599">            m02 = -m[0][2];
</code>
  <code ln="0600">            m03 = -m[0][3];
</code>
  <code ln="0601">
</code>
  <code ln="0602">            m10 = -m[1][0];
</code>
  <code ln="0603">            m11 = -m[1][1];
</code>
  <code ln="0604">            m12 = -m[1][2];
</code>
  <code ln="0605">            m13 = -m[1][3];
</code>
  <code ln="0606">
</code>
  <code ln="0607">            m[0][0] = m00;
</code>
  <code ln="0608">            m[0][1] = m01;
</code>
  <code ln="0609">            m[0][2] = m02;
</code>
  <code ln="0610">            m[0][3] = m03;
</code>
  <code ln="0611">            
</code>
  <code ln="0612">            m[1][0] = m10;
</code>
  <code ln="0613">            m[1][1] = m11;
</code>
  <code ln="0614">            m[1][2] = m12;
</code>
  <code ln="0615">            m[1][3] = m13;
</code>
  <code ln="0616">        }
</code>
  <code ln="0617">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0618">        else if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
</code>
  <code ln="0619">        #else
</code>
  <code ln="0620">        else if ( pivot == PIVOT_UPSIDE_TO_LEFT )
</code>
  <code ln="0621">        #endif
</code>
  <code ln="0622">        {
</code>
  <code ln="0623">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0624">
</code>
  <code ln="0625">            m10 = m[0][0];
</code>
  <code ln="0626">            m11 = m[0][1];
</code>
  <code ln="0627">            m12 = m[0][2];
</code>
  <code ln="0628">            m13 = m[0][3];
</code>
  <code ln="0629">
</code>
  <code ln="0630">            m00 = -m[1][0];
</code>
  <code ln="0631">            m01 = -m[1][1];
</code>
  <code ln="0632">            m02 = -m[1][2];
</code>
  <code ln="0633">            m03 = -m[1][3];
</code>
  <code ln="0634">
</code>
  <code ln="0635">            m[0][0] = m00;
</code>
  <code ln="0636">            m[0][1] = m01;
</code>
  <code ln="0637">            m[0][2] = m02;
</code>
  <code ln="0638">            m[0][3] = m03;
</code>
  <code ln="0639">            
</code>
  <code ln="0640">            m[1][0] = m10;
</code>
  <code ln="0641">            m[1][1] = m11;
</code>
  <code ln="0642">            m[1][2] = m12;
</code>
  <code ln="0643">            m[1][3] = m13;
</code>
  <code ln="0644">        }
</code>
  <code ln="0645">        #ifdef NN_PLATFORM_CTR
</code>
  <code ln="0646">        else </code>
<slashcomment ln="0646"> if ( pivot == PIVOT_UPSIDE_TO_TOP )</slashcomment>
  <code ln="0646">
</code>
  <code ln="0647">        #else
</code>
  <code ln="0648">        else </code>
<slashcomment ln="0648"> if ( pivot == PIVOT_UPSIDE_TO_RIGHT )</slashcomment>
  <code ln="0648">
</code>
  <code ln="0649">        #endif
</code>
  <code ln="0650">        {
</code>
  <code ln="0651">            register f32 m00, m01, m02, m03, m10, m11, m12, m13;
</code>
  <code ln="0652">
</code>
  <code ln="0653">            m10 = -m[0][0];
</code>
  <code ln="0654">            m11 = -m[0][1];
</code>
  <code ln="0655">            m12 = -m[0][2];
</code>
  <code ln="0656">            m13 = -m[0][3];
</code>
  <code ln="0657">
</code>
  <code ln="0658">            m00 = m[1][0];
</code>
  <code ln="0659">            m01 = m[1][1];
</code>
  <code ln="0660">            m02 = m[1][2];
</code>
  <code ln="0661">            m03 = m[1][3];
</code>
  <code ln="0662">
</code>
  <code ln="0663">            m[0][0] = m00;
</code>
  <code ln="0664">            m[0][1] = m01;
</code>
  <code ln="0665">            m[0][2] = m02;
</code>
  <code ln="0666">            m[0][3] = m03;
</code>
  <code ln="0667">            
</code>
  <code ln="0668">            m[1][0] = m10;
</code>
  <code ln="0669">            m[1][1] = m11;
</code>
  <code ln="0670">            m[1][2] = m12;
</code>
  <code ln="0671">            m[1][3] = m13;
</code>
  <code ln="0672">        }
</code>
  <code ln="0673">        return pOut;
</code>
  <code ln="0674">    }    
</code>
  <code ln="0675">
</code>
  <code ln="0676">
</code>
  <multilinecomment ln="0677" lc="09">!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both span class=argumentp1/span and span class=argumentp2/span.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0685">
</code>
  <code ln="0686">NN_MATH_INLINE MTX44*
</code>
  <code ln="0687">MTX44MultC(MTX44* pOut, const MTX44* __restrict p1, const MTX44* __restrict p2) 
</code>
  <code ln="0688">{
</code>
  <code ln="0689">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0690">    NN_NULL_ASSERT( p1 );
</code>
  <code ln="0691">    NN_NULL_ASSERT( p2 );
</code>
  <code ln="0692">    
</code>
  <code ln="0693">    MTX44 mTmp;
</code>
  <code ln="0694">    
</code>
  <code ln="0695">    MTX44* __restrict pDst = ( pOut == p1 || pOut == p2 ) ? &mTmp : pOut;
</code>
  <code ln="0696">    
</code>
  <code ln="0697">    pDst->f._00 = p1->f._00 * p2->f._00 + p1->f._01 * p2->f._10 + p1->f._02 * p2->f._20 + p1->f._03 * p2->f._30;
</code>
  <code ln="0698">    pDst->f._01 = p1->f._00 * p2->f._01 + p1->f._01 * p2->f._11 + p1->f._02 * p2->f._21 + p1->f._03 * p2->f._31;
</code>
  <code ln="0699">    pDst->f._02 = p1->f._00 * p2->f._02 + p1->f._01 * p2->f._12 + p1->f._02 * p2->f._22 + p1->f._03 * p2->f._32;
</code>
  <code ln="0700">    pDst->f._03 = p1->f._00 * p2->f._03 + p1->f._01 * p2->f._13 + p1->f._02 * p2->f._23 + p1->f._03 * p2->f._33;
</code>
  <code ln="0701">    
</code>
  <code ln="0702">    pDst->f._10 = p1->f._10 * p2->f._00 + p1->f._11 * p2->f._10 + p1->f._12 * p2->f._20 + p1->f._13 * p2->f._30;
</code>
  <code ln="0703">    pDst->f._11 = p1->f._10 * p2->f._01 + p1->f._11 * p2->f._11 + p1->f._12 * p2->f._21 + p1->f._13 * p2->f._31;
</code>
  <code ln="0704">    pDst->f._12 = p1->f._10 * p2->f._02 + p1->f._11 * p2->f._12 + p1->f._12 * p2->f._22 + p1->f._13 * p2->f._32;
</code>
  <code ln="0705">    pDst->f._13 = p1->f._10 * p2->f._03 + p1->f._11 * p2->f._13 + p1->f._12 * p2->f._23 + p1->f._13 * p2->f._33;
</code>
  <code ln="0706">    
</code>
  <code ln="0707">    pDst->f._20 = p1->f._20 * p2->f._00 + p1->f._21 * p2->f._10 + p1->f._22 * p2->f._20 + p1->f._23 * p2->f._30;
</code>
  <code ln="0708">    pDst->f._21 = p1->f._20 * p2->f._01 + p1->f._21 * p2->f._11 + p1->f._22 * p2->f._21 + p1->f._23 * p2->f._31;
</code>
  <code ln="0709">    pDst->f._22 = p1->f._20 * p2->f._02 + p1->f._21 * p2->f._12 + p1->f._22 * p2->f._22 + p1->f._23 * p2->f._32;
</code>
  <code ln="0710">    pDst->f._23 = p1->f._20 * p2->f._03 + p1->f._21 * p2->f._13 + p1->f._22 * p2->f._23 + p1->f._23 * p2->f._33;
</code>
  <code ln="0711">
</code>
  <code ln="0712">    pDst->f._30 = p1->f._30 * p2->f._00 + p1->f._31 * p2->f._10 + p1->f._32 * p2->f._20 + p1->f._33 * p2->f._30;
</code>
  <code ln="0713">    pDst->f._31 = p1->f._30 * p2->f._01 + p1->f._31 * p2->f._11 + p1->f._32 * p2->f._21 + p1->f._33 * p2->f._31;
</code>
  <code ln="0714">    pDst->f._32 = p1->f._30 * p2->f._02 + p1->f._31 * p2->f._12 + p1->f._32 * p2->f._22 + p1->f._33 * p2->f._32;
</code>
  <code ln="0715">    pDst->f._33 = p1->f._30 * p2->f._03 + p1->f._31 * p2->f._13 + p1->f._32 * p2->f._23 + p1->f._33 * p2->f._33;
</code>
  <code ln="0716">    
</code>
  <code ln="0717">    if ( pDst != pOut )
</code>
  <code ln="0718">    {
</code>
  <code ln="0719">        MTX44Copy( pOut, pDst );
</code>
  <code ln="0720">    }
</code>
  <code ln="0721">    
</code>
  <code ln="0722">    return pOut;
</code>
  <code ln="0723">}
</code>
  <code ln="0724">
</code>
  <code ln="0725">namespace {
</code>
  <code ln="0726">    inline void SwapF(f32 &a, f32 &b)
</code>
  <code ln="0727">    {
</code>
  <code ln="0728">        f32 tmp;
</code>
  <code ln="0729">        tmp = a;
</code>
  <code ln="0730">        a = b;
</code>
  <code ln="0731">        b = tmp;
</code>
  <code ln="0732">    }
</code>
  <code ln="0733">} </code>
<slashcomment ln="0733"> namespace (unnamed)</slashcomment>
  <code ln="0733">
</code>
  <code ln="0734">
</code>
  <code ln="0735">
</code>
  <multilinecomment ln="0736" lc="08">!--------------------------------------------------------------------------*
@brief Calculates the inverse of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentp/span.
@param[in] p  Pointer to the original matrix.
@return Returns 1 if the inverse matrix exists; otherwise, returns 0.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0743">
</code>
  <code ln="0744">NN_MATH_INLINE u32
</code>
  <code ln="0745">MTX44InverseC(MTX44* pOut, const MTX44* p)
</code>
  <code ln="0746">{
</code>
  <code ln="0747">    MTX44 mTmp;
</code>
  <code ln="0748">    f32 (*src)[4];
</code>
  <code ln="0749">    f32 (*inv)[4];
</code>
  <code ln="0750">    f32   w;
</code>
  <code ln="0751">    
</code>
  <code ln="0752">    NN_NULL_ASSERT( p );
</code>
  <code ln="0753">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0754">
</code>
  <code ln="0755">    MTX44Copy(&mTmp, p);
</code>
  <code ln="0756">    MTX44Identity(pOut);
</code>
  <code ln="0757">    
</code>
  <code ln="0758">    src = mTmp.m;
</code>
  <code ln="0759">    inv = pOut->m;
</code>
  <code ln="0760">    
</code>
  <code ln="0761">    for (int i = 0; i < 4; ++i)
</code>
  <code ln="0762">    {
</code>
  <code ln="0763">        f32 max = 0.0f;
</code>
  <code ln="0764">        s32 swp = i;
</code>
  <code ln="0765">        
</code>
  <code ln="0766">        </code>
<slashcomment ln="0766"> ---- Partial Pivoting -----</slashcomment>
  <code ln="0766">
</code>
  <code ln="0767">        for(int k = i ; k < 4 ; k++ )
</code>
  <code ln="0768">        {
</code>
  <code ln="0769">            f32 ftmp;
</code>
  <code ln="0770">            ftmp = ::std::fabs(src[k][i]);
</code>
  <code ln="0771">            if ( ftmp > max )
</code>
  <code ln="0772">            {
</code>
  <code ln="0773">                max = ftmp;
</code>
  <code ln="0774">                swp = k;
</code>
  <code ln="0775">            }
</code>
  <code ln="0776">        }
</code>
  <code ln="0777">        
</code>
  <code ln="0778">        </code>
<slashcomment ln="0778"> Check the singular matrix.</slashcomment>
  <code ln="0778">
</code>
  <code ln="0779">        </code>
<slashcomment ln="0779">(Alternatively, cant solve the inverse matrix with this algorithm.)</slashcomment>
  <code ln="0779">
</code>
  <code ln="0780">        if ( max == 0.0f )
</code>
  <code ln="0781">        {
</code>
  <code ln="0782">            return 0;
</code>
  <code ln="0783">        }
</code>
  <code ln="0784">        
</code>
  <code ln="0785">        </code>
<slashcomment ln="0785"> Swap the row.</slashcomment>
  <code ln="0785">
</code>
  <code ln="0786">        if ( swp != i )
</code>
  <code ln="0787">        {
</code>
  <code ln="0788">            for (int k = 0; k < 4; k++)
</code>
  <code ln="0789">            {
</code>
  <code ln="0790">                SwapF(src[i][k], src[swp][k]);
</code>
  <code ln="0791">                SwapF(inv[i][k], inv[swp][k]);
</code>
  <code ln="0792">            }
</code>
  <code ln="0793">        }
</code>
  <code ln="0794">        
</code>
  <code ln="0795">        </code>
<slashcomment ln="0795"> ---- Pivoting End ----</slashcomment>
  <code ln="0795">
</code>
  <code ln="0796">        
</code>
  <code ln="0797">        w = 1.0f / src[i][i];
</code>
  <code ln="0798">        for (int j = 0; j < 4; ++j)
</code>
  <code ln="0799">        {
</code>
  <code ln="0800">            src[i][j] *= w;
</code>
  <code ln="0801">            inv[i][j] *= w;
</code>
  <code ln="0802">        }
</code>
  <code ln="0803">        
</code>
  <code ln="0804">        for (int k = 0; k < 4; ++k )
</code>
  <code ln="0805">        {
</code>
  <code ln="0806">            if ( k == i )
</code>
  <code ln="0807">                continue;
</code>
  <code ln="0808">            
</code>
  <code ln="0809">            w = src[k][i];
</code>
  <code ln="0810">            for (int j = 0; j < 4; ++j)
</code>
  <code ln="0811">            {
</code>
  <code ln="0812">                src[k][j] -= src[i][j] * w;
</code>
  <code ln="0813">                inv[k][j] -= inv[i][j] * w;
</code>
  <code ln="0814">            }
</code>
  <code ln="0815">        }
</code>
  <code ln="0816">    }
</code>
  <code ln="0817">    
</code>
  <code ln="0818">    return 1;
</code>
  <code ln="0819">}
</code>
  <code ln="0820">NN_MATH_INLINE u32
</code>
  <code ln="0821">MTX44InverseC_FAST_ALGO(MTX44* pOut, const MTX44* p)
</code>
  <code ln="0822">{
</code>
  <code ln="0823">    const f32 (*src)[4];
</code>
  <code ln="0824">    f32 (*inv)[4];
</code>
  <code ln="0825">    
</code>
  <code ln="0826">    NN_NULL_ASSERT( p );
</code>
  <code ln="0827">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0828">
</code>
  <code ln="0829">    src = p->m;
</code>
  <code ln="0830">    inv = pOut->m;
</code>
  <code ln="0831">
</code>
  <code ln="0832">    f32 a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
</code>
  <code ln="0833">    f32 b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44;
</code>
  <code ln="0834">    f32 det;
</code>
  <code ln="0835">    
</code>
  <code ln="0836">    a11 = src[0][0];
</code>
  <code ln="0837">    a12 = src[0][1];
</code>
  <code ln="0838">    a13 = src[0][2];
</code>
  <code ln="0839">    a14 = src[0][3];
</code>
  <code ln="0840">
</code>
  <code ln="0841">    a21 = src[1][0];
</code>
  <code ln="0842">    a22 = src[1][1];
</code>
  <code ln="0843">    a23 = src[1][2];
</code>
  <code ln="0844">    a24 = src[1][3];
</code>
  <code ln="0845">
</code>
  <code ln="0846">    a31 = src[2][0];
</code>
  <code ln="0847">    a32 = src[2][1];
</code>
  <code ln="0848">    a33 = src[2][2];
</code>
  <code ln="0849">    a34 = src[2][3];
</code>
  <code ln="0850">
</code>
  <code ln="0851">    a41 = src[3][0];
</code>
  <code ln="0852">    a42 = src[3][1];
</code>
  <code ln="0853">    a43 = src[3][2];
</code>
  <code ln="0854">    a44 = src[3][3];
</code>
  <code ln="0855">    
</code>
  <code ln="0856">    det = a11*(a22*a33*a44 + a23*a34*a42 + a24*a32*a43)
</code>
  <code ln="0857">        + a12*(a21*a34*a43 + a23*a31*a44 + a24*a33*a41)
</code>
  <code ln="0858">        + a13*(a21*a32*a44 + a22*a34*a41 + a24*a31*a42)
</code>
  <code ln="0859">        + a14*(a21*a33*a42 + a22*a31*a43 + a23*a32*a41)
</code>
  <code ln="0860">        - a11*(a22*a34*a43 + a23*a32*a44 + a24*a33*a42)
</code>
  <code ln="0861">        - a12*(a21*a33*a44 + a23*a34*a41 + a24*a31*a43)
</code>
  <code ln="0862">        - a13*(a21*a34*a42 + a22*a31*a44 + a24*a32*a41)
</code>
  <code ln="0863">        - a14*(a21*a32*a43 + a22*a33*a41 + a23*a31*a42);
</code>
  <code ln="0864">        
</code>
  <code ln="0865">    if(det==0.0f)
</code>
  <code ln="0866">        return 0;
</code>
  <code ln="0867">
</code>
  <code ln="0868">    det = 1.0f / det;
</code>
  <code ln="0869">
</code>
  <code ln="0870">    f32 a33xa44_a34xa43, a32xa44_a34xa42, a33xa42_a32xa43,
</code>
  <code ln="0871">        a33xa41_a31xa43, a31xa44_a34xa41, a32xa41_a31xa42;
</code>
  <code ln="0872">    
</code>
  <code ln="0873">    a33xa44_a34xa43 = a33*a44 - a34*a43;
</code>
  <code ln="0874">    a32xa44_a34xa42 = a32*a44 - a34*a42;
</code>
  <code ln="0875">    a33xa42_a32xa43 = a33*a42 - a32*a43;
</code>
  <code ln="0876">    a33xa41_a31xa43 = a33*a41 - a31*a43;
</code>
  <code ln="0877">    a31xa44_a34xa41 = a31*a44 - a34*a41;
</code>
  <code ln="0878">    a32xa41_a31xa42 = a32*a41 - a31*a42;
</code>
  <code ln="0879">    
</code>
  <code ln="0880">    f32 a23xa44_a24xa43, a24xa33_a23xa34, a24xa42_a22xa44, a22xa43_a23xa42,
</code>
  <code ln="0881">        a22xa34_a24xa32, a23xa32_a22xa33, a21xa44_a24xa41, a23xa41_a21xa43,
</code>
  <code ln="0882">        a24xa31_a21xa34, a21xa33_a23xa31, a21xa42_a22xa41, a22xa31_a21xa32;
</code>
  <code ln="0883">    
</code>
  <code ln="0884">    a23xa44_a24xa43 = a23*a44 - a24*a43;
</code>
  <code ln="0885">    a24xa33_a23xa34 = a24*a33 - a23*a34;
</code>
  <code ln="0886">    a24xa42_a22xa44 = a24*a42 - a22*a44;
</code>
  <code ln="0887">    a22xa43_a23xa42 = a22*a43 - a23*a42;
</code>
  <code ln="0888">    a22xa34_a24xa32 = a22*a34 - a24*a32;
</code>
  <code ln="0889">    a23xa32_a22xa33 = a23*a32 - a22*a33;
</code>
  <code ln="0890">    a21xa44_a24xa41 = a21*a44 - a24*a41;
</code>
  <code ln="0891">    a23xa41_a21xa43 = a23*a41 - a21*a43;
</code>
  <code ln="0892">    a24xa31_a21xa34 = a24*a31 - a21*a34;
</code>
  <code ln="0893">    a21xa33_a23xa31 = a21*a33 - a23*a31;
</code>
  <code ln="0894">    a21xa42_a22xa41 = a21*a42 - a22*a41;
</code>
  <code ln="0895">    a22xa31_a21xa32 = a22*a31 - a21*a32;
</code>
  <code ln="0896">    
</code>
  <code ln="0897">    b11 =( a22*a33xa44_a34xa43) - (a23*a32xa44_a34xa42) - (a24*a33xa42_a32xa43);
</code>
  <code ln="0898">    b12 =( a13*a32xa44_a34xa42) + (a14*a33xa42_a32xa43) - (a12*a33xa44_a34xa43);
</code>
  <code ln="0899">    b13 =( a12*a23xa44_a24xa43) + (a13*a24xa42_a22xa44) + (a14*a22xa43_a23xa42);
</code>
  <code ln="0900">    b14 =( a12*a24xa33_a23xa34) + (a13*a22xa34_a24xa32) + (a14*a23xa32_a22xa33);
</code>
  <code ln="0901">    b21 =( a23*a31xa44_a34xa41) + (a24*a33xa41_a31xa43) - (a21*a33xa44_a34xa43);
</code>
  <code ln="0902">    b22 =( a11*a33xa44_a34xa43) - (a13*a31xa44_a34xa41) - (a14*a33xa41_a31xa43);
</code>
  <code ln="0903">    b23 =( a13*a21xa44_a24xa41) + (a14*a23xa41_a21xa43) - (a11*a23xa44_a24xa43);
</code>
  <code ln="0904">    b24 =( a13*a24xa31_a21xa34) + (a14*a21xa33_a23xa31) - (a11*a24xa33_a23xa34);
</code>
  <code ln="0905">    b31 =( a21*a32xa44_a34xa42) - (a22*a31xa44_a34xa41) - (a24*a32xa41_a31xa42);
</code>
  <code ln="0906">    b32 =( a12*a31xa44_a34xa41) + (a14*a32xa41_a31xa42) - (a11*a32xa44_a34xa42);
</code>
  <code ln="0907">    b33 =( a14*a21xa42_a22xa41) - (a11*a24xa42_a22xa44) - (a12*a21xa44_a24xa41);
</code>
  <code ln="0908">    b34 =( a14*a22xa31_a21xa32) - (a11*a22xa34_a24xa32) - (a12*a24xa31_a21xa34);
</code>
  <code ln="0909">    b41 =( a21*a33xa42_a32xa43) - (a22*a33xa41_a31xa43) + (a23*a32xa41_a31xa42);
</code>
  <code ln="0910">    b42 =( a12*a33xa41_a31xa43) - (a13*a32xa41_a31xa42) - (a11*a33xa42_a32xa43);
</code>
  <code ln="0911">    b43 =(-a13*a21xa42_a22xa41) - (a11*a22xa43_a23xa42) - (a12*a23xa41_a21xa43);
</code>
  <code ln="0912">    b44 =(-a13*a22xa31_a21xa32) - (a11*a23xa32_a22xa33) - (a12*a21xa33_a23xa31);
</code>
  <code ln="0913">
</code>
  <code ln="0914">    b11 = b11 * det;
</code>
  <code ln="0915">    b12 = b12 * det;
</code>
  <code ln="0916">    b13 = b13 * det;
</code>
  <code ln="0917">    b14 = b14 * det;
</code>
  <code ln="0918">    b21 = b21 * det;
</code>
  <code ln="0919">    b22 = b22 * det;
</code>
  <code ln="0920">    b23 = b23 * det;
</code>
  <code ln="0921">    b24 = b24 * det;
</code>
  <code ln="0922">    b31 = b31 * det;
</code>
  <code ln="0923">    b32 = b32 * det;
</code>
  <code ln="0924">    b33 = b33 * det;
</code>
  <code ln="0925">    b34 = b34 * det;
</code>
  <code ln="0926">    b41 = b41 * det;
</code>
  <code ln="0927">    b42 = b42 * det;
</code>
  <code ln="0928">    b43 = b43 * det;
</code>
  <code ln="0929">    b44 = b44 * det;
</code>
  <code ln="0930">
</code>
  <code ln="0931">    inv[0][0] = b11;
</code>
  <code ln="0932">    inv[0][1] = b12;
</code>
  <code ln="0933">    inv[0][2] = b13;
</code>
  <code ln="0934">    inv[0][3] = b14;
</code>
  <code ln="0935">
</code>
  <code ln="0936">    inv[1][0] = b21;
</code>
  <code ln="0937">    inv[1][1] = b22;
</code>
  <code ln="0938">    inv[1][2] = b23;
</code>
  <code ln="0939">    inv[1][3] = b24;
</code>
  <code ln="0940">
</code>
  <code ln="0941">    inv[2][0] = b31;
</code>
  <code ln="0942">    inv[2][1] = b32;
</code>
  <code ln="0943">    inv[2][2] = b33;
</code>
  <code ln="0944">    inv[2][3] = b34;
</code>
  <code ln="0945">
</code>
  <code ln="0946">    inv[3][0] = b41;
</code>
  <code ln="0947">    inv[3][1] = b42;
</code>
  <code ln="0948">    inv[3][2] = b43;
</code>
  <code ln="0949">    inv[3][3] = b44;
</code>
  <code ln="0950">
</code>
  <code ln="0951">    return 1;
</code>
  <code ln="0952">}
</code>
  <code ln="0953">
</code>
  <code ln="0954">
</code>
  <multilinecomment ln="0955" lc="09">!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="0963">
</code>
  <code ln="0964">NN_MATH_INLINE MTX44*
</code>
  <code ln="0965">MTX44RotAxisRad_C( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
</code>
  <code ln="0966">{
</code>
  <code ln="0967">    VEC3 vN;
</code>
  <code ln="0968">    f32 s, c;             </code>
<slashcomment ln="0968"> sinTheta, cosTheta</slashcomment>
  <code ln="0968">
</code>
  <code ln="0969">    f32 t;                </code>
<slashcomment ln="0969"> ( 1 - cosTheta )</slashcomment>
  <code ln="0969">
</code>
  <code ln="0970">    f32 x, y, z;          </code>
<slashcomment ln="0970"> The x, y, z components of the normalized axis.</slashcomment>
  <code ln="0970">
</code>
  <code ln="0971">    f32 xSq, ySq, zSq;    </code>
<slashcomment ln="0971"> x, y, z squared</slashcomment>
  <code ln="0971">
</code>
  <code ln="0972">
</code>
  <code ln="0973">
</code>
  <code ln="0974">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="0975">    NN_NULL_ASSERT( pAxis );
</code>
  <code ln="0976">
</code>
  <code ln="0977">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="0978">
</code>
  <code ln="0979">    s = ::std::sinf(fRad);
</code>
  <code ln="0980">    c = ::std::cosf(fRad);
</code>
  <code ln="0981">    t = 1.0f - c;
</code>
  <code ln="0982">
</code>
  <code ln="0983">    VEC3Normalize( &vN, pAxis );
</code>
  <code ln="0984">
</code>
  <code ln="0985">    x = vN.x;
</code>
  <code ln="0986">    y = vN.y;
</code>
  <code ln="0987">    z = vN.z;
</code>
  <code ln="0988">
</code>
  <code ln="0989">    xSq = x * x;
</code>
  <code ln="0990">    ySq = y * y;
</code>
  <code ln="0991">    zSq = z * z;
</code>
  <code ln="0992">
</code>
  <code ln="0993">    m[0][0] = ( t * xSq )   + ( c );
</code>
  <code ln="0994">    m[0][1] = ( t * x * y ) - ( s * z );
</code>
  <code ln="0995">    m[0][2] = ( t * x * z ) + ( s * y );
</code>
  <code ln="0996">    m[0][3] = 0.0f;
</code>
  <code ln="0997">
</code>
  <code ln="0998">    m[1][0] = ( t * x * y ) + ( s * z );
</code>
  <code ln="0999">    m[1][1] = ( t * ySq )   + ( c );
</code>
  <code ln="1000">    m[1][2] = ( t * y * z ) - ( s * x );
</code>
  <code ln="1001">    m[1][3] = 0.0f;
</code>
  <code ln="1002">
</code>
  <code ln="1003">    m[2][0] = ( t * x * z ) - ( s * y );
</code>
  <code ln="1004">    m[2][1] = ( t * y * z ) + ( s * x );
</code>
  <code ln="1005">    m[2][2] = ( t * zSq )   + ( c );
</code>
  <code ln="1006">    m[2][3] = 0.0f;
</code>
  <code ln="1007">    
</code>
  <code ln="1008">    m[3][0] = 0.0f;
</code>
  <code ln="1009">    m[3][1] = 0.0f;
</code>
  <code ln="1010">    m[3][2] = 0.0f;
</code>
  <code ln="1011">    m[3][3] = 1.0f;
</code>
  <code ln="1012">    
</code>
  <code ln="1013">    return pOut;
</code>
  <code ln="1014">}
</code>
  <code ln="1015">NN_MATH_INLINE MTX44*
</code>
  <code ln="1016">MTX44RotAxisRad_C_FAST( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
</code>
  <code ln="1017">{
</code>
  <code ln="1018">    VEC3 vN;
</code>
  <code ln="1019">    f32 s, c;             </code>
<slashcomment ln="1019"> sinTheta, cosTheta</slashcomment>
  <code ln="1019">
</code>
  <code ln="1020">    f32 t;                </code>
<slashcomment ln="1020"> ( 1 - cosTheta )</slashcomment>
  <code ln="1020">
</code>
  <code ln="1021">    f32 x, y, z;          </code>
<slashcomment ln="1021"> The x, y, and z components of the normalized axis.</slashcomment>
  <code ln="1021">
</code>
  <code ln="1022">    f32 xSq, ySq, zSq;    </code>
<slashcomment ln="1022"> x, y, z squared</slashcomment>
  <code ln="1022">
</code>
  <code ln="1023">    f32 m00, m01, m02, m10, m11, m12, m20, m21, m22;
</code>
  <code ln="1024">
</code>
  <code ln="1025">
</code>
  <code ln="1026">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1027">    NN_NULL_ASSERT( pAxis );
</code>
  <code ln="1028">
</code>
  <code ln="1029">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1030">
</code>
  <code ln="1031">#if (MTX44ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
</code>
  <code ln="1032">    SinCosFIdx(&s, &c, NN_MATH_RAD_TO_FIDX(fRad));
</code>
  <code ln="1033">#else
</code>
  <code ln="1034">    s = ::std::sinf(fRad);
</code>
  <code ln="1035">    c = ::std::cosf(fRad);
</code>
  <code ln="1036">#endif
</code>
  <code ln="1037">    t = 1.0f - c;
</code>
  <code ln="1038">
</code>
  <code ln="1039">    VEC3Normalize( &vN, pAxis );
</code>
  <code ln="1040">
</code>
  <code ln="1041">    x = vN.x;
</code>
  <code ln="1042">    y = vN.y;
</code>
  <code ln="1043">    z = vN.z;
</code>
  <code ln="1044">
</code>
  <code ln="1045">    xSq = x * x;
</code>
  <code ln="1046">    ySq = y * y;
</code>
  <code ln="1047">    zSq = z * z;
</code>
  <code ln="1048">
</code>
  <code ln="1049">    m00 = ( t * xSq )   + ( c );
</code>
  <code ln="1050">    m01 = ( t * x * y ) - ( s * z );
</code>
  <code ln="1051">    m02 = ( t * x * z ) + ( s * y );
</code>
  <code ln="1052">
</code>
  <code ln="1053">    m10 = ( t * x * y ) + ( s * z );
</code>
  <code ln="1054">    m11 = ( t * ySq )   + ( c );
</code>
  <code ln="1055">    m12 = ( t * y * z ) - ( s * x );
</code>
  <code ln="1056">
</code>
  <code ln="1057">    m20 = ( t * x * z ) - ( s * y );
</code>
  <code ln="1058">    m21 = ( t * y * z ) + ( s * x );
</code>
  <code ln="1059">    m22 = ( t * zSq )   + ( c );
</code>
  <code ln="1060">
</code>
  <code ln="1061">
</code>
  <code ln="1062">    m[0][0] = m00;
</code>
  <code ln="1063">    m[0][1] = m01;
</code>
  <code ln="1064">    m[0][2] = m02;
</code>
  <code ln="1065">    m[0][3] = 0.0f;
</code>
  <code ln="1066">
</code>
  <code ln="1067">    m[1][0] = m10;
</code>
  <code ln="1068">    m[1][1] = m11;
</code>
  <code ln="1069">    m[1][2] = m12;
</code>
  <code ln="1070">    m[1][3] = 0.0f;
</code>
  <code ln="1071">
</code>
  <code ln="1072">    m[2][0] = m20;
</code>
  <code ln="1073">    m[2][1] = m21;
</code>
  <code ln="1074">    m[2][2] = m22;
</code>
  <code ln="1075">    m[2][3] = 0.0f;
</code>
  <code ln="1076">    
</code>
  <code ln="1077">    m[3][0] = 0.0f;
</code>
  <code ln="1078">    m[3][1] = 0.0f;
</code>
  <code ln="1079">    m[3][2] = 0.0f;
</code>
  <code ln="1080">    m[3][3] = 1.0f;
</code>
  <code ln="1081">    
</code>
  <code ln="1082">    return pOut;
</code>
  <code ln="1083">}
</code>
  <code ln="1084">
</code>
  <code ln="1085">
</code>
  <multilinecomment ln="1086" lc="10">!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the X axis in units of 1/256th of a circle
@param[in] fIdxY  Angle around the Y axis in units of 1/256th of a circle
@param[in] fIdxZ  Angle around the Z axis in units of 1/256th of a circle
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1095">
</code>
  <code ln="1096">NN_MATH_INLINE MTX44*
</code>
  <code ln="1097">MTX44RotXYZFIdxC(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
</code>
  <code ln="1098">{
</code>
  <code ln="1099">    NN_FLOAT_ASSERT(fIdxX);
</code>
  <code ln="1100">    NN_FLOAT_ASSERT(fIdxY);
</code>
  <code ln="1101">    NN_FLOAT_ASSERT(fIdxZ);
</code>
  <code ln="1102">
</code>
  <code ln="1103">    f32 sinx, cosx;
</code>
  <code ln="1104">    f32 siny, cosy;
</code>
  <code ln="1105">    f32 sinz, cosz;
</code>
  <code ln="1106">    f32 f1, f2;
</code>
  <code ln="1107">
</code>
  <code ln="1108">    SinCosFIdx(&sinx, &cosx, fIdxX);
</code>
  <code ln="1109">    SinCosFIdx(&siny, &cosy, fIdxY);
</code>
  <code ln="1110">    SinCosFIdx(&sinz, &cosz, fIdxZ);
</code>
  <code ln="1111">
</code>
  <code ln="1112">    pOut->f._20 = -siny;
</code>
  <code ln="1113">    pOut->f._00 = cosz * cosy;
</code>
  <code ln="1114">    pOut->f._10 = sinz * cosy;
</code>
  <code ln="1115">    pOut->f._21 = cosy * sinx;
</code>
  <code ln="1116">    pOut->f._22 = cosy * cosx;
</code>
  <code ln="1117">
</code>
  <code ln="1118">    f1 = cosx * sinz;
</code>
  <code ln="1119">    f2 = sinx * cosz;
</code>
  <code ln="1120">
</code>
  <code ln="1121">    pOut->f._01 = f2 * siny - f1;
</code>
  <code ln="1122">    pOut->f._12 = f1 * siny - f2;
</code>
  <code ln="1123">
</code>
  <code ln="1124">    f1 = sinx * sinz;
</code>
  <code ln="1125">    f2 = cosx * cosz;
</code>
  <code ln="1126">    pOut->f._02 = f2 * siny + f1;
</code>
  <code ln="1127">    pOut->f._11 = f1 * siny + f2;
</code>
  <code ln="1128">
</code>
  <code ln="1129">    pOut->f._03 = 0.f;
</code>
  <code ln="1130">    pOut->f._13 = 0.f;
</code>
  <code ln="1131">    pOut->f._23 = 0.f;
</code>
  <code ln="1132">    
</code>
  <code ln="1133">    pOut->f._30 = 0.0f;
</code>
  <code ln="1134">    pOut->f._31 = 0.0f;
</code>
  <code ln="1135">    pOut->f._32 = 0.0f;
</code>
  <code ln="1136">    pOut->f._33 = 1.0f;
</code>
  <code ln="1137">    
</code>
  <code ln="1138">    return pOut;
</code>
  <code ln="1139">}
</code>
  <code ln="1140">NN_MATH_INLINE MTX44*
</code>
  <code ln="1141">MTX44RotXYZFIdxC_FAST(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
</code>
  <code ln="1142">{
</code>
  <code ln="1143">    NN_FLOAT_ASSERT(fIdxX);
</code>
  <code ln="1144">    NN_FLOAT_ASSERT(fIdxY);
</code>
  <code ln="1145">    NN_FLOAT_ASSERT(fIdxZ);
</code>
  <code ln="1146">
</code>
  <code ln="1147">    f32 sinx, cosx;
</code>
  <code ln="1148">    f32 siny, cosy;
</code>
  <code ln="1149">    f32 sinz, cosz;
</code>
  <code ln="1150">    f32 f1, f2, f3, f4;
</code>
  <code ln="1151">    f32 f00, f10, f21, f22;
</code>
  <code ln="1152">    f32 f01, f11, f02, f12;
</code>
  <code ln="1153">
</code>
  <code ln="1154">
</code>
  <code ln="1155">
</code>
  <code ln="1156">    {
</code>
  <code ln="1157">
</code>
  <code ln="1158">        u16 idxx;
</code>
  <code ln="1159">        f32 abs_fidxx;
</code>
  <code ln="1160">        f32 rx;
</code>
  <code ln="1161">     
</code>
  <code ln="1162">        u16 idxy;
</code>
  <code ln="1163">        f32 abs_fidxy;
</code>
  <code ln="1164">        f32 ry;
</code>
  <code ln="1165">
</code>
  <code ln="1166">        u16 idxz;
</code>
  <code ln="1167">        f32 abs_fidxz;
</code>
  <code ln="1168">        f32 rz;
</code>
  <code ln="1169">
</code>
  <code ln="1170">        int negx, negy, negz;
</code>
  <code ln="1171">
</code>
  <code ln="1172">        negx = (fIdxX < 0.0f) ? 1 : 0;
</code>
  <code ln="1173">        abs_fidxx = FAbs(fIdxX);
</code>
  <code ln="1174">        negy = (fIdxY < 0.0f) ? 1 : 0;
</code>
  <code ln="1175">        abs_fidxy = FAbs(fIdxY);
</code>
  <code ln="1176">        negz = (fIdxZ < 0.0f) ? 1 : 0;
</code>
  <code ln="1177">        abs_fidxz = FAbs(fIdxZ);
</code>
  <code ln="1178">
</code>
  <code ln="1179">
</code>
  <code ln="1180">        while ( abs_fidxx >= 65536.0f )
</code>
  <code ln="1181">        {
</code>
  <code ln="1182">            abs_fidxx -= 65536.0f;
</code>
  <code ln="1183">        }
</code>
  <code ln="1184">        while ( abs_fidxy >= 65536.0f )
</code>
  <code ln="1185">        {
</code>
  <code ln="1186">            abs_fidxy -= 65536.0f;
</code>
  <code ln="1187">        }
</code>
  <code ln="1188">        while ( abs_fidxz >= 65536.0f )
</code>
  <code ln="1189">        {
</code>
  <code ln="1190">            abs_fidxz -= 65536.0f;
</code>
  <code ln="1191">        }
</code>
  <code ln="1192">
</code>
  <code ln="1193">        idxx = F32ToU16(abs_fidxx);
</code>
  <code ln="1194">        idxy = F32ToU16(abs_fidxy);
</code>
  <code ln="1195">        idxz = F32ToU16(abs_fidxz);
</code>
  <code ln="1196">        {
</code>
  <code ln="1197">            f32 idxxf, idxyf, idxzf;
</code>
  <code ln="1198">            
</code>
  <code ln="1199">            idxxf = U16ToF32(idxx);
</code>
  <code ln="1200">            idxyf = U16ToF32(idxy);
</code>
  <code ln="1201">            idxzf = U16ToF32(idxz);
</code>
  <code ln="1202">            
</code>
  <code ln="1203">            rx = abs_fidxx - idxxf;
</code>
  <code ln="1204">            ry = abs_fidxy - idxyf;
</code>
  <code ln="1205">            rz = abs_fidxz - idxzf;
</code>
  <code ln="1206">            
</code>
  <code ln="1207">
</code>
  <code ln="1208">        }
</code>
  <code ln="1209">
</code>
  <code ln="1210">        idxx &= 0xff;
</code>
  <code ln="1211">        idxy &= 0xff;
</code>
  <code ln="1212">        idxz &= 0xff;
</code>
  <code ln="1213">
</code>
  <code ln="1214">        {
</code>
  <code ln="1215">            f32 sinx_val, sinx_delta, cosx_val, cosx_delta;
</code>
  <code ln="1216">            f32 siny_val, siny_delta, cosy_val, cosy_delta;
</code>
  <code ln="1217">            f32 sinz_val, sinz_delta, cosz_val, cosz_delta;
</code>
  <code ln="1218">            
</code>
  <code ln="1219">            sinx_val = internal::gSinCosTbl[idxx].sin_val;
</code>
  <code ln="1220">            cosx_val = internal::gSinCosTbl[idxx].cos_val;
</code>
  <code ln="1221">            sinx_delta = internal::gSinCosTbl[idxx].sin_delta;
</code>
  <code ln="1222">            cosx_delta = internal::gSinCosTbl[idxx].cos_delta;
</code>
  <code ln="1223">
</code>
  <code ln="1224">            sinx = sinx_val + rx * sinx_delta;
</code>
  <code ln="1225">            cosx = cosx_val + rx * cosx_delta;
</code>
  <code ln="1226">
</code>
  <code ln="1227">            siny_val = internal::gSinCosTbl[idxy].sin_val;
</code>
  <code ln="1228">            cosy_val = internal::gSinCosTbl[idxy].cos_val;
</code>
  <code ln="1229">            siny_delta = internal::gSinCosTbl[idxy].sin_delta;
</code>
  <code ln="1230">            cosy_delta = internal::gSinCosTbl[idxy].cos_delta;
</code>
  <code ln="1231">
</code>
  <code ln="1232">            siny = siny_val + ry * siny_delta;
</code>
  <code ln="1233">            cosy = cosy_val + ry * cosy_delta;
</code>
  <code ln="1234">
</code>
  <code ln="1235">            sinz_val = internal::gSinCosTbl[idxz].sin_val;
</code>
  <code ln="1236">            cosz_val = internal::gSinCosTbl[idxz].cos_val;
</code>
  <code ln="1237">            sinz_delta = internal::gSinCosTbl[idxz].sin_delta;
</code>
  <code ln="1238">            cosz_delta = internal::gSinCosTbl[idxz].cos_delta;
</code>
  <code ln="1239">
</code>
  <code ln="1240">            sinz = sinz_val + rz * sinz_delta;
</code>
  <code ln="1241">            cosz = cosz_val + rz * cosz_delta;
</code>
  <code ln="1242">
</code>
  <code ln="1243">        }
</code>
  <code ln="1244">
</code>
  <code ln="1245">        sinx = (negx) ? -sinx : sinx;
</code>
  <code ln="1246">        siny = (negy) ? -siny : siny;
</code>
  <code ln="1247">        sinz = (negz) ? -sinz : sinz;
</code>
  <code ln="1248">
</code>
  <code ln="1249">    }
</code>
  <code ln="1250">
</code>
  <code ln="1251">    f00 = cosz * cosy;
</code>
  <code ln="1252">    f10 = sinz * cosy;
</code>
  <code ln="1253">    f21 = sinx * cosy;
</code>
  <code ln="1254">    f22 = cosx * cosy;
</code>
  <code ln="1255">
</code>
  <code ln="1256">    f1 = cosx * sinz;
</code>
  <code ln="1257">    f2 = sinx * cosz;
</code>
  <code ln="1258">
</code>
  <code ln="1259">    f01 = f2 * siny - f1;
</code>
  <code ln="1260">    f12 = f1 * siny - f2;
</code>
  <code ln="1261">
</code>
  <code ln="1262">    f3 = sinx * sinz;
</code>
  <code ln="1263">    f4 = cosx * cosz;
</code>
  <code ln="1264">
</code>
  <code ln="1265">    f02 = f4 * siny + f3;
</code>
  <code ln="1266">    f11 = f3 * siny + f4;
</code>
  <code ln="1267">
</code>
  <code ln="1268">    pOut->f._00 = f00;
</code>
  <code ln="1269">    pOut->f._10 = f10;
</code>
  <code ln="1270">    pOut->f._21 = f21;
</code>
  <code ln="1271">    pOut->f._22 = f22;
</code>
  <code ln="1272">
</code>
  <code ln="1273">    pOut->f._01 = f01;
</code>
  <code ln="1274">    pOut->f._12 = f12;
</code>
  <code ln="1275">    pOut->f._02 = f02;
</code>
  <code ln="1276">    pOut->f._11 = f11;
</code>
  <code ln="1277">    pOut->f._20 = -siny;
</code>
  <code ln="1278">
</code>
  <code ln="1279">    *(unsigned int*)&pOut->f._03 = 0x00000000;
</code>
  <code ln="1280">    *(unsigned int*)&pOut->f._13 = 0x00000000;
</code>
  <code ln="1281">    *(unsigned int*)&pOut->f._23 = 0x00000000;
</code>
  <code ln="1282">
</code>
  <code ln="1283">    *(unsigned int*)&pOut->f._30 = 0x00000000;
</code>
  <code ln="1284">    *(unsigned int*)&pOut->f._31 = 0x00000000;
</code>
  <code ln="1285">    *(unsigned int*)&pOut->f._32 = 0x00000000;
</code>
  <code ln="1286">    *(unsigned int*)&pOut->f._33 = 0x3F800000;
</code>
  <code ln="1287">    
</code>
  <code ln="1288">    return pOut;
</code>
  <code ln="1289">}
</code>
  <code ln="1290">
</code>
  <multilinecomment ln="1291" lc="08">!--------------------------------------------------------------------------*
@brief Creates a matrix to use for scaling transformations.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1298">
</code>
  <code ln="1299">NN_MATH_INLINE MTX44*
</code>
  <code ln="1300">MTX44ScaleC(MTX44* pOut, const VEC3* pS)
</code>
  <code ln="1301">{
</code>
  <code ln="1302">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1303">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1304">
</code>
  <code ln="1305">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1306">
</code>
  <code ln="1307">    m[0][0] = pS->x;    m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = 0.0f;
</code>
  <code ln="1308">    m[1][0] = 0.0f;     m[1][1] = pS->y; m[1][2] = 0.0f;  m[1][3] = 0.0f;
</code>
  <code ln="1309">    m[2][0] = 0.0f;     m[2][1] = 0.0f;  m[2][2] = pS->z; m[2][3] = 0.0f;
</code>
  <code ln="1310">    m[3][0] = 0.0f;     m[3][1] = 0.0f;  m[3][2] = 0.0f; m[3][3] = 1.0f;
</code>
  <code ln="1311">
</code>
  <code ln="1312">    return pOut;
</code>
  <code ln="1313">}
</code>
  <code ln="1314">NN_MATH_INLINE MTX44*
</code>
  <code ln="1315">MTX44ScaleC_FAST(MTX44* pOut, const VEC3* pS)
</code>
  <code ln="1316">{
</code>
  <code ln="1317">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1318">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1319">
</code>
  <code ln="1320">    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);
</code>
  <code ln="1321">
</code>
  <code ln="1322">    f32 f1 = 1.0f;
</code>
  <code ln="1323">    f32 f0 = 0.0f;
</code>
  <code ln="1324">    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
</code>
  <code ln="1325">    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
</code>
  <code ln="1326">    const unsigned int *p = reinterpret_cast<const unsigned int*>(pS);
</code>
  <code ln="1327">
</code>
  <code ln="1328">    m[ 0] =  p[0];  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = f32_0;
</code>
  <code ln="1329">    m[ 4] = f32_0;  m[ 5] =  p[1];  m[ 6] = f32_0;  m[ 7] = f32_0;
</code>
  <code ln="1330">    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] =  p[2];  m[11] = f32_0;
</code>
  <code ln="1331">    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;
</code>
  <code ln="1332">
</code>
  <code ln="1333">    return pOut;
</code>
  <code ln="1334">}
</code>
  <code ln="1335">
</code>
  <code ln="1336">
</code>
  <multilinecomment ln="1337" lc="09">!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1345">
</code>
  <code ln="1346">NN_MATH_INLINE MTX44*
</code>
  <code ln="1347">MTX44MultScaleC(MTX44* pOut, const MTX44* pM, const VEC3* pS)
</code>
  <code ln="1348">{
</code>
  <code ln="1349">    </code>
<slashcomment ln="1349"> Version where the scale matrix is applied from the right.</slashcomment>
  <code ln="1349">
</code>
  <code ln="1350">    pOut->f._00 = pM->f._00 * pS->x;
</code>
  <code ln="1351">    pOut->f._10 = pM->f._10 * pS->x;
</code>
  <code ln="1352">    pOut->f._20 = pM->f._20 * pS->x;
</code>
  <code ln="1353">
</code>
  <code ln="1354">    pOut->f._01 = pM->f._01 * pS->y;
</code>
  <code ln="1355">    pOut->f._11 = pM->f._11 * pS->y;
</code>
  <code ln="1356">    pOut->f._21 = pM->f._21 * pS->y;
</code>
  <code ln="1357">
</code>
  <code ln="1358">    pOut->f._02 = pM->f._02 * pS->z;
</code>
  <code ln="1359">    pOut->f._12 = pM->f._12 * pS->z;
</code>
  <code ln="1360">    pOut->f._22 = pM->f._22 * pS->z;
</code>
  <code ln="1361">
</code>
  <code ln="1362">    if (pOut != pM)
</code>
  <code ln="1363">    {
</code>
  <code ln="1364">        pOut->f._03 = pM->f._03;
</code>
  <code ln="1365">        pOut->f._13 = pM->f._13;
</code>
  <code ln="1366">        pOut->f._23 = pM->f._23;
</code>
  <code ln="1367">    }
</code>
  <code ln="1368">
</code>
  <code ln="1369">    return pOut;
</code>
  <code ln="1370">}
</code>
  <code ln="1371">
</code>
  <code ln="1372">
</code>
  <multilinecomment ln="1373" lc="09">!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1381">
</code>
  <code ln="1382">NN_MATH_INLINE MTX44*
</code>
  <code ln="1383">MTX44MultScaleC(MTX44* pOut, const VEC3* pS, const MTX44* pM)
</code>
  <code ln="1384">{
</code>
  <code ln="1385">    NN_NULL_ASSERT( pOut  );
</code>
  <code ln="1386">    NN_NULL_ASSERT( pS  );
</code>
  <code ln="1387">    NN_NULL_ASSERT( pM  );
</code>
  <code ln="1388">
</code>
  <code ln="1389">    const f32 (*const src)[4] = pM->m;
</code>
  <code ln="1390">    f32 (*const dst)[4] = pOut->m;
</code>
  <code ln="1391">
</code>
  <code ln="1392">    dst[0][0] = src[0][0] * pS->x;     dst[0][1] = src[0][1] * pS->x;
</code>
  <code ln="1393">    dst[0][2] = src[0][2] * pS->x;     dst[0][3] = src[0][3] * pS->x;
</code>
  <code ln="1394">
</code>
  <code ln="1395">    dst[1][0] = src[1][0] * pS->y;     dst[1][1] = src[1][1] * pS->y;
</code>
  <code ln="1396">    dst[1][2] = src[1][2] * pS->y;     dst[1][3] = src[1][3] * pS->y;
</code>
  <code ln="1397">
</code>
  <code ln="1398">    dst[2][0] = src[2][0] * pS->z;     dst[2][1] = src[2][1] * pS->z;
</code>
  <code ln="1399">    dst[2][2] = src[2][2] * pS->z;     dst[2][3] = src[2][3] * pS->z;
</code>
  <code ln="1400">    
</code>
  <code ln="1401">    return pOut;
</code>
  <code ln="1402">}
</code>
  <code ln="1403">
</code>
  <code ln="1404">
</code>
  <multilinecomment ln="1405" lc="08">!--------------------------------------------------------------------------*
@brief Creates a translation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1412">
</code>
  <code ln="1413">NN_MATH_INLINE MTX44*
</code>
  <code ln="1414">MTX44TranslateC(MTX44* pOut, const VEC3* pT)
</code>
  <code ln="1415">{
</code>
  <code ln="1416">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1417">    NN_NULL_ASSERT( pT );
</code>
  <code ln="1418">
</code>
  <code ln="1419">    f32 (*const m)[4] = pOut->m;
</code>
  <code ln="1420">
</code>
  <code ln="1421">    m[0][0] = 1.0f;  m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = pT->x;
</code>
  <code ln="1422">    m[1][0] = 0.0f;  m[1][1] = 1.0f;  m[1][2] = 0.0f;  m[1][3] = pT->y;
</code>
  <code ln="1423">    m[2][0] = 0.0f;  m[2][1] = 0.0f;  m[2][2] = 1.0f;  m[2][3] = pT->z;
</code>
  <code ln="1424">    m[3][0] = 0.0f;  m[3][1] = 0.0f;  m[3][2] = 0.0f;  m[3][3] = 1.0f;
</code>
  <code ln="1425">
</code>
  <code ln="1426">    return pOut;
</code>
  <code ln="1427">}
</code>
  <code ln="1428">NN_MATH_INLINE MTX44*
</code>
  <code ln="1429">MTX44TranslateC_FAST(MTX44* pOut, const VEC3* pT)
</code>
  <code ln="1430">{
</code>
  <code ln="1431">    NN_NULL_ASSERT( pOut );
</code>
  <code ln="1432">    NN_NULL_ASSERT( pT );
</code>
  <code ln="1433">
</code>
  <code ln="1434">    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);
</code>
  <code ln="1435">
</code>
  <code ln="1436">    f32 f1 = 1.0f;
</code>
  <code ln="1437">    f32 f0 = 0.0f;
</code>
  <code ln="1438">    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
</code>
  <code ln="1439">    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
</code>
  <code ln="1440">    const unsigned int *p = reinterpret_cast<const unsigned int*>(pT);
</code>
  <code ln="1441">
</code>
  <code ln="1442">    m[ 0] = f32_1;  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = p[0];
</code>
  <code ln="1443">    m[ 4] = f32_0;  m[ 5] = f32_1;  m[ 6] = f32_0;  m[ 7] = p[1];
</code>
  <code ln="1444">    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] = f32_1;  m[11] = p[2];
</code>
  <code ln="1445">    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;
</code>
  <code ln="1446">
</code>
  <code ln="1447">    return pOut;
</code>
  <code ln="1448">}
</code>
  <code ln="1449">
</code>
  <code ln="1450">
</code>
  <multilinecomment ln="1451" lc="09">!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiplies the translation matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1459">
</code>
  <code ln="1460">NN_MATH_INLINE MTX44*
</code>
  <code ln="1461">MTX44MultTranslateC(MTX44* pOut, const VEC3* pT, const MTX44* pM)
</code>
  <code ln="1462">{
</code>
  <code ln="1463">    NN_NULL_ASSERT(pOut);
</code>
  <code ln="1464">    NN_NULL_ASSERT(pT);
</code>
  <code ln="1465">    NN_NULL_ASSERT(pM);
</code>
  <code ln="1466">
</code>
  <code ln="1467">    const f32 (*const src)[4] = pM->m;
</code>
  <code ln="1468">    f32 (*const dst)[4] = pOut->m;
</code>
  <code ln="1469">
</code>
  <code ln="1470">    if ( src != dst )
</code>
  <code ln="1471">    {
</code>
  <code ln="1472">        (void)MTX44Copy(pOut, pM);
</code>
  <code ln="1473">    }
</code>
  <code ln="1474">
</code>
  <code ln="1475">    dst[0][3] = src[0][3] + pT->x;
</code>
  <code ln="1476">    dst[1][3] = src[1][3] + pT->y;
</code>
  <code ln="1477">    dst[2][3] = src[2][3] + pT->z;
</code>
  <code ln="1478">
</code>
  <code ln="1479">    return pOut;
</code>
  <code ln="1480">}
</code>
  <code ln="1481">
</code>
  <multilinecomment ln="1482" lc="09">!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiply the translation matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------</multilinecomment>
  <code ln="1490">
</code>
  <code ln="1491">NN_MATH_INLINE MTX44*
</code>
  <code ln="1492">MTX44MultTranslateC(MTX44* pOut, const MTX44* pM, const VEC3* pT)
</code>
  <code ln="1493">{
</code>
  <code ln="1494">    NN_NULL_ASSERT(pOut);
</code>
  <code ln="1495">    NN_NULL_ASSERT(pT);
</code>
  <code ln="1496">    NN_NULL_ASSERT(pM);
</code>
  <code ln="1497">
</code>
  <code ln="1498">    </code>
<slashcomment ln="1498"> pOut = pM * pT</slashcomment>
  <code ln="1498">
</code>
  <code ln="1499">    if (pOut != pM)
</code>
  <code ln="1500">    {
</code>
  <code ln="1501">        (void)MTX44Copy(pOut, pM);
</code>
  <code ln="1502">    }
</code>
  <code ln="1503">
</code>
  <code ln="1504">    VEC4 tmp;
</code>
  <code ln="1505">    VEC3Transform(&tmp, pM, pT);
</code>
  <code ln="1506">
</code>
  <code ln="1507">    pOut->f._03 = tmp.x;
</code>
  <code ln="1508">    pOut->f._13 = tmp.y;
</code>
  <code ln="1509">    pOut->f._23 = tmp.z;
</code>
  <code ln="1510">
</code>
  <code ln="1511">    return pOut;
</code>
  <code ln="1512">}
</code>
  <code ln="1513">
</code>
  <multilinecomment ln="1514" lc="03">!
    @}
</multilinecomment>
  <code ln="1516">
</code>
  <code ln="1517">
</code>
  <code ln="1518">}  </code>
<slashcomment ln="1518"> namespace ARMv6</slashcomment>
  <code ln="1518">
</code>
  <code ln="1519">}  </code>
<slashcomment ln="1519"> namespace math</slashcomment>
  <code ln="1519">
</code>
  <code ln="1520">}  </code>
<slashcomment ln="1520"> namespace nn</slashcomment>
  <code ln="1520">
</code>
</BR>
*/
NN_MATH_INLINE MTX44*
MTX44OrthoC(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
    NN_NULL_ASSERT( pOut );

    // bNote:/b Be careful about l vs. 1 below!!!

    f32 (*const m)[4] = pOut->m;
    f32 tmp     =  1.0f / (r - l);
    m[0][0] =  2.0f * tmp;
    m[0][1] =  0.0f;
    m[0][2] =  0.0f;
    m[0][3] = -(r + l) * tmp;

    tmp     =  1.0f / (t - b);
    m[1][0] =  0.0f;
    m[1][1] =  2.0f * tmp;
    m[1][2] =  0.0f;
    m[1][3] = -(t + b) * tmp;

    m[2][0] =  0.0f;
    m[2][1] =  0.0f;

    tmp     =  1.0f / (f - n);

    m[2][2] = tmp;
    m[2][3] = n * tmp;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] =  0.0f;
    m[3][3] =  1.0f;
    
    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44OrthoC_FAST(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
    NN_NULL_ASSERT( pOut );

    // bNote:/b Be careful about l vs. 1 below!!!

    f32 (*const m)[4] = pOut->m;
    register f32 tmp1     =  1.0f / (r - l);
    register f32 tmp2     =  1.0f / (t - b);
    register f32 tmp3     =  1.0f / (f - n);
    register f32 m00, m03, m11, m13, m22, m23;

    m00 =  2.0f * tmp1;
    m03 = -(r + l) * tmp1;

    m11 =  2.0f * tmp2;
    m13 = -(t + b) * tmp2;

    m22 = tmp3;
    m23 = n * tmp3;

    m[0][1] =  0.0f;
    m[0][2] =  0.0f;

    m[1][0] =  0.0f;
    m[1][2] =  0.0f;

    m[2][0] =  0.0f;
    m[2][1] =  0.0f;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] =  0.0f;
    m[3][3] =  1.0f;

    m[0][0] =  m00;
    m[0][3] =  m03;
    m[1][1] =  m11;
    m[1][3] =  m13;
    m[2][2] =  m22;
    m[2][3] =  m23;
    
    return pOut;
}


    /*---------------------------------------------------------------------------*
Description: Faces toward the direction of the screen and rotates the projection matrix.
Arguments: pOut    Pointer to the matrix to rotate.
pivot   
Returns:      
     *---------------------------------------------------------------------------

*/
    inline MTX44*
    MTX44PivotC( MTX44* pOut, PivotDirection pivot )
    {
        // TODO: The process must be optimized.
        
        const f32 PIVOT_ROTATION_SIN_COS[ PIVOT_NUM ][ 2 ] = 
        {
        #ifdef NN_PLATFORM_CTR
            { 0.0f,  1.0f }, // NONE
            { -1.0f, 0.0f }, // TO_UP
            { 0.0f, -1.0f }, // TO_RIGHT
            { 1.0f,  0.0f }, // TO_BOTTOM
            { 0.0f,  1.0f }, // TO_LEFT
        #else
            { 0.0f,  1.0f }, // NONE
            { 0.0f,  1.0f }, // TO_UP
            { -1.0f, 0.0f }, // TO_RIGHT
            { 0.0f, -1.0f }, // TO_BOTTOM
            { 1.0f,  0.0f }, // TO_LEFT
        #endif
        };
        
        if ( pivot == PIVOT_NONE )
        {
            return pOut;
        }
        
        f32 sin = PIVOT_ROTATION_SIN_COS[ pivot ][ 0 ];
        f32 cos = PIVOT_ROTATION_SIN_COS[ pivot ][ 1 ];
        
        f32 (*const m)[4] = pOut->m;
        
        if ( sin == 0.0f )
        {
            m[0][0] = cos * m[0][0];
            m[0][1] = cos * m[0][1];
            m[0][2] = cos * m[0][2];
            m[0][3] = cos * m[0][3];
            
            m[1][0] = cos * m[1][0];
            m[1][1] = cos * m[1][1];
            m[1][2] = cos * m[1][2];
            m[1][3] = cos * m[1][3];
        }
        else // if ( cos == 0.0f )
        {
            f32 tmp = m[0][0];
            m[0][0] = -sin * m[1][0];
            m[1][0] = sin * tmp;
            
            tmp = m[0][1];
            m[0][1] = -sin * m[1][1];
            m[1][1] = sin * tmp;

            tmp = m[0][2];
            m[0][2] = -sin * m[1][2];
            m[1][2] = sin * tmp;

            tmp = m[0][3];
            m[0][3] = -sin * m[1][3];
            m[1][3] = sin * tmp;
        }
        
        return pOut;

    }
    inline MTX44*
    MTX44PivotC_FAST( MTX44* pOut, PivotDirection pivot )
    {
        f32 (*const m)[4] = pOut->m;
        #ifdef NN_PLATFORM_CTR
        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_LEFT ) )
        #else
        if ( ( pivot == PIVOT_NONE ) || ( pivot == PIVOT_UPSIDE_TO_TOP ) )      
        #endif
        {
            return pOut;
        }

        #ifdef NN_PLATFORM_CTR
        if ( pivot == PIVOT_UPSIDE_TO_RIGHT )
        #else
        if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
        #endif
        {
            register f32 m00, m01, m02, m03, m10, m11, m12, m13;

            m00 = -m[0][0];
            m01 = -m[0][1];
            m02 = -m[0][2];
            m03 = -m[0][3];

            m10 = -m[1][0];
            m11 = -m[1][1];
            m12 = -m[1][2];
            m13 = -m[1][3];

            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
        }
        #ifdef NN_PLATFORM_CTR
        else if ( pivot == PIVOT_UPSIDE_TO_BOTTOM )
        #else
        else if ( pivot == PIVOT_UPSIDE_TO_LEFT )
        #endif
        {
            register f32 m00, m01, m02, m03, m10, m11, m12, m13;

            m10 = m[0][0];
            m11 = m[0][1];
            m12 = m[0][2];
            m13 = m[0][3];

            m00 = -m[1][0];
            m01 = -m[1][1];
            m02 = -m[1][2];
            m03 = -m[1][3];

            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
        }
        #ifdef NN_PLATFORM_CTR
        else // if ( pivot == PIVOT_UPSIDE_TO_TOP )
        #else
        else // if ( pivot == PIVOT_UPSIDE_TO_RIGHT )
        #endif
        {
            register f32 m00, m01, m02, m03, m10, m11, m12, m13;

            m10 = -m[0][0];
            m11 = -m[0][1];
            m12 = -m[0][2];
            m13 = -m[0][3];

            m00 = m[1][0];
            m01 = m[1][1];
            m02 = m[1][2];
            m03 = m[1][3];

            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
        }
        return pOut;
    }    


/*!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both span class=argumentp1/span and span class=argumentp2/span.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultC(MTX44* pOut, const MTX44* __restrict p1, const MTX44* __restrict p2) 
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );
    
    MTX44 mTmp;
    
    MTX44* __restrict pDst = ( pOut == p1 || pOut == p2 ) ? &mTmp : pOut;
    
    pDst->f._00 = p1->f._00 * p2->f._00 + p1->f._01 * p2->f._10 + p1->f._02 * p2->f._20 + p1->f._03 * p2->f._30;
    pDst->f._01 = p1->f._00 * p2->f._01 + p1->f._01 * p2->f._11 + p1->f._02 * p2->f._21 + p1->f._03 * p2->f._31;
    pDst->f._02 = p1->f._00 * p2->f._02 + p1->f._01 * p2->f._12 + p1->f._02 * p2->f._22 + p1->f._03 * p2->f._32;
    pDst->f._03 = p1->f._00 * p2->f._03 + p1->f._01 * p2->f._13 + p1->f._02 * p2->f._23 + p1->f._03 * p2->f._33;
    
    pDst->f._10 = p1->f._10 * p2->f._00 + p1->f._11 * p2->f._10 + p1->f._12 * p2->f._20 + p1->f._13 * p2->f._30;
    pDst->f._11 = p1->f._10 * p2->f._01 + p1->f._11 * p2->f._11 + p1->f._12 * p2->f._21 + p1->f._13 * p2->f._31;
    pDst->f._12 = p1->f._10 * p2->f._02 + p1->f._11 * p2->f._12 + p1->f._12 * p2->f._22 + p1->f._13 * p2->f._32;
    pDst->f._13 = p1->f._10 * p2->f._03 + p1->f._11 * p2->f._13 + p1->f._12 * p2->f._23 + p1->f._13 * p2->f._33;
    
    pDst->f._20 = p1->f._20 * p2->f._00 + p1->f._21 * p2->f._10 + p1->f._22 * p2->f._20 + p1->f._23 * p2->f._30;
    pDst->f._21 = p1->f._20 * p2->f._01 + p1->f._21 * p2->f._11 + p1->f._22 * p2->f._21 + p1->f._23 * p2->f._31;
    pDst->f._22 = p1->f._20 * p2->f._02 + p1->f._21 * p2->f._12 + p1->f._22 * p2->f._22 + p1->f._23 * p2->f._32;
    pDst->f._23 = p1->f._20 * p2->f._03 + p1->f._21 * p2->f._13 + p1->f._22 * p2->f._23 + p1->f._23 * p2->f._33;

    pDst->f._30 = p1->f._30 * p2->f._00 + p1->f._31 * p2->f._10 + p1->f._32 * p2->f._20 + p1->f._33 * p2->f._30;
    pDst->f._31 = p1->f._30 * p2->f._01 + p1->f._31 * p2->f._11 + p1->f._32 * p2->f._21 + p1->f._33 * p2->f._31;
    pDst->f._32 = p1->f._30 * p2->f._02 + p1->f._31 * p2->f._12 + p1->f._32 * p2->f._22 + p1->f._33 * p2->f._32;
    pDst->f._33 = p1->f._30 * p2->f._03 + p1->f._31 * p2->f._13 + p1->f._32 * p2->f._23 + p1->f._33 * p2->f._33;
    
    if ( pDst != pOut )
    {
        MTX44Copy( pOut, pDst );
    }
    
    return pOut;
}

namespace {
    inline void SwapF(f32 &a, f32 &b)
    {
        f32 tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
} // namespace (unnamed)


/*!--------------------------------------------------------------------------*
@brief Calculates the inverse of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentp/span.
@param[in] p  Pointer to the original matrix.
@return Returns 1 if the inverse matrix exists; otherwise, returns 0.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE u32
MTX44InverseC(MTX44* pOut, const MTX44* p)
{
    MTX44 mTmp;
    f32 (*src)[4];
    f32 (*inv)[4];
    f32   w;
    
    NN_NULL_ASSERT( p );
    NN_NULL_ASSERT( pOut );

    MTX44Copy(&mTmp, p);
    MTX44Identity(pOut);
    
    src = mTmp.m;
    inv = pOut->m;
    
    for (int i = 0; i < 4; ++i)
    {
        f32 max = 0.0f;
        s32 swp = i;
        
        // ---- Partial Pivoting -----
        for(int k = i ; k < 4 ; k++ )
        {
            f32 ftmp;
            ftmp = ::std::fabs(src[k][i]);
            if ( ftmp > max )
            {
                max = ftmp;
                swp = k;
            }
        }
        
        // Check the singular matrix.
        //(Alternatively, cant solve the inverse matrix with this algorithm.)
        if ( max == 0.0f )
        {
            return 0;
        }
        
        // Swap the row.
        if ( swp != i )
        {
            for (int k = 0; k < 4; k++)
            {
                SwapF(src[i][k], src[swp][k]);
                SwapF(inv[i][k], inv[swp][k]);
            }
        }
        
        // ---- Pivoting End ----
        
        w = 1.0f / src[i][i];
        for (int j = 0; j < 4; ++j)
        {
            src[i][j] *= w;
            inv[i][j] *= w;
        }
        
        for (int k = 0; k < 4; ++k )
        {
            if ( k == i )
                continue;
            
            w = src[k][i];
            for (int j = 0; j < 4; ++j)
            {
                src[k][j] -= src[i][j] * w;
                inv[k][j] -= inv[i][j] * w;
            }
        }
    }
    
    return 1;
}
NN_MATH_INLINE u32
MTX44InverseC_FAST_ALGO(MTX44* pOut, const MTX44* p)
{
    const f32 (*src)[4];
    f32 (*inv)[4];
    
    NN_NULL_ASSERT( p );
    NN_NULL_ASSERT( pOut );

    src = p->m;
    inv = pOut->m;

    f32 a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
    f32 b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44;
    f32 det;
    
    a11 = src[0][0];
    a12 = src[0][1];
    a13 = src[0][2];
    a14 = src[0][3];

    a21 = src[1][0];
    a22 = src[1][1];
    a23 = src[1][2];
    a24 = src[1][3];

    a31 = src[2][0];
    a32 = src[2][1];
    a33 = src[2][2];
    a34 = src[2][3];

    a41 = src[3][0];
    a42 = src[3][1];
    a43 = src[3][2];
    a44 = src[3][3];
    
    det = a11*(a22*a33*a44 + a23*a34*a42 + a24*a32*a43)
        + a12*(a21*a34*a43 + a23*a31*a44 + a24*a33*a41)
        + a13*(a21*a32*a44 + a22*a34*a41 + a24*a31*a42)
        + a14*(a21*a33*a42 + a22*a31*a43 + a23*a32*a41)
        - a11*(a22*a34*a43 + a23*a32*a44 + a24*a33*a42)
        - a12*(a21*a33*a44 + a23*a34*a41 + a24*a31*a43)
        - a13*(a21*a34*a42 + a22*a31*a44 + a24*a32*a41)
        - a14*(a21*a32*a43 + a22*a33*a41 + a23*a31*a42);
        
    if(det==0.0f)
        return 0;

    det = 1.0f / det;

    f32 a33xa44_a34xa43, a32xa44_a34xa42, a33xa42_a32xa43,
        a33xa41_a31xa43, a31xa44_a34xa41, a32xa41_a31xa42;
    
    a33xa44_a34xa43 = a33*a44 - a34*a43;
    a32xa44_a34xa42 = a32*a44 - a34*a42;
    a33xa42_a32xa43 = a33*a42 - a32*a43;
    a33xa41_a31xa43 = a33*a41 - a31*a43;
    a31xa44_a34xa41 = a31*a44 - a34*a41;
    a32xa41_a31xa42 = a32*a41 - a31*a42;
    
    f32 a23xa44_a24xa43, a24xa33_a23xa34, a24xa42_a22xa44, a22xa43_a23xa42,
        a22xa34_a24xa32, a23xa32_a22xa33, a21xa44_a24xa41, a23xa41_a21xa43,
        a24xa31_a21xa34, a21xa33_a23xa31, a21xa42_a22xa41, a22xa31_a21xa32;
    
    a23xa44_a24xa43 = a23*a44 - a24*a43;
    a24xa33_a23xa34 = a24*a33 - a23*a34;
    a24xa42_a22xa44 = a24*a42 - a22*a44;
    a22xa43_a23xa42 = a22*a43 - a23*a42;
    a22xa34_a24xa32 = a22*a34 - a24*a32;
    a23xa32_a22xa33 = a23*a32 - a22*a33;
    a21xa44_a24xa41 = a21*a44 - a24*a41;
    a23xa41_a21xa43 = a23*a41 - a21*a43;
    a24xa31_a21xa34 = a24*a31 - a21*a34;
    a21xa33_a23xa31 = a21*a33 - a23*a31;
    a21xa42_a22xa41 = a21*a42 - a22*a41;
    a22xa31_a21xa32 = a22*a31 - a21*a32;
    
    b11 =( a22*a33xa44_a34xa43) - (a23*a32xa44_a34xa42) - (a24*a33xa42_a32xa43);
    b12 =( a13*a32xa44_a34xa42) + (a14*a33xa42_a32xa43) - (a12*a33xa44_a34xa43);
    b13 =( a12*a23xa44_a24xa43) + (a13*a24xa42_a22xa44) + (a14*a22xa43_a23xa42);
    b14 =( a12*a24xa33_a23xa34) + (a13*a22xa34_a24xa32) + (a14*a23xa32_a22xa33);
    b21 =( a23*a31xa44_a34xa41) + (a24*a33xa41_a31xa43) - (a21*a33xa44_a34xa43);
    b22 =( a11*a33xa44_a34xa43) - (a13*a31xa44_a34xa41) - (a14*a33xa41_a31xa43);
    b23 =( a13*a21xa44_a24xa41) + (a14*a23xa41_a21xa43) - (a11*a23xa44_a24xa43);
    b24 =( a13*a24xa31_a21xa34) + (a14*a21xa33_a23xa31) - (a11*a24xa33_a23xa34);
    b31 =( a21*a32xa44_a34xa42) - (a22*a31xa44_a34xa41) - (a24*a32xa41_a31xa42);
    b32 =( a12*a31xa44_a34xa41) + (a14*a32xa41_a31xa42) - (a11*a32xa44_a34xa42);
    b33 =( a14*a21xa42_a22xa41) - (a11*a24xa42_a22xa44) - (a12*a21xa44_a24xa41);
    b34 =( a14*a22xa31_a21xa32) - (a11*a22xa34_a24xa32) - (a12*a24xa31_a21xa34);
    b41 =( a21*a33xa42_a32xa43) - (a22*a33xa41_a31xa43) + (a23*a32xa41_a31xa42);
    b42 =( a12*a33xa41_a31xa43) - (a13*a32xa41_a31xa42) - (a11*a33xa42_a32xa43);
    b43 =(-a13*a21xa42_a22xa41) - (a11*a22xa43_a23xa42) - (a12*a23xa41_a21xa43);
    b44 =(-a13*a22xa31_a21xa32) - (a11*a23xa32_a22xa33) - (a12*a21xa33_a23xa31);

    b11 = b11 * det;
    b12 = b12 * det;
    b13 = b13 * det;
    b14 = b14 * det;
    b21 = b21 * det;
    b22 = b22 * det;
    b23 = b23 * det;
    b24 = b24 * det;
    b31 = b31 * det;
    b32 = b32 * det;
    b33 = b33 * det;
    b34 = b34 * det;
    b41 = b41 * det;
    b42 = b42 * det;
    b43 = b43 * det;
    b44 = b44 * det;

    inv[0][0] = b11;
    inv[0][1] = b12;
    inv[0][2] = b13;
    inv[0][3] = b14;

    inv[1][0] = b21;
    inv[1][1] = b22;
    inv[1][2] = b23;
    inv[1][3] = b24;

    inv[2][0] = b31;
    inv[2][1] = b32;
    inv[2][2] = b33;
    inv[2][3] = b34;

    inv[3][0] = b41;
    inv[3][1] = b42;
    inv[3][2] = b43;
    inv[3][3] = b44;

    return 1;
}


/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44RotAxisRad_C( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
{
    VEC3 vN;
    f32 s, c;             // sinTheta, cosTheta
    f32 t;                // ( 1 - cosTheta )
    f32 x, y, z;          // The x, y, z components of the normalized axis.
    f32 xSq, ySq, zSq;    // x, y, z squared


    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( pAxis );

    f32 (*const m)[4] = pOut->m;

    s = ::std::sinf(fRad);
    c = ::std::cosf(fRad);
    t = 1.0f - c;

    VEC3Normalize( &vN, pAxis );

    x = vN.x;
    y = vN.y;
    z = vN.z;

    xSq = x * x;
    ySq = y * y;
    zSq = z * z;

    m[0][0] = ( t * xSq )   + ( c );
    m[0][1] = ( t * x * y ) - ( s * z );
    m[0][2] = ( t * x * z ) + ( s * y );
    m[0][3] = 0.0f;

    m[1][0] = ( t * x * y ) + ( s * z );
    m[1][1] = ( t * ySq )   + ( c );
    m[1][2] = ( t * y * z ) - ( s * x );
    m[1][3] = 0.0f;

    m[2][0] = ( t * x * z ) - ( s * y );
    m[2][1] = ( t * y * z ) + ( s * x );
    m[2][2] = ( t * zSq )   + ( c );
    m[2][3] = 0.0f;
    
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    
    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44RotAxisRad_C_FAST( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
{
    VEC3 vN;
    f32 s, c;             // sinTheta, cosTheta
    f32 t;                // ( 1 - cosTheta )
    f32 x, y, z;          // The x, y, and z components of the normalized axis.
    f32 xSq, ySq, zSq;    // x, y, z squared
    f32 m00, m01, m02, m10, m11, m12, m20, m21, m22;


    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( pAxis );

    f32 (*const m)[4] = pOut->m;

#if (MTX44ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
    SinCosFIdx(&s, &c, NN_MATH_RAD_TO_FIDX(fRad));
#else
    s = ::std::sinf(fRad);
    c = ::std::cosf(fRad);
#endif
    t = 1.0f - c;

    VEC3Normalize( &vN, pAxis );

    x = vN.x;
    y = vN.y;
    z = vN.z;

    xSq = x * x;
    ySq = y * y;
    zSq = z * z;

    m00 = ( t * xSq )   + ( c );
    m01 = ( t * x * y ) - ( s * z );
    m02 = ( t * x * z ) + ( s * y );

    m10 = ( t * x * y ) + ( s * z );
    m11 = ( t * ySq )   + ( c );
    m12 = ( t * y * z ) - ( s * x );

    m20 = ( t * x * z ) - ( s * y );
    m21 = ( t * y * z ) + ( s * x );
    m22 = ( t * zSq )   + ( c );


    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[0][3] = 0.0f;

    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[1][3] = 0.0f;

    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
    m[2][3] = 0.0f;
    
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    
    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the X axis in units of 1/256th of a circle
@param[in] fIdxY  Angle around the Y axis in units of 1/256th of a circle
@param[in] fIdxZ  Angle around the Z axis in units of 1/256th of a circle
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44RotXYZFIdxC(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
{
    NN_FLOAT_ASSERT(fIdxX);
    NN_FLOAT_ASSERT(fIdxY);
    NN_FLOAT_ASSERT(fIdxZ);

    f32 sinx, cosx;
    f32 siny, cosy;
    f32 sinz, cosz;
    f32 f1, f2;

    SinCosFIdx(&sinx, &cosx, fIdxX);
    SinCosFIdx(&siny, &cosy, fIdxY);
    SinCosFIdx(&sinz, &cosz, fIdxZ);

    pOut->f._20 = -siny;
    pOut->f._00 = cosz * cosy;
    pOut->f._10 = sinz * cosy;
    pOut->f._21 = cosy * sinx;
    pOut->f._22 = cosy * cosx;

    f1 = cosx * sinz;
    f2 = sinx * cosz;

    pOut->f._01 = f2 * siny - f1;
    pOut->f._12 = f1 * siny - f2;

    f1 = sinx * sinz;
    f2 = cosx * cosz;
    pOut->f._02 = f2 * siny + f1;
    pOut->f._11 = f1 * siny + f2;

    pOut->f._03 = 0.f;
    pOut->f._13 = 0.f;
    pOut->f._23 = 0.f;
    
    pOut->f._30 = 0.0f;
    pOut->f._31 = 0.0f;
    pOut->f._32 = 0.0f;
    pOut->f._33 = 1.0f;
    
    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44RotXYZFIdxC_FAST(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
{
    NN_FLOAT_ASSERT(fIdxX);
    NN_FLOAT_ASSERT(fIdxY);
    NN_FLOAT_ASSERT(fIdxZ);

    f32 sinx, cosx;
    f32 siny, cosy;
    f32 sinz, cosz;
    f32 f1, f2, f3, f4;
    f32 f00, f10, f21, f22;
    f32 f01, f11, f02, f12;



    {

        u16 idxx;
        f32 abs_fidxx;
        f32 rx;
     
        u16 idxy;
        f32 abs_fidxy;
        f32 ry;

        u16 idxz;
        f32 abs_fidxz;
        f32 rz;

        int negx, negy, negz;

        negx = (fIdxX < 0.0f) ? 1 : 0;
        abs_fidxx = FAbs(fIdxX);
        negy = (fIdxY < 0.0f) ? 1 : 0;
        abs_fidxy = FAbs(fIdxY);
        negz = (fIdxZ < 0.0f) ? 1 : 0;
        abs_fidxz = FAbs(fIdxZ);


        while ( abs_fidxx >= 65536.0f )
        {
            abs_fidxx -= 65536.0f;
        }
        while ( abs_fidxy >= 65536.0f )
        {
            abs_fidxy -= 65536.0f;
        }
        while ( abs_fidxz >= 65536.0f )
        {
            abs_fidxz -= 65536.0f;
        }

        idxx = F32ToU16(abs_fidxx);
        idxy = F32ToU16(abs_fidxy);
        idxz = F32ToU16(abs_fidxz);
        {
            f32 idxxf, idxyf, idxzf;
            
            idxxf = U16ToF32(idxx);
            idxyf = U16ToF32(idxy);
            idxzf = U16ToF32(idxz);
            
            rx = abs_fidxx - idxxf;
            ry = abs_fidxy - idxyf;
            rz = abs_fidxz - idxzf;
            

        }

        idxx &= 0xff;
        idxy &= 0xff;
        idxz &= 0xff;

        {
            f32 sinx_val, sinx_delta, cosx_val, cosx_delta;
            f32 siny_val, siny_delta, cosy_val, cosy_delta;
            f32 sinz_val, sinz_delta, cosz_val, cosz_delta;
            
            sinx_val = internal::gSinCosTbl[idxx].sin_val;
            cosx_val = internal::gSinCosTbl[idxx].cos_val;
            sinx_delta = internal::gSinCosTbl[idxx].sin_delta;
            cosx_delta = internal::gSinCosTbl[idxx].cos_delta;

            sinx = sinx_val + rx * sinx_delta;
            cosx = cosx_val + rx * cosx_delta;

            siny_val = internal::gSinCosTbl[idxy].sin_val;
            cosy_val = internal::gSinCosTbl[idxy].cos_val;
            siny_delta = internal::gSinCosTbl[idxy].sin_delta;
            cosy_delta = internal::gSinCosTbl[idxy].cos_delta;

            siny = siny_val + ry * siny_delta;
            cosy = cosy_val + ry * cosy_delta;

            sinz_val = internal::gSinCosTbl[idxz].sin_val;
            cosz_val = internal::gSinCosTbl[idxz].cos_val;
            sinz_delta = internal::gSinCosTbl[idxz].sin_delta;
            cosz_delta = internal::gSinCosTbl[idxz].cos_delta;

            sinz = sinz_val + rz * sinz_delta;
            cosz = cosz_val + rz * cosz_delta;

        }

        sinx = (negx) ? -sinx : sinx;
        siny = (negy) ? -siny : siny;
        sinz = (negz) ? -sinz : sinz;

    }

    f00 = cosz * cosy;
    f10 = sinz * cosy;
    f21 = sinx * cosy;
    f22 = cosx * cosy;

    f1 = cosx * sinz;
    f2 = sinx * cosz;

    f01 = f2 * siny - f1;
    f12 = f1 * siny - f2;

    f3 = sinx * sinz;
    f4 = cosx * cosz;

    f02 = f4 * siny + f3;
    f11 = f3 * siny + f4;

    pOut->f._00 = f00;
    pOut->f._10 = f10;
    pOut->f._21 = f21;
    pOut->f._22 = f22;

    pOut->f._01 = f01;
    pOut->f._12 = f12;
    pOut->f._02 = f02;
    pOut->f._11 = f11;
    pOut->f._20 = -siny;

    *(unsigned int*)&pOut->f._03 = 0x00000000;
    *(unsigned int*)&pOut->f._13 = 0x00000000;
    *(unsigned int*)&pOut->f._23 = 0x00000000;

    *(unsigned int*)&pOut->f._30 = 0x00000000;
    *(unsigned int*)&pOut->f._31 = 0x00000000;
    *(unsigned int*)&pOut->f._32 = 0x00000000;
    *(unsigned int*)&pOut->f._33 = 0x3F800000;
    
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Creates a matrix to use for scaling transformations.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44ScaleC(MTX44* pOut, const VEC3* pS)
{
    NN_NULL_ASSERT( pOut  );
    NN_NULL_ASSERT( pS  );

    f32 (*const m)[4] = pOut->m;

    m[0][0] = pS->x;    m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = 0.0f;
    m[1][0] = 0.0f;     m[1][1] = pS->y; m[1][2] = 0.0f;  m[1][3] = 0.0f;
    m[2][0] = 0.0f;     m[2][1] = 0.0f;  m[2][2] = pS->z; m[2][3] = 0.0f;
    m[3][0] = 0.0f;     m[3][1] = 0.0f;  m[3][2] = 0.0f; m[3][3] = 1.0f;

    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44ScaleC_FAST(MTX44* pOut, const VEC3* pS)
{
    NN_NULL_ASSERT( pOut  );
    NN_NULL_ASSERT( pS  );

    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);

    f32 f1 = 1.0f;
    f32 f0 = 0.0f;
    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
    const unsigned int *p = reinterpret_cast<const unsigned int*>(pS);

    m[ 0] =  p[0];  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = f32_0;
    m[ 4] = f32_0;  m[ 5] =  p[1];  m[ 6] = f32_0;  m[ 7] = f32_0;
    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] =  p[2];  m[11] = f32_0;
    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;

    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultScaleC(MTX44* pOut, const MTX44* pM, const VEC3* pS)
{
    // Version where the scale matrix is applied from the right.
    pOut->f._00 = pM->f._00 * pS->x;
    pOut->f._10 = pM->f._10 * pS->x;
    pOut->f._20 = pM->f._20 * pS->x;

    pOut->f._01 = pM->f._01 * pS->y;
    pOut->f._11 = pM->f._11 * pS->y;
    pOut->f._21 = pM->f._21 * pS->y;

    pOut->f._02 = pM->f._02 * pS->z;
    pOut->f._12 = pM->f._12 * pS->z;
    pOut->f._22 = pM->f._22 * pS->z;

    if (pOut != pM)
    {
        pOut->f._03 = pM->f._03;
        pOut->f._13 = pM->f._13;
        pOut->f._23 = pM->f._23;
    }

    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultScaleC(MTX44* pOut, const VEC3* pS, const MTX44* pM)
{
    NN_NULL_ASSERT( pOut  );
    NN_NULL_ASSERT( pS  );
    NN_NULL_ASSERT( pM  );

    const f32 (*const src)[4] = pM->m;
    f32 (*const dst)[4] = pOut->m;

    dst[0][0] = src[0][0] * pS->x;     dst[0][1] = src[0][1] * pS->x;
    dst[0][2] = src[0][2] * pS->x;     dst[0][3] = src[0][3] * pS->x;

    dst[1][0] = src[1][0] * pS->y;     dst[1][1] = src[1][1] * pS->y;
    dst[1][2] = src[1][2] * pS->y;     dst[1][3] = src[1][3] * pS->y;

    dst[2][0] = src[2][0] * pS->z;     dst[2][1] = src[2][1] * pS->z;
    dst[2][2] = src[2][2] * pS->z;     dst[2][3] = src[2][3] * pS->z;
    
    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Creates a translation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44TranslateC(MTX44* pOut, const VEC3* pT)
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( pT );

    f32 (*const m)[4] = pOut->m;

    m[0][0] = 1.0f;  m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = pT->x;
    m[1][0] = 0.0f;  m[1][1] = 1.0f;  m[1][2] = 0.0f;  m[1][3] = pT->y;
    m[2][0] = 0.0f;  m[2][1] = 0.0f;  m[2][2] = 1.0f;  m[2][3] = pT->z;
    m[3][0] = 0.0f;  m[3][1] = 0.0f;  m[3][2] = 0.0f;  m[3][3] = 1.0f;

    return pOut;
}
NN_MATH_INLINE MTX44*
MTX44TranslateC_FAST(MTX44* pOut, const VEC3* pT)
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( pT );

    unsigned int *m = reinterpret_cast<unsigned int *>(pOut->m);

    f32 f1 = 1.0f;
    f32 f0 = 0.0f;
    const unsigned int f32_1 = *(reinterpret_cast<unsigned int*>(&f1));
    const unsigned int f32_0 = *(reinterpret_cast<unsigned int*>(&f0));
    const unsigned int *p = reinterpret_cast<const unsigned int*>(pT);

    m[ 0] = f32_1;  m[ 1] = f32_0;  m[ 2] = f32_0;  m[ 3] = p[0];
    m[ 4] = f32_0;  m[ 5] = f32_1;  m[ 6] = f32_0;  m[ 7] = p[1];
    m[ 8] = f32_0;  m[ 9] = f32_0;  m[10] = f32_1;  m[11] = p[2];
    m[12] = f32_0;  m[13] = f32_0;  m[14] = f32_0;  m[15] = f32_1;

    return pOut;
}


/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiplies the translation matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultTranslateC(MTX44* pOut, const VEC3* pT, const MTX44* pM)
{
    NN_NULL_ASSERT(pOut);
    NN_NULL_ASSERT(pT);
    NN_NULL_ASSERT(pM);

    const f32 (*const src)[4] = pM->m;
    f32 (*const dst)[4] = pOut->m;

    if ( src != dst )
    {
        (void)MTX44Copy(pOut, pM);
    }

    dst[0][3] = src[0][3] + pT->x;
    dst[1][3] = src[1][3] + pT->y;
    dst[2][3] = src[2][3] + pT->z;

    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiply the translation matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as span class=argumentpM/span.
@param[in] pM  Pointer to the original matrix.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns span class=argumentpOut/span.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44*
MTX44MultTranslateC(MTX44* pOut, const MTX44* pM, const VEC3* pT)
{
    NN_NULL_ASSERT(pOut);
    NN_NULL_ASSERT(pT);
    NN_NULL_ASSERT(pM);

    // pOut = pM * pT
    if (pOut != pM)
    {
        (void)MTX44Copy(pOut, pM);
    }

    VEC4 tmp;
    VEC3Transform(&tmp, pM, pT);

    pOut->f._03 = tmp.x;
    pOut->f._13 = tmp.y;
    pOut->f._23 = tmp.z;

    return pOut;
}

/*!
    @}
*/

}  // namespace ARMv6
}  // namespace math
}  // namespace nn

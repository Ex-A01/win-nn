/*---------------------------------------------------------------------------*
Project: Horizon

Copyright (C)Nintendo Co., Ltd.  All rights reserved.

These coded instructions, statements, and computer programs contain
proprietary information of Nintendo of America Inc. and/or Nintendo
Company Ltd., and are protected by Federal copyright law.  They may
not be disclosed to third parties or copied or duplicated in any form,
in whole or in part, without the prior written consent of Nintendo.

$Rev: 58466 $
 *---------------------------------------------------------------------------*/

#ifndef NN_MATH_MATH_MATRIX34_H_
#define NN_MATH_MATH_MATRIX34_H_

#include <cstring>
#include <nn/math/math_Config.h>
#include <nn/math/math_Vector3.h>
#include <nn/math/math_Vector4.h>
#include <nn/math/math_Quaternion.h>
#include <nn/math/ARMv6/math_Matrix34.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct MTX34;

/*!
@name 3x4 Matrices
    @{
*/

/* ------------------------------------------------------------------------
Function for MTX34
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Calculates the sum of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Add(MTX34* pOut, const MTX34* p1, const MTX34* p2);

/*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pCamPos  Pointer to the vector that specifies the camera position.
@param[in] pCamRotateDeg  Pointer to vector that specifies the amount of camera rotation. In units of degrees.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34CameraRotate(MTX34* pOut, const VEC3* pCamPos, const VEC3* pCamRotateDeg);

/*!--------------------------------------------------------------------------*
@brief Copies a matrix.

@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix to copy from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Copy(MTX34* pOut, const MTX34* p);

/*!--------------------------------------------------------------------------*
@brief Creates an identity matrix.

@param[out] pOut  Pointer to the buffer that stores the identity matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34Identity(MTX34* pOut);

/*!--------------------------------------------------------------------------*
@brief Calculates the inverse of a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.

@return Returns <tt>1</tt> if the inverse matrix exists; otherwise, returns <tt>0</tt>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE u32    MTX34Inverse(MTX34* pOut, const MTX34* p);

/*!--------------------------------------------------------------------------*
:overload     targetMtx34
@brief Calculates an inverse transpose of a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.

@return Returns <tt>1</tt> if the inverse matrix exists; otherwise, returns <tt>0</tt>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE u32    MTX34InvTranspose(MTX34* pOut, const MTX34* p);

/*!--------------------------------------------------------------------------*
:overload     targetMtx33
@brief Calculates an inverse transpose of a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.

@return Returns <tt>1</tt> if the inverse matrix exists; otherwise, returns <tt>0</tt>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE u32 MTX34InvTranspose(MTX33* pOut, const MTX34* p);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is a unitary matrix.

@param[in] p  Pointer to the matrix to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is the identity matrix, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool MTX34IsIdentity(const MTX34* p);

/*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pCamPos  Pointer to the vector that specifies the camera position.
@param[in] pCamUp  Pointer to the vector that specifies the up direction for the camera.
@param[in] pTarget  Pointer to the vector that specifies the fixation point for the camera.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34LookAt(MTX34* pOut, const VEC3* pCamPos, const VEC3* pCamUp, const VEC3* pTarget);

/*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pCamPos  Pointer to the vector that specifies the camera position.
@param[in] twistDeg  Angle of rotation around the camera's line of sight. In units of degrees.
@param[in] pTarget  Pointer to the vector that specifies the fixation point for the camera.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34LookAt(MTX34* pOut, const VEC3* pCamPos, f32 twistDeg, const VEC3* pTarget);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a real number and adds another matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] t  Number to multiply by.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to add.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34MAdd(MTX34* pOut, f32 t, const MTX34* p1, const MTX34* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Mult(MTX34* pOut, const MTX34* p1, const MTX34* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar product of a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.
@param[in] f  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Mult(MTX34* pOut, const MTX34* p, f32 f);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix from the left by a matrix array.

@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] p1  Pointer to the matrix that is taken as the left-hand value.
@param[in] pSrc  Pointer to the start of the array of matrices used as the right side value.
@param[in] count  The number of elements in the array of matrices used as the right side value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34MultArray(MTX34* pOut, const MTX34* p1, const MTX34* pSrc, s32 count);

/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the right.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the original matrix.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34MultScale(MTX34* pOut, const MTX34* pM, const VEC3* pS);

/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the left.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@param[in] pM  Pointer to the original matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34MultScale(MTX34* pOut, const VEC3* __restrict pS, const MTX34* pM);

/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiplies the translation matrix from the left.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@param[in] pM  Pointer to the original matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34MultTranslate(MTX34* pOut, const VEC3* pT, const MTX34* pM);

/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiply the translation matrix from the right.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the original matrix.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34MultTranslate(MTX34* pOut, const MTX34* pM, const VEC3* pT);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fDeg  Amount of rotation in degrees

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotAxisDeg(MTX34* pOut, const VEC3* pAxis, f32 fDeg);

/*!--------------------------------------------------------------------------*
@brief Updates the values of the rotation-related elements in the specified matrix, in terms of rotation around the specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fDeg  Amount of rotation in degrees

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotAxisDegPartially(MTX34* pOut, const VEC3* pAxis, f32 fDeg);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fIdx  Amount of rotation in units of 1/256th of a circle

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotAxisFIdx(MTX34* pOut, const VEC3* pAxis, f32 fIdx);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotAxisRad(MTX34* pOut, const VEC3* pAxis, f32 fRad);

/*!--------------------------------------------------------------------------*
:private
@brief Creates a rotation matrix for rotating about a specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotAxisRad_( MTX34* pOut, const VEC3 *pAxis, f32 fRad );

/*!--------------------------------------------------------------------------*
@brief Updates the values of the rotation-related elements in the specified matrix, in terms of rotation around the specified axis.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotAxisRadPartially(MTX34* pOut, const VEC3* pAxis, f32 fRad);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fDegX  Angle around the x-axis in degrees.
@param[in] fDegY  Angle around the y-axis in degrees.
@param[in] fDegZ  Angle around the z-axis in degrees.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotXYZDeg(MTX34* pOut, f32 fDegX, f32 fDegY, f32 fDegZ);

/*!--------------------------------------------------------------------------*
@brief Updates rotation-related elements in the specified matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fDegX  Angle around the x-axis in degrees.
@param[in] fDegY  Angle around the y-axis in degrees.
@param[in] fDegZ  Angle around the z-axis in degrees.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotXYZDegPartially(MTX34* pOut, f32 fDegX, f32 fDegY, f32 fDegZ);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the x-axis in units of 1/256th of a circle.
@param[in] fIdxY  Angle around the y-axis in units of 1/256th of a circle.
@param[in] fIdxZ  Angle around the z-axis in units of 1/256th of a circle.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotXYZFIdx(MTX34* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fRadX  Angle around the x-axis in radians.
@param[in] fRadY  Angle around the y-axis in radians.
@param[in] fRadZ  Angle around the z-axis in radians.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotXYZRad(MTX34* pOut, f32 fRadX, f32 fRadY, f32 fRadZ);

/*!--------------------------------------------------------------------------*
@brief Updates rotation-related elements in the specified matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fRadX  Angle around the x-axis in radians.
@param[in] fRadY  Angle around the y-axis in radians.
@param[in] fRadZ  Angle around the z-axis in radians.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34RotXYZRadPartially(MTX34* pOut, f32 fRadX, f32 fRadY, f32 fRadZ);

/*!--------------------------------------------------------------------------*
@brief Produces a matrix that is the result of pre-multiplying a rotation matrix by a translation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the x-axis in units of 1/256th of a circle
@param[in] fIdxY  Angle around the y-axis in units of 1/256th of a circle
@param[in] fIdxZ  Angle around the z-axis in units of 1/256th of a circle
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34RotXYZTranslateFIdx(MTX34* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ, const VEC3* pT);

/*!--------------------------------------------------------------------------*
@brief Creates a matrix to use for scaling transformations.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Scale(MTX34* pOut, const VEC3* pS);

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix for referencing shadow textures based on the viewing frustum.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] n  Distance from the camera to the near clipping plane.
@param[in] f  Distance from the camera to the far clipping plane.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34ShadowProjectionFrustum(MTX34* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f);

/*!--------------------------------------------------------------------------*
@brief Creates an orthogonal projection matrix for referencing shadow texture.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] n  Distance from the camera to the near clipping plane.
@param[in] f  Distance from the camera to the far clipping plane.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34ShadowProjectionOrtho(MTX34* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f);

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix for referencing shadow textures.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] fovy  Vertical view angle. In units of radians.
@param[in] aspect  Aspect ratio of the clipping plane.
@param[in] n  Distance from the camera to the near clipping plane.
@param[in] f  Distance from the camera to the far clipping plane.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34ShadowProjectionPerspective(MTX34* pOut, f32 fovy, f32 aspect, f32 n, f32 f);

/*!--------------------------------------------------------------------------*
@brief Calculates the difference of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34Sub(MTX34* pOut, const MTX34* p1, const MTX34* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a texture projection matrix based on the viewing frustum.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] n  Distance from the camera to the near clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34TextureProjectionFrustum(MTX34* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT);

/*!--------------------------------------------------------------------------*
@brief Creates an orthogonal texture projection matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34TextureProjectionOrtho(MTX34* pOut, f32 l, f32 r, f32 b, f32 t, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT);

/*!--------------------------------------------------------------------------*
@brief Creates a texture projection matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] fovy  Vertical view angle. In units of radians.
@param[in] aspect  Aspect ratio of the clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34TextureProjectionPerspective(MTX34* pOut, f32 fovy, f32 aspect, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT);

/*!--------------------------------------------------------------------------*
@brief Creates a translation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Translate(MTX34* pOut, const VEC3* pT);

/*!--------------------------------------------------------------------------*
:overload transpose

@brief Creates the transpose of a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the matrix to transpose.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX34* MTX34Transpose(MTX34* pOut, const MTX34* p);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.

@param[out] pOut  Pointer to the buffer that stores the zero matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX34* MTX34Zero(MTX34* pOut);

/*!
    @}
*/

NN_FORCE_INLINE MTX34* QUATToMTX34(MTX34* pOut, const QUAT* pQ);
NN_FORCE_INLINE VEC3* VEC3Transform(VEC3* pOut, const MTX34* __restrict pM, const VEC3* __restrict pV);

// This will be implemented before long
//MTX34* MTX34Inv(MTX34* pOut, f32* pDet, const MTX34* p);
//MTX34* MTX34InvTranspose(MTX34* pOut, f32* pDet, const MTX34* p);
//f32 MTX34Det(const MTX34* p);

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 3 x 4 matrix.
 *---------------------------------------------------------------------------*/
struct MTX34_
{
    //! @brief Matrix element.
    struct BaseData
    {
        f32 _00;    //!< 1 x 1
        f32 _01;    //!< 1 x 2
        f32 _02;    //!< 1 x 3
        f32 _03;    //!< 1 x 4
        f32 _10;    //!< 2 x 1
        f32 _11;    //!< 2 x 2
        f32 _12;    //!< 2 x 3
        f32 _13;    //!< 2 x 4
        f32 _20;    //!< 3 x 1
        f32 _21;    //!< 3 x 2
        f32 _22;    //!< 3 x 3
        f32 _23;    //!< 3 x 4
    };

    union
    {
    //----------------------------------------
    //! @name Union
    //@{
    #if defined(NN_MATH_USE_ANONYMOUS_STRUCT)
        //! @brief Matrix element.
        struct
        {
            f32 _00, _01, _02, _03;
            f32 _10, _11, _12, _13;
            f32 _20, _21, _22, _23;
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[3][4];    //!< Matrix elements represented as a 2D array.
        f32 a[12];      //!< Matrix elements represented as an array.
        VEC4_ v[3];     //!< Matrix elements represented as a <tt>@ref VEC4_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 3x4 matrix class.
 *---------------------------------------------------------------------------*/
class MTX34 : public MTX34_
{
public:
    static const int ROW_COUNT = 3; //!< The number of rows.
    static const int COLUMN_COUNT = 4; //!< The number of columns.

     //! @brief The identity matrix.
    static const MTX34& Identity()
    {
        static const MTX34 identity(
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f);

        return identity;
    }

    typedef MTX34 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX34() {}

    //! @brief Constructor.
    explicit MTX34(const f32* p) { (void)MTX34Copy(this, (MTX34*)p); }

    //! @brief Copy constructor.
    MTX34(const MTX34& rhs) { (void)MTX34Copy(this, &rhs); }

    //! @brief Constructor.
    explicit MTX34(const MTX33& rhs) { MTX33ToMTX34(this, &rhs); }

    //! @brief Constructor.
    MTX34(f32 x00, f32 x01, f32 x02, f32 x03,
          f32 x10, f32 x11, f32 x12, f32 x13,
          f32 x20, f32 x21, f32 x22, f32 x23)
    {
        f._00 = x00; f._01 = x01; f._02 = x02; f._03 = x03;
        f._10 = x10; f._11 = x11; f._12 = x12; f._13 = x13;
        f._20 = x20; f._21 = x21; f._22 = x22; f._23 = x23;
    }

    //@}

    //----------------------------------------
    //! @name Conversions
    //@{

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator f32*() { return this->a; }

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator const f32*() const { return this->a; }

    //! @brief Gets a row as a <tt>VEC4</tt> value.
    VEC4& GetRow(int index)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<VEC4*>(&this->v[index]);
    }

    //! @brief Gets a row as a <tt>VEC4</tt> value.
    const VEC4& GetRow(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<const VEC4*>(&this->v[index]);
    }

    //! @brief Gets a column as a <tt>VEC3</tt> value.
    VEC3 GetColumn(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        VEC3 column;
        column.x = this->m[0][index];
        column.y = this->m[1][index];
        column.z = this->m[2][index];
        return column;
    }

    //! @brief Sets a column as a <tt>VEC3</tt> value.
    void SetColumn(int index, const VEC3& column)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        this->m[0][index] = column.x;
        this->m[1][index] = column.y;
        this->m[2][index] = column.z;
    }
    //@}

    //----------------------------------------
    //! @name Operators
    //@{

    //! @brief Assigns the values after matrix addition.
    self_type& operator += (const self_type& rhs) { return *MTX34Add(this, this, &rhs); }

    //! @brief Assigns the values after matrix subtraction.
    self_type& operator -= (const self_type& rhs) { return *MTX34Sub(this, this, &rhs); }

    //! @brief Assigns the values of a postmultiplied matrix.
    self_type& operator *= (f32 f) { return *MTX34Mult(this, this, f); }

    //! @brief Assigns the values after matrix division.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }

    //! @brief Returns its own matrix.
    self_type operator + () const { return *this; }

    //! @brief Returns the conjugate of the matrix.
    self_type operator - () const
    {
        return MTX34(-f._00, -f._01, -f._02, -f._03,
                     -f._10, -f._11, -f._12, -f._13,
                     -f._20, -f._21, -f._22, -f._23);
    }

    //! @brief Returns the result of matrix addition.
    self_type operator + (const self_type& rhs) const { MTX34 tmp; return *MTX34Add(&tmp, this, &rhs); }

    //! @brief Returns the result after matrix subtraction.
    self_type operator - (const self_type& rhs) const { MTX34 tmp; return *MTX34Sub(&tmp, this, &rhs); }

    //! @brief Returns the result of matrix multiplication.
    self_type operator * (f32 f) const { MTX34 tmp; return *MTX34Mult(&tmp, this, f); }

    //! @brief Returns the result of matrix division.
    self_type operator / (f32 f) const { return *this * (1.f / f); }

    //! Calculates the transpose.
    self_type& Transpose() { return *MTX34Transpose(this, this); }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{

    //! @brief Sets as the identity matrix.
    self_type& SetupIdentity() { return *MTX34Identity(this); }

    //! @brief Sets up a scaling matrix.
    //!
    //! @param[in] scale  Scale value.
    //!
    self_type& SetupScale(const VEC3& scale) { return *MTX34Scale(this, &scale); }

    //! @brief Sets up a translation matrix.
    //!
    //! @param[in] translate  Translation value.
    //!
    self_type& SetupTranslate(const VEC3& translate)
    {
        return *MTX34Translate(this, &translate);
    }

    //! @brief Sets up a rotation matrix in XYZ order.
    //!
    //! @param[in] rotate  A rotation value. In units of radians.
    //!
    self_type& SetupRotateXyz(const VEC3& rotate)
    {
        return *MTX34RotXYZRad(this, rotate.x, rotate.y, rotate.z);
    }

    //! @brief Sets up a rotation matrix around the specified axis.
    //!
    //! @param[in] axis  The vector to take as the base axis.
    //! @param[in] theta  The angle to rotate by. In units of radians.
    //!
    self_type& SetupRotate(const VEC3& axis, f32 theta)
    {
        return *MTX34RotAxisRad(this, &axis, theta);
    }

    //! @brief Sets a rotation matrix from a quaternion.
    //!
    //! @param[in] quaternion  Source quaternion.
    self_type& SetupRotate(const QUAT& quaternion)
    {
        return *QUATToMTX34(this, &quaternion);
    }

    /*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[in] camPos  Pointer to the vector that specifies the camera position.
@param[in] camUp  Pointer to the vector that specifies the up direction for the camera.
@param[in] target  Pointer to the vector that specifies the fixation point for the camera.
     *---------------------------------------------------------------------------*/
    self_type& SetupLookAt(const VEC3& camPos, const VEC3& camUp, const VEC3& target)
    {
        return *MTX34LookAt(this, &camPos, &camUp, &target);
    }

    /*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[in] camPos  Pointer to the vector that specifies the camera position.
@param[in] twistDeg  Angle of rotation around the camera's line of sight. In units of degrees.
@param[in] target  Pointer to the vector that specifies the fixation point for the camera.
     *---------------------------------------------------------------------------*/
    self_type& SetupLookAt(const VEC3& camPos, f32 twistDeg, const VEC3& target)
    {
        return *MTX34LookAt(this, &camPos, twistDeg, &target);
    }

    /*!--------------------------------------------------------------------------*
@brief Sets the camera matrix.

@param[in] camPos  Pointer to the vector that specifies the camera position.
@param[in] camRotateDeg  Pointer to vector that specifies the amount of camera rotation. In units of degrees.
     *---------------------------------------------------------------------------*/
    self_type& SetupCameraRotate(const VEC3& camPos, const VEC3& camRotateDeg)
    {
        return *MTX34CameraRotate(this, &camPos, &camRotateDeg);
    }

    /*!--------------------------------------------------------------------------*
@brief Creates a texture projection matrix based on the viewing frustum.

@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] n  Distance from the camera to the near clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.
     *---------------------------------------------------------------------------*/
    self_type& SetupTextureProjectionFrustum(f32 l, f32 r, f32 b, f32 t, f32 n, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT)
    {
        return *MTX34TextureProjectionFrustum(this, l, r, b, t, n, scaleS, scaleT, translateS, translateT);
    }

    /*!--------------------------------------------------------------------------*
@brief Creates a texture projection matrix.

@param[in] fovyRad  Vertical view angle. In units of radians.
@param[in] aspect  Aspect ratio of the clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.
     *---------------------------------------------------------------------------*/
    self_type& SetupTextureProjectionFrustum(f32 fovyRad, f32 aspect, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT)
    {
        return *MTX34TextureProjectionPerspective(this, fovyRad, aspect, scaleS, scaleT, translateS, translateT);
    }

    /*!--------------------------------------------------------------------------*
@brief Creates a parallel projection matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] l  Left edge of the near clipping plane.
@param[in] r  Right edge of the near clipping plane.
@param[in] b  Bottom edge of the near clipping plane.
@param[in] t  Top edge of the near clipping plane.
@param[in] scaleS  Scale value along the s-axis.
@param[in] scaleT  Scale value along the t-axis.
@param[in] translateS  Translation value along the s-axis.
@param[in] translateT  Translation value along the t-axis.
     *---------------------------------------------------------------------------*/
    self_type& SetupTextureProjectionFrustum(f32 l, f32 r, f32 b, f32 t, f32 scaleS, f32 scaleT, f32 translateS, f32 translateT)
    {
        return *MTX34TextureProjectionOrtho(this, l, r, b, t, scaleS, scaleT, translateS, translateT);
    }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX34)) == 0; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX34)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX34IsIdentity(this); }
    //@}

    //! @brief Outputs the state.
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};

//! @name Matrices
//@{

//! Alternate name for <tt>MTX34</tt>.
typedef class MTX34 Matrix34;

//@}

//
inline MTX34 operator * (f32 f, const MTX34& rhs)
{
    MTX34 tmp;
    (void)MTX34Mult(&tmp, &rhs, f);
    return tmp;
}

NN_MATH_INLINE MTX34*
MTX34RotXYZRad(MTX34* pOut, f32 fRadX, f32 fRadY, f32 fRadZ)
{
    return MTX34RotXYZFIdx(pOut, NN_MATH_RAD_TO_FIDX(fRadX), NN_MATH_RAD_TO_FIDX(fRadY), NN_MATH_RAD_TO_FIDX(fRadZ));
}

NN_FORCE_INLINE MTX34*
MTX34RotXYZRadPartially(MTX34* pOut, f32 fRadX, f32 fRadY, f32 fRadZ)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTXYZFIDX_CONFIG == D_ORG)
        return ARMv6::MTX34RotXYZFIdxC(pOut, NN_MATH_RAD_TO_FIDX(fRadX), NN_MATH_RAD_TO_FIDX(fRadY), NN_MATH_RAD_TO_FIDX(fRadZ), false);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C)
        return ARMv6::MTX34RotXYZFIdxC_FAST(pOut, NN_MATH_RAD_TO_FIDX(fRadX), NN_MATH_RAD_TO_FIDX(fRadY), NN_MATH_RAD_TO_FIDX(fRadZ), false);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_MATH_INLINE MTX34*
MTX34RotXYZDeg(MTX34* pOut, f32 fDegX, f32 fDegY, f32 fDegZ)
{
    return MTX34RotXYZFIdx(pOut, NN_MATH_DEG_TO_FIDX(fDegX), NN_MATH_DEG_TO_FIDX(fDegY), NN_MATH_DEG_TO_FIDX(fDegZ));
}

NN_FORCE_INLINE MTX34*
MTX34RotXYZDegPartially(MTX34* pOut, f32 fDegX, f32 fDegY, f32 fDegZ)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTXYZFIDX_CONFIG == D_ORG)
        return ARMv6::MTX34RotXYZFIdxC(pOut, NN_MATH_DEG_TO_FIDX(fDegX), NN_MATH_DEG_TO_FIDX(fDegY), NN_MATH_DEG_TO_FIDX(fDegZ), false);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C)
        return ARMv6::MTX34RotXYZFIdxC_FAST(pOut, NN_MATH_DEG_TO_FIDX(fDegX), NN_MATH_DEG_TO_FIDX(fDegY), NN_MATH_DEG_TO_FIDX(fDegZ), false);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_MATH_INLINE MTX34*
MTX34RotAxisRad(MTX34* pOut, const VEC3* pAxis, f32 fRad)
{
    return MTX34RotAxisFIdx(pOut, pAxis, NN_MATH_RAD_TO_FIDX(fRad));
}

NN_FORCE_INLINE MTX34*
MTX34RotAxisRadPartially(MTX34* pOut, const VEC3* pAxis, f32 fRad)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTAXISRAD__CONFIG == D_ORG)
        return ARMv6::MTX34RotAxisRad_C(pOut, pAxis, fRad, false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, fRad, false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM)
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, fRad, false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_MATH_INLINE MTX34*
MTX34RotAxisDeg(MTX34* pOut, const VEC3* pAxis, f32 fDeg)
{
    return MTX34RotAxisFIdx(pOut, pAxis, NN_MATH_DEG_TO_FIDX(fDeg));
}


NN_FORCE_INLINE MTX34*
MTX34RotAxisDegPartially(MTX34* pOut, const VEC3* pAxis, f32 fDeg)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTAXISRAD__CONFIG == D_ORG)
        return ARMv6::MTX34RotAxisRad_C(pOut, pAxis, NN_MATH_DEG_TO_RAD(fDeg), false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, NN_MATH_DEG_TO_RAD(fDeg), false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM)
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, NN_MATH_DEG_TO_RAD(fDeg), false);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Copy(MTX34* pOut, const MTX34* p)
{

#if defined( NN_HARDWARE_CTR )
    #if (MTX34COPY_CONFIG == D_ORG)
        return ARMv6::MTX34CopyC( pOut, p );
    #elif (MTX34COPY_CONFIG == D_FAST_C)
    #elif (MTX34COPY_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34CopyAsm( pOut, p );
    #elif (MTX34COPY_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34COPY_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Mult(MTX34* pOut, const MTX34* p1, const MTX34* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULT_34_CONFIG == D_ORG)
        return ARMv6::MTX34MultC( pOut, p1, p2 );
    #elif (MTX34MULT_34_CONFIG == D_FAST_C)
    #elif (MTX34MULT_34_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultAsm( pOut, p1, p2 );
    #elif (MTX34MULT_34_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULT_34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Mult(MTX34* pOut, const MTX34* p, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULT_F32_CONFIG == D_ORG)
        return ARMv6::MTX34MultC( pOut, p, f );
    #elif (MTX34MULT_F32_CONFIG == D_FAST_C)
    #elif (MTX34MULT_F32_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultAsm( pOut, p, f );
    #elif (MTX34MULT_F32_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULT_F32_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Add(MTX34* pOut, const MTX34* p1, const MTX34* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ADD_CONFIG == D_ORG)
        return ARMv6::MTX34AddC( pOut, p1, p2 );
    #elif (MTX34ADD_CONFIG == D_FAST_C)
    #elif (MTX34ADD_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34AddAsm( pOut, p1, p2 );
    #elif (MTX34ADD_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34ADD_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34CameraRotate(MTX34* pOut, const VEC3* pCamPos, const VEC3* pCamRotateDeg)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34CAMERAROTATE_CONFIG == D_ORG)
        return ARMv6::MTX34CameraRotateC(pOut, pCamPos, pCamRotateDeg);
    #elif (MTX34CAMERAROTATE_CONFIG == D_FAST_C)
        return ARMv6::MTX34CameraRotateC_FAST(pOut, pCamPos, pCamRotateDeg);
    #elif (MTX34CAMERAROTATE_CONFIG == D_FAST_ASM)
    #elif (MTX34CAMERAROTATE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34CAMERAROTATE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE u32
MTX34Inverse(MTX34* pOut, const MTX34* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34INVERSE_CONFIG == D_ORG)
        return ARMv6::MTX34InverseC( pOut, p );
    #elif (MTX34INVERSE_CONFIG == D_FAST_C)
    #elif (MTX34INVERSE_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34InverseAsm( pOut, p);
    #elif (MTX34INVERSE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34INVERSE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE u32
MTX34InvTranspose(MTX34* pOut, const MTX34* __restrict p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34INVTRANSPOSE_34TO34_CONFIG == D_ORG)
        return ARMv6::MTX34InvTransposeC( pOut, p );
    #elif (MTX34INVTRANSPOSE_34TO34_CONFIG == D_FAST_C)
    #elif (MTX34INVTRANSPOSE_34TO34_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34InvTransposeAsm( pOut, p);
    #elif (MTX34INVTRANSPOSE_34TO34_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34INVTRANSPOSE_34TO34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34LookAt(MTX34* pOut, const VEC3* pCamPos, const VEC3* pCamUp, const VEC3* pTarget)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34LOOKAT_VEC3_CONFIG == D_ORG)
        return ARMv6::MTX34LookAtC(pOut, pCamPos, pCamUp, pTarget);
    #elif (MTX34LOOKAT_VEC3_CONFIG == D_FAST_C)
        return ARMv6::MTX34LookAtC_FAST(pOut, pCamPos, pCamUp, pTarget);
    #elif (MTX34LOOKAT_VEC3_CONFIG == D_FAST_ASM)
    #elif (MTX34LOOKAT_VEC3_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34LOOKAT_VEC3_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}


NN_FORCE_INLINE MTX34*
MTX34LookAt(MTX34* pOut, const VEC3* pCamPos, f32 twistDeg, const VEC3* pTarget)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34LOOKAT_F32_CONFIG == D_ORG)
        return ARMv6::MTX34LookAtC(pOut, pCamPos, twistDeg, pTarget);
    #elif (MTX34LOOKAT_F32_CONFIG == D_FAST_C)
        return ARMv6::MTX34LookAtC_FAST(pOut, pCamPos, twistDeg, pTarget);
    #elif (MTX34LOOKAT_F32_CONFIG == D_FAST_ASM)
    #elif (MTX34LOOKAT_F32_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34LOOKAT_F32_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )


}

NN_FORCE_INLINE MTX34*
MTX34MAdd(MTX34* pOut, f32 t, const MTX34* p1, const MTX34* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MADD_CONFIG == D_ORG)
        return ARMv6::MTX34MAddC( pOut, t, p1, p2 );
    #elif (MTX34MADD_CONFIG == D_FAST_C)
    #elif (MTX34MADD_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MAddAsm( pOut, t, p1, p2 );
    #elif (MTX34MADD_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MADD_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34MultScale(MTX34* pOut, const MTX34* pM, const VEC3* pS)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULTSCALE_RIGHT_CONFIG == D_ORG)
        return ARMv6::MTX34MultScaleC( pOut, pM, pS );
    #elif (MTX34MULTSCALE_RIGHT_CONFIG == D_FAST_C)
    #elif (MTX34MULTSCALE_RIGHT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultScaleAsm( pOut, pM, pS );
    #elif (MTX34MULTSCALE_RIGHT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULTSCALE_RIGHT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34MultScale(MTX34* pOut, const VEC3* __restrict pS, const MTX34* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULTSCALE_LEFT_CONFIG == D_ORG)
        return ARMv6::MTX34MultScaleC( pOut, pS, pM );
    #elif (MTX34MULTSCALE_LEFT_CONFIG == D_FAST_C)
    #elif (MTX34MULTSCALE_LEFT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultScaleAsm( pOut, pS, pM );
    #elif (MTX34MULTSCALE_LEFT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULTSCALE_LEFT_CONFIG == D_FAST_ASM_ALGO)
    #endif
    #else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34MultTranslate(MTX34* pOut, const VEC3* pT, const MTX34* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULTTRANSLATE_LEFT_CONFIG == D_ORG)
        return ARMv6::MTX34MultTranslateC( pOut, pT, pM );
    #elif (MTX34MULTTRANSLATE_LEFT_CONFIG == D_FAST_C)
    #elif (MTX34MULTTRANSLATE_LEFT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultTranslateAsm( pOut, pT, pM );
    #elif (MTX34MULTTRANSLATE_LEFT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULTTRANSLATE_LEFT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34MultTranslate(MTX34* pOut, const MTX34* pM, const VEC3* pT)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34MULTTRANSLATE_RIGHT_CONFIG == D_ORG)
        return ARMv6::MTX34MultTranslateC( pOut, pM, pT );
    #elif (MTX34MULTTRANSLATE_RIGHT_CONFIG == D_FAST_C)
    #elif (MTX34MULTTRANSLATE_RIGHT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34MultTranslateAsm( pOut, pM, pT );
    #elif (MTX34MULTTRANSLATE_RIGHT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34MULTTRANSLATE_RIGHT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34RotAxisRad_( MTX34* pOut, const VEC3 *pAxis, f32 fRad )
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTAXISRAD__CONFIG == D_ORG)
        return ARMv6::MTX34RotAxisRad_C(pOut, pAxis, fRad);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, fRad);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM)
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX34RotAxisRad_C_FAST(pOut, pAxis, fRad);
    #elif (MTX34ROTAXISRAD__CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34RotXYZFIdx(MTX34* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34ROTXYZFIDX_CONFIG == D_ORG)
        return ARMv6::MTX34RotXYZFIdxC(pOut, fIdxX, fIdxY, fIdxZ);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C)
        return ARMv6::MTX34RotXYZFIdxC_FAST(pOut, fIdxX, fIdxY, fIdxZ);
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34ROTXYZFIDX_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE MTX34*
MTX34Scale(MTX34* pOut, const VEC3* pS)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34SCALE_CONFIG == D_ORG)
        return ARMv6::MTX34ScaleC(pOut, pS);
    #elif (MTX34SCALE_CONFIG == D_FAST_C)
        return ARMv6::MTX34ScaleC_FAST(pOut, pS);
    #elif (MTX34SCALE_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34ScaleAsm(pOut, pS);
    #elif (MTX34SCALE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34SCALE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Translate(MTX34* pOut, const VEC3* pT)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34TRANSLATE_CONFIG == D_ORG)
        return ARMv6::MTX34TranslateC(pOut, pT);
    #elif (MTX34TRANSLATE_CONFIG == D_FAST_C)
        return ARMv6::MTX34TranslateC_FAST(pOut, pT);
    #elif (MTX34TRANSLATE_CONFIG == D_FAST_ASM)
    #elif (MTX34TRANSLATE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34TRANSLATE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX34*
MTX34Transpose(MTX34* pOut, const MTX34* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX34TRANSPOSE_34TO34_CONFIG == D_ORG)
        return ARMv6::MTX34TransposeC(pOut, p);
    #elif (MTX34TRANSPOSE_34TO34_CONFIG == D_FAST_C)
    #elif (MTX34TRANSPOSE_34TO34_CONFIG == D_FAST_ASM)
        return ARMv6::MTX34TransposeAsm(pOut, p);
    #elif (MTX34TRANSPOSE_34TO34_CONFIG == D_FAST_C_ALGO)
    #elif (MTX34TRANSPOSE_34TO34_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE VEC3*
VEC3Transform(VEC3* pOut, const MTX34* __restrict pM, const VEC3* __restrict pV)
{
#if defined( NN_HARDWARE_CTR )
    #if (VEC3TRANSFORM_34XVEC3_CONFIG == D_ORG)
        return ARMv6::VEC3TransformC(pOut, pM, pV);
    #elif (VEC3TRANSFORM_34XVEC3_CONFIG == D_FAST_C)
    #elif (VEC3TRANSFORM_34XVEC3_CONFIG == D_FAST_ASM)
        return ARMv6::VEC3TransformAsm(pOut, pM, pV);
    #elif (VEC3TRANSFORM_34XVEC3_CONFIG == D_FAST_C_ALGO)
    #elif (VEC3TRANSFORM_34XVEC3_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

}  // namespace math
}  // namespace nn

namespace nn { 
namespace math {

//Overload referencing the -- const argument.

inline bool MTX34IsIdentity(const MTX34& m) { return MTX34IsIdentity( &m ); }

inline MTX34* MTX34Add(MTX34* pOut, const MTX34& m1, const MTX34& m2) { return MTX34Add( pOut, &m1, &m2 ); }
inline MTX34* MTX34Sub(MTX34* pOut, const MTX34& m1, const MTX34& m2) { return MTX34Sub( pOut, &m1, &m2 ); }
inline MTX34* MTX34Mult(MTX34* pOut, const MTX34& m, f32 f) { return MTX34Mult( pOut, &m, f ); }
inline MTX34* MTX34Mult(MTX34* pOut, const MTX34& m1, const MTX34& m2) { return MTX34Mult( pOut, &m1, &m2 ); }
inline MTX34* MTX34MAdd(MTX34* pOut, f32 t, const MTX34& m1, const MTX34& m2) { return MTX34MAdd( pOut, t, &m1, &m2 ); }

inline MTX34* MTX34Copy(MTX34* pOut, const MTX34& m) { return MTX34Copy( pOut, &m ); }
inline MTX34* MTX34MultArray(MTX34* pOut, const MTX34& m1, const MTX34* pSrc, s32 count) { return MTX34MultArray( pOut, m1, pSrc, count ); }
inline u32    MTX34Inverse(MTX34* pOut, const MTX34& m) { return MTX34Inverse( pOut, &m ); }
inline MTX34* MTX34Transpose(MTX34* pOut, const MTX34& m) { return MTX34Transpose( pOut, &m ); }
inline u32    MTX34InvTranspose(MTX34* pOut, const MTX34& m) { return MTX34InvTranspose( pOut, &m ); }
inline u32    MTX34InvTranspose(MTX33* pOut, const MTX34& m) { return MTX34InvTranspose( pOut, &m ); }

inline MTX34* MTX34LookAt(MTX34* pOut, const VEC3& vCamPos, const VEC3& vCamUp, const VEC3& vTarget) { return MTX34LookAt( pOut, &vCamPos, &vCamUp, &vTarget ); }
inline MTX34* MTX34LookAt(MTX34* pOut, const VEC3& vCamPos, f32 twistDeg, const VEC3& vTarget) { return MTX34LookAt( pOut, &vCamPos, twistDeg, &vTarget ); }
inline MTX34* MTX34CameraRotate(MTX34* pOut, const VEC3& vCamPos, const VEC3& vCamRotateDeg) { return MTX34CameraRotate( pOut, &vCamPos, &vCamRotateDeg ); }

inline MTX34* MTX34RotXYZTranslateFIdx(MTX34* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ, const VEC3& vT) { return MTX34RotXYZTranslateFIdx( pOut, fIdxX, fIdxY, fIdxZ, &vT ); }
inline MTX34* MTX34RotAxisFIdx(MTX34* pOut, const VEC3& vAxis, f32 fIdx) { return MTX34RotAxisFIdx( pOut, &vAxis, fIdx ); }
inline MTX34* MTX34RotAxisRad(MTX34* pOut, const VEC3& vAxis, f32 fRad) { return MTX34RotAxisRad( pOut, &vAxis, fRad ); }
inline MTX34* MTX34RotAxisDeg(MTX34* pOut, const VEC3& vAxis, f32 fDeg) { return MTX34RotAxisDeg( pOut, &vAxis, fDeg ); }

inline MTX34* MTX34Scale(MTX34* pOut, const VEC3& vS) { return MTX34Scale( pOut, &vS ); }
inline MTX34* MTX34MultScale(MTX34* pOut, const MTX34& m, const VEC3& vS) { return MTX34MultScale( pOut, &m, &vS ); }
inline MTX34* MTX34MultScale(MTX34* pOut, const VEC3& vS, const MTX34& m) { return MTX34MultScale( pOut, &vS, &m ); }

inline MTX34* MTX34Translate(MTX34* pOut, const VEC3& vT) { return MTX34Translate( pOut, &vT ); }
inline MTX34* MTX34MultTranslate(MTX34* pOut, const MTX34& m, const VEC3& vT) { return MTX34MultTranslate( pOut, &m, &vT ); }
inline MTX34* MTX34MultTranslate(MTX34* pOut, const VEC3& vT, const MTX34& m) { return MTX34MultTranslate( pOut, &vT, &m ); }

}  // namespace math
}  // namespace nn

#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix34.ipp>
#include <nn/math/ARMv6/inline/math_Matrix34.ipp>
#endif

#pragma pop

#endif

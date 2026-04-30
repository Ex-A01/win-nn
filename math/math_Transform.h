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

#ifndef NN_MATH_MATH_TRANSFORM_H_
#define NN_MATH_MATH_TRANSFORM_H_

#include <nn/math/math_Config.h>
#include <nn/math/math_Vector2.h>
#include <nn/math/math_Vector3.h>
#include <nn/math/math_Vector4.h>

namespace nn { namespace math {

/* ------------------------------------------------------------------------
Transform
Class for controlling position via SRT.
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
:category Conversions
@brief A 2D position control member structure.
 *---------------------------------------------------------------------------*/
struct Transform2_
{
    VEC2    scale; //!< Scale.
    VEC2    rotate; //!< Rotation.
    VEC2    translate; //!< Translation.
};

typedef Transform2_ _Transform2;

/*!--------------------------------------------------------------------------*
:category Conversions
@brief A 3D position control member structure.
 *---------------------------------------------------------------------------*/
struct Transform3_
{
    VEC3    scale; //!< Scale.
    VEC3    rotate; //!< Rotation.
    VEC3    translate; //!< Translation.
};

typedef Transform3_ _Transform3;
/*!--------------------------------------------------------------------------*
:category Conversions
@brief A 2D position control class.
 *---------------------------------------------------------------------------*/
class Transform2 : public Transform2_
{
public:
    typedef Transform2 self_type; //!< This class's type.
    typedef f32        value_type; //!< The type of this class's elements.
public:
    //! @name Creation
    //@{

    //! @brief Constructor.
    Transform2() {}
    /* Implicit. */ 
    //! @brief Copy constructor.
    Transform2(const Transform2_& t)
    {
        scale = t.scale; 
        rotate = t.rotate; 
        translate = t.translate;
    }
    //! @brief Constructor.
    Transform2(const VEC2& s, const VEC2& r, const VEC2& t)
    {
        scale     = s;
        rotate    = r;
        translate = t;
    }

    //@}
    
    //! @name Comparisons
    //@{
    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(Transform2)) == 0; }
    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(Transform2)) != 0; }
    //@}
    
    /*!--------------------------------------------------------------------------*
Name: <tt>Transform2::Report</tt>

@brief Writes <tt>Transform2</tt> content to debug output.

@param[in] bNewline  If <tt>true</tt>, a linefeed is output at the end of output.
@param[in] name  Specifies the name of the <tt>Transform2</tt>. <tt>NULL</tt> may be specified.

@return  None.
     *---------------------------------------------------------------------------*/
    void Report(bool bNewline = true, const char* name = NULL) const;
};

/*!--------------------------------------------------------------------------*
:category Conversions
@brief A 3D position control class.
 *---------------------------------------------------------------------------*/
class Transform3 : public Transform3_
{
public:
    typedef Transform3 self_type; //!< This class's type.
    typedef f32        value_type; //!< The type of this class's elements.
public:
    //! @name Creation
    //@{

    //! @brief Constructor.
    Transform3() {}
    /* Implicit. */ 
    //! @brief Copy constructor.
    Transform3(const Transform3_& t) 
    {
        scale = t.scale; 
        rotate = t.rotate; 
        translate = t.translate;
    }
    //! @brief Constructor.
    Transform3(const VEC3& s, const VEC3& r, const VEC3& t)
    {
        scale     = s;
        rotate    = r;
        translate = t;
    }

    //@}
    
    //! @name Comparisons
    //@{
    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(Transform3)) == 0; }
    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(Transform3)) != 0; }
    //@}
    
    /*!--------------------------------------------------------------------------*
Name: <tt>Transform3::Report</tt>

@brief Writes <tt>Transform3</tt> content to debug output.

@param[in] bNewline  If <tt>true</tt>, a linefeed is added to the end of the output.
@param[in] name  Specifies the name of the <tt>Transform3</tt>. <tt>NULL</tt> may be specified.

@return  None.
     *---------------------------------------------------------------------------*/
    void Report(bool bNewline = true, const char* name = NULL) const;
};

/*!
@name Utilities
    @{
*/

/*!--------------------------------------------------------------------------*
@brief Generates a <tt>Transform2</tt> object without any conversion.

@param[out] pOut  Pointer to the buffer used to store the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline Transform2* 
Transform2Identity(Transform2* pOut) 
{
    NN_NULL_ASSERT(pOut);
    pOut->scale     = VEC2(1.f, 1.f);
    pOut->rotate    = VEC2(0.f, 0.f);
    pOut->translate = VEC2(0.f, 0.f);
    return pOut;
}

/*!--------------------------------------------------------------------------*
@brief Generates a <tt>Transform3</tt> object without any conversion.

@param[out] pOut  Pointer to the buffer used to store the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline Transform3* 
Transform3Identity(Transform3* pOut) 
{
    NN_NULL_ASSERT(pOut);
    pOut->scale     = VEC3(1.f, 1.f, 1.f);
    pOut->rotate    = VEC3(0.f, 0.f, 0.f);
    pOut->translate = VEC3(0.f, 0.f, 0.f);
    return pOut;
}

// Transformed as (x, y, z, 1).

/*!--------------------------------------------------------------------------*
@brief Transforms a two-dimensional vector using a matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It is not a problem if this points to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Transform(VEC2* pOut, const MTX23* pM, const VEC2* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Transform(VEC3* pOut, const MTX33* pM, const VEC3* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix. The fourth element of the vector is calculated as 1.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Transform(VEC3* pOut, const MTX34* pM, const VEC3* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix. The fourth element of the vector is calculated as 1.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC3Transform(VEC4* pOut, const MTX44* pM, const VEC3* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms an array of vectors using a matrix. The fourth element of each vector is calculated as 1.

@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the start of the source vector array.
@param[in] count  Number of elements in the vector array to transform.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3TransformArray(VEC3* pOut, const MTX34* pM, const VEC3* pV, s32 count);

/*!--------------------------------------------------------------------------*
@brief Transforms an array of vectors using a matrix. The fourth element of each vector is calculated as 1.

@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the start of the source vector array.
@param[in] count  Number of elements in the vector array to transform.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC3TransformArray(VEC4* pOut, const MTX44* pM, const VEC3* pV, u32 count);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix. The fourth element of the vector is calculated as 0.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3TransformNormal(VEC3* pOut, const MTX34* pM, const VEC3* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms an array of vectors using a matrix. The fourth element of each vector is calculated as 0.

@param[out] pOutArray  Pointer to the start of the array that receives the calculated results.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pArray  Pointer to the start of the source vector array.
@param[in] n  Number of elements in the vector array to transform.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3TransformNormalArray(VEC3* pOutArray, const MTX34* pM, const VEC3* pArray, u32 n);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix. Calculate so the fourth element of the vector is taken as 1, and store in pOut the 3D vector obtained by dividing elements 1 through 3 by the fourth element.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3TransformCoord(VEC3* pOut, const MTX44* pM, const VEC3* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms an array of vectors using a matrix. Calculate so that the fourth element of each vector is taken as 1, and store in <span class="argument">pOut</span> the 3D vectors obtained by dividing elements 1 through 3 by the fourth element.

@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the start of the source vector array.
@param[in] count  Number of elements in the vector array to transform.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3TransformCoordArray(VEC3* pOut, const MTX44* pM, const VEC3* pV, u32 count);

/*!--------------------------------------------------------------------------*
@brief Transforms a vector using a matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same vector as <span class="argument">pV</span>.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the original vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Transform(VEC4* pOut, const MTX44* pM, const VEC4* pV);

/*!--------------------------------------------------------------------------*
@brief Transforms an array of vectors using a matrix.

@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] pM  Pointer to the transformation matrix.
@param[in] pV  Pointer to the start of the source vector array.
@param[in] count  Number of elements in the vector array to transform.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4TransformArray(VEC4* pOut, const MTX44* pM, const VEC4* pV, u32 n);

/*!
    @}
*/

//Overload referencing the -- const argument.
inline VEC2* VEC2Transform(VEC2* pOut, const MTX23& m, const VEC2& v) { return VEC2Transform( pOut, &m, &v ); }

inline VEC3* VEC3Transform(VEC3* pOut, const MTX33& m, const VEC3& v) { return VEC3Transform( pOut, &m, &v ); }
inline VEC3* VEC3Transform(VEC3* pOut, const MTX34& m, const VEC3& v) { return VEC3Transform( pOut, &m, &v ); }
inline VEC4* VEC3Transform(VEC4* pOut, const MTX44& m, const VEC3& v) { return VEC3Transform( pOut, &m, &v ); }
inline VEC3* VEC3TransformArray(VEC3* pOutArray, const MTX34& m, const VEC3* pArray, s32 count) { return VEC3TransformArray( pOutArray, &m, pArray, count ); }
inline VEC4* VEC3TransformArray(VEC4* pOutArray, const MTX44& m, const VEC3* pArray, u32 count) { return VEC3TransformArray( pOutArray, &m, pArray, count ); }

inline VEC3* VEC3TransformNormal(VEC3* pOut, const MTX34& m, const VEC3& v) { return VEC3TransformNormal( pOut, &m, &v ); }
inline VEC3* VEC3TransformNormalArray(VEC3* pOutArray, const MTX34& m, const VEC3* pArray, u32 n) { return VEC3TransformNormalArray( pOutArray, &m, pArray, n ); }

inline VEC3* VEC3TransformCoord(VEC3* pOut, const MTX44& m, const VEC3& v) { return VEC3TransformCoord( pOut, &m, &v ); }
inline VEC3* VEC3TransformCoordArray(VEC3* pOutArray, const MTX44& m, const VEC3* pArray, u32 count) { return VEC3TransformCoordArray( pOutArray, &m, pArray, count ); }

inline VEC4* VEC4Transform(VEC4* pOut, const MTX44& m, const VEC4& v) { return VEC4Transform( pOut, &m, &v ); }
inline VEC4* VEC4TransformArray(VEC4* pOutArray, const MTX44& m, const VEC4* pArray, u32 n) { return VEC4TransformArray( pOutArray, &m, pArray, n ); }


}}  // nn::math


/* NN_MATH_MATH_TRANSFORM_H_ */
#endif


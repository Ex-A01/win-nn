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

#ifndef NN_MATH_MATH_VECTOR4_H_
#define NN_MATH_MATH_VECTOR4_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct VEC4;

/*!
@name 4D Vectors
    @{
*/

/* ------------------------------------------------------------------------
Function for VEC4
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Calculates a sum of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Add(VEC4* pOut, const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the square of a distance between two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the square of the distance between <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   VEC4DistSq(const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates an inner product of two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the inner product of <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   VEC4Dot(const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Determines whether a vector is the zero vector.

@param[in] p  Pointer to the vector to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is a zero vector, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool VEC4IsZero(const VEC4* p);

/*!--------------------------------------------------------------------------*
@brief Determines whether a vector is the zero vector in homogeneous coordinates.

@param[in] p  Pointer to the vector to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is a zero vector, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool VEC4IsZeroWOne(const VEC4* p);

/*!--------------------------------------------------------------------------*
@brief Calculates the vector length.

@param[in] p  Pointer to the input vector.

@return Returns the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   VEC4Len(const VEC4* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a square of a vector length.

@param[in] p  Pointer to the input vector.

@return Returns the square of the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   VEC4LenSq(const VEC4* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a linear interpolation between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the vector taken as the start point of the linear interpolation
@param[in] p2  Pointer to the vector taken as the end point of the linear interpolation
@param[in] t  Linear interpolation parameter. If <tt>0.0</tt>, <span class="argument">p1</span> is the result; if <tt>1.0</tt>, <span class="argument">p2</span> is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Lerp(VEC4* pOut, const VEC4* p1, const VEC4* p2, f32 t);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the largest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Maximize(VEC4* pOut, const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the smallest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Minimize(VEC4* pOut, const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Mult(VEC4* pOut, const VEC4* p1, const VEC4* p2);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the input vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Normalize(VEC4* pOut, const VEC4* p);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.
If normalization fails, sets the specified vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the input vector.
@param[in] alt  Vector to set if normalization fails.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4SafeNormalize(VEC4* pOut, const VEC4* p, const VEC4& alt);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar multiple of a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the left-hand value.
@param[in] scale  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Scale(VEC4* pOut, const VEC4* p, f32 scale);

/*!--------------------------------------------------------------------------*
@brief Calculates a difference between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC4* VEC4Sub(VEC4* pOut, const VEC4* p1, const VEC4* p2);

/*!
    @}
*/

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Vectors
@brief Structure with members in a 4D vector.
 *---------------------------------------------------------------------------*/
struct VEC4_
{
    f32 x;  //!< First member.
    f32 y;  //!< Second column.
    f32 z;  //!< Third member.
    f32 w;  //!< Fourth member.
};


/*!------------------------------------------------------------------------
:category Vectors
@brief A four-dimensional vector class.
   ------------------------------------------------------------------------ */
class VEC4 : public VEC4_
{
public:
    static const int DIMENSION = 4; //!< Number of dimensions.

    //! @brief This is a zero vector.
    static const VEC4& Zero()
    {
        static const VEC4 zero(0.0f, 0.0f, 0.0f, 0.0f);

        return zero;
    }

    //! @brief The zero vector in homogeneous coordinates.
    static const VEC4& ZeroWOne()
    {
        static const VEC4 zero(0.0f, 0.0f, 0.0f, 1.0f);

        return zero;
    }

    //! @brief All of the elements are vectors of <tt>1</tt>.
    static const VEC4& One()
    {
        static const VEC4 one(1.0f, 1.0f, 1.0f, 1.0f);

        return one;
    }

    typedef VEC4 self_type; //!< This class's type.
    typedef f32  value_type; //!< The type of this class's elements.
public:

    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    VEC4() {}
    //! @brief Constructor.
    explicit VEC4(const f32* p) { x = p[0]; y = p[1]; z = p[2]; w = p[3]; }
    //! @brief Copy constructor.
    VEC4(const VEC4_& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    //! @brief Constructor.
    VEC4(f32 fx, f32 fy, f32 fz, f32 fw) { x = fx; y = fy; z = fz; w = fw; }
    //! @brief Constructor.
    explicit VEC4(const VEC3& v) { x = v.x; y = v.y; z = v.z; w = 0.0f; }

    //@}

    //----------------------------------------
    //! @name Conversions
    //@{

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator f32*() { return &x; }

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator const f32*() const { return &x; }

    //@}

    //----------------------------------------
    //! @name Operators
    //@{

    //! @brief Assigns the values of the added vector.
    self_type& operator += (const self_type& rhs) { (void)VEC4Add(this, this, &rhs); return *this; }

    //! @brief Assigns the values after vector subtraction.
    self_type& operator -= (const self_type& rhs) { (void)VEC4Sub(this, this, &rhs); return *this; }

    //! @brief Assigns the values of the multiplied vector.
    self_type& operator *= (f32 f) { (void)VEC4Scale(this, this, f); return *this; }

    //! @brief Assigns values multiplied by each vector element.
    self_type& operator *= (const self_type& rhs) { (void)VEC4Mult(this, this, &rhs); return *this; }

    //! @brief Assigns the values after vector division.
    self_type& operator /= (f32 f) { (void)VEC4Scale(this, this, 1/f); return *this; }

    //! @brief Returns its own vector.
    self_type operator + () const { return *this; }

    //! @brief Returns the inverse of the vector.
    self_type operator - () const { return self_type(-x, -y, -z, -w); }

    //! @brief Returns the result of vector addition.
    self_type operator + (const self_type& rhs) const { VEC4 tmp; (void)VEC4Add(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the vector subtraction result.
    self_type operator - (const self_type& rhs) const { VEC4 tmp; (void)VEC4Sub(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the result of vector multiplication.
    self_type operator * (f32 f) const { VEC4 tmp; (void)VEC4Scale(&tmp, this, f); return tmp; }

    //! @brief Returns the result of vector division.
    self_type operator / (f32 f) const { f32 r = 1.f / f; return operator*(r); }

    //! @brief Linearly interpolates between two vectors and sets the result.
    //!
    //! @param[in] lhs  Vector to take as the starting point of the linear interpolation.
    //! @param[in] rhs  Vector to take as the ending point of the liner interpolation.
    //! @param[in] t  Linear interpolation parameter. The result is <span class="argument">lhs</span> when this is <tt>0.0</tt> and <span class="argument">rhs</span> when this is <tt>1.0</tt>.
    //!
    self_type& Lerp(const VEC4& lhs, const VEC4& rhs, f32 t)
    {
        return *VEC4Lerp(this, &lhs, &rhs, t);
    }

    //! @brief Calculates the dot product with the specified vector.
    //!
    //! @param[in] vec  The vector to use to calculate the dot product.
    //!
    f32 Dot(const VEC4& vec) const
    {
        return VEC4Dot(this, &vec);
    }

    //! @brief Calculates a square of a vector length.
    //! Use of this function is not recommended because it may be removed in the future.
    //! We recommend that you use <tt>LengthSquare</tt> instead.
    f32 LenSq() const { return VEC4LenSq(this); }

    //! @brief Calculates a square of a vector length.
    f32 LengthSquare() const { return VEC4LenSq(this); }

    //! @brief Calculates the vector length.
    f32 Length() const { return VEC4Len(this); }

    //! @brief Normalizes a vector.
    self_type& Normalize()
    {
        return *VEC4Normalize(this, this);
    }

    //! @brief Normalizes a vector.
    //!        If normalization fails, sets the specified vector.
    //!
    //! @param[in] alt  Vector to set if normalization fails.
    self_type& SafeNormalize(const VEC4& alt)
    {
        return *VEC4SafeNormalize(this, this, alt);
    }

    //! @brief Calculates the squared distance to the specified vector.
    //!
    //! @param[in] vec  Vector whose distance you want to calculate.
    f32 DistanceSquare(const VEC4& vec) const
    {
        return VEC4DistSq(this, &vec);
    }

    //! @brief Creates the vector formed by the larger of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the maximum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the maximum values.
    self_type& Maximize(const VEC4& lhs, const VEC4& rhs)
    {
        return *VEC4Maximize(this, &lhs, &rhs);
    }

    //! @brief Creates the vector formed by the smaller of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the minimum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the minimum values.
    self_type& Minimize(const VEC4& lhs, const VEC4& rhs)
    {
        return *VEC4Minimize(this, &lhs, &rhs);
    }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{

    //! @brief Sets values individually.
    void Set(f32 fx, f32 fy, f32 fz, f32 fw) { x = fx; y = fy; z = fz; w = fw; }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w; }

    //! @brief Returns <tt>true</tt> if this is a zero vector.
    bool IsZero() const { return VEC4IsZero(this); }

    //! @brief Returns <tt>true</tt> if this is a zero vector in homogeneous coordinates.
    bool IsZeroWOne() const { return VEC4IsZeroWOne(this); }
    //@}

    //! @brief Outputs the state.
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};

//! @name Vectors
//@{

//! Alternate name for <tt>VEC4</tt>.
typedef class VEC4 Vector4;

//@}

inline VEC4
operator * (f32 f, const VEC4& rhs) { VEC4 tmp; (void)VEC4Scale(&tmp, &rhs, f); return tmp; }


}  // namespace math
}  // namespace nn


#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Vector4.ipp>
#endif

namespace nn {
namespace math {

//Overload referencing the -- const argument.
inline bool VEC4IsZero(const VEC4& v){ return VEC4IsZero( &v ); }
inline bool VEC4IsZeroWOne(const VEC4& v){ return VEC4IsZeroWOne( &v ); }
inline VEC4* VEC4Add(VEC4* pOut, const VEC4& v1, const VEC4& v2) { return VEC4Add( pOut, &v1, &v2 ); }
inline VEC4* VEC4Sub(VEC4* pOut, const VEC4& v1, const VEC4& v2) { return VEC4Sub( pOut, &v1, &v2 ); }
inline VEC4* VEC4Mult(VEC4* pOut, const VEC4& v1, const VEC4& v2) { return VEC4Mult( pOut, &v1, &v2 ); }
inline VEC4* VEC4Scale(VEC4* pOut, const VEC4& v, f32 scale) { return VEC4Scale( pOut, &v, scale); }
inline VEC4* VEC4Lerp(VEC4* pOut, const VEC4& v1, const VEC4& v2, f32 t) { return VEC4Lerp( pOut, &v1, &v2, t ); }
inline f32   VEC4Dot(const VEC4& v1, const VEC4& v2) { return VEC4Dot( &v1, &v2 ); }
inline f32   VEC4LenSq(const VEC4& v) { return VEC4LenSq( &v ); }
inline f32   VEC4Len(const VEC4& v) { return VEC4Len( &v ); }
inline VEC4* VEC4Normalize(VEC4* pOut, const VEC4& v) { return VEC4Normalize( pOut, &v ); }
inline VEC4* VEC4SafeNormalize(VEC4* pOut, const VEC4& v, const VEC4& alt) { return VEC4SafeNormalize( pOut, &v, alt ); }
inline f32   VEC4DistSq(const VEC4& v1, const VEC4& v2) { return VEC4DistSq( &v1, &v2 ); }
inline VEC4* VEC4Maximize(VEC4* pOut, const VEC4& v1, const VEC4& v2) { return VEC4Maximize( pOut, &v1, &v2 ); }
inline VEC4* VEC4Minimize(VEC4* pOut, const VEC4& v1, const VEC4& v2) { return VEC4Minimize( pOut, &v1, &v2 ); }


}  // namespace math
}  // namespace nn

#pragma pop

#endif

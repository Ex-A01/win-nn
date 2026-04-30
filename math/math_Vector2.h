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

#ifndef NN_MATH_MATH_VECTOR2_H_
#define NN_MATH_MATH_VECTOR2_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct VEC2;
struct MTX23;

/*!
@name 2D Vectors
    @{
*/
/*!--------------------------------------------------------------------------*
@brief Calculates a sum of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Add(VEC2* pOut, const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the square of a distance between two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the square of the distance between <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 VEC2DistSq(const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates an inner product of two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the inner product of <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 VEC2Dot(const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Determines whether a vector is the zero vector.

@param[in] p  Pointer to the vector to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is a zero vector, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool VEC2IsZero(const VEC2* p);

/*!--------------------------------------------------------------------------*
@brief Calculates the vector length.

@param[in] p  Pointer to the input vector.

@return Returns the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 VEC2Len(const VEC2* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a square of a vector length.

@param[in] p  Pointer to the input vector.

@return Returns the square of the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32 VEC2LenSq(const VEC2* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a linear interpolation between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the vector taken as the start point of the linear interpolation
@param[in] p2  Pointer to the vector taken as the end point of the linear interpolation
@param[in] t  Linear interpolation parameter. If 0.0, p1 is the result; if 1.0, p2 is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Lerp(VEC2* pOut, const VEC2* p1, const VEC2* p2, f32 t);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the largest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Maximize(VEC2* pOut, const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the smallest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Minimize(VEC2* pOut, const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Mult(VEC2* pOut, const VEC2* p1, const VEC2* p2);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to target vector 1.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Normalize(VEC2* pOut, const VEC2* p);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.
If normalization fails, sets the specified vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to target vector 1.
@param[in] alt  Vector to set if normalization fails.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2SafeNormalize(VEC2* pOut, const VEC2* p, const VEC2& alt);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar multiple of a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the left-hand value.
@param[in] scale  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Scale(VEC2* pOut, const VEC2* p, f32 scale);

/*!--------------------------------------------------------------------------*
@brief Calculates a difference between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC2* VEC2Sub(VEC2* pOut, const VEC2* p1, const VEC2* p2);

/*!
    @}
*/

NN_MATH_INLINE VEC2* VEC2Transform(VEC2* pOut, const MTX23* pM, const VEC2* pV);

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Vectors
@brief Structure with members in a 2D vector.
 *---------------------------------------------------------------------------*/
struct VEC2_
{
    f32 x;  //!< First member.
    f32 y;  //!< Second column.
};

#pragma diag_suppress 2530
/*!------------------------------------------------------------------------
:category Vectors
@brief A two-dimensional vector class.
   ------------------------------------------------------------------------ */
class VEC2 : public VEC2_
{
public:
    static const int DIMENSION = 2; //!< Number of dimensions.

    //! @brief This is a zero vector.
    static const VEC2& Zero()
    {
        static const VEC2 zero(0.0f, 0.0f);

        return zero;
    }

    //! @brief All of the elements are vectors of <tt>1</tt>.
    static const VEC2& One()
    {
        static const VEC2 one(1.0f, 1.0f);

        return one;
    }

    typedef VEC2 self_type; //!< This class's type.
    typedef f32  value_type; //!< The type of this class's elements.
public:

    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    VEC2() {}
    //! @brief Constructor.
    explicit VEC2(const f32* p) { x = p[0]; y = p[1]; }
    //! @brief Copy constructor.
    VEC2(const VEC2_& v) { x = v.x; y = v.y; }
    //! @brief Constructor.
    VEC2(f32 fx, f32 fy) { x = fx; y = fy; }

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
    self_type& operator += (const self_type& rhs) { x += rhs.x; y += rhs.y; return *this; }

    //! @brief Assigns the values after vector subtraction.
    self_type& operator -= (const self_type& rhs) { x -= rhs.x; y -= rhs.y; return *this; }

    //! @brief Assigns the values of the multiplied vector.
    self_type& operator *= (f32 f) { x *= f; y *= f; return *this; }

    //! @brief Assigns values multiplied by each vector element.
    self_type& operator *= (const self_type& rhs) { x *= rhs.x; y *= rhs.y; return *this; }

    //! @brief Assigns the values after vector division.
    self_type& operator /= (f32 f) { f32 r = 1.f / f; x *= r; y *= r; return *this; }

    //! @brief Returns its own vector.
    self_type operator + () const { return *this; }

    //! @brief Returns the inverse of the vector.
    self_type operator - () const { return self_type(-x, -y); }

    //! @brief Returns the result of vector addition.
    self_type operator + (const self_type& rhs) const { return self_type(x + rhs.x, y + rhs.y); }

    //! @brief Returns the vector subtraction result.
    self_type operator - (const self_type& rhs) const { return self_type(x - rhs.x, y - rhs.y); }

    //! @brief Returns the result of vector multiplication.
    self_type operator * (f32 f) const { return self_type(f * x, f * y); }

    //! @brief Returns the result of vector division.
    self_type operator / (f32 f) const { f32 r = 1.f / f; return self_type(r * x, r * y); }

    //! @brief Linearly interpolates between two vectors and sets the result.
    //!
    //! @param[in] lhs  Vector to take as the starting point of the linear interpolation.
    //! @param[in] rhs  Vector to take as the ending point of the liner interpolation.
    //! @param[in] t  Linear interpolation parameter. The result is <span class="argument">lhs</span> when this is <tt>0.0</tt> and <span class="argument">rhs</span> when this is <tt>1.0</tt>.
    //!
    self_type& Lerp(const VEC2& lhs, const VEC2& rhs, f32 t)
    {
        return *VEC2Lerp(this, &lhs, &rhs, t);
    }

    //! @brief Calculates the dot product with the specified vector.
    //!
    //! @param[in] vec  The vector to use to calculate the dot product.
    //!
    f32 Dot(const VEC2& vec) const
    {
        return VEC2Dot(this, &vec);
    }

    //! @brief Calculates a square of a vector length.
    f32 LenSq() const { return x * x + y * y; }

    //! @brief Calculates a square of a vector length.
    f32 LengthSquare() const { return x * x + y * y; }

    //! @brief Calculates the vector length.
    f32 Length() const { return FSqrt(this->x * this->x + this->y * this->y); }

    //! @brief Normalizes a vector.
    self_type& Normalize()
    {
        return *VEC2Normalize(this, this);
    }

    //! @brief Normalizes a vector.
    //!        If normalization fails, sets the specified vector.
    //!
    //! @param[in] alt  Vector to set if normalization fails.
    self_type& SafeNormalize(const VEC2& alt)
    {
        return *VEC2SafeNormalize(this, this, alt);
    }

    //! @brief Calculates the squared distance to the specified vector.
    //!
    //! @param[in] vec  Vector whose distance you want to calculate.
    f32 DistanceSquare(const VEC2& vec) const
    {
        return VEC2DistSq(this, &vec);
    }

    //! @brief Creates the vector formed by the larger of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the maximum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the maximum values.
    self_type& Maximize(const VEC2& lhs, const VEC2& rhs)
    {
        return *VEC2Maximize(this, &lhs, &rhs);
    }

    //! @brief Creates the vector formed by the smaller of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the minimum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the minimum values.
    self_type& Minimize(const VEC2& lhs, const VEC2& rhs)
    {
        return *VEC2Minimize(this, &lhs, &rhs);
    }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{

    //! @brief Sets values individually.
    void Set(f32 fx, f32 fy) { x = fx; y = fy; }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return x == rhs.x && y == rhs.y; }

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator != (const self_type& rhs) const { return x != rhs.x || y != rhs.y; }

    //! @brief Returns <tt>true</tt> if this is a zero vector.
    bool IsZero() const { return VEC2IsZero(this); }
    //@}

    //! @brief Outputs the state.
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};
#pragma diag_default 2530

//! @name Vectors
//@{

//! Alternate name for <tt>VEC2</tt>.
typedef class VEC2 Vector2;

//@}

/* ------------------------------------------------------------------------
Function for VEC2
   ------------------------------------------------------------------------ */
NN_MATH_INLINE VEC2*
VEC2Add(VEC2* pOut, const VEC2* p1, const VEC2* p2) 
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );

    pOut->x = p1->x + p2->x; pOut->y = p1->y + p2->y; 
    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2Sub(VEC2* pOut, const VEC2* p1, const VEC2* p2) 
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );

    pOut->x = p1->x - p2->x; pOut->y = p1->y - p2->y; 
    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2Mult(VEC2* pOut, const VEC2* p1, const VEC2* p2)
{
    pOut->x = p1->x * p2->x;
    pOut->y = p1->y * p2->y;
    return pOut;
}


NN_MATH_INLINE VEC2*
VEC2Scale(VEC2* pOut, const VEC2* p, f32 scale)
{
    NN_NULL_ASSERT( pOut );
    NN_NULL_ASSERT( p );

    pOut->x = p->x * scale; pOut->y = p->y * scale;
    return pOut;
}

NN_MATH_INLINE VEC2*
VEC2Lerp(VEC2* pOut, const VEC2* p1, const VEC2* p2, f32 t)
{
    // (1-t)*p1 + t*p2
    pOut->x = p1->x + t * (p2->x - p1->x);
    pOut->y = p1->y + t * (p2->y - p1->y);
    return pOut;
}

NN_MATH_INLINE f32
VEC2Dot(const VEC2* p1, const VEC2* p2) 
{
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );

    return p1->x * p2->x + p1->y * p2->y;
}

NN_MATH_INLINE f32
VEC2LenSq(const VEC2* p)
{
    NN_NULL_ASSERT( p );
    return p->x * p->x + p->y * p->y;
}

NN_MATH_INLINE f32
VEC2Len(const VEC2* p) { return FSqrt(p->x * p->x + p->y * p->y); }

NN_MATH_INLINE f32
VEC2DistSq(const VEC2* p1, const VEC2* p2) { VEC2 tmp; return VEC2LenSq(VEC2Sub(&tmp, p1, p2)); }

NN_MATH_INLINE VEC2
operator * (f32 f, const VEC2& rhs) { return VEC2(f * rhs.x, f * rhs.y); }

}  // namespace math
}  // namespace nn

#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Vector2.ipp>
#endif

namespace nn {
namespace math {

//Overload referencing the -- const argument.
inline bool VEC2IsZero(const VEC2& v){ return VEC2IsZero( &v ); }
inline VEC2* VEC2Add(VEC2* pOut, const VEC2& p1, const VEC2& p2) { return VEC2Add(pOut, &p1, &p2); }
inline VEC2* VEC2Sub(VEC2* pOut, const VEC2& v1, const VEC2& v2) { return VEC2Sub(pOut, &v1, &v2); }
inline VEC2* VEC2Mult(VEC2* pOut, const VEC2& v1, const VEC2& v2) { return VEC2Mult(pOut, &v1, &v2); }
inline VEC2* VEC2Scale(VEC2* pOut, const VEC2& v, f32 scale) { return VEC2Scale(pOut, &v, scale); }
inline VEC2* VEC2Lerp(VEC2* pOut, const VEC2& v1, const VEC2& v2, f32 t) { return VEC2Lerp(pOut, &v1, &v2, t); }
inline f32 VEC2Dot(const VEC2& v1, const VEC2& v2) { return VEC2Dot(&v1, &v2); }
inline f32 VEC2LenSq(const VEC2& v) { return VEC2LenSq( &v ); }
inline f32 VEC2Len(const VEC2& v) { return VEC2Len( &v ); }
inline f32 VEC2DistSq(const VEC2& v1, const VEC2& v2) { return VEC2DistSq( &v1, &v2 ); }

inline VEC2* VEC2Maximize(VEC2* pOut, const VEC2& v1, const VEC2& v2) { return VEC2Maximize( pOut, &v1, &v2 ); }
inline VEC2* VEC2Minimize(VEC2* pOut, const VEC2& v1, const VEC2& v2) { return VEC2Minimize( pOut, &v1, &v2 ); }
inline VEC2* VEC2Normalize(VEC2* pOut, const VEC2& v) { return VEC2Normalize( pOut, &v ); }
inline VEC2* VEC2SafeNormalize(VEC2* pOut, const VEC2& v, const VEC2& alt) { return VEC2SafeNormalize( pOut, &v, alt ); }

}  // namespace math
}  // namespace nn

#pragma pop

#endif

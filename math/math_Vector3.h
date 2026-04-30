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

#ifndef NN_MATH_MATH_VECTOR3_H_
#define NN_MATH_MATH_VECTOR3_H_

#include <cstring>
#include <nn/math/math_Config.h>
#include <nn/math/math_Constant.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct VEC3;
struct MTX33;
struct MTX34;

/*!
@name 3D Vectors
    @{
*/
// Transformed as (x, y, z, 0).
/*!--------------------------------------------------------------------------*
@brief Calculates a sum of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline VEC3* VEC3Add(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the cross product of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Cross(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the distance between two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the distance between <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
inline f32   VEC3Dist(const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates an inner product of two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the inner product of <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
inline f32   VEC3Dot(const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Determines whether a vector is the zero vector.

@param[in] p  Pointer to the vector to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is a zero vector, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool VEC3IsZero(const VEC3* p);

/*!--------------------------------------------------------------------------*
@brief Calculates the vector length.

@param[in] p  Pointer to the input vector.

@return Returns the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
inline f32   VEC3Len(const VEC3* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a linear interpolation between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the vector taken as the start point of the linear interpolation
@param[in] p2  Pointer to the vector taken as the end point of the linear interpolation
@param[in] t  Linear interpolation parameter. If <tt>0.0</tt>, <span class="argument">p1</span> is the result; if <tt>1.0</tt>, <span class="argument">p2</span> is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline VEC3* VEC3Lerp(VEC3* pOut, const VEC3* p1, const VEC3* p2, f32 t);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the largest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Maximize(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a vector consisting of the smallest component of two other vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to target vector 1.
@param[in] p2  Pointer to target vector 2.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Minimize(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline VEC3* VEC3Mult(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the input vector.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3Normalize(VEC3* pOut, const VEC3* p);

/*!--------------------------------------------------------------------------*
@brief Normalizes a vector.
If normalization fails, sets the specified vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the input vector.
@param[in] alt  Vector to set if normalization fails.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE VEC3* VEC3SafeNormalize(VEC3* pOut, const VEC3* p, const VEC3& alt);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar multiple of a vector.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same vector as <span class="argument">p</span>.
@param[in] p  Pointer to the left-hand value.
@param[in] scale  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline VEC3* VEC3Scale(VEC3* pOut, const VEC3* p, f32 scale);

/*!--------------------------------------------------------------------------*
@brief Calculates the square of a distance between two vectors.

@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns the square of the distance between <span class="argument">p1</span> and <span class="argument">p2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   VEC3SquareDist(const VEC3* p1, const VEC3* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates a square of a vector length.

@param[in] p  Pointer to the input vector.

@return Returns the square of the length of <span class="argument">p</span>.
 *---------------------------------------------------------------------------*/
inline f32   VEC3SquareLen(const VEC3* p);

/*!--------------------------------------------------------------------------*
@brief Calculates a difference between two vectors.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same vector may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
inline VEC3* VEC3Sub(VEC3* pOut, const VEC3* p1, const VEC3* p2);

/*!
    @}
*/

NN_FORCE_INLINE VEC3* VEC3Normalize(VEC3* pOut, const VEC3* p);

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Vectors
@brief Structure with members in a 3D vector.
 *---------------------------------------------------------------------------*/
struct VEC3_
{
    f32 x;  //!< First member.
    f32 y;  //!< Second column.
    f32 z;  //!< Third member.
};

/*!------------------------------------------------------------------------
:category Vectors
@brief A three-dimensional vector class.
   ------------------------------------------------------------------------ */
class VEC3 : public VEC3_
{
public:
    static const int DIMENSION = 3; //!< Number of dimensions.

    //! @brief This is a zero vector.
    static const VEC3& Zero()
    {
        static const VEC3 zero(0.0f, 0.0f, 0.0f);
        
        return zero;
    }
    
    //! @brief All of the elements are vectors of <tt>1</tt>.
    static const VEC3& One()
    {
        static const VEC3 one(1.0f, 1.0f, 1.0f);
        
        return one;
    }

    typedef VEC3 self_type; //!< This class's type.
    typedef f32  value_type; //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    VEC3() {}
    explicit VEC3(const f32* p) { x = p[0]; y = p[1]; z = p[2]; }
    //! @brief Copy constructor.
    VEC3(const VEC3_& v) { x = v.x; y = v.y; z = v.z; }
    //! @brief Constructor.
    VEC3(f32 fx, f32 fy, f32 fz) { x = fx; y = fy; z = fz; }
    //! @brief Constructor.
    explicit VEC3(const VEC2& v) { x = v.x; y = v.y; z = 0.0f; }

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

    //! @brief Vector addition operation.
    self_type& operator += (const self_type& rhs) { (void)VEC3Add(this, this, &rhs); return *this; }

    //! @brief Vector subtraction operation.
    self_type& operator -= (const self_type& rhs) { (void)VEC3Sub(this, this, &rhs); return *this; }

    //! @brief Vector multiplication operation.
    self_type& operator *= (f32 f) { (void)VEC3Scale(this, this, f); return *this; }

    //! @brief Multiplies by each vector element.
    self_type& operator *= (const self_type& rhs) { (void)VEC3Mult(this, this, &rhs); return *this; }

    //! @brief Vector division operation.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }

    //! @brief Returns its own vector.
    self_type operator + () const { return *this; }

    //! @brief Returns the inverse of the vector.
    self_type operator - () const { return self_type(-x, -y, -z); }

    // The best implementation for binary operators differs depending on whether return values are optimized.
    //! @brief Returns the result of vector addition.
    self_type operator + (const self_type& rhs) const { VEC3 tmp; (void)VEC3Add(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the vector subtraction result.
    self_type operator - (const self_type& rhs) const { VEC3 tmp; (void)VEC3Sub(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the result of vector multiplication.
    self_type operator * (f32 f) const { VEC3 tmp; (void)VEC3Scale(&tmp, this, f); return tmp; }

    //! @brief Returns the result of vector division.
    self_type operator / (f32 f) const { f32 r = 1.f / f; return operator*(r); }

    //! @brief Linearly interpolates between two vectors and sets the result.
    //!
    //! @param[in] lhs  Vector to take as the starting point of the linear interpolation.
    //! @param[in] rhs  Vector to take as the ending point of the liner interpolation.
    //! @param[in] t  Linear interpolation parameter. The result is <span class="argument">lhs</span> when this is <tt>0.0</tt> and <span class="argument">rhs</span> when this is <tt>1.0</tt>.
    //!
    self_type& Lerp(const VEC3& lhs, const VEC3& rhs, f32 t)
    {
        return *VEC3Lerp(this, &lhs, &rhs, t);
    }

    //! @brief Calculates the dot product with the specified vector.
    //! 
    //! @param[in] vec  The vector to use to calculate the dot product.
    //!
    f32 Dot(const VEC3& vec) const
    {
        return VEC3Dot(this, &vec);
    }

    //! @brief Calculates a square of a vector length.
    //! Use of this function is not recommended because it may be removed in the future.
    //! We recommend that you use <tt>LengthSquare</tt> instead.
    f32 LenSq() const { return VEC3SquareLen(this); }

    //! @brief Calculates a square of a vector length.
    f32 LengthSquare() const { return VEC3SquareLen(this); }

    //! @brief Calculates the vector length.
    f32 Length() const { return VEC3Len(this); }

    //! @brief Normalizes a vector.
    self_type& Normalize()
    {
        return *VEC3Normalize(this, this);
    }

    //! @brief Normalizes a vector.
    //!        If normalization fails, sets the specified vector.
    //!
    //! @param[in] alt  Vector to set if normalization fails.
    self_type& SafeNormalize(const VEC3& alt)
    {
        return *VEC3SafeNormalize(this, this, alt);
    }

    //! @brief Calculates the squared distance to the specified vector.
    //!
    //! @param[in] vec  Vector whose distance you want to calculate.
    f32 DistanceSquare(const VEC3& vec) const
    {
        return VEC3SquareDist(this, &vec);
    }

    //! @brief Creates the vector formed by the larger of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the maximum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the maximum values.
    self_type& Maximize(const VEC3& lhs, const VEC3& rhs)
    {
        return *VEC3Maximize(this, &lhs, &rhs);
    }

    //! @brief Creates the vector formed by the smaller of each component of two input vectors.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the minimum values.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the minimum values.
    self_type& Minimize(const VEC3& lhs, const VEC3& rhs)
    {
        return *VEC3Minimize(this, &lhs, &rhs);
    }

    //! @brief Calculates the cross product of two vectors and sets the result.
    //!
    //! @param[in] lhs  The <span class="argument">lhs</span> vector represents the left side of the equation that calculates the cross product.
    //! @param[in] rhs  The <span class="argument">rhs</span> vector represents the right side of the equation that calculates the cross product.
    self_type& Cross(const VEC3& lhs, const VEC3& rhs)
    {
        return *VEC3Cross(this, &lhs, &rhs);
    }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{
    
    //! @brief Sets values individually.
    void Set(f32 fx, f32 fy, f32 fz) { x = fx; y = fy; z = fz; }
    
    //! @brief  Sets values.
    void Set(const self_type& value) { x = value.x; y = value.y; z = value.z; }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{
    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z; }

    //! @brief Returns <tt>true</tt> if this is a zero vector.
    bool IsZero() const { return VEC3IsZero(this); }

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

//! Alternate name for <tt>VEC3</tt>.
typedef class VEC3 Vector3;

//@}

/* ------------------------------------------------------------------------
Function for VEC3
   ------------------------------------------------------------------------ */
inline VEC3*
VEC3Add(VEC3* pOut, const VEC3* p1, const VEC3* p2)
{
    pOut->x = p1->x + p2->x;
    pOut->y = p1->y + p2->y;
    pOut->z = p1->z + p2->z;
    return pOut;
}

inline VEC3*
VEC3Sub(VEC3* pOut, const VEC3* p1, const VEC3* p2)
{
    pOut->x = p1->x - p2->x;
    pOut->y = p1->y - p2->y;
    pOut->z = p1->z - p2->z;
    return pOut;
}

inline VEC3*
VEC3Mult(VEC3* pOut, const VEC3* p1, const VEC3* p2)
{
    pOut->x = p1->x * p2->x;
    pOut->y = p1->y * p2->y;
    pOut->z = p1->z * p2->z;
    return pOut;
}

inline VEC3*
VEC3Scale(VEC3* pOut, const VEC3* p, f32 scale)
{
    pOut->x = scale * p->x;
    pOut->y = scale * p->y;
    pOut->z = scale * p->z;
    return pOut;
}

inline VEC3*
VEC3Lerp(VEC3* pOut, const VEC3* p1, const VEC3* p2, f32 t)
{
    pOut->x = p1->x + t * (p2->x - p1->x);
    pOut->y = p1->y + t * (p2->y - p1->y);
    pOut->z = p1->z + t * (p2->z - p1->z);
    return pOut;
}

inline f32
VEC3Dot(const VEC3* p1, const VEC3* p2)
{
    return p1->x * p2->x + p1->y * p2->y + p1->z * p2->z;
}

inline f32
VEC3Len(const VEC3* p)
{
    NN_NULL_ASSERT( p );
    
    return ::std::sqrtf( VEC3SquareLen( p ) );
}

inline f32
VEC3SquareLen(const VEC3* p)
{
    return p->x * p->x + p->y * p->y + p->z * p->z;
}

inline f32
VEC3Dist( const VEC3* p1, const VEC3* p2 )
{
    NN_NULL_ASSERT( p1 );
    NN_NULL_ASSERT( p2 );
    
    return ::std::sqrtf( VEC3SquareDist( p1, p2 ) );
}


inline VEC3
operator * (f32 f, const VEC3& rhs) { VEC3 tmp; (void)VEC3Scale(&tmp, &rhs, f); return tmp; }

}  // namespace math
}  // namespace nn

#include <nn/math/ARMv6/math_Vector3.h>

namespace nn { 
namespace math {

NN_FORCE_INLINE VEC3*
VEC3Normalize(VEC3* pOut, const VEC3* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (VEC3NORMALIZE__CONFIG == D_ORG)
        return ARMv6::VEC3NormalizeC(pOut, p);
    #elif (VEC3NORMALIZE__CONFIG == D_FAST_C)
        return ARMv6::VEC3NormalizeC_FAST(pOut, p);
    #elif (VEC3NORMALIZE__CONFIG == D_FAST_ASM)
    #elif (VEC3NORMALIZE__CONFIG == D_FAST_C_ALGO)
    #elif (VEC3NORMALIZE__CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

}  // namespace math
}  // namespace nn



#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Vector3.ipp>
#include <nn/math/ARMv6/inline/math_Vector3.ipp>
#endif

namespace nn { 
namespace math {

//Overload referencing the -- const argument.
inline bool VEC3IsZero(const VEC3& v){ return VEC3IsZero( &v ); }
inline VEC3* VEC3Maximize(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Maximize( pOut, &v1, &v2 ); }
inline VEC3* VEC3Minimize(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Minimize( pOut, &v1, &v2 ); }
inline VEC3* VEC3Cross(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Cross( pOut, &v1, &v2 ); }
inline VEC3* VEC3Normalize(VEC3* pOut, const VEC3& v) { return VEC3Normalize( pOut, &v ); }
inline VEC3* VEC3SafeNormalize(VEC3* pOut, const VEC3& v, const VEC3& alt) { return VEC3SafeNormalize( pOut, &v, alt ); }
inline f32   VEC3SquareDist(const VEC3& v1, const VEC3& v2) { return VEC3SquareDist( &v1, &v2 ); }

inline VEC3* VEC3Add(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Add( pOut, &v1, &v2 ); }
inline VEC3* VEC3Sub(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Sub( pOut, &v1, &v2 ); }
inline VEC3* VEC3Mult(VEC3* pOut, const VEC3& v1, const VEC3& v2) { return VEC3Mult( pOut, &v1, &v2 ); }
inline VEC3* VEC3Scale(VEC3* pOut, const VEC3& v, f32 scale) { return VEC3Scale( pOut, &v, scale ); }
inline VEC3* VEC3Lerp(VEC3* pOut, const VEC3& v1, const VEC3& v2, f32 t) { return VEC3Lerp( pOut, &v1, &v2, t ); }
inline f32   VEC3Dot(const VEC3& v1, const VEC3& v2) { return VEC3Dot( &v1, &v2 ); }
inline f32   VEC3Len(const VEC3& v) { return VEC3Len( &v ); }
inline f32   VEC3SquareLen(const VEC3& v) { return VEC3SquareLen( &v ); }
inline f32   VEC3Dist(const VEC3& v1, const VEC3& v2) { return VEC3Dist( &v1, &v2 ); }

}  // namespace math
}  // namespace nn

#pragma pop

#endif

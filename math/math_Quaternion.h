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

#ifndef NN_MATH_MATH_QUATERNION_H_
#define NN_MATH_MATH_QUATERNION_H_

#include <nn/math/math_Config.h>

namespace nn {
namespace math {

struct QUAT;

/*!
@name Quaternions
    @{
*/

/* ------------------------------------------------------------------------
Function for QUAT
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Calculates a sum of two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the left-hand value.
@param[in] q2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATAdd(QUAT* pOut, const QUAT* q1, const QUAT* q2);

/*!--------------------------------------------------------------------------*
@brief Calculates a quotient of two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the left-hand value.
@param[in] q2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATDivide(QUAT* pOut, const QUAT* q1, const QUAT* q2);

/*!--------------------------------------------------------------------------*
@brief Calculates an inner product of two quaternions.

@param[in] q1  Pointer to the left-hand value.
@param[in] q2  Pointer to the right-hand value.

@return Returns the inner product of <span class="argument">q1</span> and <span class="argument">q2</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE f32   QUATDot(const QUAT* q1, const QUAT* q2);

/*!--------------------------------------------------------------------------*
@brief Calculates the natural logarithm for base e to the power of a given quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
It may point to the same quaternion as <span class="argument">q</span>.
@param[in] q  Pointer to the quaternion to use as the exponent.
Must be a pure quaternion (w=0).

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATExp(QUAT* pOut, const QUAT* q);

/*!--------------------------------------------------------------------------*
@brief Calculates an inverse of a quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same quaternion as <span class="argument">q</span>.
@param[in] q  Pointer to the left-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE QUAT* QUATInverse(QUAT* pOut, const QUAT* __restrict q);

/*!--------------------------------------------------------------------------*
@brief Calculates a linear interpolation between two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the quaternion taken as the start point of the linear interpolation
@param[in] q2  Pointer to the quaternion taken as the end point of the linear interpolation
@param[in] t  Linear interpolation parameter. If <tt>0.0</tt>, <span class="argument">q1</span> is the result; if <tt>1.0</tt>, <span class="argument">q2</span> is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATLerp(QUAT* pOut, const QUAT* q1, const QUAT* q2, f32 t);

/*!--------------------------------------------------------------------------*
@brief Calculates a natural logarithm of a quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
It may point to the same quaternion as <span class="argument">q</span>.
@param[in] q  Pointer to the quaternion to use as the antilogarithm.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATLogN(QUAT* pOut, const QUAT* q);

/*!--------------------------------------------------------------------------*
@brief       Modify <span class="argument">q</span> so that it is on the same side of the hypersphere as <span class="argument">qto</span>.

@param[out]  pOut  Resulting modified quaternion.
@param[in]   q     Quaternion.
@param[in]   qto   Quaternion to be close to.

@return      None.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATMakeClosest( QUAT* pOut, const QUAT *q, const QUAT *qto );

/*!--------------------------------------------------------------------------*
@brief Calculates a product of two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the left-hand value.
@param[in] q2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE QUAT* QUATMult(QUAT* pOut, const QUAT* __restrict q1, const QUAT* __restrict q2);

/*!--------------------------------------------------------------------------*
@brief Normalizes a quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same quaternion as <span class="argument">q</span>.
@param[in] q  Pointer to the quaternion to normalize.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE QUAT* QUATNormalize(QUAT* pOut, const QUAT* __restrict q);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar multiple of a quaternion.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
It may point to the same quaternion as <span class="argument">q</span>.
@param[in] q  Pointer to the left-hand value.
@param[in] scale  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATScale(QUAT* pOut, const QUAT* q, f32 scale);

/*!--------------------------------------------------------------------------*
@brief Calculates the spherical linear interpolation between two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the quaternion taken as the start point of the spherical linear interpolation
@param[in] q2  Pointer to the quaternion taken as the end point of the spherical linear interpolation
@param[in] t  Spherical linear interpolation parameter. If <tt>0.0</tt>, <span class="argument">q1</span> is the result; if <tt>1.0</tt>, <span class="argument">q2</span> is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATSlerp(QUAT* pOut, const QUAT* q1, const QUAT* q2, f32 t);

/*!--------------------------------------------------------------------------*
@brief Calculates a spherical 3D interpolation between two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same quaternion as <span class="argument">p</span>, <span class="argument">a</span>, <span class="argument">b</span>, <span class="argument">q</span>.
@param[in] p  Pointer to the quaternion taken as the start point of the spherical 3D interpolation
@param[in] a  Pointer to the quaternion used to control the spherical 3D interpolation.
@param[in] b  Pointer to the quaternion used to control the spherical 3D interpolation.
@param[in] q  Pointer to the quaternion taken as the end point of the spherical 3D interpolation
@param[in] t  Spherical linear interpolation parameter. If <tt>0.0</tt>, <span class="argument">q1</span> is the result; if <tt>1.0</tt>, <span class="argument">q2</span> is the result.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATSquad(QUAT* pOut, const QUAT* p, const QUAT* a, const QUAT* b, const QUAT* q, f32 t);

/*!--------------------------------------------------------------------------*
@brief Calculates a difference for two quaternions.

@param[out] pOut  Pointer to the buffer that receives the calculation results.
The same quaternion may be specified for both <span class="argument">q1</span> and <span class="argument">q2</span>.
@param[in] q1  Pointer to the left-hand value.
@param[in] q2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATSub(QUAT* pOut, const QUAT* q1, const QUAT* q2);

/*!--------------------------------------------------------------------------*
@brief Configures a quaternion to perform a rotation around an arbitrary axis defined by the (x, y, z) components of <span class="argument">axis</span>.
               

@param[out] pOut  Pointer to the resulting quaternion.
@param[in] axis  Pointer to vector structure holding the components of the axis of rotation.
The <SPAN class="argument">axis</SPAN> argument does not need to be a unit vector.
@param[in] rad  Rotation (in radians). Positive values indicate counterclockwise rotation.

@return      None.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE QUAT* QUATRotAxisRad( QUAT* pOut, const VEC3 *axis, f32 rad );

/*!
    @}
*/

/* ------------------------------------------------------------------------
QUAT
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
:category Quaternions
@brief Structure with members in a quaternion.
 *---------------------------------------------------------------------------*/
struct QUAT_
{
    f32 x;  //!< First member.
    f32 y;  //!< Second column.
    f32 z;  //!< Third member.
    f32 w;  //!< Fourth member.
};

/*!--------------------------------------------------------------------------*
:category Quaternions
@brief Quaternion class.
 *---------------------------------------------------------------------------*/
class QUAT : public QUAT_
{
public:
    typedef QUAT self_type;     //!< This class's type.
    typedef f32  value_type;    //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{
    //! Constructor.
    QUAT() {}
    //! Constructor.
    explicit QUAT(const f32* p) { x = p[0]; y = p[1]; z = p[2]; w = p[3]; }
    //! Copy constructor.
    QUAT(const QUAT_& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; w = rhs.w; }
    //! Constructor.
    QUAT(f32 fx, f32 fy, f32 fz, f32 fw) { x = fx; y = fy; z = fz; w = fw; }

    //@}

    //----------------------------------------
    //! @name Conversions
    //@{

    //! Casts to an <tt>f32</tt>-type value.
    operator f32*() { return &x; }
    //! Casts to an <tt>f32</tt>-type value.
    operator const f32*() const { return &x; }
#if 0
    // The cast operator is put off because the function name is the same as <tt>DolphinSDK</tt>.
    operator Quaternion*() { return (Quaternion*)&x; }
    operator const Quaternion*() const { return (const Quaternion*)&x; }
#endif
    //@}

    //----------------------------------------
    //! @name Operators
    //@{

    //! @brief Assigns the values after quaternion addition.
    self_type& operator += (const self_type& rhs) { (void)QUATAdd(this, this, &rhs); return *this; }

    //! @brief Assigns the values after quaternion subtraction.
    self_type& operator -= (const self_type& rhs) { (void)QUATSub(this, this, &rhs); return *this; }

    //! @brief Assigns the values after quaternion multiplication.
    self_type& operator *= (f32 f) { (void)QUATScale(this, this, f); return *this; }

    //! @brief Assigns the values after quaternion division.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }

    //! @brief Returns its own quaternion.
    self_type operator + () const { return *this; }

    //! @brief Returns the conjugate of the quaternion.
    self_type operator - () const { return self_type(-x, -y, -z, -w); }

    //! @brief Returns the result of quaternion addition.
    self_type operator + (const self_type& rhs) const { QUAT tmp; (void)QUATAdd(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the result after quaternion subtraction.
    self_type operator - (const self_type& rhs) const { QUAT tmp; (void)QUATSub(&tmp, this, &rhs); return tmp; }

    //! @brief Returns the result of quaternion multiplication.
    self_type operator * (f32 f) const { QUAT tmp; (void)QUATScale(&tmp, this, f); return tmp; }

    //! @brief Returns the result of quaternion division.
    self_type operator / (f32 f) const { return operator*(1.f / f); }

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w; }

    //@}

    //! @brief Outputs the state.
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};

//! @name Quaternions
//@{

//! Alternate name for <tt>QUAT</tt>.
typedef class QUAT Quaternion;

//@}

inline QUAT
operator * (f32 f, const QUAT& rhs) { QUAT tmp; (void)QUATScale(&tmp, &rhs, f); return tmp; }

}  // namespace math
}  // namespace nn

#include <nn/math/ARMv6/math_Quaternion.h>

namespace nn { 
namespace math {

NN_FORCE_INLINE QUAT*
QUATInverse(QUAT* pOut, const QUAT* __restrict q)
{
#if defined( NN_HARDWARE_CTR )
    #if (QUATINVERSE_CONFIG == D_ORG)
        return ARMv6::QUATInverseC( pOut, q );
    #elif (QUATINVERSE_CONFIG == D_FAST_C)
        return ARMv6::QUATInverseC_FAST( pOut, q);
    #elif (QUATINVERSE_CONFIG == D_FAST_ASM)
    #elif (QUATINVERSE_CONFIG == D_FAST_C_ALGO)
    #elif (QUATINVERSE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE QUAT*
QUATMult(QUAT* pOut, const QUAT* __restrict q1, const QUAT* __restrict q2)
{
#if defined( NN_HARDWARE_CTR )
    #if (QUATMULT_CONFIG == D_ORG)
        return ARMv6::QUATMultC( pOut, q1, q2);
    #elif (QUATMULT_CONFIG == D_FAST_C)
        return ARMv6::QUATMultC_FAST( pOut, q1, q2);
    #elif (QUATMULT_CONFIG == D_FAST_ASM)
        return ARMv6::QUATMultAsm( pOut, q1, q2);
    #elif (QUATMULT_CONFIG == D_FAST_C_ALGO)
    #elif (QUATMULT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE QUAT*
QUATNormalize(QUAT* pOut, const QUAT* __restrict q)
{
#if defined( NN_HARDWARE_CTR )
    #if (QUATNORMALIZE_CONFIG == D_ORG)
        return ARMv6::QUATNormalizeC( pOut, q );
    #elif (QUATNORMALIZE_CONFIG == D_FAST_C)
        return ARMv6::QUATNormalizeC_FAST( pOut, q);
    #elif (QUATNORMALIZE_CONFIG == D_FAST_ASM)
    #elif (QUATNORMALIZE_CONFIG == D_FAST_C_ALGO)
    #elif (QUATNORMALIZE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

}  // namespace math
}  // namespace nn


#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Quaternion.ipp>
#include <nn/math/ARMv6/inline/math_Quaternion.ipp>
#endif

namespace nn {
namespace math {

//Overload referencing the -- const argument.
inline QUAT* QUATAdd(QUAT* pOut, const QUAT& q1, const QUAT& q2) { return QUATAdd( pOut, &q1, &q2 ); }
inline QUAT* QUATSub(QUAT* pOut, const QUAT& q1, const QUAT& q2) { return QUATSub( pOut, &q1, &q2 ); }
inline QUAT* QUATDivide(QUAT* pOut, const QUAT& q1, const QUAT& q2) { return QUATDivide( pOut, &q1, &q2 ); }
inline QUAT* QUATMult(QUAT* pOut, const QUAT& q1, const QUAT& q2) { return QUATMult( pOut, &q1, &q2 ); }
inline f32   QUATDot(const QUAT& q1, const QUAT& q2) { return QUATDot( &q1, &q2 ); }
inline QUAT* QUATInverse(QUAT* pOut, const QUAT& q) { return QUATInverse( pOut, &q ); }
inline QUAT* QUATScale(QUAT* pOut, const QUAT& q, f32 scale) { return QUATScale( pOut, &q, scale ); }
inline QUAT* QUATNormalize(QUAT* pOut, const QUAT& q) { return QUATNormalize( pOut, &q ); }
inline QUAT* QUATExp(QUAT* pOut, const QUAT& q) { return QUATExp( pOut, &q ); }
inline QUAT* QUATLogN(QUAT* pOut, const QUAT& q) { return QUATLogN( pOut, &q ); }
inline QUAT* QUATLerp(QUAT* pOut, const QUAT& q1, const QUAT& q2, f32 t) { return QUATLerp( pOut, &q1, &q2, t ); }
inline QUAT* QUATSlerp(QUAT* pOut, const QUAT& q1, const QUAT& q2, f32 t) { return QUATSlerp( pOut, &q1, &q2, t ); }
inline QUAT* QUATSquad(QUAT* pOut, const QUAT& p, const QUAT& a, const QUAT& b, const QUAT& q, f32 t) { return QUATSquad( pOut, &p, &a, &b, &q, t ); }

inline QUAT* QUATMakeClosest( QUAT*  pOut, const QUAT& q, const QUAT& qto ) { return QUATMakeClosest( pOut, &q, &qto ); }
inline QUAT* QUATRotAxisRad( QUAT* pOut, const VEC3& axis, f32 rad ) { return QUATRotAxisRad( pOut, &axis, rad ); }

}  // namespace math
}  // namespace nn


#endif // NN_MATH_MATH_QUATERNION_H_

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

#ifndef NN_MATH_MATH_MATRIX43_H_
#define NN_MATH_MATH_MATRIX43_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn { 
namespace math {

struct MTX43;

/*!
@name 4x3 Matrices
    @{
*/

/* ------------------------------------------------------------------------
Function for MTX43
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Calculates the sum of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX43* MTX43Add(MTX43* pOut, const MTX43* p1, const MTX43* p2);

/*!--------------------------------------------------------------------------*
@brief Copies a matrix.

@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix to copy from.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX43* MTX43Copy(MTX43* pOut, const MTX43* p);

/*!--------------------------------------------------------------------------*
@brief Creates an identity matrix.

@param[out] pOut  Pointer to the buffer that stores the identity matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX43* MTX43Identity(MTX43* pOut);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is a unitary matrix.

@param[in] p  Pointer to the matrix to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is the identity matrix, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool   MTX43IsIdentity(const MTX43* p);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX43* MTX43Mult(MTX43* pOut, const MTX43* p1, const MTX43* p2);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a scalar value.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as p.
@param[in] p  Pointer to the original matrix.
@param[in] f  Scalar value by which to multiply.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX43* MTX43Mult(MTX43* pOut, const MTX43* p, f32 f);

/*!--------------------------------------------------------------------------*
@brief Calculates the difference of two matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX43* MTX43Sub(MTX43* pOut, const MTX43* p1, const MTX43* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.

@param[out] pOut  Pointer to the buffer that stores the zero matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX43* MTX43Zero(MTX43* pOut);
/*!
    @}
*/
/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 4 x 3 matrix.
 *---------------------------------------------------------------------------*/
struct MTX43_
{
    //! @brief Matrix element.
    struct BaseData
    {
        f32 _00;    //!< 1 x 1
        f32 _01;    //!< 1 x 2
        f32 _02;    //!< 1 x 3
        f32 _10;    //!< 2 x 1
        f32 _11;    //!< 2 x 2
        f32 _12;    //!< 2 x 3
        f32 _20;    //!< 3 x 1
        f32 _21;    //!< 3 x 2
        f32 _22;    //!< 3 x 3
        f32 _30;    //!< 4 x 1
        f32 _31;    //!< 4 x 2
        f32 _32;    //!< 4 x 3
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
            f32 _00, _01, _02;
            f32 _10, _11, _12;
            f32 _20, _21, _22;
            f32 _30, _31, _32;
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[4][3];    //!< Matrix elements represented as a 2D array.
        f32 a[12];      //!< Matrix elements represented as an array.
        VEC3_ v[4];     //!< Matrix elements represented as a <tt>@ref VEC3_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 4x3 matrix class.
 *---------------------------------------------------------------------------*/
class MTX43 : public MTX43_
{
public:
    static const int ROW_COUNT = 4; //!< The number of rows.
    static const int COLUMN_COUNT = 3; //!< The number of columns.

    //! @brief The identity matrix.
    static const MTX43& Identity()
    {
        static const MTX43 identity(
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f);
        
        return identity;
    }
    typedef MTX43 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.

public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX43() {}
    
    //! @brief Constructor.
    explicit MTX43(const f32* p) { (void)MTX43Copy(this, (MTX43*)p); }
    
    //! @brief Constructor.
    MTX43(f32 x00, f32 x01, f32 x02,
          f32 x10, f32 x11, f32 x12,
          f32 x20, f32 x21, f32 x22,
          f32 x30, f32 x31, f32 x32)
    {
        f._00 = x00; f._01 = x01; f._02 = x02;
        f._10 = x10; f._11 = x11; f._12 = x12;
        f._20 = x20; f._21 = x21; f._22 = x22;
        f._30 = x30; f._31 = x31; f._32 = x32;
    }
    //@}

    //----------------------------------------
    //! @name Conversions
    //@{

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator f32*() { return this->a; }
    //! @brief Casts to an <tt>f32</tt>-type value.
    operator const f32*() const { return this->a; }

    //! @brief Gets a row as a <tt>VEC3</tt> value.
    VEC3& GetRow(int index)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<VEC3*>(&this->v[index]);
    }
    
    //! @brief Gets a row as a <tt>VEC3</tt> value.
    const VEC3& GetRow(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<const VEC3*>(&this->v[index]);
    }
    
    //! @brief Gets a column as a <tt>VEC4</tt> value.
    VEC4 GetColumn(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        VEC4 column;
        column.x = this->m[0][index];
        column.y = this->m[1][index];
        column.z = this->m[2][index];
        column.w = this->m[3][index];
        return column;
    }
    
    //! @brief Sets a column as a <tt>VEC4</tt> value.
    void SetColumn(int index, const VEC4& column)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        this->m[0][index] = column.x;
        this->m[1][index] = column.y;
        this->m[2][index] = column.z;
        this->m[3][index] = column.w;
    }

    //@}

    //----------------------------------------
    //! @name Operators
    //@{

    //! @brief Assigns the values after matrix addition.
    self_type& operator += (const self_type& rhs) { return *MTX43Add(this, this, &rhs); }

    //! @brief Assigns the values after matrix subtraction.
    self_type& operator -= (const self_type& rhs) { return *MTX43Sub(this, this, &rhs); }
    
    //! @brief Assigns the values of a postmultiplied matrix.
    self_type& operator *= (const self_type& rhs) { return *MTX43Mult(this, this, &rhs); }

    //! @brief Assigns the values after matrix multiplication.
    self_type& operator *= (f32 f) { return *MTX43Mult(this, this, f); }

    //! @brief Assigns the values after matrix division.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }
    
    //! @brief Returns its own matrix.
    self_type operator + () const { return *this; }

    //! @brief Returns the conjugate of the matrix.
    self_type operator - () const 
        {
            return MTX43(-f._00, -f._01, -f._02,
                         -f._10, -f._11, -f._12,
                         -f._20, -f._21, -f._22,
                         -f._30, -f._31, -f._32);
        }

    //! @brief Returns the result of matrix addition.
    self_type operator + (const self_type& rhs) const { MTX43 tmp; return *MTX43Add(&tmp, this, &rhs); }

    //! @brief Returns the result after matrix subtraction.
    self_type operator - (const self_type& rhs) const { MTX43 tmp; return *MTX43Add(&tmp, this, &rhs); }

    //! @brief Returns the result of matrix multiplication.
    self_type operator * (f32 f) const { MTX43 tmp; return *MTX43Mult(&tmp, this, f); }

    //! @brief Returns the result of matrix division.
    self_type operator / (f32 f) const { return *this * (1.f / f); }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{
    
    //! @brief Sets as the identity matrix.
    self_type& SetupIdentity() { return *MTX43Identity(this); }
    
    //@}
    
    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX43)) == 0; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX43)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX43IsIdentity(this); }

    //@}

    //! @brief Outputs the state.
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};
#include <nn/math/ARMv6/math_Matrix43.h>

NN_FORCE_INLINE MTX43* 
MTX43Add(MTX43* pOut, const MTX43* p1, const MTX43* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX43ADD_CONFIG == D_ORG)
        return ARMv6::MTX43AddC(pOut, p1, p2);
    #elif (MTX43ADD_CONFIG == D_FAST_C)
    #elif (MTX43ADD_CONFIG == D_FAST_ASM)
        return ARMv6::MTX43AddAsm(pOut, p1, p2);
    #elif (MTX43ADD_CONFIG == D_FAST_C_ALGO)
    #elif (MTX43ADD_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE MTX43*
MTX43Copy(MTX43* pOut, const MTX43* p) 
{ 
#if defined( NN_HARDWARE_CTR )
    #if (MTX43COPY_CONFIG == D_ORG)
        return ARMv6::MTX43CopyC(pOut, p);
    #elif (MTX43COPY_CONFIG == D_FAST_C)
    #elif (MTX43COPY_CONFIG == D_FAST_ASM)
        return ARMv6::MTX43CopyAsm(pOut, p);
    #elif (MTX43COPY_CONFIG == D_FAST_C_ALGO)
    #elif (MTX43COPY_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE MTX43*
MTX43Mult(MTX43* pOut, const MTX43* p1, const MTX43* p2) 
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX43MULT_43_CONFIG == D_ORG)
        return ARMv6::MTX43MultC(pOut, p1, p2);
    #elif (MTX43MULT_43_CONFIG == D_FAST_C)
    #elif (MTX43MULT_43_CONFIG == D_FAST_ASM)
        return ARMv6::MTX43MultAsm(pOut, p1, p2);
    #elif (MTX43MULT_43_CONFIG == D_FAST_C_ALGO)
    #elif (MTX43MULT_43_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX43* 
MTX43Mult(MTX43* pOut, const MTX43* p, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX43MULT_F32_CONFIG == D_ORG)
        return ARMv6::MTX43MultC(pOut, p, f);
    #elif (MTX43MULT_F32_CONFIG == D_FAST_C)
    #elif (MTX43MULT_F32_CONFIG == D_FAST_ASM)
        return ARMv6::MTX43MultAsm(pOut, p, f);
    #elif (MTX43MULT_F32_CONFIG == D_FAST_C_ALGO)
    #elif (MTX43MULT_F32_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

//! @name Matrices
//@{

//! Alternate name for <tt>MTX43</tt>.
typedef class MTX43 Matrix43;

//@}

//Overload referencing the -- const argument.
inline bool   MTX44IsIdentity(const MTX43& m) { return MTX43IsIdentity( &m ); }
inline MTX43* MTX43Copy(MTX43* pOut, const MTX43& m) { return MTX43Copy( pOut, &m ); }
inline MTX43* MTX43Add(MTX43* pOut, const MTX43& m1, const MTX43& m2) { return MTX43Add( pOut, &m1, &m2 ); }
inline MTX43* MTX43Sub(MTX43* pOut, const MTX43& m1, const MTX43& m2) { return MTX43Sub( pOut, &m1, &m2 ); }
inline MTX43* MTX43Mult(MTX43* pOut, const MTX43& m1, const MTX43& m2) { return MTX43Mult( pOut, &m1, &m2 ); }
inline MTX43* MTX43Mult(MTX43* pOut, const MTX43& m, f32 f) { return MTX43Mult( pOut, &m, f); }

}  // namespace math
}  // namespace nn


#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix43.ipp>
#include <nn/math/ARMv6/inline/math_Matrix43.ipp>
#endif

#pragma pop

#endif

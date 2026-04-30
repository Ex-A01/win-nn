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

#ifndef NN_MATH_MATH_MATRIX23_H_
#define NN_MATH_MATH_MATRIX23_H_

#include <cstring>
#include <nn/math/math_Config.h>
#include <nn/math/math_Vector2.h>
#include <nn/math/math_Vector3.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct MTX23;
struct MTX22;

/*!
@name 2x3 Matrices
    @{
*/

/* ------------------------------------------------------------------------
Function for MTX23
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Adds two 2x3 matrices.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It is not a problem if this points to the same matrix as <span class="argument">p1</span> or <span class="argument">p2</span>.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to add.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Add(MTX23* pOut, const MTX23* p1, const MTX23* p2);

/*!--------------------------------------------------------------------------*
@brief Copies a 2x3 matrix.

@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix from which to copy the data.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Copy(MTX23* pOut, const MTX23* p);

/*!--------------------------------------------------------------------------*
@brief Creates a 2x3 identity matrix.

@param[out] pOut  Pointer to the buffer in which to store the identity matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Identity(MTX23* pOut);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is an identity matrix.

@param[in] p  Matrix to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is an identity matrix.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool   MTX23IsIdentity(const MTX23* p);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a real number and adds another matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] t  Number to multiply by.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to add.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23MAdd(MTX23* pOut, f32 t, const MTX23* p1, const MTX23* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the scalar product of a 2x3 matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. May point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.
@param[in] f  Number to multiply by.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Mult(MTX23* pOut, const MTX23* p, f32 f);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two 2x3 matrices.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Mult(MTX23* pOut, const MTX23* p1, const MTX23* p2);

/*!--------------------------------------------------------------------------*
@brief Translates a 2x3 matrix. Multiply the translation matrix from the right.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It may point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the input matrix.
@param[in] pT  Pointer to the vector that stores the amount of translation along the direction of each axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23MultTranslate(MTX23* pOut, const MTX23* pM, const VEC2* pT);

/*!--------------------------------------------------------------------------*
@brief Translates a 2x3 matrix. Multiplies the translation matrix from the left.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It may point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the input matrix.
@param[in] pT  Pointer to the vector that stores the amount of translation along the direction of each axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23MultTranslate(MTX23* pOut, const VEC2* pT, const MTX23* pM);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix having the specified center of rotation.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] pCenter  Coordinates of the center of rotation.
@param[in] fIdx  Angle in units for which one complete revolution is defined as equal to 256.0 units.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23RotCenterFIdx(MTX23* pOut, const VEC2* pCenter, f32 fIdx);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation.
@param[in] fIdx  Angle in units for which one complete revolution is defined as equal to 256.0 units.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23RotFIdx(MTX23* pOut, f32 fIdx);

/*!--------------------------------------------------------------------------*
@brief Scales a 2x3 matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It may point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the input matrix.
@param[in] pS  Pointer to the vector that stores the scaling value along the direction of each axis.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Scale(MTX23* pOut, const MTX23* pM, const VEC2* pS);

/*!--------------------------------------------------------------------------*
@brief Subtracts a 2x3 matrix from a 2x3 matrix.

@param[out] pOut  Pointer to the buffer that receives the result of the calculation. It is not a problem if this points to the same matrix as <span class="argument">p1</span> or <span class="argument">p2</span>.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to subtract.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Sub(MTX23* pOut, const MTX23* p1, const MTX23* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a translation matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Translate(MTX23* pOut, const VEC2* pT);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.

@param[out] pOut  Pointer to the buffer that stores the zero matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX23* MTX23Zero(MTX23* pOut);

/*!
    @}
*/

NN_MATH_INLINE MTX23* MTX22ToMTX23(MTX23* pOut, const MTX22* pM);

/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 2 x 3 matrix.
 *---------------------------------------------------------------------------*/
struct MTX23_
{
    //! @brief Structure with members in a 2 x 3 matrix.
    struct BaseData
    {
        f32 _00;    //!< 1 x 1
        f32 _01;    //!< 1 x 2
        f32 _02;    //!< 1 x 3
        f32 _10;    //!< 2 x 1
        f32 _11;    //!< 2 x 2
        f32 _12;    //!< 2 x 3
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
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[2][3];    //!< Matrix elements represented as a 2D array.
        f32 a[6];       //!< Matrix elements represented as an array.
        VEC3_ v[2];     //!< Matrix elements represented as a <tt>@ref VEC3_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 2x3 matrix class.
 *---------------------------------------------------------------------------*/
class MTX23 : public MTX23_
{
public:
    static const int ROW_COUNT = 2; //!< The number of rows.
    static const int COLUMN_COUNT = 3; //!< The number of columns.

    //! @brief The identity matrix.
    static const MTX23& Identity()
    {
        static const MTX23 identity(
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f);
        
        return identity;
    }

    typedef MTX23 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX23() {}
    //! @brief Constructor.
    explicit MTX23(const f32* p) { (void)MTX23Copy(this, reinterpret_cast<const MTX23*>(p)); }
    //! @brief Constructor.
    explicit MTX23(const MTX22& rhs) { MTX22ToMTX23(this, &rhs); }
    //! @brief Constructor.
    MTX23(f32 x00, f32 x01, f32 x02,
          f32 x10, f32 x11, f32 x12)
    {
        f._00 = x00; f._01 = x01; f._02 = x02;
        f._10 = x10; f._11 = x11; f._12 = x12;
    }

    //@}

    //----------------------------------------
    //! @name Conversions
    //@{

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator f32*() { return this->a; }

    //! @brief Casts to an <tt>f32</tt>-type value.
    operator const f32*() const { return this->a; }

    //! @brief Gets a row as a <tt>VEC2</tt> value.
    VEC3& GetRow(int index)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<VEC3*>(&this->v[index]);
    }
    
    //! @brief Gets a row as a <tt>VEC2</tt> value.
    const VEC3& GetRow(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<const VEC3*>(&this->v[index]);
    }
    
    //! @brief Gets a column as a <tt>VEC3</tt> value.
    VEC2 GetColumn(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        VEC2 column;
        column.x = this->m[0][index];
        column.y = this->m[1][index];
        return column;
    }
    
    //! @brief Sets a column as a <tt>VEC3</tt> value.
    void SetColumn(int index, const VEC2& column)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        this->m[0][index] = column.x;
        this->m[1][index] = column.y;
    }
    //@}

    //----------------------------------------
    //! @name Settings
    //@{
    
    //! @brief Sets as the identity matrix.
    self_type& SetupIdentity() { return *MTX23Identity(this); }
    
    //@}
    
    //----------------------------------------
    //! @name Operators
    //@{

    //! @brief Assigns the values after matrix addition.
    self_type& operator += (const self_type& rhs) { return *MTX23Add(this, this, &rhs); }

    //! @brief Assigns the values after matrix subtraction.
    self_type& operator -= (const self_type& rhs) { return *MTX23Sub(this, this, &rhs); }
    
    //! @brief Assigns the values after matrix multiplication.
    self_type& operator *= (f32 f) { return *MTX23Mult(this, this, f); }

    //! @brief Assigns the values after matrix division.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }

    //! @brief Returns its own matrix.
    self_type operator + () const { return *this; }

    //! @brief Returns the conjugate of the matrix.
    self_type operator - () const
    {
        return MTX23(-f._00, -f._01, -f._02,
                     -f._10, -f._11, -f._12);
    }

    //! @brief Returns the result of matrix addition.
    self_type operator + (const self_type& rhs) const { MTX23 tmp; return *MTX23Add(&tmp, this, &rhs); }

    //! @brief Returns the result after matrix subtraction.
    self_type operator - (const self_type& rhs) const { MTX23 tmp; return *MTX23Sub(&tmp, this, &rhs); }

    //! @brief Returns the result of matrix multiplication.
    self_type operator * (f32 f) const { MTX23 tmp; return *MTX23Mult(&tmp, this, f); }

    //! @brief Returns the result of matrix division.
    self_type operator / (f32 f) const { return *this * (1.f / f); }

    //@}

    //----------------------------------------
    //! @name Settings
    //@{
    
    //! @brief Sets up a scaling matrix.
    //!
    //! @param[in] matrix  Source matrix.
    //! @param[in] scale  Scale value.
    //!
    self_type& SetupScale(const MTX23& matrix, const VEC2& scale)
    {
        return *MTX23Scale(this, &matrix, &scale);
    }

    //! @brief Sets up a translation matrix.
    //!
    //! @param[in] matrix  Source matrix.
    //! @param[in] translate  Translation value.
    //!
    self_type& SetupTranslate(const MTX23& matrix, const VEC2& translate)
    {
        return *MTX23MultTranslate(this, &matrix, &translate);
    }

    //! @brief Sets up a rotation matrix in XYZ order.
    //!
    //! @param[in] rotate  A rotation value. In units of radians.
    //!
    self_type& SetupRotate(f32 rotate)
    {
        return *MTX23RotFIdx(this, NN_MATH_RAD_TO_FIDX(rotate));
        
    }

    //! @brief Sets up a rotation matrix around the specified axis.
    //!
    //! @param[in] center  The base coordinates.
    //! @param[in] rotate  The angle to rotate by. In units of radians.
    //!
    self_type& SetupRotate(const VEC2& center, f32 rotate)
    {
        return *MTX23RotCenterFIdx(this, &center, NN_MATH_RAD_TO_FIDX(rotate));
    }

    //@}
    
    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX23)) == 0; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX23)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX23IsIdentity(this); }
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

//! Alternate name for <tt>MTX23</tt>.
typedef class MTX23 Matrix23;

//@}

}  // namespace math
}  // namespace nn

namespace nn { 
namespace math {

//Overload referencing the -- const argument.

inline MTX23* MTX23Copy(MTX23* pOut, const MTX23& m) { return MTX23Copy( pOut, &m ); }
inline bool   MTX23IsIdentity(const MTX23& m) { return MTX23IsIdentity( &m ); }
inline MTX23* MTX23Add(MTX23* pOut, const MTX23& m1, const MTX23& m2) { return MTX23Add( pOut, &m1, &m2 ); }
inline MTX23* MTX23Sub(MTX23* pOut, const MTX23& m1, const MTX23& m2) { return MTX23Sub( pOut, &m1, &m2 ); }
inline MTX23* MTX23Mult(MTX23* pOut, const MTX23& m, f32 f) { return MTX23Mult( pOut, &m, f ); }
inline MTX23* MTX23Mult(MTX23* pOut, const MTX23& m1, const MTX23& m2) { return MTX23Mult( pOut, &m1, &m2); }
inline MTX23* MTX23Scale(MTX23* pOut, const MTX23& m, const VEC2& vS) { return MTX23Scale( pOut, &m, &vS); }
inline MTX23* MTX23Translate(MTX23* pOut, const VEC2& vT) { return MTX23Translate( pOut, &vT); }
inline MTX23* MTX23MultTranslate(MTX23* pOut, const MTX23& m, const VEC2& vT) { return MTX23MultTranslate( pOut, &m, &vT); }
inline MTX23* MTX23MultTranslate(MTX23* pOut, const VEC2& vT, const MTX23& m) { return MTX23MultTranslate( pOut, &vT, &m); }
inline MTX23* MTX23RotCenterFIdx(MTX23* pOut, const VEC2& vCenter, f32 fIdx) { return MTX23RotCenterFIdx( pOut, &vCenter, fIdx ); }
inline MTX23* MTX23MAdd(MTX23* pOut, f32 t, const MTX23& m1, const MTX23& m2) { return MTX23MAdd( pOut, t, &m1, &m2 ); }

}  // namespace math
}  // namespace nn

#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix23.ipp>
#endif

#pragma pop

#endif

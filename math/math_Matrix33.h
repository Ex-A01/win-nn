#ifndef NN_MATH_MATH_MATRIX33_H_
#define NN_MATH_MATH_MATRIX33_H_

#include <cstring>
#include <nn/math/math_Config.h>
#include <nn/math/math_Vector3.h>
#include <nn/math/ARMv6/math_Matrix33.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct MTX33;
struct MTX34;

/*!
@name 3x3 Matrices
    @{
*/
/* ------------------------------------------------------------------------
Function for MTX33
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Copies a 3x3 matrix.

@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix from which to copy the data.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX33* MTX33Copy(MTX33* pOut, const MTX33* p);

/*!--------------------------------------------------------------------------*
@brief Creates an identity matrix.

@param[out] pOut  Pointer to the buffer that stores the identity matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX33* MTX33Identity(MTX33* pOut);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is a unitary matrix.

@param[in] p  Pointer to the matrix to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is the identity matrix, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool   MTX33IsIdentity(const MTX33* p);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a real number and adds another matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] t  Number to multiply by.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to add.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_FORCE_INLINE MTX33* MTX33MAdd(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two 3x3 matrices.

@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand matrix.
@param[in] p2  Pointer to the right-hand matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
template<typename TMatrix>
NN_FORCE_INLINE TMatrix* MTX33Mult(TMatrix* pOut, const TMatrix* p1, const TMatrix* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.

@param[out] pOut  Pointer to the buffer that stores the zero matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX33* MTX33Zero(MTX33* pOut);

/*!
    @}
*/

NN_MATH_INLINE MTX34* MTX33ToMTX34(MTX34* pOut, const MTX33* pM);
NN_MATH_INLINE MTX33* MTX34ToMTX33(MTX33* pOut, const MTX34* pM);

NN_FORCE_INLINE VEC3* VEC3Transform(VEC3* pOut, const MTX33* pM, const VEC3* pV);

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 3 x 3 matrix.
 *---------------------------------------------------------------------------*/
struct MTX33_
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
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[3][3];    //!< Matrix elements represented as a 2D array.
        f32 a[9];       //!< Matrix elements represented as an array.
        VEC3_ v[3];     //!< Matrix elements represented as a <tt>@ref VEC3_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 3x3 matrix class.
 *---------------------------------------------------------------------------*/
// Exists mainly for the normal matrix.
// For now, only those things that are definitely necessary are implemented.
class MTX33 : public MTX33_
{
public:
    static const int ROW_COUNT = 3; //!< The number of rows.
    static const int COLUMN_COUNT = 3; //!< The number of columns.

    //! @brief The identity matrix.
    static const MTX33& Identity()
    {
        static const MTX33 identity(
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f);

        return identity;
    }

    typedef MTX33 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX33() {}
    //! @brief Constructor.
    explicit MTX33(const f32* p) { MTX33Copy(this, reinterpret_cast<const MTX33*>(p)); }
    //! @brief Constructor.
    explicit MTX33(const MTX34& rhs) { MTX34ToMTX33(this, &rhs); }
    //! @brief Constructor.
    MTX33(f32 x00, f32 x01, f32 x02,
          f32 x10, f32 x11, f32 x12,
          f32 x20, f32 x21, f32 x22)
    {
        f._00 = x00; f._01 = x01; f._02 = x02;
        f._10 = x10; f._11 = x11; f._12 = x12;
        f._20 = x20; f._21 = x21; f._22 = x22;
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
    //! @name Settings
    //@{

    //! @brief Sets as the identity matrix.
    self_type& SetupIdentity() { return *MTX33Identity(this); }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX33)) == 0; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX33)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX33IsIdentity(this); }

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

//! Alternate name for <tt>MTX33</tt>.
typedef class MTX33 Matrix33;

//@}

}  // namespace math
}  // namespace nn


namespace nn {
namespace math {

template<typename TMatrix>
NN_FORCE_INLINE TMatrix*
MTX33Mult(TMatrix* pOut, const TMatrix* p1, const TMatrix* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX33MULT_CONFIG == D_ORG)
        return ARMv6::MTX33MultC( pOut, p1, p2 );
    #elif (MTX33MULT_CONFIG == D_FAST_C)
    #elif (MTX33MULT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX33MultAsm( pOut, p1, p2 );
    #elif (MTX33MULT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX33MULT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif
}

NN_FORCE_INLINE MTX33*
MTX33MAdd(MTX33* pOut, f32 t, const MTX33* p1, const MTX33* p2)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX33MADD_CONFIG == D_ORG)
        return ARMv6::MTX33MAddC(pOut, t, p1, p2);
    #elif (MTX33MADD_CONFIG == D_FAST_C)
        return ARMv6::MTX33MAddC_FAST(pOut, t, p1, p2);
    #elif (MTX33MADD_CONFIG == D_FAST_ASM)
        return ARMv6::MTX33MAddAsm(pOut, t, p1, p2);
    #elif (MTX33MADD_CONFIG == D_FAST_C_ALGO)
    #elif (MTX33MADD_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX33*
MTX33Copy(MTX33* pOut, const MTX33* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX33COPY_CONFIG == D_ORG)
        return ARMv6::MTX33CopyC(pOut, p);
    #elif (MTX33COPY_CONFIG == D_FAST_C)
    #elif (MTX33COPY_CONFIG == D_FAST_ASM)
        return ARMv6::MTX33CopyAsm(pOut, p);
    #elif (MTX33COPY_CONFIG == D_FAST_C_ALGO)
    #elif (MTX33COPY_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE VEC3*
VEC3Transform(VEC3* pOut, const MTX33* pM, const VEC3* pV)
{
#if defined( NN_HARDWARE_CTR )
    #if (VEC3TRANSFORM_33XVEC3_CONFIG == D_ORG)
        return ARMv6::VEC3TransformC(pOut, pM, pV);
    #elif (VEC3TRANSFORM_33XVEC3_CONFIG == D_FAST_C)
    #elif (VEC3TRANSFORM_33XVEC3_CONFIG == D_FAST_ASM)
        return ARMv6::VEC3TransformAsm(pOut, pM, pV);
    #elif (VEC3TRANSFORM_33XVEC3_CONFIG == D_FAST_C_ALGO)
    #elif (VEC3TRANSFORM_33XVEC3_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

//Overload referencing the -- const argument.
template<typename TMatrix>
inline TMatrix* MTX33Mult(TMatrix* pOut, const TMatrix& m1, const TMatrix& m2) { return MTX33Mult( pOut, &m1, &m2 ); }
inline bool   MTX33IsIdentity(const MTX33& m) { return MTX33IsIdentity( &m ); }
inline MTX33* MTX33Copy(MTX33* pOut, const MTX33& m) { return MTX33Copy( pOut, &m ); }
inline MTX33* MTX33MAdd(MTX33* pOut, f32 t, const MTX33& m1, const MTX33& m2) { return MTX33MAdd( pOut, t, &m1, &m2 ); }

}  // namespace math
}  // namespace nn


#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix33.ipp>
#include <nn/math/ARMv6/inline/math_Matrix33.ipp>
#endif

#pragma pop

#endif

#ifndef NN_MATH_MATH_MATRIX22_H_
#define NN_MATH_MATH_MATRIX22_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn {
namespace math {

struct MTX22;
struct MTX23;

/*!
@name 2x2 Matrices
    @{
*/

/* ------------------------------------------------------------------------
Function for MTX22
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Copies a 2x2 matrix.

@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix from which to copy the data.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX22* MTX22Copy(MTX22* pOut, const MTX22* p);

/*!--------------------------------------------------------------------------*
@brief Creates a 2x2 identity matrix.

@param[out] pOut  Pointer to the buffer in which to store the identity matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX22* MTX22Identity(MTX22* pOut);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is a unitary matrix.

@param[in] p  Pointer to the matrix to evaluate.

@return Returns <tt>true</tt> if <span class="argument">p</span> is the identity matrix, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE bool   MTX22IsIdentity(const MTX22* p);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix by a real number and adds another matrix.

@param[out] pOut  Pointer to the buffer that receives the calculation results. It is not a problem if this points to the same matrix as <span class="argument">p1</span> or <span class="argument">p2</span>.
@param[in] t  Number to multiply by.
@param[in] p1  Pointer to the original matrix.
@param[in] p2  Pointer to the matrix to add.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX22* MTX22MAdd(MTX22* pOut, f32 t, const MTX22* p1, const MTX22* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.

@param[out] pOut  Pointer to the buffer that stores the zero matrix.

@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------*/
NN_MATH_INLINE MTX22* MTX22Zero(MTX22* pOut);

/*!
    @}
*/

NN_MATH_INLINE MTX22* MTX23ToMTX22(MTX22* pOut, const MTX23* pM);

/* =======================================================================
Class Definitions
   ======================================================================== */
/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 2 x 2 matrix.
 *---------------------------------------------------------------------------*/
struct MTX22_
{
    //! @brief Matrix element.
    struct BaseData
    {
        f32 _00;    //!< 1 x 1
        f32 _01;    //!< 1 x 2
        f32 _10;    //!< 2 x 1
        f32 _11;    //!< 2 x 2
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
            f32 _00, _01;
            f32 _10, _11;
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[2][2];    //!< Matrix elements represented as a 2D array.
        f32 a[4];       //!< Matrix elements represented as an array.
        VEC2_ v[2];     //!< Matrix elements represented as a <tt>@ref VEC2_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 2x2 matrix class.
 *---------------------------------------------------------------------------*/
class MTX22 : public MTX22_
{
public:
    static const int ROW_COUNT = 2; //!< The number of rows.
    static const int COLUMN_COUNT = 2; //!< The number of columns.

    //! @brief The identity matrix.
    static const MTX22& Identity()
    {
        static const MTX22 identity(
            1.0f, 0.0f,
            0.0f, 1.0f);

        return identity;
    }

    typedef MTX22 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.
public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX22() {}
    //! @brief Constructor.
    explicit MTX22(const f32* p);
    //! @brief Constructor.
    explicit MTX22(const MTX23& rhs);
    //! @brief Constructor.
    MTX22(f32 x00, f32 x01, 
          f32 x10, f32 x11)
    {
        f._00 = x00; f._01 = x01;
        f._10 = x10; f._11 = x11;
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
    VEC2& GetRow(int index)
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<VEC2*>(&this->v[index]);
    }

    //! @brief Gets a row as a <tt>VEC2</tt> value.
    const VEC2& GetRow(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, ROW_COUNT);
        return *reinterpret_cast<const VEC2*>(&this->v[index]);
    }

    //! @brief Gets a column as a <tt>VEC2</tt> value.
    VEC2 GetColumn(int index) const
    {
        NN_MATH_MINMAXLT_ASSERT(index, 0, COLUMN_COUNT);
        VEC2 column;
        column.x = this->m[0][index];
        column.y = this->m[1][index];
        return column;
    }

    //! @brief Sets a column as a <tt>VEC2</tt> value.
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
    self_type& SetupIdentity() { return *MTX22Identity(this); }

    //@}

    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX22)) == 0; }

    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX22)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX22IsIdentity(this); }

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

//! Alternate name for <tt>MTX22</tt>.
typedef class MTX22 Matrix22;

//@}

}  // namespace math
}  // namespace nn

namespace nn {
namespace math {

inline
MTX22::MTX22(const f32* p) { MTX22Copy(this, reinterpret_cast<const MTX22*>(p)); }

inline
MTX22::MTX22(const MTX23& rhs) { MTX23ToMTX22(this, &rhs); }

//Overload referencing the -- const argument.
inline bool   MTX22IsIdentity(const MTX22& m) { return MTX22IsIdentity( &m ); }
inline MTX22* MTX22Copy(MTX22* pOut, const MTX22& m) { return MTX22Copy(pOut, &m); }
inline MTX22* MTX22MAdd(MTX22* pOut, f32 t, const MTX22& m1, const MTX22& m2) { return MTX22MAdd(pOut, t, &m1, &m2); }

}  // namespace math
}  // namespace nn

#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix22.ipp>
#endif

#pragma pop

#endif

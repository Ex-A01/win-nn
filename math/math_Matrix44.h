#ifndef NN_MATH_MATH_MATRIX44_H_
#define NN_MATH_MATH_MATRIX44_H_

#include <cstring>
#include <nn/math/math_Config.h>

#pragma push
#pragma Otime

namespace nn { 
namespace math {

/*!--------------------------------------------------------------------------*
@brief Enumerated type for specifying the rotation matrix to multiply the projection matrix by.
  
 *---------------------------------------------------------------------------*/
enum PivotDirection
{
    PIVOT_NONE,             //!< No rotation.
    PIVOT_UPSIDE_TO_TOP,    //!< Rotates so that the camera's upward direction points in the screen's upward direction.
    PIVOT_UPSIDE_TO_RIGHT,  //!< Rotates so that the camera's upward direction points in the screen's rightward direction.
    PIVOT_UPSIDE_TO_BOTTOM, //!< Rotates so that the camera's upward direction points in the screen's downward direction.
    PIVOT_UPSIDE_TO_LEFT,   //!< Rotates so that the camera's upward direction points in the screen's leftward direction.
    PIVOT_NUM
};

struct MTX44;

/*!
@name 4x4 Matrices
    @{
*/

/* ------------------------------------------------------------------------
Function for MTX44
   ------------------------------------------------------------------------ */
/*!--------------------------------------------------------------------------*
@brief Calculates the sum of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Add(MTX44* pOut, const MTX44* p1, const MTX44* p2);

/*!--------------------------------------------------------------------------*
@brief Copies a matrix.
@param[out] pOut  Pointer to the matrix to which to copy the data.
@param[in] p  Pointer to the matrix to copy from.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Copy(MTX44* pOut, const MTX44* p);

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix based on the view frustum at the near clipping plane.
<BR /><BR /><B>Note:</B> The order of the arguments follows the OpenGL standard.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Frustum(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f);

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix that has been multiplied by a screen rotation.
Create a projection matrix based on the view frustum at the near clipping plane.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@param[in] pivot  Direction of screen rotation.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44FrustumPivot(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE);

/*!--------------------------------------------------------------------------*
@brief Creates an identity matrix.
@param[out] pOut  Pointer to the buffer that stores the identity matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44Identity(MTX44* pOut);

/*!--------------------------------------------------------------------------*
@brief Calculates the inverse of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.
@return Returns 1 if the inverse matrix exists; otherwise, returns 0.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE u32 MTX44Inverse(MTX44* pOut, const MTX44* p);

/*!--------------------------------------------------------------------------*
@brief Determines whether a matrix is a unitary matrix.
@param[in] p  Pointer to the matrix to evaluate.
@return Returns <tt>true</tt> if <span class="argument">p</span> is the identity matrix, and <tt>false</tt> otherwise.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE bool   MTX44IsIdentity(const MTX44* p);

/*!--------------------------------------------------------------------------*
@brief Calculates the product of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Mult(MTX44* pOut, const MTX44* __restrict p1, const MTX44* __restrict p2);

/*!--------------------------------------------------------------------------*
@brief Calculates a scalar product of a matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">p</span>.
@param[in] p  Pointer to the original matrix.
@param[in] f  Number to multiply by.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Mult(MTX44* pOut, const MTX44* p, f32 f);

/*!--------------------------------------------------------------------------*
@brief Multiplies a matrix from the left by a matrix array.
@param[out] pOut  Pointer to the start of the array that receives the calculated results.
@param[in] p1  Pointer to the matrix that is taken as the left-hand value.
@param[in] pSrc  Pointer to the start of the array of matrices used as the right side value.
@param[in] count  The number of elements in the array of matrices used as right-hand values.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44MultArray(MTX44* pOut, const MTX44* p1, const MTX44* pSrc, s32 count);

/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. It may point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the original matrix.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44MultScale(MTX44* pOut, const MTX44* pM, const VEC3* pS);

/*!--------------------------------------------------------------------------*
@brief Applies a scalar transformation to a matrix. Multiplies the scale matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44MultScale(MTX44* pOut, const VEC3* pS, const MTX44* pM);

/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiplies the translation matrix from the left.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@param[in] pM  Pointer to the original matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44MultTranslate(MTX44* pOut, const VEC3* pT, const MTX44* pM);

/*!--------------------------------------------------------------------------*
@brief Applies a translation to a matrix. Multiply the translation matrix from the right.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pM  Pointer to the original matrix.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44MultTranslate(MTX44* pOut, const MTX44* pM, const VEC3* pT);

/*!--------------------------------------------------------------------------*
@brief Creates an orthogonal matrix.
<BR /><BR /><B>Note:</B> The order of the arguments follows the OpenGL standard.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Ortho(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f);

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix that has been multiplied by a screen rotation.
Creates an orthogonal matrix.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
@param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
@param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
@param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@param[in] pivot  Direction of screen rotation.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44OrthoPivot(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE);

/*!--------------------------------------------------------------------------*
@brief Creates a perspective matrix based on the viewing angle and aspect ratio.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] fovy  Vertical field-of-view angle (in degrees).
@param[in] aspect  View aspect ratio (width:height).
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44PerspectiveDeg(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f);

// Alias of the <tt>MTX44PerspectiveDeg</tt> function.
// For compatibility reasons, the <tt>Perspective</tt> function does not have a suffix. This is for the "degree" version.
inline MTX44* 
MTX44Perspective(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f) 
{ 
    return MTX44PerspectiveDeg(pOut, fovy, aspect, n, f); 
}

/*!--------------------------------------------------------------------------*
@brief Creates a perspective matrix based on the viewing angle and aspect ratio.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] fovy  Vertical field-of-view angle (in degrees).
@param[in] aspect  View aspect ratio (width:height).
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@param[in] pivot  Direction of screen rotation.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44PerspectivePivotDeg(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE );

/*!--------------------------------------------------------------------------*
@brief Creates a projection matrix that has been multiplied by a screen rotation.
Creates a perspective matrix based on the viewing angle and aspect ratio.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] fovy  Vertical field-of-view angle (in radians).
@param[in] aspect  View aspect ratio (width:height).
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@param[in] pivot  Direction of screen rotation.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44PerspectivePivotRad(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE);

/*!--------------------------------------------------------------------------*
@brief Creates a perspective matrix based on the viewing angle and aspect ratio.
@param[out] pOut  Pointer to the matrix that stores the projection matrix.
@param[in] fovy  Vertical field-of-view angle (in radians).
@param[in] aspect  View aspect ratio (width:height).
@param[in] n  Distance to the near clipping plane.
@param[in] f  Distance to the far clipping plane.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44PerspectiveRad(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f);

/*!---------------------------------------------------------------------------*
@brief Rotates the specified projection matrix in the direction the screen is facing.
@param[in] pOut  Pointer to the matrix to rotate.
@param[in] pivot  Direction of screen rotation.
@return Returns <span class="argument">pOut</span>.
*---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Pivot( MTX44* pOut, PivotDirection pivot );

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fDeg  Amount of rotation in degrees
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44RotAxisDeg(MTX44* pOut, const VEC3* pAxis, f32 fDeg);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fIdx  Amount of rotation in units of 1/256th of a circle
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44RotAxisFIdx(MTX44* pOut, const VEC3* pAxis, f32 fIdx);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44RotAxisRad(MTX44* pOut, const VEC3* pAxis, f32 fRad);

/*!--------------------------------------------------------------------------*
:private
  
@brief Creates a rotation matrix for rotating about a specified axis.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] pAxis  Pointer to the vector specified as the axis of rotation.
@param[in] fRad  Amount of rotation in radians.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44RotAxisRad_( MTX44* pOut, const VEC3 *pAxis, f32 fRad );

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fDegX  Angle around the x-axis in degrees.
@param[in] fDegY  Angle around the y-axis in degrees.
@param[in] fDegZ  Angle around the z-axis in degrees.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44RotXYZDeg(MTX44* pOut, f32 fDegX, f32 fDegY, f32 fDegZ);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fIdxX  Angle around the x-axis in units of 1/256th of a circle.
@param[in] fIdxY  Angle around the y-axis in units of 1/256th of a circle.
@param[in] fIdxZ  Angle around the z-axis in units of 1/256th of a circle.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44RotXYZFIdx(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ);

/*!--------------------------------------------------------------------------*
@brief Creates a rotation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results.
@param[in] fRadX  Angle around the x-axis in radians.
@param[in] fRadY  Angle around the y-axis in radians.
@param[in] fRadZ  Angle around the z-axis in radians.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44RotXYZRad(MTX44* pOut, f32 fRadX, f32 fRadY, f32 fRadZ);

/*!--------------------------------------------------------------------------*
@brief Creates a matrix to use for scaling transformations.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pS  Pointer to the vector storing the scale values for each of the three axis directions.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Scale(MTX44* pOut, const VEC3* pS);

/*!--------------------------------------------------------------------------*
@brief Calculates the difference of two matrices.
@param[out] pOut  Pointer to the buffer that receives the calculation results. The same matrix may be specified for both <span class="argument">p1</span> and <span class="argument">p2</span>.
@param[in] p1  Pointer to the left-hand value.
@param[in] p2  Pointer to the right-hand value.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44Sub(MTX44* pOut, const MTX44* p1, const MTX44* p2);

/*!--------------------------------------------------------------------------*
@brief Creates a translation matrix.
@param[out] pOut  Pointer to the buffer that receives the calculation results. May point to the same matrix as <span class="argument">pM</span>.
@param[in] pT  Pointer to the vector storing the amount of translation in each of the three axis directions.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Translate(MTX44* pOut, const VEC3* pT);

/*!--------------------------------------------------------------------------*
@brief Creates the transpose of a matrix.
@param[in] pOut  Pointer to the buffer that receives the calculation results. It is not a problem if this points to the same matrix as <SPAN class="argument">pSrc</SPAN>.
@param[in] pSrc  Pointer to the original matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_FORCE_INLINE MTX44* MTX44Transpose(MTX44* pOut, const MTX44 *pSrc);

/*!--------------------------------------------------------------------------*
@brief Creates a zero matrix.
@param[out] pOut  Pointer to the buffer that stores the zero matrix.
@return Returns <span class="argument">pOut</span>.
 *---------------------------------------------------------------------------

*/
NN_MATH_INLINE MTX44* MTX44Zero(MTX44* pOut);

/*!
    @}
*/

NN_FORCE_INLINE VEC4* VEC3Transform(VEC4* pOut, const MTX44* pM, const VEC3* pV);

/* =======================================================================
Class Definitions
   ======================================================================== */
struct MTX34;

/*!--------------------------------------------------------------------------*
:category Matrices
@brief Structure defining only elements in a 4 x 4 matrix.
 *---------------------------------------------------------------------------*/
struct MTX44_
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
        f32 _30;    //!< 4 x 1
        f32 _31;    //!< 4 x 2
        f32 _32;    //!< 4 x 3
        f32 _33;    //!< 4 x 4
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
            f32 _30, _31, _32, _33;
        };
    #endif
        BaseData f;     //!< Matrix element.
        f32 m[4][4];    //!< Matrix elements represented as a 2D array.
        f32 a[16];      //!< Matrix elements represented as an array.
        VEC4_ v[4];     //!< Matrix elements represented as a <tt>@ref VEC4_</tt> array.
    //@}
    };
};

/*!--------------------------------------------------------------------------*
:category Matrices
@brief A 4x4 matrix class.
 *---------------------------------------------------------------------------*/
class MTX44 : public MTX44_
{
public:
    static const int ROW_COUNT = 4; //!< The number of rows.
    static const int COLUMN_COUNT = 4; //!< The number of columns.
    
    //! @brief The identity matrix.
    static const MTX44& Identity()
    {
        static const MTX44 identity(
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
        
        return identity;
    }
    typedef MTX44 self_type; //!< This class's type.
    typedef f32   value_type; //!< The type of this class's elements.

public:
    //----------------------------------------
    //! @name Creation
    //@{

    //! @brief Constructor.
    MTX44() {}
    
    //! @brief Constructor.
    explicit MTX44(const f32* p) { (void)MTX44Copy(this, (MTX44*)p); }
    
    //! @brief Constructor.
    explicit MTX44(const MTX34& rhs)
    {
        (void)MTX34Copy((MTX34*)this, (MTX34*)&rhs);
        f._30 = f._31 = f._32 = 0.f; f._33 = 1.f;
    }
    
    //! @brief Copy constructor.
    MTX44(const MTX44& rhs) { (void)MTX44Copy(this, &rhs); }
    
    //! @brief Constructor.
    MTX44(f32 x00, f32 x01, f32 x02, f32 x03,
          f32 x10, f32 x11, f32 x12, f32 x13,
          f32 x20, f32 x21, f32 x22, f32 x23,
          f32 x30, f32 x31, f32 x32, f32 x33)
    {
        f._00 = x00; f._01 = x01; f._02 = x02; f._03 = x03;
        f._10 = x10; f._11 = x11; f._12 = x12; f._13 = x13;
        f._20 = x20; f._21 = x21; f._22 = x22; f._23 = x23;
        f._30 = x30; f._31 = x31; f._32 = x32; f._33 = x33;
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

    //! @brief Assigns the values of a postmultiplied matrix.
    self_type& operator *= (const self_type& rhs) { return *MTX44Mult(this, this, &rhs); }

    //! @brief Assigns the values after matrix addition.
    self_type& operator += (const self_type& rhs) { return *MTX44Add(this, this, &rhs); }

    //! @brief Assigns the values after matrix subtraction.
    self_type& operator -= (const self_type& rhs) { return *MTX44Sub(this, this, &rhs); }
    
    //! @brief Assigns the values after matrix multiplication.
    self_type& operator *= (f32 f) { return *MTX44Mult(this, this, f); }

    //! @brief Assigns the values after matrix division.
    self_type& operator /= (f32 f) { return operator*=(1.f / f); }

    //! @brief Returns its own matrix.
    self_type operator + () const { return *this; }

    //! @brief Returns the conjugate of the matrix.
    self_type operator - () const
    {
        return MTX44(-f._00, -f._01, -f._02, -f._03,
                     -f._10, -f._11, -f._12, -f._13,
                     -f._20, -f._21, -f._22, -f._23,
                     -f._30, -f._31, -f._32, -f._33);
    }

    //! @brief Returns the result of matrix addition.
    self_type operator + (const self_type& rhs) const { MTX44 tmp; return *MTX44Add(&tmp, this, &rhs); }

    //! @brief Returns the result after matrix subtraction.
    self_type operator - (const self_type& rhs) const { MTX44 tmp; return *MTX44Sub(&tmp, this, &rhs); }

    //! @brief Returns the result of matrix multiplication.
    self_type operator * (f32 f) const { MTX44 tmp; return *MTX44Mult(&tmp, this, f); }

    //! @brief Returns the result of matrix division.
    self_type operator / (f32 f) const { return *this * (1.f / f); }

    //! Calculates the transpose.
    self_type& Transpose() { return *MTX44Transpose(this, this); }
    //@}

    //----------------------------------------
    //! @name Settings
    //@{
    
    //! @brief Sets as the identity matrix.
    self_type& SetupIdentity() { return *MTX44Identity(this); }
    
    //! @brief Sets up a scaling matrix.
    //!
    //! @param[in] scale  Scale value.
    //!
    self_type& SetupScale(const VEC3& scale) { return *MTX44Scale(this, &scale); }

    //! @brief Sets up a translation matrix.
    //!
    //! @param[in] translate  Translation value.
    //!
    self_type& SetupTranslate(const VEC3& translate)
    {
        return *MTX44Translate(this, &translate);
    }

    //! @brief Sets up a rotation matrix in XYZ order.
    //!
    //! @param[in] rotateRad  A rotation value. In units of radians.
    //!
    self_type& SetupRotateXyz(const VEC3& rotateRad)
    {
        return *MTX44RotXYZRad(this, rotateRad.x, rotateRad.y, rotateRad.z);
    }

    //! @brief Sets up a rotation matrix around the specified axis.
    //!
    //! @param[in] axis  The vector to take as the base axis.
    //! @param[in] theta  The angle to rotate by. In units of radians.
    //!
    self_type& SetupRotate(const VEC3& axis, f32 thetaRad)
    {
        return *MTX44RotAxisRad(this, &axis, thetaRad);
    }

    //! @brief Sets up a projection matrix based on the viewing frustum at the near clipping plane.
    //!               <BR /><B>Note:</B> The order of the arguments follows the OpenGL standard.
    //! 
    //! @param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
    //! @param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
    //! @param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
    //! @param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
    //! @param[in] n  Distance to the near clipping plane.
    //! @param[in] f  Distance to the far clipping plane.
    //! @param[in] pivot  Direction of the screen rotation.
    //!
    self_type& SetupFrustum(f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE)
    {
        return *MTX44FrustumPivot(this, l, r, b, t, n, f, pivot);
    }

    //! @brief Sets up an orthographic projection matrix.
    //!               <BR /><B>Note:</B> The order of the arguments follows the OpenGL standard.
    //!
    //! @param[in] l  X-coordinate of the left edge of the viewing frustum at the near clipping plane.
    //! @param[in] r  X-coordinate of the right edge of the viewing frustum at the near clipping plane.
    //! @param[in] b  Y-coordinate of the bottom edge of the viewing frustum at the near clipping plane.
    //! @param[in] t  Y-coordinate of the top edge of the viewing frustum at the near clipping plane.
    //! @param[in] n  Distance to the near clipping plane.
    //! @param[in] f  Distance to the far clipping plane.
    //! @param[in] pivot  Direction of the screen rotation.
    //!
    self_type& SetupOrtho(f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE)
    {
        return *MTX44OrthoPivot(this, l, r, b, t, n, f, pivot);
    }
    
    //! @brief Sets up a projection matrix based on field-of-view angle and aspect ratio.
    //!
    //! @param[in] fovyRad  Vertical field-of-view angle (in radians).
    //! @param[in] aspect  Aspect ratio (width/height) of the field of view.
    //! @param[in] n  Distance to the near clipping plane.
    //! @param[in] f  Distance to the far clipping plane.
    //! @param[in] pivot  Direction of the screen rotation.
    //!
    self_type& SetupPerspective(f32 fovyRad, f32 aspect, f32 n, f32 f, PivotDirection pivot = PIVOT_NONE)
    {
        return *MTX44PerspectivePivotRad(this, fovyRad, aspect, n, f, pivot);
    }

    //@}
    
    //----------------------------------------
    //! @name Comparisons
    //@{

    //! @brief Returns <tt>true</tt> if the values are equal.
    bool operator == (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX44)) == 0; }
    
    //! @brief Returns <tt>true</tt> if the values are not equal.
    bool operator != (const self_type& rhs) const { return ::std::memcmp(this, &rhs, sizeof(MTX44)) != 0; }

    //! @brief Returns <tt>true</tt> if this is an identity matrix.
    bool IsIdentity() const { return MTX44IsIdentity(this); }
    //@}

    /*!--------------------------------------------------------------------------*
@brief Writes matrix content to debug output.
@param[in] bNewline  If <tt>true</tt>, a linefeed is output to the end of output.
@param[in] name  Specifies the name of the matrix. <tt>NULL</tt> may be specified.
@return  None.
     *---------------------------------------------------------------------------

*/
    void Report(bool bNewline = true, const char* name = NULL) const;

private:
    typedef void (self_type::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const;
    operator UnspecifiedBoolType();
};

//! @name Matrices
//@{

//! Alternate name for <tt>MTX44</tt>.
typedef class MTX44 Matrix44;

//@}

}  // namespace math
}  // namespace nn

#include <nn/math/ARMv6/math_Matrix44.h>

namespace nn { 
namespace math {

NN_FORCE_INLINE MTX44*
MTX44Add(MTX44* pOut, const MTX44* p1, const MTX44* p2)
{

#if defined( NN_HARDWARE_CTR )
    #if (MTX44ADD_ASM_CONFIG == D_ORG)
        return ARMv6::MTX44AddC(pOut, p1, p2);
    #elif (MTX44ADD_ASM_CONFIG == D_FAST_C)
    #elif (MTX44ADD_ASM_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44AddAsm(pOut, p1, p2);
    #elif (MTX44ADD_ASM_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44ADD_ASM_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44Copy(MTX44* pOut, const MTX44* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44COPY_CONFIG == D_ORG)
        return ARMv6::MTX44CopyC(pOut, p);
    #elif (MTX44COPY_CONFIG == D_FAST_C)
    #elif (MTX44COPY_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44CopyAsm(pOut, p);
    #elif (MTX44COPY_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44COPY_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}


NN_FORCE_INLINE MTX44*
MTX44Frustum(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44FRUSTUM_CONFIG == D_ORG)
        return ARMv6::MTX44FrustumC(pOut, l, r, b, t, n, f);
    #elif (MTX44FRUSTUM_CONFIG == D_FAST_C)
        return ARMv6::MTX44FrustumC_FAST(pOut, l, r, b, t, n, f);
    #elif (MTX44FRUSTUM_CONFIG == D_FAST_ASM)
    #elif (MTX44FRUSTUM_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44FRUSTUM_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}


NN_FORCE_INLINE u32
MTX44Inverse(MTX44* pOut, const MTX44* p)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44INVERSE_CONFIG == D_ORG)
        return ARMv6::MTX44InverseC(pOut, p);
    #elif (MTX44INVERSE_CONFIG == D_FAST_C)
    #elif (MTX44INVERSE_CONFIG == D_FAST_ASM)
    #elif (MTX44INVERSE_CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX44InverseC_FAST_ALGO(pOut, p);
    #elif (MTX44INVERSE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}


NN_FORCE_INLINE MTX44*
MTX44Mult(MTX44* pOut, const MTX44* __restrict p1, const MTX44* __restrict p2) 
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULT_44_CONFIG == D_ORG)
        return ARMv6::MTX44MultC(pOut, p1, p2);
    #elif (MTX44MULT_44_CONFIG == D_FAST_C)
    #elif (MTX44MULT_44_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultAsm(pOut, p1, p2);
    #elif (MTX44MULT_44_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULT_44_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44Mult(MTX44* pOut, const MTX44* p, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULT_F32_CONFIG == D_ORG)
        return ARMv6::MTX44MultC(pOut, p, f);
    #elif (MTX44MULT_F32_CONFIG == D_FAST_C)
    #elif (MTX44MULT_F32_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultAsm(pOut, p, f);
    #elif (MTX44MULT_F32_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULT_F32_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE MTX44*
MTX44MultScale(MTX44* pOut, const MTX44* pM, const VEC3* pS)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULTSCALE_RIGHT_CONFIG == D_ORG)
        return ARMv6::MTX44MultScaleC(pOut, pM, pS);
    #elif (MTX44MULTSCALE_RIGHT_CONFIG == D_FAST_C)
    #elif (MTX44MULTSCALE_RIGHT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultScaleAsm(pOut, pM, pS);
    #elif (MTX44MULTSCALE_RIGHT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULTSCALE_RIGHT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44MultScale(MTX44* pOut, const VEC3* pS, const MTX44* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULTSCALE_LEFT_CONFIG == D_ORG)
        return ARMv6::MTX44MultScaleC(pOut, pS, pM);
    #elif (MTX44MULTSCALE_LEFT_CONFIG == D_FAST_C)
    #elif (MTX44MULTSCALE_LEFT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultScaleAsm(pOut, pS, pM);
    #elif (MTX44MULTSCALE_LEFT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULTSCALE_LEFT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44MultTranslate(MTX44* pOut, const VEC3* pT, const MTX44* pM)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULTTRANSLATE_LEFT_CONFIG == D_ORG)
        return ARMv6::MTX44MultTranslateC(pOut, pT, pM);
    #elif (MTX44MULTTRANSLATE_LEFT_CONFIG == D_FAST_C)
    #elif (MTX44MULTTRANSLATE_LEFT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultTranslateAsm(pOut, pT, pM);
    #elif (MTX44MULTTRANSLATE_LEFT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULTTRANSLATE_LEFT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44MultTranslate(MTX44* pOut, const MTX44* pM, const VEC3* pT)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44MULTTRANSLATE_RIGHT_CONFIG == D_ORG)
        return ARMv6::MTX44MultTranslateC(pOut, pM, pT);
    #elif (MTX44MULTTRANSLATE_RIGHT_CONFIG == D_FAST_C)
    #elif (MTX44MULTTRANSLATE_RIGHT_CONFIG == D_FAST_ASM)
        return ARMv6::MTX44MultTranslateAsm(pOut, pM, pT);
    #elif (MTX44MULTTRANSLATE_RIGHT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44MULTTRANSLATE_RIGHT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44Ortho(MTX44* pOut, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44ORTHO_CONFIG == D_ORG)
        return ARMv6::MTX44OrthoC(pOut, l, r, b, t, n, f);
    #elif (MTX44ORTHO_CONFIG == D_FAST_C)
        return ARMv6::MTX44OrthoC_FAST(pOut, l, r, b, t, n, f);
    #elif (MTX44ORTHO_CONFIG == D_FAST_ASM)
    #elif (MTX44ORTHO_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44ORTHO_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44PerspectiveRad(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44PERSPECTIVERAD_CONFIG == D_ORG)
        return ARMv6::MTX44PerspectiveRadC(pOut, fovy, aspect, n, f);
    #elif (MTX44PERSPECTIVERAD_CONFIG == D_FAST_C)
        return ARMv6::MTX44PerspectiveRadC_FAST(pOut, fovy, aspect, n, f);
    #elif (MTX44PERSPECTIVERAD_CONFIG == D_FAST_ASM)
    #elif (MTX44PERSPECTIVERAD_CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX44PerspectiveRadC_FAST(pOut, fovy, aspect, n, f);
    #elif (MTX44PERSPECTIVERAD_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44RotAxisRad_( MTX44* pOut, const VEC3 *pAxis, f32 fRad )
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44ROTAXISRAD__CONFIG == D_ORG)
        return ARMv6::MTX44RotAxisRad_C(pOut, pAxis, fRad);
    #elif (MTX44ROTAXISRAD__CONFIG == D_FAST_C)
        return ARMv6::MTX44RotAxisRad_C_FAST(pOut, pAxis, fRad);
    #elif (MTX44ROTAXISRAD__CONFIG == D_FAST_ASM)
    #elif (MTX44ROTAXISRAD__CONFIG == D_FAST_C_ALGO)
        return ARMv6::MTX44RotAxisRad_C_FAST(pOut, pAxis, fRad);
    #elif (MTX44ROTAXISRAD__CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44RotXYZFIdx(MTX44* pOut, f32 fIdxX, f32 fIdxY, f32 fIdxZ)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44ROTXYZFIDX_CONFIG == D_ORG)
        return ARMv6::MTX44RotXYZFIdxC(pOut, fIdxX, fIdxY, fIdxZ);
    #elif (MTX44ROTXYZFIDX_CONFIG == D_FAST_C)
        return ARMv6::MTX44RotXYZFIdxC_FAST(pOut, fIdxX, fIdxY, fIdxZ);
    #elif (MTX44ROTXYZFIDX_CONFIG == D_FAST_ASM)
    #elif (MTX44ROTXYZFIDX_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44ROTXYZFIDX_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44Scale(MTX44* pOut, const VEC3* pS)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44SCALE_CONFIG == D_ORG)
        return ARMv6::MTX44ScaleC(pOut, pS);
    #elif (MTX44SCALE_CONFIG == D_FAST_C)
        return ARMv6::MTX44ScaleC_FAST(pOut, pS);
    #elif (MTX44SCALE_CONFIG == D_FAST_ASM)
    #elif (MTX44SCALE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44SCALE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

NN_FORCE_INLINE MTX44*
MTX44Translate(MTX44* pOut, const VEC3* pT)
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44TRANSLATE_CONFIG == D_ORG)
        return ARMv6::MTX44TranslateC(pOut, pT);
    #elif (MTX44TRANSLATE_CONFIG == D_FAST_C)
        return ARMv6::MTX44TranslateC_FAST(pOut, pT);
    #elif (MTX44TRANSLATE_CONFIG == D_FAST_ASM)
    #elif (MTX44TRANSLATE_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44TRANSLATE_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE MTX44* 
MTX44Transpose(MTX44* pOut, const MTX44 *pSrc)
{
#if defined( NN_HARDWARE_CTR )
#if (MTX44TRANSPOSE_44_CONFIG == D_ORG)
    return ARMv6::MTX44TransposeC(pOut, pSrc);
#elif (MTX44TRANSPOSE_44_CONFIG == D_FAST_C)
#elif (MTX44TRANSPOSE_44_CONFIG == D_FAST_ASM)
    return ARMv6::MTX44TransposeAsm(pOut, pSrc);
#elif (MTX44TRANSPOSE_44_CONFIG == D_FAST_C_ALGO)
#elif (MTX44TRANSPOSE_44_CONFIG == D_FAST_ASM_ALGO)
#endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_MATH_INLINE MTX44*
MTX44PerspectiveDeg(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f)
{
    return MTX44PerspectiveRad(pOut, NN_MATH_DEG_TO_RAD(fovy), aspect, n, f);
}

NN_MATH_INLINE MTX44*
MTX44PerspectivePivotDeg(MTX44* pOut, f32 fovy, f32 aspect, f32 n, f32 f, PivotDirection pivot)
{
    return MTX44PerspectivePivotRad(pOut, NN_MATH_DEG_TO_RAD(fovy), aspect, n, f, pivot);
}

NN_MATH_INLINE MTX44*
MTX44RotXYZRad(MTX44* pOut, f32 fRadX, f32 fRadY, f32 fRadZ)
{
    return MTX44RotXYZFIdx(pOut, NN_MATH_RAD_TO_FIDX(fRadX), NN_MATH_RAD_TO_FIDX(fRadY), NN_MATH_RAD_TO_FIDX(fRadZ));
}

NN_MATH_INLINE MTX44*
MTX44RotXYZDeg(MTX44* pOut, f32 fDegX, f32 fDegY, f32 fDegZ)
{
    return MTX44RotXYZFIdx(pOut, NN_MATH_DEG_TO_FIDX(fDegX), NN_MATH_DEG_TO_FIDX(fDegY), NN_MATH_DEG_TO_FIDX(fDegZ));
}

NN_MATH_INLINE MTX44*
MTX44RotAxisRad(MTX44* pOut, const VEC3* pAxis, f32 fRad)
{
    return MTX44RotAxisFIdx(pOut, pAxis, NN_MATH_RAD_TO_FIDX(fRad));
}

NN_MATH_INLINE MTX44*
MTX44RotAxisDeg(MTX44* pOut, const VEC3* pAxis, f32 fDeg)
{
    return MTX44RotAxisFIdx(pOut, pAxis, NN_MATH_DEG_TO_FIDX(fDeg));
}

NN_FORCE_INLINE MTX44*
MTX44Pivot( MTX44* pOut, PivotDirection pivot )
{
#if defined( NN_HARDWARE_CTR )
    #if (MTX44PIVOT_CONFIG == D_ORG)
        return ARMv6::MTX44PivotC(pOut, pivot);
    #elif (MTX44PIVOT_CONFIG == D_FAST_C)
        return ARMv6::MTX44PivotC_FAST(pOut, pivot);
    #elif (MTX44PIVOT_CONFIG == D_FAST_ASM)
    #elif (MTX44PIVOT_CONFIG == D_FAST_C_ALGO)
    #elif (MTX44PIVOT_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )

}

NN_FORCE_INLINE VEC4*
VEC3Transform(VEC4* pOut, const MTX44* pM, const VEC3* pV)
{
#if defined( NN_HARDWARE_CTR )
    #if (VEC3TRANSFORM_44XVEC3_CONFIG == D_ORG)
        return ARMv6::VEC3TransformC(pOut, pM, pV);
    #elif (VEC3TRANSFORM_44XVEC3_CONFIG == D_FAST_C)
    #elif (VEC3TRANSFORM_44XVEC3_CONFIG == D_FAST_ASM)
        return ARMv6::VEC3TransformAsm(pOut, pM, pV);
    #elif (VEC3TRANSFORM_44XVEC3_CONFIG == D_FAST_C_ALGO)
    #elif (VEC3TRANSFORM_44XVEC3_CONFIG == D_FAST_ASM_ALGO)
    #endif
#else
#endif // #if defined( NN_HARDWARE_CTR )
}

//Overload referencing the -- const argument.
inline MTX44* MTX44Copy(MTX44* pOut, const MTX44& m) { return MTX44Copy( pOut, &m ); }
inline bool   MTX44IsIdentity(const MTX44& m) { return MTX44IsIdentity( &m ); }

inline MTX44* MTX44Add(MTX44* pOut, const MTX44& m1, const MTX44& m2) { return MTX44Add( pOut, &m1, &m2 ); }
inline MTX44* MTX44Sub(MTX44* pOut, const MTX44& m1, const MTX44& m2) { return MTX44Sub( pOut, &m1, &m2 ); }
inline MTX44* MTX44Mult(MTX44* pOut, const MTX44& m, f32 f) { return MTX44Mult( pOut, &m, f ); }
inline MTX44* MTX44Mult(MTX44* pOut, const MTX44& m1, const MTX44& m2) { return MTX44Mult( pOut, &m1, &m2 ); }

inline MTX44* MTX44Transpose(MTX44* pOut, const MTX44& m) { return MTX44Transpose( pOut, &m ); }
inline MTX44* MTX44MultArray(MTX44* pOut, const MTX44& m1, const MTX44* pSrc, s32 count) { return MTX44MultArray( pOut, &m1, pSrc, count ); }
inline u32    MTX44Inverse(MTX44* pOut, const MTX44& m) { return MTX44Inverse( pOut, &m ); }

inline MTX44* MTX44RotAxisFIdx(MTX44* pOut, const VEC3& vAxis, f32 fIdx) { return MTX44RotAxisFIdx( pOut, &vAxis, fIdx ); }
inline MTX44* MTX44RotAxisRad(MTX44* pOut, const VEC3& vAxis, f32 fRad) { return MTX44RotAxisRad( pOut, &vAxis, fRad ); }
inline MTX44* MTX44RotAxisDeg(MTX44* pOut, const VEC3& vAxis, f32 fDeg) { return MTX44RotAxisDeg( pOut, &vAxis, fDeg ); }

inline MTX44* MTX44Scale(MTX44* pOut, const VEC3& S) { return MTX44Scale(pOut, &S); }
inline MTX44* MTX44MultScale(MTX44* pOut, const MTX44& M, const VEC3& S) { return MTX44MultScale(pOut, &M, &S); }
inline MTX44* MTX44MultScale(MTX44* pOut, const VEC3& S, const MTX44& M) { return MTX44MultScale(pOut, &S, &M); }

inline MTX44* MTX44Translate(MTX44* pOut, const VEC3& T) { return MTX44Translate(pOut, &T); }
inline MTX44* MTX44MultTranslate(MTX44* pOut, const MTX44& M, const VEC3& T) { return MTX44MultTranslate(pOut, &M, &T); }
inline MTX44* MTX44MultTranslate(MTX44* pOut, const VEC3& T, const MTX44& M) { return MTX44MultTranslate(pOut, &T, &M); }

}  // namespace math
}  // namespace nn

#if defined(NN_MATH_AS_INLINE)
#include <nn/math/inline/math_Matrix44.ipp>
#include <nn/math/ARMv6/inline/math_Matrix44.ipp>
#endif

#pragma pop

#endif

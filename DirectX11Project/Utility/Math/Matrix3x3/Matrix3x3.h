#ifndef MATRIX_3X3_H_
#define MATRIX_3X3_H_

// ostream�̐�s�錾
#include <iosfwd>

struct Vector2;

// �s��
struct Matrix3x3 {
	float m[3][3];

	// �R���X�g���N�^
	Matrix3x3() = default;
	// �R���X�g���N�^
	Matrix3x3(	float m11, float m12, float m13,
				float m21, float m22, float m23,
				float m31, float m32, float m33);
	// �[���s��
	static Matrix3x3 zero();
	// �P�ʍs��
	static Matrix3x3 identity();
	// �g��k���s��
	static Matrix3x3 scale(const Vector2& vector);
	// ��]
	static Matrix3x3 rotate(float rotation);
	// ���s�ړ�
	static Matrix3x3 translate(const Vector2& position);
};

// �s��̉��Z
Matrix3x3 operator + (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��̌��Z
Matrix3x3 operator - (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��̃X�J���[�{
Matrix3x3 operator * (const Matrix3x3& lhs, const float rhs);
// �s��̃X�J���[�{
Matrix3x3 operator * (const float lhs, const Matrix3x3& rhs);
// �s��̏�Z
Matrix3x3 operator * (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��ƃx�N�g���̐�
Vector2 operator * (const Vector2& lhs, const Matrix3x3 rhs);

// �s��̏o��
std::ostream& operator << (std::ostream& out, const Matrix3x3& rhs);

#endif
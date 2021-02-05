#pragma once

// ostream�̐�s�錾
#include <iosfwd>

#ifdef EVAENGINE_EXPORTS
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

struct Vector2;

// �s��
EVAENGINE_API struct Matrix3x3 {
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
EVAENGINE_API Matrix3x3 operator + (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��̌��Z
EVAENGINE_API Matrix3x3 operator - (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��̃X�J���[�{
EVAENGINE_API Matrix3x3 operator * (const Matrix3x3& lhs, const float rhs);
// �s��̃X�J���[�{
EVAENGINE_API Matrix3x3 operator * (const float lhs, const Matrix3x3& rhs);
// �s��̏�Z
EVAENGINE_API Matrix3x3 operator * (const Matrix3x3& lhs, const Matrix3x3 rhs);
// �s��ƃx�N�g���̐�
EVAENGINE_API Vector2 operator * (const Vector2& lhs, const Matrix3x3 rhs);

// �s��̏o��
EVAENGINE_API std::ostream& operator << (std::ostream& out, const Matrix3x3& rhs);
#pragma once

#include "../Vector3/Vector3.h"
#include <string>

#ifdef EVAENGINE_EXPORTS
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

// �N�H�[�^�j�I��
struct Quaternion {
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };
	float w{ 1.0f };

	// �f�t�H���g�R���X�g���N�^
	EVAENGINE_API Quaternion() = default;
	// �R���X�g���N�^
	EVAENGINE_API Quaternion(float x, float y, float z, float w);

	// �P�ʃN�H�[�^�j�I��
	EVAENGINE_API static Quaternion identity();
	// ���K��
	EVAENGINE_API Quaternion normalized() const;
	// [0] ��[1] ���g�p���� x �� y �����ɃA�N�Z�X���܂�
	EVAENGINE_API float operator[](int index) const;
	EVAENGINE_API float& operator[](int index);

	// ������ Quaternion �� x�Ay�Az�Aw �̐�����ݒ肵�܂�
	EVAENGINE_API void set(float newX, float newY, float newZ, float newW);
	// �N�H�[�^��I���̒l�����₷�������������Ԃ��܂��B
	EVAENGINE_API std::string to_string() const;

	// 2 �̉�] a �� b �Ԃ̊p�x��Ԃ��܂��B
	EVAENGINE_API static float angle(const Quaternion& a, const Quaternion& b);
	EVAENGINE_API static Vector3 internal_make_positive(Vector3 euler);
	// axis �̎���� angle �x��]�����]���쐬���܂��B
	EVAENGINE_API static Quaternion angle_axis(float angle, const Vector3& axis);
	// 2 �̉�]�̓��ς�Ԃ��܂��B
	EVAENGINE_API static float dot(const Quaternion& a, const Quaternion& b);

	// �t�N�H�[�^�j�I����Ԃ��܂�
	EVAENGINE_API static Quaternion inverse(const Quaternion& rotation);
	// ���K�������N�H�[�^�j�I����Ԃ��܂�
	EVAENGINE_API static Quaternion normalize(const Quaternion& q);

	EVAENGINE_API float length() const;

	//�@a �� b �̊Ԃ� t �ŋ���ɕ�Ԃ��܂��B�p�����[�^�[ t �́A[0, 1] �͈̔͂ł��B
	EVAENGINE_API static Quaternion slerp(const Quaternion& a, const Quaternion& b, float t);
	// a �� b �̊Ԃ� t �ŋ���ɕ�Ԃ��܂��B�p�����[�^�[ t �́A�����Ă��܂���B
	EVAENGINE_API static Quaternion slerp_unclamped(const Quaternion& a, const Quaternion& b, float t);

	// ��]���I�C���[�p�̒l�ŕԂ��܂�
	EVAENGINE_API Vector3 euler_angles() const;
	// �I�C���[�p���N�H�[�^�j�I���ɕϊ����Ď��g�ɑ��
	EVAENGINE_API void euler_angles(const Vector3& value);


	// fromDirection ���� toDirection �ւ̉�]���쐬���܂�
	EVAENGINE_API void set_from_to_rotation(const Vector3& fromDirection, const Vector3& toDirection);
	// �w�肳�ꂽ forward �� upwards �����ɉ�]���܂�
	EVAENGINE_API void set_look_rotation(const Vector3& view, const Vector3& up = Vector3::up());
	// ��]�����W�ɑ΂���p�x�̒l (AngleAxis) �ɕϊ����܂��B
	EVAENGINE_API void to_angle_axis(float& angle, Vector3& axis);

	// z���𒆐S��z�x�Ax���𒆐S��x�x�Ay���𒆐S��y�x��]�����]��Ԃ��܂��B
	EVAENGINE_API static Quaternion euler(float x, float y, float z);
	EVAENGINE_API static Quaternion euler(const Vector3& euler);
	// fromDirection ���� toDirection �ւ̉�]���쐬���܂��B
	EVAENGINE_API static Quaternion from_to_rotation(const Vector3& fromDirection,
		const Vector3& toDirection);
	// �w�肳�ꂽ forward �� upwards �����ɉ�]���܂�
	EVAENGINE_API static Quaternion look_rotation(const Vector3& view, const Vector3& up = Vector3::up());
	// from ���� to �ւ̉�]�𓾂܂�
	EVAENGINE_API static Quaternion rotate_towards(const Quaternion& from,
		const Quaternion& to, float maxDegreesDelta);
	//�@a �� b �̊Ԃ� t �Ő��`�ɕ�Ԃ��܂��B�p�����[�^�[ t �́A[0, 1] �͈̔͂ł��B
	EVAENGINE_API static Quaternion lerp(const Quaternion& a, const Quaternion& b, float t);
	// a �� b �̊Ԃ� t �Ő��`�ɕ�Ԃ��܂��B�p�����[�^�[ t �́A�����Ă��܂���B
	EVAENGINE_API static Quaternion lerp_unclamped(const Quaternion& a, const Quaternion& b, float t);

	// ��r(���S�ɒl����v���Ă��邩�H�j
	EVAENGINE_API bool equals(const Quaternion& other) const;

private:
	static bool is_equal_using_dot(float dot);

public:
	static const float k_epsilon;
};

// ���Z�q�I�[�o�[���[�h
EVAENGINE_API Quaternion operator - (const Quaternion& q);
EVAENGINE_API Quaternion operator + (const Quaternion& lhs, const Quaternion& rhs);
EVAENGINE_API Quaternion operator - (const Quaternion& lhs, const Quaternion& rhs);
EVAENGINE_API Quaternion operator * (const Quaternion& lhs, float rhs);
EVAENGINE_API Quaternion operator * (float rhs, const Quaternion& lhs);
EVAENGINE_API Quaternion operator * (const Quaternion& lhs, const Quaternion& rhs);
EVAENGINE_API Quaternion operator / (Quaternion lhs, float s);
EVAENGINE_API Vector3 operator * (const Quaternion& rotation, const Vector3& point);
EVAENGINE_API bool operator == (const Quaternion& lhs, const Quaternion& rhs);
EVAENGINE_API bool operator != (const Quaternion& lhs, const Quaternion& rhs);
#pragma once

#include <string>

#ifdef EVAENGINE_EXPORTS
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

// 2D�x�N�g��
struct Vector2 {
	// �x�N�g����x����
	float x{ 0.0f };
	// �x�N�g����y����
	float y{ 0.0f };

	// �f�t�H���g�R���X�g���N�^
	EVAENGINE_API Vector2() = default;
	// �R���X�g���N�^
	EVAENGINE_API Vector2(float x, float y);

	// Vector2(0, 0) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 zero();
	// Vector2(1, 1) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 one();
	// Vector2(0, 1) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 up();
	// Vector2(0, -1) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 down();
	// Vector2(-1, 0) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 left();
	// Vector2(1, 0) �Ɠ����Ӗ�
	EVAENGINE_API static Vector2 right();

	// �x�N�g���̒����i�ǂݎ���p�j
	EVAENGINE_API float magnitude() const;
	// magnitude �� 1 �Ƃ����x�N�g���i�ǂݎ���p�j
	EVAENGINE_API Vector2 normalized() const;
	//�@�x�N�g���� 2 ��̒�����Ԃ��܂��i�ǂݎ���p�j
	EVAENGINE_API float sqr_magnitude() const;

	// [0] ��[1] ���g�p���� x �� y �����ɃA�N�Z�X���܂�
	EVAENGINE_API float operator[](int index) const;
	EVAENGINE_API float& operator[](int index);

	// �Q�̃x�N�g�������������H
	EVAENGINE_API bool equals(const Vector2& other);
	// magnitude �� 1 �Ƃ����x�N�g�����쐬���܂�
	EVAENGINE_API void normalize();
	// ������ Vector2 �� x �� y �̐�����ݒ肵�܂�
	EVAENGINE_API void set(float x, float y);
	// �x�N�g���̒l�����₷���t�H�[�}�b�g���ꂽ������
	EVAENGINE_API std::string to_string() const;

	// 2�̃x�N�g���̂Ȃ��p��Ԃ��܂�
	EVAENGINE_API static float angle(const Vector2& from, const Vector2& to);
	// �傫���� maxLength �܂łɐ������� vector �̃R�s�[��Ԃ��܂�
	EVAENGINE_API static Vector2 clamp_magnitude(const Vector2& vector, float max_length);
	// a �� b �̊Ԃ̋�����Ԃ��܂�
	EVAENGINE_API static float distance(const Vector2& a, const Vector2& b);
	// 2 �̃x�N�g���̓���
	EVAENGINE_API static float dot(const Vector2& lhs, const Vector2& rhs);

	// 2�x�N�g��a��b�̐��`��Ԃ��܂��B
	EVAENGINE_API static Vector2 lerp(const Vector2& a, const Vector2& b, float t);
	// 2�x�N�g��a �� b �̐��`��Ԃ��܂��B
	EVAENGINE_API static Vector2 lerp_unclamped(const Vector2& a, const Vector2& b, float t);
	// 2�̃x�N�g���Ŋe�����̈�ԑ傫�Ȓl���g�p���ăx�N�g�����쐬���܂�
	EVAENGINE_API static Vector2 max(const Vector2& lhs, const Vector2& rhs);
	// 2 �̃x�N�g���Ŋe�����̈�ԏ����Ȓl���g�p���ăx�N�g�����쐬���܂�
	EVAENGINE_API static Vector2 min(const Vector2& lhs, const Vector2& rhs);
	// ���݂̈ʒu current ���� target �Ɍ����Ĉړ����܂�
	EVAENGINE_API static Vector2 move_towards(const Vector2& current, const Vector2& target,
		float max_distance_delta);
	// ����2D�x�N�g���ɐ�����2D�x�N�g����Ԃ��܂��B
	// ����Y�����オ��2D���W�n�ł́A���ʂ͏�ɔ����v����90�x��]���܂��B
	EVAENGINE_API static Vector2 perpendicular(Vector2 inDirection);
	// �@������ɂ��ăx�N�g���̔��˂����x�N�g�����擾���܂�
	EVAENGINE_API static Vector2 reflect(const Vector2& inDirection, const Vector2& inNormal);
	// 2�̃x�N�g���̊e��������Z���܂�
	EVAENGINE_API static Vector2 scale(const Vector2& a, const Vector2& b);
	// Returns the signed angle in degrees between from and to.
	EVAENGINE_API static float signed_angle(const Vector2& from, const Vector2& to);
	// �ړI�n�Ɍ������Ď��Ԃ̌o�߂ƂƂ��ɏ��X�Ƀx�N�g����ω������܂�
	EVAENGINE_API Vector2 smooth_damp(const Vector2& current, const Vector2& target,
		Vector2& currentVelocity, float smooth_time, float max_speed, float delta_time);
};

// �P�����Z�q�I�[�o�[���[�h
EVAENGINE_API Vector2 operator - (const Vector2& v);

// ������Z�q�I�[�o�[���[�h
EVAENGINE_API Vector2& operator += (Vector2& lhs, const Vector2& rhs);
EVAENGINE_API Vector2& operator -= (Vector2& lhs, const Vector2& rhs);
EVAENGINE_API Vector2& operator *= (Vector2& lhs, float rhs);
EVAENGINE_API Vector2& operator /= (Vector2& lhs, float rhs);

// �Q�����Z�q�I�[�o�[���[�h
EVAENGINE_API Vector2 operator + (const Vector2& lhs, const Vector2& rhs);
EVAENGINE_API Vector2 operator - (const Vector2& lhs, const Vector2& rhs);
EVAENGINE_API Vector2 operator * (const Vector2& lhs, float rhs);
EVAENGINE_API Vector2 operator * (float lhs, const Vector2& rhs);
EVAENGINE_API Vector2 operator / (const Vector2& lhs, float rhs);

EVAENGINE_API bool operator == (const Vector2& lhs, const Vector2& rhs);
EVAENGINE_API bool operator != (const Vector2& lhs, const Vector2& rhs);
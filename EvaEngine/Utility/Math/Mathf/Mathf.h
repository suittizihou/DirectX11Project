#pragma once

#include <cmath>
#include <limits>

#ifdef EVAENGINE_EXPORTS
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

struct Mathf {
public:
	// �~����
	EVAENGINE_API static float pi() {
		return 3.14159265358979f;
	}
	// �x���烉�W�A���ɕϊ�����萔
	EVAENGINE_API static float deg_to_rad() {
		return  pi() * 2.0f / 360.0f;
	}
	// ���W�A������x�ɕϊ�����萔
	EVAENGINE_API static float rad_to_deg() {
		return 1.0f / deg_to_rad();
	}
	// f �̕�����Ԃ��܂�
	EVAENGINE_API static float sign(float f) {
		return f >= 0.0f ? 1.0f : -1.0f;
	}
	// �������\�����܂�
	EVAENGINE_API static float infinity() {
		return std::numeric_limits<float>::infinity();
	}
	// ���̖������\�����܂�
	EVAENGINE_API static float negative_infinity() {
		return -std::numeric_limits<float>::infinity();
	}
	// �^����ꂽ�ŏ� float �l�ƍő� float �l�͈̔͂ɒl�𐧌����܂��B
	EVAENGINE_API static float clamp(float value, float min, float max) {
		return (value < min) ? min : (value > max) ? max : value;
	}
	// 0 �� 1 �̊Ԃɒl�𐧌����A���̒l��Ԃ��܂��B�B
	EVAENGINE_API static float clamp01(float value) {
		return clamp(value, 0.0f, 1.0f);
	}
	// current ���� target �܂ŁAmaxDelta �̃X�s�[�h�ňړ����܂�
	EVAENGINE_API static float move_towards(float current, float target, float max_delta) {
		if (std::abs(target - current) <= max_delta)
			return target;
		return current + sign(target - current) * max_delta;
	}
	// �ŏ��l��Ԃ�
	EVAENGINE_API static float min(float a, float b)
	{
		return (a >= b) ? b : a;
	}
};
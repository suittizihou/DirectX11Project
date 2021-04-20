#pragma once

#include <cmath>
#include <limits>

#undef min

namespace EvaEngine {
	struct Mathf {
	public:
		// �~����
		static float pi() {
			return 3.14159265358979f;
		}
		// �x���烉�W�A���ɕϊ�����萔
		static float deg_to_rad() {
			return  pi() * 2.0f / 360.0f;
		}
		// ���W�A������x�ɕϊ�����萔
		static float rad_to_deg() {
			return 1.0f / deg_to_rad();
		}
		// f �̕�����Ԃ��܂�
		static float sign(float f) {
			return f >= 0.0f ? 1.0f : -1.0f;
		}
		// �������\�����܂�
		static float infinity() {
			return std::numeric_limits<float>::infinity();
		}
		// ���̖������\�����܂�
		static float negative_infinity() {
			return -std::numeric_limits<float>::infinity();
		}
		// �^����ꂽ�ŏ� float �l�ƍő� float �l�͈̔͂ɒl�𐧌����܂��B
		static float clamp(float value, float min, float max) {
			return (value < min) ? min : (value > max) ? max : value;
		}
		// 0 �� 1 �̊Ԃɒl�𐧌����A���̒l��Ԃ��܂��B�B
		static float clamp01(float value) {
			return clamp(value, 0.0f, 1.0f);
		}
		// current ���� target �܂ŁAmaxDelta �̃X�s�[�h�ňړ����܂�
		static float move_towards(float current, float target, float max_delta) {
			if (std::abs(target - current) <= max_delta)
				return target;
			return current + sign(target - current) * max_delta;
		}
		// �ŏ��l��Ԃ�
		static float min(float a, float b)
		{
			return (a >= b) ? b : a;
		}
	};
}
#pragma once

#include "../../../GameSystemBase/Base/Component/Component.h"
#include "../../../Utility/Math/Vector3/Vector3.h"
#include "../../../Utility/Math/Matrix4x4/Matrix4x4.h"
#include "../../../Utility/Math/Quaternion/Quaternion.h"
#include <list>

// �g�����X�t�H�[���N���X
class Transform : public Component {
public:
	// ���W�n�̎w��
	enum class Space {
		Self,   // ���[�J�����W�n
		World   // ���[���h���W�n
	};

	// �R���X�g���N�^
	Transform() :
		Component(0U, false, false) {};
	// �f�X�g���N�^
	~Transform();
	// ���[���h��Ԃ� Transform �̐� �O���擾
	EVAENGINE_API Vector3 forward() const;
	// ���[���h��Ԃ� Transform �̐� �O��ݒ�
	EVAENGINE_API void forward(const Vector3& value);
	// ���[���h��Ԃ� Transform �̐� ����擾
	EVAENGINE_API Vector3 back() const;
	// ���[���h��Ԃ� Transform �̐Ԏ� �E���擾
	EVAENGINE_API Vector3 right() const;
	// ���[���h��Ԃ� Transform �̐Ԏ� �E��ݒ�
	EVAENGINE_API void right(const Vector3& value);
	// ���[���h��Ԃ� Transform �̐Ԏ� �����擾
	EVAENGINE_API Vector3 left() const;
	// ���[���h��Ԃ� Transform �̗Ύ� ����擾
	EVAENGINE_API Vector3 up() const;
	// ���[���h��Ԃ� Transform �̗Ύ� ���ݒ�
	EVAENGINE_API void up(const Vector3& value);
	// ���[���h��Ԃ� Transform �̗Ύ� �����擾
	EVAENGINE_API Vector3 down() const;
	// �I�u�W�F�N�g�̃O���[�o���X�P�[�����擾
	EVAENGINE_API Vector3 lossy_scale() const;
	// ���[���h��Ԃ� Transform �̈ʒu���擾
	EVAENGINE_API Vector3 position() const;
	// ���[���h��Ԃ� Transform �̈ʒu��ݒ�
	EVAENGINE_API void position(const Vector3& value);
	// ���[���h��Ԃł̈ړ�
	EVAENGINE_API void move(const Vector3& velocity);
	// �e�� Transform �I�u�W�F�N�g����Velocity���ړ�
	EVAENGINE_API void local_move(const Vector3& velocity);
	// Quaternion �Ƃ��ĕۑ�����郏�[���h��Ԃł� Transform �̉�]���擾
	EVAENGINE_API Quaternion rotation() const;
	// Quaternion �Ƃ��ĕۑ�����郏�[���h��Ԃł� Transform �̉�]��ݒ�
	EVAENGINE_API void rotation(const Quaternion& value);
	// �I�C���[�p�Ƃ��Ă̊p�x���擾
	EVAENGINE_API Vector3 euler_angles() const;
	// �I�C���[�p�Ƃ��Ă̊p�x��ݒ�
	EVAENGINE_API void euler_angles(const Vector3& value);

	// �Ώۂ� Transform ��ݒ肵�A���̕����ւƌ������܂�
	EVAENGINE_API void look_at(const Transform& target, const Vector3& world_up = Vector3{ 0.0f, 1.0f, 0.0f });
	EVAENGINE_API void look_at(const Vector3& target, const Vector3& world_up = Vector3{ 0.0f, 1.0f, 0.0f });
	// Z ����eulers.z �x��]�AX���� euler.x �x��]�AY����eulers.y �x��]���܂�(���Ԃ͐���������)
	EVAENGINE_API void rotate(const Vector3& eulers, Space relative_to = Space::Self);
	EVAENGINE_API void rotate(float x, float y, float z, Space relative_to = Space::Self);
	// axis ���̎���� angle �x�A��]���܂�
	EVAENGINE_API void rotate(const Vector3& axis, float angle, Space relative_to = Space::Self);
	// ���[���h���W�� point �𒆐S�Ƃ�����(axis)�� angle �x��]�����܂�
	EVAENGINE_API void rotate_around(const Vector3& point, const Vector3& axis, float angle);

	// translation �̕����Ƌ����Ɉړ����܂�
	EVAENGINE_API void translate(const Vector3& translation, Space relative_to = Space::Self);

	// ���[�J�����W���烏�[���h���W�֕ϊ������s��
	EVAENGINE_API Matrix4x4 local_to_world_matrix() const;
	// ���[���h���W���烍�[�J�����W�֕ϊ������s��
	EVAENGINE_API Matrix4x4 world_to_local_matrix() const;

	// ���[�J����Ԃ��烏�[���h��Ԃ� position ��ϊ����܂��B(�X�P�[���E��]�E���s�ړ��j
	EVAENGINE_API Vector3 transform_point(const Vector3& position) const;
	// ���[�J����Ԃ��烏�[���h��Ԃ� vector ��ϊ����܂��B(�X�P�[���E��]�j
	EVAENGINE_API Vector3 transform_vector(const Vector3& vector) const;
	// ���[�J����Ԃ��烏�[���h��Ԃ� direction ��ϊ����܂�(��]�j
	EVAENGINE_API Vector3 transform_direction(const Vector3& direction) const;

	// ���[���h��Ԃ��烍�[�J����Ԃ� position ��ϊ����܂�
	EVAENGINE_API Vector3 inverse_transform_point(const Vector3& position) const;
	// ���[���h��Ԃ��烍�[�J����Ԃ� vector ��ϊ����܂�
	EVAENGINE_API Vector3 inverse_transform_vector(const Vector3& vector) const;
	// ���[���h��Ԃ��烍�[�J����Ԃ� direction ��ϊ����܂�
	EVAENGINE_API Vector3 inverse_transform_direction(const Vector3& direction) const;

	// Transform �̐e���擾
	EVAENGINE_API Transform* parent() const;
	// Transform �̐e��ݒ�
	EVAENGINE_API void parent(Transform* parent);
	// Transform �̐e��ݒ�
	EVAENGINE_API void set_parent(Transform* parent, bool world_position_stays = true);

	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȃX�P�[�����擾
	EVAENGINE_API Vector3 local_scale() const;
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȃX�P�[����ݒ�
	EVAENGINE_API void local_scale(const Vector3& value);
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�Ȉʒu���擾
	EVAENGINE_API Vector3 local_position() const;
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�Ȉʒu��ݒ�
	EVAENGINE_API void local_position(const Vector3& value);
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȉ�]���擾
	EVAENGINE_API Quaternion local_rotation() const;
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȉ�]��ݒ�
	EVAENGINE_API void local_rotation(const Quaternion& value);
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȃI�C���[�p�Ƃ��Ẳ�]�l���擾
	EVAENGINE_API Vector3 local_euler_angles() const;
	// �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȃI�C���[�p�Ƃ��Ẳ�]�l��ݒ�
	EVAENGINE_API void local_euler_angles(const Vector3& value);
	// ���ׂĂ̎q�I�u�W�F�N�g��e�I�u�W�F�N�g����؂藣���܂�
	EVAENGINE_API void detach_children();
	// �e�� Transform ����؂藣��
	EVAENGINE_API void detach_parent();

private:
	// ���[���h���W�n�̍X�V
	void update_world_transform(const Transform* parent);

private:
	// �|�W�V���� (���[���h���W�n)
	Vector3 position_{ 0.0f, 0.0f, 0.0f };
	// ��] (���[���h���W�n)
	Quaternion rotation_{ 0.0f, 0.0f, 0.0f, 1.0f };
	// �X�P�[�� (���[���h���W�n)
	Vector3 scale_{ 1.0f, 1.0f, 1.0f };

	// �|�W�V���� (���[�J�����W�n)
	Vector3 local_position_{ 0.0f, 0.0f, 0.0f };
	// ��] (���[�J�����W�n)
	Quaternion local_rotation_{ 0.0f, 0.0f, 0.0f, 1.0f };
	// �X�P�[�� (���[�J�����W�n)
	Vector3 local_scale_{ 1.0f, 1.0f, 1.0f };

	// �e�̃g�����X�t�H�[��
	Transform* parent_{ nullptr };
	// �q�̃g�����X�t�H�[��
	std::list<Transform*> children_;
};
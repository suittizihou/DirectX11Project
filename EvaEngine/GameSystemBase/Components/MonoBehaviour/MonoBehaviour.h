#pragma once

#include "../../Base/Component/Component.h"
#include "../../../Utility/Input/Input.h"
#include <vector>

class GameObject;
class Transform;

class MonoBehaviour : public Component {
public:
	MonoBehaviour(
		const UINT& functionMask,
		const bool canMultiAttach = true,
		const bool canRemove = true);
	virtual ~MonoBehaviour() = default;

	// ���O�Ō���
	EVAENGINE_API std::weak_ptr<GameObject> Find(const std::string& name);
	// �^�O�Ō������ăQ�[���I�u�W�F�N�g��������Ă���
	EVAENGINE_API std::weak_ptr<GameObject> FindGameObjectWithTag(const std::string& tag);
	// �^�O�Ō������ăq�b�g�����Q�[���I�u�W�F�N�g��S�������Ă���
	EVAENGINE_API std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag);

private:
	std::weak_ptr<Transform> m_Transform;
};
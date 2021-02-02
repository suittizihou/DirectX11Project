#pragma once

#include "GameObjectBase.h"
#include "../../Manager/ComponentManager/ComponentManager.h"

class Transform;

class GameObject final : public GameObjectBase {
public:
	GameObject(
		const SceneType& sceneType = SceneType::None,
		const UINT& gameObjectID = 0,
		const std::string& tag = "",
		const std::string& name = "") :
		GameObjectBase(sceneType),
		m_GameObjectID(gameObjectID),
		m_Tag(tag),
		m_Name(name)
	{};
	
	~GameObject() = default;

	// ����������
	void Initialize() override;

	// ObjectID��Ԃ�
	EVAENGINE_API UINT GetObjectID() const override;
	// ���O��Ԃ�
	EVAENGINE_API std::string GetName() const override;
	// �^�O��Ԃ�
	EVAENGINE_API std::string GetTag() const override;
	// Transform��Ԃ�
	EVAENGINE_API std::weak_ptr<Transform> GetTransform();

	// �R���|�[�l���g�̓o�^
	template<class T, class... Args>
	EVAENGINE_API std::weak_ptr<T> AddComponent(Args&& ... args) {
		return ComponentManager::Instance().AddComponent<T>(GetSceneType(), GetGameObject(), args...);
	}

	// �R���|�[�l���g�̎擾
	template<class T>
	EVAENGINE_API std::weak_ptr<T> GetComponent() {
		return ComponentManager::Instance().GetComponent<T>(GetSceneType(), m_GameObjectID);
	}

	// �R���|�[�l���g�̍폜
	template<class T>
	EVAENGINE_API void RemoveComponent() {
		ComponentManager::Instance().RemoveComponent<T>(GetSceneType(), m_GameObjectID);
	}

	// ���O�Ō���
	EVAENGINE_API std::weak_ptr<GameObject> Find(const std::string& name);
	// �^�O�Ō������ăQ�[���I�u�W�F�N�g��������Ă���
	EVAENGINE_API std::weak_ptr<GameObject> FindGameObjectWithTag(const std::string& tag);
	// �^�O�Ō������ăq�b�g�����Q�[���I�u�W�F�N�g��S�������Ă���
	EVAENGINE_API std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag);

private:
	std::weak_ptr<Transform> m_Transform;
	std::string m_Tag{};
	std::string m_Name{};
	UINT m_GameObjectID{};
};
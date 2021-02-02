#pragma once

#include <string>
#include <list>
#include <queue>
#include <map>
#include <memory>
#include <stdexcept>
#include <functional>
#include "../../Base/Component/Component.h"
#include "../../DataBase/ComponentDataBase/ComponentDataBase.h"
#include "../../Base/GameObject/GameObjectBase.h"
#include "../../Base/Scene/SceneType.h"

class ComponentManager {
private:
	ComponentManager() = default;
	ComponentManager(const ComponentManager&);
	ComponentManager& operator=(const ComponentManager&);
	~ComponentManager() = default;

public:
	static ComponentManager& Instance() {
		static ComponentManager componentManager;
		return componentManager;
	}

	// �R���|�[�l���g�f�[�^�x�[�X���V�[���ɒǉ�
	void AddComponentDataBase(const SceneType& sceneType);

	// �R���|�[�l���g�̓o�^
	template<class T, class... Args>
	std::weak_ptr<T> AddComponent(const SceneType& sceneType, const std::weak_ptr<GameObjectBase>& gameObject, Args&& ... args)
	{
		return m_ComponentList[sceneType]->AddComponent<T>(sceneType, gameObject, args...);
	}

	// �R���|�[�l���g�̎擾
	template<class T>
	std::weak_ptr<T> GetComponent(const SceneType& sceneType, const UINT& gameObjectID)
	{
		return m_ComponentList[sceneType]->GetComponent<T>(gameObjectID);
	}

	// �R���|�[�l���g���폜
	template<class T>
	void RemoveComponent(const SceneType& sceneType, const UINT& gameObjectID)
	{
		m_ComponentList[sceneType]->RemoveComponent<T>(gameObjectID);
	}

	// �ێ����Ă���R���|�[�l���g��S���폜
	void RemoveAllComponent(const SceneType& sceneType);

	// FixedUpdate�֐�����
	void FixedUpdate(const SceneType& sceneType);
	// Update�֐�����
	void Update(const SceneType& sceneType);
	// LateUpdate�֐�����
	void LateUpdate(const SceneType& sceneType);
	// Draw�֐�����
	void Draw(
		const SceneType& sceneType,
		const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command);

private:
	// �R���|�[�l���g�̃��X�g(first�̓I�u�W�F�N�gID)
	std::map<SceneType,		// GameObjectID
		std::shared_ptr<ComponentDataBase>> m_ComponentList;

	UINT m_ComponentID{};
};
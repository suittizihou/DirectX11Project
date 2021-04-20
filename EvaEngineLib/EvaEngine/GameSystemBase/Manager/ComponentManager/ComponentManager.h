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

namespace EvaEngine {

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
		void AddComponentDataBase(const std::string& sceneName);

		// �R���|�[�l���g�̓o�^
		template<class T, class... Args>
		std::weak_ptr<T> AddComponent(const std::string& sceneName, const std::weak_ptr<GameObjectBase>& gameObject, Args&& ... args)
		{
			return m_ComponentList[sceneName]->AddComponent<T>(sceneName, gameObject, args...);
		}

		// �R���|�[�l���g�̎擾
		template<class T>
		std::weak_ptr<T> GetComponent(const std::string& sceneName, const UINT& gameObjectID)
		{
			return m_ComponentList[sceneName]->GetComponent<T>(gameObjectID);
		}

		// �R���|�[�l���g���폜
		template<class T>
		void RemoveComponent(const std::string& sceneName, const UINT& gameObjectID)
		{
			m_ComponentList[sceneName]->RemoveComponent<T>(gameObjectID);
		}

		// �ێ����Ă���R���|�[�l���g��S���폜
		void RemoveAllComponent(const std::string& sceneName);

		// FixedUpdate�֐�����
		void FixedUpdate(const std::string& sceneName);
		// Update�֐�����
		void Update(const std::string& sceneName);
		// LateUpdate�֐�����
		void LateUpdate(const std::string& sceneName);
		// Draw�֐�����
		void Draw(
			const std::string& sceneName,
			const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command);

	private:
		// �R���|�[�l���g�̃��X�g(first�̓I�u�W�F�N�gID)
		std::map<std::string,		// GameObjectID
			std::shared_ptr<ComponentDataBase>> m_ComponentList;

		UINT m_ComponentID{};
	};
}
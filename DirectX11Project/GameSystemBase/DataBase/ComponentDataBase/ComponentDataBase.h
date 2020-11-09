#pragma once

#include <string>
#include <list>
#include <queue>
#include <map>
#include <memory>
#include <stdexcept>
#include "../../Base/Component/Component.h"

class ComponentDataBase {
public:
	ComponentDataBase() = default;
	~ComponentDataBase() = default;

	// �R���|�[�l���g�̓o�^
	template<class T, class... Args>
	std::weak_ptr<T> AddComponent(const SceneType& sceneType, const std::weak_ptr<GameObjectBase>& gameObject, Args&& ... args)
	{
		ComponentDesc componentDesc{};
		componentDesc.sceneType = sceneType;
		componentDesc.gameObject = gameObject;
		componentDesc.hashCode = typeid(T).hash_code();
		componentDesc.componentID = m_ComponentID;
		std::shared_ptr<T> component_temp = std::make_shared<T>(args...);
		component_temp->SetComponentDesc(componentDesc);

		// �����A�^�b�`�ł��Ȃ��R���|�[�l���g�̏ꍇ
		if (!component_temp->GetCanMultiAttach()) {
			// �����R���|�[�l���g���������`�F�b�N
			for (const auto& component : m_ComponentList[gameObject.lock()->GetObjectID()]) {
				if (componentDesc.hashCode == component->GetHashCode()) {
					throw std::runtime_error("Can't multi attach." + (std::string)typeid(T).name() + " : ���̃R���|�[�l���g�͕����A�^�b�`�ł��܂���");
					return std::weak_ptr<T>();
				}
			}
		}

		// �R���|�[�l���g��ǉ�(�֐��Ȃǂ��o�^)
		AddComponent(gameObject, component_temp);
		// �R���|�[�l���gID���C���N�������g
		m_ComponentID += 1;

		// �R���|�[�l���g�̏����֐����Ă�
		component_temp->Awake();
		component_temp->Start();


		// �Q�Ƃ�Ԃ�
		return component_temp;
	}

	// �R���|�[�l���g�̎擾
	template<class T>
	std::weak_ptr<T> GetComponent(const UINT& gameObjectID)
	{
		// �R���|�[�l���g����
		for (const auto& component : m_ComponentList[gameObjectID]) {
			// �w�肵���R���|�[�l���g��ID�Ɠ���ID�̕���������΂����Ԃ�
			if (typeid(T).hash_code() == component->GetHashCode()) {
				// dynamic_cast���g�p���Ă��Ȃ��̂͌^�ϊ��`�F�b�N�ɂ�鑬�x�ቺ��h������
				return std::static_pointer_cast<T>(component);
			}
		}

		throw std::runtime_error(
			"Not found. : Name : " +
			(std::string)typeid(T).name() +
			" : " +
			std::to_string(typeid(T).hash_code()) +
			" : �R���|�[�l���g��������܂���ł���");
		return std::weak_ptr<T>();
	}

	// �R���|�[�l���g���폜
	template<class T>
	void RemoveComponent(const UINT& gameObjectID)
	{
		size_t hashCode = typeid(T).hash_code();
		for (const auto& component : m_ComponentList[gameObjectID]) {
			// ����ID����������
			if (hashCode == component->GetHashCode()) {
				// �����Ȃ��R���|�[�l���g�Ȃ瑁�����^�[��
				if (!component->GetCanRemove()) {
					throw std::runtime_error(
						"Can't remove component : " +
						(std::string)typeid(T).name() +
						" : " +
						std::to_string(typeid(T).hash_code()) +
						" : ���̃R���|�[�l���g�͏����܂���");
					return;
				}

				// �����Ώۂ̃I�u�W�F�N�gID�ƃR���|�[�l���g�̃n�b�V���l��Queue�ɒǉ�
				std::map<UINT, size_t> removeList{ { gameObjectID, hashCode } };
				m_RemoveHashQueue.push(removeList);
				return;
			}
		}

		throw std::runtime_error(
			"Not found.: Name : " +
			(std::string)typeid(T).name() +
			" : " +
			std::to_string(typeid(T).hash_code()) +
			" : �R���|�[�l���g��������܂���ł���");
	}

	// �폜�˗����o�Ă�R���|�[�l���g������
	void RunRemoveComponents();
	// �ێ����Ă���R���|�[�l���g��S���폜
	void RemoveAllComponent();

	// FixedUpdate�֐�����
	void FixedUpdate();
	// Update�֐�����
	void Update();
	// LateUpdate�֐�����
	void LateUpdate();
	// Draw�֐�����
	void Draw(
		const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command) const;

private:
	template<class T>
	void AddComponent(const std::weak_ptr<GameObjectBase>& gameObject, std::shared_ptr<T> component) {
		// FixedUpdate�֐��̓o�^
		if (component->GetFunctionMask() & FunctionMask::FIXED_UPDATE) {
			m_FixedUpdateFunctionList[gameObject.lock()->GetObjectID()][m_ComponentID] = [=]()
				->void { return component->FixedUpdate(); };
		}
		// Update�֐��̓o�^
		if (component->GetFunctionMask() & FunctionMask::UPDATE) {
			m_UpdateFunctionList[gameObject.lock()->GetObjectID()][m_ComponentID] = [=]()
				->void { return component->Update(); };
		}
		// LateUpdate�֐��̓o�^
		if (component->GetFunctionMask() & FunctionMask::LATE_UPDATE) {
			m_LateUpdateFunctionList[gameObject.lock()->GetObjectID()][m_ComponentID] = [=]()
				->void { return component->LateUpdate(); };
		}
		// Draw�֐��̓o�^
		if (component->GetFunctionMask() & FunctionMask::DRAW) {
			m_DrawFunctionList[gameObject.lock()->GetObjectID()][m_ComponentID] = [=](const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command)
				->void { return component->Draw(command); };
		}
		// �R���|�[�l���g�̓o�^
		m_ComponentList[gameObject.lock()->GetObjectID()].push_back(component);
	}


private:
	// �R���|�[�l���g�̃��X�g(first�̓I�u�W�F�N�gID)
	std::map<UINT,		// GameObjectID
		std::list<std::shared_ptr<Component>>> m_ComponentList;

	// FixedUpdate�֐��̃��X�g
	std::map <UINT,	// GameObjectID
		std::map<UINT,	// ComponentID
		std::function<void()>>> m_FixedUpdateFunctionList;

	// Update�֐��̃��X�g
	std::map<UINT,		// GameObjectID
		std::map<UINT,	// ComponentID
		std::function<void()>>> m_UpdateFunctionList;

	// LateUpdate�֐��̃��X�g
	std::map<UINT,		// GameObjectID
		std::map<UINT,	// ComponentID
		std::function<void()>>> m_LateUpdateFunctionList;

	// Draw�֐��̃��X�g
	std::map<UINT,		// GameObjectID
		std::map<UINT,	// ComponentID
		std::function<void(const Microsoft::WRL::ComPtr<ID3D11DeviceContext>&)>>> m_DrawFunctionList;

	// �폜�\��̃n�b�V���L���[
	std::queue<std::map<UINT, size_t>> m_RemoveHashQueue;

	UINT m_ComponentID{};
};
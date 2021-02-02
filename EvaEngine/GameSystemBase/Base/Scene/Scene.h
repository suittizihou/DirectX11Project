#pragma once

#include "../../Manager/ComponentManager/ComponentManager.h"
#include "../../Manager/GameObjectManager/GameObjectManager.h"
#include "../../../GameSystemBase/Components/ComponentHeaders.h"

#include "SceneType.h"

class Scene {
public:
	Scene(const SceneType& sceneType) : m_SceneType(sceneType) {};
	virtual ~Scene() = default;

public:
	// �V�[���̏�����
	virtual void Initialize() = 0;

	// �V�[���̃A�b�v�f�[�g
	virtual void SceneUpdate() = 0;

	// �Œ�X�V����
	void FixedUpdate() {
		ComponentManager::Instance().FixedUpdate(m_SceneType);
	}

	// �X�V����
	void Update() {
		ComponentManager::Instance().Update(m_SceneType);
	};

	// �x���X�V����
	void LateUpdate() {
		ComponentManager::Instance().LateUpdate(m_SceneType);
	}

	// �`�揈��
	void Draw(const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command)
	{
		ComponentManager::Instance().Draw(m_SceneType, command);
	};

	// ���O�Ō���
	EVAENGINE_API std::weak_ptr<GameObject> Find(const std::string& name);
	// �^�O�Ō������ăQ�[���I�u�W�F�N�g��������Ă���
	EVAENGINE_API std::weak_ptr<GameObject> FindGameObjectWithTag(const std::string& tag);
	// �^�O�Ō������ăq�b�g�����Q�[���I�u�W�F�N�g��S�������Ă���
	EVAENGINE_API std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag);


	EVAENGINE_API std::weak_ptr<GameObject> AddGameObject(const std::string& tag = "None", const std::string& name = "GameObject");

protected:
	SceneType m_SceneType{};
};
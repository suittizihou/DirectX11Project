#pragma once

#include <list>
#include <memory>

#include "../../Base/Scene/SceneType.h"
#include "../../DataBase/GameObjectDataBase/GameObjectDataBase.h"

class GameObject;

class GameObjectManager {
private:
	GameObjectManager() = default;
	~GameObjectManager() = default;

	GameObjectManager(const GameObjectManager&);
	GameObjectManager& operator=(const GameObjectManager&);

public:
	static GameObjectManager& Instance() {
		static GameObjectManager gameObjectManager;
		return gameObjectManager;
	}

	// �Q�[���I�u�W�F�N�g�f�[�^�x�[�X���V�[���ɒǉ�
	void AddGameObjectDataBase(const SceneType& sceneType);

	std::weak_ptr<GameObject> AddGameObject(const SceneType& sceneType, const std::string& tag, const std::string& name);
	// ���O�Ō���
	std::weak_ptr<GameObject> Find(const SceneType& sceneType, const std::string& name);
	// �^�O�Ō������ăQ�[���I�u�W�F�N�g��������Ă���
	std::weak_ptr<GameObject> FindGameObjectWithTag(const SceneType& sceneType, const std::string& tag);
	// �^�O�Ō������ăq�b�g�����Q�[���I�u�W�F�N�g��S�������Ă���
	std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(const SceneType& sceneType, const std::string& tag);
	// �ێ����Ă���Q�[���I�u�W�F�N�g��S�폜
	void RemoveAllGameObject(const SceneType& sceneType);
	// �ێ����Ă���Q�[���I�u�W�F�N�g��S�폜
	void RemoveAllGameObject();

private:
	UINT m_ObjectID{};
	std::map <SceneType,	// Tag 
		std::shared_ptr<GameObjectDataBase>> m_GameObjectList;
};
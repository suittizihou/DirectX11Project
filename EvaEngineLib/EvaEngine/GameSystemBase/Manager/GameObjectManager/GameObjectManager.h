#pragma once

#include <list>
#include <memory>

#include "../../DataBase/GameObjectDataBase/GameObjectDataBase.h"

namespace EvaEngine {
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
		void AddGameObjectDataBase(const std::string& sceneName);

		std::weak_ptr<GameObject> AddGameObject(const std::string& sceneName, const std::string& tag, const std::string& name);
		// ���O�Ō���
		std::weak_ptr<GameObject> Find(const std::string& sceneName, const std::string& name);
		// �^�O�Ō������ăQ�[���I�u�W�F�N�g��������Ă���
		std::weak_ptr<GameObject> FindGameObjectWithTag(const std::string& sceneName, const std::string& tag);
		// �^�O�Ō������ăq�b�g�����Q�[���I�u�W�F�N�g��S�������Ă���
		std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(const std::string& sceneName, const std::string& tag);
		// �ێ����Ă���Q�[���I�u�W�F�N�g��S�폜
		void RemoveAllGameObject(const std::string& sceneName);
		// �ێ����Ă���Q�[���I�u�W�F�N�g��S�폜
		void RemoveAllGameObject();

	private:
		UINT m_ObjectID{};
		std::map <std::string,	// Tag 
			std::shared_ptr<GameObjectDataBase>> m_GameObjectList;
	};
}
#include "GameObjectManager.h"

#include <stdexcept>

#include "../../Base/GameObject/GameObject.h"
#include "../../Components/Transform/Transform.h"

using namespace EvaEngine;

void GameObjectManager::AddGameObjectDataBase(const std::string& sceneName)
{
	m_GameObjectList[sceneName] = std::make_shared<GameObjectDataBase>();
}

std::weak_ptr<GameObject> GameObjectManager::AddGameObject(const std::string& sceneName, const std::string& tag, const std::string& name) {
	return m_GameObjectList[sceneName]->AddGameObject(sceneName, tag, name);
}

std::weak_ptr<GameObject> GameObjectManager::Find(const std::string& sceneName, const std::string& name)
{
	return m_GameObjectList[sceneName]->Find(name);
}

std::weak_ptr<GameObject> GameObjectManager::FindGameObjectWithTag(const std::string& sceneName, const std::string& tag)
{
	return m_GameObjectList[sceneName]->FindGameObjectWithTag(tag);
}

std::vector<std::weak_ptr<GameObject>> GameObjectManager::FindGameObjectsWithTag(const std::string& sceneName, const std::string& tag)
{
	return m_GameObjectList[sceneName]->FindGameObjectsWithTag(tag);
}

void GameObjectManager::RemoveAllGameObject(const std::string& sceneName)
{
	m_GameObjectList[sceneName]->RemoveAllGameObject();
}

void GameObjectManager::RemoveAllGameObject()
{
	for (const auto& gameObjectList : m_GameObjectList) {
		gameObjectList.second->RemoveAllGameObject();
	}
}

#include "GameObject.h"
#include "../../Components/Transform/Transform.h"
#include "../../Manager/GameObjectManager/GameObjectManager.h"

using namespace EvaEngine;

void GameObject::Initialize()
{
    m_Transform = AddComponent<Transform>();
}

UINT GameObject::GetObjectID() const
{
    return m_GameObjectID;
}

std::string GameObject::GetName() const
{
    return m_Name;
}

std::string GameObject::GetTag() const
{
    return m_Tag;
}

std::weak_ptr<Transform> GameObject::GetTransform()
{
    return m_Transform;
}

std::weak_ptr<GameObject> GameObject::Find(const std::string& name)
{
    return GameObjectManager::Instance().Find(GetSceneType(), name);
}

std::weak_ptr<GameObject> GameObject::FindGameObjectWithTag(const std::string& tag)
{
    return GameObjectManager::Instance().FindGameObjectWithTag(GetSceneType(), tag);
}

std::vector<std::weak_ptr<GameObject>> GameObject::FindGameObjectsWithTag(const std::string& tag)
{
    return GameObjectManager::Instance().FindGameObjectsWithTag(GetSceneType(), tag);
}

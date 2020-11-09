#pragma once

#include <wrl/client.h>
#include <functional>
#include <list>
#include <d3d11.h>
#include <memory>
#include <bitset>

#pragma comment(lib,"d3d12.lib")

#include "../Scene/SceneType.h"

class GameObject;

class GameJobs {
public:
	GameJobs() {};
	virtual ~GameJobs() = default;

	std::weak_ptr<GameObject> AddGameObject();

	// ��������V�[����ݒ�
	void SetSceneType(const SceneType& sceneType);
	// ��������V�[����Ԃ�
	SceneType GetSceneType();

private:
	SceneType m_SceneType{};

private:
	GameJobs (const GameJobs&);
	void operator=(const GameJobs& obj);
};
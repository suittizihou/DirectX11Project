#pragma once

#include <wrl/client.h>
#include <functional>
#include <list>
#include <d3d11.h>
#include <memory>
#include <bitset>

#pragma comment(lib,"d3d12.lib")

#include "../Scene/SceneType.h"

#ifdef EVAENGINE_EXPORTS
#define __declspec(dllexport)
#else
#define __declspec(dllimport)
#endif

class GameObject;

class GameJobs {
public:
	GameJobs() {};
	virtual ~GameJobs() = default;

	// �Q�[���I�u�W�F�N�g�̒ǉ�
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
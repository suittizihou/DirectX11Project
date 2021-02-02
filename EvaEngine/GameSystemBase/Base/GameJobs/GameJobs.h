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
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

class GameObject;

class GameJobs {
public:
	GameJobs() {};
	virtual ~GameJobs() = default;

	// �Q�[���I�u�W�F�N�g�̒ǉ�
	EVAENGINE_API std::weak_ptr<GameObject> AddGameObject();

	// ��������V�[����ݒ�
	EVAENGINE_API void SetSceneType(const SceneType& sceneType);
	// ��������V�[����Ԃ�
	EVAENGINE_API SceneType GetSceneType();

private:
	SceneType m_SceneType{};

private:
	GameJobs (const GameJobs&);
	void operator=(const GameJobs& obj);
};
#pragma once

#include <wrl/client.h>
#include <functional>
#include <list>
#include <d3d11.h>
#include <memory>
#include <bitset>

#pragma comment(lib,"d3d12.lib")

namespace EvaEngine {

	class GameObject;

	class GameJobs {
	public:
		GameJobs() {};
		virtual ~GameJobs() = default;

		// �Q�[���I�u�W�F�N�g�̒ǉ�
		std::weak_ptr<GameObject> AddGameObject(const std::string& tag = "None", const std::string& name = "GameObject");

		// ��������V�[����ݒ�
		void SetSceneName(const std::string& sceneType);
		// ��������V�[����Ԃ�
		std::string GetSceneType();

	private:
		std::string m_SceneName{};

	private:
		GameJobs(const GameJobs&);
		void operator=(const GameJobs& obj);
	};
}
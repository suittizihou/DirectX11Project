#pragma once

#include <memory>
#include "../GameJobs/GameJobs.h"

namespace EvaEngine {

	class GameObjectBase : public GameJobs, public std::enable_shared_from_this<GameObjectBase> {
	public:
		GameObjectBase(const std::string& sceneName) :
			GameJobs()
		{
			SetSceneName(sceneName);
		};
		virtual ~GameObjectBase() = default;

		// ����������
		virtual void Initialize() = 0;

		// ���g��weak_ptr��Ԃ�
		std::weak_ptr<GameObjectBase> GetGameObject() { return shared_from_this(); }

		// ObjectID��Ԃ�
		virtual UINT GetObjectID() const = 0;
		// ���O��Ԃ�
		virtual std::string GetName() const = 0;
		// �^�O��Ԃ�
		virtual std::string GetTag() const = 0;
	};
}
#pragma once

#include "../../Base/Scene/Scene.h"
#include "../../DataBase/SceneDataBase/SceneDataBase.h"

class SceneManager {
public:
	SceneManager() = default;
	~SceneManager() = default;

	typedef unsigned int UINT;

public:
	// �V�[���̒ǉ�
	template<class T>
	EVAENGINE_API static void AddScene(const SceneType& sceneType) {
		SceneDataBase::Instance().AddScene<T>(sceneType);
	}

	// �V�[���̃��[�h
	EVAENGINE_API static void LoadScene(const SceneType& sceneType);
	EVAENGINE_API static void LoadScene(const UINT& sceneType);
	
	// ���݂̃V�[�����擾
	EVAENGINE_API static SceneType GetCurrentScene();
};
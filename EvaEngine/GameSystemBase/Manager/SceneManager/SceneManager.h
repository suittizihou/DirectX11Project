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
	static void AddScene(const SceneType& sceneType) {
		SceneDataBase::Instance().AddScene<T>(sceneType);
	}

	// �V�[���̃��[�h
	static void LoadScene(const SceneType& sceneType);
	static void LoadScene(const UINT& sceneType);
	
	// ���݂̃V�[�����擾
	static SceneType GetCurrentScene();
};
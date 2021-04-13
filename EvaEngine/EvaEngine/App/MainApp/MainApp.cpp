#include "MainApp.h"
#include "../WindowApp/WindowApp.h"
#include "../DirectX11App/DirectX11App.h"
#include "../EvaEngineApp/EvaEngineApp.h"
#include "../../GameSystemBase/Base/GameBase/GameBase.h"

bool EvaEngine::MainApp::Init()
{
	// �E�B���h�E�̏�����
	HRESULT hr = WindowApp::Init();
	if (FAILED(hr)) {
		DebugLog::LogError("Window initialize failed.");
		return false;
	}

	// DirectX11�̏�����
	hr = DirectX11App::Init();
	if (FAILED(hr)) {
		DebugLog::LogError("DirectX initialize failed.");
		return false;
	}

	// ���[�U�[�̏���������(�V�[���̒ǉ��Ȃǂ����邽�߂����ł���)
	GameBase::Instance()->Init();

	// �G���W���̏�����
	hr = EvaEngineApp::Instance().Init();
	if (FAILED(hr)) {
		DebugLog::LogError("EvaEngine initialize failed.");
		return false;
	}

	return true;
}

int EvaEngine::MainApp::Run()
{
	return WindowApp::Update();
}

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#endif

#include "../../Setting/Window/Window.h"
#include <stdexcept>

#if _DEBUG
#define NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
#if _DEBUG
	// ���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	EvaEngine::Window::g_hInstance = hInstance;
	EvaEngine::Window::g_nCmdShow = nCmdShow;

	// EvaEngine�̏�����
	if (FAILED(EvaEngine::MainApp::Instance().Init())) {
		EvaEngine::DebugLog::LogError("EvaEngine initialize failed.");
		return -1;
	}

	int result = EvaEngine::MainApp::Instance().Run();

	// ���b�Z�[�W���[�v
	return result;
}
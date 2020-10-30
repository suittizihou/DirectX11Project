#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#endif

#include <Windows.h>
#include <stdexcept>
#include "Setting/Window/Window.h"
#include "App/WindowApp/WindowApp.h"
#include "System/DebugLog/DebugLog.h"

#if _DEBUG
#define NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
#if _DEBUG
    // ���������[�N���o(����͈̔͂����o���邽�߂̂���)
    _CrtMemState s1;
    _CrtMemCheckpoint(&s1);
#endif

    Window::hInstance = hInstance;
    Window::nCmdShow = nCmdShow;

    // �E�B���h�E�̏�����
    if (!WindowApp::Init()) {
        DebugLog::LogError("Window Initialize Failed.");
        return -1;
    }

    int result = WindowApp::Update();

#if _DEBUG
    _CrtMemDumpAllObjectsSince(&s1);
#endif

    // ���b�Z�[�W���[�v
    return result;
}
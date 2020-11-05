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

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
#if _DEBUG
    // ���������[�N���o
    //_CrtMemState s1;
    //_CrtMemCheckpoint(&s1);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif


    Window::g_hInstance = hInstance;
    Window::g_nCmdShow = nCmdShow;

    // �E�B���h�E�̏�����
    if (FAILED(WindowApp::Init())) {
        DebugLog::LogError("Window Initialize Failed.");
        return -1;
    }

    int result = WindowApp::Update();

//#if _DEBUG
//    _CrtMemDumpAllObjectsSince(&s1);
//#endif

    // ���b�Z�[�W���[�v
    return result;
}
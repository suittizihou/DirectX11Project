#include <Windows.h>
#include <stdexcept>
#include "Setting/Window/Window.h"
#include "App/WindowApp/WindowApp.h"
#include "System/DebugLog/DebugLog.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow){
    // ���������[�N���o(�v���O�����̏I�����Ɏ����I�� _CrtDumpMemoryLeaks() ��}�����Ă������̂炵��)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Window::hInstance = hInstance;
    Window::nCmdShow = nCmdShow;

    // �E�B���h�E�̏�����
    if (!WindowApp::Init()) {
        DebugLog::LogError("Window Initialize Failed.");
        return -1;
    }

    // ���b�Z�[�W���[�v
    return WindowApp::Update();
}
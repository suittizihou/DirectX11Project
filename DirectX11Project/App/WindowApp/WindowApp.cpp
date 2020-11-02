#include "WindowApp.h"
#include <wrl.h>
#include "../../Setting/Window/Window.h"
#include "../../System/DebugLog/DebugLog.h"
#include "../../Utility/Input/InputBufferUpdate/InputBufferUpdate.h"
#include "../../Utility/Input/Input.h"
#include "../DirectX11App/DirectX11App.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    PAINTSTRUCT ps;
    HDC hdc;
    switch (msg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wp, lp);
}

HRESULT WindowApp::Init()
{
    HRESULT hr{};

    // COM���C�u�������������������(COM�Ƃ̓R���|�[�l���g�E�I�u�W�F�N�g�E���f���̗�)
    // COM���C�u�������g�����Ɏg���X���b�h�ŏ��Ȃ��Ƃ��P��͎��s����K�v������B
    // D3D�֘A�̐F��ȃN���X������COM�𗘗p���Ď�������Ă���A���������K�v������(���Ԃ�)
    hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

    if (FAILED(hr)) {
        DebugLog::LogError("COM Initialize Failed.");
        return hr;
    }

    WNDCLASSEX wc{};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = Window::g_hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"HelloDirectX12";
    if (!RegisterClassEx(&wc)) {
        DebugLog::LogError("WNDCLASSEX Initialize Failed.");
        return hr;
    }

    DWORD dwStyle = WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX;
    RECT rect = { 0,0, static_cast<LONG>(Window::g_WindowRight), static_cast<LONG>(Window::g_WindowBottom) };
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // �E�B���h�E�𐶐�
    Window::g_hWnd = CreateWindow(wc.lpszClassName, L"DirectX11App",
        dwStyle,
        CW_USEDEFAULT, CW_USEDEFAULT,
        Window::g_WindowRight - Window::g_WindowLeft, Window::g_WindowBottom - Window::g_WindowTop,
        nullptr,
        nullptr,
        wc.hInstance,
        nullptr
    );

    ShowWindow(Window::g_hWnd, Window::g_nCmdShow);

    return hr;
}

int WindowApp::Update()
{
    UpdateWindow(Window::g_hWnd);

    if (FAILED(DirectX11App::Init())) {
        DebugLog::LogError("DirectX Initialize Failed.");
        return -1;
    }

    MSG msg{};
    while (msg.message != WM_QUIT) {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            InputBufferUpdate::Instance().KeyUpdate();
        }
    }
    return static_cast<int>(msg.wParam);
}

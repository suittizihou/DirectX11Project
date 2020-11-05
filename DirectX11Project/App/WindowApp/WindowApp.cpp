#include "WindowApp.h"
#include <wrl.h>
#include "../../Setting/Window/Window.h"
#include "../../Utility/Input/InputBufferUpdate/InputBufferUpdate.h"
#include "../../Utility/Input/Input.h"
#include "../DirectX11App/DirectX11App.h"
#include "../../Utility/ModelUtility/ModelData/ModelData.h"
#include "../../Utility/BufferCreate/BufferCreate.h"
#include "../../GameSystemBase/Manager/DrawManager/DrawManager.h"
//#include "../../Utility/Material/Material.h"
#include "../../Utility/ShaderUtility/Shader/Shader.h"
#include "../../Utility/ResourceLoad/ResourceLoad.h"
#include "../../GameSystemBase/DataBase/ShaderDataBase/ShaderDataBase.h"

#include <vector>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    
    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
        break;
    }

    return 0;
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

    WNDCLASSEX wc {
        sizeof(WNDCLASSEX),
        CS_HREDRAW | CS_VREDRAW,
        WndProc,
        0L,
        0L,
        GetModuleHandle(NULL),
        NULL,
        LoadCursor(NULL, IDC_ARROW),
        NULL,
        NULL,
        Window::g_WindowName.c_str(),
        NULL
    };

    if (!RegisterClassEx(&wc)) {
        DebugLog::LogError("WNDCLASSEX Initialize Failed.");
        return hr;
    }

    RECT rect = { 0,0, static_cast<LONG>(Window::g_WindowRight), static_cast<LONG>(Window::g_WindowBottom) };

    // �E�B���h�E�𐶐�
    Window::g_hWnd = CreateWindow(
        Window::g_WindowName.c_str(),
        Window::g_WindowName.c_str(),
        (WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE,
        CW_USEDEFAULT,
        0,
        Window::g_WindowRight - Window::g_WindowLeft, 
        Window::g_WindowBottom - Window::g_WindowTop,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (!Window::g_hWnd) {
        DebugLog::LogError("Window Create Failed.");
        return E_FAIL;
    }

    RECT window_rect{};
    RECT client_rect{};

    GetWindowRect(Window::g_hWnd, &window_rect);
    GetClientRect(Window::g_hWnd, &client_rect);

    int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
    int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

    SetWindowPos(
        Window::g_hWnd, 
        NULL, 
        CW_USEDEFAULT, 
        0, 
        frame_size_x + static_cast<int>(Window::GetViewport().Width), 
        frame_size_y + static_cast<int>(Window::GetViewport().Height), 
        SWP_NOMOVE);

    ShowWindow(Window::g_hWnd, SW_SHOW);
    UpdateWindow(Window::g_hWnd);

    return hr;
}

int WindowApp::Update()
{

    if (FAILED(DirectX11App::Init())) {
        DebugLog::LogError("DirectX Initialize Failed.");
        return -1;
    }

    ResourceLoad resources{};
    resources.Load();

    My3DLib::ModelData::Model model{};


    My3DLib::Material material{};
    material.g_Shader.SetVertexShader(0);
    material.g_Shader.SetPixelShader(0);
    model.materials[""].push_back(material);

    std::vector<My3DLib::ModelData::VertexData> vertexs =
    {
        { DirectX::XMFLOAT3(-0.5f,-0.5f, 0.0f), DirectX::XMFLOAT4(1,0,0,1) },   // ��
        { DirectX::XMFLOAT3( 0.5f,-0.5f, 0.0f), DirectX::XMFLOAT4(0,1,0,1) },   // ��
        { DirectX::XMFLOAT3( 0.5f, 0.5f, 0.0f), DirectX::XMFLOAT4(0,0,1,1) },   // ��
        { DirectX::XMFLOAT3(-0.5f, 0.5f, 0.0f), DirectX::XMFLOAT4(0,0,0,1) }    // ��
    };
    My3DLib::Mesh mesh{};
    mesh.SetVertices(vertexs);
    model.meshes[""].push_back(mesh);
    
    BufferCreate::SetVertexBuffer(model.meshes);

    D3D11_INPUT_ELEMENT_DESC elem[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    InputLayout inputLayout{ nullptr };
    inputLayout.Attach(ShaderCompiler::CreateInputLayout(elem, 2, "Shader/VertexShader.hlsl", "vsMain"));

    // �C���f�b�N�X���̐ݒ�
    std::vector<UINT> idxs = { 0, 3, 2, 0, 2, 1 };
    IndexBuffer ib{ nullptr };
    ib.Attach(BufferCreate::SetIndexBuffer(idxs.data(), static_cast<UINT>(idxs.size())));

    MSG msg{};
    while (msg.message != WM_QUIT) {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {

            if (msg.message == WM_QUIT) {
                break;
            }
            else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else {
            InputBufferUpdate::Instance().KeyUpdate();
            DirectX11App::Update();

            DrawManager::DrawBegin();

            DrawManager::SetInputLayout(inputLayout.Get());
            DrawManager::SetVertexBuffer(vb.Get(), sizeof(ModelData::VertexData));
            DrawManager::SetIndexBuffer(ib.Get());
            DirectX11App::g_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
            DrawManager::SetShader(material);
            DirectX11App::g_Context->OMSetRenderTargets(1, DirectX11App::g_RenderTargetView.GetAddressOf(), DirectX11App::g_DepthStencilView.Get());

            DrawManager::DrawIndexed(static_cast<UINT>(idxs.size()));

            DrawManager::DrawEnd();
        }
    }


    return static_cast<int>(msg.wParam);
}

#include "EvaEngineApp.h"
#include "../../Setting/Window/Window.h"
#include "../DirectX11App/DirectX11App.h"
#include "../../GameSystemBase/DataBase/ModelDataBase/ModelDataBase.h"
#include "../../GameSystemBase/DataBase/ShaderDataBase/ShaderDataBase.h"
#include "../../GameSystemBase/DataBase/TextureDataBase/TextureDataBase.h"
#include "../../GameSystemBase/DataBase/SceneDataBase/SceneDataBase.h"
#include "../../GameSystemBase/Manager/DrawManager/DrawManager.h"

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <iostream>

using namespace EvaEngine;

EvaEngineApp::~EvaEngineApp() {
}

HRESULT EvaEngineApp::Init()
{
	HRESULT hr{};

	// �`��}�l�[�W���[�̏�����
	hr = DrawManager::Init();
	if (FAILED(hr)) {
		DebugLog::LogError("DrawManager�̏������Ɏ��s���܂����B");
		return hr;
	}

	// �V�[���̏�����
	hr = SceneDataBase::Instance().InitializeScene();
	if (FAILED(hr)) {
		DebugLog::LogError("�V�[���̏������Ɏ��s���܂����B");
		return hr;
	}

	// ImGui�̏�����
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsLight();

	if (!ImGui_ImplWin32_Init(Window::g_hWnd)) {
		DebugLog::LogError("ImGui_ImplWin32_Init�Ɏ��s���܂����B");
		ImGui::DestroyContext();
		UnregisterClass(Window::g_wc.lpszClassName, Window::g_wc.hInstance);
		hr = E_ABORT;
		return hr;
	}

	if (!ImGui_ImplDX11_Init(DirectX11App::g_Device.Get(), DirectX11App::g_Context.Get())) {
		DebugLog::LogError("ImGui_ImplDX11_Init�Ɏ��s���܂����B");
		ImGui::DestroyContext();
		UnregisterClass(Window::g_wc.lpszClassName, Window::g_wc.hInstance);
		hr = E_ABORT;
		return hr;
	}

	// ini�𐶐����Ȃ�
	io.IniFilename = NULL;
	// ���{��t�H���g�ɑΉ�
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\meiryo.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());

	return S_OK;
}

void EvaEngineApp::Update()
{
	SceneDataBase::Instance().SceneUpdate();
	SceneDataBase::Instance().FixedUpdate();
	SceneDataBase::Instance().Update();
	SceneDataBase::Instance().LateUpdate();
}

void EvaEngineApp::Draw(const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command)
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// �`��J�n����
	DrawManager::DrawBegin();

	// �|���S���̎��
	DirectX11App::g_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// �V�F�[�_�[�̃Z�b�g
	Shader shader{ DrawManager::GetDefaultShader() };
	DrawManager::SetShader(shader);
	// �����_�[�^�[�Q�b�g�̐ݒ�
	DirectX11App::g_Context->OMSetRenderTargets(1, DirectX11App::g_RenderTargetView.GetAddressOf(), DirectX11App::g_DepthStencilView.Get());

	// �`��
	SceneDataBase::Instance().Draw(command);

	ImGui::Begin("Test Window");

	ImGui::Text("Hello world");

	if (ImGui::Button("OK")) {
		std::cout << "Button" << std::endl;
	}

	static float f = 0.0f;
	if (ImGui::SliderFloat("float", &f, 0.0f, 1.0f)) {
		std::cout << "SliderFloat" << std::endl;
	}

	ImGui::End();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	// �`��I������
	DrawManager::DrawEnd();
}

void EvaEngineApp::FrameEnd()
{
	SceneDataBase::Instance().SceneChange();
}

void EvaEngine::EvaEngineApp::End()
{
	// ImGui�̉��
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

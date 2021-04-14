#include "EvaEngineApp.h"
#include "../DirectX11App/DirectX11App.h"
#include "../../GameSystemBase/DataBase/ModelDataBase/ModelDataBase.h"
#include "../../GameSystemBase/DataBase/ShaderDataBase/ShaderDataBase.h"
#include "../../GameSystemBase/DataBase/TextureDataBase/TextureDataBase.h"
#include "../../GameSystemBase/DataBase/SceneDataBase/SceneDataBase.h"
#include "../../GameSystemBase/Manager/DrawManager/DrawManager.h"

using namespace EvaEngine;

EvaEngineApp::~EvaEngineApp() {
}

HRESULT EvaEngineApp::Init()
{
	HRESULT hr{};

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

	// �`��I������
	DrawManager::DrawEnd();
}

void EvaEngineApp::Last()
{
	SceneDataBase::Instance().SceneChange();
}

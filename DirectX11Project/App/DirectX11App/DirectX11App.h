#pragma once
#include "../../Define/D3D11Defines.h"

class DirectX11App {
public:
	static HRESULT Init();
	static int Update();

private:
	// �n�[�h�E�F�A�̃`�F�b�N(���GPU�������Ă���GPU���g���悤�ɂ���)
	static HRESULT HardWareCheck();
	// DirectX�̏�����
	static HRESULT DirectXInit();

public:
	static D3DDevice g_Device;
	static D3DContext g_Context;
	static SwapChain g_SwapChain;
	static Texture2D g_BuckBufferTexture;
	static RenderTargetView g_RenderTargetView;

private:
	static Microsoft::WRL::ComPtr<IDXGIAdapter> m_Adapter;
};
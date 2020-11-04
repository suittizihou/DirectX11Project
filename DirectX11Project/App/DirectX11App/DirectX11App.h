#pragma once
#include "../../Define/D3D11Defines.h"
#include "../../System/DebugLog/DebugLog.h"

class DirectX11App {
public:
	// DirectX�̏�����
	static HRESULT Init();
	static int Update();

private:
	// �n�[�h�E�F�A�̃`�F�b�N(���GPU�������Ă���GPU���g���悤�ɂ���)
	static HRESULT HardWareCheck();
	// �f�o�C�X�ƃX���b�v�`�F�C���̍쐬
	static HRESULT CreateDeviceAndSwapChain();
	// �����_�[�^�[�Q�b�g�̍쐬
	static HRESULT CreateRenderTargetView();
	// �[�x�X�e���V���r���[�̍쐬
	static HRESULT CreateDepthAndStencilView();

public:
	static D3DDevice g_Device;
	static D3DContext g_Context;
	static SwapChain g_SwapChain;
	static RenderTargetView g_RenderTargetView;
	static DepthStencilView g_DepthStencilView;

private:
	static IDXGIAdapter* m_Adapter;
};
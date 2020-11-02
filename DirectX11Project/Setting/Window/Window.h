#pragma once
#include <Windows.h>

struct D3D11_VIEWPORT;

class Window {
public:
	// DirectX11�Ŏg��Viewport�ɂ��ĕԂ�
	static D3D11_VIEWPORT GetViewport();

public:
	// �E�B���h�E�̍��[
	static UINT g_WindowLeft;
	// �E�B���h�E�̉E�[
	static UINT g_WindowRight;
	// �E�B���h�E�̏�[
	static UINT g_WindowTop;
	// �E�B���h�E�̉��[
	static UINT g_WindowBottom;
	// ��ʂ̃��t���b�V�����[�g
	static UINT g_FPS;
	// �C���X�^���X�n���h��(�A�v���P�[�V�������̂������l)
	static HINSTANCE g_hInstance;
	// �E�B���h�E�n���h��(�E�B���h�E���̂������l)
	static HWND g_hWnd;
	// �E�C���h�E���ǂ̂悤�ɕ\�����邩�������萔
	static int g_nCmdShow;
};
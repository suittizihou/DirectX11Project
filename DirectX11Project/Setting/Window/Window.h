#pragma once
#include <Windows.h>

class Window {
public:
	// �E�B���h�E�̉���
	static long WindowWidthSize;
	// �E�B���h�E�̏c��
	static long WindowHeightSize;
	// �C���X�^���X�n���h��(�A�v���P�[�V�������̂������l)
	static HINSTANCE hInstance;
	// �E�B���h�E�n���h��(�E�B���h�E���̂������l)
	static HWND hWnd;
	// �E�C���h�E���ǂ̂悤�ɕ\�����邩�������萔
	static int nCmdShow;
};
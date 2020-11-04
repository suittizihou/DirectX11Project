#pragma once

#include "../../../Define/D3D11Defines.h"

class Material;

class DrawManager {
public:
	// ���_���C�A�E�g�̃Z�b�g
	static void SetInputLayout(ID3D11InputLayout* vertexLayout);
	// �V�F�[�_�[�̃Z�b�g
	static void SetShader(const Material& material);

	// ���_�o�b�t�@�[�̃Z�b�g
	static void SetVertexBuffer(ID3D11Buffer* vertexBuffer, UINT vertexSize);
	// �C���f�b�N�X�o�b�t�@�[�̃Z�b�g
	static void SetIndexBuffer(ID3D11Buffer* indexBuffer);

	// �`��J�n
	static void DrawBegin();
	// �`��I��
	static void DrawEnd();

	// �v���~�e�B�u�̕`��
	static void DrawIndexed(UINT vertexNum);
};
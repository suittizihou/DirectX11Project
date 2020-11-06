#pragma once

#include "../../../Define/D3D11Defines.h"
#include "../../../Utility/ModelUtility/ModelData/ModelData.h"

class DrawManager {
public:
	// �`��J�n
	static void DrawBegin();
	// �`��
	static void Draw(const My3DLib::Model& model);
	// �`��I��
	static void DrawEnd();

	// �C���v�b�g���C�A�E�g�̐ݒ�
	static void SetInputLayout(ID3D11InputLayout* inputLayout);

private:
	// �V�F�[�_�[�̃Z�b�g
	static void SetShader(const My3DLib::Material& material);
	
private:
	static InputLayout m_InputLayout;
};
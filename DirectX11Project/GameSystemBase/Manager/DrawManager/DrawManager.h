#pragma once

#include "../../../Define/D3D11Defines.h"
#include "../../../Utility/ModelUtility/ModelData/ModelData.h"

class Camera;
class Transform;

class DrawManager {
public:
	// ������
	static void Init();

	// �`��J�n
	static void DrawBegin();
	// �`��
	static void Draw(const std::weak_ptr<Camera>& camera, const std::weak_ptr<Transform>& transform, My3DLib::ModelData& model);
	// �`��I��
	static void DrawEnd();

	// �}�e���A���̐ݒ�
	static void SetMaterial(const My3DLib::Material& material);
	// ���_���C�A�E�g�̐ݒ�
	static void SetVertexLayout();

	// �V�F�[�_�[�̐ݒ�
	static void SetShader(Shader& shader);
	static void SetShader(My3DLib::Material& material);
	// �`�悷�邽�߂ɕK�v�ȏ����V�F�[�_�[���擾
	static Shader GetDefaultShader();
	
private:
	static InputLayout m_InputLayout;
	static Shader m_Shader;
};
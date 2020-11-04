#pragma once
#include "../ShaderCompiler/ShaderCompiler.h"

class Shader {
public:
	// ���_�V�F�[�_�[���Z�b�g
	void SetVertexShader(const int shaderHandle);
	// �s�N�Z���V�F�[�_�[���Z�b�g
	void SetPixelShader(const int shaderHandle);
	// �W�I���g���V�F�[�_�[���Z�b�g
	void SetGeometryShader(const int shaderHandle);
	// �R���s���[�g�V�F�[�_�[���Z�b�g
	void SetComputeShader(const int shaderHandle);
	// �n���V�F�[�_�[���Z�b�g
	void SetHullShader(const int shaderHandle);
	// �h���C���V�F�[�_�[���Z�b�g
	void SetDomainShader(const int shaderHandle);

	// ���_�V�F�[�_�[�̎擾
	VertexShader GetVertexShader();
	// �s�N�Z���V�F�[�_�[�̎擾
	PixelShader GetPixelShader();
	// �W�I���g���V�F�[�_�[�̎擾
	GeometryShader GetGeometryShader();
	// �R���s���[�g�V�F�[�_�[�̎擾
	ComputeShader GetComputeShader();
	// �n���V�F�[�_�[�̎擾
	HullShader GetHullShader();
	// �h���C���V�F�[�_�[�̎擾
	DomainShader GetDomainShader();

private:
	VertexShader m_VertexShader{ nullptr };
	PixelShader m_PixelShader{ nullptr };
	GeometryShader m_GeometryShader{ nullptr };
	ComputeShader m_ComputeShader{ nullptr };
	HullShader m_HullShader{ nullptr };
	DomainShader m_DomainShader{ nullptr };

	InputLayout m_InputLayout{ nullptr };
};
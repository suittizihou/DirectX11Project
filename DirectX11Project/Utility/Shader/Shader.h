#pragma once
#include "../ShaderCompiler/ShaderCompiler.h"

class Shader {
public:
	// ���_�V�F�[�_�[���Z�b�g
	void SetVertexShader(const std::string& filePath, const std::string& entryPoint = "vsMain");
	// �s�N�Z���V�F�[�_�[���Z�b�g
	void SetPixelShader(const std::string& filePath, const std::string& entryPoint = "psMain");
	// �W�I���g���V�F�[�_�[���Z�b�g
	void SetGeometryShader(const std::string& filePath, const std::string& entryPoint = "gsMain");
	// �R���s���[�g�V�F�[�_�[���Z�b�g
	void SetComputeShader(const std::string& filePath, const std::string& entryPoint = "csMain");
	// �n���V�F�[�_�[���Z�b�g
	void SetHullShader(const std::string& filePath, const std::string& entryPoint = "hsMain");
	// �h���C���V�F�[�_�[���Z�b�g
	void SetDomainShader(const std::string& filePath, const std::string& entryPoint = "dsMain");

	// �V�F�[�_�[���R���e�L�X�g�ɃZ�b�g
	void SetShader(D3DContext context);

private:
	VertexShader m_VertexShader{ nullptr };
	PixelShader m_PixelShader{ nullptr };
	GeometryShader m_GeometryShader{ nullptr };
	ComputeShader m_ComputeShader{ nullptr };
	HullShader m_HullShader{ nullptr };
	DomainShader m_DomainShader{ nullptr };
};
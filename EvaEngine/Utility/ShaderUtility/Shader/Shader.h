#pragma once
#include "../ShaderCompiler/ShaderCompiler.h"

#include "../../../Define/DLLDefine.h"

EVAENGINE_API class Shader {
public:
	Shader() = default;

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
	ID3D11VertexShader* GetVertexShader();
	// �s�N�Z���V�F�[�_�[�̎擾
	ID3D11PixelShader* GetPixelShader();
	// �W�I���g���V�F�[�_�[�̎擾
	ID3D11GeometryShader* GetGeometryShader();
	// �R���s���[�g�V�F�[�_�[�̎擾
	ID3D11ComputeShader* GetComputeShader();
	// �n���V�F�[�_�[�̎擾
	ID3D11HullShader* GetHullShader();
	// �h���C���V�F�[�_�[�̎擾
	ID3D11DomainShader* GetDomainShader();

private:
	ID3D11VertexShader* m_VertexShader{ nullptr };
	ID3D11PixelShader* m_PixelShader{ nullptr };
	ID3D11GeometryShader* m_GeometryShader{ nullptr };
	ID3D11ComputeShader* m_ComputeShader{ nullptr };
	ID3D11HullShader* m_HullShader{ nullptr };
	ID3D11DomainShader* m_DomainShader{ nullptr };
};
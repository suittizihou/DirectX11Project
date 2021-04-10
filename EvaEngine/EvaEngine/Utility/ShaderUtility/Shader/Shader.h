#pragma once
#include "../ShaderCompiler/ShaderCompiler.h"

namespace EvaEngine {
	class Shader {
	public:
		Shader() = default;
		~Shader() = default;

		// ���_�V�F�[�_�[���Z�b�g
		void SetVertexShader(const int shaderHandle);
		void SetVertexShader(ID3D11VertexShader* shader);
		// �s�N�Z���V�F�[�_�[���Z�b�g
		void SetPixelShader(const int shaderHandle);
		void SetPixelShader(ID3D11PixelShader* shader);
		// �W�I���g���V�F�[�_�[���Z�b�g
		void SetGeometryShader(const int shaderHandle);
		void SetGeometryShader(ID3D11GeometryShader* shader);
		// �R���s���[�g�V�F�[�_�[���Z�b�g
		void SetComputeShader(const int shaderHandle);
		void SetComputeShader(ID3D11ComputeShader* shader);
		// �n���V�F�[�_�[���Z�b�g
		void SetHullShader(const int shaderHandle);
		void SetHullShader(ID3D11HullShader* shader);
		// �h���C���V�F�[�_�[���Z�b�g
		void SetDomainShader(const int shaderHandle);
		void SetDomainShader(ID3D11DomainShader* shader);

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
}
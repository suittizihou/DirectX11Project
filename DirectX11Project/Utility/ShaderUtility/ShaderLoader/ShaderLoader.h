#pragma once

#include <string>
#include "../../../Define/D3D11Defines.h"

class ShaderLoader {
private:
	ShaderLoader() = default;
	ShaderLoader(const ShaderLoader&);
	ShaderLoader operator=(const ShaderLoader&);
	~ShaderLoader() = default;

public:
	static ShaderLoader& Instance() {
		static ShaderLoader instance;
		return instance;
	}

	// ���_�V�F�[�_�[�̓ǂݍ���
	int VertexShaderLoad(const std::string & fileName, const std::string& entryPoint = "vsMain");
	// �s�N�Z���V�F�[�_�[�̓ǂݍ���
	int PixelShaderLoad(const std::string & fileName, const std::string& entryPoint = "psMain");
	// �W�I���g���V�F�[�_�[�̓ǂݍ���
	int GeometryShaderLoad(const std::string & fileName, const std::string& entryPoint = "gsMain");
	// �R���s���[�g�V�F�[�_�[�̓ǂݍ���
	int ComputeShaderLoad(const std::string & fileName, const std::string& entryPoint = "csMain");
	// �n���V�F�[�_�[�̓ǂݍ���
	int HullShaderLoad(const std::string & fileName, const std::string& entryPoint = "hsMain");
	// �h���C���V�F�[�_�[�̓ǂݍ���
	int DomainShaderLoad(const std::string & fileName, const std::string& entryPoint = "dsMain");
};
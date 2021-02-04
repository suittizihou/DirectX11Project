#pragma once

#include <string>
#include "../../../Define/D3D11Defines.h"

#ifdef EVAENGINE_EXPORTS
#define EVAENGINE_API __declspec(dllexport)
#else
#define EVAENGINE_API __declspec(dllimport)
#endif

class ShaderLoader {
private:
	ShaderLoader() = default;
	ShaderLoader(const ShaderLoader&);
	ShaderLoader operator=(const ShaderLoader&);
	~ShaderLoader() = default;

public:
	// ���_�V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int VertexShaderLoad(const std::string & fileName, const std::string& entryPoint = "vsMain");
	// �s�N�Z���V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int PixelShaderLoad(const std::string & fileName, const std::string& entryPoint = "psMain");
	// �W�I���g���V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int GeometryShaderLoad(const std::string & fileName, const std::string& entryPoint = "gsMain");
	// �R���s���[�g�V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int ComputeShaderLoad(const std::string & fileName, const std::string& entryPoint = "csMain");
	// �n���V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int HullShaderLoad(const std::string & fileName, const std::string& entryPoint = "hsMain");
	// �h���C���V�F�[�_�[�̓ǂݍ���
	EVAENGINE_API static int DomainShaderLoad(const std::string & fileName, const std::string& entryPoint = "dsMain");
};
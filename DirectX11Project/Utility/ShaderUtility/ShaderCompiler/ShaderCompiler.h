#pragma once
#include <string>
#include "../../../Define/D3D11Defines.h"

class ShaderCompiler {
public:
	// ���_�V�F�[�_�[�̃R���p�C��
	static VertexShader CreateVertexShader(const std::string& fileName, const std::string& entrypath = "vsMain", bool error = true);
	// �s�N�Z���V�F�[�_�[�̃R���p�C��
	static PixelShader CreatePixelShader(const std::string& fileName, const std::string& entrypath = "psMain", bool error = true);
	// �W�I���g���V�F�[�_�[�̃R���p�C��
	static GeometryShader CreateGeometryShader(const std::string& fileName, const std::string& entrypath = "gsMain", bool error = true);
	// �R���s���[�g�V�F�[�_�[�̃R���p�C��
	static ComputeShader CreateComputeShader(const std::string& fileName, const std::string& entrypath = "gsMain", bool error = true);
	// �n���V�F�[�_�[�̃R���p�C��
	static HullShader CreateHullShader(const std::string& fileName, const std::string& entrypath = "hsMain", bool error = true);
	// �h���C���V�F�[�_�[�̃R���p�C��
	static DomainShader CreateDomainShader(const std::string& fileName, const std::string& entrypath = "dsMain", bool error = true);

	// �Z�}���e�B�N�X�̃Z�b�g�Ȃǂ�����C���v�b�g���C�A�E�g���쐬
	static InputLayout CreateInputLayout(D3D11_INPUT_ELEMENT_DESC* layout, UINT elemNum, const std::string& fileName, const std::string& entryPath);

private:
	// �V�F�[�_�[�̃G���[�`�F�b�N
	static HRESULT ShaderErrorCheck(const std::string& fileName, const std::string& entryPath, const LPCSTR& pTarget, ID3DBlob** blob, bool error = true);
	// �C���v�b�g���C�A�E�g�̃G���[�`�F�b�N
	static HRESULT InputLayoutErrorCheck(const std::string& fileName, const std::string& entryPath, const LPCSTR& pTarget, ID3DBlob** blob);
};
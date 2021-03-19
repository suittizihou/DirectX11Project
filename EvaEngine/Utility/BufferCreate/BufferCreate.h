#pragma once

#include <DirectXMath.h>
#include "../../App/DirectX11App/DirectX11App.h"
#include "../ModelUtility/ModelData/ModelData.h"

#ifdef EVAENGINE_EXPORTS
#define __declspec(dllexport)
#else
#define __declspec(dllimport)
#endif

class BufferCreate {
public:
	// ���_�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateVertexBuffer(const std::vector<My3DLib::VertexData>& vertices, size_t strides);
	// ���_�o�b�t�@���Z�b�g����
	static bool SetVertexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
	// �C���f�b�N�X�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateIndexBuffer(const std::vector<UINT>& indices, size_t strides);
	// �C���f�b�N�X�o�b�t�@���Z�b�g����
	static bool SetIndexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
	// �萔�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateConstantBuffer();
};
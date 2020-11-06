#pragma once

#include <DirectXMath.h>
#include "../../App/DirectX11App/DirectX11App.h"
#include "../ModelUtility/ModelData/ModelData.h"

class BufferCreate {
public:
	// ���_�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateVertexBuffer(UINT strides, std::vector<DirectX::XMFLOAT3> vertices);
	// ���_�o�b�t�@���Z�b�g����
	static bool SetVertexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
	// �C���f�b�N�X�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateIndexBuffer(UINT strides, std::vector<UINT> indices);
	// �C���f�b�N�X�o�b�t�@���Z�b�g����
	static bool SetIndexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
};
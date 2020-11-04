#pragma once

#include "../../App/DirectX11App/DirectX11App.h"
#include "../ModelUtility/ModelData/ModelData.h"

class BufferCreate {
public:
	// ���_�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateVertexBuffer(ModelData::VertexData* vertexData, UINT vertexNum);
	// �C���f�b�N�X�o�b�t�@�̍쐬
	static ID3D11Buffer* CreateIndexBuffer(UINT* index, UINT indexNum);
};
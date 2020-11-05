#pragma once

#include "../../App/DirectX11App/DirectX11App.h"
#include "../ModelUtility/ModelData/ModelData.h"
#include "../Math/Vector3/Vector3.h"

class BufferCreate {
public:
	// ���_�o�b�t�@�̍쐬
	static bool SetVertexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
	// �C���f�b�N�X�o�b�t�@�̍쐬
	static bool SetIndexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap);
};
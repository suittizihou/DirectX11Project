#pragma once

#include <DirectXMath.h>

namespace My3DLib {
	struct VertexData {
		DirectX::XMFLOAT3 position;		// ���W(x, y, z)
		DirectX::XMFLOAT3 normal;		// �@��
		DirectX::XMFLOAT4 color;		// ���_�J���[
		DirectX::XMFLOAT2 uv;		// �e�N�X�`�����W(u, v)
	};
}
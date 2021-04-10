#pragma once

#include <DirectXMath.h>

namespace EvaEngine {
	struct ShaderParameters {
		DirectX::XMFLOAT4X4 mtxWorld;
		DirectX::XMFLOAT4X4 mtxView;
		DirectX::XMFLOAT4X4 mtxProj;
	};
}
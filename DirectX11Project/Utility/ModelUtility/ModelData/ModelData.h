#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include <GLTFSDK/GLTF.h>
#include <wrl.h>
#include <vector>
#include <map>
#include "../../../Define/D3D11Defines.h"

class ModelData {
public:
	template<class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

	ModelData() = default;
	~ModelData() = default;

	struct VertexData {
		DirectX::XMFLOAT3 position;		// ���W(x, y, z)
		DirectX::XMFLOAT3 normal;		// �@��
		DirectX::XMFLOAT2 texture;	// �e�N�X�`�����W(u, v)
	};

	struct ShaderParameters {
		DirectX::XMFLOAT4X4 mtxWorld;
		DirectX::XMFLOAT4X4 mtxView;
		DirectX::XMFLOAT4X4 mtxProj;
	};

	struct BufferObject {
		ComPtr<ID3D11Buffer> buffer;
		union {
			D3D11_BUFFER_DESC vertexView;
			D3D11_BUFFER_DESC indexView;
		};
	};

	struct TextureObject {
		ComPtr<ID3D11Texture2D> texture;
		DXGI_FORMAT format;
	};

	struct ModelMesh {
		VertexBuffer m_VertexBuffer;			// ���_�o�b�t�@(Shader���M�p)
		IndexBuffer m_IndexBuffer;				// �C���f�b�N�X�o�b�t�@(Shader���M�p)
		std::vector<VertexData> m_Vertices;		// ���_�o�b�t�@
		std::vector<uint32_t> m_Indices;		// �C���f�b�N�X�o�b�t�@

		uint32_t vertexCount;
		uint32_t indexCount;
														   
		int m_MaterialIndex;						// �}�e���A��ID
	};

	struct Material {
		ComPtr<ID3D11Texture2D> texture;
		std::vector<char> m_ImageData;
		Microsoft::glTF::AlphaMode m_AlphaMode;
	};

	struct Model {
		std::map<std::string, std::vector<ModelMesh>> meshes;
		std::map<std::string, std::vector<Material>> materials;
	};
};

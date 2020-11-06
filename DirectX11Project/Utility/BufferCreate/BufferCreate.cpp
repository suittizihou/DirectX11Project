#include "BufferCreate.h"
#include "../Mesh/Mesh.h"

ID3D11Buffer* BufferCreate::CreateVertexBuffer(UINT strides, std::vector<DirectX::XMFLOAT3> vertices)
{
	// ���_�o�b�t�@�̍쐬
	// ���_�o�b�t�@�Ƃ̓V�X�e���������O�A���Ȃ킿GPU���ɂ��郁�����ɒ��_�f�[�^��z�u���邽�߂̂���
	D3D11_BUFFER_DESC bufferDesc{};
	ZeroMemory(&bufferDesc, sizeof(bufferDesc));
	bufferDesc.ByteWidth = strides * static_cast<UINT>(vertices.size());
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA subResourceData{};
	ZeroMemory(&subResourceData, sizeof(subResourceData));
	subResourceData.pSysMem = &vertices[0];

	ID3D11Buffer* buffer{ nullptr };
	if (FAILED(DirectX11App::g_Device->CreateBuffer(&bufferDesc, &subResourceData, &buffer))) {
		DebugLog::LogError("Vertex Buffer Create Failed.");
		return nullptr;
	}

	return buffer;
}

bool BufferCreate::SetVertexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap) {

    UINT strides = sizeof(My3DLib::VertexData);
	for (auto& meshs : meshMap) {
		for (auto& mesh : meshs.second) {
			// ���_�o�b�t�@�̍쐬
            mesh.SetVertexBuffer(CreateVertexBuffer(strides, mesh.GetVertices()));
		}
	}

	return true;
}

ID3D11Buffer* BufferCreate::CreateIndexBuffer(UINT strides, std::vector<UINT> indices)
{
    // �C���f�b�N�X�o�b�t�@�̍쐬
    // �C���f�b�N�X�o�b�t�@�Ƃ́A���_�d�����̖��ʂ��Ȃ����߂̂���
    D3D11_BUFFER_DESC bufferDesc{};
    ZeroMemory(&bufferDesc, sizeof(bufferDesc));
    bufferDesc.ByteWidth = strides * static_cast<UINT>(indices.size());
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA subResourceData{};
    ZeroMemory(&subResourceData, sizeof(subResourceData));
    subResourceData.pSysMem = &indices[0];

    ID3D11Buffer* buffer{ nullptr };
    if (FAILED(DirectX11App::g_Device->CreateBuffer(&bufferDesc, &subResourceData, &buffer))) {
        DebugLog::LogError("Index Buffer Create Failed.");
        return nullptr;
    }
    
    return buffer;
}

bool BufferCreate::SetIndexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap)
{
    UINT strides = sizeof(UINT);
    for (auto& meshs : meshMap) {
        for (auto& mesh : meshs.second) {
            // �C���f�b�N�X�o�b�t�@�[�̐ݒ�
            mesh.SetIndexBuffer(CreateIndexBuffer(strides, mesh.GetIndices()));
        }
    }

    return true;
}

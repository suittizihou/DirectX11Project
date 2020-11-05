#include "BufferCreate.h"
#include "../Mesh/Mesh.h"

bool BufferCreate::SetVertexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap) {

    UINT strides = sizeof(My3DLib::VertexData);
	for (auto& meshs : meshMap) {
		for (auto& mesh : meshs.second) {
			// ���_�o�b�t�@�̍쐬
            // ���_�o�b�t�@�Ƃ̓V�X�e���������O�A���Ȃ킿GPU���ɂ��郁�����ɒ��_�f�[�^��z�u���邽�߂̂���
			D3D11_BUFFER_DESC bufferDesc{};
			ZeroMemory(&bufferDesc, sizeof(bufferDesc));
			bufferDesc.ByteWidth = strides * static_cast<UINT>(mesh.GetVertices().size());
			bufferDesc.Usage = D3D11_USAGE_DEFAULT;
			bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

			D3D11_SUBRESOURCE_DATA subResourceData{};
			ZeroMemory(&subResourceData, sizeof(subResourceData));
			subResourceData.pSysMem = &mesh.GetVertices()[0];

			ID3D11Buffer* buffer{ nullptr };
			if (FAILED(DirectX11App::g_Device->CreateBuffer(&bufferDesc, &subResourceData, &buffer))) {
				DebugLog::LogError("Vertex Buffer Create Failed.");
				return false;
			}
            mesh.SetVertexBuffer(buffer);
		}
	}

	return true;
}

bool BufferCreate::SetIndexBuffer(std::map<std::string, std::vector<My3DLib::Mesh>>& meshMap)
{
    for (auto& meshs : meshMap) {
        for (auto& mesh : meshs.second) {
            // �C���f�b�N�X�o�b�t�@�̍쐬
            // �C���f�b�N�X�o�b�t�@�Ƃ́A���_�d�����̖��ʂ��Ȃ����߂̂���
            D3D11_BUFFER_DESC bufferDesc{};
            ZeroMemory(&bufferDesc, sizeof(bufferDesc));
            bufferDesc.ByteWidth = (sizeof(UINT)) * static_cast<UINT>(mesh.GetIndices().size());
            bufferDesc.Usage = D3D11_USAGE_DEFAULT;
            bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
            //bufferDesc.CPUAccessFlags = 0;

            D3D11_SUBRESOURCE_DATA subResourceData{};
            ZeroMemory(&subResourceData, sizeof(subResourceData));
            subResourceData.pSysMem = &mesh.GetIndices()[0];

            ID3D11Buffer* buffer{ nullptr };
            if (FAILED(DirectX11App::g_Device->CreateBuffer(&bufferDesc, &subResourceData, &buffer))) {
                DebugLog::LogError("Index Buffer Create Failed.");
                return false;
            }
            // �C���f�b�N�X�o�b�t�@�[�̐ݒ�
            mesh.SetIndexBuffer(buffer);
        }
    }

    return true;
}

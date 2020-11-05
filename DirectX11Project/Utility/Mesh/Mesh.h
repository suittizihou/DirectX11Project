#pragma once

#include "../../Define/D3D11Defines.h"
#include <vector>
#include <DirectXMath.h>
#include "../ModelUtility/ModelData/VertexData.h"


namespace My3DLib {
	class Mesh {
	public:
		// ���_���̎擾
		std::vector<DirectX::XMFLOAT3> GetVertices();
		// ���_�o�b�t�@�[�̎擾
		ID3D11Buffer* const* GetVertexBuffer();
		// ���_���g�p���鏇�Ԃ̎擾(�C���f�b�N�X�o�b�t�@)
		std::vector<unsigned int> GetIndices();
		// �C���f�b�N�X�o�b�t�@�̎擾
		ID3D11Buffer* GetIndexBuffer();
		// ���_�̖@�����擾
		std::vector<DirectX::XMFLOAT3> GetNormal();
		// UV���擾
		std::vector<DirectX::XMFLOAT2> GetUV();
		// �}�e���A����ID���擾
		int GetMaterialID();

		// ���_����ݒ�
		void SetVertices(std::vector<DirectX::XMFLOAT3> vertices, bool isCreateIndices = false);
		void SetVertices(std::vector<My3DLib::VertexData> vertices, bool isCreateIndices = false);
		void SetVertexBuffer(ID3D11Buffer* vertexBuffer);
		//// ���_���g�p���鏇�Ԃ̍쐬(�C���f�b�N�X�o�b�t�@)
		//void CreateIndices();
		// ���_���g�p���鏇�Ԃ̐ݒ�(�C���f�b�N�X�o�b�t�@)
		void SetIndices(std::vector<unsigned int> indices);
		void SetIndexBuffer(ID3D11Buffer* indexBuffer);
		// ���_�̖@����ݒ�
		void SetNormals(std::vector<DirectX::XMFLOAT3> normals);
		void SetNormal(int vertexNum, DirectX::XMFLOAT3 normal);
		// UV�̐ݒ�
		void SetUV(std::vector<DirectX::XMFLOAT2> uvs);
		// �}�e���A���̔ԍ���ݒ�
		void SetMaterialID(int materialID);

	private:
		// ���_�̔z��
		std::vector<DirectX::XMFLOAT3> m_Vertices;
		// ���_���g�����Ԃ��L���ꂽ�z��
		std::vector<unsigned int> m_Indices;
		// ���ꂼ��̒��_�̖@��
		std::vector<DirectX::XMFLOAT3> m_Normals;
		// ���_�J���[
		std::vector<DirectX::XMFLOAT4> m_Color;
		// UV���W
		std::vector<DirectX::XMFLOAT2> m_UVs;
		// �U�蕪�����Ă���}�e���A���̔ԍ�
		int m_MaterialID{ 0 };

		// GPU�p���_�o�b�t�@�[
		VertexBuffer m_VertexBuffer{ nullptr };
		// GPU�p�C���f�b�N�X�o�b�t�@
		IndexBuffer m_IndexBuffer{ nullptr };
	};
}
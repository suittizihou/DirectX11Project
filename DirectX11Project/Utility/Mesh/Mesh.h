#pragma once

#include "../../Define/D3D11Defines.h"
#include "../ModelUtility/ModelData/ModelData.h"
#include <vector>
#include "../Math/Vector3/Vector3.h"
#include "../Math/Vector2/Vector2.h"

namespace My3DLib {
	class Mesh {
	public:
		// ���_���̎擾
		std::vector<Vector3> GetVertices();
		// ���_���g�p���鏇�Ԃ̎擾(�C���f�b�N�X�o�b�t�@)
		std::vector<unsigned int> GetIndices();
		// ���_�̖@�����擾
		std::vector<Vector3> GetNormal();
		// UV���擾
		std::vector<Vector2> GetUV();

		// ���_�����Z�b�g
		void SetVertices(std::vector<Vector3> vertices);
		void SetVertices(std::vector<My3DLib::ModelData::VertexData> vertices);
		void SetVertexBuffer(ID3D11Buffer* vertexBuffer);
		// ���_���g�p���鏇�Ԃ̃Z�b�g(�C���f�b�N�X�o�b�t�@)
		void SetIndices(std::vector<unsigned int> indices);
		void SetIndexBuffer(ID3D11Buffer* indexBuffer);
		// ���_�̖@�����Z�b�g
		void SetNormals(std::vector<Vector3> normals);
		void SetNormal(int vertexNum, Vector3 normal);
		// UV�̃Z�b�g
		void SetUV(std::vector<Vector2> uvs);

	private:
		std::vector<Vector3> m_Vertices;
		std::vector<unsigned int> m_Indices;
		std::vector<Vector3> m_Normals;
		std::vector<Vector2> m_UVs;

		// GPU�p���_�o�b�t�@�[
		VertexBuffer m_VertexBuffer{ nullptr };
		// GPU�p�C���f�b�N�X�o�b�t�@
		IndexBuffer m_IndexBuffer{ nullptr };
	};
}
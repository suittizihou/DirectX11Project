#include <stdexcept>
#include <string>
#include <fbxsdk.h>

#include "FBXModelLoader.h"

#include "../../../Mesh/Mesh.h"
#include "../../../Material/Material.h"

My3DLib::Model FBXModelLoader::LoadFbxFile(const char* fileName)
{
    // FbxManager�쐬
    FbxManager* fbx_manager = fbxsdk::FbxManager::Create();
    if (fbx_manager == nullptr)
    {
        std::runtime_error("FbxManager�̍쐬�Ɏ��s���܂���");
        return My3DLib::Model();
    }

    // FbxImporter�쐬
    FbxImporter* fbx_importer = FbxImporter::Create(fbx_manager, "");
    if (fbx_importer == nullptr) {
        fbx_manager->Destroy();
        std::runtime_error("FbxImporter�̍쐬�Ɏ��s���܂���");
        return My3DLib::Model();
    }

    // FbxScene�𐶐�
    FbxScene* fbx_scene = FbxScene::Create(fbx_manager, "");
    if (fbx_scene == nullptr) {
        fbx_importer->Destroy();
        fbx_manager->Destroy();
        std::runtime_error("FbxScene�̍쐬�Ɏ��s���܂���");
        return My3DLib::Model();
    }

    // File��������
    fbx_importer->Initialize(fileName);
    // scene�ɃC���|�[�g
    fbx_importer->Import(fbx_scene);

    FbxGeometryConverter converter(fbx_manager);
    // �|���S�����O�p�`�ɂ���
    converter.Triangulate(fbx_scene, true);

    std::map<std::string, FbxNode*> mesh_node_list;
    // ���b�V��Node��T��
    FindMeshNode(fbx_scene->GetRootNode(), mesh_node_list);

    for (auto data : mesh_node_list) {
        // mesh�쐬
        CreateMesh(data.first.c_str(), data.second->GetMesh());
    }

    // �֘A���邷�ׂẴI�u�W�F�N�g����������
    // �C���|�[�^�\���
    fbx_importer->Destroy();
    // �V�[�����
    fbx_scene->Destroy();
    // �}�l�[�W�����
    fbx_manager->Destroy();

    return m_Model;
}

void FBXModelLoader::FindMeshNode(fbxsdk::FbxNode* node, std::map<std::string, fbxsdk::FbxNode*>& list)
{
    std::string name = node->GetName();
    for (int i = 0; i < node->GetNodeAttributeCount(); i++)
    {
        FbxNodeAttribute* attribute = node->GetNodeAttributeByIndex(i);

        // Attribute�����b�V���Ȃ�ǉ�
        if (attribute->GetAttributeType() == FbxNodeAttribute::EType::eMesh)
        {
            list[node->GetName()] = node;
            break;
        }
    }

    for (int i = 0; i < node->GetChildCount(); i++)
    {
        FindMeshNode(node->GetChild(i), list);
    }
}

bool FBXModelLoader::CreateMesh(const char* node_name, fbxsdk::FbxMesh* mesh)
{
    // ���_�o�b�t�@�̎擾
    fbxsdk::FbxVector4* vertices = mesh->GetControlPoints();
    // �C���f�b�N�X�o�b�t�@�̎擾
    int* indices = mesh->GetPolygonVertices();
    // ���_���W�̐��̎擾
    int polygon_vertex_count = mesh->GetPolygonVertexCount();
    
    My3DLib::Mesh tempMesh{ polygon_vertex_count };

    // GetPolygonVertexCount => ���_��
    for (int i = 0; i < polygon_vertex_count; ++i) {
        // �C���f�b�N�X�o�b�t�@���璸�_�ԍ����擾
        int index = indices[i];
        // ���_���W���X�g������W���擾����
        tempMesh.SetVertexPos(i, (float)-vertices[index][0], (float)vertices[index][1], (float)vertices[index][2]);
    }

    fbxsdk::FbxArray<fbxsdk::FbxVector4> normals;
    // �@�����X�g�̎擾
    mesh->GetPolygonVertexNormals(normals);

    // �@���ݒ�
    for (int i = 0; i < normals.Size(); ++i) {
        // ���_�@�����X�g����@�����擾����
        tempMesh.SetVertexNormal(i, (float)-normals[i][0], (float)normals[i][1], (float)normals[i][2]);
    }

    // �|���S�����̎擾
    int polygon_count = mesh->GetPolygonCount();

    std::vector<unsigned int> tempIndices;
    // �|���S���̐������A�ԂƂ��ĕۑ�����
    for (int i = 0; i < polygon_count; ++i) {
        tempIndices.push_back(i * 3 + 2);
        tempIndices.push_back(i * 3 + 1);
        tempIndices.push_back(i * 3);
    }
    // �C���f�b�N�X�o�b�t�@���Z�b�g
    tempMesh.SetIndices(tempIndices);

    // ���_���̃Z�b�g
    m_Model.meshes[node_name].push_back(tempMesh);

    return true;
}

#include <stdexcept>
#include <string>
#include <fbxsdk.h>

#include "FBXModelLoader.h"

ModelData::Model FBXModelLoader::LoadFbxFile(const char* fileName)
{
    // FbxManager�쐬
    FbxManager* fbx_manager = fbxsdk::FbxManager::Create();
    if (fbx_manager == nullptr)
    {
        std::runtime_error("FbxManager�̍쐬�Ɏ��s���܂���");
        return ModelData::Model();
    }

    // FbxImporter�쐬
    FbxImporter* fbx_importer = FbxImporter::Create(fbx_manager, "");
    if (fbx_importer == nullptr) {
        fbx_manager->Destroy();
        std::runtime_error("FbxImporter�̍쐬�Ɏ��s���܂���");
        return ModelData::Model();
    }

    // FbxScene�𐶐�
    FbxScene* fbx_scene = FbxScene::Create(fbx_manager, "");
    if (fbx_scene == nullptr) {
        fbx_importer->Destroy();
        fbx_manager->Destroy();
        std::runtime_error("FbxScene�̍쐬�Ɏ��s���܂���");
        return ModelData::Model();
    }

    //// IOSetting�𐶐�
    //FbxIOSettings* ioSettings = FbxIOSettings::Create(manager, IOSROOT);
    //if (ioSettings == nullptr) {
    //    manager->Destroy();
    //    importer->Destroy();
    //    scene->Destroy();
    //    std::runtime_error("FbxIOSettings�̍쐬�Ɏ��s���܂���");
    //    return ModelData::Model();
    //}
    //manager->SetIOSettings(ioSettings);

    // File��������
    fbx_importer->Initialize(fileName/*, -1, manager->GetIOSettings()*/);
    // scene�ɃC���|�[�g
    fbx_importer->Import(fbx_scene);

    // �O�p�|���S����
    FbxGeometryConverter geometryConverter(fbx_manager);
    geometryConverter.Triangulate(fbx_scene, true);

    fbxsdk::FbxNode* root_node = fbx_scene->GetRootNode();
    // Scene���
    std::map<std::string, FbxNode*> mesh_node_list;
    // ���b�V��Node��T��
    FindMeshNode(root_node, mesh_node_list);

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
    if (node == nullptr) return;

    for (int i = 0; i < node->GetNodeAttributeCount(); i++) {
        fbxsdk::FbxNodeAttribute* attribute = node->GetNodeAttributeByIndex(i);

        // Attribute�����b�V���Ȃ�ǉ�
        if (attribute->GetAttributeType() == fbxsdk::FbxNodeAttribute::EType::eMesh) {
            list[node->GetName()] = node;
            break;
        }

        for (int i = 0; i < node->GetChildCount(); i++) {
            FindMeshNode(node->GetChild(i), list);
        }
    }
}

bool FBXModelLoader::CreateMesh(const char* node_name, fbxsdk::FbxMesh* mesh)
{
    // ���_�o�b�t�@�̎擾
    FbxVector4* vertices = mesh->GetControlPoints();
    // �C���f�b�N�X�o�b�t�@�̎擾
    int* indices = mesh->GetPolygonVertices();
    // ���_���W�̐��̎擾
    int polygon_vertex_count = mesh->GetPolygonVertexCount();

    // GetPolygonVertexCount => ���_��
    for (int i = 0; i < polygon_vertex_count; i++) {
        ModelData::VertexData vertex;
        // �C���f�b�N�X�o�b�t�@���璸�_�ԍ����擾
        int index = indices[i];

        // ���_���W���X�g������W���擾����
        vertex.position.x = (float)-vertices[index][0];
        vertex.position.y = (float)vertices[index][1];
        vertex.position.z = (float)vertices[index][2];

        // �ǉ�
        m_Model.meshes[node_name][0].m_Vertices.push_back(vertex);
    }

    fbxsdk::FbxArray<FbxVector4> normals;
    // �@�����X�g�̎擾
    mesh->GetPolygonVertexNormals(normals);

    //// �@���ݒ�
    //for (int i = 0; i < normals.Size(); i++) {
    //    m_Model.meshes[node_name][0].m_Vertices[i].normal.x = (float)-normals[i][0];
    //    m_Model.meshes[node_name][0].m_Vertices[i].normal.y = (float)normals[i][1];
    //    m_Model.meshes[node_name][0].m_Vertices[i].normal.z = (float)normals[i][2];
    //}

    // �|���S�����̎擾
    int polygon_count = mesh->GetPolygonCount();

    // �|���S���̐������A�ԂƂ��ĕۑ�����
    for (int i = 0; i < polygon_count; i++) {
        m_Model.meshes[node_name][0].m_Indices.push_back(i * 3 + 2);
        m_Model.meshes[node_name][0].m_Indices.push_back(i * 3 + 1);
        m_Model.meshes[node_name][0].m_Indices.push_back(i * 3);
    }

    return true;
}

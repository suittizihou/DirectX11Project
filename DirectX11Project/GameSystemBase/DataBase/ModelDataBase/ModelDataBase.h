#pragma once

#include "../../../Utility/ModelUtility/ModelData/ModelData.h"

class ModelDataBase {
private:
	ModelDataBase() = default;
	ModelDataBase(const ModelDataBase&);
	ModelDataBase operator=(const ModelDataBase&);
	~ModelDataBase() = default;

public:
	static ModelDataBase& Instance() {
		static ModelDataBase instance;
		return instance;
	}

	// ���f���f�[�^��ǉ�����
	int AddModelData(const My3DLib::ModelData& model);
	// ���f���f�[�^���擾
	My3DLib::ModelData GetModel(const int modelHandle);
	// ���f���f�[�^���������������
	void DeleteModel(const int modelHandle);
	// �������Ƀ��f���̃f�[�^��ǂݍ���
	My3DLib::ModelData LoadModelDataMemory(const My3DLib::ModelData& model);
	
private:
	// ���f���f�[�^�̃n���h��
	int modelCount{ 0 };
	// ���f���f�[�^
	std::map<int, My3DLib::ModelData> m_Models{};
};
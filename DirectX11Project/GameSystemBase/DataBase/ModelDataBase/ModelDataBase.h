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
	int AddModelData(const ModelData::Model& model);
	// ���f���f�[�^���擾
	ModelData::Model GetModel(const int modelHandle);
	// ���f���f�[�^���������������
	void DeleteModel(const int modelHandle);
	// �������Ƀ��f���̃f�[�^��ǂݍ���
	ModelData::Model LoadModelDataMemory(const ModelData::Model& model);
	
private:
	// ���f���f�[�^�̃n���h��
	int modelCount{ 0 };
	// ���f���f�[�^
	std::map<int, ModelData::Model> m_Model{};
};
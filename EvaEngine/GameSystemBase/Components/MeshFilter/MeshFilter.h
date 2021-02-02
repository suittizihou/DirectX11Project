#pragma once

#include "../../Base/Component/Component.h"
#include "../../DataBase/ModelDataBase/ModelDataBase.h"

class MeshFilter : public Component {
public:
	MeshFilter(const int& modelHandle)
		:Component(0U, false),
		m_Model(ModelDataBase::Instance().GetModel(modelHandle))
	{}
	
	~MeshFilter() = default;

	EVAENGINE_API My3DLib::ModelData GetModel() { return m_Model; }

private:
	My3DLib::ModelData m_Model{};
};
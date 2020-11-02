#ifndef MESH_FILTER_H_
#define MESH_FILTER_H_

#include "../../Base/Component/Component.h"
#include "../../../Utility/ModelUtility/ModelDataBase/ModelDataBase.h"

class MeshFilter : public Component {
public:
	MeshFilter(const ComponentDesc& componentDesc, const int& modelHandle)
		:Component(componentDesc, 0U, false),
		m_Model(ModelDataBase::Instance().GetModel(modelHandle))
	{}
	
	~MeshFilter() = default;

	ModelData::Model GetModel() { return m_Model; }

private:
	ModelData::Model m_Model{};
};

#endif
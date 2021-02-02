#include "ModelLoadManager.h"
#include "../../../StringAssist/StringAssist.h"
#include "../../../../GameSystemBase/DataBase/ModelDataBase/ModelDataBase.h"

#include "../FBXModelLoader/FBXModelLoader.h"
#include "../VRMModelLoader/VRMModelLoader.h"
#include "../OBJModelLoader/OBJModelLoader.h"

#include "../../../../System/DebugLog/DebugLog.h"

int ModelLoadManager::Load(const std::string& fileName)
{
    std::vector<std::string> fileSplit{ StringAssist::split(fileName, '.') };

    if (fileSplit.size() == 0) DebugLog::LogError("�g���q�t���œ��͂��Ă�������");

    std::string modelType = fileSplit[fileSplit.size() - 1];

    My3DLib::ModelData model{};
    
    if (modelType == "fbx") {
        FBXModelLoader fbxModelLoader{};
        model = fbxModelLoader.LoadModel(fileName.c_str());
    }
    else if (modelType == "vrm") {
        VRMModelLoader vrmModelLoader{};
        model = vrmModelLoader.LoadModel(fileName.c_str());
    }
    else if (modelType == "obj") {
        OBJModelLoader objModelLoader{};
        model = objModelLoader.LoadModel(fileName.c_str());
    }

    return ModelDataBase::Instance().AddModelData(model);
}
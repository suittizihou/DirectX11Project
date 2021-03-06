#pragma once

#include <DirectXMath.h>
#include <GLTFSDK/GLTF.h>

#include "../ModelLoadBase.h"

namespace Microsoft {
	namespace glTF {
		class Document;
		class GLTFResourceReader;
	}
}

namespace EvaEngine {
	class VRMModelLoader : public ModelLoadBase {
	public:
		template<class T>
		using ComPtr = Microsoft::WRL::ComPtr<T>;

		VRMModelLoader() = default;
		~VRMModelLoader() = default;
		ModelData LoadModel(const char* fileName) override;
		ModelData MakeModelDataMemory(const ModelData& model);

	private:
		void LoadModelGeometry(const Microsoft::glTF::Document& doc, std::shared_ptr<Microsoft::glTF::GLTFResourceReader> reader);
		void MakeModelGeometry(ModelData& model);
		void LoadModelMaterial(const Microsoft::glTF::Document& doc, std::shared_ptr<Microsoft::glTF::GLTFResourceReader> reader);
		void MakeModelMaterial(ModelData& model);

	private:
		ModelData m_Model{};
	};
}
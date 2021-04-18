#if _DEBUG
#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <imgui.h>
#include <memory>

namespace EvaEngine {
	class SceneView;

	class EditorApp {
	public:
		// ������
		static HRESULT Init();

		// Editor�`��O����
		static void DrawBegin();
		// Editor�`�揈��
		static void Draw(const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command);
		// Editor�`��I����
		static void DrawEnd();

		// Editor�I��������
		static void End();

	public:
		void EditTransform(float* cameraView, float* cameraProjection, float* matrix, bool editTransformDecomposition);

	private:
		static std::unique_ptr<SceneView> m_SceneView;
	};
}
#endif
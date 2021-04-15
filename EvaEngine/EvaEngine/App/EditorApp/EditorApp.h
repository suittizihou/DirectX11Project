#if _DEBUG
#pragma once

#include <wrl.h>
#include <imgui.h>

namespace EvaEngine {
	class EditorApp {
	public:
		// ������
		static HRESULT Init();

		// Editor�`��O����
		static void DrawBegin();
		// Editor�`�揈��
		static void Draw();
		// Editor�`��I����
		static void DrawEnd();

		// Editor�I��������
		static void End();

	public:
		void EditTransform(float* cameraView, float* cameraProjection, float* matrix, bool editTransformDecomposition);

	private:
		static ImGuiIO& io;
	};
}
#endif
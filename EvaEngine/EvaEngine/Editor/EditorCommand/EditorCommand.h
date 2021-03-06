#if _DEBUG
#pragma once

namespace ImGuizmo {
	enum OPERATION;
}

namespace EvaEngine {
	class EditorCommand {
	public:
		EditorCommand() = default;

		// Transformの編集をGUIで行えるようにする関数
		void EditTransform(float* cameraView, float* cameraProjection, float* matrix, bool editTransformDecomposition);

	public:
		float camDistance = 8.f;

	private:
		static ImGuizmo::OPERATION mCurrentGizmoOperation;
	};
}

#endif
#pragma once

class EditorWindow {
public:
	EditorWindow() = default;
	~EditorWindow() = default;

	// 初期化処理
	void Init();
	// 更新
	void Update();
	// 描画
	void Draw();
};
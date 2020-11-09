#include "MoveScript.h"
#include "../../../GameSystemBase/Components/ComponentHeaders.h"

MoveScript::MoveScript(const float& speed) : 
	MonoBehaviour(FunctionMask::UPDATE),
	m_Speed(speed)
{
}

void MoveScript::Update()
{
	// 左に移動
	if (Input::GetKey(KeyCode::A)) {
		GetTransform().lock()->move(-GetTransform().lock()->right() * m_Speed);
	}

	// 右に移動
	if (Input::GetKey(KeyCode::D)) {
		GetTransform().lock()->move(GetTransform().lock()->right() * m_Speed);
	}

	// 奥に移動
	if (Input::GetKey(KeyCode::W)) {
		GetTransform().lock()->move(GetTransform().lock()->forward() * m_Speed);
	}

	// 手前に移動
	if (Input::GetKey(KeyCode::S)) {
		GetTransform().lock()->move(GetTransform().lock()->back() * m_Speed);
	}
}

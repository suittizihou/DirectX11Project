#include "MoveScript.h"
#include "../../../GameSystemBase/Components/ComponentHeaders.h"

MoveScript::MoveScript(const float& speed) : 
	MonoBehaviour(FunctionMask::UPDATE),
	m_Speed(speed)
{
}

void MoveScript::Update()
{
	// ���Ɉړ�
	if (Input::GetKey(KeyCode::A)) {
		GetTransform().lock()->move(GetTransform().lock()->left() * m_Speed);
	}

	// �E�Ɉړ�
	if (Input::GetKey(KeyCode::D)) {
		GetTransform().lock()->move(GetTransform().lock()->right() * m_Speed);
	}

	// ���Ɉړ�
	if (Input::GetKey(KeyCode::W)) {
		GetTransform().lock()->move(GetTransform().lock()->forward() * m_Speed);
	}

	// ��O�Ɉړ�
	if (Input::GetKey(KeyCode::S)) {
		GetTransform().lock()->move(GetTransform().lock()->back() * m_Speed);
	}

	// ��Ɉړ�
	if (Input::GetKey(KeyCode::E)) {
		GetTransform().lock()->move(Vector3::up() * m_Speed);
	}

	// ���Ɉړ�
	if (Input::GetKey(KeyCode::Q)) {
		GetTransform().lock()->move(Vector3::down() * m_Speed);
	}
}

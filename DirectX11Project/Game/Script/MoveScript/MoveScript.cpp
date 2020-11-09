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
		GetTransform().lock()->move(Vector3::left() * m_Speed);
	}

	// �E�Ɉړ�
	if (Input::GetKey(KeyCode::D)) {
		GetTransform().lock()->move(Vector3::right() * m_Speed);
	}

	// ���Ɉړ�
	if (Input::GetKey(KeyCode::W)) {
		GetTransform().lock()->move(Vector3::forward() * m_Speed);
	}

	// ��O�Ɉړ�
	if (Input::GetKey(KeyCode::S)) {
		GetTransform().lock()->move(Vector3::back() * m_Speed);
	}
}

#include "MeshRenderer.h"

#include <iterator>

#include "../../Base/GameObject/GameObject.h"

#include "../MeshFilter/MeshFilter.h"
#include "../Transform/Transform.h"
#include "../Camera/Camera.h"

#include "../../Manager/DrawManager/DrawManager.h"

using namespace EvaEngine;
using namespace FunctionMask;

MeshRenderer::MeshRenderer(
	const std::weak_ptr<MeshFilter>& meshFilter,
	const std::weak_ptr<Camera>& camera) :
	Component(DRAW, false),
	m_Model(meshFilter.lock()->GetModel()),
	m_MeshFilter(meshFilter),
	m_Camera(camera)
{
}

void MeshRenderer::Awake() {
	m_Transform = GetTransform();
}

void MeshRenderer::Draw(const Microsoft::WRL::ComPtr<ID3D11DeviceContext>& command)
{
	DrawManager::Draw(m_Camera, m_Transform, m_Model);
}

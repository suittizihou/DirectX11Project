#pragma once

#include "../../../App/DirectX11App/DirectX11App.h"
#include <DirectXMath.h>
#include "../../Base/Component/Component.h"

#undef near
#undef far

struct Matrix4x4;

class Camera : public Component
{
public:
	Camera(
		const D3D11_VIEWPORT& viewPort,
		const float& near = 0.3f,
		const float& far = 1000.0f,
		const float& fov = 60.0f);
	Camera(
		const float& near = 0.3f,
		const float& far = 1000.0f,
		const float& fov = 60.0f);
	~Camera() = default;

public:
	void Awake() override;
	void Update() override;

public:
	// �r���[�|�[�g���擾
	EVAENGINE_API D3D11_VIEWPORT  GetViewport() const;
	// �r���[�s����擾
	EVAENGINE_API DirectX::XMMATRIX GetViewMatrix() const;
	// �v���W�F�N�V�����s����擾
	EVAENGINE_API DirectX::XMMATRIX GetProjectionMatrix() const;

	// �r���[�s����쐬
	EVAENGINE_API DirectX::XMMATRIX CreateViewMatrix(const std::weak_ptr<Transform>& transform);
	EVAENGINE_API DirectX::XMMATRIX CreateViewMatrix(const Matrix4x4& rotateMatrix, const Matrix4x4& positionMatrix);
	// �v���W�F�N�V�����s����쐬
	EVAENGINE_API DirectX::XMMATRIX CreateProjectionMatrix(
									const D3D11_VIEWPORT& viewPort,
									const float& near,
									const float& far,
									const float& fovDegree);

private:
	DirectX::XMMATRIX	m_ViewMatrix{};
	DirectX::XMMATRIX	m_ProjectionMatrix{};

	float m_Near{};
	float m_Far{};
	float m_Fov{};
};
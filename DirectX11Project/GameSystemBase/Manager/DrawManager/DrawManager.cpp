#include "DrawManager.h"
#include "../../../App/DirectX11App/DirectX11App.h"
#include "../../../Setting/Window/Window.h"
#include "../../../Utility/Material/Material.h"
#include "../../../Utility/Math/Vector3/Vector3.h"

InputLayout DrawManager::m_InputLayout{ nullptr };

void DrawManager::SetShader(Shader& shader) {
	// nullptr �łȂ��ꍇ�V�F�[�_�[���Z�b�g����
	if (shader.GetComputeShader() != nullptr) DirectX11App::g_Context->CSSetShader(shader.GetComputeShader(), nullptr, 0);
	if (shader.GetVertexShader() != nullptr) DirectX11App::g_Context->VSSetShader(shader.GetVertexShader(), nullptr, 0);
	if (shader.GetHullShader() != nullptr) DirectX11App::g_Context->HSSetShader(shader.GetHullShader(), nullptr, 0);
	if (shader.GetDomainShader() != nullptr) DirectX11App::g_Context->DSSetShader(shader.GetDomainShader(), nullptr, 0);
	if (shader.GetGeometryShader() != nullptr) DirectX11App::g_Context->GSSetShader(shader.GetGeometryShader(), nullptr, 0);
	if (shader.GetPixelShader() != nullptr) DirectX11App::g_Context->PSSetShader(shader.GetPixelShader(), nullptr, 0);
}

void DrawManager::SetShader(My3DLib::Material& material)
{
	SetShader(material.g_Shader);
}

void DrawManager::DrawBegin()
{
	// �|���S���̐������@�̎w��
	DirectX11App::g_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// �w��F�ŉ�ʃN���A
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	// RenderTargetView�̃N���A
	DirectX11App::g_Context->ClearRenderTargetView(DirectX11App::g_RenderTargetView.Get(), clearColor);

	// DepthView��StencilView�̃N���A
	DirectX11App::g_Context->ClearDepthStencilView(
		DirectX11App::g_DepthStencilView.Get(),			// �N���A�Ώۂ�View
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,		// �N���A�t���O
		1.0f,											// �[�x�N���A�l
		0);												// �X�e���V���N���A�l
}

void DrawManager::Draw(const My3DLib::Model& model)
{
	Shader shader{};
	shader.SetVertexShader(0);
	shader.SetPixelShader(0);

	// �|���S���̎��
	DirectX11App::g_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// �V�F�[�_�[�̃Z�b�g
	DrawManager::SetShader(shader);
	// �����_�[�^�[�Q�b�g�̐ݒ�
	DirectX11App::g_Context->OMSetRenderTargets(1, DirectX11App::g_RenderTargetView.GetAddressOf(), DirectX11App::g_DepthStencilView.Get());

	UINT strides = sizeof(My3DLib::VertexData);
	UINT offset = 0;

	Vector3 pos = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 degree = Vector3(0.0f, 180.0f, 0.0f);
	Vector3 scale = Vector3(1.0f, 1.0f, 1.0f);

	for (const auto& meshs : model.meshes) {
		for (auto mesh : meshs.second) {
			// �C���v�b�g���C�A�E�g�̐ݒ�
			DirectX11App::g_Context->IASetInputLayout(m_InputLayout.Get());
			// ���_�o�b�t�@�[�̐ݒ�
			DirectX11App::g_Context->IASetVertexBuffers(0, 1, mesh.GetVertexBuffer(), &strides, &offset);
			// �C���f�b�N�X�o�b�t�@�̐ݒ�
			DirectX11App::g_Context->IASetIndexBuffer(mesh.GetIndexBuffer(), DXGI_FORMAT_R32_UINT, 0);

			//// ���[���h�s��̐ݒ�
			//DirectX::XMMATRIX world_matrix;
			//DirectX::XMMATRIX translate = DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);
			//DirectX::XMMATRIX rotate_x = DirectX::XMMatrixRotationX(DirectX::XMConvertToRadians(degree.x));
			//DirectX::XMMATRIX rotate_y = DirectX::XMMatrixRotationY(DirectX::XMConvertToRadians(degree.y));
			//DirectX::XMMATRIX rotate_z = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(degree.z));
			//DirectX::XMMATRIX scale_mat = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);
			//world_matrix = scale_mat * rotate_x * rotate_y * rotate_z * translate;

			//// ���[���h�s���萔�o�b�t�@�ɐݒ�
			//DirectX::XMStoreFloat4x4(&DirectX11App::g_ConstantBufferData.world, DirectX::XMMatrixTranspose(world_matrix));
			//// �萔�o�b�t�@�̍X�V
			//DirectX11App::g_Context->UpdateSubresource(DirectX11App::g_ConstantBuffer.Get(), 0, NULL, &DirectX11App::g_ConstantBufferData, 0, 0);

			//ID3D11Buffer* buffer = DirectX11App::g_ConstantBuffer.Get();
			//// �R���e�L�X�g�ɒ萔�o�b�t�@��ݒ�
			//DirectX11App::g_Context->VSSetConstantBuffers(0, 1, &buffer);
			//DirectX11App::g_Context->PSSetConstantBuffers(0, 1, &buffer);

			// �|���S���`��
			DirectX11App::g_Context->DrawIndexed(static_cast<UINT>(mesh.GetIndices().size()), 0, 0);
		}
	}
}

void DrawManager::DrawEnd()
{
	DirectX11App::g_SwapChain->Present(0, 0);
}

void DrawManager::SetInputLayout(ID3D11InputLayout* inputLayout)
{
	m_InputLayout.Attach(inputLayout);
}
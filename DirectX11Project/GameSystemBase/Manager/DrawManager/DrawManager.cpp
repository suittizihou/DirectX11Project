#include "DrawManager.h"
#include "../../../App/DirectX11App/DirectX11App.h"
#include "../../../Setting/Window/Window.h"
#include "../../../Utility/Material/Material.h"

InputLayout DrawManager::m_InputLayout{ nullptr };

void DrawManager::SetShader(const My3DLib::Material& material)
{
	Shader shader{ material.g_Shader };
	ID3D11VertexShader* vertexShader{ shader.GetVertexShader() };
	ID3D11PixelShader* pixelShader{ shader.GetPixelShader() };
	ID3D11GeometryShader* geometryShader{ shader.GetGeometryShader() };
	ID3D11ComputeShader* computeShader{ shader.GetComputeShader() };
	ID3D11HullShader* hullShader{ shader.GetHullShader() };
	ID3D11DomainShader* domainShader{ shader.GetDomainShader() };

	// ���ꂼ�� nullptr �łȂ��ꍇ�V�F�[�_�[���Z�b�g����
	if (computeShader != nullptr) DirectX11App::g_Context->CSSetShader(computeShader, nullptr, 0);
	if (vertexShader != nullptr) DirectX11App::g_Context->VSSetShader(vertexShader, nullptr, 0);
	if (hullShader != nullptr) DirectX11App::g_Context->HSSetShader(hullShader, nullptr, 0);
	if (domainShader != nullptr) DirectX11App::g_Context->DSSetShader(domainShader, nullptr, 0);
	if (geometryShader != nullptr) DirectX11App::g_Context->GSSetShader(geometryShader, nullptr, 0);
	if (pixelShader != nullptr) DirectX11App::g_Context->PSSetShader(pixelShader, nullptr, 0);
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

void DrawManager::Draw(const My3DLib::ModelData::Model& model)
{
	My3DLib::Material material{};
	material.g_Shader.SetVertexShader(0);
	material.g_Shader.SetPixelShader(0);

	UINT strides = sizeof(My3DLib::VertexData);
	UINT offset = 0;

	// �V�F�[�_�[�̃Z�b�g
	DrawManager::SetShader(material);

	for (const auto& meshs : model.meshes) {
		for (auto mesh : meshs.second) {
			// �C���v�b�g���C�A�E�g�̐ݒ�
			DirectX11App::g_Context->IASetInputLayout(m_InputLayout.Get());
			// ���_�o�b�t�@�[�̐ݒ�
			DirectX11App::g_Context->IASetVertexBuffers(0, 1, mesh.GetVertexBuffer(), &strides, &offset);
			// �C���f�b�N�X�o�b�t�@�̐ݒ�
			DirectX11App::g_Context->IASetIndexBuffer(mesh.GetIndexBuffer(), DXGI_FORMAT_R32_UINT, 0);
			// �|���S���̎��
			DirectX11App::g_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			// �����_�[�^�[�Q�b�g�̐ݒ�
			DirectX11App::g_Context->OMSetRenderTargets(1, DirectX11App::g_RenderTargetView.GetAddressOf(), DirectX11App::g_DepthStencilView.Get());

			// �|���S���`��
			DirectX11App::g_Context->DrawIndexed(static_cast<UINT>(mesh.GetVertices().size()), 0, 0);
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
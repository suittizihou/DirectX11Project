#include "DirectX11App.h"
#include "../../Setting/Window/Window.h"
#include "../../System/DebugLog/DebugLog.h"

D3DDevice DirectX11App::m_Device{ nullptr };
D3DContext DirectX11App::m_Context{ nullptr };
SwapChain DirectX11App::m_SwapChain{ nullptr };
Texture2D DirectX11App::m_BuckBufferTexture{ nullptr };
RenderTargetView DirectX11App::m_RenderTargetView{ nullptr };
Microsoft::WRL::ComPtr<IDXGIAdapter> DirectX11App::m_Adapter{ nullptr };


HRESULT DirectX11App::Init()
{
	HRESULT hr{};
	hr = HardWareCheck();
	if (FAILED(hr)) {
		DebugLog::LogError("Hard Ware Check Failed.");
		return hr;
	}

	hr = DirectXInit();
	if (FAILED(hr)) {
		DebugLog::LogError("DirectX Initialize Failed.");
		return hr;
	}

	return hr;
}

int DirectX11App::Update()
{
	return 0;
}

HRESULT DirectX11App::HardWareCheck()
{
	Microsoft::WRL::ComPtr<IDXGIFactory> factory{ nullptr };
	Microsoft::WRL::ComPtr<IDXGIOutput> adapterOutput{ nullptr };
	UINT numModes{ 0 };
	size_t stringLength{};
	DXGI_ADAPTER_DESC adapterDesc{};

	// �O���t�B�b�N �C���^�[�t�F�[�X �t�@�N�g�����쐬
	auto hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(hr)) {
		DebugLog::LogError("Graphic Interface Factory Create Failed.");
		return hr;
	}

	int gpuNumber{};
	int gpuMaxMem{};
	// ��ԋ���GPU�A�_�v�^������(�S�A�_�v�^�̌�����������VRAM����ԑ����A�_�v�^���擾)
	for (int adapterNum = 0; factory->EnumAdapters(adapterNum, &m_Adapter) != DXGI_ERROR_NOT_FOUND; ++adapterNum) {
		Microsoft::WRL::ComPtr<IDXGIAdapter> add{ nullptr };
		hr = factory->EnumAdapters(adapterNum, &add);
		if (FAILED(hr)) break;

		hr = add->GetDesc(&adapterDesc);

		char videoCardDescription[128];
		// �r�f�I�J�[�h�����擾
		int error = wcstombs_s(&stringLength, videoCardDescription, 128, adapterDesc.Description, 128);

		if (error != 0) break;

		DebugLog::Log("�r�f�I�J�[�h�� : " + std::string(videoCardDescription, sizeof(videoCardDescription) / sizeof(videoCardDescription[0])));

		// �r�f�I�J�[�h���������擾(MB�P��)
		int videoCardMemory = static_cast<int>(adapterDesc.DedicatedVideoMemory / 1024 / 1024);
		DebugLog::Log("�r�f�I�������[ : " + videoCardMemory);

		// �A�E�g�v�b�g(���j�^�[)�ɔԍ�ID��t����
		hr = add->EnumOutputs(0, &adapterOutput);
		if (FAILED(hr)) continue;

		// DXGI_FORMAT_R8G8B8A8_UNORM �̕\���`�������擾����
		hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
		if (FAILED(hr)) continue;
		DebugLog::Log("RGBA8_UNORM Count : " + numModes);

		if (videoCardMemory > gpuMaxMem) {
			gpuMaxMem = videoCardMemory;
			gpuNumber = adapterNum;
		}
	}

	// �O���t�B�b�N �C���^�[�t�F�[�X �A�_�v�^�[���쐬
	hr = factory->EnumAdapters(gpuNumber, &m_Adapter);
	if (FAILED(hr)) return hr;

	return hr;
}

HRESULT DirectX11App::DirectXInit()
{
	UINT cdev_flags{};
#ifdef _DEBUG
	cdev_flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// �X���b�v�`�F�C���ݒ�
	DXGI_SWAP_CHAIN_DESC sd{};
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = Window::g_WindowRight;
	sd.BufferDesc.Height = Window::g_WindowBottom;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = Window::g_FPS;
	sd.BufferDesc.RefreshRate.Denominator = 1; // 1 / 60 = 60fps
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = Window::g_hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1
	};

	HRESULT hr{};

	// DirectX11�f�o�C�X�ƃX���b�v�`�F�C���쐬
	hr = D3D11CreateDeviceAndSwapChain(m_Adapter.Get(), D3D_DRIVER_TYPE_UNKNOWN, NULL,
		cdev_flags, featureLevels, 1, D3D11_SDK_VERSION, &sd,
		&m_SwapChain, &m_Device, NULL, &m_Context);
	if (FAILED(hr)) {
		DebugLog::LogError("Swap Chain Create Failed.");
		return hr;
	}

	// �X���b�v�`�F�C���ɗp�ӂ��ꂽ�o�b�t�@(2D�e�N�X�`��)���擾
	hr = m_SwapChain->GetBuffer(0, IID_PPV_ARGS(&m_BuckBufferTexture));
	if (FAILED(hr)) {
		DebugLog::LogError("Buffer Texture Get Failed.");
		return hr;
	}

	// �����_�[�^�[�Q�b�gView�쐬
	hr = m_Device->CreateRenderTargetView(m_BuckBufferTexture.Get(), NULL, &m_RenderTargetView);
	if (FAILED(hr)) {
		DebugLog::LogError("Render Target View Create Failed.");
		return hr;
	}

	return hr;
}

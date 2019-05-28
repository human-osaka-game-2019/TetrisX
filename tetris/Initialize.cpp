#include "Initialize.h"

#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib,"dxguid.lib")
#pragma comment (lib,"dinput8.lib")

HRESULT Init::InitD3Device(HWND hWnd, const TCHAR* FilePath) {
	if (NULL == (pDirect3D = Direct3DCreate9(D3D_SDK_VERSION))) {
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}

	Init::InitPresentParameters(hWnd);

	if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&D3dPresentParameters,&pD3Device))){

		MessageBox(0, "HALモードでDIRECT3Dデバイスの作成に失敗しました\nREFモードで再試行します",NULL,MB_OK);
		if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&D3dPresentParameters, &pD3Device))) {
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
			return E_FAIL;
		}
	}
}

HRESULT Init::BuildDxDevice(HWND hWnd, const TCHAR* filepath)
{
	if (FAILED(InitD3Device(hWnd, filepath))) {
		return E_FAIL;
	}

	if (FAILED(InitDinput(hWnd))) {
		return E_FAIL;
	}

	pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (pDirect3D == NULL) {
		MessageBox(0, "Direct3Dの作成に失敗しました", NULL, MB_OK);
		return E_FAIL;
	}

	pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	
	pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	return S_OK;
}

void Init::InitPresentParameters(HWND hWnd)
{
	ZeroMemory(&D3dPresentParameters, sizeof(D3dPresentParameters));

	D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	D3dPresentParameters.BackBufferCount = 1;
	D3dPresentParameters.BackBufferHeight = 480;
	D3dPresentParameters.BackBufferWidth = 640;
	D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	D3dPresentParameters.MultiSampleQuality = 0;
	D3dPresentParameters.hDeviceWindow = hWnd;
	D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	D3dPresentParameters.Flags = 0;
	D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3dPresentParameters.Windowed = TRUE;
}

HRESULT Init::InitDinput(HWND hWnd)
{
	HRESULT hr;
	
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION,IID_IDirectInput8,(VOID * *)& pDinput,NULL)))
	{
		return hr;
	}

	if (FAILED(hr = pDinput->CreateDevice(GUID_SysKeyboard,&pDxIKetDevice,NULL)))
	{
		return hr;
	}

	if (FAILED(hr = pDxIKetDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	if (FAILED(hr = pDxIKetDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}

	pDxIKetDevice->Acquire();
	return S_OK;
}
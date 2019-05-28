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
	if (FAILED(D3DXCreateTextureFromFileEx(pD3Device, FilePath, 100, 100, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,D3DX_FILTER_NONE,D3DX_DEFAULT,
		0xff000000, NULL, NULL, &pTexture))) {
		MessageBox(0, "テクスチャの作成に失敗しました", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

void Init::InitPresentParameters(HWND hWnd) {
	ZeroMemory(&D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	D3dPresentParameters.BackBufferWidth = 0;
	D3dPresentParameters.BackBufferHeight = 0;
	D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	D3dPresentParameters.BackBufferCount = 1;
	D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	D3dPresentParameters.MultiSampleQuality = 0;
	D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3dPresentParameters.hDeviceWindow = hWnd;
	D3dPresentParameters.Windowed = TRUE;
	D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	D3dPresentParameters.Flags = 0;
	D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}
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

	InitPresentParameters(hWnd);

	if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&D3dPresentParameters,&pD3Device))){

		MessageBox(0, "HALモードでDIRECT3Dデバイスの作成に失敗しました\nREFモードで再試行します");
		if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&D3dPresentParameters, &pD3Device))) {
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
			return E_FAIL;
		}
	}
}
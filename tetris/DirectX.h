#ifndef DirectX_H
#define DirectX_H

#include <windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <d3dx9tex.h>
#include <tchar.h>

#define TEX_MAX 10

class DirectX {
public:
	//　Direct3Dのインターフェイス
	LPDIRECT3D9 pDirect3D;

	//　Direct3Dのデバイス
	IDirect3DDevice9* pD3Device;

	//　ウィンドウの設定
	D3DPRESENT_PARAMETERS D3dPresentParameters;
	
	//　DirectInputのキーボードデバイス
	LPDIRECTINPUTDEVICE8 pDxIKeyDevice;

	//　DirectInputのインターフェイス
	LPDIRECTINPUT8 pDinput;

	//　テクスチャ
	LPDIRECT3DTEXTURE9 pTexture[TEX_MAX];

	enum KEY_STATE {
		PRESS,
		RELEASE,
		ON,
		OFF
	};

	static const int MAX_KEY = 256;
	const int MASK_NUM = 0x80;

	KEY_STATE KeyState[256];

	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	HRESULT InitDinput(HWND hWnd);

	void InitPresentParameters(HWND hWnd);

	void UpdateKeyState();

	KEY_STATE GetKeyState(INT diks);

	void All_Release();


};
#endif
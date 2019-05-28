#include <windows.h>
#include <d3dx9.h>
#include <dinput.h>

class Init {
public:
	//　Direct3Dのインターフェイス
	LPDIRECT3D9 pDirect3D;
	//　Direct3Dのデバイス
	IDirect3DDevice9* pD3Device;
	//　ウィンドウの設定
	D3DPRESENT_PARAMETERS D3dPresentParameters;
	//　DirectInputのキーボードデバイス
	LPDIRECTINPUTDEVICE8 pDxIKetDevice;
	//　DirectInputのインターフェイス
	LPDIRECTINPUT8 pDinput;
	//　テクスチャ
	LPDIRECT3DTEXTURE9 pTexture;
	//カスタムバーテックス
	struct CustomVertex {
		FLOAT x, y, z, rhw;
		DWORD color;
		FLOAT tu, tv;
	};

	BYTE KeyState[256];

	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	void InitPresentParameters(HWND hWnd);

	HRESULT InitDinput(HWND hWnd);
};

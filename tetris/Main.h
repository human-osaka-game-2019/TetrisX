#include <windows.h>
#include <d3d9.h>

//カスタムバーテックス
struct CustomVertex {
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

//WinMain関数
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd,HINSTANCE* hInstance,const TCHAR* API_NAME);

//メインループ
VOID Mainloop(MSG* msg);

void InitPresentParameters(HWND hWnd);

enum TEX_NO {
	TITLE,
	TITLE_BACK,
	GAME_BACK,
	GAME_STAGE,
	GAME_BLOCK,
	RESULT
};

enum SCENE {
	TITLE,
	GAME,
	RESULT
};

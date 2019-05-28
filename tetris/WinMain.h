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

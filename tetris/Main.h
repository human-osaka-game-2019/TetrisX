#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"

//カスタムバーテックス
struct CustomVertex {
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

extern DirectX dx;

//WinMain関数
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd,HINSTANCE* hInstance,const TCHAR* API_NAME);

//メインループ
void Mainloop(MSG* msg);

enum TEX_NO {
	TITLE_BACK,
	TITLE_FONT,
	GAME_BACK,
	GAME_STAGE,
	GAME_BLOCK,
	RESULT_BACK,
	RESULT_FONT
};

enum SCENE {
	TITLE,
	GAME,
	RESULT
};

#endif

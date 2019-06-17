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

extern DirectX dx;
extern SCENE scene;

//WinMain関数
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd,HINSTANCE* hInstance,const TCHAR* API_NAME);

//メインループ
void Mainloop(MSG* msg);

//描画関数
void Draw(FLOAT x, FLOAT y, FLOAT tu, FLOAT tv,FLOAT width,FLOAT height,FLOAT tu_width,FLOAT tv_height,INT texture);

#endif

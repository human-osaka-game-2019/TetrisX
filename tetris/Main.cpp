#include "Control.h"
#include "Initialize.h"
#include "WinMain.h"

#define Width 1920
#define Height 1080 
 
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int nCmdShow) {

	const TCHAR API_NAME[] = _T("Tetris_X");
	DWORD Prev = timeGetTime();
	DWORD Curr;

	//メッセージ
	MSG msg;

	//ウィンドウクラス
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW; //ウィンドウスタイル
	Wndclass.lpfnWndProc = WndProc; //ウィンドウプロシージャ
	Wndclass.cbClsExtra = 0; //メモリ確保
	Wndclass.cbWndExtra = 0; //メモリ確保
	Wndclass.hInstance = hInstance;	//ハンドルインスタンス
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソル
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景のブラシ,色
	Wndclass.lpszMenuName = NULL; //メニュー画面の名前
	Wndclass.lpszClassName = API_NAME; //アプリケーションの名前

	//ウィンドウクラスの登録
	RegisterClass(&Wndclass);

	//ウィンドウハンドルにcreatewindow関数で作った情報を代入
	HWND hWnd = CreateWindow(
		API_NAME,							//クラスの名前
		API_NAME,							//アプリケーションのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウのスタイル
		CW_USEDEFAULT,						//Xの位置
		CW_USEDEFAULT,						//Yの位置
		Width,								//幅
		Height,								//高さ
		NULL,								//親ウィンドウのハンドル
		NULL,								//メニューのハンドル
		hInstance,							//インスタンスハンドル
		NULL								//メッセージに渡されるパラメータ
	);

	ZeroMemory(&msg, sizeof(msg));


	//ウィンドウ情報をみて更新
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	return (int)msg.wParam;
}

//ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//メッセージ別の処理
	switch (msg)
	{
		//ウィンドウが破壊されたときのメッセージ
	case WM_DESTROY:
		//閉じるメッセージを送る
		PostQuitMessage(0);
		return 0;
		//ユーザーがメニューかALTキーと何かを押したとき
	case WM_SYSKEYDOWN:
		switch (wp)
		{
		case VK_RETURN:
			return 0;
		case VK_F4:
			//閉じるメッセ―ジ
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			return 0;
		}
		return 0;
	}
	//DefaultWindowProcedureを返す(デフォルト)
	return DefWindowProc(hWnd, msg, wp, lp);
}
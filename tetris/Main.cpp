#include "Control.h"
#include "DirectX.h"
#include "Main.h"
#include "Title.h"

#define Width 1280
#define Height 720 

Init init;
 
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int nCmdShow) {
	HWND hWnd = NULL;
	const TCHAR API_NAME[] = _T("Tetris_X");
	//メッセージ
	MSG msg;
	hWnd = GenerateWindow(&hWnd, &hInstance, API_NAME);

	Mainloop(&msg);


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

HWND GenerateWindow(HWND* hWnd,HINSTANCE* hInstance,const TCHAR* API_NAME) {
	//ウィンドウクラス
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW; //ウィンドウスタイル
	Wndclass.lpfnWndProc = WndProc; //ウィンドウプロシージャ
	Wndclass.cbClsExtra = 0; //メモリ確保
	Wndclass.cbWndExtra = 0; //メモリ確保
	Wndclass.hInstance = *hInstance;	//ハンドルインスタンス
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソル
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景のブラシ,色
	Wndclass.lpszMenuName = NULL; //メニュー画面の名前
	Wndclass.lpszClassName = API_NAME; //アプリケーションの名前

	//ウィンドウクラスの登録
	RegisterClass(&Wndclass);

	//ウィンドウハンドルにcreatewindow関数で作った情報を代入
	return *hWnd = CreateWindow(
		API_NAME,							//クラスの名前
		API_NAME,							//アプリケーションのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウのスタイル
		CW_USEDEFAULT,						//Xの位置
		CW_USEDEFAULT,						//Yの位置
		Width,								//幅
		Height,								//高さ
		NULL,								//親ウィンドウのハンドル
		NULL,								//メニューのハンドル
		*hInstance,							//インスタンスハンドル
		NULL								//メッセージに渡されるパラメータ
	);
}

VOID Mainloop(MSG* msg) {
	
	enum SCENE scene;

	DWORD Prev = timeGetTime();
	DWORD Curr;
	
	timeBeginPeriod(1);

	ZeroMemory(msg, sizeof(msg));
	while (msg->message != WM_QUIT) {
		if (PeekMessage(msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(msg);
			DispatchMessage(msg);
		}
		else {
			Curr = timeGetTime();
			if (Curr - Prev >= 1000 / 60) {
				//ここからゲーム処理
				switch (scene) {
				case TITLE:

					break;
				case GAME:

					break;
				case RESULT:

					break;
				}

				Prev = Curr;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
}


void InitPresentParameters(HWND hWnd)
{
	ZeroMemory(&(init.D3dPresentParameters), sizeof(init.D3dPresentParameters));

	init.D3dPresentParameters.BackBufferWidth = 1280;
	init.D3dPresentParameters.BackBufferHeight = 720;
	init.D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	init.D3dPresentParameters.BackBufferCount = 1;
	init.D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	init.D3dPresentParameters.MultiSampleQuality = 0;
	init.D3dPresentParameters.hDeviceWindow = hWnd;
	init.D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	init.D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	init.D3dPresentParameters.Flags = 0;
	init.D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	init.D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	init.D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	init.D3dPresentParameters.Windowed = TRUE;
}


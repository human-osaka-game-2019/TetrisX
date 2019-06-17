#include "Result.h"

//リザルトのフェーズの移動
void Result::Result_Scene() {

	switch (Phase) {
	case LOAD:
		Loading();
		break;
	case PROCESSING:
		Process();
		break;
	case RELEASES:
		Release();
		Phase = LOAD;
		break;
	}
}

//リザルトのテクスチャの読み込み
void Result::Loading() {

	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Result_Back.png"),
		&dx.pTexture[RESULT_BACK]);
	Phase = PROCESSING;
}

//リザルトの描画処理
void Result::Process() {

	//リザルトの描画
	Draw(0, 0, 0.0f, 0.0f, window_width, window_height, 1.0f,1.0f,RESULT_BACK);

	//エンターでタイトルへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//リザルトのテクスチャの解放
void Result::Release() {

	dx.pTexture[RESULT_BACK]->Release();
	dx.pTexture[RESULT_BACK] = nullptr;
	scene = TITLE;
}

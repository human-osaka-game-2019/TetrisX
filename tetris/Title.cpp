#include "Title.h"

//タイトルのフェーズの宣言
Title::SCENE_PHASE Phase = Title::LOAD;

//タイトルのフェーズの移動
void Title::Title_Scene() {

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

//タイトルのテクスチャの読み込み
void Title::Loading() {
			D3DXCreateTextureFromFile(
			dx.pD3Device,
			_T("Title_Back.png"),
			&dx.pTexture[TITLE_BACK]);
		Phase = PROCESSING;
}

//タイトルの描画処理
void Title::Process() {

	//タイトルの描画
	Draw(0, 0, 0.0f, 0.0f, window_width, window_height,1.0f,1.0f,TITLE_BACK);

	//エンターでゲームへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//タイトルのテクスチャの解放
void Title::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}
	scene = GAME;

}

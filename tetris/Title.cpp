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
	dx.pD3Device->SetTexture(0, dx.pTexture[TITLE_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleBack_Vertex, sizeof(CustomVertex));

	//エンターでゲームへ
	if (dx.GetKeyState(DIK_RETURN)) {
		Phase = RELEASES;
	}
}

//タイトルのテクスチャの解放
void Title::Release() {

	dx.pTexture[TITLE_BACK]->Release();
	dx.pTexture[TITLE_BACK] = nullptr;
	scene = GAME;

}

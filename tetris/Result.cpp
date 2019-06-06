#include "Result.h"

//リザルトのフェーズの宣言
Result::SCENE_PHASE Phase = Result::LOAD;

//リザルトの
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
	dx.pD3Device->SetTexture(0, dx.pTexture[RESULT_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,ResultBack_Vertex, sizeof(CustomVertex));

	//エンターでタイトルへ
	if (dx.GetKeyState(DIK_RETURN)) {
		Phase = RELEASES;
	}
}

//リザルトのテクスチャの解放
void Result::Release() {

	dx.pTexture[RESULT_BACK]->Release();
	dx.pTexture[RESULT_BACK] = nullptr;
	scene = TITLE;
}

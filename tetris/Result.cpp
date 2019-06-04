#include "Result.h"

Result::SCENE_PHASE Phase = Result::LOAD;

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

void Result::Loading() {

	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Result_Back.png"),
		&dx.pTexture[RESULT_BACK]);
	Phase = PROCESSING;
}

void Result::Process() {

	dx.pD3Device->SetTexture(0, dx.pTexture[RESULT_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,ResultBack_Vertex, sizeof(CustomVertex));
	if (dx.GetKeyState(DIK_RETURN)) {
		Phase = RELEASES;
	}
}

void Result::Release() {

	dx.pTexture[RESULT_BACK]->Release();
	dx.pTexture[RESULT_BACK] = nullptr;
	scene = TITLE;
}

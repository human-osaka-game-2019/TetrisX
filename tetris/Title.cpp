#include "Title.h"

Title::SCENE_PHASE Phase = Title::LOAD;

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

void Title::Loading() {
			D3DXCreateTextureFromFile(
			dx.pD3Device,
			_T("Title_Back.png"),
			&dx.pTexture[TITLE_BACK]);
		Phase = PROCESSING;
}

void Title::Process() {

	dx.pD3Device->SetTexture(0, dx.pTexture[TITLE_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleBack_Vertex, sizeof(CustomVertex));
	if (dx.GetKeyState(DIK_RETURN)) {
		Phase = RELEASES;
	}
}

void Title::Release() {

	dx.pTexture[TITLE_BACK]->Release();
	dx.pTexture[TITLE_BACK] = nullptr;
	scene = GAME;

}

#include "Title.h"

Title::SCENE_PHASE Phase = Title::LOAD;

void Title::Title_Scene() {

	CustomVertex customvertex[4]{
	{0,0,0,1,0xffffff,0.0f,0.0f},
	{1280,0,0,1,0xffffff,1.0f,0.0f},
	{1280,720,0,1,0xffffff,1.0f,1.0f},
	{0,720,0,1,0xffffff,0.0f,1.0f}
	};

	switch (Phase) {
	case LOAD:
		Loading();
		break;
	case PROCESSING:
		Process(customvertex);
		break;
	case RELEASES:
		Release();
		break;
	}
	SCENE_PHASE phase = LOAD;
}

void Title::Loading() {
	if (loading) {
		D3DXCreateTextureFromFile(
			dx.pD3Device,
			_T("Title_Back.png"),
			&dx.pTexture[TITLE_BACK]);
		loading = false;
		Phase = PROCESSING;
	}
}

void Title::Process(CustomVertex* cutomvertex) {

	dx.pD3Device->SetTexture(0, dx.pTexture[TITLE_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cutomvertex, sizeof(CustomVertex));
}

void Title::Release() {
	dx.pTexture[TITLE_BACK]->Release();
	dx.pTexture[TITLE_BACK] = nullptr;
}
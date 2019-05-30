#include "Title.h"

void Title::Title_Scene() {
	SCENE_PHASE Phase_T = LOAD;

	CustomVertex customvertex[4]{
	{0,0,0,1,0xffffff,0.0f,0.0f},
	{1280,0,0,1,0xffffff,1.0f,0.0f},
	{1280,720,0,1,0xffffff,1.0f,1.0f},
	{0,720,0,1,0xffffff,0.0f,1.0f}
	};

	switch (Phase_T) {
	case LOAD:
		title.Loading();
		break;
	case PROCESSING:
		title.Process(customvertex);
		break;
	case RELEASES:
		title.Release();
		break;
	}
	SCENE_PHASE phase = LOAD;


}

void Title::Loading() {
	if (Loading) {
		D3DXCreateTextureFromFile(
			dx.pD3Device,
			_T("Title_Back.png"),
			&dx.pTexture[TITLE_BACK]);
		Loading == false;
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
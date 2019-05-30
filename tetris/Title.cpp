#include "DirectX.h"
#include "Title.h"
#include "Main.h"

void title_Scene() {
	CustomVertex customvertex[4]{
		{0,0,0,1,0x000000,0.0f,0.0f},
		{1280,0,0,1,0x000000,1.0f,0.0f},
		{1280,720,0,1,0x000000,1.0f,1.0f},
		{0,720,0,1,0x000000,0.0f,1.0f}
	};

	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Title_Back.png"),
		&dx.pTexture[TITLE_BACK]);

	dx.pD3Device->SetTexture(0, dx.pTexture[TITLE_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CustomVertex));
}

#include "Game.h"

Game::SCENE_PAHSE Phase = Game::LOAD;

void Game::Game_Scene() {

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

void Game::Loading() {
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Back.png"),
		&dx.pTexture[GAME_BACK]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Stage.png"),
		&dx.pTexture[GAME_STAGE]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Block.png"),
		&dx.pTexture[GAME_BLOCK]
	);
	Phase = PROCESSING;
}

void Game::Process() {


	if (dx.GetKeyState(DIK_UP)) {

		BLOCK_y -= 36;
			
	}
	
	if (dx.GetKeyState(DIK_DOWN)) {
		
			BLOCK_y += 36;
		
	}
	
	if (dx.GetKeyState(DIK_RIGHT)) {
	
			BLOCK_x += 36;

	}
	
	if (dx.GetKeyState(DIK_LEFT)) {
		
		BLOCK_x -= 36;
		
	}
	
	CustomVertex GameBlock_Vertex[4] = {
		{BLOCK_x,BLOCK_y,1,1,0xffffff,0.0f,0.0f},
		{BLOCK_x + BLOCK_width,BLOCK_y,1,1,0xffffff,1.0f,0.0f},
		{BLOCK_x + BLOCK_width,BLOCK_y + BLOCK_height,1,1,0xffffff,1.0f,1.0f},
		{BLOCK_x,BLOCK_y + BLOCK_height,1,1,0xffffff,0.0f,1.0f}
	};

	dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBack_Vertex, sizeof(CustomVertex));

	for (INT row = 0; row <= 20; row++) {
	
		for (INT col = 0; col <= 10; col++) {

			CustomVertex GameStage_Vertex[4]{
				{stage_x + stage_block_width * col                    ,stage_y + stage_block_hight * row                    ,0,1,0xffffff,0.0f,0.0f},
				{stage_x + stage_block_width + stage_block_width * col,stage_y + stage_block_hight * row                    ,0,1,0xffffff,1.0f,0.0f},
				{stage_x + stage_block_width + stage_block_width * col,stage_y + stage_block_hight + stage_block_hight * row,0,1,0xffffff,1.0f,1.0f},
				{stage_x + stage_block_width * col                    ,stage_y + stage_block_hight + stage_block_hight * row,0,1,0xffffff,0.0f,1.0f}
			};

			dx.pD3Device->SetTexture(0, dx.pTexture[GAME_STAGE]);
			dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameStage_Vertex, sizeof(CustomVertex));
		}

	}
	
	dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
	

	if (dx.GetKeyState(DIK_RETURN)) {
		Phase = RELEASES;
	}
}

void Game::Release() {
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_STAGE]->Release();
	dx.pTexture[GAME_STAGE] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;
	scene = RESULT;
}

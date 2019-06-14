
#include "Game.h"

Game::SCENE_PAHSE Phase = Game::LOAD;

//ゲームのフェーズの移動
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

//ゲームのテクスチャの読み込み
void Game::Loading() {
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Back.png"),
		&dx.pTexture[GAME_BACK]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Block.png"),
		&dx.pTexture[GAME_STAGE]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Block.png"),
		&dx.pTexture[GAME_BLOCK]
	);
	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {


	if (dx.KeyState[DIK_UP] == dx.PRESS) {

		BLOCK_y -= 36;

	}
	//下移動
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {

		BLOCK_y += 36;

	}
	//右移動
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {

		BLOCK_x += 36;

	}
	//左移動
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {

		BLOCK_x -= 36;

	}

	//ゲーム時の背景描画
	dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BACK]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBack_Vertex, sizeof(CustomVertex));

	//ステージ描画
	for (INT row = 0; row < 20; row++) {

		for (INT col = 0; col < 10; col++) {
			
			switch(color){

			case Back:
				Block_tu = 0.75f;
				Block_tv = 0.75f;
				break;
			case Red:
				Block_tu = 0.0f;
				Block_tv = 0.0f;
				break;
			case Blue:
				Block_tu = 0.25f;
				Block_tv = 0.0f;
				break;
			case Green:
				Block_tu = 0.5f;
				Block_tv = 0.0f;
				break;
			case Yellow:
				Block_tu = 0.75f;
				Block_tv = 0.0f;
				break;
			case White:
				Block_tu = 0.0f;
				Block_tv = 0.25;
				break;
			case Black:
				Block_tu = 0.25f;
				Block_tv = 0.25f;
				break;
			case Lightblue:
				Block_tu = 0.75f;
				Block_tv = 0.25f;
				break;
			default:
				Block_tu = 0.75f;
				Block_tv = 0.75f;
				break;
			}

			CustomVertex GameStage_Vertex[4]{
				{stage_x + stage_block_width * col                    ,stage_y + stage_block_hight * row                    ,0,1,0xffffff,Block_tu,Block_tv},
				{stage_x + stage_block_width + stage_block_width * col,stage_y + stage_block_hight * row                    ,0,1,0xffffff,Block_tu + 0.25,Block_tv},
				{stage_x + stage_block_width + stage_block_width * col,stage_y + stage_block_hight + stage_block_hight * row,0,1,0xffffff,Block_tu + 0.25,Block_tv + 0.25},
				{stage_x + stage_block_width * col                    ,stage_y + stage_block_hight + stage_block_hight * row,0,1,0xffffff,Block_tu,Block_tv + 0.25}
			};

			dx.pD3Device->SetTexture(0, dx.pTexture[GAME_STAGE]);
			dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameStage_Vertex, sizeof(CustomVertex));
		}
	}

	//重力
	BLOCK_y += 1;
	
	srand((unsigned int)time(NULL));

	//下につくと7種類の描画・真ん中に移動処理
	if (BLOCK_y + BLOCK_height >= window_height - 108) {
		//Block_Kind = rand() % 7;
		//BLOCK_x = stage_x + 108;
		BLOCK_y = window_height - 108;
	}
	
		/*ブロック描画*/

	if (Block_Kind == 0) {
		//Lのブロック
		for (BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 && BlockRow < 3) || (BlockRow == 2 && BlockCol < 3 && BlockCol > 0)) {
					
					CustomVertex  GameBlock_Vertex[4]{
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f}
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));

				}
			}
		}
	}
	else if (Block_Kind == 1) {
		//Iのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if (BlockCol == 1) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
				}
			}
		}
	}
	else if (Block_Kind == 2) {
		//Jのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 2 && BlockRow < 3) || (BlockRow == 2 && BlockCol < 3 && BlockCol >0)) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
				}
			}
		}
	}
	else if (Block_Kind == 3) {
		//Sのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 && BlockRow == 1) || (BlockCol == 2 && BlockRow == 1) || (BlockCol == 0 && BlockRow == 2) || (BlockCol == 1 && BlockRow == 2)) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
				}
			}
		}
	}
	else if (Block_Kind == 4) {
		//Oのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 || BlockCol == 2) && (BlockRow == 1 || BlockRow == 2)) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
				}
			}
		}
	}
	else if (Block_Kind == 5) {
		//Zのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 0 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 2) || (BlockCol == 2 && BlockRow == 2)) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};

					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
				}
			}
		}
	}
	else if (Block_Kind == 6) {
		//Tのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 0 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 1) || (BlockCol == 2 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 2)) {
					CustomVertex GameBlock_Vertex[4] = {
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
						{BLOCK_x + BLOCK_width + BLOCK_width * BlockCol,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
						{BLOCK_x + BLOCK_width * BlockCol              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f},
					};
					dx.pD3Device->SetTexture(0, dx.pTexture[GAME_BLOCK]);
					dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameBlock_Vertex, sizeof(CustomVertex));
					
				}
			}
		}
	}


	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//ゲームのテクスチャの解放
void Game::Release() {
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_STAGE]->Release();
	dx.pTexture[GAME_STAGE] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;
	scene = RESULT;
}
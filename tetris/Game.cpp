
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

	FrameCount++;

	
	//一瞬で下に落とす処理
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

	//ゲーム時の背景描画]
	Draw(0, 0, 0.0f, 0.0f, window_width, window_height, 1.0f, 1.0f, GAME_BACK);
	
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
			//二次元配列にし、背景に反映→動いているブロックから情報を持ってくる
			//座標の特性持った構造体を作
			Draw(stage_x + stage_block_width * col, stage_y + stage_block_hight * row, Block_tu, Block_tv, stage_block_width, stage_block_hight,0.25f,0.25f, GAME_STAGE);

		}
	}

	//重力
	if (FrameCount == 60){
		// 1秒たった
		FrameCount = 0;
		BLOCK_y += 36;
	}

	//テトリミノをランダム
	srand((unsigned int)time(NULL));


	//下につくと7種類の描画・真ん中に移動処理
	if (BLOCK_y + BLOCK_height >= window_height - 36) {
		Block_Kind = rand() % 7;
		BLOCK_x = stage_x + 108;
		BLOCK_y = -144;
	}

	//当たり判定・左・L
	if (stage_x <= BLOCK_x && (Block_Kind == 0 || Block_Kind == 1)) {
		BLOCK_x = stage_x;
	}

	//当たり判定・右
	if (stage_x + stage_block_hight * 10 >= BLOCK_x + BLOCK_width * 4  && Block_Kind) {
		BLOCK_x = stage_x + stage_block_hight * 10 - BLOCK_width * 4;
	}
	
		/*ブロック描画*/

	if (Block_Kind == 0) {
		//Lのブロック
		for (BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 && BlockRow < 3) || (BlockRow == 2 && BlockCol < 3 && BlockCol > 0)) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.0f, 0.0f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);
					
				}
			}
		}
	}
	else if (Block_Kind == 1) {
		//Iのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if (BlockCol == 1) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.25f, 0.0f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);
				
				}
			}
		}
	}
	else if (Block_Kind == 2) {
		//Jのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 2 && BlockRow < 3) || (BlockRow == 2 && BlockCol < 3 && BlockCol >0)) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.5f, 0.0f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);
				}
			}
		}
	}
	else if (Block_Kind == 3) {
		//Sのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 && BlockRow == 1) || (BlockCol == 2 && BlockRow == 1) || (BlockCol == 0 && BlockRow == 2) || (BlockCol == 1 && BlockRow == 2)) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.75f, 0.0f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);

				}
			}
		}
	}
	else if (Block_Kind == 4) {
		//Oのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 1 || BlockCol == 2) && (BlockRow == 1 || BlockRow == 2)) {

					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.0f, 0.25f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);

				}
			}
		}
	}
	else if (Block_Kind == 5) {
		//Zのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 0 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 2) || (BlockCol == 2 && BlockRow == 2)) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.25f, 0.25f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);
					
				}
			}
		}
	}
	else if (Block_Kind == 6) {
		//Tのブロック
		for (INT BlockRow = 0; BlockRow < 4; BlockRow++) {

			for (INT BlockCol = 0; BlockCol < 4; BlockCol++) {
				if ((BlockCol == 0 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 1) || (BlockCol == 2 && BlockRow == 1) || (BlockCol == 1 && BlockRow == 2)) {
					
					Draw(BLOCK_x + BLOCK_width * BlockCol, BLOCK_y + BLOCK_height * BlockRow, 0.75f, 0.25f, BLOCK_width, BLOCK_height, 0.25f, 0.25f, GAME_STAGE);
					
				}
			}
		}
	}

	//debug用
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//ゲームのテクスチャの解放
void Game::Release() {
	//ブロック位置の初期化
	BLOCK_x = stage_x + 108;
	BLOCK_y = -144;

	//テクスチャの開放
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_STAGE]->Release();
	dx.pTexture[GAME_STAGE] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;

	//リザルトシーンへ
	scene = RESULT;
}
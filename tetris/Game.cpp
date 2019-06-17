
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
		&dx.pTexture[GAME_BLOCK]
	);
	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {

	FrameCount++;

	
	//一瞬で下に落とす処理
	if (dx.KeyState[DIK_UP] == dx.PRESS) {

		block_y -= 36;

	}
	//下移動
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {

		block_y += 36;

	}
	//右移動
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {

		block_x += 36;

	}
	//左移動
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {

		block_x -= 36;

	}

	//ゲーム時の背景描画]
	Draw(0, 0, 0.0f, 0.0f, window_width, window_height, 1.0f, 1.0f, GAME_BACK);
	
	//ステージ描画
	for (INT row = 0; row < 20; row++) {

		for (INT col = 0; col < 10; col++) {
			
			switch(color){

			case Back:
				block_tu = 0.75f;
				block_tv = 0.75f;
				break;
			case Red:
				block_tu = 0.0f;
				block_tv = 0.0f;
				break;
			case Blue:
				block_tu = 0.25f;
				block_tv = 0.0f;
				break;
			case Green:
				block_tu = 0.5f;
				block_tv = 0.0f;
				break;
			case Yellow:
				block_tu = 0.75f;
				block_tv = 0.0f;
				break;
			case White:
				block_tu = 0.0f;
				block_tv = 0.25;
				break;
			case Black:
				block_tu = 0.25f;
				block_tv = 0.25f;
				break;
			case Lightblue:
				block_tu = 0.75f;
				block_tv = 0.25f;
				break;
			default:
				block_tu = 0.75f;
				block_tv = 0.75f;
				break;
			}
			//二次元配列にし、背景に反映→動いているブロックから情報を持ってくる
			//座標の特性持った構造体を作
			Draw(stage_x + stage_block_width * col, stage_y + stage_block_hight * row, block_tu, block_tv, stage_block_width, stage_block_hight,0.25f,0.25f, GAME_BLOCK);

		}
	}

	//重力
	if (FrameCount == 60){
		// 1秒たった
		FrameCount = 0;
		block_y += 36;
	}

	//テトリミノをランダム
	srand((unsigned int)time(NULL));


	//下につくと7種類の描画・真ん中に移動処理
	if (block_y + block_height >= window_height - 36) {
		block_Kind = rand() % 7;
		block_x = stage_x + 108;
		block_y = -144;
	}

	//当たり判定・左・L
	if (stage_x <= block_x && (block_Kind == 0 || block_Kind == 1)) {
		block_x = stage_x;
	}

	//当たり判定・右
	if (stage_x + stage_block_hight * 10 >= block_x + block_width * 4  && block_Kind) {
		block_x = stage_x + stage_block_hight * 10 - block_width * 4;
	}
	
		/*ブロック描画*/

	if (block_Kind == 0) {
		//Lのブロック
		for (block_row = 0; block_row < 4; block_row++) {

			for (block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 1 && block_row < 3) || (block_row == 2 && block_col < 3 && block_col > 0)) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.0f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
					
				}
			}
		}
	}
	else if (block_Kind == 1) {
		//Iのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if (block_col == 1) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.25f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
				
				}
			}
		}
	}
	else if (block_Kind == 2) {
		//Jのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 2 && block_row < 3) || (block_row == 2 && block_col < 3 && block_col >0)) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.5f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
				}
			}
		}
	}
	else if (block_Kind == 3) {
		//Sのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 1 && block_row == 1) || (block_col == 2 && block_row == 1) || (block_col == 0 && block_row == 2) || (block_col == 1 && block_row == 2)) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.75f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);

				}
			}
		}
	}
	else if (block_Kind == 4) {
		//Oのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 1 || block_col == 2) && (block_row == 1 || block_row == 2)) {

					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.0f, 0.25f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);

				}
			}
		}
	}
	else if (block_Kind == 5) {
		//Zのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 0 && block_row == 1) || (block_col == 1 && block_row == 1) || (block_col == 1 && block_row == 2) || (block_col == 2 && block_row == 2)) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.25f, 0.25f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
					
				}
			}
		}
	}
	else if (block_Kind == 6) {
		//Tのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 0 && block_row == 1) || (block_col == 1 && block_row == 1) || (block_col == 2 && block_row == 1) || (block_col == 1 && block_row == 2)) {
					
					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.75f, 0.25f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
					
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
	block_x = stage_x + 108;
	block_y = -144;

	//テクスチャの開放
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;

	//リザルトシーンへ
	scene = RESULT;
}
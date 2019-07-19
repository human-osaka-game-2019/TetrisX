
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

	//テトリミノをランダム
	srand((unsigned int)time(NULL));
	CreateBlock();

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {

	FrameCount++;

	
	//一瞬で下に落とす処理
	if (dx.KeyState[DIK_UP] == dx.PRESS) {


	}
	//下移動
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {


	}
	//右移動
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {

		MoveSide(RIGHT);

	}
	//左移動
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {

		MoveSide(LEFT);

	}

	//重力
	if (FrameCount == 60) {
		// 1秒たった
		FrameCount = 0;
		MoveDown();
	}

	//ゲーム時の背景描画
	Draw(0, 0, 0.0f, 0.0f, window_width, window_height, 1.0f, 1.0f, GAME_BACK);
	
	//ステージ描画
	for (INT row = 0; row < 25; row++) {

		for (INT col = 0; col < 12; col++) {

			//二次元配列にし、背景に反映→動いているブロックから情報を持ってくる
			//座標の特性持った構造体を作る
			Draw(stage_x + stage_block_width * col, 
				stage_y + stage_block_hight * row, 
				GetUV(board[row][col]).u,
				GetUV(board[row][col]).v,
				stage_block_width,
				stage_block_hight,0.25f,0.25f, GAME_BLOCK);

		}
	}

	//ブロック描画
	DrawBlocks();

	if (landed) {
		FixBloack();
		CreateBlock();
	}

	//debug用
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
	if (dx.KeyState[DIK_E] == dx.PRESS && dx.KeyState[DIK_S] == dx.PRESS) {
		
	}
}

//ゲームのテクスチャの解放
void Game::Release() {
	
	//テクスチャの開放
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;

	//リザルトシーンへ
	scene = RESULT;
}

void Game::MoveDown() {
	if (CanMove(DOWN)) {
		++block_position.row;
	}
	else {
		landed = true;
	}
}

void Game::MoveSide(DIRECTION direction) {
	if (CanMove(direction) == RIGHT) {
		block_position.col += 1;
	}
	else if (CanMove(direction) == LEFT) {
		block_position.col -= 1;
	}
}

void Game::DrawBlocks() {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (block[row][col].blockkind != Back) {
				FLOAT left = stage_x + block_width * (block_col + col);
				FLOAT top = stage_y + block_height * (block_row + row);
				UV uv = GetUV(color);
				Draw(left, top, uv.u,uv.v ,block_width, block_height, 0.25, 0.25, GAME_BLOCK);

	/*ブロック描画*/

	if (block_kind == L) {
		//Lのブロック
		for (block_row = 0; block_row < 4; block_row++) {

			for (block_col = 0; block_col < 4; block_col++) {
				if ((block_col == 1 && block_row < 3) || (block_row == 2 && block_col < 3 && block_col > 0)) {

					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.0f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);
					
					/*if (board[20][1] == Back) {
						board[20][1] = Red;
						board[20][2] = Red;
						board[19][1] = Red;
						board[18][1] = Red;
						exists[20][1] = true;
						exists[20][1] = true;
						exists[20][1] = true;
						exists[20][1] = true;
					}*/
				}
			}
		}
	}
	else if (block_kind == L) {

	}
	else if (block_kind == I) {
		//Iのブロック
		for (INT block_row = 0; block_row < 4; block_row++) {

			for (INT block_col = 0; block_col < 4; block_col++) {
				if (block_col == 1) {

					Draw(block_x + block_width * block_col, block_y + block_height * block_row, 0.25f, 0.0f, block_width, block_height, 0.25f, 0.25f, GAME_BLOCK);

				}
			}
		}
	}
}

void Game::Jugement() {

}

Game::UV Game::GetUV(COLOR color) {
	UV uv;

	switch (color) {
	case Back:
		uv.SetUV(0.75f,0.75f);
		break;
	case Red:
		uv.SetUV(0.0f,0.0f);
		break;
	case Blue:
		uv.SetUV(0.25f,0.0f);
		break;
	case Green:
		uv.SetUV(0.5f,0.0f);
		break;
	case Yellow:
		uv.SetUV(0.75f,0.0f);
		break;
	case White:
		uv.SetUV(0.0f,0.25f);
		break;
	case Black:
		uv.SetUV(0.5f,0.25f);
		break;
	case Lightblue:
		uv.SetUV(0.75f,0.25f);
		break;
	case Wall:
		uv.SetUV(0.75f, 0.75f);
		break;
	default:
		uv.SetUV(0.75f, 0.75f);
		break;
	}

	return uv;
}

bool Game::CanMove(DIRECTION direction) {
	Game::Cell topleft = block_position;

	switch (direction) {
	case LEFT:
	case RIGHT:
		if (direction == RIGHT) {
			topleft.col += 1;
		}
		else if (direction == LEFT) {
			topleft.col -= 1;
			}
	case DOWN:
		++topleft.row;
		break;
	default:
		return false;
	}

	if (Conflict(topleft)) {
		return false;
	}

	return true;
}

bool Game::Conflict(Cell topleft) {
	for (int row = 0; row < 4;row++) {
		for (int col = 0; col < 4; col++) {
			if (block[row][col].blockkind == (Back || Wall)) {
				continue;
			}
			if (board[topleft.row + row][topleft.col + col] != (Back || Wall)) {
				return true;
			}
		}
	}
	return false;
}

void Game::CreateBlock() {
	const Block(*tmpl)[4];

	switch (rand() % 7)
	{
	case Game::L:
		color = Red;
		tmpl = block_L;
		break;
	case Game::I:
		color = Blue;
		tmpl = block_I;
		break;
	case Game::J:
		color = Green;
		tmpl = block_J;
		break;
	case Game::S:
		color = Yellow;
		tmpl = block_S;
		break;
	case Game::O:
		color = White;
		tmpl = block_O;
		break;
	case Game::Z:
		color = Black;
		tmpl = block_Z;
		break;
	case Game::T:
		color = Lightblue;
		tmpl = block_T;
		break;
	default:
		return;
		break;
	}
	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){
			block[row][col] = tmpl[row][col];
		}
	}
	
	block_position.col = 3;
	block_position.row = 0;
	landed = false;
}

void Game::FixBloack() {
	int col = block_position.col;
	int row = block_position.row;

	for (int y = 0; y < 4; y++){
		for (int x = 0; x < 4; x++) {
			if (block[y][x].blockkind != 0) {
				board[row + y][col + x] = color;
			}
		}
	}
}

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
	CreateMino();

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {
	FrameCount++;

	Control();
	
	//ゲーム時の背景描画
	Draw(0, 0, 0.0f, 0.0f, windowSize.w, windowSize.h, 1.0f, 1.0f, GAME_BACK);
	
	//ステージ描画
	for (INT row = 4; row < 25; row++) {
		for (INT col = 0; col < 12; col++) {
			UV uv = GetUV(board[row][col]);

			//二次元配列にし、背景に反映→動いているブロックから情報を持ってくる
					 	//座標の特性持った構造体を作る
			FLOAT x = stageTopLeft.x + blockSize.w * col;
			FLOAT y = stageTopLeft.y + blockSize.h * row;
			Draw(x, y, uv.u, uv.v, blockSize.w, blockSize.h, 0.25f, 0.25f, GAME_BLOCK);
		}
	}

	//ミノ描画
	DrawMino();

	//下につくと7種類の描画・真ん中に移動処理
	if (landed) {
		FixMino();
		CreateMino();
	}

	//debug用
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

void Game::Control()
{
	//一瞬で下に落とす処理
	if (dx.KeyState[DIK_UP] == dx.PRESS) {
		//block_y -= 36;
	}
	//下移動
	if (dx.KeyState[DIK_DOWN] == dx.PRESS){
		MoveDown();
	}
	//右移動
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS){
		MoveHorizontally(RIGHT);
	}
	//左移動
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
		MoveHorizontally(LEFT);
	}

	//重力
	if (FrameCount == 60){
		// 1秒たった
		FrameCount = 0;
		MoveDown();
	}
}

void Game::MoveDown()
{
	if (CanMove(DOWN)) {
		++blockPosition.row;
	} else {
		landed = true;
	}
}

void Game::MoveHorizontally(DIRECTION direction)
{
	if(CanMove(direction)) {
		blockPosition.col += (direction == LEFT ? -1 : 1);
	}
}

void Game::FixMino()
{
	int col = blockPosition.col;
	int row = blockPosition.row;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (mino[y][x] != 0) {
				board[row + y][col + x] = minoColor;
			}
		}
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

void Game::CreateMino() {
	const INT(*tmpl)[4];

	switch (rand() % 7) {
	case L:
		minoColor = Red;
		tmpl = MINO_L;
		break;
	case I:
		minoColor = Blue;
		tmpl = MINO_I;
		break;
	case J:
		minoColor = Green;
		tmpl = MINO_J;
		break;
	case S:
		minoColor = Yellow;
		tmpl = MINO_S;
		break;
	case O:
		minoColor = White;
		tmpl = MINO_O;
		break;
	case Z:
		minoColor = Black;
		tmpl = MINO_Z;
		break;
	case T:
		minoColor = Lightblue;
		tmpl = MINO_T;
		break;
	default:
		return;
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			mino[y][x] = tmpl[y][x];
		}
	}

	blockPosition.col = 3;
	blockPosition.row = 0;
	landed = false;
}

void Game::DrawMino() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (mino[y][x]) {
				FLOAT left = stageTopLeft.x + blockSize.w * (blockPosition.col + x);
				FLOAT top = stageTopLeft.y + blockSize.h * (blockPosition.row + y);
				UV uv = GetUV(minoColor);
				Draw(left, top, uv.u, uv.v, blockSize.w, blockSize.h, 0.25f, 0.25f, GAME_BLOCK);
			}
		}
	}
}

Game::UV Game::GetUV(COLOR color)
{
	UV uv;
	switch (color) {
	case Red:
		uv.SetUV(0.0f, 0.0f);
		break;
	case Blue:
		uv.SetUV(0.25f, 0.0f);
		break;
	case Green:
		uv.SetUV(0.5f, 0.0f);
		break;
	case Yellow:
		uv.SetUV(0.75f, 0.0f);
		break;
	case White:
		uv.SetUV(0.0f, 0.25f);
		break;
	case Black:
		uv.SetUV(0.5f, 0.25f);
		break;
	case Lightblue:
		uv.SetUV(0.75f, 0.25f);
		break;
	case Wall:
		uv.SetUV(0.25f, 0.5f);
		break;
	default:
		uv.SetUV(0.75f, 0.75f);
		break;
	}

	return uv;
}

bool Game::CanMove(DIRECTION direction)
{
	// 衝突判定の基点となるCell
	Cell topLeft = blockPosition;

	switch (direction) {
	case Game::LEFT:
	case Game::RIGHT:
		// ミノを左右に動かした場所で衝突しているかをチェックする
		topLeft.col += (direction == RIGHT ? 1 : -1);
		break;
	case Game::DOWN:
		// ミノを下に動かした場所で衝突しているかをチェックする
		++topLeft.row;
		break;
	default:
		return false;
	}

	if (Collides(topLeft)) {
		return false;
	}

	return true;
}

bool Game::Collides(Cell topLeft)
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (mino[y][x] == Back) {
				continue;
			}

			if (board[topLeft.row + y][topLeft.col + x] != Back) {
				return true;
			}
		}
	}

	return false;
}

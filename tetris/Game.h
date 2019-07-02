#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"
#include <time.h>

class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	Game::SCENE_PAHSE Phase = Game::LOAD;

private:
	enum COLOR {
		Back,
		Red,
		Blue,
		Green,
		Yellow,
		White,
		Black,
		Lightblue,
		Wall,
	};

	//ブロックの種類
	enum BLOCK_KIND {
		L,
		I,
		J,
		S,
		O,
		Z,
		T
	};

	// 方向
	enum DIRECTION {
		LEFT,
		RIGHT,
		DOWN
	};

	// 行と列
	struct Cell {
		int row, col;
	};

	// 座標(pixel)
	struct Point {
		FLOAT x, y;
	};

	// uv値
	struct UV {
		FLOAT u, v;
		void SetUV(FLOAT tu, FLOAT tv) { u = tu; v = tv; }
	};

	// 幅と高さ(pixel)
	struct Size {
		FLOAT w, h;
	};

	//関数のプロトタイプ宣言
	void Loading();
	void Process();
	void Control();
	void Release();
	void CreateMino();
	void DrawMino();
	UV GetUV(COLOR color);
	bool CanMove(DIRECTION direction);
	bool Collides(Cell topLeft);
	void MoveDown();
	void MoveHorizontally(DIRECTION direction);
	void FixMino();

	//ウィンドウのサイズ
	Size windowSize = { 1280.0f, 720.0f };

	//ゲームステージの位置
	Point stageTopLeft = { 460.0f, -144.0f };

	//ブロックの1マスの大きさ
	Size blockSize = { 36.0f, 36.0f };
		   
	//フレームを数える
	INT FrameCount = 0;

	//移動ブロックの縦と横
	Cell blockPosition;

	// 接地したかどうか
	bool landed = false;

	// 落下中のminoの色
	COLOR minoColor = Red;

	COLOR board[25][12] = {
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Back,Back,Back,Back,Back,Back,Back,Back,Back,Back,Wall},
	{Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall},
	};

	const int MINO_L[4][4] = {
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0},
	};

	const int MINO_I[4][4] = {
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
	};

	const int MINO_J[4][4] = {
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0},
	};

	const int MINO_S[4][4] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0},
	};

	const int MINO_O[4][4] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0},
	};

	const int MINO_Z[4][4] = {
		{0, 0, 0, 0},
		{1, 1, 0, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0},
	};

	const int MINO_T[4][4] = {
		{0, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0},
	};

	int mino[4][4];
};

#endif

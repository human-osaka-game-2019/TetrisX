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

	struct UV {
		float u, v;
		void SetUV(float tu, float tv){
			u = tu; 
			v = tv; 
		}
	};

	enum DIRECTION {
		LEFT,
		RIGHT,
		DOWN
	};

	struct Cell {
		int col;
		int row;
	};

	//ウィンドウのサイズ
	FLOAT window_height = 720;
	FLOAT window_width = 1280;

	//ゲームステージの位置
	FLOAT stage_x = 460;
	FLOAT stage_y = 0;
	FLOAT stage_width = 360;
	FLOAT stage_height = 720;

	//ステージの1マスの大きさ
	FLOAT stage_block_width = 36;
	FLOAT stage_block_hight = 36;

	//移動ブロックの位置
	FLOAT block_x = stage_x + 108;
	FLOAT block_y = -144;

	//ブロックの1マスの大きさ
	FLOAT block_width = 36;
	FLOAT block_height = 36;
		   
	//フレームを数える
	INT FrameCount = 0;

	//ブロックの種類
	INT block_kind = 0;

	//移動ブロックの縦と横
	INT block_row = 0;
	INT block_col = 0;

	//ブロックのtuとtv
	FLOAT block_tu = 0.0f;
	FLOAT block_tv = 0.0f;

	bool landed = false;

	Cell block_position;

	void Loading();
	void Process();
	void Release();

	//関数プロトタイプ宣言
	void DrawBlocks();
	void Jugement();
	bool CanMove(DIRECTION direction);
	bool Conflict(Cell topleft);
	void CreateBlock();
	void MoveSide(DIRECTION direction);
	void MoveDown();
	void FixBloack();


	//色
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

	COLOR color = Red;

	UV GetUV(COLOR);

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
	{Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall},
	};

	};

	Block block[4][4];
};

#endif

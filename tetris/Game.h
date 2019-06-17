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
	FLOAT block_tu = 0.5f;
	FLOAT block_tv = 0.5f;
	
	//ステージのフラグ
	bool exists[20][10];

	//関数のプロトタイプ宣言
	void Loading();
	void Process();
	void Release();
	void DrawBlocks();
	void Jugement();

	//
	enum COLOR {
		Back,
		Red,
		Blue,
		Green,
		Yellow,
		White,
		Black,
		Lightblue
	};

	COLOR color = Back;

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
};

#endif

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

	//ステージの1マスの大きさ
	FLOAT stage_block_width = 36;
	FLOAT stage_block_hight = 36;

	//移動ブロックの位置
	FLOAT BLOCK_x = stage_x + 108;
	FLOAT BLOCK_y = -144;

	//ブロックの1マスの大きさ
	FLOAT BLOCK_width = 36;
	FLOAT BLOCK_height = 36;
		   
	//フレームを数える
	INT FrameCount = 0;

	//ブロックの種類
	INT Block_Kind = 0;
	
	//移動ブロックの縦と横
	INT BlockRow = 0;
	INT BlockCol = 0;

	//ブロックのtuとtv
	FLOAT Block_tu = 0.5f;
	FLOAT Block_tv = 0.5f;
	
	//ステージのフラグ
	bool exists[20][10];

	//関数のプロトタイプ宣言
	void Loading();
	void Process();
	void Release();

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

	struct BLOCK {

	};
};

#endif

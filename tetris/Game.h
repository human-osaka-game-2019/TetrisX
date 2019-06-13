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

private:
	FLOAT window_height = 720;
	FLOAT window_width = 1280;

	FLOAT stage_x = 460;
	FLOAT stage_y = 0;
	FLOAT stage_block_width = 36;
	FLOAT stage_block_hight = 36;

	FLOAT BLOCK_x = stage_x + 108;
	FLOAT BLOCK_y = 0;
	FLOAT BLOCK_width = 36;
	FLOAT BLOCK_height = 36;
		   
	INT Block_Kind = 0;
	INT block_kind = 0;

	INT BlockRow = 0;
	INT BlockCol = 0;

	FLOAT Block_tu = 0.5f;
	FLOAT Block_tv = 0.5f;

	bool exists[20][10];

	void Loading();
	void Process();
	void Release();

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

	enum BLOCK_KIND {
		L,
		I,
		J,
		S,
		O,
		Z,
		T
	};

	CustomVertex GameBack_Vertex[4]{
		{0,0,0,1,0xffffff,0.0f,0.0f},
		{window_width,0,0,1,0xffffff,1.0f,0.0f},
		{window_width,window_height,-1,1,0xffffff,1.0f,1.0f},
		{0,window_height,0,1,0xffffff,0.0f,1.0f}
		};
};

#endif

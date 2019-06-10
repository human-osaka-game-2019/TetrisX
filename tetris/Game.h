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

	FLOAT stage_x = 400;
	FLOAT stage_y = 0;
	FLOAT stage_block_width = 36;
	FLOAT stage_block_hight = 36;

	FLOAT BLOCK_x = stage_x + 108;
	FLOAT BLOCK_y = 0;
	FLOAT BLOCK_width = 36;
	FLOAT BLOCK_height = 36;
		   
	void Loading();
	void Process();
	void Release();

	INT Block_Kind = 0;
	INT block_kind = 0;

	FLOAT BlockRow = 0;
	FLOAT BlockCol = 0;

	FLOAT leftposition;

	CustomVertex  GameBlock_Vertex[4]{
		{BLOCK_x + BLOCK_width * leftposition              ,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,0.0f,0.0f},
		{BLOCK_x + BLOCK_width + BLOCK_width * leftposition,BLOCK_y + BLOCK_height * BlockRow               ,0,1,0xffffff,1.0f,0.0f},
		{BLOCK_x + BLOCK_width + BLOCK_width * leftposition,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,1.0f,1.0f},
		{BLOCK_x + BLOCK_width * leftposition              ,BLOCK_y + BLOCK_height + BLOCK_height * BlockRow,0,1,0xffffff,0.0f,1.0f}
	};

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
#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"

class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

private:
	FLOAT window_width = 1280;
	FLOAT window_height = 720;

	FLOAT stage_x = 400;
	FLOAT stage_y = 0;
	FLOAT stage_block_width = 36;
	FLOAT stage_block_hight = 36;

	FLOAT BLOCK_x = stage_x;
	FLOAT BLOCK_y = 400;
	FLOAT BLOCK_width = 50;
	FLOAT BLOCK_height = 50;
		   
	void Loading();
	void Process();
	void Release();
	CustomVertex GameBack_Vertex[4]{
		{0,0,0,1,0xffffff,0.0f,0.0f},
		{window_width,0,0,1,0xffffff,1.0f,0.0f},
		{window_width,window_height,-1,1,0xffffff,1.0f,1.0f},
		{0,window_height,0,1,0xffffff,0.0f,1.0f}
		};
	
	/*CustomVertex GameStage_Vertex[20][10]{
			{stage_x,stage_y,0,1,0xffffff,0.0f,0.0f},
			{stage_x + stage_block_width,stage_y,0,1,0xffffff,1.0f,0.0f},
			{stage_x + stage_block_width,stage_y + stage_block_hight,0,1,0xffffff,1.0f,1.0f},
			{stage_x,stage_y + stage_block_hight,0,1,0xffffff,0.0f,1.0f}
		};*/

	CustomVertex GameBlock_Vertex[231] = {
		{BLOCK_x,BLOCK_y,0,1,0xffffff,0.0f,0.0f},
		{BLOCK_x + BLOCK_width,BLOCK_y,0,1,0xffffff,1.0f,0.0f},
		{BLOCK_x + BLOCK_width,BLOCK_y + BLOCK_height,0,1,0xffffff,1.0f,1.0f},
		{BLOCK_x,BLOCK_y + BLOCK_height,0,1,0xffffff,0.0f,1.0f},
	};
};

#endif
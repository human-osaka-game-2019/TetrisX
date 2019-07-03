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
		Lightblue,
		Wall,
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

	INT board[21][12] = {
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

	//ステージのフラグ
	bool exists[21][12] = {
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,false,false,false,false,false,false,false,false,false,false,true},
		{true,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true},
	};

	// ピース管理構造体
	typedef struct tagPIECE
	{
		//bool block[block_row][block_col]; // true：ブロックあり / false：なし
		BYTE image;         // ブロックのビットマップ番号
		char x, y;           // 左上のセル座標
	}PIECE;

	//現在移動中のブロックの位置 
	PIECE location = { 0,0 };

};

#endif

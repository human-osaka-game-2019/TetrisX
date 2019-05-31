#include "Game.h"

Game::SCENE_PAHSE Phase = Game::LOAD;

void Game::Game_Scene() {

	switch (Phase) {
	case LOAD:
		Loading();
	case PROCESSING:
		Process(Block_Vertex);
	case RELEASES:
		Release();
	}
}

void Game::Loading() {
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Back.png"),
		&dx.pTexture[GAME_BACK]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_STAGE.png"),
		&dx.pTexture[GAME_STAGE]
	);
	D3DXCreateTextureFromFile(
		dx.pD3Device,
		_T("Game_Block.png"),
		&dx.pTexture[GAME_BLOCK]
	);
	Phase = PROCESSING;
}

void Game::Process(CustomVertex* customvertex) {

}

void Game::Release() {
	dx.pTexture[GAME_BACK]->Release();
	dx.pTexture[GAME_BACK] = nullptr;
	dx.pTexture[GAME_STAGE]->Release();
	dx.pTexture[GAME_STAGE] = nullptr;
	dx.pTexture[GAME_BLOCK]->Release();
	dx.pTexture[GAME_BLOCK] = nullptr;
	scene = RESULT;
}

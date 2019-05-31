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

	void Loading();
	void Process(CustomVertex*);
	void Release();
	CustomVertex Block_Vertex[231] = {

	};
};

#endif
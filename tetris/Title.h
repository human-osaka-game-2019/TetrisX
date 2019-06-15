#ifndef TITLE_H
#define TITLE_H

#include "DirectX.h"
#include "Main.h"

class Title {
public:

	void Title_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

private:
	FLOAT window_width = 1280;
	FLOAT window_height = 720;
	void Loading();
	void Process();
	void Release(); 
	
};

#endif
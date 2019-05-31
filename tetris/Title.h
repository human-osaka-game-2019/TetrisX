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

	void Loading();
	void Process(CustomVertex*);
	void Release(); 
	CustomVertex TitleBack_Vertex[4]{
		{0,0,0,1,0xffffff,0.0f,0.0f},
		{1280,0,0,1,0xffffff,1.0f,0.0f},
		{1280,720,0,1,0xffffff,1.0f,1.0f},
		{0,720,0,1,0xffffff,0.0f,1.0f}
	};
};

#endif
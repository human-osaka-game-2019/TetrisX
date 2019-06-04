#ifndef RESULT_H
#define RESULT_H

#include "DirectX.h"
#include "Main.h"

class Result {
public:

	void Result_Scene();

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
	CustomVertex ResultBack_Vertex[4]{
		{0,0,0,1,0xffffff,0.0f,0.0f},
		{window_width,0,0,1,0xffffff,1.0f,0.0f},
		{window_width,window_height,0,1,0xffffff,1.0f,1.0f},
		{0,window_height,0,1,0xffffff,0.0f,1.0f}
	};
};
#endif

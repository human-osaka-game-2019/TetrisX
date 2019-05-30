#include "DirectX.h"
#include "Main.h"

class Title {
public:
	bool Loading;
	bool Process;
	bool Release;

	void Title_Scene();
	void Loading();
	void Process(CustomVertex*);
	void Release();
};

Title title;

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>

class Control {
public:

	static const int MAX_KEY_NUMBER = 256;
	const int MASK_NUM = 0x80;
	BYTE KeyState[MAX_KEY_NUMBER];

	void UpdateKeyState();

	void GetKeyState(BYTE KeyState);
};
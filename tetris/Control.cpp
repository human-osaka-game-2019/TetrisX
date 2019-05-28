#include "Control.h"
#include "Initialize.h"

Init init;

void Control::UpdateKeyState(){
	HRESULT hr = init.pDxIKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE)) {
		init.pDxIKeyDevice->GetDeviceState(sizeof(KeyState), &KeyState);
	}
}

bool Control::GetKeyState(BYTE KeyNumber) {
	if (KeyState[KeyNumber] & 0x80) {
		return true;
	}
	return false;
}

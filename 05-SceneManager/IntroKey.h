#pragma once
#include "Scene.h"
class CIntroKey : public CSceneKeyHandler
{
public:
	virtual void OnKeyDown(int KeyCode);
	virtual void KeyState(BYTE* states) {};
	virtual void OnKeyUp(int KeyCode) {};
	CIntroKey(LPSCENE s) : CSceneKeyHandler(s) {}
};


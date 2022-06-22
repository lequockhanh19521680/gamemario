#include "Scene.h"

class CWorldMapKeyEvent : public CSceneKeyHandler
{
	CScene* scene;
public:
	virtual void OnKeyDown(int KeyCode);
	virtual void KeyState(BYTE* states) {};
	virtual void OnKeyUp(int KeyCode) {};
	CWorldMapKeyEvent(LPSCENE s) : CSceneKeyHandler(s) { scene = s; }
};
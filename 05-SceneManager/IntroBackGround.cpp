#include "IntroBackGround.h"
#include "Game.h"
#include "debug.h"
void CIntroBackGround::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (state == BACKGROUND_STATE_WILL_CHANGE_SCENE) {
		if (GetTickCount64() - start_change > TIME_CHANGE_SCENE_WORLD_MAP) CGame::GetInstance()->InitiateSwitchScene(ID_SCENE_WORLD_MAP);
	}
}

void CIntroBackGround::Render() {
	if (state != BACKGROUND_STATE_MOVE) { CAnimations::GetInstance()->Get(ID_ANI_INTRO_BACKGROUND_DONE)->Render(x , y); }
	if (state != BACKGROUND_STATE_WILL_CHANGE_SCENE)
	{
		if(isUpArrow) introArrow->Render(x + POSITION_X_ARROW, y + POSITION_Y_ARROW);
		else introArrow->Render(x + POSITION_X_ARROW, y + POSITION_Y_ARROW + DISTANCE_ARROW);
	}
	else {
		if(isUpArrow) introArrow->RenderChangeScene(x + POSITION_X_ARROW, y + POSITION_Y_ARROW);
		else introArrow->RenderChangeScene(x + POSITION_X_ARROW, y + POSITION_Y_ARROW + DISTANCE_ARROW);
	}
	
	DebugOutTitle(L"state %d", state);
}

void CIntroBackGround::SetState(int state) {
	switch (state) {
	case BACKGROUND_STATE_MOVE: break;
	case BACKGROUND_STATE_DONE_ARROW_UP:
		isUpArrow = true;
		break;
	case BACKGROUND_STATE_DONE_ARROW_DOWN:
		isUpArrow = false;
		break;
	case BACKGROUND_STATE_WILL_CHANGE_SCENE:
		start_change = GetTickCount64();
		break;
	}
	CGameObject::SetState(state);
}
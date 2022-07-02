#pragma once
#include "GameObject.h"
#include "IntroArrow.h"
#include"FontIntro.h"
#define SPEED_BACKGROUND 0.05f
#define ID_ANI_INTRO_BACKGROUND_NOT_DONE 400000
#define ID_ANI_INTRO_BACKGROUND_DONE 400001

#define BACKGROUND_STATE_MOVE 100
#define BACKGROUND_STATE_DONE_ARROW_UP 200
#define BACKGROUND_STATE_DONE_ARROW_DOWN 300
#define BACKGROUND_STATE_WILL_CHANGE_SCENE 400
#define POSITION_X_ARROW -56
#define POSITION_Y_ARROW 55
#define DISTANCE_ARROW 16

#define TIME_CHANGE_SCENE_WORLD_MAP 1600
class CIntroBackGround :public CGameObject
{
private:
	ULONGLONG start_change;
	bool isUpArrow;
	CIntroArrow* introArrow = NULL;
public:
	CIntroBackGround(float x, float y) : CGameObject(x, y) {
		introArrow = new CIntroArrow();
		SetState(BACKGROUND_STATE_MOVE);
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void SetState(int l);
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};

};


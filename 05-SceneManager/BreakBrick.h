#pragma once

#include "GameObject.h"

#define ID_ANI_BREAK 565

#define BREAK_GRAVTY 0.0003f

#define BREAK_SPEED_Y_HIGH 0.15f
#define BREAK_SPEED_Y_LOW 0.1f
#define BREAK_SPEED_X 0.05f

#define BREAK_STATE_TOP_RIGHT 100
#define BREAK_STATE_TOP_LEFT 200
#define BREAK_STATE_BOTTOM_RIGHT 300
#define BREAK_STATE_BOTTOM_LEFT 400

#define BREAK_EFFECT_TIME_OUT 1000

class CBreakBrick : public CGameObject
{
protected:
	float ax;
	float ay;

	BOOLEAN isFinish = false;
	ULONGLONG effect_start = -1;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) { left = top = right = bottom = 0; }
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void OnNoCollision(DWORD dt);
	virtual void Render();

public:
	CBreakBrick(float x, float y);
	virtual void SetState(int state);
};



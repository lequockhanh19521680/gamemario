#pragma once
#include "GameObject.h"

#define SPEED_EFFECT 0.12f

#define EFFECT_DELETE_TIME 600

#define EFFECT_SCORE_100 1
#define EFFECT_SCORE_200 2
#define EFFECT_SCORE_400 3
#define EFFECT_SCORE_800 4
#define EFFECT_SCORE_1000 5
#define EFFECT_SCORE_2000 6
#define EFFECT_SCORE_4000 7
#define EFFECT_SCORE_8000 8
#define EFFECT_UP 9
#define EFFECT_CHANGE 20
#define EFFECT_ATTACK 30
#define EFFECT_FONT_END_1 36
#define EFFECT_FONT_END_2 37
#define EFFECT_HELP_WORLD_MAP 40


#define ID_ANI_EFFECT_100_SCORE 31001
#define ID_ANI_EFFECT_200_SCORE 31002
#define ID_ANI_EFFECT_400_SCORE 31003
#define ID_ANI_EFFECT_800_SCORE 31004
#define ID_ANI_EFFECT_1000_SCORE 31005
#define ID_ANI_EFFECT_2000_SCORE 31006
#define ID_ANI_EFFECT_4000_SCORE 31007
#define ID_ANI_EFFECT_8000_SCORE 31008
#define ID_ANI_EFFECT_1UP 31009

#define ID_ANI_EFFECT_FONT_END_1 31015
#define ID_ANI_EFFECT_FONT_END_2 31016

#define ID_ANI_EFFECT_HELP_WORLD_MAP 31017

#define ID_ANI_EFFECT_ATTACK 31010
#define ID_ANI_EFFECT_CHANGE 31020

#define POSITION_X_CARD_EFFECT 64

#define POSITION_X_EFFECT_FONT_1 2682
#define POSITION_Y_EFFECT_FONT_1 270

#define POSITION_X_EFFECT_FONT_2 2690
#define POSITION_Y_EFFECT_FONT_2 300

class CEffect : public CGameObject
{
private:
	ULONGLONG start_delete;
	int model;
public:
	CEffect(float x, float y,int model) : CGameObject(x, y) {
		this->model = model;
		start_delete = GetTickCount64();
	}
	void Render();
	void Update(DWORD dt,vector<LPGAMEOBJECT>* coObjects);
	virtual void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	virtual int IsCollidable() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b){}
};


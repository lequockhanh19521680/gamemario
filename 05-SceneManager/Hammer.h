#pragma once
#include "GameObject.h"
#define SPEED_HAMMER 0.007f

#define HAMMER_BBOX_WIDTH 16
#define HAMMER_BBOX_HEIGHT 16


#define ID_ANI_HAMMER_LEFT 56700
#define ID_ANI_HAMMER_RIGHT 56701
class CHammer : public CGameObject
{
	float xBlock1, xBlock2;
public:
	CHammer(float x, float y) : CGameObject(x, y) {
		xBlock1 = x - HAMMER_BBOX_WIDTH/2+2;
		xBlock2 = x + HAMMER_BBOX_WIDTH/2+2;
		vx = SPEED_HAMMER;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
};


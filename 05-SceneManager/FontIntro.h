#pragma once
#include "GameObject.h"
#define SPEED_FONT 0.06f
#define ID_ANI_FONT 400060
#define BLOCK_FONT 72
class CFontIntro :public CGameObject
{
	float blockY;
public:
	CFontIntro(float x, float y) {
		vy = SPEED_FONT;
		blockY = y + BLOCK_FONT;
	}

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt) {
		y += vy * dt;
	}
	void GetBoundingBox(float& l, float& t, float& r, float& b){}

};

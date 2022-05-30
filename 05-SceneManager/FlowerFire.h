#pragma once
#include "GameObject.h"

#define ID_ANI_FLOWER 11004
#define FL_BBOX_WIDTH 10
#define FL_BBOX_HEIGHT 16
#define FL_QUICKLY_Y 0.0003f;
class CFlowerFire :	public CGameObject
{
	float ay;
	float firstYPosition;
public:
	CFlowerFire(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsCollidable() { return 1; }
	virtual void OnNoCollision(DWORD dt);
	virtual int IsBlocking() { return 0; }
	virtual bool IsItem() { return 1; }

};


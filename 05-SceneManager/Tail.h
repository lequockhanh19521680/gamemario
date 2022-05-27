#pragma once
#include "GameObject.h"
#define TAIL_BBOX_WIDTH 50
#define TAIL_BBOX_HEIGHT 8
class CTail :	public CGameObject
{

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithBrickQuestion(LPCOLLISIONEVENT e);


public:
	CTail(float x, float y);
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual int IsCollidable() { return 1; }
	void OnNoCollision(DWORD dt) {};
	virtual int IsPlayer() { return 1; }

	void OnCollisionWith(LPCOLLISIONEVENT e);


	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }

};


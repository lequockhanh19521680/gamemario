#pragma once
#include "GameObject.h"
#define BULLET_BBOX_WIDTH	8
#define BULLET_BBOX_HEIGHT	8

#define BULLET_SPEED_X	0.2f
#define BULLET_SPEED_Y	0.05f

#define BULLET_GRAVITY 0.0006f;
#define BULLET_JUMP 0.15f;

#define ID_ANI_BULLET_RIGHT		71
#define ID_ANI_BULLET_LEFT		72	

class CBullet :public CGameObject
{
protected:
	float ax, ay;

	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 0; }

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e);
public:
	CBullet(float bx, float by);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

};


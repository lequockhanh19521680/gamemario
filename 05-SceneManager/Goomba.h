#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "debug.h"

#define GOOMBA_GRAVITY 0.001f
#define GOOMBA_FLY_ADJUST 0.2f
#define GOOMBA_WALKING_SPEED 0.04f


#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 16
#define GOOMBA_BBOX_HEIGHT_DIE 10

#define GOOMBA_DIE_TIMEOUT 500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_FLY 200
#define GOOMBA_STATE_DIE 300
#define GOOMBA_STATE_DIE_UPSIDE 400


#define ID_ANI_GOOMBA_WALKING 5000
#define ID_ANI_GOOMBA_FLY 5500
#define ID_ANI_GOOMBA_DIE_UPSIDE 5600
#define ID_ANI_GOOMBA_DIE 5999


class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	int GetAniIdWalking() { return ID_ANI_GOOMBA_WALKING; };
	int GetAniIdFly() { return ID_ANI_GOOMBA_FLY; };
public: 	

	CGoomba(float x, float y);
	void SetLevel(int l);
	virtual void SetState(int state);
};
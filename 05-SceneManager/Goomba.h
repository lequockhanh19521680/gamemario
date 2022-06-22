#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "debug.h"

#define GOOMBA_GRAVITY 0.0005f

#define GOOMBA_FLY_ADJUST 0.08f
#define GOOMBA_WALKING_SPEED 0.03f
#define GOOMBA_JUMP_DEFLECT_SPEED 0.2f


#define TIME_WALKING 2000
#define TIME_JUMP_SMALL 900

#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 16
#define GOOMBA_BBOX_HEIGHT_DIE 10

#define GOOMBA_DIE_TIMEOUT 500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_FLY 200
#define GOOMBA_STATE_DIE 300
#define GOOMBA_STATE_DIE_UPSIDE 400
#define GOOMBA_STATE_IS_ATTACK 500


#define ID_ANI_GOOMBA_WALKING 5000
#define ID_ANI_GOOMBA_DIE 5001
#define ID_ANI_GOOMBA_UPSIDE 5002

#define ID_ANI_GOOMBA_RED 5003
#define ID_ANI_GOOMBA_RED_DIE 5004
#define ID_ANI_GOOMBA_RED_FLY_WALKING 5005
#define ID_ANI_GOOMBA_RED_FLY_JUMP 5006
#define ID_ANI_GOOMBA_RED_UPSIDE 5007



#define GOOMBA_BASE 1
#define GOOMBA_WING 2

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	float startX, startY;
	int model; 
	ULONGLONG die_start;
	ULONGLONG time_walking;
	ULONGLONG time_jump_small;

	bool walkingCheck;
	int num_jump_small;
	bool isJump;
	bool isUpside;
	bool isDead;
	bool isAttack;
	bool isOnPlatForm;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return !isUpside; };
	virtual int IsBlocking() { return 0; }
	virtual int IsEnemy() { return 1; }

	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWithPlatForm(LPCOLLISIONEVENT e);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	int GetAniGoompaBase();
	int GetAniGoompaWing();
public: 	
	CGoomba(float x, float y, int model);

	//get
	bool GetIsDead() { return isDead; }

	void SetModel(int model) { this->model = model; }
	int GetModel() { return model; }
	//set
	void SetLevel(int l);
	virtual void SetState(int state);
};
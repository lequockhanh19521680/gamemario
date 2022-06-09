#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "debug.h"

#define ID_ANI_MUSHROOM_RED 11001
#define ID_ANI_MUSHROOM_GREEN 11008


#define	MUSHROOM_WIDTH 10
#define MUSHROOM_BBOX_WIDTH 10
#define MUSHROOM_BBOX_HEIGHT 16
#define MUSHROOM_STATE_WALKING 100
#define MUSHROOM_STATE_OUTSIDE 200

#define MUSHROOM_GREEN 2
#define MUSHROOM_RED 1

class CMushRoom : public CGameObject {
	float ax;
	float ay;
	float startY;
	int model;
	void OnCollisionWithPlatForm(LPCOLLISIONEVENT e);


public:
	CMushRoom(float x, float y);
	CMushRoom(float x, float y, int model);
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual int IsCollidable() { return 1; }
	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);


	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	virtual void SetState(int state);

	virtual bool IsItem() { return 1; }
	void SetModel(int model) { this->model = model; }
	int GetModel() { return model; }


};


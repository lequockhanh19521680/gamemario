#pragma once
#include "Animation.h"
#include "Animations.h"
#include "Platform.h"
#include"Game.h"
#include"PlayScene.h"

#define ID_ANI_BRICK_COLOR 10001
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

#define BRICK_IS_COIN 1

#define BRICK_STATE_DELETE 100
#define BRICK_STATE_GOLD 200

#include "GameObject.h"
class CBrickColor :    public CGameObject
{
	CPlatform* platform;
	bool isBreak = false;
	bool isGold = false;
	bool isUseButton = false;
	bool isStopLoop = false;
protected:
	int model;
public:
	CBrickColor(float x, float y, int model) : CGameObject(x, y) { 
		this->model = model; 
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
};


#pragma once
#include "GameObject.h"

#define QUESTION_BRICK_BBOX_WIDTH 16
#define QUESTION_BRICK_BBOX_HEIGHT 16

#define ID_ANI_QUESTION_BRICK 11100
#define ID_ANI_QUESTION_BRICK_EMPTY 11101
#define QUESTION_BRICK_SPEED_UP 0.04f

#define QUESTION_BRICK_MAX_HEIGHT 10
#define QUESTION_BRICK_SPEED_DOWN 0.04f

#define QUESTION_BRICK_ITEM 2
#define QUESTION_BRICK_COIN 1

#define QUESTION_BRICK_STATE_UP 100

#define ADJUST_UP_DOWN 13

class CBrickQuestion : public CGameObject
{
protected:
	float ay;

	float minY;
	float startY;
	float startX;
	BOOLEAN isUnbox = false;
	BOOLEAN isEmpty = false;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt);

public:

	CBrickQuestion(float x, float y, int model);
	virtual void SetState(int state);
	float GetMinY() { return minY; }
	BOOLEAN GetIsUnbox() { return isUnbox; }
	BOOLEAN GetIsEmpty() { return isEmpty; }
	void SetIsUnbox(BOOLEAN b) { isUnbox = b; }
	void SetIsEmpty(BOOLEAN b) { isEmpty = b; }
	
	CGameObject* item = NULL;
};


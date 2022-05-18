#include "BrickQuestion.h"
#include "Leaf.h"
#include "MushRoom.h"
#include "Mario.h"
#include "PlayScene.h"
#include "FlowerFire.h"
#include "Coin.h"

CBrickQuestion::CBrickQuestion(float x, float y, int model) :CGameObject(x, y)
{
	this->model = model;
	this->ay = 0;
	this->ax = 0;
	this->minY = y - QUESTION_BRICK_BBOX_HEIGHT;
	this->startY = y;
	this->startX = x;
}

void CBrickQuestion::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - QUESTION_BRICK_BBOX_WIDTH / 2;
	top = y - QUESTION_BRICK_BBOX_HEIGHT / 2;
	right = left + QUESTION_BRICK_BBOX_WIDTH-1;
	bottom = top + QUESTION_BRICK_BBOX_HEIGHT;
}

void CBrickQuestion::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};


void CBrickQuestion::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
		if (y <= minY)
		{
			vy = QUESTION_BRICK_SPEED_DOWN;
		}
		if (y > startY)
		{
			y = startY;
			vy = 0;
			isEmpty = true;
			isUnbox = true;
		}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBrickQuestion::Render()
{
	int aniId = ID_ANI_QUESTION_BRICK;

	if (isEmpty) {
		aniId = ID_ANI_QUESTION_BRICK_EMPTY;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CBrickQuestion::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case QUESTION_BRICK_STATE_UP:
		vy = -QUESTION_BRICK_SPEED_UP;
		break;
		
	}
}
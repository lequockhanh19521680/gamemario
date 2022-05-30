#include "MushRoom.h"
#define MUSHROOM_GRAVITY 0.001f
#define MUSHROOM_SPEED 0.06f
#define OUT_BRICK -0.02f
#include "Platform.h"
CMushRoom::CMushRoom(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = MUSHROOM_GRAVITY;
	vy = 0;
	startY = y;
	SetState(MUSHROOM_STATE_OUTSIDE);
}
void CMushRoom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects){
	if (state == MUSHROOM_STATE_WALKING) {
		vy += ay * dt;
		vx += ax * dt;
	}
	else if(state == MUSHROOM_STATE_OUTSIDE) {
		if (startY - y < MUSHROOM_BBOX_HEIGHT - 1) {
			vy = OUT_BRICK;
			vx = 0;
		}
		else SetState(MUSHROOM_STATE_WALKING);
	}
		
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CMushRoom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CMushRoom::OnCollisionWith(LPCOLLISIONEVENT e)
{	
	if (!e->obj->IsBlocking() && !e->obj->IsPlatform()) return;
	if (!e->obj->IsPlayer()) {
		if (e->ny != 0)
		{
			vy = 0;
		}
		else if (e->nx != 0)
		{
			vx = -vx;
		}
	}

	if (dynamic_cast<CMushRoom*>(e->obj)) {}
	else if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatForm(e);

}
void CMushRoom::OnCollisionWithPlatForm(LPCOLLISIONEVENT e)
{
	CPlatform* platform = dynamic_cast<CPlatform*>(e->obj);
	if (platform->IsBlocking()) {}
	else if (e->ny < 0) {
		SetY(platform->GetY() - MUSHROOM_BBOX_HEIGHT);
	}
}
void CMushRoom::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_MUSHROOM)->Render(x, y);

	RenderBoundingBox();
}

void CMushRoom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;
}

void CMushRoom::SetState(int state)
{
	switch (state)
	{
		case MUSHROOM_STATE_WALKING:
		vx = -MUSHROOM_SPEED;
		break;
	}
	CGameObject::SetState(state);
}

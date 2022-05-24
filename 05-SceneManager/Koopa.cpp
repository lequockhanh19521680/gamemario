#include "Koopa.h"
#include "Goomba.h"
#include "Mario.h"
#include "Platform.h"
#include "debug.h"
#include "BrickQuestion.h"

CKoopa::CKoopa(float x, float y, int model) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPA_GRAVITY;
	this->model = model;
	defend_start = -1;
	isHeld = false;
	if (model == KOOPA_GREEN_WING) {
		SetState(KOOPA_STATE_JUMP);
	}
	else {
		SetState(KOOPA_STATE_WALKING);
	}
}
void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vy += ay * dt;
	vx += ax * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if (isDefend || isUpside) {
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT_DEFEND / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT_DEFEND;
	}
	else {
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT;
	}
}

void CKoopa::Render() {
	int aniId = ID_ANI_RED_UPSIDE_KICKED;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}

void CKoopa::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CKoopa::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (e->ny < 0)
	{
		vy = 0;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = -vx;
	}
	if (dynamic_cast<CGoomba*>(e->obj))
		this->OnCollisionWithGoomba(e);
	else if (dynamic_cast<CMario*>(e->obj))
		this->OnCollisionWithMario(e);
	else if (dynamic_cast<CBrickQuestion*>(e->obj))
		this->OnCollisionWithBrickQuestion(e);
	else if (dynamic_cast<CPlatform*>(e->obj))
		this->OnCollisionWithPlatform(e);
}
void CKoopa::OnCollisionWithBrickQuestion(LPCOLLISIONEVENT e) {

}
void CKoopa::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {

}
void CKoopa::OnCollisionWithMario(LPCOLLISIONEVENT e) {

}
void CKoopa::OnCollisionWithPlatform(LPCOLLISIONEVENT e) {

}
void CKoopa::SetState(int l) {

}

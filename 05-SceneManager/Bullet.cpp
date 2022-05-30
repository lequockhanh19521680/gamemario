#include "Bullet.h"
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Animation.h"
#include "PlantEnemy.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Pipe.h"
#include "Map.h"
CBullet::CBullet(float bx, float by)
{
	ay = BULLET_GRAVITY;
	ax = 0;
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	y = by ;
	vy = BULLET_SPEED_Y;


	if(mario->GetNx()>0){
		x = bx + MARIO_BIG_BBOX_WIDTH;
		vx = BULLET_SPEED_X;
	}
	else
	{
		x = bx - MARIO_BIG_BBOX_WIDTH;
		vx = -BULLET_SPEED_X;
	}
}
void CBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CBullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	int aniId = 0;
	if (vx > 0)
		aniId = ID_ANI_BULLET_RIGHT;
	else
		aniId = ID_ANI_BULLET_LEFT;
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BULLET_BBOX_WIDTH;
	b = y + BULLET_BBOX_HEIGHT;
}

void CBullet::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (e->obj->IsItem()) return;
	if (e->obj->IsPlatform() || e->obj->IsBlocking() || !e->obj->IsEnemy()) {
		if (e->nx != 0) {
			isDeleted = true;
		}
		else if(e->ny<0){
			vy = -BULLET_JUMP;
		}
		return;
	}

	if (dynamic_cast<CGoomba*>(e->obj)) OnCollisionWithGoomba(e);
	else if (dynamic_cast<CKoopa*>(e->obj)) OnCollisionWithKoopa(e);
	else if (dynamic_cast<CPlantEnemy*>(e->obj)) OnCollisionWithPlantEnemy(e);
}

void CBullet::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	goomba->SetState(GOOMBA_STATE_DIE_UPSIDE);
}

void CBullet::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	koopa->SetState(KOOPA_STATE_DEAD_UPSIDE);
}

void CBullet::OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CPlantEnemy* plant = dynamic_cast<CPlantEnemy*>(e->obj);
	plant->SetState(PLANT_STATE_DEATH);
}
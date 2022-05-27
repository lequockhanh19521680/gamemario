#include "FireFromPlant.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Animation.h"
#include "PlantEnemy.h"
#include "Pipe.h"
#include "Map.h"
CFireFromPlant::CFireFromPlant(float bx, float by, bool Up, bool Right)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (Up)
	{
		y = by - PLANT_BBOX_HEIGHT/2;
		vy = -abs((mario->GetY() - GetY()))/ADJUST_VECTOR_Y * BULLET_SPEED_Y;
	}
	else
	{
		y = by + BULLET_BBOX_HEIGHT - PLANT_BBOX_HEIGHT/2;
		vy = abs((mario->GetY() - GetY())- CHANGE_DIRECTION)/ADJUST_VECTOR_Y * BULLET_SPEED_Y;
	}


	if (Right)
	{
		x = bx + PLANT_BBOX_WIDTH;
		vx = BULLET_SPEED_X;
	}
	else
	{
		x = bx - BULLET_BBOX_WIDTH;
		vx = -BULLET_SPEED_X;
	}
	start_deleted = GetTickCount64();
}
void CFireFromPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - start_deleted > TIME_BULLET_DELETE) {
		isDeleted = true;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CFireFromPlant::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	int aniId = 0;
	if (vx > 0)
		aniId = ID_ANI_BULLET_RIGHT;
	else
		aniId = ID_ANI_BULLET_LEFT;
	animations->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}
void CFireFromPlant::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BULLET_BBOX_WIDTH;
	b = y + BULLET_BBOX_HEIGHT;
}

void CFireFromPlant::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<CPipe*>(e->obj)) return;
	if (e->obj->IsBlocking() && !e->obj->IsPlayer()) {
		isDeleted = true;
	}

}
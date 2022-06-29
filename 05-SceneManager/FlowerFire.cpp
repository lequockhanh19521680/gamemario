#include "FlowerFire.h"
#include "debug.h"
CFlowerFire::CFlowerFire(float x, float y) : CGameObject(x, y) {
	ay = -FL_QUICKLY_Y;
	firstYPosition = y;
}

void CFlowerFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!checkObjectInCamera(this)) return;

	if (firstYPosition - y < FL_BBOX_HEIGHT-1) {
		vy = ay*dt;
	}
	else vy = 0;
	//DebugOut(L"[Debug bong hoa] %f %d %f \n", vy, dt,firstYPosition-y);
	

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFlowerFire::Render()
{
	if (!checkObjectInCamera(this)) return;

	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FLOWER)->Render(x, y);

	//RenderBoundingBox();
}
void CFlowerFire::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};
void CFlowerFire::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FL_BBOX_WIDTH / 2;
	t = y - FL_BBOX_HEIGHT / 2;
	r = l + FL_BBOX_WIDTH;
	b = t + FL_BBOX_HEIGHT;
}
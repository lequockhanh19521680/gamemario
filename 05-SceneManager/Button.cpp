#include "Button.h"
#include "debug.h"
CButton::CButton(float x, float y) : CGameObject(x, y) {
	ay = -BUTTON_QUICKLY_Y;
	firstYPosition = y;
}

void CButton::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if ((firstYPosition - y < BUTTON_BBOX_HEIGHT - 1) && !isCollected) {
		vy = ay * dt;
	}
	else vy = 0;
	if (isCollected) {
		y = firstYPosition - BUTTON_BBOX_HEIGHT / 2 - 2;
	}
	//DebugOut(L"[Debug bong hoa] %f %d %f \n", vy, dt,firstYPosition-y);


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CButton::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	if (!isCollected) aniId = ID_ANI_BUTTON_NOT_COLLECTED;
	else aniId = ID_ANI_BUTTON_COLLECTED;
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CButton::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};
void CButton::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BUTTON_BBOX_WIDTH / 2;
	t = y - BUTTON_BBOX_HEIGHT / 2;
	r = l + BUTTON_BBOX_WIDTH;
	b = t + BUTTON_BBOX_HEIGHT;
}
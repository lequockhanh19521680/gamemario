#include "Hammer.h"

void CHammer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (x > xBlock2) {
		x = xBlock2;
		vx = -vx;
	}
	if (x < xBlock1) {
		x=xBlock1;
		vx = -vx;
	}
	
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CHammer::Render() {

	CAnimations* animations = CAnimations::GetInstance();
	if (vx > 0) animations->Get(ID_ANI_HAMMER_RIGHT)->Render(x, y);
	else animations->Get(ID_ANI_HAMMER_LEFT)->Render(x, y);
	
}
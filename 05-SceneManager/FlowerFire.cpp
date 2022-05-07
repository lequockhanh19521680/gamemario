#include "FlowerFire.h"


void CFlowerFire::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FLOWER)->Render(x, y);

	RenderBoundingBox();
}

void CFlowerFire::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FL_BBOX_WIDTH / 2;
	t = y - FL_BBOX_HEIGHT / 2;
	r = l + FL_BBOX_WIDTH;
	b = t + FL_BBOX_HEIGHT;
}
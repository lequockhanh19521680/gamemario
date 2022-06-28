#include "PlatformIntro.h"


void CPlatformIntro::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_PLATFORM_INTRO)->Render(x, y);
	//animations->Get(ID_ANI_PLATFORM_INTRO)->Render(x + PLATFORM_INTRO_BBOX_WIDTH, y);
	//RenderBoundingBox();
}

void CPlatformIntro::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PLATFORM_INTRO_BBOX_WIDTH / 2;
	t = y - PLATFORM_INTRO_BBOX_HEIGHT / 2;
	r = l + PLATFORM_INTRO_BBOX_WIDTH;
	b = t + PLATFORM_INTRO_BBOX_HEIGHT;
}
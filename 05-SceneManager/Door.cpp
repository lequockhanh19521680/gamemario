#include "Door.h"

void CDoor::Render()
{
	int aniId = -1;
	CAnimations* animations = CAnimations::GetInstance();

	if (model == DOOR_WORLD_1_1) {
		aniId = ID_ANI_DOOR_1;
	}
	else if (model == DOOR_WORLD_1_2) {
		aniId = ID_ANI_DOOR_2;
	}
	else if (model == DOOR_WORLD_1_3) {
		aniId = ID_ANI_DOOR_3;
	}
	else if (model == DOOR_WORLD_1_4)
	{
		aniId = ID_ANI_DOOR_4;
	}
	else if (model == DOOR_WORLD_1_5) {
		aniId = ID_ANI_DOOR_5;
	}
	else if (model == DOOR_WORLD_1_6) {
		aniId = ID_ANI_DOOR_6;
	}
	else if (model == DOOR_WORLD_START) {
		aniId = ID_ANI_DOOR_START;
	}
	animations->Get(aniId)->Render(x, y);

	//RenderBoundingBox();
}

void CDoor::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - DOOR_BBOX_WIDTH / 2;
	t = y - DOOR_BBOX_HEIGHT / 2;
	r = l + DOOR_BBOX_WIDTH;
	b = t + DOOR_BBOX_HEIGHT;
}
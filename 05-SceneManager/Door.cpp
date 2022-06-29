#include "Door.h"
#include "Game.h"
CDoor::CDoor(float x, float y, int model, bool allowLeft, bool allowTop, bool allowRight, bool allowBottom) : CGameObject(x, y) {
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	
	this->model = model;
	if ((model==DOOR_WORLD_START)||(model == DOOR_WORLD_1_1 && data->GetIsPassDoor1()) || (model == DOOR_WORLD_1_2 && data->GetIsPassDoor2()) || (model == DOOR_WORLD_1_3 && data->GetIsPassDoor3()) || (model == DOOR_WORLD_1_4 && data->GetIsPassDoor4()) || (model == DOOR_WORLD_1_5 && data->GetIsPassDoor5()) || (model == DOOR_WORLD_1_6 && data->GetIsPassDoor6())) {
		idScene = 0;
	}
	else { this->idScene = ID_SCENE_WORLD_1_1; }// dat nhu vay la vi chi ton tai world 1-1}
	this->allowLeft = allowLeft;
	this->allowTop = allowTop;
	this->allowRight = allowRight;
	this->allowBottom = allowBottom;
}
void CDoor::Render()
{
	int aniId = ID_ANI_DOOR_START;
	CAnimations* animations = CAnimations::GetInstance();

	if (model == DOOR_WORLD_START) aniId = ID_ANI_DOOR_START;
	else if (idScene) {
		if (model == DOOR_WORLD_1_1) aniId = ID_ANI_DOOR_1;
		else if (model == DOOR_WORLD_1_2) aniId = ID_ANI_DOOR_2;
		else if (model == DOOR_WORLD_1_3) aniId = ID_ANI_DOOR_3;
		else if (model == DOOR_WORLD_1_4) aniId = ID_ANI_DOOR_4;
		else if (model == DOOR_WORLD_1_5) aniId = ID_ANI_DOOR_5;
		else if (model == DOOR_WORLD_1_6) aniId = ID_ANI_DOOR_6;
		else if (model == DOOR_WORLD_START) aniId = ID_ANI_DOOR_START;
	}
	else aniId = ID_ANI_DOOR_PASS;
	
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
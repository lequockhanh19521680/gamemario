#include "PlantEnemy.h"
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
CPlantEnemy::CPlantEnemy(float x, float y, int model) : CGameObject(x,y)
{
	this->model = model;
	startY = y;
	maxY = startY - PLANT_BBOX_HEIGHT;
}

void CPlantEnemy::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	left = x - PLANT_BBOX_WIDTH / 2;
	top = y - PLANT_BBOX_HEIGHT / 2;
	right = left + PLANT_BBOX_WIDTH;
	bottom = top + PLANT_BBOX_HEIGHT;
}
void CPlantEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
int CPlantEnemy::PositionXWithMario() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetX() < GetX()) //mario left, plant right
	{
		return 1;
	}
	else return -1;
}

void CPlantEnemy::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

int CPlantEnemy::PositionYWithMario() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetY() < GetY()) //mario top, plant under
	{
		return 1;
	}
	else return -1;
}

void CPlantEnemy::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	if (model == PLANT_SHOOT) {
		if (PositionXWithMario() == 1 && PositionYWithMario() == -1)
			aniId = ID_ANI_PLANT_LEFT_UNDER_NOT_SHOOT;
		else if (PositionXWithMario() == 1 && PositionYWithMario() == 1)
			aniId = ID_ANI_PLANT_LEFT_TOP_NOT_SHOOT;
		else if (PositionXWithMario() == -1 && PositionYWithMario() == 1)
			aniId = ID_ANI_PLANT_RIGHT_TOP_NOT_SHOOT;
		else {
			aniId = ID_ANI_PLANT_RIGHT_UNDER_NOT_SHOOT;
		}
	

	}
	else {
		aniId = ID_ANI_PLANT_NOT_SHOOT;
	}

	animations->Get(aniId)->Render(x, y);
}

void CPlantEnemy::SetState(int state) {
	switch (state) {
	case PLANT_STATE_UP:
		isUp = true;
		isDown = false;
		break;
	case PLANT_STATE_DOWN:
		isUp = false;
		isDown = true;
		break;
	case PLANT_STATE_DEATH:
		isDeleted = true;
		break;
	}
	CGameObject::SetState(state);
}

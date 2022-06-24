#include "WorldMapPlayer.h"
#include "GameObject.h"
#include "Door.h"
#include "Game.h"
#include "debug.h"
void CWorldMapPlayer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (sceneChange  && isCanGoWorld && CanActive()) {
			CGame::GetInstance()->InitiateSwitchScene(sceneChange);
	}
	//DebugOutTitle(L"vx vy: %f %f", vx, vy);
	DebugOutTitle(L"x y: %f %f", x,y);
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CWorldMapPlayer::Render() {
	int aniId = ID_ANI_MARIO_WORLD_MAP;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
}

void CWorldMapPlayer::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	left = x - MARIO_WORLD_MAP_BBOX_WIDTH / 2; 
	top = y - MARIO_WORLD_MAP_BBOX_WIDTH / 2; 
	right = left + MARIO_WORLD_MAP_BBOX_HEIGHT; 
	bottom = top + MARIO_WORLD_MAP_BBOX_HEIGHT;

}

void CWorldMapPlayer::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CWorldMapPlayer::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (e->obj->IsBlocking()) {
		vx = 0;
		vy = 0;
	}
	if (dynamic_cast<CDoor*>(e->obj))
		OnCollisionWithDoor(e);
}

void CWorldMapPlayer::OnCollisionWithDoor(LPCOLLISIONEVENT e) {
	CDoor* door = dynamic_cast<CDoor*>(e->obj);
	sceneChange = door->GetIdScene();
}

void CWorldMapPlayer::SetState(int state) {
	switch (state) {
	case MARIO_STATE_GO_LEFT:
		vy = 0.0f;
		vx = -SPEED_MARIO;
		break;
	case MARIO_STATE_GO_RIGHT:
		vy = 0.0f;
		vx = SPEED_MARIO;
		break;
	case MARIO_STATE_GO_TOP:
		vy = -SPEED_MARIO;
		vx = 0.0f;
		break;
	case MARIO_STATE_GO_UNDER:
		vy = SPEED_MARIO;
		vx = 0.0f;
		break;
	case MARIO_STATE_GO_WORLD_1:
		isCanGoWorld = true;
		break;
	}
}

#include "WorldMapPlayer.h"
#include "GameObject.h"
void CWorldMapPlayer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

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

}

void CWorldMapPlayer::SetState(int state) {

	CGameObject:SetState(state);
}

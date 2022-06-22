
#include "GameObject.h"
#define MARIO_WORLD_MAP_BBOX_WIDTH 8
#define MARIO_WORLD_MAP_BBOX_HEIGHT 8


#define ID_ANI_MARIO_WORLD_MAP 1661

#define MARIO_STATE_NOT_MOVE 100
#define MARIO_STATE_GO_LEFT 200
#define MARIO_STATE_GO_TOP 300
#define MARIO_STATE_GO_RIGHT 400
#define MARIO_STATE_GO_UNDER 500

#define MARIO_STATE_GO_WORLD_1 600
#pragma once
class CWorldMapPlayer : public CGameObject
{
	bool isCanUseKey = true;
public:
	CWorldMapPlayer(float x, float y) : CGameObject(x, y) {}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsCollidable() { return 1; }
	int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetState(int state);
};
#include "WorldMapPlayer.h"
#include "GameObject.h"
#include "Door.h"
#include "OtherObject.h"
#include "Game.h"
#include "debug.h"
void CWorldMapPlayer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (sceneChange  && isCanGoWorld && CanActive()) {
			CGame::GetInstance()->InitiateSwitchScene(sceneChange);
	}
	if (isGoingNodeX == true) {
		if (vx * (x - startX ) >= 0) {
			x = startX;
			vx = 0;
			vy = 0;
			isGoingNodeX = false;
		}
	}
	/*why    vx* (x - startX)>0. Because more simple this code
	if (isGoingNodeX == true) {
		if (vx > 0) {
			if (x > startX) {
				x = startX;
				vx = 0;
				vy = 0;
				isGoingNodeX = false;
			}
		}
		else if(vx<0){
			if (x<startX) {
				x = startX;
				vx = 0;
				vy = 0;
				isGoingNodeX = false;
			}
		}
	}*/
	if (isGoingNodeY == true) {
		if (vy * (y - startY + 2) >= 0) {
			y = startY;
			vx = 0;
			vy = 0;
			isGoingNodeY = false;
		}
	}
	//DebugOutTitle(L"vx vy: %f %f", vx, vy);
	//DebugOutTitle(L"x y: %f %f", x,y);
	//DebugOutTitle(L"x y startX startY: %f %f %f %f", x,y,startX,startY);
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
	else if (dynamic_cast<COtherObject*>(e->obj))
		OnCollisionWithOtherObject(e);
}

void CWorldMapPlayer::OnCollisionWithOtherObject(LPCOLLISIONEVENT e) {

	COtherObject* object = dynamic_cast<COtherObject*>(e->obj);
	sceneChange = 0;
	isAllowLeft = object->GetAllowLeft();
	isAllowRight = object->GetAllowRight();
	isAllowTop = object->GetAllowTop();
	isAllowBottom = object->GetAllowBottom();
	if (e->nx != 0) {
		Go1NodeX(object);
	}
	if (e->ny != 0) {
		Go1NodeY(object);
	}
}
void CWorldMapPlayer::OnCollisionWithDoor(LPCOLLISIONEVENT e) {
	CDoor* door = dynamic_cast<CDoor*>(e->obj);
	isAllowLeft = door->GetAllowLeft();
	isAllowRight = door->GetAllowRight();
	isAllowTop = door->GetAllowTop();
	isAllowBottom = door->GetAllowBottom();
	sceneChange = door->GetIdScene();
	if (e->nx != 0) {
		Go1NodeX(door);
	}
	if (e->ny != 0) {
		Go1NodeY(door);
	}

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

void CWorldMapPlayer::Go1NodeX(LPGAMEOBJECT gameobject) {
	startX = gameobject->GetX();
	isGoingNodeX = true;
}

void CWorldMapPlayer::Go1NodeY(LPGAMEOBJECT gameobject) {
	startY = gameobject->GetY();
	isGoingNodeY = true;
}
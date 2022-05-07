#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "GameObject.h"


#define KOOPAS_GRAVITY 0.002f
#define KOOPAS_WALKING_SPEED 0.02f
#define KOOPAS_IS_KICKED_SPEED 0.18f
#define KOOPAS_SPEED_Y_IS_FIRE_ATTACKED 0.4f
#define KOOPAS_SPEED_Y_IS_TAIL_ATTACKED 0.4f
#define KOOPAS_SPEED_X_IS_TAIL_ATTACKED 0.05f
#define KOOPAS_RED_WING_SPEED_X 0.03f


#define KOOPAS_WING_GRAVITY 0.0002f
#define KOOPAS_WING_JUMP_SPEED 0.15f
#define KOOPAS_BBOX_WIDTH 16
#define KOOPAS_BBOX_HEIGHT 26
#define KOOPAS_BBOX_HEIGHT_DEFEND 16
#define ADJUST_POSITION_KOOPAS_HELD 13
#define KOOPAS_COMBACK_HEIGHT_ADJUST 0.15f
#define KOOPAS_BOUNCE_SPEED 0.3f

#define KOOPAS_DEFEND_TIMEOUT 8000 // hết thời gian defend ( ra khỏi mai rùa và bắt đầu đi)
#define KOOPAS_COMBACK_START 6000 //thời gian tính từ lúc defend đến lúc có hiệu ứng comeback

#define KOOPAS_STATE_WALKING 100
#define KOOPAS_STATE_DEFEND 200
#define KOOPAS_STATE_IS_KICKED 300
#define KOOPAS_STATE_UPSIDE 400
#define KOOPAS_STATE_JUMP 500

#define ADJUST_X_TO_RED_CHANGE_DIRECTION 10
#define KOOPAS_GREEN 1
#define KOOPAS_RED 2
#define KOOPAS_GREEN_WING 3
#pragma region ANIMATION_ID
// KOOPAS GREEN
#define ID_ANI_KOOPAS_WALKING_RIGHT 6001
#define ID_ANI_KOOPAS_WALKING_LEFT 6002
#define ID_ANI_KOOPAS_DEFEND 6003
#define ID_ANI_KOOPAS_IS_KICKED 6004
#define ID_ANI_KOOPAS_IS_UPSIDE 6005
#define ID_ANI_KOOPAS_COMEBACK 6006
#define ID_ANI_KOOPAS_UPSIDE_ISKICKED 6007	// hiệu ứng bị raccoon tấn công và bị đá
#define ID_ANI_KOOPAS_UPSIDE_COMEBACK 6008 // hiệu ứng bị lật úp sau đó bắt đầu ra khỏi mai rùa
#define ID_ANI_KOOPAS_GREEN_WING_RIGHT 6009
#define ID_ANI_KOOPAS_GREEN_WING_LEFT 6010

// KOOPAS RED
#define ID_ANI_KOOPAS_RED_WALKING_RIGHT 6101
#define ID_ANI_KOOPAS_RED_WALKING_LEFT 6102
#define ID_ANI_KOOPAS_RED_DEFEND 6103
#define ID_ANI_KOOPAS_RED_IS_KICKED 6104
#define ID_ANI_KOOPAS_RED_IS_UPSIDE 6105
#define ID_ANI_KOOPAS_RED_COMEBACK 6106
#define ID_ANI_KOOPAS_RED_UPSIDE_ISKICKED 6107 // hiệu ứng bị raccoon tấn công và bị đá
#define ID_ANI_KOOPAS_RED_UPSIDE_COMEBACK 6108 // hiệu ứng bị lật úp sau đó bắt đầu ra khỏi mai rùa
class CKoopas : public CGameObject
{
protected:
	float ax;
	float ay;


	ULONGLONG defend_start;

	vector<LPGAMEOBJECT> effects;

	int mario_nx;
	BOOLEAN isTailAttacked = false;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable();
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithColorBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithQuestionBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithGoldBrick(LPCOLLISIONEVENT e);

public:
	CKoopas(float x, float y, int model);
	virtual void SetState(int state);

	BOOLEAN isHeld;
	BOOLEAN isDefend;
	BOOLEAN isKicked;
	BOOLEAN isComeback;
	BOOLEAN isUpside;

};

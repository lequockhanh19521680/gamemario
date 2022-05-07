#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f

#define MARIO_GRAVITY			0.002f

#define MARIO_JUMP_DEFLECT_SPEED  0.5f

#define MARIO_STATE_DIE				-10
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	200
#define MARIO_STATE_WALKING_LEFT	100

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	500
#define MARIO_STATE_RUNNING_LEFT	400

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601

#define MARIO_STATE_FALL			700
#define MARIO_STATE_TAIL_ATTACK		800
#pragma region ANIMATION_ID

#define ID_ANI_MARIO_BIG_IDLE_RIGHT 401
#define ID_ANI_MARIO_BIG_IDLE_LEFT 400

#define ID_ANI_MARIO_BIG_WALKING_RIGHT 501
#define ID_ANI_MARIO_BIG_WALKING_LEFT 500

#define ID_ANI_MARIO_BIG_RUNNING_RIGHT 601
#define ID_ANI_MARIO_BIG_RUNNING_LEFT 600

#define ID_ANI_MARIO_BIG_JUMP_WALK_RIGHT 701
#define ID_ANI_MARIO_BIG_JUMP_WALK_LEFT 700

#define ID_ANI_MARIO_BIG_JUMP_RUN_RIGHT 801
#define ID_ANI_MARIO_BIG_JUMP_RUN_LEFT 800

#define ID_ANI_MARIO_BIG_SIT_RIGHT 901
#define ID_ANI_MARIO_BIG_SIT_LEFT 900


#define ID_ANI_MARIO_BIG_BRACE_RIGHT 1001
#define ID_ANI_MARIO_BIG_BRACE_LEFT 1000

#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1102
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1100

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1201
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1200

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1301
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1300

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1401
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1400

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1501
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1500

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1601
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1600

//
//
//
//
//

#define ID_ANI_MARIO_FIRE_IDLE_RIGHT 1701
#define ID_ANI_MARIO_FIRE_IDLE_LEFT 1700

#define ID_ANI_MARIO_FIRE_WALKING_RIGHT 1801
#define ID_ANI_MARIO_FIRE_WALKING_LEFT 1800

#define ID_ANI_MARIO_FIRE_RUNNING_RIGHT 1901
#define ID_ANI_MARIO_FIRE_RUNNING_LEFT 1900

#define ID_ANI_MARIO_FIRE_JUMP_WALK_RIGHT 2001
#define ID_ANI_MARIO_FIRE_JUMP_WALK_LEFT 2000

#define ID_ANI_MARIO_FIRE_JUMP_RUN_RIGHT 2101
#define ID_ANI_MARIO_FIRE_JUMP_RUN_LEFT 2100

#define ID_ANI_MARIO_FIRE_SIT_RIGHT 2201
#define ID_ANI_MARIO_FIRE_SIT_LEFT 2200

#define ID_ANI_MARIO_FIRE_BRACE_RIGHT 2301
#define ID_ANI_MARIO_FIRE_BRACE_LEFT 2300
//
//
//
//

#define ID_ANI_MARIO_TAIL_IDLE_RIGHT 2401
#define ID_ANI_MARIO_TAIL_IDLE_LEFT 2400

#define ID_ANI_MARIO_TAIL_WALKING_RIGHT 2501
#define ID_ANI_MARIO_TAIL_WALKING_LEFT 2500

#define ID_ANI_MARIO_TAIL_RUNNING_RIGHT 2601
#define ID_ANI_MARIO_TAIL_RUNNING_LEFT 2600

#define ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT 2701
#define ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT 2700

#define ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT 2801
#define ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT 2800

#define ID_ANI_MARIO_TAIL_SIT_RIGHT 2901
#define ID_ANI_MARIO_TAIL_SIT_LEFT 2900

#define ID_ANI_MARIO_TAIL_BRACE_RIGHT 3001
#define ID_ANI_MARIO_TAIL_BRACE_LEFT 3000

#define ID_ANI_MARIO_TAIL_ATTACK 3100



#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define MARIO_LEVEL_FIRE    3
#define MARIO_LEVEL_TAIL	4

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12


#define MARIO_UNTOUCHABLE_TIME 2500

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 
	int acceleration;
	int level; 
	int untouchable; 
	ULONGLONG untouchable_start;
	BOOLEAN isOnPlatform;
	int coin; 

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);

	int GetAniIdBig();
	int GetAniIdSmall();
	int GetAniIdFire();
	int GetAniIdTail();

public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY; 

		level = MARIO_LEVEL_SMALL;
		untouchable = 0;
		untouchable_start = -1;
		isOnPlatform = false;
		coin = 0;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);
	int GetLevel() { return level; }
	int IsCollidable()
	{ 
		return (state != MARIO_STATE_DIE); 
	}
	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable==0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetLevel(int l);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
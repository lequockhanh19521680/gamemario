#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.15f


#define MARIO_SPEED_USE_PIPE 0.02f
#define SPEED_MARIO_WHEN_BLOCK 0.007f
#define MARIO_ACCEL_WALK_X	0.00014f
#define MARIO_ACCEL_RUN_X	0.0002f

#define MARIO_JUMP_SPEED_Y		0.2f
#define MARIO_JUMP_RUN_SPEED_Y	0.2f

#define SPEED_LEVEL_RUN 0.015f


#define MARIO_GRAVITY 0.0003f

#define MARIO_JUMP_DEFLECT_SPEED  0.1f
#define MARIO_JUMP_DEFLECT_SPEED_DIE  0.2f

#define MARIO_FLY_FALL 0.0f
#define MARIO_FLYING 0.2f


#define LEVEL_RUN_MAX 7
#define TIME_FLY 3000
#define TIME_TAIL_ATTACK 400
#define TIME_PREPARE_RUN 700
#define TIME_SPEED 150
#define TIME_KICK_ANIMATION 100
#define TIME_SHOOT_ANI 100
#define TIME_SHOOT_LIMIT 200

#define POSITION_X_HIDDEN_MAP 3340
#define POSITION_Y_HIDDEN_MAP 0
#define POSITION_X_OUT_HIDDEN_MAP 2325
#define POSITION_Y_OUT_HIDDEN_MAP 366

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

#define MARIO_STATE_SHOOT	900
#define MARIO_STATE_FLY	1000

#define MARIO_STATE_DOWNING_PIPE 1100
#define MARIO_STATE_UPPING_PIPE 1200

#define MARIO_STATE_END_SCENE 1300
#pragma region ANIMATION_ID

#define ID_ANI_MARIO_BIG_IDLE_RIGHT 401
#define ID_ANI_MARIO_BIG_IDLE_LEFT 400

#define ID_ANI_MARIO_BIG_WALKING_RIGHT 501
#define ID_ANI_MARIO_BIG_WALKING_LEFT 500

#define ID_ANI_MARIO_BIG_RUNNING_RIGHT 601
#define ID_ANI_MARIO_BIG_RUNNING_LEFT 600

#define ID_ANI_MARIO_BIG_RUNNING_PREPARE_RIGHT 603
#define ID_ANI_MARIO_BIG_RUNNING_PREPARE_LEFT 602

#define ID_ANI_MARIO_BIG_JUMP_WALK_RIGHT 701
#define ID_ANI_MARIO_BIG_JUMP_WALK_LEFT 700

#define ID_ANI_MARIO_BIG_JUMP_RUN_RIGHT 801
#define ID_ANI_MARIO_BIG_JUMP_RUN_LEFT 800

#define ID_ANI_MARIO_BIG_SIT_RIGHT 901
#define ID_ANI_MARIO_BIG_SIT_LEFT 900


#define ID_ANI_MARIO_BIG_BRACE_RIGHT 1001
#define ID_ANI_MARIO_BIG_BRACE_LEFT 1000

#define ID_ANI_MARIO_BIG_HOLD_RUNNING_RIGHT 1011
#define ID_ANI_MARIO_BIG_HOLD_RUNNING_LEFT 1010

#define ID_ANI_MARIO_BIG_KICK_RIGHT 1021
#define ID_ANI_MARIO_BIG_KICK_LEFT 1020

#define ID_ANI_MARIO_BIG_HOLD_IDLE_RIGHT 1041
#define ID_ANI_MARIO_BIG_HOLD_IDLE_LEFT 1040

#define ID_ANI_MARIO_BIG_HOLD_JUMP_RIGHT 1051
#define ID_ANI_MARIO_BIG_HOLD_JUMP_LEFT 1050

#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1102
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1100

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1201
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1200

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1301
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1300

#define ID_ANI_MARIO_SMALL_RUNNING_PREPARE_RIGHT 1303
#define ID_ANI_MARIO_SMALL_RUNNING_PREPARE_LEFT 1302

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1401
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1400

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1501
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1500

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1601
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1600

#define ID_ANI_MARIO_SMALL_HOLD_RUNNING_RIGHT 1611
#define ID_ANI_MARIO_SMALL_HOLD_RUNNING_LEFT 1610

#define ID_ANI_MARIO_SMALL_KICK_RIGHT 1621
#define ID_ANI_MARIO_SMALL_KICK_LEFT  1620

#define ID_ANI_MARIO_SMALL_HOLD_IDLE_RIGHT 1641
#define ID_ANI_MARIO_SMALL_HOLD_IDLE_LEFT 1640

#define ID_ANI_MARIO_SMALL_HOLD_JUMP_RIGHT 1651
#define ID_ANI_MARIO_SMALL_HOLD_JUMP_LEFT 1650

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

#define ID_ANI_MARIO_FIRE_RUNNING_PREPARE_RIGHT 1903
#define ID_ANI_MARIO_FIRE_RUNNING_PREPARE_LEFT 1902

#define ID_ANI_MARIO_FIRE_JUMP_WALK_RIGHT 2001
#define ID_ANI_MARIO_FIRE_JUMP_WALK_LEFT 2000

#define ID_ANI_MARIO_FIRE_JUMP_RUN_RIGHT 2101
#define ID_ANI_MARIO_FIRE_JUMP_RUN_LEFT 2100

#define ID_ANI_MARIO_FIRE_SIT_RIGHT 2201
#define ID_ANI_MARIO_FIRE_SIT_LEFT 2200

#define ID_ANI_MARIO_FIRE_BRACE_RIGHT 2301
#define ID_ANI_MARIO_FIRE_BRACE_LEFT 2300

#define ID_ANI_MARIO_FIRE_HOLD_RUNNING_RIGHT 2311
#define ID_ANI_MARIO_FIRE_HOLD_RUNNING_LEFT 2310

#define ID_ANI_MARIO_FIRE_KICK_RIGHT 2321
#define ID_ANI_MARIO_FIRE_KICK_LEFT 2320

#define ID_ANI_MARIO_FIRE_HOLD_IDLE_RIGHT 2341
#define ID_ANI_MARIO_FIRE_HOLD_IDLE_LEFT 2340

#define ID_ANI_MARIO_FIRE_HOLD_JUMP_RIGHT 2351
#define ID_ANI_MARIO_FIRE_HOLD_JUMP_LEFT 2350


#define ID_ANI_MARIO_FIRE_SHOOT_RIGHT 2331
#define ID_ANI_MARIO_FIRE_SHOOT_LEFT 2330
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

#define ID_ANI_MARIO_TAIL_RUNNING_PREPARE_RIGHT 2603
#define ID_ANI_MARIO_TAIL_RUNNING_PREPARE_LEFT 2602

#define ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT 2701
#define ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT 2700

#define ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT 2801
#define ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT 2800

#define ID_ANI_MARIO_TAIL_SIT_RIGHT 2901
#define ID_ANI_MARIO_TAIL_SIT_LEFT 2900

#define ID_ANI_MARIO_TAIL_BRACE_RIGHT 3001
#define ID_ANI_MARIO_TAIL_BRACE_LEFT 3000

#define ID_ANI_MARIO_TAIL_HOLD_RUNNING_RIGHT 3011
#define ID_ANI_MARIO_TAIL_HOLD_RUNNING_LEFT 3010

#define ID_ANI_MARIO_TAIL_KICK_RIGHT 3021
#define ID_ANI_MARIO_TAIL_KICK_LEFT 3020

#define ID_ANI_MARIO_TAIL_ATTACK 3100

#define ID_ANI_MARIO_FLY_RIGHT 3300
#define ID_ANI_MARIO_FLY_LEFT 3200

#define ID_ANI_MARIO_TAIL_HOLD_IDLE_RIGHT 3041
#define ID_ANI_MARIO_TAIL_HOLD_IDLE_LEFT 3040

#define ID_ANI_MARIO_TAIL_HOLD_JUMP_RIGHT 3051
#define ID_ANI_MARIO_TAIL_HOLD_JUMP_LEFT 3050

#define ID_ANI_MARIO_TAIL_FLY_DOWN_RIGHT 3061
#define ID_ANI_MARIO_TAIL_FLY_DOWN_LEFT 3060

#define ID_ANI_MARIO_TAIL_USE_PIPE 3411

#define ID_ANI_MARIO_CHANGE_SMALL_TO_BIG_RIGHT 3401
#define ID_ANI_MARIO_CHANGE_SMALL_TO_BIG_LEFT 3400
#define ID_ANI_MARIO_CHANGE_BIG_TO_BIGGER 3402


#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define MARIO_LEVEL_FIRE    3
#define MARIO_LEVEL_TAIL	4

#define MARIO_BIG_BBOX_WIDTH  16
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  16
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  16
#define MARIO_SMALL_BBOX_HEIGHT 12

#define POSITION_Y_DIE 440
#define TIME_CHANGING 900
#define MARIO_UNTOUCHABLE_TIME (TIME_CHANGING + 2500)
#define TIME_ONE_SECOND 1000
#define TIME_CLOCK_VERY_FAST 10
#define TIME_SCORE_UP_MAX 1000
#define TIME_MAX_HOLDING 6000
#define TIME_CHANGE_SCENE 4000
#define TIME_ADD_EFFECT 400
#define POSITION_MAX_END_SCENE 2830


#define MARIO_WORLD_MAP_SCENE 1
class CMario : public CGameObject
{
	int testDebug = 0;
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 
	int level; 
	int untouchable; 
	int clock;
	int levelRun;
	int score;
	int Up;
	int scoreUpCollision;
	//danh cho downing va upping pipe
	float startUsePiPeY;
	bool isDowned;
	bool isUpped;
	bool isPrepareEndScene;

	ULONGLONG start_add_effect;
	ULONGLONG start_score_up;
	ULONGLONG untouchable_start;
	ULONGLONG start_limit_shoot;
	ULONGLONG start_fly;
	ULONGLONG start_prepare;
	ULONGLONG start_kick;
	ULONGLONG start_shoot;
	ULONGLONG speed_start;
	ULONGLONG speed_stop;
	ULONGLONG start_tail_attack;
	ULONGLONG start_changing;
	ULONGLONG time_down_1_second;
	ULONGLONG start_holding;
	ULONGLONG start_change_scene_die;
	ULONGLONG start_change_scene_clock;
	BOOLEAN isOnPlatform;
	int coin; 

	bool isChanging;
	bool isRunning;
	bool isHolding;
	bool isFlying;
	bool isKicking;
	bool isShoot;
	bool isTailAttack;
	bool isLower;
	bool isUsePipe;
	bool isPrepareUp = false;
	bool isNotMove = false;
	bool isEndScene = false;
	bool isWillAddEffect = false;
	bool isClockVeryFast ;
	int card1;
	int card2;
	int card3;
	int cardCollected;

	void BlockIfNoBlock(LPGAMEOBJECT gameobject);
	int GetAniIdBig();
	int GetAniIdSmall();
	int GetAniIdFire();
	int GetAniIdTail();

	virtual int IsPlayer() { return 1; }
	int IsCollidable(){ return (state != MARIO_STATE_DIE); }
	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable == 0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);
	void OnCollisionWithMushRoom(LPCOLLISIONEVENT e);
	void OnCollisionWithLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithFlowerFire(LPCOLLISIONEVENT e);
	void OnCollisionWithBrickQuestion(LPCOLLISIONEVENT e);
	void OnCollisionWithBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithPlatForm(LPCOLLISIONEVENT e);
	void OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e);
	void OnCollisionWithFireFromPlant(LPCOLLISIONEVENT e);
	void OnCollisionWithCard(LPCOLLISIONEVENT e);


	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

public:
	CMario(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();



	//get
	int GetScoreCollision() { return scoreUpCollision; }
	int GetScore() { return score; }
	int GetLevel() { return level; }
	int GetCoin() { return this->coin; }
	int GetUp() { return Up; }
	int GetClock() { return clock; }
	int GetLevelRun() { return levelRun; }
	int GetCard1() { return card1; }
	int GetCard2() { return card2; }
	int GetCard3() { return card3; }
	int GetCardCollected() { return cardCollected; }
	bool GetIsPrepareEndScene() { return isPrepareEndScene; }
	bool IsEndScene() { return isEndScene; }
	bool IsNotMove() { return isNotMove; }

	bool GetIsPrepareUp() { return isPrepareUp; }
	bool GetIsTailAttack() { return isTailAttack; }
	bool GetIsFlying() { return isFlying; }
	bool GetIsHolding() { return isHolding; }
	bool GetIsKicking() { return isKicking; }
	bool GetIsOnPlatform() { return isOnPlatform; }
	bool GetIsRunning() { return isRunning; }
	bool GetIsShoot() { return isShoot; }
	bool IsBrace() { return (ax * vx < 0); }
	bool GetIsChanging() { return isChanging; }
	//set
	void SetScoreCollision(int l) { scoreUpCollision = l; }
	void SetState(int state);
	void SetIsHolding(bool b) { isHolding = b; }
	void SetIsKicking(bool b) { isKicking = b; }
	void SetIsRunning(bool b) { isRunning = b; }
	void SetIsPrepareUp(bool b) { isPrepareUp = b; }
	void SetCoin(int coin) { this->coin = coin; }
	void SetLevel(int l);
	void SetVy(float v) { vy = v; }
	void SetScore(int l) { score = l; }
	//void phat sinh
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }
	void SetFly();
	void SetMarioTailAttack();
	void SetLevelLower();
	void AddChangeAnimation();
	void AddEffectAttack(float xTemp,float yTemp);
	void AddScore(float xTemp, float yTemp, int scoreAdd);
	void IncreaseScoreUpCollision(float xTemp,float yTemp);
	void TeleportToHiddenMap() {
		SetPosition(POSITION_X_HIDDEN_MAP,POSITION_Y_HIDDEN_MAP);
	}
	void ReturnWorldFromHiddenMap() {
		SetPosition(POSITION_X_OUT_HIDDEN_MAP,POSITION_Y_OUT_HIDDEN_MAP);
	}
};
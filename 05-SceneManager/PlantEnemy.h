#pragma once
#include "GameObject.h"

#define PLANT_SPEED_UP_DOWN 0.025f

#define TIME_OUT_PIPE 5000
#define TIME_SHOOT 100
#define TIME_DOWN_PIPE 3000

#define PLANT_SHOOT 1
#define PLANT_NOT_SHOOT 2

#define PLANT_BBOX_WIDTH 16
#define PLANT_BBOX_HEIGHT 32

#define PLANT_STATE_UP 100
#define PLANT_STATE_DOWN 200
#define PLANT_STATE_DEATH 300

#define ID_ANI_PLANT_LEFT_UNDER_NOT_SHOOT	301
#define ID_ANI_PLANT_LEFT_UNDER_SHOOT 302
#define ID_ANI_PLANT_LEFT_TOP_NOT_SHOOT 303
#define ID_ANI_PLANT_LEFT_TOP_SHOOT 304
#define ID_ANI_PLANT_RIGHT_UNDER_NOT_SHOOT	305
#define ID_ANI_PLANT_RIGHT_UNDER_SHOOT 306
#define ID_ANI_PLANT_RIGHT_TOP_NOT_SHOOT 307
#define ID_ANI_PLANT_RIGHT_TOP_SHOOT 308

#define ID_ANI_PLANT_NOT_SHOOT 311
class CPlantEnemy :	public CGameObject
{
protected:
	float startY;
	float minY;
	bool isShoot = false;
	bool isUpping, isDowning;
	ULONGLONG time_out_pipe;
	ULONGLONG time_shoot;
	ULONGLONG time_down_pipe;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	int PositionYWithMario(); //1 if mario on top plant, -1 if mario underplant
	int PositionXWithMario(); //1 if mario left to plant, -1 if mario right to plant

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual int IsEnemy() { return 1; }

	virtual void OnNoCollision(DWORD dt);

public:

	CPlantEnemy(float x, float y, int model);
	virtual void SetState(int state);
};


#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "Font.h"
#include "Power.h"

#define ID_ANI_HUD 300
#define NUMBER_SCORE 7
#define NUMBER_TIME 3
#define NUMBER_WORLD 1
#define NUMBER_COIN 1
#define NUMBER_HEALTH 1

#define ADJUST_X_POWER 62
#define ADJUST_Y_POWER 3

#define ADJUST_X_COIN 20
#define ADJUST_Y_COIN 4

#define ADJUST_X_HEALTH 86
#define ADJUST_Y_HEALTH 5

#define ADJUST_X_WORLD 76
#define ADJUST_Y_WORLD 4

#define ADJUST_X_TIME 12
#define ADJUST_Y_TIME 5

#define ADJUST_X_SCORE 62
#define ADJUST_Y_SCORE 5
class CHUD
{
	float x, y;
	ULONGLONG now_time;
	int time;
	CFont font;
	CPower* power;
public:
	CHUD(float x, float y);
	void Render(CMario* mario, int remainingTime);
	string FillNumber(string s, UINT fillNumber);
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
	~CHUD() {}
};



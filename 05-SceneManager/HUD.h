#pragma once
#include "HUD.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Mario.h"

#define FONT_BBOX_WIDTH	8
#define DEFAULT_TIME	300
#define ID_ANI_HUD 30000
#define ID_ANI_POWER_HUD 30002
#define ID_ANI_POWER_HUD_MAX 30003


#define ID_ANI_BLACK_RECTANGEL 30001
#define ADJUST_HUD_X_POSITION 128
#define ADJUST_HUD_Y_POSITION 196
#define ADJUST_X_POWER_POSITION 60
#define ADJUST_X_POWER_POSITION_MAX 8

#define DISTANCE_EVERY_LEVEL_RUN 8
#define ADJUST_Y_POWER_POSITION 3


class CHUD 
{
private:
	float x, y;


public:
	CHUD(float x, float y);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom){}
};
#pragma once
#include "HUD.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Mario.h"

#define FONT_BBOX_WIDTH	8
#define DEFAULT_TIME	300
#define SPRITE_HUD_ID	11700

class CHUD : public CGameObject
{
protected:

public:
	CHUD(float x, float y) : CGameObject(x, y){}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom){}
};
#pragma once
#include "GameObject.h"

#define MUSHROOM_WORLD_MAP 1
#define CARD_WORLD_MAP 2
#define NODE_WORLD_MAP 3

#define OBJECT_BBOX_WIDTH	16
#define OBJECT_BBOX_HEIGHT	16

#define ID_ANI_CARD 25002

class COtherObject :public CGameObject
{
private:
	int model;
	bool allowLeft;
	bool allowTop;
	bool allowRight;
	bool allowBottom;
public:
	COtherObject(float x, float y, int model,bool allowLeft, bool allowTop, bool allowRight, bool allowBottom) : CGameObject(x, y) {
		this->model = model;
		this->allowLeft = allowLeft;
		this->allowTop = allowTop;
		this->allowRight = allowRight;
		this->allowBottom = allowBottom;
	}
	void Render();
	void Update(DWORD dt) {}
	virtual int IsBlocking() { return 0; }
	bool GetAllowLeft() { return allowLeft; }
	bool GetAllowTop() { return allowTop; }
	bool GetAllowRight() { return allowRight; }
	bool GetAllowBottom() { return allowBottom; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};



#pragma once
#include "GameObject.h"

#define MUSHROOM_WORLD_MAP 1
#define CARD_WORLD_MAP 2
#define NODE_WORLD_MAP 3

#define OBJECT_BBOX_WIDTH	16
#define OBJECT_BBOX_HEIGHT	16
class COtherObject :public CGameObject
{
private:
	int model;
public:
	COtherObject(float x, float y, int model) : CGameObject(x, y) {
		this->model = model;
	}
	void Render();
	void Update(DWORD dt) {}
	virtual int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};



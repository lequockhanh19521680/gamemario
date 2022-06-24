#pragma once
#include "GameObject.h"

#define MUSHROOM_WORLD_MAP 1

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



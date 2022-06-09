#pragma once
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BRICK_COLOR 10001
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

#define BRICK_IS_COIN 1
#define BRICK_IS_NOT_COIN 2

#include "GameObject.h"
class CBrickColor :    public CGameObject
{
protected:
	int model;
public:
	CBrickColor(float x, float y, int model) : CGameObject(x, y) { this->model = model; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};


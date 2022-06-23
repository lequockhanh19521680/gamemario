#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_GRASS 25001
#define GRASS_BBOX_WIDTH 16
#define GRASS_BBOX_HEIGHT 16



class CGrass :
    public CGameObject
{
public:
	CGrass(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};


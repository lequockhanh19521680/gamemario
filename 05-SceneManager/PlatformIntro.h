#pragma once
#include "GameObject.h"
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PLATFORM_INTRO 25500
#define PLATFORM_INTRO_BBOX_WIDTH 400
#define PLATFORM_INTRO_BBOX_HEIGHT 16



class CPlatformIntro :public CGameObject
{
public:
	CPlatformIntro(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 0; };
};



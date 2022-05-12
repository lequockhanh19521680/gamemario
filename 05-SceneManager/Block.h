#pragma once
#include "GameObject.h"

#define BLOCK_BBOX_WIDTH 16
#define BLOCK_BBOX_HEIGHT 16


class CBlock :	public CGameObject
{
	float left, top, right, bottom;
public:
	CBlock(float x, float y) : CGameObject(x, y) {}
	CBlock(float l, float t, float r, float b) { 
		left = l; 
		top = t; 
		right = r; 
		bottom = b; 
	}

	
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { return !(bottom - top == 1); }

	void GetBoundingBox(float& l, float& t, float& r, float& b);
};


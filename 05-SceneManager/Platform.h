#pragma once

#include "GameObject.h"

#define HEIGHT_CAN_DOWN 15.9f
#define HEIGHT_CAN_DOWN_BLOCK 15.8f
#define SPRITE_NULL 2
// 
// The most popular type of object in Mario! 
// 
class CPlatform : public CGameObject
{
protected: 
	int length;				// Unit: cell 
	float cellWidth;
	float cellHeight;
	int spriteIdBegin, spriteIdMiddle, spriteIdEnd;

	virtual bool IsPlatform() { return 1; }

public: 
	CPlatform(float x, float y,
		float cell_width, float cell_height, int length,
		int sprite_id_begin, int sprite_id_middle, int sprite_id_end) :CGameObject(x, y)
	{
		this->length = length;
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
		this->spriteIdBegin = sprite_id_begin;
		this->spriteIdMiddle = sprite_id_middle;
		this->spriteIdEnd = sprite_id_end;
	}
	CPlatform(float x, float y, float cell_width, float cell_height, int length) :CGameObject(x, y) {
		this->length = length;
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
		this->spriteIdBegin = SPRITE_NULL;
		this->spriteIdMiddle = SPRITE_NULL;
		this->spriteIdEnd = SPRITE_NULL;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void OnNoCollision(LPCOLLISIONEVENT e) {};

	void RenderBoundingBox();
	int GetLength() { return length; }
	virtual int IsCollidable() { return 0; }
	bool isCanNotBlockKoopa() { return (cellHeight == HEIGHT_CAN_DOWN_BLOCK); }
	bool IsCanDown() { return (cellHeight == HEIGHT_CAN_DOWN); }
	virtual int IsBlocking() { return (cellHeight==16); }//(cellHeight==16); }
};

typedef CPlatform* LPPLATFORM;
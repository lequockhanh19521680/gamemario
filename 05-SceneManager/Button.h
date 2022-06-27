#pragma once
#include "GameObject.h"

#define ID_ANI_BUTTON_NOT_COLLECTED 13131
#define ID_ANI_BUTTON_COLLECTED 13132
#define BUTTON_BBOX_WIDTH 10
#define BUTTON_BBOX_HEIGHT 16
#define BUTTON_QUICKLY_Y 0.0003f;
class CButton : public CGameObject
{
	float ay;
	float firstYPosition;
	bool isCollected = false;
public:
	CButton(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsCollidable() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual int IsBlocking() { return 0; }
	virtual bool IsItem() { return 1; }
	virtual bool IsButton() { return 1; }
	bool GetIsCollected() { return isCollected; }
	
	void SetIsCollected(bool b) { isCollected = b; }

};





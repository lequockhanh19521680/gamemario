#pragma once
#include "GameObject.h"

#define SPEED_CARD 0.07f

#define CARD_BBOX_HEIGHT 16
#define CARD_BBOX_WIDTH 16


#define ID_ANI_CARD_MUSHROOM 24781
#define ID_ANI_CARD_FLOWER 24786
#define ID_ANI_CARD_STAR 24791

#define TIME_CHANGE_CARD 150
#define CARD_MUSHROOM 1
#define CARD_FLOWER 2
#define CARD_STAR 3

#define CARD_STATE_COLLECTED 100
class CCard : public CGameObject
{
	int card;
	bool isCollected;
	ULONGLONG start_change;
public:
	CCard(float x, float y) : CGameObject(x, y) {
		card = CARD_MUSHROOM;
		isCollected = false;
		start_change = GetTickCount64();
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 1; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	int GetCard() { return card; }
	void SetCard(int card) { this->card = card; }
	bool GetCollected(){ return isCollected; }
	void SetState(int state);
};


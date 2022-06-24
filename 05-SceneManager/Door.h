#pragma once
#include "GameObject.h"

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Game.h"
#include "PlayScene.h"

#define ID_ANI_DOOR_START 25010
#define ID_ANI_DOOR_1 25011
#define ID_ANI_DOOR_2 25012
#define ID_ANI_DOOR_3 25013
#define ID_ANI_DOOR_4 25014
#define ID_ANI_DOOR_5 25015
#define ID_ANI_DOOR_6 25016
#define DOOR_BBOX_WIDTH 16
#define DOOR_BBOX_HEIGHT 16

#define DOOR_WORLD_START 1
#define DOOR_WORLD_1_1 2
#define DOOR_WORLD_1_2 3
#define DOOR_WORLD_1_3 4
#define DOOR_WORLD_1_4 5
#define DOOR_WORLD_1_5 6
#define DOOR_WORLD_1_6 7


class CDoor :
	public CGameObject
{
private:
	int model;
	int idScene;
public:
	CDoor(float x, float y,int model) : CGameObject(x, y) {
		this->model = model;
		this->idScene = DOOR_WORLD_1_1;// dat nhu vay la vi chi ton tai world 1-1
	}
	void Render();
	void Update(DWORD dt) {}
	virtual int IsBlocking() { return 0; }
	int GetIdScene() { return idScene; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};




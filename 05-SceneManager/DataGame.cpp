#include "DataGame.h"
#include "Mario.h"
#include"Door.h"
CDataGame::CDataGame() {
	ResetFullData();
}

void CDataGame::SavePositionXWorldMap(float f) {position_x_world_map = f;}
void CDataGame::SavePositionYWorldMap(float f) {position_y_world_map = f;}
void CDataGame::SaveLevel(int l) {level = l;}
void CDataGame::SaveScore(int s) {score = s;}
void CDataGame::SaveCoin(int c) {coin = c;}
void CDataGame::SaveUp(int u) {Up = u;}
void CDataGame::SaveCard1(int c1) { card1 = c1; }
void CDataGame::SaveCard2(int c2) { card2 = c2; }
void CDataGame::SaveCard3(int c3) { card3 = c3; }
void CDataGame::SaveDoorProcess(int n) { saveDoorProcess = n; }
void CDataGame::SetIsDisplayHUD(bool b) {
	isDisplayHUD = b;
}


void CDataGame::SavePassDoor(bool door1, bool door2, bool door3, bool door4, bool door5, bool door6) {
	if(!isPassDoor1) isPassDoor1 = door1;
	if(!isPassDoor2) isPassDoor2 = door2;
	if(!isPassDoor3) isPassDoor3 = door3;
	if(!isPassDoor4) isPassDoor4 = door4;
	if(!isPassDoor5) isPassDoor5 = door5;
	if(!isPassDoor6) isPassDoor6 = door6;
}

void CDataGame::SaveAllowKey(bool isAllowLeft, bool isAllowTop, bool isAllowRight, bool isAllowBottom) {
	this->isAllowLeft = isAllowLeft;
	this->isAllowTop = isAllowTop;
	this->isAllowRight = isAllowRight;
	this->isAllowBottom = isAllowBottom;
}
void CDataGame::ResetFullData() {
	Up = 4;
	score = 0;
	position_x_world_map = MARIO_START_WORLD_MAP_X;
	position_y_world_map = MARIO_START_WORLD_MAP_Y;
	level = MARIO_LEVEL_SMALL;
	coin = 0;
	card1 = 0;
	card2 = 0;
	card3 = 0;

	saveDoorProcess = 0;
	isAllowLeft = true;
	isAllowRight = true;
	isAllowBottom = false;
	isAllowTop = false;

	isDisplayHUD = true;

	isPassDoor1 = false;
	isPassDoor2 = false;
	isPassDoor3 = false;
	isPassDoor4 = false;
	isPassDoor5 = false;
	isPassDoor6 = false;
}

void CDataGame::SavePassDoorEasier(int i) {
	switch (i) {
	case DOOR_WORLD_1_1: SavePassDoor(true, false, false, false, false, false); break;
	case DOOR_WORLD_1_2: SavePassDoor(false, true, false, false, false, false); break;
	case DOOR_WORLD_1_3: SavePassDoor(false, false, true, false, false, false); break;
	case DOOR_WORLD_1_4: SavePassDoor(false, false, false, true, false, false); break;
	case DOOR_WORLD_1_5: SavePassDoor(false, false, false, false, true, false);  break;
	case DOOR_WORLD_1_6: SavePassDoor(false, false, false, false, false, true);  break;
	}
}

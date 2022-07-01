#pragma once

#define MARIO_START_WORLD_MAP_X 32
#define MARIO_START_WORLD_MAP_Y 48
class CDataGame
{
private:
	//world map
	float position_x_world_map;
	float position_y_world_map;
	bool isAllowLeft;
	bool isAllowRight;
	bool isAllowTop;
	bool isAllowBottom;

	bool isPassDoor1;
	bool isPassDoor2;
	bool isPassDoor3;
	bool isPassDoor4;
	bool isPassDoor5;
	bool isPassDoor6;

	int saveDoorProcess;

	bool isDisplayHUD;

	bool isGameOver;
	bool prepareContinue;
	bool prepareEnd;

	bool isContinue;
	bool isEnd;



	//playscene
	int level;
	int score;
	int Up;
	int coin;
	int card1;
	int card2;
	int card3;
public:
	CDataGame();
	void SavePositionXWorldMap(float f);
	void SavePositionYWorldMap(float f);
	void SaveLevel(int l);
	void SaveScore(int s);
	void SaveCoin(int c);
	void SaveUp(int u);
	void SaveCard1(int c1);
	void SaveCard2(int c2);
	void SaveCard3(int c3);
	void SavePassDoor(bool door1, bool door2, bool door3, bool door4, bool door5, bool door6);
	void SavePassDoorEasier(int i);
	void SetIsDisplayHUD(bool b);
	void SaveDoorProcess(int n);
	void SettingGameOver() { isGameOver = true; }
	void SettingCountinue() { isContinue = true; }
	void SettingEnd() { isEnd = true; }
	void SetPrepareContinue(bool b);
	void SetPrepareEnd(bool b);
	void SaveAllowKey(bool isAllowLeft, bool isAllowRight, bool isAllowTop, bool isAllowBottom);
	
	float GetPositionXWorldMap() { return position_x_world_map; }
	float GetPositionYWorldMap() { return position_y_world_map; }

	int GetCard1() { return card1; }
	int GetCard2() { return card2; }
	int GetCard3() { return card3; }

	int GetLevel() { return level; }
	int GetScore() { return score; }
	int GetUp() { return Up; }
	int GetCoin() { return coin; }
	int GetDoorProcess() { return saveDoorProcess; }

	bool GetAllowKeyLeft() { return isAllowLeft; }
	bool GetAllowKeyTop() { return isAllowTop; }
	bool GetAllowKeyBottom() { return isAllowBottom; }
	bool GetAllowKeyRight() { return isAllowRight; }

	bool GetIsPassDoor1() { return isPassDoor1; }
	bool GetIsPassDoor2() { return isPassDoor2; }
	bool GetIsPassDoor3() { return isPassDoor3; }
	bool GetIsPassDoor4() { return isPassDoor4; }
	bool GetIsPassDoor5() { return isPassDoor5; }
	bool GetIsPassDoor6() { return isPassDoor6; }

	bool GetIsPrepareContinue() { return prepareContinue; }
	bool GetIsPrepareEnd() { return prepareEnd; }
	bool GetIsOver() { return isGameOver; }
	bool GetIsEnd() { return isEnd; }
	bool GetIsContinue() { return isContinue; }

	

	bool GetIsDisplayHUD() { return isDisplayHUD; }



	void ResetFullData();
	void ChangeBetweenPrepareContinueAndEnd();
};


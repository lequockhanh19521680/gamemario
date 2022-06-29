#pragma once

#define MARIO_START_WORLD_MAP_X 32
#define MARIO_START_WORLD_MAP_Y 48
class CDataGame
{
private:
	//world map
	float position_x_world_map;
	float position_y_world_map;

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

	float GetPositionXWorldMap() { return position_x_world_map; }
	float GetPositionYWorldMap() { return position_y_world_map; }

	int GetCard1() { return card1; }
	int GetCard2() { return card2; }
	int GetCard3() { return card3; }

	int GetLevel() { return level; }
	int GetScore() { return score; }
	int GetUp() { return Up; }
	int GetCoin() { return coin; }

	void ResetFullData();
};


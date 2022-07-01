#pragma once
#define POSITION_X_HUD_WORLD_MAP 120
#define POSITION_Y_HUD_WORLD_MAP 188

#define POSITION_X_HUD_GAME_OVER 120
#define POSITION_Y_HUD_GAME_OVER 80

#define ADJUST_X_POSITION_ARROW -22
#define ADJUST_Y_POSITION_ARROW 12

#define ADJUST_X_POSITION_NUMBER_HUD_SUB 36
#define ADJUST_Y_POSITION_NUMBER_HUD_SUB 11

#define ADJUST_X_NUMBER_WORLD 20
#define ADJUST_Y_NUMBER_WORLD -10

#define DISTANCE_2_ARROW 8
class CHUDWorldMap
{
private:
	float x, y;


public:
	CHUDWorldMap(float x, float y);
	void DrawNumber(int n, float xTemp, float yTemp);
	void DrawCard(int n, float xTemp, float yTemp);
	void DrawDisPlayHudSub();
	void DrawGameOver();
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};



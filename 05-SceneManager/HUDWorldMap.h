#pragma once
#define POSITION_X_HUD_WORLD_MAP 120
#define POSITION_Y_HUD_WORLD_MAP 188

#define POSITION_X_HUD_GAME_OVER 120
#define POSITION_Y_HUD_GAME_OVER 80

#define ADJUST_X_POSITION_ARROW -22
#define ADJUST_Y_POSITION_ARROW 12

#define DISTANCE_2_ARROW 8
class CHUDWorldMap
{
private:
	float x, y;


public:
	CHUDWorldMap(float x, float y);
	void DrawNumber(int n, float xTemp, float yTemp);
	void DrawCard(int n, float xTemp, float yTemp);
	void DrawGameOver();
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};



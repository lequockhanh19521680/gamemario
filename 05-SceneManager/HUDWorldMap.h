#pragma once
#define POSITION_X_HUD_WORLD_MAP 120
#define POSITION_Y_HUD_WORLD_MAP 188
class CHUDWorldMap
{
private:
	float x, y;


public:
	CHUDWorldMap(float x, float y);
	void DrawNumber(int n, float xTemp, float yTemp);
	void DrawCard(int n, float xTemp, float yTemp);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};



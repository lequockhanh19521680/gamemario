#include "HUD.h"
#include "Font.h"
#include <string>

CHUD::CHUD(float x, float y) {

	this->x = x;
	this->y = y;
	now_time = GetTickCount64();
}

string CHUD::FillNumber(string s, UINT fillNumber)
{
	while (s.size() < fillNumber) {
		s = "0" + s;
	}
	return s;
}

void CHUD::Render(CMario* mario, int remainingTime)
{
	now_time = GetTickCount64();
	CAnimations::GetInstance()->Get(ID_ANI_HUD)->Render(x, y);
	font.Draw(x - ADJUST_X_SCORE, y + ADJUST_Y_SCORE, FillNumber(std::to_string(mario->GetScore()), NUMBER_SCORE)); //score
	font.Draw(x + ADJUST_X_TIME, y + ADJUST_Y_TIME, FillNumber(std::to_string(remainingTime), NUMBER_TIME));
	font.Draw(x - ADJUST_X_WORLD, y - ADJUST_Y_WORLD, FillNumber(std::to_string(1), NUMBER_WORLD));
	font.Draw(x + ADJUST_X_COIN, y - ADJUST_Y_COIN, FillNumber(std::to_string(mario->GetCoin()), NUMBER_COIN));
	font.Draw(x - ADJUST_X_HEALTH, y + ADJUST_X_HEALTH, FillNumber(std::to_string(mario->GetHealth()), NUMBER_HEALTH));
	power = new CPower(x - ADJUST_X_POWER, y - ADJUST_Y_POWER, mario->powerStack);
	power->Render();
}



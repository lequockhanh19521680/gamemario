#include "HUD.h"
#include"Game.h"
#include"Textures.h"
#include "Sprites.h"
#include"PlayScene.h"
#include "Mario.h"
CHUD::CHUD(float x, float y) {
	this->x = x;
	this->y = y;


}

void CHUD::Render() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	CAnimations::GetInstance()->Get(ID_ANI_BLACK_RECTANGEL)->Render(x, y);

	CAnimations::GetInstance()->Get(ID_ANI_HUD)->Render(x, y);
	if(!mario){ }
	else {
		if (mario->GetLevelRun() > 1)
		{
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION, y-ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() > 2) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION + DISTANCE_EVERY_LEVEL_RUN, y - ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() > 3) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION + DISTANCE_EVERY_LEVEL_RUN*2, y - ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() > 4) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION + DISTANCE_EVERY_LEVEL_RUN * 3, y - ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() > 5) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION + DISTANCE_EVERY_LEVEL_RUN * 4, y - ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() > 6) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD)->Render(x - ADJUST_X_POWER_POSITION + DISTANCE_EVERY_LEVEL_RUN * 5, y - ADJUST_Y_POWER_POSITION);
		}
		if (mario->GetLevelRun() == LEVEL_RUN_MAX) {
			CAnimations::GetInstance()->Get(ID_ANI_POWER_HUD_MAX)->Render(x - ADJUST_X_POWER_POSITION_MAX, y - ADJUST_Y_POWER_POSITION);

		}

	}

}

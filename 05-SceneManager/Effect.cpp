#include "Effect.h"
#include"HUD.h"
#include"Game.h"
#include"PlayScene.h"
void CEffect::Render() {
	if (!checkObjectInCamera(this)) return;

	CAnimations* animations = CAnimations::GetInstance();
	if (model == EFFECT_SCORE_100) animations->Get(ID_ANI_EFFECT_100_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_200) animations->Get(ID_ANI_EFFECT_200_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_400) animations->Get(ID_ANI_EFFECT_400_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_800) animations->Get(ID_ANI_EFFECT_800_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_1000) animations->Get(ID_ANI_EFFECT_1000_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_2000) animations->Get(ID_ANI_EFFECT_2000_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_4000) animations->Get(ID_ANI_EFFECT_4000_SCORE)->Render(x, y);
	else if (model == EFFECT_SCORE_8000) animations->Get(ID_ANI_EFFECT_8000_SCORE)->Render(x, y);
	else if (model == EFFECT_UP) animations->Get(ID_ANI_EFFECT_1UP)->Render(x, y);
	else if (model == EFFECT_ATTACK) animations->Get(ID_ANI_EFFECT_ATTACK)->Render(x, y);
	else if (model == EFFECT_FONT_END_1) animations->Get(ID_ANI_EFFECT_FONT_END_1)->Render(x, y);
	else if (model == EFFECT_FONT_END_2) {
		CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		int cardCollected = mario->GetCardCollected();
		animations->Get(ID_ANI_EFFECT_FONT_END_2)->Render(x, y);
		if (cardCollected == 1) animations->Get(ID_ANI_HUD_CARD_MUSHROOM)->Render(x + POSITION_X_CARD_EFFECT, y);
		else if(cardCollected == 2)animations->Get(ID_ANI_HUD_CARD_FLOWER)->Render(x + POSITION_X_CARD_EFFECT, y);
		else if (cardCollected == 3)animations->Get(ID_ANI_HUD_CARD_STAR)->Render(x + POSITION_X_CARD_EFFECT, y);
	}
	else if(model==EFFECT_HELP_WORLD_MAP) animations->Get(ID_ANI_EFFECT_HELP_WORLD_MAP)->Render(x, y);
	else animations->Get(ID_ANI_EFFECT_CHANGE)->Render(x, y);
}

void CEffect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!checkObjectInCamera(this)) return;
	
	if ((EFFECT_SCORE_100 <= model) && (model <= EFFECT_UP))
	{
		if (GetTickCount64() - start_delete > EFFECT_DELETE_TIME) { isDeleted = true; }

		vy = -SPEED_EFFECT;
	}
	if (model == EFFECT_ATTACK) {
		if (GetTickCount64() - start_delete > EFFECT_DELETE_TIME / 2) { isDeleted = true; }
	}
	if (model == EFFECT_CHANGE) {
		if (GetTickCount64() - start_delete > EFFECT_DELETE_TIME ) { isDeleted = true; }
	}
	
	CCollision::GetInstance()->Process(this, dt, coObjects);

}
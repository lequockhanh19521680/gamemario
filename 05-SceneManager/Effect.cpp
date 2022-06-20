#include "Effect.h"
void CEffect::Render() {
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
	else animations->Get(ID_ANI_EFFECT_CHANGE)->Render(x, y);
}

void CEffect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

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
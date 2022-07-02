#include "FontIntro.h"
#include"IntroBackGround.h"
#include"IntroScene.h"
#include "debug.h"
#include"Game.h"
void CFontIntro::Render() {
	CIntroBackGround* player = (CIntroBackGround*)((LPINTROSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if(player->GetState() == BACKGROUND_STATE_MOVE)CAnimations::GetInstance()->Get(ID_ANI_FONT)->Render(x, y);
}
void CFontIntro::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	DebugOutTitle(L"y vy %f %f", y, vy);
	CIntroBackGround* player = (CIntroBackGround*)((LPINTROSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (player->GetState() != BACKGROUND_STATE_MOVE) return;
	if (y > blockY) {
		y = blockY;
		vy = 0;
		player->SetState(BACKGROUND_STATE_DONE_ARROW_UP);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

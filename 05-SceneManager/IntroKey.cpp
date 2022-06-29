#include "IntroKey.h"
#include "debug.h"
#include "AssetIDs.h"
#include "IntroScene.h"
#include "IntroBackGround.h"
void CIntroKey::OnKeyDown(int KeyCode)
{
	CIntroBackGround* player = (CIntroBackGround*)((LPINTROSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
		if (player->GetState() != BACKGROUND_STATE_WILL_CHANGE_SCENE) {
	case DIK_DOWN:
		if (player->GetState() == BACKGROUND_STATE_DONE_ARROW_UP) player->SetState(BACKGROUND_STATE_DONE_ARROW_DOWN);
		else if(player->GetState() == BACKGROUND_STATE_DONE_ARROW_DOWN)  player->SetState(BACKGROUND_STATE_DONE_ARROW_UP);
		break;
	case DIK_UP:
		if (player->GetState() == BACKGROUND_STATE_DONE_ARROW_UP) player->SetState(BACKGROUND_STATE_DONE_ARROW_DOWN);
		else if (player->GetState() == BACKGROUND_STATE_DONE_ARROW_DOWN)  player->SetState(BACKGROUND_STATE_DONE_ARROW_UP);
		break;
	case DIK_S:
		if ((player->GetState() == BACKGROUND_STATE_DONE_ARROW_DOWN) || (player->GetState() == BACKGROUND_STATE_DONE_ARROW_UP))
			player->SetState(BACKGROUND_STATE_WILL_CHANGE_SCENE);
		break;
		}
	}
}
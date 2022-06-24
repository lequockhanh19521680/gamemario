#include "WorldMapKeyEvent.h"
#include "WorldMapPlayer.h"
#include "WorldMapScene.h"
#include "debug.h"

void CWorldMapKeyEvent::OnKeyDown(int KeyCode)
{
	CWorldMapPlayer* player = (CWorldMapPlayer*)((LPWORLDSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
	case DIK_RIGHT:
		if(player->CanActive()) player->SetState(MARIO_STATE_GO_RIGHT);
		break;
	case DIK_LEFT:
		if (player->CanActive()) player->SetState(MARIO_STATE_GO_LEFT);
		break;
	case DIK_UP:
		if (player->CanActive()) player->SetState(MARIO_STATE_GO_TOP);
		break;
	case DIK_DOWN:
		if (player->CanActive()) player->SetState(MARIO_STATE_GO_UNDER);
		break;
	case DIK_S:
		if (player->CanActive()) player->SetState(MARIO_STATE_GO_WORLD_1);
		break;
	
	}
}
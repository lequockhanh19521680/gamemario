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
		
		break;
	case DIK_LEFT:
		
		break;
	case DIK_UP:
		
		break;
	case DIK_DOWN:
		
		break;
	case DIK_S:
	
		break;
	
	}
}
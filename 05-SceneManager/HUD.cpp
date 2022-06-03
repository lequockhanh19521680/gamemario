#include "HUD.h"
#include"Game.h"
#include"Textures.h"
#include "Sprites.h"
#include"PlayScene.h"
void CHUD::Render() {
	CSprites::GetInstance()->Get(SPRITE_HUD_ID)->Draw(x, y);

}
void CHUD::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects){
	CGameObject::Update(dt, coObjects);

}
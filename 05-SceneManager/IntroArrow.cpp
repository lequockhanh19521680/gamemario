#include "IntroArrow.h"
#include"Game.h"
#include"Textures.h"
#include "Sprites.h"
#include"PlayScene.h"
void CIntroArrow::Render(float x, float y) {
	CAnimations::GetInstance()->Get(ID_ANI_ARROW_INTRO)->Render(x, y);
}

void CIntroArrow::RenderChangeScene(float x, float y) {
	CAnimations::GetInstance()->Get(ID_ANI_ARROW_INTRO_CHANGE_SCENE)->Render(x, y);
}
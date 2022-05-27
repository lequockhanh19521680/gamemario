#include "Tail.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Mario.h"
#include "PlantEnemy.h"
#include "BrickQuestion.h"
#include "PlayScene.h"
#include "MushRoom.h"
#include "Leaf.h"
#include "Coin.h"
#include "FlowerFire.h"
CTail::CTail(float x,float y):CGameObject(x,y){}

void CTail::GetBoundingBox(float& l, float& t, float& r, float& b) {

	l = x - TAIL_BBOX_WIDTH/2;
	t = y - TAIL_BBOX_HEIGHT/2;
	r = l + TAIL_BBOX_WIDTH;
	b = t + TAIL_BBOX_HEIGHT;
}
void CTail::Render() {
	RenderBoundingBox();
}
void CTail::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CTail::OnCollisionWith(LPCOLLISIONEVENT e) {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if ((dynamic_cast<CKoopa*>(e->obj)))
		OnCollisionWithKoopa(e);
	else if ((dynamic_cast<CBrickQuestion*>(e->obj)))
		OnCollisionWithBrickQuestion(e);
	else if ((dynamic_cast<CPlantEnemy*>(e->obj)))
		OnCollisionWithPlantEnemy(e);
}

void CTail::OnCollisionWithBrickQuestion(LPCOLLISIONEVENT e)
{
	CBrickQuestion* questionBrick = (dynamic_cast<CBrickQuestion*>(e->obj));
	CMario * mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CPlayScene * scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		if (!questionBrick->GetIsEmpty() || !questionBrick->GetIsUnbox())
		{
			if (questionBrick->GetModel() == QUESTION_BRICK_ITEM) {
				if (mario->GetLevel() == MARIO_LEVEL_SMALL) {
					CMushRoom* mushroom = new CMushRoom(questionBrick->GetX(), questionBrick->GetY());
					scene->AddObject(mushroom);
				}
				else if (mario->GetLevel() == MARIO_LEVEL_BIG) {
					CLeaf* leaf = new CLeaf(questionBrick->GetX(), questionBrick->GetY());
					scene->AddObject(leaf);
				}
				else if (mario->GetLevel() == MARIO_LEVEL_TAIL || mario->GetLevel() == MARIO_LEVEL_FIRE) {
					CFlowerFire* flower = new CFlowerFire(questionBrick->GetX(), questionBrick->GetY());
					scene->AddObject(flower);
				}
			}
			else {
				mario->SetCoin(mario->GetCoin() + 1);
				CCoin* coin = new CCoin(questionBrick->GetX(), questionBrick->GetY());
				coin->SetState(COIN_SUMMON_STATE);
				scene->AddObject(coin);
			}
			questionBrick->SetIsEmpty(true);
			questionBrick->SetIsUnbox(true);
		}
}
void CTail::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	goomba->SetState(GOOMBA_STATE_DIE_UPSIDE);
}
void CTail::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	koopa->SetState(KOOPA_STATE_UPSIDE);
}
void CTail::OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e) {
	CPlantEnemy* plant = dynamic_cast<CPlantEnemy*>(e->obj);
	plant->SetState(PLANT_STATE_DEATH);
}

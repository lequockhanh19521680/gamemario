#include "Koopa.h"
#include "Goomba.h"
#include "Mario.h"
#include "Platform.h"
#include "Scene.h"
#include "Game.h"
#include "PlayScene.h"
#include "debug.h"
#include "BrickQuestion.h"
#include "MushRoom.h"
#include "Leaf.h"
#include "Coin.h"
#include "FlowerFire.h"
#include "PlayScene.h"

CKoopa::CKoopa(float x, float y, int model) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPA_GRAVITY;
	this->model = model;
	defend_start = -1;
	isHeld = false;
	if (model == KOOPA_GREEN_WING) {
		isWing = true;
		SetState(KOOPA_STATE_JUMP);
	}
	else {
		isWing = false;
		SetState(KOOPA_STATE_WALKING);
	}
	isComeback = false;
	isDefend = false;
	isKicked = false;
	isOnPlatform = false;
	isHeld = false;
	isUpside = false;
}
void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vy += ay * dt;
	vx += ax * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if (state == KOOPA_STATE_ISDEAD) return;
	if (isDefend || isUpside) {
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT_DEFEND / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT_DEFEND;
	}
	else {
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT;
	}
}

int CKoopa::GetAniGreen() {
	int aniId = -1;
	if (!isWing) {
		if (isUpside) {
			if (isKicked) aniId = ID_ANI_GREEN_UPSIDE_KICKED;
			else aniId = ID_ANI_GREEN_UPSIDE;
		}
		else {
			if (isDefend) {
				if (isKicked) aniId = ID_ANI_GREEN_DEFEND;//ID_ANI_GREEN_KICKED;
				else aniId = ID_ANI_GREEN_DEFEND;
			}
			else
			{
				if (vx > 0) aniId = ID_ANI_GREEN_WALK_RIGHT;
				else aniId = ID_ANI_GREEN_WALK_LEFT;
			}
		}
	}
	else {
		if (vx > 0) aniId = ID_ANI_GREEN_WING_RIGHT;
		else aniId = ID_ANI_GREEN_WING_LEFT;
	}
	return aniId;
}

int CKoopa::GetAniRed() {
	int aniId;
	if (isUpside) {
		if (isKicked) aniId = ID_ANI_RED_UPSIDE_KICKED;
		else aniId = ID_ANI_RED_UPSIDE;
	}
	else {
		if (isDefend) {
			if (isKicked) aniId = ID_ANI_RED_DEFEND;//ID_ANI_RED_KICKED;
			else aniId = ID_ANI_RED_DEFEND;
		}
		else
		{
		if (vx > 0) aniId = ID_ANI_RED_WALK_RIGHT;
		else aniId = ID_ANI_RED_WALK_LEFT;
		}
	}
	return aniId;
}

void CKoopa::Render() {
	int aniId;
	if (model == KOOPA_RED) {
		aniId = GetAniRed();
	}
	else aniId = GetAniGreen();
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CKoopa::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CKoopa::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (!e->obj->IsBlocking() && !e->obj->IsPlatform() && !e->obj->IsPlayer() && !e->obj->IsEnemy()) return;
	if (!dynamic_cast<CGoomba*>(e->obj) && !dynamic_cast<CMario*>(e->obj)) {
		if (e->ny < 0)
		{
			vy = 0;
			isOnPlatform = true;
		}
		if (e->nx != 0 && e->obj->IsBlocking())
		{
			vx = -vx;
		}
	}

	if (dynamic_cast<CGoomba*>(e->obj))
		this->OnCollisionWithGoomba(e);
	else if (dynamic_cast<CBrickQuestion*>(e->obj))
		this->OnCollisionWithBrickQuestion(e);
	else if (dynamic_cast<CPlatform*>(e->obj))
		this->OnCollisionWithPlatform(e);
}
void CKoopa::OnCollisionWithBrickQuestion(LPCOLLISIONEVENT e) {
	CBrickQuestion* questionBrick = dynamic_cast<CBrickQuestion*>(e->obj);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();

	if (e->nx != 0) {
		if (isKicked) {
			if (!questionBrick->GetIsEmpty() || !questionBrick->GetIsUnbox()) {
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
	}
}
void CKoopa::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (e->nx != 0) {
		if (isKicked) {
			goomba->SetState(GOOMBA_STATE_DIE_UPSIDE);
		}
	}
}
void CKoopa::OnCollisionWithPlatform(LPCOLLISIONEVENT e) {
	CPlatform* platform = dynamic_cast<CPlatform*>(e->obj);
	if (e->ny < 0) {
		isOnPlatform = true;
		if (!isDefend && !isUpside) {
			SetY(platform->GetY() - KOOPA_BBOX_HEIGHT + 4);
		}
		else
		{
			SetY(platform->GetY() - KOOPA_BBOX_HEIGHT/2 - 3);
		}
	}
	if ((model == KOOPA_RED) && (state == KOOPA_STATE_WALKING))
	{
		if ((platform->GetX() > GetX()) || (GetX() > platform->GetX() + (platform->GetLength() - 1) * KOOPA_BBOX_WIDTH))
		{
			if ((platform->GetX() > GetX())) {
				SetX(platform->GetX());
			}
			if ((GetX() > platform->GetX() + (platform->GetLength() - 1) * KOOPA_BBOX_WIDTH)){
			SetX(platform->GetX() + (platform->GetLength() - 1) * KOOPA_BBOX_WIDTH);
			}
			vx = -vx;
		}
	}
}
void CKoopa::SetState(int state) {
	if (this->state == KOOPA_STATE_ISDEAD) return;
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (state) {
	case KOOPA_STATE_WALKING: 
		vx = -KOOPA_WALKING_SPEED;
		vy = 0;
		ay = KOOPA_GRAVITY;
		isComeback = false;
		isDefend = false;
		isUpside = false;
		isKicked = false;
		isWing = false;
		isHeld = false;
		isOnPlatform = true;
		break;
	case KOOPA_STATE_DEFEND:
		isOnPlatform = true;
		isDefend = true;
		isComeback = false;
		isKicked = false;
		isUpside = false;
		defend_start = GetTickCount64();
		vx = 0;
		break;
	case KOOPA_STATE_UPSIDE:
		isUpside = true;
		isDefend = false;
		isComeback = false;
		isKicked = false;
		defend_start = GetTickCount64();
		vx = 0;
		break;
	case KOOPA_STATE_IS_KICKED:
		isOnPlatform = true;
		isKicked = true;
		isHeld = false;
		vx = mario->GetNx() * KOOPA_IS_KICKED_SPEED;
		break;
	case KOOPA_STATE_JUMP: {
		isUpside = false;
		isDefend = false;
		isComeback = false;
		isKicked = false;
		vx = -KOOPA_WALKING_SPEED;
		ay = KOOPA_GRAVITY;
		break;
	}

	}
	CGameObject::SetState(state);
}

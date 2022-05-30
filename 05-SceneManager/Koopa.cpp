#include "Koopa.h"
#include "Goomba.h"
#include "Mario.h"
#include "Platform.h"
#include "Scene.h"
#include "Game.h"
#include "PlantEnemy.h"
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
	isDead = false;
}

void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!checkObjectInCamera(this)) return;

	vy += ay * dt;
	vx += ax * dt;
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	
	if (mario->GetIsHolding() && isHeld) {
		this->x = mario->GetX() + mario->GetNx() * (MARIO_BIG_BBOX_WIDTH-3);
		this->y = mario->GetY();

		vx = mario->GetVx();
		vy = mario->GetVy();
	}
	else {
		if (this->isHeld) {
			ay = KOOPA_GRAVITY;
			SetState(KOOPA_STATE_IS_KICKED);
		}
	}
	
	if (isDead && isUpside) {
		if (GetTickCount64() - die_start > KOOPA_DIE_TIME)
		{
			isDeleted = true;
			return;
		}
	}
	if (!isDead) {
		if (!isKicked) {
			if (GetTickCount64() - defend_start > KOOPA_COMBACK_START && (isDefend || isUpside) && !isKicked) {
				isComeback = true;
			}
			if ((GetTickCount64() - defend_start > KOOPA_DEFEND_TIMEOUT && (isDefend || isUpside) && !isKicked)) {
				if (isComeback) {
					SetState(KOOPA_STATE_WALKING);
					vy = -KOOPA_ADJUST_NOT_FALL;
					defend_start = -1;
				}
			}
		}
		else { isComeback = false; }
	}
	if (state == KOOPA_STATE_UPSIDE && !isOnPlatform) {
		vx = -KOOPA_WALKING_SPEED;
	}
	
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if ((state == KOOPA_STATE_ISDEAD) || (state == KOOPA_STATE_DEAD_UPSIDE)) return;
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
int CKoopa::PositionWithMario() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetX() < GetX()) return 1;
	else return -1;

}
int CKoopa::GetAniGreen() {
	int aniId = -1;
	if (!isWing) {
		if (isUpside) {
			if (isComeback) aniId = ID_ANI_GREEN_UPSIDE_COMEBACK;
			else if (isKicked) aniId = ID_ANI_GREEN_UPSIDE_KICKED;
			else aniId = ID_ANI_GREEN_UPSIDE;
		}
		else {
			if (isDefend) {
				if (isComeback) aniId = ID_ANI_GREEN_COMEBACK;
				else if (isKicked) aniId = ID_ANI_GREEN_DEFEND;//ID_ANI_GREEN_KICKED;
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
		if (isComeback) aniId = ID_ANI_RED_UPSIDE_COMEBACK;
		else if (isKicked) aniId = ID_ANI_RED_UPSIDE_KICKED;
		else aniId = ID_ANI_RED_UPSIDE;
	}
	else {
		if (isDefend) {
			if (isComeback) aniId = ID_ANI_RED_COMEBACK;
			else if (isKicked) aniId = ID_ANI_RED_DEFEND;//ID_ANI_RED_KICKED;
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
			if (model != KOOPA_GREEN_WING) {
				vy = 0;
				isOnPlatform = true;
			}
			else {
				if (state == KOOPA_STATE_JUMP)  {
					vy = -KOOPA_JUMP_SPEED;
				}
				else vy = 0;
			}
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
	else if ((dynamic_cast<CKoopa*>(e->obj)))
		this->OnCollisionWithKoopa(e);
	else if ((dynamic_cast<CPlantEnemy*>(e->obj)))
		this->OnCollisionWithPlantEnemy(e);
}


void CKoopa::OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e) {
	CPlantEnemy* plant = dynamic_cast<CPlantEnemy*>(e->obj);
	if (isKicked) {
		plant->SetState(PLANT_STATE_DEATH);
	}
}


void CKoopa::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	if (isHeld) {
		SetState(KOOPA_STATE_DEAD_UPSIDE);
		koopa->SetState(KOOPA_STATE_DEAD_UPSIDE);
	}
	else if (isKicked) {
		koopa->SetState(KOOPA_STATE_DEAD_UPSIDE);
	}
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
		if ((model == KOOPA_GREEN_WING) && (state == KOOPA_STATE_JUMP)) {
			vy = -KOOPA_JUMP_SPEED;
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
		break;
	case KOOPA_STATE_DEFEND:
		isDefend = true;
		isComeback = false;
		isKicked = false;
		isUpside = false;
		if(isOnPlatform) vx = 0;
		defend_start = GetTickCount64();
		break;
	case KOOPA_STATE_UPSIDE:
		isUpside = true;
		isDefend = false;
		isComeback = false;
		isKicked = false;
		vy = -KOOPA_JUMP_SPEED;
		if (isOnPlatform) vx = 0;
		defend_start = GetTickCount64();
		break;
	case KOOPA_STATE_IS_KICKED:
		if (isHeld) {
			vy = -KOOPA_KICKED_NOT_FALL;
		}
		isOnPlatform = true;
		isKicked = true;
		isHeld = false;
		vx = PositionWithMario() * KOOPA_IS_KICKED_SPEED;
		break;
	case KOOPA_STATE_JUMP: 
		isUpside = false;
		isDefend = false;
		isComeback = false;
		isKicked = false;
		vx = -KOOPA_WALKING_SPEED;
		if (isWing) {
			ay = KOOPA_GRAVITY_WING;
		}
		break;
	case KOOPA_STATE_DEAD_UPSIDE:
		vy = -KOOPA_JUMP_DEATH;
		ay = KOOPA_GRAVITY;
		vx = 0;
		isWing = false;
		isComeback = false;
		isDefend = false;
		isHeld = false;
		isKicked = false;
		isUpside = true;
		isDead = true;
		die_start = GetTickCount64();
		break;
	}
	CGameObject::SetState(state);
}

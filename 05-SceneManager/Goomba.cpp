#include "Goomba.h"
#include "Platform.h"
#include "Mario.h"
#include "PlayScene.h"
CGoomba::CGoomba(float x, float y,int model):CGameObject(x, y)
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;
	this->model = model;
	startX = x;
	startY = y;
	
	SetState(GOOMBA_STATE_WALKING);
	isUpside = false;
	isJump = false;
	isAttack = false;
	isOnPlatForm = false;
	isDead = false;

	num_jump_small = 0;
}

void CGoomba::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (isUpside) return;
	if (isDead)
	{
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{ 
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT - 2;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CGoomba*>(e->obj)) return;
	if (!e->obj->IsBlocking() && !e->obj->IsPlatform()) return;
	if (e->ny < 0)
	{
		isOnPlatForm = true;
		vy = 0;
	}
	if ((e->nx != 0) && (!e->obj->IsEnemy()))
	{
		if (!e->obj->IsPlayer()) {
			vx = -vx;
		}
	}
	if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatForm(e);
}

void CGoomba::OnCollisionWithPlatForm(LPCOLLISIONEVENT e)
{
	CPlatform* platform = dynamic_cast<CPlatform*>(e->obj);
	if (e->ny < 0) {
		isOnPlatForm = true;
		SetY(platform->GetY() - GOOMBA_BBOX_HEIGHT+1);
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (!checkObjectInCamera(this)) return;
	if (mario->GetIsChanging() || mario->GetState()==MARIO_STATE_DIE) return;
	vy += ay * dt;
	vx += ax * dt;

	if ( (isDead == true) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT) )
	{
		isDeleted = true;
		return;
	}
	if ((isUpside == true) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT * 6))
	{
		isDeleted = true;
		return;
	}
	if (vy < 0) {
		isOnPlatForm = false;
	}
	if (!isUpside) {
		if ((model == GOOMBA_WING) && (!isAttack)) {
			if ((GetTickCount64() - time_walking > TIME_WALKING-TIME_JUMP_SMALL)&& !isJump) {
				if (isOnPlatForm && (num_jump_small <3)) {
					vy = -GOOMBA_JUMP_DEFLECT_SPEED / 2; 
					num_jump_small +=1;
				}
			}
			if (GetTickCount64() - time_walking > TIME_WALKING && !isJump) {
				SetState(GOOMBA_STATE_FLY);

				if ((vx >= 0) && (mario->GetX() < GetX()))
				{
					vx = -GOOMBA_WALKING_SPEED;
				}
				else if ((vx <= 0) && (mario->GetX() > GetX()))
				{
					vx = GOOMBA_WALKING_SPEED;
				}
				time_walking = -1;
				num_jump_small = 0;
				//time_jump_small = GetTickCount64();
			}
			else 
			{
				if (isJump) {
					SetState(GOOMBA_STATE_WALKING);
				}
				
			}
		}
	}
	
	
	
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

int CGoomba::GetAniGoompaWing() {
	int aniId = -1;
	if (isAttack) {
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_RED_UPSIDE;
		}
		else {
			if (isDead) {
				aniId = ID_ANI_GOOMBA_RED_DIE;
			}
			else {
				aniId = ID_ANI_GOOMBA_RED;
			}
		}
	}
	else {
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_RED_UPSIDE;
		}
		else if (!isOnPlatForm) {
			aniId = ID_ANI_GOOMBA_RED_FLY_JUMP;
		}
		else aniId = ID_ANI_GOOMBA_RED_FLY_WALKING;
	}
		
	
	return aniId;
}

int CGoomba::GetAniGoompaBase() {
	int aniId = -1;
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_UPSIDE;
		}
		else {
			if (isDead) {
				aniId = ID_ANI_GOOMBA_DIE;
			}
			else {
				aniId = ID_ANI_GOOMBA_WALKING;
			}
		}
	return aniId;
}


void CGoomba::Render()
{
	if (!checkObjectInCamera(this)) return;

	int aniId = -1;
	if (model == GOOMBA_WING) {
		aniId = GetAniGoompaWing();
	}
	else{
		aniId = GetAniGoompaBase();
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x,y);
	//RenderBoundingBox();
	//DebugOutTitle(L"IsPlatform: %d", isOnPlatForm);

}

void CGoomba::SetState(int state)
{	
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (state)
	{
		case GOOMBA_STATE_DIE:
			die_start = GetTickCount64();
			y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
			vx = 0;
			vy = 0;
			isDead = true;
			isUpside = false;
			break;
		case GOOMBA_STATE_WALKING: 
			if (model == GOOMBA_BASE) {
				vx = -GOOMBA_WALKING_SPEED;
				isDead = false;
				isJump = false;
				isAttack = false;
				isUpside = false;
				walkingCheck = false;
			}
			else {
				if (isAttack) {
					isDead = false;
					isJump = false;
					isUpside = false;
					walkingCheck = false;
					vx = -GOOMBA_WALKING_SPEED;
					time_walking = GetTickCount64();
				}
				else {
					isDead = false;
					isJump = false;
					isUpside = false;
					time_walking = GetTickCount64();

				}
			}

			break;
		case GOOMBA_STATE_FLY:
			vy = -GOOMBA_JUMP_DEFLECT_SPEED;
			isJump = true;
			isOnPlatForm = false;
			break;
		case GOOMBA_STATE_IS_ATTACK:
			vx = -GOOMBA_WALKING_SPEED;
			if (model == GOOMBA_WING) {
				if (!isAttack) {
					isAttack = true;
					isDead = false;
					isJump = false;
					isUpside = false;
				}
				else {
					vx = 0;
					die_start = GetTickCount64();
					isDead = true;
					isJump = false;
					isUpside = false;
				}
			}
			else {
				vx = 0;
				die_start = GetTickCount64();
				isDead = true;
				isJump = false;
				isUpside = false;
			};
			break;
		case GOOMBA_STATE_DIE_UPSIDE:
			vy = -GOOMBA_JUMP_DEFLECT_SPEED;
			isUpside = true;
			die_start = GetTickCount64();
			break;
	}
	CGameObject::SetState(state);
}



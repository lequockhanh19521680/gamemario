#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "GameObject.h"


class CKoopa : public CGameObject {
	protected:
		float ax;
		float ay;

		ULONGLONG die_start;

		virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
		virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
		virtual void Render();

		virtual int IsCollidable() { return 1; };
		virtual int IsBlocking() { return 1; }
		virtual void OnNoCollision(DWORD dt);

		virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	public:
		CKoopa(float x, float y);
		virtual void SetState(int state);
	
};
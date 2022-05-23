#pragma once
#include "GameObject.h"

#define PIPE_BBOX_WIDTH 32
#define PIPE_BBOX_HEIGHT_SHORT 32 
#define	PIPE_BBOX_HEIGHT_LONG 48 


#define ID_ANI_PIPE_SHORT 201
#define ID_ANI_PIPE_LONG 202

#define FLOWER_SHOOT 10
#define	FLOWER_NOT_SHOOT 20

#define PIPE_SHORT_MODEL 1
#define PIPE_LONG_MODEL	2
class CPipe : public CGameObject
{
	protected:
		int typeFlower;

	public:
		CPipe(float x, float y) : CGameObject(x, y) {}
		CPipe(float x, float y, int model, int typeFlower) {
			this->x = x;
			this->y = y;
			this->model = model;
			this->typeFlower = typeFlower;
		}

		void Render();
		void Update(DWORD dt) {}
		void GetBoundingBox(float& l, float& t, float& r, float& b);

		virtual int IsBlocking() { return 1; }
};


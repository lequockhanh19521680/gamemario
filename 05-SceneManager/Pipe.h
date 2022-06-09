#pragma once
#include "GameObject.h"

#define PIPE_BBOX_WIDTH 28
#define PIPE_BBOX_HEIGHT_SHORT 32 
#define	PIPE_BBOX_HEIGHT_LONG 48 


#define ID_ANI_PIPE_SHORT 201
#define ID_ANI_PIPE_LONG 202

#define PIPE_SHORT_MODEL 1
#define PIPE_LONG_MODEL	2
#define PLANT_NOTHING 10
class CPipe : public CGameObject
{
	protected:
		int model;
		int typePlant;

	public:
		CPipe(float x, float y, int model, int typeFlower);

		void Render();
		void Update(DWORD dt) {}
		void GetBoundingBox(float& l, float& t, float& r, float& b);

		virtual int IsBlocking() { return 1; }
		void SetModel(int model) { this->model = model; }
		int GetModel() { return model; }
};


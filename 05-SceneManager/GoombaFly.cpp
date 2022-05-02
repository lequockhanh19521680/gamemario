#include "GoombaFly.h"
CGoombaFly::CGoombaFly(float x, float y) :CGoomba(x,y)
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;
	SetState(GOOMBA_STATE_FLY);
}
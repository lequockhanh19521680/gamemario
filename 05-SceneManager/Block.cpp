#include "Block.h"
#include "Game.h"
#include "Textures.h"
#include "Mario.h"
void CBlock::Render()
{
	//RenderBoundingBox();
}

void CBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = left-BLOCK_BBOX_WIDTH/2;
	t = top-BLOCK_BBOX_HEIGHT/2;
	r = right-BLOCK_BBOX_HEIGHT;
	b = bottom-BLOCK_BBOX_WIDTH;
}
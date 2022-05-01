#pragma once

#include "GameObject.h"
#include "Sprites.h"
#include "Game.h"
#include "Textures.h"

#define ID_TEXT_FONT 110
#define NUM_OF_LETTER 26
#define NUM_OF_NUMBER 10
#define TILE_FONT_WIDTH 8
#define	TILE_FONT_LETTER_HEIGHT 8
#define TILE_FONT_NUMBER_HEIGHT 8
#define SPACE_WIDTH 8
#define NOTE_OF_EXCLAMATION_WIDTH 6
#define TOP_LETTER 0
class CFont
{
public:
	LPTEXTURE Tex;
	void Draw(float x, float y, const string& s);
	CFont();
};


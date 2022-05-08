#pragma once
#include"Sprites.h"
#include <map>
#include "AssetIDs.h"

class CFont
{
	std::map<char, LPSPRITE> fonts;

public:
	CFont();
	void Init();
	LPSPRITE mapping(char c);
	vector<LPSPRITE> StringToSprite(string str);
};


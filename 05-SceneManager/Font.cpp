#include "Font.h"
void CFont::Init()
{
	CSprites* sprites = CSprites::GetInstance();
	fonts.insert(make_pair('0', sprites->Get(ID_SPRITE_FONT_0)));
	fonts.insert(make_pair('1', sprites->Get(ID_SPRITE_FONT_1)));
	fonts.insert(make_pair('2', sprites->Get(ID_SPRITE_FONT_2)));
	fonts.insert(make_pair('3', sprites->Get(ID_SPRITE_FONT_3)));
	fonts.insert(make_pair('4', sprites->Get(ID_SPRITE_FONT_4)));
	fonts.insert(make_pair('5', sprites->Get(ID_SPRITE_FONT_5)));
	fonts.insert(make_pair('6', sprites->Get(ID_SPRITE_FONT_6)));
	fonts.insert(make_pair('7', sprites->Get(ID_SPRITE_FONT_7)));
	fonts.insert(make_pair('8', sprites->Get(ID_SPRITE_FONT_8)));
	fonts.insert(make_pair('9', sprites->Get(ID_SPRITE_FONT_9)));
	fonts.insert(make_pair('A', sprites->Get(ID_SPRITE_FONT_A)));
	fonts.insert(make_pair('B', sprites->Get(ID_SPRITE_FONT_B)));
	fonts.insert(make_pair('C', sprites->Get(ID_SPRITE_FONT_C)));
	fonts.insert(make_pair('D', sprites->Get(ID_SPRITE_FONT_D)));
	fonts.insert(make_pair('E', sprites->Get(ID_SPRITE_FONT_E)));
	fonts.insert(make_pair('F', sprites->Get(ID_SPRITE_FONT_F)));
	fonts.insert(make_pair('G', sprites->Get(ID_SPRITE_FONT_G)));
	fonts.insert(make_pair('H', sprites->Get(ID_SPRITE_FONT_H)));
	fonts.insert(make_pair('I', sprites->Get(ID_SPRITE_FONT_I)));
	fonts.insert(make_pair('J', sprites->Get(ID_SPRITE_FONT_J)));
	fonts.insert(make_pair('K', sprites->Get(ID_SPRITE_FONT_K)));
	fonts.insert(make_pair('L', sprites->Get(ID_SPRITE_FONT_L)));
	fonts.insert(make_pair('M', sprites->Get(ID_SPRITE_FONT_M)));
	fonts.insert(make_pair('N', sprites->Get(ID_SPRITE_FONT_N)));
	fonts.insert(make_pair('O', sprites->Get(ID_SPRITE_FONT_O)));
	fonts.insert(make_pair('P', sprites->Get(ID_SPRITE_FONT_P)));
	fonts.insert(make_pair('Q', sprites->Get(ID_SPRITE_FONT_Q)));
	fonts.insert(make_pair('R', sprites->Get(ID_SPRITE_FONT_R)));
	fonts.insert(make_pair('S', sprites->Get(ID_SPRITE_FONT_S)));
	fonts.insert(make_pair('T', sprites->Get(ID_SPRITE_FONT_T)));
	fonts.insert(make_pair('U', sprites->Get(ID_SPRITE_FONT_U)));
	fonts.insert(make_pair('V', sprites->Get(ID_SPRITE_FONT_V)));
	fonts.insert(make_pair('W', sprites->Get(ID_SPRITE_FONT_W)));
	fonts.insert(make_pair('X', sprites->Get(ID_SPRITE_FONT_X)));
	fonts.insert(make_pair('Y', sprites->Get(ID_SPRITE_FONT_Y)));
	fonts.insert(make_pair('Z', sprites->Get(ID_SPRITE_FONT_Z)));
}

LPSPRITE CFont::mapping(char c)
{
	int ic = (int)c;
	if (!(ic >= 48 && ic <= 57 || ic >= 64 && ic <= 90))
		return NULL;
	return fonts.at(c);
}
vector<LPSPRITE> CFont::StringToSprite(string str)
{
	vector<LPSPRITE> sprites;
	LPSPRITE sprite;
	char c;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		c = (char)str[i];
		sprite = mapping(c);
		if (sprite != NULL)
			sprites.push_back(sprite);
	}
	return sprites;
}
CFont::CFont()
{
	Init();
}

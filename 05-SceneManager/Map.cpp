#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(int TexID, int NumofRowMap, int NumofColMap, int NumofRowTileSet, int NumofColTileSet, int TotalTile)
{
	Tex = CTextures::GetInstance()->Get(TexID);
	this->NumofRowMap = NumofRowMap;
	this->NumofColMap = NumofColMap;
	this->NumofRowTileSet = NumofRowTileSet;
	this->NumofColTileSet = NumofColTileSet;
	this->TotalTile = TotalTile;
	CamX = CamY = 0;
}
Map::~Map() {}
void Map::SetMapData(int** mapData)
{
	TileMapData = mapData;
}
void Map::DrawMap()
{
	int FirstColumn = (int)floor(CamX / TILE_WIDTH);
	int LastColumn = (int)ceil((CamX + CGame::GetInstance()->GetScreenWidth()) / TILE_WIDTH);
	if (LastColumn >= NumofColMap)
		LastColumn = NumofColMap - 1;
	for (int CurrentRow = 0; CurrentRow < NumofRowMap; CurrentRow++) {
		for (int CurrentColumn = 0; CurrentColumn <= LastColumn; CurrentColumn++)
		{
			int index = TileMapData[CurrentRow][CurrentColumn] - 1;
			if (index < TotalTile)
				Tiles.at(index)->Draw((float)(CurrentColumn * TILE_WIDTH), float(CurrentRow * TILE_HEIGHT - HUD_HEIGHT));
		}
	}
}
void Map::GetSpriteTile()
{
	for (int tile = 0; tile < TotalTile; tile++)
	{
		{
			int left = tile % NumofColTileSet * TILE_WIDTH;
			int top = tile / NumofColTileSet * TILE_HEIGHT;
			int right = left + TILE_WIDTH;
			int bottom = top + TILE_HEIGHT;
			LPSPRITE SpriteTile = new CSprite(tile, left, top, right, bottom, Tex);
			Tiles.push_back(SpriteTile);
		}
	}
}
int Map::GetMapHeight()
{
	return NumofRowMap * TILE_HEIGHT;
}
int Map::GetMapWidth()
{
	return NumofColMap * TILE_WIDTH;
}



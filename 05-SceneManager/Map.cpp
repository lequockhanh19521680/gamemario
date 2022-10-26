#include "Map.h"
#include "Utils.h"
#include "Game.h"
#include "debug.h"
CMap::CMap(int TileSetID, int TotalRowsOfMap, int TotalColumnsOfMap, int TotalRowsOfTileSet, int  TotalColumnsOfTileSet, int TotalTiles,int startX, int startY)
{
	TileSet = CTextures::GetInstance()->Get(TileSetID);
	this->TotalRowsOfMap = TotalRowsOfMap;
	this->TotalColumnsOfMap = TotalColumnsOfMap;
	this->TotalRowsOfTileSet = TotalRowsOfTileSet;
	this->TotalColumnsOfTileSet = TotalColumnsOfTileSet;
	this->TotalTiles = TotalTiles;
	this->startX = startX;
	this->startY = startY;
	CamX = CamY = 0;
	TileMap = NULL;
}

CMap::~CMap()
{
}
bool CMap::checkObjectInCamera(float x, float y) {
	float w = 32.0f;
	float h = 32.0f;
	if (x + w <= (CGame::GetInstance()->GetCamX()) || (CGame::GetInstance()->GetCamX()) + SCREEN_WIDTH <= x)
		return false;
	if (y + h <= (CGame::GetInstance()->GetCamY()) || (CGame::GetInstance()->GetCamY()) + SCREEN_HEIGHT + h <= y)
		return false;
	return true;
}
void CMap::Render()
{
	int FirstColumn = int(floor(CamX/ TILE_WIDTH));
	int LastColumn =  int(ceil((CamX * TILE_WIDTH + CGame::GetInstance()->GetScreenWidth())/ TILE_WIDTH));
	if (LastColumn >= TotalColumnsOfMap)
		LastColumn = TotalColumnsOfMap - 1;
	int d = 0;
	for (int CurrentRow = 0; CurrentRow < TotalRowsOfMap; CurrentRow++)
		for (int CurrentColumn = FirstColumn; CurrentColumn <= LastColumn; CurrentColumn++)
		{
			int index = TileMap[CurrentRow][CurrentColumn] - 1;
			if (index < TotalTiles)
			{
				float xDraw = float(CurrentColumn * TILE_WIDTH) + float(startX * TILE_WIDTH);
				float yDraw = float(CurrentRow * TILE_HEIGHT) - float(startY * TILE_HEIGHT);
				if (checkObjectInCamera(xDraw, yDraw)) {
					Tiles.at(index)->Draw(xDraw,yDraw);
				}
			}
		}
}

void CMap::SetTileMapData(int** TileMapData)
{
	TileMap = TileMapData;
}


void CMap::ExtractTileFromTileSet()
{
	for (int TileNum = 0; TileNum < TotalTiles; TileNum++)
	{
		int left = TileNum % TotalColumnsOfTileSet * TILE_WIDTH;
		int top = TileNum / TotalColumnsOfTileSet * TILE_HEIGHT;
		int right = left + TILE_WIDTH-1;
		int bottom = top + TILE_HEIGHT-1;
		LPSPRITE NewTile = new CSprite(TileNum, left, top, right, bottom, TileSet); // get tile from tileset
		this->Tiles.push_back(NewTile);
	}
}

int CMap::GetMapWidth()
{
	return TotalColumnsOfMap * TILE_WIDTH;
}

int CMap::GetMapHeight()
{
	return TotalRowsOfMap * TILE_HEIGHT;
}

#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "Map.h"
#include "HUD.h"


#define CAM_CHANGE_TIME		30
class CPlayScene: public CScene
{
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;					
	CMap* current_map = NULL;
	CMap* hidden_map = NULL;
	CHUD* hud = NULL;
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_TILEMAP_DATA(string line);
	void _ParseSection_TILEMAP_HIDDEN_DATA(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);
	void LoadAssets(LPCWSTR assetFile);
	
public: 

	void AddObject(LPGAMEOBJECT object);
	CPlayScene(int id, LPCWSTR filePath);
	vector<LPGAMEOBJECT> GetListObject() { return objects; }
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	CMap* GetMap() { return current_map; }
	CMap* GetHiddenMap() { return hidden_map; }
	LPGAMEOBJECT GetPlayer() { return player; }
	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;


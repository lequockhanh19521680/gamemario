#pragma once
#include "Scene.h"
#include"Scene.h"
#include "WorldMapPlayer.h"
#include "Map.h"
#include "GameObject.h"
#include "HUDWorldMap.h"



class CIntroScene : public CScene
{
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);

public:

	CIntroScene(int id, LPCWSTR filePath);
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	void Clear();
	bool IsGameObjectDeleted(const LPGAMEOBJECT& o);

	void PurgeDeletedObjects();
};




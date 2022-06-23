#include"Scene.h"
#include "WorldMapPlayer.h"
#include "Map.h"
#include "GameObject.h"


class CWorldMapScene : public CScene
{
	LPGAMEOBJECT player = NULL;
	CMap* current_map = NULL;
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_TILEMAP_DATA(string line);

	void LoadAssets(LPCWSTR assetFile);

public:

	CWorldMapScene(int id, LPCWSTR filePath);
	LPGAMEOBJECT GetPlayer() { return player; }
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	void Clear();
	bool IsGameObjectDeleted(const LPGAMEOBJECT& o);

	void PurgeDeletedObjects();
};

typedef CWorldMapScene* LPWORLDSCENE;

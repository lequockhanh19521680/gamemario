#include"Scene.h"
#include "WorldMapPlayer.h"
#include "Map.h"
#include "GameObject.h"


class CWorldMapScene : public CScene
{
	CWorldMapPlayer* player = NULL;
	CMap* map = NULL;
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_TILEMAP(string line);

	void LoadAssets(LPCWSTR assetFile);

public:

	CWorldMapScene(int id, LPCWSTR filePath);
	CWorldMapPlayer* GetPlayer() { return player; }
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	void Clear();

};

typedef CWorldMapScene* LPWORLDSCENE;

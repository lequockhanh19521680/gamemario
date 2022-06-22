#include "WorldMapScene.h"
#include "WorldMapKeyEvent.h"
#include "WorldMapPlayer.h"
CWorldMapScene::CWorldMapScene(int id, LPCWSTR filePath) :
	CScene(id, filePath)
{
	player = NULL;

	key_handler = new CWorldMapKeyEvent(this);
}
void CWorldMapScene::_ParseSection_SPRITES(string line) {

}
void CWorldMapScene::_ParseSection_ANIMATIONS(string line) {

}

void CWorldMapScene::_ParseSection_ASSETS(string line) {

}
void CWorldMapScene::_ParseSection_OBJECTS(string line) {

}
void CWorldMapScene::_ParseSection_TILEMAP(string line) {

}

void CWorldMapScene::LoadAssets(LPCWSTR assetFile) {

}



void CWorldMapScene::Load() {

}
void CWorldMapScene::Update(DWORD dt) {

}
void CWorldMapScene::Render() {

}
void CWorldMapScene::Unload() {

}
void CWorldMapScene::Clear() {

}
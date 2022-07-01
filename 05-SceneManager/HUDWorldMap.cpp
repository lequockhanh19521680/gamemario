#include "HUDWorldMap.h"
#include"HUD.h"
#include "Game.h"
#include"debug.h"
#include"Animations.h"
CHUDWorldMap::CHUDWorldMap(float x, float y) {
	this->x = x;
	this->y = y;
}

void CHUDWorldMap::Render() {
	CDataGame* data = CGame::GetInstance()->GetDataGame();

	CAnimations::GetInstance()->Get(ID_ANI_BLACK_RECTANGEL)->Render(x, y);

	CAnimations::GetInstance()->Get(ID_ANI_HUD)->Render(x, y);
	// WRITE WORLD
	DrawNumber(1, x + POSITION_WORLD_X, y - ADJUST_Y_POWER_POSITION);
	//WRITE M SYMBOL
	CAnimations::GetInstance()->Get(ID_ANI_M_SYMBOL)->Render(x + POSITION_M_SYMBOL_X, y - ADJUST_Y_POWER_POSITION_UNDER - 1);

	//WRITE SCORE
	int score = data->GetScore();
	DrawNumber(score / 1000000, x + POSITION_SCORE_X, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber((score / 100000) % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber((score / 10000) % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER * 2, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber((score / 1000) % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER * 3, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber((score / 100) % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER * 4, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber((score / 10) % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER * 5, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber(score % 10, x + POSITION_SCORE_X + DISTANCE_NUMBER * 6, y - ADJUST_Y_POWER_POSITION_UNDER);




	//WRITE CARD
	int card1 = data->GetCard1();
	int card2 = data->GetCard2();
	int card3 = data->GetCard3();

	if (card1) DrawCard(card1, x + X_CARD_POSITION, y + Y_CARD_POSITION);
	if (card2) DrawCard(card2, x + X_CARD_POSITION + CARD_WIDTH, y + Y_CARD_POSITION);
	if (card3) DrawCard(card3, x + X_CARD_POSITION + CARD_WIDTH * 2, y + Y_CARD_POSITION);

	//DebugOutTitle(L"[CARD 1 2 3 hjhj] %d %d %d \n", card1, card2, card3);




	// WRITE UP
	int up = data->GetUp();
	if (up / 10 > 0) DrawNumber(up / 10, x + POSITION_UP_X, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber(up % 10, x + POSITION_UP_X + DISTANCE_NUMBER, y - ADJUST_Y_POWER_POSITION_UNDER);



	//WRITE COIN
	int coin = data->GetCoin();
	if (coin / 10 > 0) DrawNumber(coin / 10, x + POSITION_COIN_X, y - ADJUST_Y_POWER_POSITION);
	DrawNumber(coin % 10, x + POSITION_COIN_X + DISTANCE_NUMBER, y - ADJUST_Y_POWER_POSITION);
	//WRITE CLOCK
	DrawNumber(0, x + POSITION_CLOCK_X, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber(0, x + POSITION_CLOCK_X + DISTANCE_NUMBER, y - ADJUST_Y_POWER_POSITION_UNDER);
	DrawNumber(0, x + POSITION_CLOCK_X + DISTANCE_NUMBER * 2, y - ADJUST_Y_POWER_POSITION_UNDER);

	if (data->GetIsOver()) DrawGameOver();
	if (data->GetIsDisplayHUD()) DrawDisPlayHudSub();
	//DebugOutTitle(L"%d %d %d %d %d %d", data->GetIsOver(), data->GetIsPrepareContinue(), data->GetIsPrepareEnd(), data->GetIsContinue(), data->GetIsEnd(), data->GetIsDisplayHUD());
}


void CHUDWorldMap::DrawNumber(int n, float xTemp, float yTemp) {
	if (n == 0) CAnimations::GetInstance()->Get(ID_ANI_0)->Render(xTemp, yTemp);
	else if (n == 1) CAnimations::GetInstance()->Get(ID_ANI_1)->Render(xTemp, yTemp);
	else if (n == 2) CAnimations::GetInstance()->Get(ID_ANI_2)->Render(xTemp, yTemp);
	else if (n == 3) CAnimations::GetInstance()->Get(ID_ANI_3)->Render(xTemp, yTemp);
	else if (n == 4) CAnimations::GetInstance()->Get(ID_ANI_4)->Render(xTemp, yTemp);
	else if (n == 5) CAnimations::GetInstance()->Get(ID_ANI_5)->Render(xTemp, yTemp);
	else if (n == 6) CAnimations::GetInstance()->Get(ID_ANI_6)->Render(xTemp, yTemp);
	else if (n == 7) CAnimations::GetInstance()->Get(ID_ANI_7)->Render(xTemp, yTemp);
	else if (n == 8) CAnimations::GetInstance()->Get(ID_ANI_8)->Render(xTemp, yTemp);
	else  CAnimations::GetInstance()->Get(ID_ANI_9)->Render(xTemp, yTemp);
}

void CHUDWorldMap::DrawCard(int n, float xTemp, float yTemp) {

	if (n == HUD_CARD_MUSHROOM) CAnimations::GetInstance()->Get(ID_ANI_HUD_CARD_MUSHROOM)->Render(xTemp, yTemp);
	else if (n == HUD_CARD_FLOWER) CAnimations::GetInstance()->Get(ID_ANI_HUD_CARD_FLOWER)->Render(xTemp, yTemp);
	else if (n == HUD_CARD_STAR) CAnimations::GetInstance()->Get(ID_ANI_HUD_CARD_STAR)->Render(xTemp, yTemp);
	//else CAnimations::GetInstance()->Get(ID_ANI_HUD_CARD_MUSHROOM)->Render(xTemp, yTemp);
}

void CHUDWorldMap::DrawGameOver() {
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	CAnimations::GetInstance()->Get(ID_ANI_HUD_GAME_OVER)->Render(POSITION_X_HUD_GAME_OVER, POSITION_Y_HUD_GAME_OVER); 
	if (data->GetIsPrepareEnd()) {
		CAnimations::GetInstance()->Get(ID_ANI_NULL)->Render(POSITION_X_HUD_GAME_OVER + ADJUST_X_POSITION_ARROW, POSITION_Y_HUD_GAME_OVER + ADJUST_Y_POSITION_ARROW);
		CAnimations::GetInstance()->Get(ID_ANI_ARROW)->Render(POSITION_X_HUD_GAME_OVER + ADJUST_X_POSITION_ARROW, POSITION_Y_HUD_GAME_OVER + ADJUST_Y_POSITION_ARROW + DISTANCE_2_ARROW);
	}

}

void CHUDWorldMap::DrawDisPlayHudSub() {
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	CAnimations::GetInstance()->Get(ID_ANI_HUD_SUB)->Render(POSITION_X_HUD_GAME_OVER, POSITION_Y_HUD_GAME_OVER);
	DrawNumber(1, POSITION_X_HUD_GAME_OVER + ADJUST_X_NUMBER_WORLD, POSITION_Y_HUD_GAME_OVER + ADJUST_Y_NUMBER_WORLD );
	DrawNumber(0, POSITION_X_HUD_GAME_OVER + ADJUST_X_POSITION_NUMBER_HUD_SUB, POSITION_Y_HUD_GAME_OVER + ADJUST_Y_POSITION_NUMBER_HUD_SUB);
	DrawNumber(4, POSITION_X_HUD_GAME_OVER + ADJUST_X_POSITION_NUMBER_HUD_SUB +  DISTANCE_NUMBER, POSITION_Y_HUD_GAME_OVER + ADJUST_Y_POSITION_NUMBER_HUD_SUB);

}
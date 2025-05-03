#include "Player_ResultState.h"
#include "Scene.h"

void C_Player_ResultState::OnStart(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_ScoreManager* scoremanager = scene->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();

	scorecircle->SetLoadBulletFlg(false);
	a_pPlayer->SetPlayerSpeed(pDefaultSpd);
	a_pPlayer->SetDrawBulletPredictionFlg(false);
}

void C_Player_ResultState::OnUpdate(C_Player* a_pPlayer)
{
	a_pPlayer->SetMovDeg(a_pPlayer->GetPlayerSpeed());
	a_pPlayer->SetbMoveFlg(true);
}

void C_Player_ResultState::OnExit(C_Player* a_pPlayer)
{

}

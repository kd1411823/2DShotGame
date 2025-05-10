#include "Player_MoveState.h"
#include "Player_StandState.h"
#include "Player_LoadBulletState.h"
#include "Player_ResultState.h"
#include "Scene.h"

void C_Player_MoveState::OnStart(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_ScoreManager* scoremanager = scene->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();

	scorecircle->SetLoadBulletFlg(false);
	a_pPlayer->SetPlayerSpeed(pDefaultSpd);
	a_pPlayer->SetDrawBulletPredictionFlg(false);
}

void C_Player_MoveState::OnUpdate(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_Player_Circle* playercircle = scene->GetPlayer_Circle();

	if ((GetAsyncKeyState('D') & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000))
	{
		a_pPlayer->SetMovDeg(a_pPlayer->GetPlayerSpeed());
		a_pPlayer->SetbMoveFlg(true);
	}
	else if ((GetAsyncKeyState('A') & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000))
	{
		a_pPlayer->SetMovDeg(-(a_pPlayer->GetPlayerSpeed()));
		a_pPlayer->SetbMoveFlg(true);
	}
	else
	{
		m_pMachine->ChangeState<C_Player_StandState>();
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_pMachine->ChangeState<C_Player_LoadBulletState>();
	}
	
	// リザルトになったらステートを変更
	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_pMachine->ChangeState<C_Player_ResultState>();
	}


}

void C_Player_MoveState::OnExit(C_Player* a_pPlayer)
{

}

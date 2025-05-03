#include "Enemy_HighMoveState.h"
#include "Enemy_StandState.h"
#include "Scene.h"

void C_Enemy_HighMoveState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Enemy_SquareFrame* enemysquareframe = a_pEnemy->GetEnemySquareFrame();
	enemysquareframe->SetStopFlg(false);
	m_highmoveStateCnt = systm->RndBtwn(20, 60); // 早く動く状態のステートカウント
	m_dir = (eEnemyMovDir)systm->RndBtwn(LeftDir, RightDir); // 動く方向
	a_pEnemy->SetbMoveFlg(true);
}

void C_Enemy_HighMoveState::OnUpdate(C_Enemy* a_pEnemy)
{
	m_highmoveStateCnt--;

	switch (m_dir)
	{
	case LeftDir:
		a_pEnemy->SetMovDeg(-eHighSpd);
		break;
	case RightDir:
		a_pEnemy->SetMovDeg(eHighSpd);
		break;
	}

	if (m_highmoveStateCnt <= 0)
	{
		m_pMachine->ChangeState<C_Enemy_StandState>();
	}
}

void C_Enemy_HighMoveState::OnExit(C_Enemy* a_pEnemy)
{
}

#include "Enemy_MoveState.h"
#include "Enemy_StandState.h"
#include "Scene.h"

void C_Enemy_MoveState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Enemy_SquareFrame* enemysquareframe = a_pEnemy->GetEnemySquareFrame();
	enemysquareframe->SetStopFlg(false);
	m_moveStateCnt = systm->RndBtwn(30, 100); // 動く状態のステートカウント
	m_dir = (eEnemyMovDir)systm->RndBtwn(LeftDir,RightDir); // 動く方向
	a_pEnemy->SetbMoveFlg(true);
}

void C_Enemy_MoveState::OnUpdate(C_Enemy* a_pEnemy)
{
	m_moveStateCnt--;

	switch (m_dir)
	{
	case LeftDir:
		a_pEnemy->SetMovDeg(-eDefaultSpd);
		break;
	case RightDir:
		a_pEnemy->SetMovDeg(eDefaultSpd);
		break;
	}
	
	if (m_moveStateCnt <= 0)
	{
		m_pMachine->ChangeState<C_Enemy_StandState>();
	}

	

}

void C_Enemy_MoveState::OnExit(C_Enemy* a_pEnemy)
{
}

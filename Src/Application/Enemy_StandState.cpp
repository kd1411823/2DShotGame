#include "Enemy_StandState.h"
#include "Enemy_ShotState.h"
#include "Scene.h"

void C_Enemy_StandState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Enemy_SquareFrame* enemysquareframe = a_pEnemy->GetEnemySquareFrame();
	enemysquareframe->SetStopFlg(true);
	m_standStateCnt = systm->RndBtwn(60,580); // 通常状態のステートカウント
	a_pEnemy->SetMovDeg(0);
	a_pEnemy->SetbMoveFlg(false);
}

void C_Enemy_StandState::OnUpdate(C_Enemy* a_pEnemy)
{
	m_standStateCnt--;

	if (m_standStateCnt <= 0)
	{
		m_pMachine->ChangeState<C_Enemy_ShotState>();
	}


}

void C_Enemy_StandState::OnExit(C_Enemy* a_pEnemy)
{

}

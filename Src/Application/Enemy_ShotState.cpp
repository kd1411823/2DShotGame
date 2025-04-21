#include "Enemy_ShotState.h"
#include "Enemy_MoveState.h"
#include "Enemy_HighMoveState.h"
#include "Scene.h"

void C_Enemy_ShotState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	m_shotStateCnt = systm->RndBtwn(90, 180); // 撃つ状態のステート
	m_movepattern = (eEnemyMovCmd)systm->RndBtwn(DefaultMov,HighMov);  // 動くパターン
}

void C_Enemy_ShotState::OnUpdate(C_Enemy* a_pEnemy)
{
	C_Bullet* bullet[ebulletNum];

	m_shotStateCnt--;




	if (m_shotStateCnt <= 0)
	{
		switch (m_movepattern)
		{
		case DefaultMov:
			m_pMachine->ChangeState<C_Enemy_MoveState>();
			break;
		case HighMov:
			m_pMachine->ChangeState<C_Enemy_HighMoveState>();
			break;
		}
	}
}

void C_Enemy_ShotState::OnExit(C_Enemy* a_pEnemy)
{
}

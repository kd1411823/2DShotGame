#include "Enemy_TitleState.h"

void C_Enemy_TitleState::OnStart(C_Enemy* a_pEnemy)
{
	a_pEnemy->SetbMoveFlg(true);
}

void C_Enemy_TitleState::OnUpdate(C_Enemy* a_pEnemy)
{
	a_pEnemy->SetMovDeg(eDefaultSpd);
}

void C_Enemy_TitleState::OnExit(C_Enemy* a_pEnemy)
{
}

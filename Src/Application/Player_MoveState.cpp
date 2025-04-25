#include "Player_MoveState.h"
#include "Player_StandState.h"
#include "Player_LoadBulletState.h"

void C_Player_MoveState::OnStart(C_Player* a_pPlayer)
{
	a_pPlayer->SetPlayerSpeed(pDefaultSpd);
}

void C_Player_MoveState::OnUpdate(C_Player* a_pPlayer)
{

	if (GetAsyncKeyState('D') & 0x8000)
	{
		a_pPlayer->SetMovDeg(a_pPlayer->GetPlayerSpeed());
		a_pPlayer->SetbMoveFlg(true);
	}
	else if (GetAsyncKeyState('A') & 0x8000)
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
	
}

void C_Player_MoveState::OnExit(C_Player* a_pPlayer)
{

}

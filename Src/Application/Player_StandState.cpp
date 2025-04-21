#include "Player_StandState.h"
#include "Player_MoveState.h"
#include "Player_LoadBulletState.h"

void C_Player_StandState::OnStart(C_Player* a_pPlayer)
{
	a_pPlayer->SetMovDeg(0.0f);
}

void C_Player_StandState::OnUpdate(C_Player* a_pPlayer)
{

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pMachine->ChangeState<C_Player_MoveState>();
	}
	else if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pMachine->ChangeState<C_Player_MoveState>();
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

void C_Player_StandState::OnExit(C_Player* a_pPlayer)
{
}

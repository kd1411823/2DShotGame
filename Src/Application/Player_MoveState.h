#pragma once
#include "StateBase.h"
#include "Player.h"

class C_Player_MoveState :public C_StateBase<C_Player>
{
public:

	void OnStart(C_Player* a_pPlayer)override;
	void OnUpdate(C_Player* a_pPlayer)override;
	void OnExit(C_Player* a_pPlayer)override;


};
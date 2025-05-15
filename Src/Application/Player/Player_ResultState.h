#pragma once
#include "../GameSystem/StateBase.h"
#include "Player.h"

class C_Player_ResultState :public C_StateBase<C_Player>
{
public:

	void OnStart(C_Player* a_pPlayer)override;
	void OnUpdate(C_Player* a_pPlayer)override;
	void OnExit(C_Player* a_pPlayer)override;

private:

};
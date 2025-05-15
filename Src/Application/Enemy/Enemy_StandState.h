#pragma once
#include "../GameSystem/StateBase.h"
#include "Enemy.h"

class C_Enemy_StandState :public C_StateBase<C_Enemy>
{
public:

	void OnStart(C_Enemy* a_pEnemy)override;
	void OnUpdate(C_Enemy* a_pEnemy)override;
	void OnExit(C_Enemy* a_pEnemy)override;

private:

	int m_standStateCnt; // 通常状態のステートカウント
};
#pragma once
#include "../GameSystem/StateBase.h"
#include "Enemy.h"

class C_Enemy_MoveState :public C_StateBase<C_Enemy>
{
public:

	void OnStart(C_Enemy* a_pEnemy)override;
	void OnUpdate(C_Enemy* a_pEnemy)override;
	void OnExit(C_Enemy* a_pEnemy)override;

private:

	int m_moveStateCnt; // 動く状態のステートカウント
	eEnemyMovDir m_dir; // 動く方向
};
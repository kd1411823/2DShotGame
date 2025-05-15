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

	int m_moveStateCnt; // ������Ԃ̃X�e�[�g�J�E���g
	eEnemyMovDir m_dir; // ��������
};
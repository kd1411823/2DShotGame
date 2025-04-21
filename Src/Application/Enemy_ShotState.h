#pragma once
#include "StateBase.h"
#include "Enemy.h"

class C_Enemy_ShotState :public C_StateBase<C_Enemy>
{
public:

	void OnStart(C_Enemy* a_pEnemy)override;
	void OnUpdate(C_Enemy* a_pEnemy)override;
	void OnExit(C_Enemy* a_pEnemy)override;

private:

	int m_shotStateCnt; // ����Ԃ̃X�e�[�g
	eEnemyMovCmd m_movepattern;  // �����p�^�[��
};
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

	int m_shotStateCnt; // 撃つ状態のステート
	eEnemyMovCmd m_movepattern;  // 動くパターン
	eEnemyMovDir m_dir;	// 動く方向
	bool m_shotEndFlg;  // 撃ち終わったかフラグ
	int  m_shotIntervalCnt; // 弾の間隔カウント
};
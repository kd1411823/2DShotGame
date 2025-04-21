#pragma once
#include "StateBase.h"
#include "Player.h"

class C_Player_ShotBulletState :public C_StateBase<C_Player>
{
public:

	void OnStart(C_Player* a_pPlayer)override;
	void OnUpdate(C_Player* a_pPlayer)override;
	void OnExit(C_Player* a_pPlayer)override;

private:

	bool m_shotEndFlg;  // 撃ち終わったかフラグ
	int  m_shotIntervalCnt; // 弾の間隔カウント
};
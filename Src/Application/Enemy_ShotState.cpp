#include "Enemy_ShotState.h"
#include "Enemy_MoveState.h"
#include "Enemy_HighMoveState.h"
#include "Scene.h"

void C_Enemy_ShotState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Bullet* bullet[ebulletNum];
	// すべて装填済みにする
	for (int i = 0;i < ebulletNum;i++)
	{
		bullet[i] = a_pEnemy->GetBullet(i);

		bullet[i]->SetLoadOkFlg(true);
	}
	m_shotStateCnt = systm->RndBtwn(60, 120); // 撃つ状態のステート
	m_movepattern = (eEnemyMovCmd)systm->RndBtwn(DefaultMov,HighMov);  // 動くパターン
	m_dir = (eEnemyMovDir)systm->RndBtwn(LeftDir,RightDir);	// 動く方向
	m_shotEndFlg = false;  // 撃ち終わったかフラグ
	m_shotIntervalCnt = 0; // 弾の間隔カウント
}

void C_Enemy_ShotState::OnUpdate(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Bullet* bullet[ebulletNum];
	for (int i = 0;i < ebulletNum;i++)bullet[i] = a_pEnemy->GetBullet(i);

	// 弾間隔カウント加算
	m_shotIntervalCnt++;
	m_shotStateCnt--;

	// 左右移動する(ゆっくり)
	switch (m_dir)
	{
	case LeftDir:
		a_pEnemy->SetMovDeg(-eSlowSpd);
		break;
	case RightDir:
		a_pEnemy->SetMovDeg(eSlowSpd);
		break;
	}


	if (!m_shotEndFlg)
	{
		for (int i = 0;i < ebulletNum;i++)
		{
			// 弾が発射していない
			if (!bullet[i]->GetAlive() && bullet[i]->GetLoadOkFlg())
			{
				// 弾の間隔制御
				if (m_shotIntervalCnt > ShotInterval)
				{
					// カウントリセットし、弾を発射する
					m_shotIntervalCnt = 0;
					bullet[i]->ShotBullet(a_pEnemy->GetPos(), systm->GetDeg(initPos, a_pEnemy->GetPos()), a_pEnemy->GetEBulletSpdScl());
					break;
				}
			}
		}
	}

	// すべて装填フラグがfalse(準備状態)になったらendflgをtrueにする
	m_shotEndFlg = std::all_of(bullet, bullet + ebulletNum, [](auto* b) { return !b->GetLoadOkFlg(); });


	if (m_shotStateCnt <= 0 && m_shotEndFlg)
	{
		switch (m_movepattern)
		{
		case DefaultMov:
			m_pMachine->ChangeState<C_Enemy_MoveState>();
			break;
		case HighMov:
			m_pMachine->ChangeState<C_Enemy_HighMoveState>();
			break;
		}
	}
}

void C_Enemy_ShotState::OnExit(C_Enemy* a_pEnemy)
{
}

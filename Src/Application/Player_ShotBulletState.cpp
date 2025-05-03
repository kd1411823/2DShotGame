#include "Player_ShotBulletState.h"
#include "Player_StandState.h"
#include "Player_ResultState.h"
#include "Scene.h"

void C_Player_ShotBulletState::OnStart(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_ScoreManager* scoremanager = scene->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();

	scorecircle->SetLoadBulletFlg(false);
	a_pPlayer->SetPlayerSpeed(pSlowSpd); // 通常のスピードに戻す
	a_pPlayer->SetDrawBulletPredictionFlg(false);
	m_shotEndFlg = false;  // 撃ち終わったかフラグ
	m_shotIntervalCnt = 0; // 弾の間隔カウント
}

void C_Player_ShotBulletState::OnUpdate(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Player_Circle* playercircle = scene->GetPlayer_Circle();
	C_Bullet* bullet[BulletNum];
	C_Drop_Bullet* dropbullet[DropBulletNum];
	for (int i = 0;i < BulletNum;i++)bullet[i] = a_pPlayer->GetBullet(i);
	for (int j = 0;j < DropBulletNum;j++)dropbullet[j] = a_pPlayer->GetDropBullet(j);

	// 弾間隔カウント加算
	m_shotIntervalCnt++;

	// 移動
	if (GetAsyncKeyState('D') & 0x8000)
	{
		a_pPlayer->SetMovDeg(a_pPlayer->GetPlayerSpeed());
		a_pPlayer->SetbMoveFlg(true);
	}
	else if (GetAsyncKeyState('A') & 0x8000)
	{
		a_pPlayer->SetMovDeg(-(a_pPlayer->GetPlayerSpeed()));
		a_pPlayer->SetbMoveFlg(true);
	}

	// リザルトになったらステートを変更
	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_pMachine->ChangeState<C_Player_ResultState>();
	}


	// 弾を貯めるフェーズ終了(弾取得オブジェクトを表示)
	for (int j = 0;j < DropBulletNum;j++)
	{
		dropbullet[j]->SetAlive(true);
	}

	for (int i = 0;i < BulletNum;i++)
	{
		// 弾が発射していなく、load出来ている
		if (!bullet[i]->GetAlive() && bullet[i]->GetLoadOkFlg())
		{
			// 弾の間隔制御
			if (m_shotIntervalCnt > ShotInterval)
			{
				// カウントリセットし、弾を発射する
				m_shotIntervalCnt = 0;
				bullet[i]->ShotBullet(a_pPlayer->GetPos(), systm->GetDeg(initPos, a_pPlayer->GetPos()));
				break;
			}
		}
	}
	
	// すべて装填フラグがfalse(準備状態)になったらendflgをtrueにする
	m_shotEndFlg = std::all_of(bullet, bullet + BulletNum, [](auto* b) { return !b->GetLoadOkFlg(); });

	// 撃ち終わったら待機状態へ
	if (m_shotEndFlg)
	{
		m_pMachine->ChangeState<C_Player_StandState>();
	}
}

void C_Player_ShotBulletState::OnExit(C_Player* a_pPlayer)
{

}

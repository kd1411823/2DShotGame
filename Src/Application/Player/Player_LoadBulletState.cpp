#include "Player_LoadBulletState.h"
#include "Player_ShotBulletState.h"
#include "Player_ResultState.h"
#include "../Scene/Scene.h"

void C_Player_LoadBulletState::OnStart(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_ScoreManager* scoremanager = scene->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Player_BulletPredictionLine* playerbulletpredictionline[pBulletLineNum];
	for (int i = 0; i < pBulletLineNum;i++)
	{
		playerbulletpredictionline[i] = a_pPlayer->GetPlayerBulletPredictionLine(i);
	}
	C_Player_BulletPredictionTriangle* playerbulletpredictiontriangle = a_pPlayer->GetPlayerBulletPredictionTriangle();

	for (int i = 0; i < pBulletLineNum;i++)
	{
		playerbulletpredictionline[i]->SetClr({ GREEN, 1.0f });
	}

	playerbulletpredictiontriangle->SetClr({ GREEN, 1.0f });

	scorecircle->SetLoadBulletFlg(true);
	a_pPlayer->SetPlayerSpeed(pHighSpd);
	a_pPlayer->SetDrawBulletPredictionFlg(true);
}

void C_Player_LoadBulletState::OnUpdate(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Player_Circle* playercircle = scene->GetPlayer_Circle();
	C_Drop_Bullet* dropbullet[DropBulletNum];
	C_Player_AfterImage* playerafterimage[afterImageNum];


	for (int i = 0;i < DropBulletNum;i++)
	{
		dropbullet[i] = a_pPlayer->GetDropBullet(i);
	}

	for (int i = 0;i < afterImageNum;i++)
	{
		playerafterimage[i] = a_pPlayer->GetPlayerAfterImage(i);
	}
	
	
	for (int i = 0;i < afterImageNum; i++)
	{
		if (!playerafterimage[i]->GetAlive())
		{	
			if (a_pPlayer->GetAfterImageTimer() > afterImageInterval)
			{
				a_pPlayer->SetAfterImageTimer(0);
				playerafterimage[i]->Emit(a_pPlayer->GetPos(),
					a_pPlayer->GetMov(),
					a_pPlayer->GetScl(),
					a_pPlayer->GetRot(),
					true,
					40,
					false,
					{ 0,0,BIT256,BIT256 },
					{ GREEN, 0.8f }
				);
				break;
			}
		}
	}
	// 移動
	if ((GetAsyncKeyState('D') & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000))
	{
		a_pPlayer->SetMovDeg(a_pPlayer->GetPlayerSpeed());
		a_pPlayer->SetbMoveFlg(true);
	}
	else if ((GetAsyncKeyState('A') & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000))
	{
		a_pPlayer->SetMovDeg(-(a_pPlayer->GetPlayerSpeed()));
		a_pPlayer->SetbMoveFlg(true);
	}

	// スペースキーを離すと撃つフェーズ移行
	if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		m_pMachine->ChangeState<C_Player_ShotBulletState>();
	}

	// リザルトになったらステートを変更
	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_pMachine->ChangeState<C_Player_ResultState>();
	}

	// 弾(取得オブジェクト)とプレイヤーの当たり判定
	for (int i = 0;i < DropBulletNum;i++)
	{
		// 取得されたものは飛ばす
		if (!dropbullet[i]->GetAlive())continue;

		const tTry PlayerBulletDis = systm->CalcPythag(a_pPlayer->GetPos(), dropbullet[i]->GetPos());

		const float playerBullethypn = a_pPlayer->GetRadius() + dropbullet[i]->GetDropBulletRadius();

		if (PlayerBulletDis.hypn < playerBullethypn)
		{
			dropbullet[i]->CountHIT();
		}
	}

}

void C_Player_LoadBulletState::OnExit(C_Player* a_pPlayer)
{
}


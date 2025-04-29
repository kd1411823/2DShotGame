#include "Player_LoadBulletState.h"
#include "Player_ShotBulletState.h"
#include "Scene.h"

void C_Player_LoadBulletState::OnStart(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_ScoreManager* scoremanager = scene->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();

	scorecircle->SetLoadBulletFlg(true);
	a_pPlayer->SetPlayerSpeed(pHighSpd);
	a_pPlayer->SetDrawBulletPredictionFlg(true);
}

void C_Player_LoadBulletState::OnUpdate(C_Player* a_pPlayer)
{
	Scene* scene = a_pPlayer->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Drop_Bullet* dropbullet[DropBulletNum];
	for (int i = 0;i < DropBulletNum;i++)
	{
		dropbullet[i] = a_pPlayer->GetDropBullet(i);
	}

	// �ړ�
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

	// �X�y�[�X�L�[�𗣂��ƌ��t�F�[�Y�ڍs
	if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		m_pMachine->ChangeState<C_Player_ShotBulletState>();
	}

	// �e(�擾�I�u�W�F�N�g)�ƃv���C���[�̓����蔻��
	for (int i = 0;i < DropBulletNum;i++)
	{
		// �擾���ꂽ���͔̂�΂�
		if (!dropbullet[i]->GetAlive())continue;

		const tTry PlayerBulletDis = systm->CalcPythag(a_pPlayer->GetPos(), dropbullet[i]->GetPos());

		const float playerBullethypn = a_pPlayer->GetRadius() + dropbullet[i]->GetDropBulletRadius();

		if (PlayerBulletDis.hypn < playerBullethypn)
		{
			dropbullet[i]->Hit();
		}
	}

}

void C_Player_LoadBulletState::OnExit(C_Player* a_pPlayer)
{
}


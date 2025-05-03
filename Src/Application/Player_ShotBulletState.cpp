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
	a_pPlayer->SetPlayerSpeed(pSlowSpd); // �ʏ�̃X�s�[�h�ɖ߂�
	a_pPlayer->SetDrawBulletPredictionFlg(false);
	m_shotEndFlg = false;  // �����I��������t���O
	m_shotIntervalCnt = 0; // �e�̊Ԋu�J�E���g
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

	// �e�Ԋu�J�E���g���Z
	m_shotIntervalCnt++;

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

	// ���U���g�ɂȂ�����X�e�[�g��ύX
	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_pMachine->ChangeState<C_Player_ResultState>();
	}


	// �e�𒙂߂�t�F�[�Y�I��(�e�擾�I�u�W�F�N�g��\��)
	for (int j = 0;j < DropBulletNum;j++)
	{
		dropbullet[j]->SetAlive(true);
	}

	for (int i = 0;i < BulletNum;i++)
	{
		// �e�����˂��Ă��Ȃ��Aload�o���Ă���
		if (!bullet[i]->GetAlive() && bullet[i]->GetLoadOkFlg())
		{
			// �e�̊Ԋu����
			if (m_shotIntervalCnt > ShotInterval)
			{
				// �J�E���g���Z�b�g���A�e�𔭎˂���
				m_shotIntervalCnt = 0;
				bullet[i]->ShotBullet(a_pPlayer->GetPos(), systm->GetDeg(initPos, a_pPlayer->GetPos()));
				break;
			}
		}
	}
	
	// ���ׂđ��U�t���O��false(�������)�ɂȂ�����endflg��true�ɂ���
	m_shotEndFlg = std::all_of(bullet, bullet + BulletNum, [](auto* b) { return !b->GetLoadOkFlg(); });

	// �����I�������ҋ@��Ԃ�
	if (m_shotEndFlg)
	{
		m_pMachine->ChangeState<C_Player_StandState>();
	}
}

void C_Player_ShotBulletState::OnExit(C_Player* a_pPlayer)
{

}

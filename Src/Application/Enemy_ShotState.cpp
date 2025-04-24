#include "Enemy_ShotState.h"
#include "Enemy_MoveState.h"
#include "Enemy_HighMoveState.h"
#include "Scene.h"

void C_Enemy_ShotState::OnStart(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Bullet* bullet[ebulletNum];
	// ���ׂđ��U�ς݂ɂ���
	for (int i = 0;i < ebulletNum;i++)
	{
		bullet[i] = a_pEnemy->GetBullet(i);

		bullet[i]->SetLoadOkFlg(true);
	}
	m_shotStateCnt = systm->RndBtwn(60, 120); // ����Ԃ̃X�e�[�g
	m_movepattern = (eEnemyMovCmd)systm->RndBtwn(DefaultMov,HighMov);  // �����p�^�[��
	m_dir = (eEnemyMovDir)systm->RndBtwn(LeftDir,RightDir);	// ��������
	m_shotEndFlg = false;  // �����I��������t���O
	m_shotIntervalCnt = 0; // �e�̊Ԋu�J�E���g
}

void C_Enemy_ShotState::OnUpdate(C_Enemy* a_pEnemy)
{
	Scene* scene = a_pEnemy->GetPowner();
	C_Systm* systm = scene->GetSystm();
	C_Bullet* bullet[ebulletNum];
	for (int i = 0;i < ebulletNum;i++)bullet[i] = a_pEnemy->GetBullet(i);

	// �e�Ԋu�J�E���g���Z
	m_shotIntervalCnt++;
	m_shotStateCnt--;

	// ���E�ړ�����(�������)
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
			// �e�����˂��Ă��Ȃ�
			if (!bullet[i]->GetAlive() && bullet[i]->GetLoadOkFlg())
			{
				// �e�̊Ԋu����
				if (m_shotIntervalCnt > ShotInterval)
				{
					// �J�E���g���Z�b�g���A�e�𔭎˂���
					m_shotIntervalCnt = 0;
					bullet[i]->ShotBullet(a_pEnemy->GetPos(), systm->GetDeg(initPos, a_pEnemy->GetPos()), a_pEnemy->GetEBulletSpdScl());
					break;
				}
			}
		}
	}

	// ���ׂđ��U�t���O��false(�������)�ɂȂ�����endflg��true�ɂ���
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

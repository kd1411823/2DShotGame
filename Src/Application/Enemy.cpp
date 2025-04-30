#include "Enemy.h"
#include "Enemy_StandState.h"
#include "Sun.h"
#include "Scene.h"

C_Enemy::C_Enemy()
{
	
}

C_Enemy::~C_Enemy()
{
	enemyTex.Release();
	hpCircleTex.Release();
	frameCircleTex.Release();
	ebulletTex.Release();
}

void C_Enemy::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_EnemyManager* enemymanager = m_p0wner->GetEnemyManager();

	// ���������ɃC���X�^���X�̃|�C���^��n��
	m_stateMachine.Start(this);

	// ������Ԃ̃X�e�[�g���Z�b�g
	m_stateMachine.ChangeState<C_Enemy_StandState>();

	enemyTex.Load("Texture/enemy.png");
	hpCircleTex.Load("Texture/enemyhpcircle.png");
	frameCircleTex.Load("Texture/enemycircle.png");
	ebulletTex.Load("Texture/ebullet.png");

	// �e(�G)�̏�����
	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].SetTex(&ebulletTex);
		m_bullet[i].SetP0wner(m_p0wner);
		m_bullet[i].Init();
	}

	// �G��HP�~������
	m_enemyhpCircle.SetTex(&hpCircleTex);
	m_enemyhpCircle.SetP0wner(m_p0wner);
	m_enemyhpCircle.Init();

	
	m_enemyframeCircle.SetTex(&frameCircleTex);
	m_enemyframeCircle.SetP0wner(m_p0wner);
	m_enemyframeCircle.Init();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	// �����o�ϐ�
	m_enemyHitpoint = EnemyHp;						// �G��HP
	m_damagePoint	= 1.0f;							// �_���[�W��
	m_autoRecoveryRate = 0.02f;	// ���R�񕜗�
	m_deg			= systm->RndBtwn(0, 360);		// �p�x
	m_movDeg		= 0;							// �ړ���(�p�x)
	m_circleRadius	= FourRadius;					// �~�̔��a
	m_ebulletSpdScl = 0.4f;							// �G�̒e�̃X�s�[�h�{��
	m_bMoveFlg = false;		// �����Ă��邩�t���O
	m_isRisingScl= false;		// �G�̂̊g�嗦�����t���O
	m_deltaScl = 0.013f;				// �G�̊g�嗦������
	m_maxDeltaScl= 0.0f;			// �ő�G�̊g�嗦
	m_minDeltaScl= 0.0f;			// �ŏ��G�̊g�嗦
	m_sclInitFlg= false;			// �g�嗦�������t���O

	// �I�u�W�F�N�g������
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { EnemyBaseScl ,EnemyBaseScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.pTex = &enemyTex;
	m_bsst.draw.rct = { 0, 0, BIT64, BIT64 };
	m_bsst.draw.clr = { RED ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Draw()
{

	D3D.SetBlendState(BlendMode::Add);

	m_sun->Draw();

	D3D.SetBlendState(BlendMode::Alpha);

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	
	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Draw();
	}

	m_enemyhpCircle.Draw(m_bsst.alive);

	m_enemyframeCircle.Draw(m_bsst.alive);
}

void C_Enemy::Update()
{
	if (!m_bsst.alive)return;

	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_deg += m_movDeg;

	m_movDeg = 0;

	m_sun->Update(m_bsst.pos,{ 2.0f,2.0f},{ RED,1.0f });

	m_enemyhpCircle.Update(m_bsst.alive, m_bsst.pos);

	m_enemyframeCircle.Update(m_bsst.pos,m_bsst.alive);

	m_stateMachine.Update();

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Update();
	}

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Action()
{
	if (!m_bsst.alive)return;

	C_Systm* systm = m_p0wner->GetSystm();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();

	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;

	ScaleManager();

	EnemyBulletPlayerCircleHit();
	// �̗͂������Ă����玩�R�񕜂���
	if (m_enemyHitpoint > 0.0f && m_enemyHitpoint < EnemyHp)
	{
		m_enemyHitpoint += m_autoRecoveryRate;
	}

	printf("%.2f\n", m_enemyHitpoint);



	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Action();
	}

	m_enemyhpCircle.Action(m_bsst.alive,m_enemyHitpoint);

	m_enemyframeCircle.Action(m_bsst.alive);
}

void C_Enemy::ScaleManager()
{
	if (m_bMoveFlg)
	{
		m_maxDeltaScl = EnemyBaseScl + 0.1f;
		m_minDeltaScl = EnemyBaseScl - 0.1f;
		m_sclInitFlg = false;
	}
	else
	{
		if (!m_sclInitFlg)
		{
			m_maxDeltaScl = EnemyBaseScl + 0.05f;
			m_minDeltaScl = EnemyBaseScl - 0.05f;
			m_sclInitFlg = true;
		}

		if (m_maxDeltaScl > EnemyBaseScl)
		{
			m_maxDeltaScl -= 0.0005f;
		}
		else
		{
			m_maxDeltaScl = EnemyBaseScl;
		}

		if (m_minDeltaScl < EnemyBaseScl)
		{
			m_minDeltaScl += 0.0005f;
		}
		else
		{
			m_minDeltaScl = EnemyBaseScl;
		}
	}


	if (m_bsst.scl.x >= m_maxDeltaScl && m_bsst.scl.y <= m_minDeltaScl)
	{
		m_isRisingScl = false;
	}

	if (m_bsst.scl.x <= m_minDeltaScl && m_bsst.scl.y >= m_maxDeltaScl)
	{
		m_isRisingScl = true;
	}

	if (m_maxDeltaScl != EnemyBaseScl && m_minDeltaScl != EnemyBaseScl)
	{
		if (m_isRisingScl)
		{
			m_bsst.scl.x += m_deltaScl;
			m_bsst.scl.y -= m_deltaScl;
		}
		else
		{
			m_bsst.scl.x -= m_deltaScl;
			m_bsst.scl.y += m_deltaScl;
		}
	}
	printf("%d\n", m_bMoveFlg);
}

void C_Enemy::EnemyBulletPlayerCircleHit()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();

	for (int i = 0;i < ebulletNum;i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const tTry enemybulletPlayercircletTry = systm->CalcPythag(initPos, m_bullet[i].GetPos());

		const float bulletCirclehypn =  m_bullet[i].GetRadius() + playercircle->GetCircleRadius();

		if (enemybulletPlayercircletTry.hypn < bulletCirclehypn)
		{
			if (scoremanager->GetScore() > 0)
			{
				scoremanager->DecreaseScore();
			}
			m_bullet[i].Hit();
		}
		
	}
}

void C_Enemy::TakeDamage()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();

	// HP���_���[�W�����炷
	m_enemyHitpoint -= m_damagePoint;

	if (m_enemyHitpoint <= 0.0f)
	{
		scoremanager->AddScore();
		m_bsst.alive = false;	
	}
}

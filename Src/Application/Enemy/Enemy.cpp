#include "Enemy.h"
#include "Enemy_StandState.h"
#include "Enemy_TitleState.h"
#include "../Particle/Sun.h"
#include "../Scene/Scene.h"

C_Enemy::C_Enemy()
{
}

C_Enemy::~C_Enemy()
{
	enemyTex.Release();
	hpCircleTex.Release();
	frameCircleTex.Release();
	ebulletTex.Release();
	squareframeTex.Release();
}

void C_Enemy::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_EnemyManager* enemymanager = m_p0wner->GetEnemyManager();

	// ���������ɃC���X�^���X�̃|�C���^��n��
	m_stateMachine.Start(this);

	// ������Ԃ̃X�e�[�g���Z�b�g
	if (m_p0wner->GetSceneType() == GameScene)
	{
		m_stateMachine.ChangeState<C_Enemy_StandState>();
	}
	else if (m_p0wner->GetSceneType() == TitleScene)
	{
		m_stateMachine.ChangeState<C_Enemy_TitleState>();
	}

	enemyTex.Load("Texture/enemy.png");
	hpCircleTex.Load("Texture/enemyhpcircle.png");
	frameCircleTex.Load("Texture/enemycircle.png");
	ebulletTex.Load("Texture/bullet.png");
	squareframeTex.Load("Texture/enemysquareframe.png");

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

	// �G��HP�~(�t���[��)
	m_enemyframeCircle.SetTex(&frameCircleTex);
	m_enemyframeCircle.SetP0wner(m_p0wner);
	m_enemyframeCircle.Init();

	// �G�p�[�e�B�N��
	for (int i = 0;i < squareParticleNum;i++)
	{
		m_enemysquareParticle[i].SetP0wner(m_p0wner);
		m_enemysquareParticle[i].SetTex(&enemyTex);
		m_enemysquareParticle[i].Init();
	}

	// �G�p�[�e�B�N��(HIT��)
	for (int i = 0; i < hitParticleNum;i++)
	{
		m_enemyhitParticle[i].SetP0wner(m_p0wner);
		m_enemyhitParticle[i].SetTex(&enemyTex);
		m_enemyhitParticle[i].Init();
	}

	// �G�l�p�`�t���[��
	m_enemySquareFrame.SetP0wner(m_p0wner);
	m_enemySquareFrame.SetTex(&squareframeTex);
	m_enemySquareFrame.Init();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	// �����o�ϐ�
	m_enemyHitpoint    = EnemyHp;						// �G��HP
	m_damagePoint	   = 1.0f;							// �_���[�W��
	m_autoRecoveryRate = 0.02f;							// ���R�񕜗�
	m_deg			   = systm->RndBtwn(0, 360);		// �p�x
	m_movDeg		   = 0;								// �ړ���(�p�x)
	m_circleRadius	   = FourRadius;					// �~�̔��a
	m_ebulletSpdScl    = 0.4f;							// �G�̒e�̃X�s�[�h�{��
	m_bMoveFlg         = false;							// �����Ă��邩�t���O
	m_isRisingScl      = false;							// �G�̂̊g�嗦�����t���O
	m_deltaScl         = 0.013f;						// �G�̊g�嗦������
	m_maxDeltaScl      = 0.0f;							// �ő�G�̊g�嗦
	m_minDeltaScl      = 0.0f;							// �ŏ��G�̊g�嗦
	m_sclInitFlg       = false;							// �g�嗦�������t���O

	// �I�u�W�F�N�g������
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.mov   = { 0,0 };
	m_bsst.scl   = { EnemyBaseScl ,EnemyBaseScl };
	m_bsst.rot   = 0;
	m_bsst.alive = true;
	m_bsst.draw.pTex = &enemyTex;
	m_bsst.draw.rct  = { 0, 0, BIT64, BIT64 };
	m_bsst.draw.clr  = { RED ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Draw()
{

	D3D.SetBlendState(BlendMode::Add);

	m_sun->Draw();

	for (int i = 0;i < squareParticleNum;i++)
	{
		m_enemysquareParticle[i].Draw();
	}

	for (int i = 0; i < hitParticleNum;i++)
	{
		m_enemyhitParticle[i].Draw();
	}

	D3D.SetBlendState(BlendMode::Alpha);

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	
	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Draw();
	}

	m_enemyhpCircle.Draw(m_bsst.alive);

	m_enemyframeCircle.Draw(m_bsst.alive);

	m_enemySquareFrame.Draw();
}

void C_Enemy::Update()
{
	if (!m_bsst.alive)return;

	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_deg += m_movDeg;

	m_movDeg = 0;

	m_sun->Update(m_bsst.pos,{ 3.0f,3.0f},{ RED,1.0f });

	// �����Ă���Ƃ��Ƀp�[�e�B�N����\������
	if (m_bMoveFlg)
	{
		for (int i = 0;i < squareParticleNum; i++)
		{
			if (!m_enemysquareParticle[i].GetAlive())
			{
				m_enemysquareParticle[i].Emit(
					{ 0, 0 },
					{ 0 ,0 },
					{ 0.0f ,0.0f },
					0.0f,
					true,
					0,
					true,
					{ 0,0,0,0 },
					{ 0.0f,0.0f,0.0f,0.0f }
				);
			}
		}
	}

	for (int i = 0;i < squareParticleNum;i++)
	{
		m_enemysquareParticle[i].Update(m_bsst.pos, m_bMoveFlg);
	}

	for (int i = 0; i < hitParticleNum;i++)
	{
		m_enemyhitParticle[i].Update(m_bsst.pos, m_bMoveFlg);
	}

	m_enemyhpCircle.Update(m_bsst.alive, m_bsst.pos);

	m_enemyframeCircle.Update(m_bsst.pos,m_bsst.alive);

	m_stateMachine.Update();

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Update();
	}

	m_enemySquareFrame.Update();

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

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Action({ 0.05f,0.13f }, { RED, 1.0f }, { 0, 0, BIT256, BIT256 });
	}

	m_enemyhpCircle.Action(m_bsst.alive,m_enemyHitpoint);

	m_enemyframeCircle.Action(m_bsst.alive);

	m_enemySquareFrame.Action(m_bsst.pos);
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
}

void C_Enemy::EnemyBulletPlayerCircleHit()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();
	C_RenderWipe* playerrenderwipe = m_p0wner->GetPlayerRenderWipe();
	C_Sound* sound = m_p0wner->GetSound();

	if (playercircle->GetPlayerLife() == FourLife)return;

	for (int i = 0;i < ebulletNum;i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const tTry enemybulletPlayercircletTry = systm->CalcPythag(initPos, m_bullet[i].GetPos());

		const float bulletCirclehypn =  m_bullet[i].GetRadius() + playercircle->GetCircleRadius();

		if (enemybulletPlayercircletTry.hypn < bulletCirclehypn)
		{
			// �X�R�A��0�̂Ƃ��͌��炳�Ȃ�
			if (scoremanager->GetScore() > 0)
			{
				scoremanager->DecreaseScore();
			}
			// �v���C���[�̉~�Ɠ��������Ƃ��̏���
			playerrenderwipe->SetShakeTime(5);
			sound->GetPlayerCircleHitSe().inst->Play();
			m_bullet[i].Hit();
		}
		
	}
}

void C_Enemy::TakeDamage()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Sound* sound = m_p0wner->GetSound();

	// HP���_���[�W�����炷
	m_enemyHitpoint -= m_damagePoint;

	sound->GetEnemyHitSe().inst->Play();

	// �p�[�e�B�N���\������
	for (int i = 0; i < hitParticleNum;i++)
	{
		if (!m_enemyhitParticle[i].GetAlive())
		{
			float _rnd = m_enemyhitParticle[i].Rnd() * 0.9f - 0.6f;
			m_enemyhitParticle[i].Emit(
				{ m_bsst.pos.x + ((m_enemyhitParticle[i].Rnd() * (m_enemyRadius * 2)) - m_enemyRadius),
				  m_bsst.pos.y + ((m_enemyhitParticle[i].Rnd() * (m_enemyRadius * 2)) - m_enemyRadius) },
				{ m_enemyhitParticle[i].Rnd() * 12 - 6 ,m_enemyhitParticle[i].Rnd() * 12 - 6 },
				{ _rnd,_rnd },
				m_bsst.rot,
				true,
				m_enemyhitParticle[i].Rnd() * 30 + 15,
				false,
				{ 0,0,BIT64,BIT64 },
				{ intenseRed, 0.8f }
			);
		}
	}

	// �X�R�A�����Z����
	if (m_enemyHitpoint <= 0.0f)
	{
		scoremanager->AddScore();
		m_bsst.alive = false;	
	}
}

#include "Enemy.h"
#include "Enemy_StandState.h"
#include "Scene.h"

C_Enemy::C_Enemy()
{

}

C_Enemy::~C_Enemy()
{
	ebulletTex.Release();
}

void C_Enemy::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	// ���������ɃC���X�^���X�̃|�C���^��n��
	m_stateMachine.Start(this);

	// ������Ԃ̃X�e�[�g���Z�b�g
	m_stateMachine.ChangeState<C_Enemy_StandState>();

	ebulletTex.Load("Texture/ebullet.png");

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].SetTex(&ebulletTex);
		m_bullet[i].Init();
	}

	m_circleRadius = 305.0f;		// �~�̔��a
	m_deg = systm->RndBtwn(0,360);		// �p�x
	m_movDeg = 0;				// �ړ���(�p�x)

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.5f,0.5f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT64, BIT64 };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Draw()
{
	if (!m_bsst.alive)return;
	
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	
	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Draw();
	}

}

void C_Enemy::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_deg += m_movDeg;

	m_movDeg = 0;

	m_stateMachine.Update();

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Update();
	}

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();


	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;

	for (int i = 0;i < ebulletNum;i++)
	{
		m_bullet[i].Action();
	}
}

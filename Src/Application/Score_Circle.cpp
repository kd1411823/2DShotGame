#include "Score_Circle.h"
#include "Scene.h"

C_Score_Circle::C_Score_Circle()
{
}

C_Score_Circle::~C_Score_Circle()
{
	scorecircleTex.Release();
}

void C_Score_Circle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	m_rctY = 0; // �摜�؂�����WY
	m_targetScore = 0; // ���ɖڎw���X�R�A
	m_getScore = 0; // �擾�X�R�A��
	m_loadBulletFlg = false; // �e���`���[�W���Ă��邩�t���O
	m_scoreScl = OneScorescl; // �X�R�A�T�[�N���g�嗦

	scorecircleTex.Load("Texture/scorecircle.png");

	m_bsst.draw.pTex = &scorecircleTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_scoreScl,m_scoreScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0,  ScrnHgt, ScrnHgt,  -m_rctY };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_Circle::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (playercircle->GetPlayerLife() == FourLife)return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_Score_Circle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_Circle::Action(int a_score)
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	// �X�R�A�ɉ����Đ؂�����WY��ς���
	m_rctY = ScrnHgt *  (((float)a_score - m_getScore) / (m_targetScore - m_getScore));

	// �؂�����WY�ɉ����č��W�����炷
	m_bsst.pos.y = (- ScrnHgt * m_scoreScl * 0.5f) + (m_rctY * m_scoreScl * 0.5f);

	m_bsst.scl = { m_scoreScl,m_scoreScl };

	// �؂�����W�𒴂��Ȃ��悤�ɕ␳
	if (m_rctY > ScrnHgt)
	{
		m_rctY = ScrnHgt;
	}

	// �؂�����W���f
	m_bsst.draw.rct = { 0,  ScrnHgt, ScrnHgt, - m_rctY };

	if (m_loadBulletFlg)
	{
		m_bsst.draw.clr.A(0.3f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}
}

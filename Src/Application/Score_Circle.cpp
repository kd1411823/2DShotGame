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

	scorecircleTex.Load("Texture/scorecircle.png");

	m_bsst.draw.pTex = &scorecircleTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { playercircle->GetPlayerCircleScl(),playercircle->GetPlayerCircleScl()};
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0,  ScrnWid, ScrnWid,  -m_rctY };
	m_bsst.draw.clr = YELLOW;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_Circle::Draw()
{
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
	m_rctY = ScrnWid *  (((float)a_score - m_getScore) / (m_targetScore - m_getScore));

	printf("%.0f\n",m_targetScore);

	// �؂�����WY�ɉ����č��W�����炷
	m_bsst.pos.y = (- ScrnWid * playercircle->GetPlayerCircleScl() * 0.5f) + (m_rctY * playercircle->GetPlayerCircleScl() * 0.5f);

	// �傫�����v���C���[�̃��C�t���x���ɉ����Ĕ��f������
	m_bsst.scl = { playercircle->GetPlayerCircleScl(),playercircle->GetPlayerCircleScl() };

	// �؂�����W���f
	m_bsst.draw.rct = { 0,  ScrnWid, ScrnWid, - m_rctY };
}

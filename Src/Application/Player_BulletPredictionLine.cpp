#include "Player_BulletPredictionLine.h"
#include "Scene.h"

void C_Player_BulletPredictionLine::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no;	// 予測ラインのナンバー

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.1f,0.1f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT128, BIT128 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_BulletPredictionLine::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (m_no > playercircle->GetBulletPredictionLineDeleteNo())return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Player_BulletPredictionLine::Update(Math::Vector2 a_pos)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (m_no > playercircle->GetBulletPredictionLineDeleteNo())return;

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_BulletPredictionLine::Action(Math::Vector2 a_pos,float a_rot, float a_deg, float a_circleRadius)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (m_no > playercircle->GetBulletPredictionLineDeleteNo())return;

	m_bsst.rot = a_rot;

	m_bsst.pos.x = cos(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * m_no);
	m_bsst.pos.y = sin(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * m_no);

}






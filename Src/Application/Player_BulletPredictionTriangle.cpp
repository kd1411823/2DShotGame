#include "Player_BulletPredictionTriangle.h"
#include "Scene.h"

void C_Player_BulletPredictionTriangle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.15f,0.15f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT256, BIT256 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_BulletPredictionTriangle::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Player_BulletPredictionTriangle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_BulletPredictionTriangle::Action(Math::Vector2 a_pos, float a_rot, float a_deg, float a_circleRadius)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	m_bsst.rot = a_rot;

	m_bsst.pos.x = cos(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * playercircle->GetBulletPredictionLineDeleteNo());
	m_bsst.pos.y = sin(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * playercircle->GetBulletPredictionLineDeleteNo());
}

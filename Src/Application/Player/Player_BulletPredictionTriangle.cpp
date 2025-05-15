#include "Player_BulletPredictionTriangle.h"
#include "../Particle/Sun.h"
#include "../Scene/Scene.h"

void C_Player_BulletPredictionTriangle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.3f,0.3f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT128, BIT128 };
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

	m_sun->Update(m_bsst.pos, { 0.2f,0.2f }, { m_bsst.draw.clr });

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_BulletPredictionTriangle::Action(Math::Vector2 a_pos, float a_rot, float a_deg, float a_circleRadius)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_Player* player = m_p0wner->GetPlayer();

	if (player->GetDropHitCount() > DecreaseGCnt)
	{
		m_bsst.draw.clr.G(1.0f - (playercircle->GetBulletPredictionLineDeleteNo() * 0.01f * (player->GetDropHitCount() - DecreaseGCnt)));
	}

	m_bsst.draw.clr.R(playercircle->GetBulletPredictionLineDeleteNo() * 0.02f * player->GetDropHitCount());

	m_bsst.rot = a_rot;

	m_bsst.pos.x = cos(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * playercircle->GetBulletPredictionLineDeleteNo());
	m_bsst.pos.y = sin(systm->CnvrtToRadians(a_deg)) * (a_circleRadius - PredictionLineDistance * playercircle->GetBulletPredictionLineDeleteNo());
}

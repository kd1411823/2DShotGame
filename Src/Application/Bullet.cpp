#include "Bullet.h"
#include "Scene.h"

void C_Bullet::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_loadOkFlg = false;	// ‘•“Uƒtƒ‰ƒO

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.0f,0.0f };
	m_bsst.rot = 0;
	m_bsst.alive = false;
	m_bsst.draw.rct = { 0, 0, BIT256, BIT256 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Bullet::Draw()
{
	if (!m_bsst.alive)return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Bullet::Update()
{
	if (!m_bsst.alive)return;

	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Bullet::Action(Math::Vector2 a_scl, Math::Color a_clr, Math::Rectangle a_rct)
{
	if (!m_bsst.alive)return;

	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.scl = a_scl;

	m_bsst.draw.clr = a_clr;

	m_bsst.draw.rct = a_rct;

	IsEndPoint();
	
	
}

void C_Bullet::ShotBullet(Math::Vector2 a_pos, float a_deg, float a_spdScl)
{
	m_bsst.pos = a_pos;
	m_bsst.rot = a_deg - 90.0f;
	m_bsst.mov.x = cos(DirectX::XMConvertToRadians(a_deg)) * (m_bulletSpd * a_spdScl);
	m_bsst.mov.y = sin(DirectX::XMConvertToRadians(a_deg)) * (m_bulletSpd * a_spdScl);
	m_bsst.alive = true;
	m_loadOkFlg = false;
}

void C_Bullet::IsEndPoint()
{
	if (m_bsst.pos.x > ScrnRht + m_bulletRadius || m_bsst.pos.x < ScrnLft - m_bulletRadius ||
		m_bsst.pos.y > ScrnTop + m_bulletRadius || m_bsst.pos.y < ScrnBtm - m_bulletRadius)
	{
		Hit();
	}

}







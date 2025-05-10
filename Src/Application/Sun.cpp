#include "Sun.h"
#include "Scene.h"

C_Sun::C_Sun()
{

}

C_Sun::~C_Sun()
{
	sunTex.Release();
}

void C_Sun::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	sunTex.Load("Texture/Sun.png");

	m_bsst.draw.pTex = &sunTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT128, BIT128 };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Sun::Draw()
{
	D3D.SetBlendState(BlendMode::Add);
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	D3D.SetBlendState(BlendMode::Alpha);

}

void C_Sun::Update(Math::Vector2 a_pos, Math::Vector2 a_scl, Math::Color a_clr)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.pos = a_pos;
	m_bsst.scl = a_scl;
	m_bsst.draw.clr = a_clr;

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}



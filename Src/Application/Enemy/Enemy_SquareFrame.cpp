#include "Enemy_SquareFrame.h"
#include "../Scene/Scene.h"

C_Enemy_SquareFrame::C_Enemy_SquareFrame()
{
}

C_Enemy_SquareFrame::~C_Enemy_SquareFrame()
{
}

void C_Enemy_SquareFrame::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_frameScl = EnemyBaseScl;// ƒtƒŒ[ƒ€Šg‘å—¦
	m_maxScl = 5.0f; // Å‘åŠg‘å—¦
	m_stopFlg = false; // Ž~‚Ü‚Á‚Ä‚¢‚é‚©ƒtƒ‰ƒO

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_frameScl,m_frameScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT64, BIT64 };
	m_bsst.draw.clr = { RED ,0.00f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy_SquareFrame::Draw()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();
	if (!m_stopFlg || (renderwipe->GetShakeTime() != 0))return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Enemy_SquareFrame::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy_SquareFrame::Action(Math::Vector2 a_pos)
{
	
	m_bsst.pos = a_pos;

	m_frameScl -= 0.1f;
	m_bsst.draw.clr.A(m_bsst.draw.clr.A() + 0.013f);

	if (m_frameScl <= EnemyBaseScl)
	{
		m_frameScl = m_maxScl;
		m_bsst.draw.clr.A(0.00f);
	}

	m_bsst.scl = { m_frameScl,m_frameScl };

}

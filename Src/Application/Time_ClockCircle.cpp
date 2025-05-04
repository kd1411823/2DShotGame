#include "Time_ClockCircle.h"
#include "Scene.h"

C_Time_ClockCircle::C_Time_ClockCircle()
{
}

C_Time_ClockCircle::~C_Time_ClockCircle()
{
	clockCircleTex.Release();
}

void C_Time_ClockCircle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	clockCircleTex.Load("Texture/clockCircle.png");

	m_isRisingAlpha = false;	// 数字のalpha値増減フラグ
	m_deltaAlpha = 0.03f;		// 数字のalpha値増減量

	m_bsst.draw.pTex = &clockCircleTex;

	m_bsst.pos = { 450,300 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.1f,0.1f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT512 , BIT512 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockCircle::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Time_ClockCircle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockCircle::Action()
{
}

void C_Time_ClockCircle::AlphaManager()
{
	if (m_bsst.draw.clr.A() >= 1.0f)
	{
		m_isRisingAlpha = false;
	}

	if (m_bsst.draw.clr.A() <= 0.5f)
	{
		m_isRisingAlpha = true;
	}

	if (m_isRisingAlpha)
	{
		m_bsst.draw.clr.A(m_bsst.draw.clr.A() + m_deltaAlpha);
	}
	else
	{
		m_bsst.draw.clr.A(m_bsst.draw.clr.A() - m_deltaAlpha);
	}

}

void C_Time_ClockCircle::DecreaseAlpha()
{
	if (m_bsst.draw.clr.A() <= 0.0f)return;
	m_deltaAlpha = 0.005f;

	m_bsst.draw.clr.A(m_bsst.draw.clr.A() - m_deltaAlpha);
}

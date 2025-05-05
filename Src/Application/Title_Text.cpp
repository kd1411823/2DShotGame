#include "Title_Text.h"
#include "Scene.h"

C_Title_Text::C_Title_Text()
{
}

C_Title_Text::~C_Title_Text()
{
}

void C_Title_Text::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no; // オブジェクトナンバー

	if (m_no == 0)
	{
		m_rctX = BIT24 * 0;
		m_widRctX = BIT24 * 4; // 切り取り量X
		m_bsst.draw.clr = { GREEN ,1.0f };
		m_bsst.pos = { -125 ,-100 };
	}
	else if (m_no == 1)
	{
		m_rctX = BIT24 * 4;
		m_widRctX = BIT24 * 2; // 切り取り量X
		m_bsst.draw.clr = { GREEN ,1.0f };
		m_bsst.pos = { -20 , -100 };
	}
	else if (m_no == 2)
	{
		m_rctX = BIT24 * 6;
		m_widRctX = BIT24 * 5; // 切り取り量X
		m_bsst.draw.clr = { RED ,1.0f };
		m_bsst.pos = { 100 , -100 };
	}

	m_isRisingAlpha = false;	// alpha値増減フラグ
	m_deltaAlpha = 0.02f; // alpha値加算量

	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, m_widRctX, BIT24 };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Title_Text::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Title_Text::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Title_Text::Action()
{

	AlphaManager();

	m_bsst.draw.rct = { m_rctX, 0, m_widRctX, BIT24 };

	
}

void C_Title_Text::AlphaManager()
{
	if (m_bsst.draw.clr.A() >= 1.0f)
	{
		m_isRisingAlpha = false;
	}

	if (m_bsst.draw.clr.A() <= 0.0f)
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



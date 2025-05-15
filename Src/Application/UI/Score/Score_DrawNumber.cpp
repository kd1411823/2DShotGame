#include "Score_DrawNumber.h"
#include "../../Scene/Scene.h"

C_Score_DrawNumber::C_Score_DrawNumber()
{
}

C_Score_DrawNumber::~C_Score_DrawNumber()
{
}

void C_Score_DrawNumber::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Time_ClockNumber* timeclocknumber = timemanager->GetTimeClockNumber(0);

	m_no = a_no; // •`‰æ—p”Žš‚ÌNo
	m_numberDistance = 40.0f; // •`‰æ—p”ŽšŠÔŠu
	m_deltaAlpha = 0.005f; // alpha’l‰ÁŽZ—Ê

	if (m_no == 0)
	{
		m_bsst.draw.rct = { BIT24 * 1, 0, BIT24 , BIT24 };
	}
	else if (m_no == 1)
	{
		m_bsst.draw.rct = { BIT24 * 5, 0, BIT24 , BIT24 };
	}
	else
	{
		m_bsst.draw.rct = { BIT24 * 0, 0, BIT24 , BIT24 };
	}

	m_bsst.pos = { m_numberDistance,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.5f,1.5f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.clr = { GREEN ,0.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_DrawNumber::Draw()
{
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	if (!timemanager->GetIsTimeLeftFlg())return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Score_DrawNumber::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_DrawNumber::Action()
{
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Time_ClockNumber* timeclocknumber = timemanager->GetTimeClockNumber(0);

	m_bsst.pos.x = m_numberDistance * m_no + 50;

	m_bsst.scl = timeclocknumber->GetScl();
}

void C_Score_DrawNumber::AddAlpha()
{
	if (m_bsst.draw.clr.A() >= 1.0f)return;

	m_bsst.draw.clr.A(m_bsst.draw.clr.A() + m_deltaAlpha);
}

void C_Score_DrawNumber::DecreaseAlpha()
{
	if (m_bsst.draw.clr.A() <= 0.0f)return;

	m_bsst.draw.clr.A(m_bsst.draw.clr.A() - m_deltaAlpha);
}

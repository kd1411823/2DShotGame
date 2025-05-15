#include "Time_ClockHands.h"
#include "../../Scene/Scene.h"

C_Time_ClockHands::C_Time_ClockHands()
{
}

C_Time_ClockHands::~C_Time_ClockHands()
{
	clockHandsTex.Release();
}

void C_Time_ClockHands::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Time_ClockCircle* timeclockcircle = timemanager->GetTimeClockCircle();

	clockHandsTex.Load("Texture/clockHands.png");

	m_bsst.draw.pTex = &clockHandsTex;

	m_bsst.pos = timeclockcircle->GetPos();
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.1f,0.1f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT512 , BIT512 };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockHands::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Time_ClockHands::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockHands::Action()
{
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Time_ClockCircle* timeclockcircle = timemanager->GetTimeClockCircle();

	m_bsst.mov = timeclockcircle->GetMov();

	m_bsst.pos = timeclockcircle->GetPos();

	m_bsst.draw.clr.A(timeclockcircle->GetAlpha());
}

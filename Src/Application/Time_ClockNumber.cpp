#include "Time_ClockNumber.h"
#include "Scene.h"

C_Time_ClockNumber::C_Time_ClockNumber()
{
}

C_Time_ClockNumber::~C_Time_ClockNumber()
{
}

void C_Time_ClockNumber::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no; // タイマー数字ナンバー
	m_rctX = BIT24 * 0; // 切り取り座標X
	m_digitsNumber = 0; // 桁数字
	m_numberDistance = 40.0f; // 数字間隔

	m_bsst.pos = { 520,300 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 2.0f,2.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockNumber::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Time_ClockNumber::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Time_ClockNumber::Action()
{
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();

	switch (m_no)
	{
	case 0:
		m_digitsNumber = (timemanager->GetTimer() / 100) % 10;
	    break;
	case 1:
		m_digitsNumber = (timemanager->GetTimer() / 10) % 10;
		break;
	case 2:
		m_digitsNumber = timemanager->GetTimer() % 10;
		break;
	}

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

	m_bsst.pos.x = 520 + m_no * m_numberDistance;

}

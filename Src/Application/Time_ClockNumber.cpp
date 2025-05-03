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
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Time_ClockCircle* timeclockcircle = timemanager->GetTimeClockCircle();

	m_no = a_no; // タイマー数字ナンバー
	m_rctX = BIT24 * 0; // 切り取り座標X
	m_digitsNumber = 0; // 桁数字
	m_numberDistance = 40.0f; // 数字間隔
	m_numberScl = 2.0f; // 数字の拡大率
	m_isRisingScl = false;	// 数字の拡大率増減フラグ
	m_deltaScl = 0.025f;		// 数字の拡大率増減量
	m_deltaMax = 0.4f;	// max - 基準値　
	m_deltaMin = 0.4f;	// min - 基準値　
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// 最大数字の拡大率
	m_minDeltaScl = m_numberScl + m_deltaMin;		// 最小数字の拡大率

	m_bsst.pos = { timeclockcircle->GetPos().x + 60, timeclockcircle->GetPos().y };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_numberScl,m_numberScl };
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
	C_Time_ClockCircle* timeclockcircle = timemanager->GetTimeClockCircle();

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

	m_bsst.pos.x = timeclockcircle->GetPos().x + 60 + m_no * m_numberDistance;
	m_bsst.pos.y = timeclockcircle->GetPos().y;


	ScaleManager();

}

void C_Time_ClockNumber::ScaleManager()
{
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// 最大プレイヤーの拡大率
	m_minDeltaScl = m_numberScl - m_deltaMin;		// 最小プレイヤーの拡大率

	if (m_bsst.scl.x >= m_maxDeltaScl && m_bsst.scl.y >= m_maxDeltaScl)
	{
		m_isRisingScl = false;
	}

	if (m_bsst.scl.x <= m_minDeltaScl && m_bsst.scl.y <= m_minDeltaScl)
	{
		m_isRisingScl = true;
	}

	if (m_isRisingScl)
	{
		m_bsst.scl.x += m_deltaScl;
		m_bsst.scl.y += m_deltaScl;
	}
	else
	{
		m_bsst.scl.x -= m_deltaScl;
		m_bsst.scl.y -= m_deltaScl;
	}


}

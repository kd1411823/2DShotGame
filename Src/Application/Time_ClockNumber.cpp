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

	m_no = a_no; // �^�C�}�[�����i���o�[
	m_rctX = BIT24 * 0; // �؂�����WX
	m_digitsNumber = 0; // ������
	m_numberDistance = 40.0f; // �����Ԋu
	m_numberScl = 2.0f; // �����̊g�嗦
	m_isRisingScl = false;	// �����̊g�嗦�����t���O
	m_deltaScl = 0.025f;		// �����̊g�嗦������
	m_deltaMax = 0.4f;	// max - ��l�@
	m_deltaMin = 0.4f;	// min - ��l�@
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// �ő吔���̊g�嗦
	m_minDeltaScl = m_numberScl + m_deltaMin;		// �ŏ������̊g�嗦

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
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// �ő�v���C���[�̊g�嗦
	m_minDeltaScl = m_numberScl - m_deltaMin;		// �ŏ��v���C���[�̊g�嗦

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

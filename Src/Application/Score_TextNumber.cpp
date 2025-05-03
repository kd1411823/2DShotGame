#include "Score_TextNumber.h"
#include "Scene.h"

C_Score_TextNumber::C_Score_TextNumber()
{

}

C_Score_TextNumber::~C_Score_TextNumber()
{

}

void C_Score_TextNumber::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no; // �I�u�W�F�N�g�i���o�[
	m_rctX = BIT24 * 0; // �؂�����WX
	m_numberDistance = OneNumDistance; // �����Ԋu
	m_digitsNumber = 0; // ������
	m_numberScl = OneNumScl; // �����̑傫��
	m_addDrawScore = 0.0f; // �X�R�A�����Z���鉉�o�p�̃X�R�A������ϐ�
	m_addSpeed = 10.0f; // �X�R�A�����Z����X�s�[�h
	m_isRisingScl = false;	// �v���C���[�̊g�嗦�����t���O
	m_deltaScl = 0.1f;		// �v���C���[�̊g�嗦������
	m_deltaMax = 0.4f;	// max - ��l�@
	m_deltaMin = 0.4f;	// min - ��l�@
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// �ő�v���C���[�̊g�嗦
	m_minDeltaScl = m_numberScl - m_deltaMin;		// �ŏ��v���C���[�̊g�嗦
	m_isRisingAlpha = false;	// ������alpha�l�����t���O
	m_deltaAlpha = 0.03f;		// ������alpha�l������


	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextNumber::Draw()
{

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_Score_TextNumber::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextNumber::Action()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	
	if (playercircle->GetPlayerLife() == FourLife)return;

	if (scorecircle->GetLoadBulletFlg())
	{
		m_bsst.draw.clr.A(0.2f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}

	
	// No�̍��W�̒��S�����ɂ��炷
	m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
	m_bsst.pos.y = - m_numberDistance;

	switch (m_no)
	{
	case 0:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 1000) % 10;
		break;
	case 1:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 100) % 10;
		break;
	case 2:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 10) % 10;
		break;
	case 3:
		m_digitsNumber = ((int)std::floor(scoremanager->GetScore())) % 10;
		break;
	}


	m_bsst.scl = { m_numberScl, m_numberScl };

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

}

void C_Score_TextNumber::AddDrawScore()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	
	ScaleManager();

	scoretextstring->SetScl(m_bsst.scl * 0.5f);

	if (m_addDrawScore < scoremanager->GetScore())
	{
		m_addDrawScore += m_addSpeed;
		m_deltaScl = 0.1f;
	}
	else
	{
		m_addDrawScore = scoremanager->GetScore();
		m_bsst.draw.clr = { GREEN,1.0f };
		scoretextstring->SetClr({ GREEN,1.0f});
		m_deltaScl = 0.02f;
		m_deltaMax = 0.2f;
		m_deltaMin = 0.2f;
	}

	m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
	m_bsst.pos.y = -m_numberDistance;

	switch (m_no)
	{
	case 0:
		m_digitsNumber = (((int)std::floor(m_addDrawScore))/ 1000) % 10;
		break;
	case 1:
		m_digitsNumber = (((int)std::floor(m_addDrawScore)) / 100) % 10;
		break;
	case 2:
		m_digitsNumber = (((int)std::floor(m_addDrawScore)) / 10) % 10;
		break;
	case 3:
		m_digitsNumber = ((int)std::floor(m_addDrawScore)) % 10;
		break;
	}

	//m_bsst.draw.clr.A(1.0f);

	//m_bsst.scl = { m_numberScl, m_numberScl };

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

	
}

void C_Score_TextNumber::ScaleManager()
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

void C_Score_TextNumber::AlphaManager()
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




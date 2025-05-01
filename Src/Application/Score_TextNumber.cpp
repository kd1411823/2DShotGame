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
	m_numberScl = 1.0f; // �����̑傫��

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


	if (scorecircle->GetLoadBulletFlg())
	{
		m_bsst.draw.clr.A(0.2f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}

	m_bsst.scl = { m_numberScl, m_numberScl };

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

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

	printf("number %d\n", m_digitsNumber);

	
}

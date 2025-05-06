#include "GameStart_StringText.h"
#include "Scene.h"

C_GameStart_StringText::C_GameStart_StringText()
{
}

C_GameStart_StringText::~C_GameStart_StringText()
{
}

void C_GameStart_StringText::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no; // オブジェクトナンバー
	m_isRisingAlpha = false;	// alpha値増減フラグ
	m_deltaAlpha = 0.02f;		// alpha値増減量


	if (m_no == 0)
	{
		m_rctX = BIT24 * m_no; // 切り取り座標X
		m_rctWidX = BIT24 * 5; // 切り取り量X
		m_bsst.pos = { 470, -300 };
		m_bsst.draw.clr = { GREEN ,1.0f };
	}
	else if (m_no == 1)
	{
		m_rctX = BIT24 * m_no; // 切り取り座標X
		m_rctWidX = BIT24 * 1; // 切り取り量X
		m_bsst.pos = { 600, -300 };
		m_bsst.draw.clr = { RED ,1.0f };
	}

	
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.5f,1.5f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, m_rctWidX, BIT24 };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_GameStart_StringText::Draw()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (gamestartmanager->GetGameStartFlg())return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_GameStart_StringText::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (gamestartmanager->GetGameStartFlg())return;


	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_GameStart_StringText::Action()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (gamestartmanager->GetGameStartFlg())return;


	m_bsst.draw.rct = { m_rctX, 0, m_rctWidX, BIT24 };

	AlphaManager();
}

void C_GameStart_StringText::AlphaManager()
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

#include "GameStart_Number.h"
#include "Scene.h"

C_GameStart_Number::C_GameStart_Number()
{
}

C_GameStart_Number::~C_GameStart_Number()
{
	startTex.Release();
}

void C_GameStart_Number::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	startTex.Load("Texture/start.png");

	m_digitsNumber = gamestartmanager->GetStartCountTime(); // Œ…”Žš
	m_rctX = m_digitsNumber * BIT24; // Ø‚èŽæ‚èÀ•WX
	m_deltaScale = 0.4f;// Šg‘å—¦‘Œ¸—Ê
	m_baseScale = 3.5f; // Œ³‚ÌŠg‘å—¦
	m_maxScale = 15.0f;// Å‘åŠg‘å—¦
	m_deltaAlpha = 0.04f; // alpha’l‘Œ¸—Ê

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_maxScale,m_maxScale };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, BIT24, BIT24 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_GameStart_Number::Draw()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (!gamestartmanager->GetStartCountFlg() ||
		 gamestartmanager->GetGameStartFlg())return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_GameStart_Number::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (!gamestartmanager->GetStartCountFlg() || gamestartmanager->GetGameStartFlg())return;

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_GameStart_Number::Action()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (!gamestartmanager->GetStartCountFlg() || gamestartmanager->GetGameStartFlg())return;

	if (m_digitsNumber != gamestartmanager->GetStartCountTime() - 1)
	{
		m_bsst.scl = { m_maxScale,m_maxScale };
		m_bsst.draw.clr.A(0.0f);
	}

	ScaleManger();

	AddAlpha();

	m_digitsNumber = (((int)std::floor(gamestartmanager->GetStartCountTime())) % 10) - 1;


	if (gamestartmanager->GetStartCountTime() - 1 < 0)
	{
		m_bsst.draw.clr = { RED ,m_bsst.draw.clr.A()};
		m_bsst.draw.rct = { 0, 0, BIT120, BIT24 };
		m_bsst.draw.pTex = &startTex;
	}
	else
	{
		m_rctX = m_digitsNumber * BIT24; // Ø‚èŽæ‚èÀ•WX
		m_bsst.draw.rct = { m_rctX, 0, BIT24, BIT24 };
	}
}

void C_GameStart_Number::ScaleManger()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (m_bsst.scl.x > m_baseScale)
	{
		m_bsst.scl.x -= m_deltaScale;
	}
	
	if (m_bsst.scl.y > m_baseScale)
	{
		m_bsst.scl.y -= m_deltaScale;
	}
	
}

void C_GameStart_Number::AddAlpha()
{

	if (m_bsst.draw.clr.A() < 1.0f)
	{
		m_bsst.draw.clr.A(m_bsst.draw.clr.A() + m_deltaAlpha);
	}
}

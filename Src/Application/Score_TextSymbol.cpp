#include "Score_TextSymbol.h"
#include "Scene.h"

C_Score_TextSymbol::C_Score_TextSymbol()
{
}

C_Score_TextSymbol::~C_Score_TextSymbol()
{
	symbolTex.Release();
}

void C_Score_TextSymbol::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	symbolTex.Load("Texture/symbol.png");


	m_deltaAlpha = 0.005f; // alpha’l‰ÁŽZ—Ê

	m_bsst.draw.pTex = &symbolTex;
	m_plusBsst.draw.pTex = &symbolTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.5f,1.5f };
	m_bsst.rot = 45;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT24 , BIT24 };
	m_bsst.draw.clr = { WHITE ,0.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);


	m_plusBsst.pos = { 0, -75 };
	m_plusBsst.mov = { 0,0 };
	m_plusBsst.scl = { 1.5f,1.5f };
	m_plusBsst.rot = 0;
	m_plusBsst.alive = true;
	m_plusBsst.draw.rct = { 0, 0, BIT24 , BIT24 };
	m_plusBsst.draw.clr = { WHITE ,0.0f };
	m_plusBsst.mat = systm->CreateMat(m_plusBsst.scl, m_plusBsst.rot, m_plusBsst.pos);
}

void C_Score_TextSymbol::Draw()
{
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	if (!timemanager->GetIsTimeLeftFlg())return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

	SHADER.m_spriteShader.SetMatrix(m_plusBsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_plusBsst.draw.pTex, 0, 0, &m_plusBsst.draw.rct, &m_plusBsst.draw.clr);
}

void C_Score_TextSymbol::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;
	m_plusBsst.pos += m_plusBsst.mov;

	m_bsst.mov = { 0,0 };
	m_plusBsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
	m_plusBsst.mat = systm->CreateMat(m_plusBsst.scl, m_plusBsst.rot, m_plusBsst.pos);
}

void C_Score_TextSymbol::Action()
{

}

void C_Score_TextSymbol::AddAlpha()
{
	if (m_bsst.draw.clr.A() >= 1.0f && m_plusBsst.draw.clr.A() >= 1.0f)return;

	m_bsst.draw.clr.A(m_bsst.draw.clr.A() + m_deltaAlpha);
	m_plusBsst.draw.clr.A(m_plusBsst.draw.clr.A() + m_deltaAlpha);

}

void C_Score_TextSymbol::DecreaseAlpha()
{
	if (m_bsst.draw.clr.A() <= 0.0f && m_plusBsst.draw.clr.A() <= 0.0f)return;

	m_bsst.draw.clr.A(m_bsst.draw.clr.A() - m_deltaAlpha);
	m_plusBsst.draw.clr.A(m_plusBsst.draw.clr.A() - m_deltaAlpha);
}

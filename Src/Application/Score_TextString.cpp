#include "Score_TextString.h"
#include "Scene.h"

C_Score_TextString::C_Score_TextString()
{

}

C_Score_TextString::~C_Score_TextString()
{
	scoretextstringTex.Release();
}

void C_Score_TextString::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	scoretextstringTex.Load("Texture/score.png");

	m_scoreTextScl = OnescoreTextScl; // ƒXƒRƒA•¶Žš—ñ‚ÌŠg‘å—¦

	m_bsst.draw.pTex = &scoretextstringTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_scoreTextScl,m_scoreTextScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT120 , BIT24 };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextString::Draw()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Result* scoreresult = scoremanager->GetScoreResult();

	if (scoreresult->GetTextDrawFlg())return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_Score_TextString::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextString::Action()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextNumber* scoretextnumber = scoremanager->GetScoreTextNumber(0);

	m_bsst.scl = { m_scoreTextScl,m_scoreTextScl };

	if (scorecircle->GetLoadBulletFlg())
	{
		m_bsst.draw.clr.A(0.4f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}

}

#include "Score_TextString.h"
#include "Sun.h"
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

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	m_bsst.draw.pTex = &scoretextstringTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT72 , BIT18};
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);



}

void C_Score_TextString::Draw()
{

	D3D.SetBlendState(BlendMode::Add);

	m_sun->Draw();

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

	D3D.SetBlendState(BlendMode::Alpha);

}

void C_Score_TextString::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_sun->Update(m_bsst.pos, { 2.5f,0.6f }, { 1.0f,1.0f,1.0f,1.0f });

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextString::Action()
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

}

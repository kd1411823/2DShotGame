#include "ScoreManager.h"
#include "Scene.h"

C_ScoreManager::C_ScoreManager()
{
}

C_ScoreManager::~C_ScoreManager()
{
	scoretextnumberTex.Release();
}

void C_ScoreManager::Init()
{

	scoretextnumberTex.Load("Texture/Number.png");


	m_scorecircle.SetP0wner(m_p0wner);
	m_scorecircle.Init();

	m_scoretextstring.SetP0wner(m_p0wner);
	m_scoretextstring.Init();


	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].SetP0wner(m_p0wner);
		m_scoretextnumber[i].SetTex(&scoretextnumberTex);
		m_scoretextnumber[i].Init(i);
	}
}

void C_ScoreManager::Draw()
{
	m_scorecircle.Draw();
	m_scoretextstring.Draw();
	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Draw();
	}
}

void C_ScoreManager::Update()
{
	m_scorecircle.Update();
	m_scoretextstring.Update();
	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Update();
	}
	printf("score: %.0f\n", m_score);

}

void C_ScoreManager::Action()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (m_score <= 0)m_score = 0;

	if (m_score <= oneTargetScore)
	{
		playercircle->SetPlayerLife(OneLife);
	}
	if (m_score > oneTargetScore)
	{
		playercircle->SetPlayerLife(TwoLife);
	}
	if (m_score > twoTargetScore)
	{
		playercircle->SetPlayerLife(ThreeLife);
	}
	if (m_score > threeTargetScore)
	{
		playercircle->SetPlayerLife(FourLife);
	}

	m_scoretextstring.Action();

	m_scorecircle.Action(m_score);

	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Action();
	}
}

void C_ScoreManager::AddScore()
{
	m_score += 100.0f;
}

void C_ScoreManager::DecreaseScore()
{
	m_score -= 0.0f;
}

#include "ScoreManager.h"
#include "Scene.h"

void C_ScoreManager::Init()
{

	m_scorecircle.SetP0wner(m_p0wner);
	m_scorecircle.Init();
}

void C_ScoreManager::Draw()
{
	m_scorecircle.Draw();
}

void C_ScoreManager::Update()
{
	m_scorecircle.Update();
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

	m_scorecircle.Action(m_score);

	
}

void C_ScoreManager::AddScore()
{
	m_score += 100.0f;
}

void C_ScoreManager::DecreaseScore()
{
	m_score -= 20.0f;
}

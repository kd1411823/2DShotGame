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

	m_scoretextsymbol.SetP0wner(m_p0wner);
	m_scoretextsymbol.Init();

	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].SetP0wner(m_p0wner);
		m_scoretextnumber[i].SetTex(&scoretextnumberTex);
		m_scoretextnumber[i].Init(i);
	}

	for (int i = 0;i < scoreDrawDigits;i++)
	{
		m_scoredrawnumber[i].SetP0wner(m_p0wner);
		m_scoredrawnumber[i].SetTex(&scoretextnumberTex);
		m_scoredrawnumber[i].Init(i);
	}

	m_scoreresult.SetP0wner(m_p0wner);
	m_scoreresult.Init();

	m_score = 0; // ƒXƒRƒA
}

void C_ScoreManager::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (!gamestartmanager->GetGameStartFlg())return;

	m_scorecircle.Draw();
	m_scoretextstring.Draw();
	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Draw();
	}
	for (int i = 0;i < scoreDrawDigits;i++)
	{
		m_scoredrawnumber[i].Draw();
	}

	m_scoretextsymbol.Draw();
	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_scoreresult.Draw();
	}
}

void C_ScoreManager::Update()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();


	m_scorecircle.Update();
	m_scoretextstring.Update();
	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Update();
	}
	for (int i = 0;i < scoreDrawDigits;i++)
	{
		m_scoredrawnumber[i].Update();
	}

	m_scoretextsymbol.Update();

	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_scoreresult.Update();
	}
	printf("score: %.0f\n", m_score);

}

void C_ScoreManager::Action()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();

	
	if (m_score >= 9999)
	{
		m_score = 9999;
	}

	if (timemanager->GetTimer() > 0)
	{
		if (m_score <= oneTargetScore)
		{
			playercircle->SetPlayerLife(OneLife);
			for (int i = 0;i < scoreDigits;i++)
			{
				m_scoretextnumber[i].SetNumberScl(OneNumScl);
				m_scoretextnumber[i].SetNumberDistance(OneNumDistance);
			}
		}
		if (m_score > oneTargetScore)
		{
			playercircle->SetPlayerLife(TwoLife);
			for (int i = 0;i < scoreDigits;i++)
			{
				m_scoretextnumber[i].SetNumberScl(TwoNumScl);
				m_scoretextnumber[i].SetNumberDistance(TwoNumDistance);
			}
		}
		if (m_score > twoTargetScore)
		{
			playercircle->SetPlayerLife(ThreeLife);
			for (int i = 0;i < scoreDigits;i++)
			{
				m_scoretextnumber[i].SetNumberScl(ThreeNumScl);
				m_scoretextnumber[i].SetNumberDistance(ThreeNumDistance);
			}
		}
		if (m_score > threeTargetScore)
		{
			playercircle->SetPlayerLife(FourLife);
			for (int i = 0;i < scoreDigits;i++)
			{
				m_scoretextnumber[i].SetNumberScl(FourNumScl);
				m_scoretextnumber[i].SetNumberDistance(FourNumDistance);
			}
		}
	}

	m_scoretextstring.Action();

	m_scorecircle.Action(m_score);

	for (int i = 0;i < scoreDigits;i++)
	{
		m_scoretextnumber[i].Action();
	}
	for (int i = 0;i < scoreDrawDigits;i++)
	{
		m_scoredrawnumber[i].Action();
	}
	m_scoretextsymbol.Action();

	if (playercircle->GetPlayerLife() == FourLife)
	{
		m_scoreresult.Action();
	}
}

void C_ScoreManager::AddScore()
{
	if (m_score >= 9999)return;

	m_score += 100.0f;
}

void C_ScoreManager::DecreaseScore()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (playercircle->GetPlayerLife() == FourLife || m_score <= 0)return;

	m_score -= 10.0f;
}

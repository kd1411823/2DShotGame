#include "Score_Result.h"
#include "Scene.h"

void C_Score_Result::Init()
{

}

void C_Score_Result::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	if (playercircle->GetPlayerLife() != FourLife)return;

	

}

void C_Score_Result::Update()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();

	if (playercircle->GetPlayerLife() != FourLife)return;

}

void C_Score_Result::Action()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Score_TextNumber* scoretextnumber[scoreDigits];

	for (int i = 0; i < scoreDigits;i++)
	{
		scoretextnumber[i] = scoremanager->GetScoreTextNumber(i);
	}

	if (playercircle->GetPlayerLife() != FourLife)return;

	for (int i = 0; i < scoreDigits;i++)
	{
		scoretextnumber[i]->AddDrawScore();

	}

	

}


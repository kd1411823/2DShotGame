#include "Score_Result.h"
#include "Scene.h"

void C_Score_Result::Init()
{
	m_keyFlg = false; // キーフラグ
	m_decreaseAlphaFlg = false; // フェードアウトフラグ
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

void C_Score_Result::ToTitle()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();


	if (GetAsyncKeyState('T') & 0x8000)
	{
		if (!m_keyFlg)
		{
			m_decreaseAlphaFlg = true;
			m_keyFlg = true;
		}
	}
	else
	{
		m_keyFlg = false;
	}

	if (m_decreaseAlphaFlg)
	{
		renderwipe->DecreaseAlpha();
	}

	if (renderwipe->GetAlpha() <= 0.0f)
	{
		m_p0wner->SetNowScene(TitleScene);
	}

}


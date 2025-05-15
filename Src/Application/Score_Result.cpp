#include "Score_Result.h"
#include "Scene.h"

void C_Score_Result::Init()
{
	m_keyFlg = false; // キーフラグ
	m_decreaseAlphaFlg = false; // フェードアウトフラグ
	m_stringDrawFlg = false; // 文字列描画フラグ
	m_isRisingAlpha = false;	// alpha値増減フラグ
	m_deltaAlpha = 0.02f;		// alpha値増減量
	m_stringAlpha = 0.00f; // 文字のalpha値
	m_textDrawCount = 0; // TimeUpText描画カウント
	m_textDrawFlg = false; // TimeUpText描画フラグ
	m_strScl = 10.0f; // textの拡大率
	m_minStrScl = 2.0f;// textの最小拡大率
	m_strAlpha = 0.0f; // textのalpha値
}

void C_Score_Result::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	if (playercircle->GetPlayerLife() != FourLife)return;

	if (m_stringDrawFlg)
	{
		systm->DrawStringGg({ -190 , -120 }, { 1.0f,1.0f }, L"space" ,{ RED ,m_stringAlpha});
		systm->DrawStringGg({ -190  ,-120 }, { 1.0f,1.0f }, L"      to title", { GREEN ,m_stringAlpha });
	}

	if (m_textDrawFlg)
	{
		systm->DrawStringGg({ -200  ,0 }, { m_strScl , m_strScl  }, L"f", { RED ,m_strAlpha });
		systm->DrawStringGg({ -120  ,0 }, { m_strScl , m_strScl  }, L"i", { RED ,m_strAlpha });
		systm->DrawStringGg({ -40  ,0 }, { m_strScl , m_strScl  }, L"n", { RED ,m_strAlpha });
		systm->DrawStringGg({  40  ,0 }, { m_strScl , m_strScl  }, L"i", { RED ,m_strAlpha });
		systm->DrawStringGg({ 120  ,0 }, { m_strScl , m_strScl  }, L"s", { RED ,m_strAlpha });
		systm->DrawStringGg({ 200  ,0 }, { m_strScl , m_strScl  }, L"h", { RED ,m_strAlpha });
	}

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


	if (playercircle->GetPlayerLife() == FourLife)
	{
		TimeUpText();
	}

	AlphaManager();

	



}

void C_Score_Result::AlphaManager()
{
	if (m_stringAlpha >= 1.0f)
	{
		m_isRisingAlpha = false;
	}

	if (m_stringAlpha <= 0.3f)
	{
		m_isRisingAlpha = true;
	}

	if (m_isRisingAlpha)
	{
		m_stringAlpha += m_deltaAlpha;
	}
	else
	{
		m_stringAlpha -= m_deltaAlpha;
	}
}

void C_Score_Result::TimeUpText()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Score_TextNumber* scoretextnumber[scoreDigits];
	C_Sound* sound = m_p0wner->GetSound();

	for (int i = 0; i < scoreDigits;i++)
	{
		scoretextnumber[i] = scoremanager->GetScoreTextNumber(i);
	}

	if (m_textDrawCount < INT_MAX)
	{
		m_textDrawCount++;
	}

	if (m_textDrawCount == 30)
	{
		sound->GetFinishSe().inst->Play();
	}

	if (m_textDrawCount < 60 * 2)
	{
		m_textDrawFlg = true;

		if (m_strAlpha < 1.0f)
		{
			m_strAlpha += m_deltaAlpha * 0.6f;
		}

		if (m_minStrScl < m_strScl)
		{
			m_strScl -= 0.1f;
		}
	}
	if (m_textDrawCount >= 60 * 2)
	{
		m_strAlpha -= m_deltaAlpha * 0.4f;

		if (m_strAlpha <= 0.0f)
		{
			m_textDrawFlg = false;
		}
	}

	if (m_textDrawCount >= 60 * 3 && !m_textDrawFlg)
	{
		for (int i = 0; i < scoreDigits;i++)
		{
			scoretextnumber[i]->AddDrawScore();
		}
	}
}

void C_Score_Result::ToTitle()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();
	C_Sound* sound = m_p0wner->GetSound();

	m_stringDrawFlg = true;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
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
		gamestartmanager->SetRenderSwitchFlg(false);
		renderwipe->DecreaseAlpha();
	}

	if (renderwipe->GetAlpha() <= 0.0f)
	{
		sound->GetBGM().inst->Stop();
		m_p0wner->Init();
	}

}


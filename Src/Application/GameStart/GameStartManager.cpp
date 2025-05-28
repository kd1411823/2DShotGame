#include "GameStartManager.h"
#include "../Scene/Scene.h"

C_GameStartManager::C_GameStartManager()
{
}

C_GameStartManager::~C_GameStartManager()
{
	gamestartnumberTex.Release();
	gamestartstringTex.Release();
	keyTex.Release();
	spaceTex.Release();
}

void C_GameStartManager::Init()
{

	gamestartnumberTex.Load("Texture/Number.png");
	gamestartstringTex.Load("Texture/start.png");

	keyTex.Load("Texture/key.png");
	spaceTex.Load("Texture/spacekey.png");

	m_gamestart_number.SetP0wner(m_p0wner);
	m_gamestart_number.SetTex(&gamestartnumberTex);
	m_gamestart_number.Init();



	for (int i = 0; i < KeyNum;i++)
	{
		m_control_key[i].SetP0wner(m_p0wner);
		if (i == 0)
		{
			m_control_key[i].SetTex(&spaceTex);
		}
		else
		{
			m_control_key[i].SetTwoTex(&keyTex);
		}
		m_control_key[i].Init((eKeyType)i);
	}

	
	m_gameStartFlg = false; // ゲームスタートフラグ
	m_startCountFrame = 60 * 6; // スタートまでのカウント
	m_startCountTime = m_startCountFrame / 60; // スタートまでのタイマー
	m_startCountFlg = false; // スタートカウントを開始するフラグ
	m_addAlphaFlg = false; // alpha値を上げるフラグ
	m_decreaseAlphaFlg = false; // alpha値を下げているフラグ
	m_isRisingAlpha = false;	// alpha値増減フラグ
	m_deltaAlpha = 0.02f;		// alpha値増減量
	m_stringAlpha = 1.0f; // 文字のalpha値
	m_renderSwitchFlg = false;// レンダーターゲット切り替え
}

void C_GameStartManager::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_gamestart_number.Draw();

	for (int i = 0; i < KeyNum;i++)
	{
		m_control_key[i].Draw();
	}

	if (!m_gameStartFlg && !m_startCountFlg)
	{
		systm->DrawStringGg({ 320 , 300 }, { 1.0f,1.0f }, L"game start", { GREEN , m_stringAlpha });
		systm->DrawStringGg({ 400 , 250 }, { 1.0f,1.0f }, L"enter", { RED , m_stringAlpha });
	}

}

void C_GameStartManager::Update()
{
	m_gamestart_number.Update();

	for (int i = 0; i < KeyNum;i++)
	{
		m_control_key[i].Update();
	}
}

void C_GameStartManager::Action()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();

	AlphaManager();

	m_startCountTime = m_startCountFrame / 60; // スタートまでのタイマー

	if (renderwipe->GetAlpha() < 1.0f)
	{
		m_addAlphaFlg = true;
	}
	
	if (m_addAlphaFlg)
	{
		renderwipe->AddAlpha(0.01f);
	}

	if (renderwipe->GetAlpha() >= 1.0f)
	{
		TutorialSkip();
	}

	if (m_startCountFlg)
	{
		StartGameCount();
	}

	m_gamestart_number.Action();

	for (int i = 0; i < KeyNum;i++)
	{
		m_control_key[i].Action();
	}

}

void C_GameStartManager::StartGameCount()
{
	C_Sound* sound = m_p0wner->GetSound();

	if (m_gameStartFlg)return;

	m_startCountFrame--;


	if (m_startCountFrame <= 0)
	{
		m_renderSwitchFlg = true;
		m_gameStartFlg = true;
	}
}

void C_GameStartManager::TutorialSkip()
{
	
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_startCountFlg = true;
	}

}

void C_GameStartManager::AlphaManager()
{
	if (m_gameStartFlg)return;

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



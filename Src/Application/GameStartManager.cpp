#include "GameStartManager.h"
#include "Scene.h"

C_GameStartManager::C_GameStartManager()
{
}

C_GameStartManager::~C_GameStartManager()
{
	gamestartnumberTex.Release();
	gamestartstringTex.Release();
}

void C_GameStartManager::Init()
{

	gamestartnumberTex.Load("Texture/Number.png");
	gamestartstringTex.Load("Texture/start.png");

	m_gamestart_number.SetP0wner(m_p0wner);
	m_gamestart_number.SetTex(&gamestartnumberTex);
	m_gamestart_number.Init();

	
	m_gameStartFlg = false; // ゲームスタートフラグ
	m_startCountFrame = 60 * 7; // スタートまでのカウント
	m_startCountTime = m_startCountFrame / 60; // スタートまでのタイマー
	m_startCountFlg = false; // スタートカウントを開始するフラグ
	m_addAlphaFlg = false; // alpha値を上げるフラグ
	m_decreaseAlphaFlg = false; // alpha値を下げているフラグ
}

void C_GameStartManager::Draw()
{
	m_gamestart_number.Draw();

	
}

void C_GameStartManager::Update()
{
	m_gamestart_number.Update();

	
}

void C_GameStartManager::Action()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();

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
		m_startCountFlg = true;
	}

	if (m_startCountFlg)
	{
		StartGameCount();
	}

	m_gamestart_number.Action();

}

void C_GameStartManager::StartGameCount()
{
	if (m_gameStartFlg)return;

	m_startCountFrame--;


	if (m_startCountFrame <= 0)
	{
		m_gameStartFlg = true;
	}
}



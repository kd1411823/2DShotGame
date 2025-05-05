#include "GameStartManager.h"
#include "Scene.h"

C_GameStartManager::C_GameStartManager()
{
}

C_GameStartManager::~C_GameStartManager()
{
}

void C_GameStartManager::Init()
{
	m_gameStartFlg = false; // ゲームスタートフラグ
	m_startCount = 60 * 5; // スタートまでのカウント
	m_addAlphaFlg = false; // alpha値を上げるフラグ
	m_decreaseAlphaFlg = false; // alpha値を下げているフラグ
}

void C_GameStartManager::Draw()
{
}

void C_GameStartManager::Update()
{
}

void C_GameStartManager::Action()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();
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
		StartGameCount();
	}

}

void C_GameStartManager::StartGameCount()
{
	if (m_gameStartFlg)return;

	m_startCount--;


	if (m_startCount <= 0)
	{
		m_gameStartFlg = true;
	}
}

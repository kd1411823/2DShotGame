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
	m_gameStartFlg = false; // �Q�[���X�^�[�g�t���O
	m_startCount = 60 * 5; // �X�^�[�g�܂ł̃J�E���g
	m_addAlphaFlg = false; // alpha�l���グ��t���O
	m_decreaseAlphaFlg = false; // alpha�l�������Ă���t���O
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

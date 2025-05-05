#include "TitleManager.h"
#include "Scene.h"

C_TitleManager::C_TitleManager()
{
}

C_TitleManager::~C_TitleManager()
{
	titlegamenameTex.Release();
	titlebackgroundTex.Release();
	titlebackcircleTex.Release();
}

void C_TitleManager::Init()
{

	titlegamenameTex.Load("Texture/titlegamename.png");
	titlebackgroundTex.Load("Texture/background.png");
	titlebackcircleTex.Load("Texture/back_circle.png");

	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].SetP0wner(m_p0wner);
		m_title_gamenametext[i].SetTex(&titlegamenameTex);
		m_title_gamenametext[i].Init(i);
	}

	m_title_background.SetP0wner(m_p0wner);
	m_title_background.SetTex(&titlebackgroundTex);
	m_title_background.Init();

	m_title_backcircle.SetP0wner(m_p0wner);
	m_title_backcircle.SetTex(&titlebackcircleTex);
	m_title_backcircle.Init();
}

void C_TitleManager::Draw()
{
	m_title_background.Draw();

	m_title_backcircle.Draw();

	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].Draw();
	}
}

void C_TitleManager::Update()
{
	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].Update();
	}

	m_title_background.Update();

	m_title_backcircle.Update();
}

void C_TitleManager::Action()
{
	ToGame();

	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].Action();
	}

	m_title_background.Action();

	m_title_backcircle.Action();
}

void C_TitleManager::ToGame()
{

	if (GetAsyncKeyState('G') & 0x8000)
	{
		m_p0wner->GameInit();
		m_p0wner->SetNowScene(GameScene);
	}
}

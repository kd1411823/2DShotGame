#include "TitleManager.h"
#include "Scene.h"

C_TitleManager::C_TitleManager()
{
}

C_TitleManager::~C_TitleManager()
{
	titlebackgroundTex.Release();
	titlebackcircleTex.Release();
	titlepushtoTex.Release();
}

void C_TitleManager::Init()
{

	titlebackgroundTex.Load("Texture/background.png");
	titlebackcircleTex.Load("Texture/back_circle.png");
	titlepushtoTex.Load("Texture/pushto.png");

	m_addAlphaFlg = false; // alpha値を上げるか？フラグ
	m_decreaseAlphaFlg = false; // alpha値を下げているフラグ

	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].SetP0wner(m_p0wner);
		m_title_gamenametext[i].Init(i);
	}

	m_title_background.SetP0wner(m_p0wner);
	m_title_background.SetTex(&titlebackgroundTex);
	m_title_background.Init();

	m_title_backcircle.SetP0wner(m_p0wner);
	m_title_backcircle.SetTex(&titlebackcircleTex);
	m_title_backcircle.Init();

	m_drawEnemy.SetP0wner(m_p0wner);
	m_drawEnemy.Init();

	for (int i = 0;i < titleText;i++)
	{
		m_titletext[i].SetP0wner(m_p0wner);
		m_titletext[i].SetTex(&titlepushtoTex);
		m_titletext[i].Init(i);
	}

}

void C_TitleManager::Draw()
{
	m_title_background.Draw();

	m_title_backcircle.Draw();


	for (int i = 0;i < titleText;i++)
	{
		m_titletext[i].Draw();
	}

	m_drawEnemy.Draw();

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

	m_drawEnemy.Update();

	for (int i = 0;i < titleText;i++)
	{
		m_titletext[i].Update();
	}
}

void C_TitleManager::Action()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();

	if (renderwipe->GetAlpha() < 1.0f)
	{
		m_addAlphaFlg = true;
	}

	if (m_addAlphaFlg && !m_decreaseAlphaFlg)
	{
		renderwipe->AddAlpha(0.01f);
	}

	if (renderwipe->GetAlpha() >= 1.0f)
	{
		ToGame();
	}

	for (int i = 0;i < gameNameText;i++)
	{
		m_title_gamenametext[i].Action();
	}

	m_title_background.Action();

	m_title_backcircle.Action();

	m_drawEnemy.Action();

	for (int i = 0;i < titleText;i++)
	{
		m_titletext[i].Action();
	}
}

void C_TitleManager::ToGame()
{
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_decreaseAlphaFlg = true;
		m_p0wner->GameInit();
	}

	if (m_decreaseAlphaFlg)
	{
		renderwipe->DecreaseAlpha(0.01f);
	}

	if (renderwipe->GetAlpha() <= 0.0f)
	{
		m_p0wner->SetNowScene(GameScene);
	}

}

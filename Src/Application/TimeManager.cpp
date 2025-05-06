#include "TimeManager.h"
#include "Scene.h"

C_TimeManager::C_TimeManager()
{

}

C_TimeManager::~C_TimeManager()
{
	numberTex.Release();
}

void C_TimeManager::Init()
{
	numberTex.Load("Texture/Number.png");

	m_timeClockCircle.SetP0wner(m_p0wner);
	m_timeClockCircle.Init();

	m_timeClockHands.SetP0wner(m_p0wner);
	m_timeClockHands.Init();

	for (int i = 0;i < timeDigits;i++)
	{
		m_timeClockNumber[i].SetP0wner(m_p0wner);
		m_timeClockNumber[i].SetTex(&numberTex);
		m_timeClockNumber[i].Init(i);
	}

	m_frameTime = 60 * 120; // フレーム
	m_timer = m_frameTime / 60; // タイマー
	m_isTimeLeftFlg = false; // タイムが残っているかいないか(true:残っている false:残っていない)
}

void C_TimeManager::Draw()
{
	C_GameStartManager* gamestartmanager = m_p0wner->GetGameStartManager();

	if (!gamestartmanager->GetGameStartFlg())return;

	m_timeClockCircle.Draw();
	m_timeClockHands.Draw();
	for (int i = 0;i < timeDigits;i++)
	{
		m_timeClockNumber[i].Draw();
	}
}

void C_TimeManager::Update()
{
	m_timeClockCircle.Update();
	m_timeClockHands.Update();
	for (int i = 0;i < timeDigits;i++)
	{
		m_timeClockNumber[i].Update();
	}

}

void C_TimeManager::Action()
{
	Timer();

	if (m_timer > 0)
	{
		m_isTimeLeftFlg = true;
	}

	m_timeClockCircle.Action();
	m_timeClockHands.Action();
	for (int i = 0;i < timeDigits;i++)
	{
		m_timeClockNumber[i].Action();
	}
}

void C_TimeManager::Timer()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (playercircle->GetPlayerLife() == FourLife)
	{
		return;
	}
	if (m_timer <= 0) 
	{
		m_isTimeLeftFlg = false;
		playercircle->SetPlayerLife(FourLife);
		return;
	}
	

	if (m_frameTime > 0)
	{
		m_frameTime--;
	}

	m_timer = m_frameTime / 60;

	
	// 残り10秒間になったら色変更
	if (m_timer <= 10)
	{
		m_timeClockCircle.SetClr({ RED,1.0f });
		for (int i = 0;i < timeDigits;i++)
		{
			m_timeClockNumber[i].SetClr({ RED,1.0f });
		}
	}
	
	if (m_timer <= 0)
	{
		m_timer = 0;
	}
}

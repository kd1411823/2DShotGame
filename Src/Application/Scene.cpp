#include "ParticleBase.h"
#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_backgroud.Draw();
	m_back_circle.Draw();
	m_player_circle.Draw();
	m_enemy_manager.Draw();
	m_player.Draw();
}

void Scene::Update()
{
	if (GetAsyncKeyState('1') & 0x8000)
	{
		m_player_circle.SetPlayerLife(OneLife);
	}
	if (GetAsyncKeyState('2') & 0x8000)
	{
		m_player_circle.SetPlayerLife(TwoLife);
	}
	if (GetAsyncKeyState('3') & 0x8000)
	{
		m_player_circle.SetPlayerLife(ThreeLife);
	}
	if (GetAsyncKeyState('4') & 0x8000)
	{
		m_player_circle.SetPlayerLife(FourLife);
	}

	m_backgroud.Action();
	m_back_circle.Action();
	m_player_circle.Action();
	m_player.Action();
	m_enemy_manager.Action();

	m_player.Update();
	m_player_circle.Update();
	m_backgroud.Update();
	m_back_circle.Update();
	m_enemy_manager.Update();
}

void Scene::Init()
{
	// 乱数初期化
	srand(timeGetTime());
	system("cls");


	m_cons.create();

	m_sound.SeLoad();
	m_sound.BgmLoad();

	backgroundTex.Load("Texture/background.png");
	backcircleTex.Load("Texture/backcircle.png");
	sunTex.Load("Texture/Sun.png");
	sun2Tex.Load("Texture/Sun2.png");

	m_sun.SetTex(&sunTex);
	m_backgroud.SetTex(&backgroundTex);
	m_back_circle.SetTex(&backcircleTex);
	m_player_circle.SetTex(&backcircleTex);
	

	m_particlebase.SetP0wner(this);
	m_sun.SetP0wner(this);
	m_sound.SetP0wner(this);
	m_backgroud.SetP0wner(this);
	m_back_circle.SetP0wner(this);
	m_player_circle.SetP0wner(this);
	m_player.SetP0wner(this);
	m_enemy_manager.SetP0wner(this);
	

	m_sun.Init();
	m_sound.Init();
	m_backgroud.Init();
	m_back_circle.Init();
	m_player_circle.Init();
	m_player.Init();
	m_enemy_manager.Init();
}

void Scene::Release()
{
	backgroundTex.Release();
	backcircleTex.Release();
	playercircleTex.Release();
	sunTex.Release();
	sun2Tex.Release();
	m_cons.destroy();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

#include "ParticleBase.h"
#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	switch (m_nowScene)
	{
	case TitleScene:
		TitleDraw();
		break;
	case GameScene:
		GameDraw();
		break;
	}


	

}

void Scene::TitleUpdate()
{
	if (GetAsyncKeyState('G') & 0x8000)
	{
		m_nowScene = GameScene;
	}
}

void Scene::TitleDraw()
{

}

void Scene::GameUpdate()
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
	m_scoremanager.Action();
	m_player.Action();
	m_enemy_manager.Action();
	m_timemanager.Action();

	m_renderwipe.ActionWipe();

	m_player.Update();
	m_player_circle.Update();
	m_scoremanager.Update();
	m_backgroud.Update();
	m_back_circle.Update();
	m_enemy_manager.Update();
	m_timemanager.Update();

	m_renderwipe.UpdateWipe();
	
}

void Scene::GameDraw()
{
	//描画先をバックバッファに切り替え
	D3D.SetBackBuffer();

	m_backgroud.Draw();
	m_renderwipe.DrawWipe();
}

void Scene::Update()
{

	switch (m_nowScene)
	{
	case TitleScene:
		TitleUpdate();
		break;
	case GameScene:
		GameUpdate();
		break;
	}
	
}

void Scene::DynamicDraw2D()
{
	// クリア
	tmpTex.ClearRenerTarget(Math::Color(0.0f, 0.0f, 0.0f, 0.0f));

	//描画先をテクスチャへ切り替え
	tmpTex.SetRenderTarget();

	m_backgroud.Draw();
	m_back_circle.Draw();
	m_scoremanager.Draw();
	m_player_circle.Draw();
	m_enemy_manager.Draw();
	m_player.Draw();
	m_timemanager.Draw();
}

void Scene::Init()
{
	// 乱数初期化
	srand(timeGetTime());
	system("cls");

	m_nowScene = GameScene;

	//描画ターゲット用テクスチャ作成
	tmpTex.CreateRenderTarget(ScrnWid, ScrnHgt);

	m_renderwipe.SetP0wner(this);
	m_renderwipe.SetTex(&tmpTex);
	m_renderwipe.InitWipe();


	m_cons.create();

	m_sound.SeLoad();
	m_sound.BgmLoad();

	backgroundTex.Load("Texture/background.png");
	backcircleTex.Load("Texture/back_circle.png");

	m_backgroud.SetTex(&backgroundTex);
	m_back_circle.SetTex(&backcircleTex);
	m_player_circle.SetTex(&backcircleTex);
	

	m_sound.SetP0wner(this);
	m_backgroud.SetP0wner(this);
	m_back_circle.SetP0wner(this);
	m_player_circle.SetP0wner(this);
	m_scoremanager.SetP0wner(this);
	m_player.SetP0wner(this);
	m_enemy_manager.SetP0wner(this);
	m_timemanager.SetP0wner(this);

	m_sound.Init();
	m_backgroud.Init();
	m_back_circle.Init();
	m_player_circle.Init();
	m_scoremanager.Init();
	m_player.Init();
	m_enemy_manager.Init();
	m_timemanager.Init();
}

void Scene::Release()
{
	tmpTex.Release();
	backgroundTex.Release();
	backcircleTex.Release();
	playercircleTex.Release();
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

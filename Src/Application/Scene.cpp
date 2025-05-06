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
	m_titlemanager.Action();
	m_renderwipe.ActionWipe();

	m_titlemanager.Update();
	m_renderwipe.UpdateWipe();
}

void Scene::TitleDynamicDraw()
{
	m_titlemanager.Draw();
}

void Scene::TitleDraw()
{
	//�`�����o�b�N�o�b�t�@�ɐ؂�ւ�
	D3D.SetBackBuffer();

	m_backgroud.Draw();
	m_renderwipe.DrawWipe();

	
}

void Scene::TitleInit()
{

	m_titlemanager.SetP0wner(this);
	m_titlemanager.Init();
}

void Scene::GameUpdate()
{

	m_gamestartmanager.Action();
	m_player.Action();
	m_player_circle.Action();



	m_gamestartmanager.Update();
	m_player.Update();
	m_player_circle.Update();


	if (m_gamestartmanager.GetGameStartFlg())
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
		m_scoremanager.Action();
		m_enemy_manager.Action();
		m_timemanager.Action();

		m_renderwipe.ActionWipe();

	
		m_scoremanager.Update();
		m_backgroud.Update();
		m_back_circle.Update();
		m_enemy_manager.Update();
		m_timemanager.Update();

		m_renderwipe.UpdateWipe();
	}
}

void Scene::GameDynamicDraw()
{
	m_backgroud.Draw();
	m_back_circle.Draw();
	m_scoremanager.Draw();
	m_player_circle.Draw();
	m_enemy_manager.Draw();
	m_player.Draw();
	m_timemanager.Draw();
	m_gamestartmanager.Draw();
}

void Scene::GameDraw()
{
	//�`�����o�b�N�o�b�t�@�ɐ؂�ւ�
	D3D.SetBackBuffer();

	m_backgroud.Draw();
	m_renderwipe.DrawWipe();
}

void Scene::GameInit()
{
	//�`��^�[�Q�b�g�p�e�N�X�`���쐬
	tmpTex.CreateRenderTarget(ScrnWid, ScrnHgt);

	m_renderwipe.SetP0wner(this);
	m_renderwipe.SetTex(&tmpTex);
	m_renderwipe.InitWipe();


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
	
	m_sound.Update();
}

void Scene::DynamicDraw2D()
{
	// �N���A
	tmpTex.ClearRenerTarget(Math::Color(0.0f, 0.0f, 0.0f, 0.0f));

	//�`�����e�N�X�`���֐؂�ւ�
	tmpTex.SetRenderTarget();

	switch (m_nowScene)
	{
	case TitleScene:
		TitleDynamicDraw();
		break;
	case GameScene:
		GameDynamicDraw();
		break;
	}
	
	
}

void Scene::Init()
{
	// ����������
	srand(timeGetTime());
	system("cls");

	m_cons.create();

	m_sound.SetP0wner(this);
	m_sound.Init();
	m_sound.SeLoad();
	m_sound.BgmLoad();

	m_gamestartmanager.SetP0wner(this);
	m_gamestartmanager.Init();

	m_nowScene = TitleScene;


	TitleInit();

	GameInit();
	
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

	// �f�o�b�O�E�B���h�E
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

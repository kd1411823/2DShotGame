#include "main.h"
#include "Scene.h"
#include "Sun.h"

void Scene::Draw2D()
{
	// 描画
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
	//描画先をバックバッファに切り替え
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

	//　ゲームスタートしたら実行する
	if (m_gamestartmanager.GetGameStartFlg())
	{
		m_backgroud.Action();
		m_back_circle.Action();
		m_scoremanager.Action();
		m_enemy_manager.Action();
		m_timemanager.Action();

		m_renderwipe.ActionWipe();
		m_player_renderwipe.ActionWipe();
	
		m_scoremanager.Update();
		m_backgroud.Update();
		m_back_circle.Update();
		m_enemy_manager.Update();
		m_timemanager.Update();

		m_renderwipe.UpdateWipe();
		m_player_renderwipe.UpdateWipe();
	}
}

void Scene::GameDynamicDraw()
{
	// 全描画
	if (!m_gamestartmanager.GetRenderSwitchFlg())
	{
		m_back_circle.Draw();
		m_enemy_manager.Draw();

		m_scoremanager.Draw();
		m_timemanager.Draw();
		m_player_circle.Draw();
		m_player.Draw();
		m_gamestartmanager.Draw();
	}
	else // 敵系だけ描画
	{
		m_back_circle.Draw();
		m_enemy_manager.Draw();
	}
	
}

void Scene::GameDraw()
{
	m_backgroud.Draw();
	
	{
		C_Drop_Bullet* dropbullet[DropBulletNum];
		for (int i = 0;i < DropBulletNum;i++)
		{
			dropbullet[i] = m_player.GetDropBullet(i);
		}
		C_Player_BulletPredictionLine* playerbulletpredictionline[pBulletLineNum];
		for (int i = 0;i < pBulletLineNum;i++)
		{
			playerbulletpredictionline[i] = m_player.GetPlayerBulletPredictionLine(i);
		}
		C_Player_BulletPredictionTriangle* playerbulletpredictiontirangle = m_player.GetPlayerBulletPredictionTriangle();

		for (int i = 0;i < DropBulletNum;i++)
		{
			if (m_player_circle.GetPlayerLife() != FourLife)
			{
				if (dropbullet[i]->GetAlive())
				{
					dropbullet[i]->GetSun()->Draw();
				}
			}
		}

		if (m_player.GetDrawBulletPredictionFlg())
		{
			for (int i = 0;i < pBulletLineNum;i++)
			{
				if (!(i > m_player_circle.GetBulletPredictionLineDeleteNo()))
				{
					playerbulletpredictionline[i]->GetSun()->Draw();
				}
			}
			playerbulletpredictiontirangle->GetSun()->Draw();
		}

		m_player.GetSun()->Draw();
		
	}

	m_player_renderwipe.DrawWipe();
	
	if (m_gamestartmanager.GetRenderSwitchFlg())
	{
		D3D.SetBlendState(BlendMode::Add);
	}
	m_renderwipe.DrawWipe();

	D3D.SetBlendState(BlendMode::Alpha);

	// UI通常描画する
	if (m_gamestartmanager.GetRenderSwitchFlg())
	{
		m_timemanager.Draw();
		m_gamestartmanager.Draw();
	}
}

void Scene::GameInit()
{
	//描画ターゲット用テクスチャ作成
	tmpTex.CreateRenderTarget(ScrnWid, ScrnHgt);
	playertmpTex.CreateRenderTarget(ScrnWid, ScrnHgt);

	backgroundTex.Load("Texture/background.png");
	backcircleTex.Load("Texture/back_circle.png");

	m_renderwipe.SetP0wner(this);
	m_renderwipe.SetTex(&tmpTex);
	m_renderwipe.InitWipe();

	m_player_renderwipe.SetP0wner(this);
	m_player_renderwipe.SetTex(&playertmpTex);
	m_player_renderwipe.InitWipe(1.0f);

	m_sound.SeLoad();
	m_sound.BgmLoad();

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

	m_systm.Init();
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
	
	// クリア
	tmpTex.ClearRenerTarget(Math::Color(0.0f, 0.0f, 0.0f, 0.0f));

	//描画先をテクスチャへ切り替え
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
	
	// クリア
	playertmpTex.ClearRenerTarget(Math::Color(0.0f, 0.0f, 0.0f, 0.0f));

	//描画先をテクスチャへ切り替え
	playertmpTex.SetRenderTarget();

	if (m_gamestartmanager.GetRenderSwitchFlg())
	{
		// プレイヤー系
		m_scoremanager.Draw();
		m_player_circle.Draw();
		m_player.Draw();
	}
	//描画先をバックバッファに切り替え
	D3D.SetBackBuffer();
}

void Scene::Init()
{
	// 乱数初期化
	srand(timeGetTime());
	system("cls");

	// コンソール
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
	playertmpTex.Release();
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

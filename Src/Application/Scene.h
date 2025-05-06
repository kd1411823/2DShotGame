#pragma once
#include "RenderWipe.h"
#include "Player.h"
#include "Player_Circle.h"
#include "Background.h"
#include "Back_Circle.h"
#include "EnemyManager.h"
#include "ParticleBase.h"
#include "ScoreManager.h"
#include "TimeManager.h"
#include "TitleManager.h"
#include "GameStartManager.h"
#include "Systm.h"
#include "Sound.h"
#include "Console.h"


class Scene
{
private:

	// テクスチャ
	KdTexture tmpTex;	//レンダーターゲット切り替え用
	KdTexture backgroundTex;
	KdTexture backcircleTex;
	KdTexture playercircleTex;

	// インスタンス
	C_RenderWipe m_renderwipe;
	C_Background m_backgroud;
	C_Back_Circle m_back_circle;
	C_Player m_player;
	C_Player_Circle m_player_circle;
	C_Cons   m_cons;
	C_Sound  m_sound;
	C_Systm  m_systm;
	C_EnemyManager m_enemy_manager;
	C_ParticleBase m_particlebase;
	C_ScoreManager m_scoremanager;
	C_TimeManager m_timemanager;
	C_TitleManager m_titlemanager;
	C_GameStartManager m_gamestartmanager;

	eSceneType m_nowScene;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	//テクスチャへの描画処理
	void DynamicDraw2D();

	// 描画処理
	void Draw2D();

	void TitleUpdate();

	void TitleDynamicDraw();

	void TitleDraw();

	void TitleInit();

	void GameUpdate();

	void GameDynamicDraw();

	void GameDraw();

	void GameInit();

	// GUI処理
	void ImGuiUpdate();


	void SetNowScene(eSceneType a_nowScene) { m_nowScene = a_nowScene; }
	
	C_RenderWipe* GetRenderWipe() { return &m_renderwipe; }
	C_Player* GetPlayer() { return &m_player; }
	C_Player_Circle* GetPlayer_Circle() { return &m_player_circle; }
	C_Systm* GetSystm() { return &m_systm; }
	C_Background* GetBackground() { return &m_backgroud; }
	C_Back_Circle* GetBack_Circle() { return &m_back_circle; }
	C_EnemyManager* GetEnemyManager() { return &m_enemy_manager; }
	C_ScoreManager* GetScoreManager() { return &m_scoremanager;}
	C_TimeManager* GetTimeManager() { return &m_timemanager; }
	C_TitleManager* GetTitleManager() { return &m_titlemanager; }
	C_GameStartManager* GetGameStartManager() { return &m_gamestartmanager; }
	C_Sound* GetSound() { return &m_sound; }

	eSceneType GetSceneType() { return m_nowScene; }

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()

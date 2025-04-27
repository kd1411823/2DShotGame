#pragma once
#include "Player.h"
#include "Player_Circle.h"
#include "Background.h"
#include "Back_Circle.h"
#include "EnemyManager.h"
#include "ParticleBase.h"
#include "ScoreManager.h"
#include "Sun.h"
#include "Systm.h"
#include "Sound.h"
#include "Console.h"


class Scene
{
private:

	// �e�N�X�`��
	KdTexture backgroundTex;
	KdTexture backcircleTex;
	KdTexture playercircleTex;
	KdTexture sunTex;
	KdTexture sun2Tex;

	// �C���X�^���X
	C_Background m_backgroud;
	C_Back_Circle m_back_circle;
	C_Player m_player;
	C_Player_Circle m_player_circle;
	C_Sun m_sun;
	C_Cons   m_cons;
	C_Sound  m_sound;
	C_Systm  m_systm;
	C_EnemyManager m_enemy_manager;
	C_ParticleBase m_particlebase;
	C_ScoreManager m_scoremanager;

public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	// GUI����
	void ImGuiUpdate();

	
	C_Player* GetPlayer() { return &m_player; }
	C_Player_Circle* GetPlayer_Circle() { return &m_player_circle; }
	C_Systm* GetSystm() { return &m_systm; }
	C_Background* GetBackground() { return &m_backgroud; }
	C_Back_Circle* GetBack_Circle() { return &m_back_circle; }
	C_Sun* GetSun() { return &m_sun; }
	C_EnemyManager* GetEnemyManager() { return &m_enemy_manager; }
	C_ScoreManager* GetScoreManager() { return &m_scoremanager;}

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

#pragma once
#include "Player.h"
#include "Player_Circle.h"
#include "Enemy.h"
#include "Background.h"
#include "Back_Circle.h"
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
	KdTexture playerTex;
	KdTexture playercircleTex;
	KdTexture enemyTex;
	KdTexture sunTex;

	// �C���X�^���X
	C_Sun m_sun;
	C_Background m_backgroud;
	C_Back_Circle m_back_circle;
	C_Player m_player;
	C_Player_Circle m_player_circle;
	C_Enemy  m_enemy;
	C_Cons   m_cons;
	C_Sound  m_sound;
	C_Systm  m_systm;

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
	C_Enemy* GetEnemy() { return &m_enemy; }
	C_Sun* GetSun() { return &m_sun; }

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

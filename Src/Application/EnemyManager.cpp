#include "EnemyManager.h"

C_EnemyManager::C_EnemyManager()
{
}

C_EnemyManager::~C_EnemyManager()
{
	m_enemies.clear();
}

void C_EnemyManager::Init()
{
	
	m_spawnCount = 0; // スポーンカウント
	
}

void C_EnemyManager::Draw()
{

	for (auto& enemy : m_enemies)
	{
		enemy->Draw();
	}
}

void C_EnemyManager::Update()
{
	if (m_enemies.size() < EnemyMax)
	{
		m_spawnCount++;

		if (m_spawnCount > 60 * 5)
		{
			m_enemies.push_back(std::make_unique<C_Enemy>());
			m_spawnCount = 0;
		}
	}

	for (auto& enemy : m_enemies)
	{
		enemy->Update();
	}
}

void C_EnemyManager::Action()
{
	for (auto& enemy : m_enemies)
	{ 
		enemy->Action();
	}
}

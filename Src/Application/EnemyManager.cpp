#include "EnemyManager.h"
#include "Enemy.h"
#include "Scene.h"

C_EnemyManager::C_EnemyManager()
{
}

C_EnemyManager::~C_EnemyManager()
{
	m_enemies.clear();
}

void C_EnemyManager::Init()
{
	m_enemies.clear();
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

		if (m_spawnCount > 60 * 2)
		{
			std::unique_ptr<C_Enemy> newEnemy = std::make_unique<C_Enemy>();
			newEnemy->SetP0wner(m_p0wner);
			m_enemies.push_back(std::move(newEnemy));
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
	PlayerBulletHit();

	for (auto& enemy : m_enemies)
	{ 
		enemy->Action();
	}
}

void C_EnemyManager::PlayerBulletHit()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player* player = m_p0wner->GetPlayer();
	C_RenderWipe* renderwipe = m_p0wner->GetRenderWipe();
	C_Bullet* pbullet[BulletNum];
	for (int i = 0;i < BulletNum;i++)pbullet[i] = player->GetBullet(i);
	
	for (auto enemy = m_enemies.begin(); enemy != m_enemies.end(); )
	{
		bool erased = false;

		for (int i = 0; i < BulletNum; ++i)
		{
			if (!pbullet[i]->GetAlive()) continue;

			const tTry playerbulletEnemytTry = systm->CalcPythag((*enemy)->GetPos(), pbullet[i]->GetPos());
			const float bulletEnemyhypn = pbullet[i]->GetRadius() + (*enemy)->GetRadius();

			if (playerbulletEnemytTry.hypn < bulletEnemyhypn)
			{
				pbullet[i]->Hit();
				(*enemy)->TakeDamage();
				renderwipe->SetShakeTime(10);

				if (!(*enemy)->GetAlive())
				{
					
					// 敵を削除し、イテレータを更新してループを抜ける
					enemy = m_enemies.erase(enemy);
					erased = true;
				}
				break;
			}

		}
		// 倒されてなかったらイテレータをまわす
		if (!erased)
		{
			++enemy;
		}
	}



}



#pragma once

class C_Enemy;
class Scene;

class C_EnemyManager
{
public:

	C_EnemyManager();
	~C_EnemyManager();

	void Init();
	void Draw();
	void Update();
	void Action();

	// プレイヤーの弾と敵の当たり判定する
	void PlayerBulletHit();

	void SetP0wner(Scene* a_p0wner) { m_p0wner = a_p0wner; }
	

private:

	Scene* m_p0wner = nullptr; 
	std::vector<std::unique_ptr<C_Enemy>> m_enemies; // 動的に敵を管理
	int    m_spawnCount; // スポーンカウント


};
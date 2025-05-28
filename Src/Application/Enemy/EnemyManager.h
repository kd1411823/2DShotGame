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

	// �v���C���[�̒e�ƓG�̓����蔻�肷��
	void PlayerBulletHit();

	void SetP0wner(Scene* a_p0wner) { m_p0wner = a_p0wner; }
	

private:

	Scene* m_p0wner = nullptr; 
	std::vector<std::unique_ptr<C_Enemy>> m_enemies; // ���I�ɓG���Ǘ�
	int    m_spawnCount; // �X�|�[���J�E���g


};
#pragma once
#include "Systm.h"

class Scene;

class C_Sound 
{
public:

	C_Sound():m_p0wner(nullptr){}
	~C_Sound(){}

	void Init();
	void SeLoad();
	void BgmLoad();
	void Update();

	void SetP0wner(Scene* a_p0wner) { m_p0wner = a_p0wner; }

	tSnd GetGetBulletSe() { return m_getBulletSe; }
	tSnd GetShotBulletSe() { return m_shotBulletSe; }
	tSnd GetEnemyHitSe() { return m_enemyHitSe; }

private:

	Scene* m_p0wner;

	// ���ʒ���	
	float m_seeVol;			//  SE �{�����[��
	float m_bgmVol;			// BGM �{�����[��


	tSnd m_getBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������
	tSnd m_shotBulletSe;// �e�𔭎˂����Ƃ��̉�
	tSnd m_enemyHitSe; // �G�ƒe���q�b�g�����Ƃ��̉�
};
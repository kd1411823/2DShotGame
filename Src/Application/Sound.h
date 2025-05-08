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

	tSnd GetOneGetBulletSe() { return m_oneGetBulletSe; }
	tSnd GetTwoGetBulletSe() { return m_twoGetBulletSe; }
	tSnd GetThreeGetBulletSe() { return m_threeGetBulletSe; }
	tSnd GetFourGetBulletSe() { return m_fourGetBulletSe; }
	tSnd GetFiveGetBulletSe() { return m_fiveGetBulletSe; }

	tSnd GetShotBulletSe() { return m_shotBulletSe; }
	tSnd GetEnemyHitSe() { return m_enemyHitSe; }

private:

	Scene* m_p0wner;

	// ���ʒ���	
	float m_seeVol;			//  SE �{�����[��
	float m_bgmVol;			// BGM �{�����[��


	tSnd m_oneGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������1
	tSnd m_twoGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������2
	tSnd m_threeGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������3
	tSnd m_fourGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������4
	tSnd m_fiveGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������5
	tSnd m_shotBulletSe;// �e�𔭎˂����Ƃ��̉�
	tSnd m_enemyHitSe; // �G�ƒe���q�b�g�����Ƃ��̉�
};
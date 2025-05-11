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

	tSnd GetBGM() { return m_BGM; }
	tSnd GetOneGetBulletSe() { return m_oneGetBulletSe; }
	tSnd GetTwoGetBulletSe() { return m_twoGetBulletSe; }
	tSnd GetThreeGetBulletSe() { return m_threeGetBulletSe; }
	tSnd GetFourGetBulletSe() { return m_fourGetBulletSe; }
	tSnd GetFiveGetBulletSe() { return m_fiveGetBulletSe; }

	tSnd GetShotBulletSe() { return m_shotBulletSe; }
	tSnd GetEnemyHitSe() { return m_enemyHitSe; }
	tSnd GetPlayerCircleHitSe() { return m_playerCircleHitSe; }

	tSnd GetStartSe() { return m_startSe; }
	tSnd GetStartCountSe() { return m_startCountSe; }
	tSnd GetFinishSe() { return m_finishSe; }
	tSnd GetAddScoreSe() { return m_addScoreSe; }


private:

	Scene* m_p0wner;

	// ���ʒ���	
	float m_seeVol;			//  SE �{�����[��
	float m_bgmVol;			// BGM �{�����[��

	tSnd m_BGM;// BGM
	tSnd m_oneGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������1
	tSnd m_twoGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������2
	tSnd m_threeGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������3
	tSnd m_fourGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������4
	tSnd m_fiveGetBulletSe;	// �e(�擾�I�u�W�F�N�g)���l��������5
	tSnd m_shotBulletSe;// �e�𔭎˂����Ƃ��̉�
	tSnd m_enemyHitSe; // �G�ƒe���q�b�g�����Ƃ��̉�
	tSnd m_playerCircleHitSe; // �v���C���[�~�ƒe���q�b�g�����Ƃ��̉�
	tSnd m_startSe; // �X�^�[�g��
	tSnd m_startCountSe;// �X�^�[�g�J�E���g��
	tSnd m_finishSe;// �I����
	tSnd m_addScoreSe;// �X�R�A���Z��
};
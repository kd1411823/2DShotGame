#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 0.2f;			//  SE �{�����[��
	m_bgmVol = 0.2f;			// BGM �{�����[��
}

void C_Sound::SeLoad()
{

	m_getBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_getBulletSe.data->Load("Sound/dropbullet2.wav");					// ���f�[�^�ǂݍ���
	m_getBulletSe.inst = m_getBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_getBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_getBulletSe.endFlg = false;

	m_shotBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_shotBulletSe.data->Load("Sound/shotbullet5.wav");					// ���f�[�^�ǂݍ���
	m_shotBulletSe.inst = m_shotBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_shotBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_shotBulletSe.endFlg = false;

	m_enemyHitSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_enemyHitSe.data->Load("Sound/enemyhit.wav");					// ���f�[�^�ǂݍ���
	m_enemyHitSe.inst = m_enemyHitSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_enemyHitSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_enemyHitSe.endFlg = false;
}

void C_Sound::BgmLoad()
{

}

void C_Sound::Update()
{

}

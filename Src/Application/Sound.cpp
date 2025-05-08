#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 0.2f;			//  SE �{�����[��
	m_bgmVol = 0.2f;			// BGM �{�����[��
}

void C_Sound::SeLoad()
{

	m_oneGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_oneGetBulletSe.data->Load("Sound/dropbullet1.wav");					// ���f�[�^�ǂݍ���
	m_oneGetBulletSe.inst = m_oneGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_oneGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_oneGetBulletSe.endFlg = false;

	m_twoGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_twoGetBulletSe.data->Load("Sound/dropbullet2.wav");					// ���f�[�^�ǂݍ���
	m_twoGetBulletSe.inst = m_twoGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_twoGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_twoGetBulletSe.endFlg = false;

	m_threeGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_threeGetBulletSe.data->Load("Sound/dropbullet3.wav");					// ���f�[�^�ǂݍ���
	m_threeGetBulletSe.inst = m_threeGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_threeGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_threeGetBulletSe.endFlg = false;

	m_fourGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_fourGetBulletSe.data->Load("Sound/dropbullet3.wav");					// ���f�[�^�ǂݍ���
	m_fourGetBulletSe.inst = m_fourGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_fourGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_fourGetBulletSe.endFlg = false;

	m_fiveGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_fiveGetBulletSe.data->Load("Sound/dropbullet3.wav");					// ���f�[�^�ǂݍ���
	m_fiveGetBulletSe.inst = m_fiveGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_fiveGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_fiveGetBulletSe.endFlg = false;

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

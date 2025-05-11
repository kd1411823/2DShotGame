#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 0.18f;			//  SE �{�����[��
	m_bgmVol = 0.3f;			// BGM �{�����[��
	SeLoad();
	BgmLoad();
	

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
	m_fourGetBulletSe.data->Load("Sound/dropbullet4.wav");					// ���f�[�^�ǂݍ���
	m_fourGetBulletSe.inst = m_fourGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_fourGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_fourGetBulletSe.endFlg = false;

	m_fiveGetBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_fiveGetBulletSe.data->Load("Sound/dropbullet5.wav");					// ���f�[�^�ǂݍ���
	m_fiveGetBulletSe.inst = m_fiveGetBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_fiveGetBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_fiveGetBulletSe.endFlg = false;

	m_shotBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_shotBulletSe.data->Load("Sound/shotbullet.wav");					// ���f�[�^�ǂݍ���
	m_shotBulletSe.inst = m_shotBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_shotBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_shotBulletSe.endFlg = false;

	m_enemyHitSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_enemyHitSe.data->Load("Sound/enemyhit.wav");					// ���f�[�^�ǂݍ���
	m_enemyHitSe.inst = m_enemyHitSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_enemyHitSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_enemyHitSe.endFlg = false;

	m_playerCircleHitSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_playerCircleHitSe.data->Load("Sound/enemyhit.wav");					// ���f�[�^�ǂݍ���
	m_playerCircleHitSe.inst = m_playerCircleHitSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_playerCircleHitSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_playerCircleHitSe.endFlg = false;

	m_startSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_startSe.data->Load("Sound/start.wav");					// ���f�[�^�ǂݍ���
	m_startSe.inst = m_startSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_startSe.inst->SetVolume(m_seeVol * 0.8f);							// �{�����[������
	m_startSe.endFlg = false;

	m_startCountSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_startCountSe.data->Load("Sound/count.wav");					// ���f�[�^�ǂݍ���
	m_startCountSe.inst = m_startCountSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_startCountSe.inst->SetVolume(m_seeVol * 0.8f);							// �{�����[������
	m_startCountSe.endFlg = false;

	m_finishSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_finishSe.data->Load("Sound/finish.wav");					// ���f�[�^�ǂݍ���
	m_finishSe.inst = m_finishSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_finishSe.inst->SetVolume(m_seeVol);							// �{�����[������
	m_finishSe.endFlg = false;

	m_addScoreSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_addScoreSe.data->Load("Sound/score.wav");					// ���f�[�^�ǂݍ���
	m_addScoreSe.inst = m_addScoreSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_addScoreSe.inst->SetVolume(m_seeVol * 0.8f);							// �{�����[������
	m_addScoreSe.endFlg = false;



}

void C_Sound::BgmLoad()
{
	m_BGM.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	m_BGM.data->Load("Sound/BGM.wav");					// ���f�[�^�ǂݍ���
	m_BGM.inst = m_BGM.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	m_BGM.inst->SetVolume(m_bgmVol);							// �{�����[������
	m_BGM.endFlg = false;
	m_BGM.inst->Play(true);
}

void C_Sound::Update()
{


	
}

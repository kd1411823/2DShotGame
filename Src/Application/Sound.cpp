#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 5.0f;			//  SE �{�����[��
	m_bgmVol = 5.0f;			// BGM �{�����[��
}

void C_Sound::SeLoad()
{

	//m_getBulletSe.data = std::make_shared<KdSoundEffect>();				// �������̈�m��
	//m_getBulletSe.data->Load("Sound/");									// ���f�[�^�ǂݍ���
	//m_getBulletSe.inst = m_getBulletSe.data->CreateInstance(false);		// �X�s�[�J�[�̃������̈�m��
	//m_getBulletSe.inst->SetVolume(m_seeVol);							// �{�����[������
	//m_getBulletSe.endFlg = false;
}

void C_Sound::BgmLoad()
{

}

void C_Sound::Update()
{

}

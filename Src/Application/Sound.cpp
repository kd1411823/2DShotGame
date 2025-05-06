#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 0.2f;			//  SE ボリューム
	m_bgmVol = 0.2f;			// BGM ボリューム
}

void C_Sound::SeLoad()
{

	m_getBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_getBulletSe.data->Load("Sound/dropbullet2.wav");					// 音データ読み込み
	m_getBulletSe.inst = m_getBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_getBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_getBulletSe.endFlg = false;

	m_shotBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_shotBulletSe.data->Load("Sound/shotbullet5.wav");					// 音データ読み込み
	m_shotBulletSe.inst = m_shotBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_shotBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_shotBulletSe.endFlg = false;

	m_enemyHitSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_enemyHitSe.data->Load("Sound/enemyhit.wav");					// 音データ読み込み
	m_enemyHitSe.inst = m_enemyHitSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_enemyHitSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_enemyHitSe.endFlg = false;
}

void C_Sound::BgmLoad()
{

}

void C_Sound::Update()
{

}

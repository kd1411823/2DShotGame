#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 5.0f;			//  SE ボリューム
	m_bgmVol = 5.0f;			// BGM ボリューム
}

void C_Sound::SeLoad()
{

	//m_getBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	//m_getBulletSe.data->Load("Sound/");									// 音データ読み込み
	//m_getBulletSe.inst = m_getBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	//m_getBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	//m_getBulletSe.endFlg = false;
}

void C_Sound::BgmLoad()
{

}

void C_Sound::Update()
{

}

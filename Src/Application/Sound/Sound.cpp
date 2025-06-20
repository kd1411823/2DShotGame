#include "Sound.h"

void C_Sound::Init()
{
	m_seeVol = 0.17f;			//  SE ボリューム
	m_bgmVol = 0.36f;			// BGM ボリューム
	SeLoad();
	BgmLoad();
	

}

void C_Sound::SeLoad()
{

	m_oneGetBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_oneGetBulletSe.data->Load("Sound/dropbullet1.wav");					// 音データ読み込み
	m_oneGetBulletSe.inst = m_oneGetBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_oneGetBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_oneGetBulletSe.endFlg = false;

	m_twoGetBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_twoGetBulletSe.data->Load("Sound/dropbullet2.wav");					// 音データ読み込み
	m_twoGetBulletSe.inst = m_twoGetBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_twoGetBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_twoGetBulletSe.endFlg = false;

	m_threeGetBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_threeGetBulletSe.data->Load("Sound/dropbullet3.wav");					// 音データ読み込み
	m_threeGetBulletSe.inst = m_threeGetBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_threeGetBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_threeGetBulletSe.endFlg = false;

	m_fourGetBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_fourGetBulletSe.data->Load("Sound/dropbullet4.wav");					// 音データ読み込み
	m_fourGetBulletSe.inst = m_fourGetBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_fourGetBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_fourGetBulletSe.endFlg = false;

	m_fiveGetBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_fiveGetBulletSe.data->Load("Sound/dropbullet5.wav");					// 音データ読み込み
	m_fiveGetBulletSe.inst = m_fiveGetBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_fiveGetBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_fiveGetBulletSe.endFlg = false;

	m_shotBulletSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_shotBulletSe.data->Load("Sound/shotbullet.wav");					// 音データ読み込み
	m_shotBulletSe.inst = m_shotBulletSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_shotBulletSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_shotBulletSe.endFlg = false;

	m_enemyHitSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_enemyHitSe.data->Load("Sound/enemyhit.wav");					// 音データ読み込み
	m_enemyHitSe.inst = m_enemyHitSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_enemyHitSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_enemyHitSe.endFlg = false;

	m_playerCircleHitSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_playerCircleHitSe.data->Load("Sound/enemyhit.wav");					// 音データ読み込み
	m_playerCircleHitSe.inst = m_playerCircleHitSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_playerCircleHitSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_playerCircleHitSe.endFlg = false;

	m_startSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_startSe.data->Load("Sound/start.wav");					// 音データ読み込み
	m_startSe.inst = m_startSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_startSe.inst->SetVolume(m_seeVol * 0.8f);							// ボリューム調整
	m_startSe.endFlg = false;

	m_startCountSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_startCountSe.data->Load("Sound/count.wav");					// 音データ読み込み
	m_startCountSe.inst = m_startCountSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_startCountSe.inst->SetVolume(m_seeVol * 0.8f);							// ボリューム調整
	m_startCountSe.endFlg = false;

	m_finishSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_finishSe.data->Load("Sound/finish.wav");					// 音データ読み込み
	m_finishSe.inst = m_finishSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_finishSe.inst->SetVolume(m_seeVol);							// ボリューム調整
	m_finishSe.endFlg = false;

	m_addScoreSe.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_addScoreSe.data->Load("Sound/score.wav");					// 音データ読み込み
	m_addScoreSe.inst = m_addScoreSe.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_addScoreSe.inst->SetVolume(m_seeVol * 0.8f);							// ボリューム調整
	m_addScoreSe.endFlg = false;



}

void C_Sound::BgmLoad()
{
	m_BGM.data = std::make_shared<KdSoundEffect>();				// メモリ領域確保
	m_BGM.data->Load("Sound/BGM.wav");					// 音データ読み込み
	m_BGM.inst = m_BGM.data->CreateInstance(false);		// スピーカーのメモリ領域確保
	m_BGM.inst->SetVolume(m_bgmVol);							// ボリューム調整
	m_BGM.endFlg = false;
	m_BGM.inst->Play(true);
}

void C_Sound::Update()
{


	
}

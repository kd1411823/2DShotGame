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

	// 音量調整	
	float m_seeVol;			//  SE ボリューム
	float m_bgmVol;			// BGM ボリューム

	tSnd m_BGM;// BGM
	tSnd m_oneGetBulletSe;	// 弾(取得オブジェクト)を獲得した音1
	tSnd m_twoGetBulletSe;	// 弾(取得オブジェクト)を獲得した音2
	tSnd m_threeGetBulletSe;	// 弾(取得オブジェクト)を獲得した音3
	tSnd m_fourGetBulletSe;	// 弾(取得オブジェクト)を獲得した音4
	tSnd m_fiveGetBulletSe;	// 弾(取得オブジェクト)を獲得した音5
	tSnd m_shotBulletSe;// 弾を発射したときの音
	tSnd m_enemyHitSe; // 敵と弾がヒットしたときの音
	tSnd m_playerCircleHitSe; // プレイヤー円と弾がヒットしたときの音
	tSnd m_startSe; // スタート音
	tSnd m_startCountSe;// スタートカウント音
	tSnd m_finishSe;// 終了音
	tSnd m_addScoreSe;// スコア加算音
};
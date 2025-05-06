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

	tSnd GetGetBulletSe() { return m_getBulletSe; }
	tSnd GetShotBulletSe() { return m_shotBulletSe; }
	tSnd GetEnemyHitSe() { return m_enemyHitSe; }

private:

	Scene* m_p0wner;

	// 音量調整	
	float m_seeVol;			//  SE ボリューム
	float m_bgmVol;			// BGM ボリューム


	tSnd m_getBulletSe;	// 弾(取得オブジェクト)を獲得した音
	tSnd m_shotBulletSe;// 弾を発射したときの音
	tSnd m_enemyHitSe; // 敵と弾がヒットしたときの音
};
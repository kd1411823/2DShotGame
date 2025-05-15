#pragma once
#include "../GameSystem/GameObjectBase.h"
#include "Enemy_SquareParticle.h"
#include "Enemy_SquareFrame.h"
#include "Enemy_HPCircle.h"
#include "Enemy_Circle.h"
#include "../GameSystem/StateMachine.h"
#include "../Bullet/Bullet.h"

class C_Sun;

class C_Enemy :public C_GameObject
{
public:

	C_Enemy();
	~C_Enemy();

	
	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void ScaleManager();
	// 敵の弾とプレイヤーの円と当たり判定
	void EnemyBulletPlayerCircleHit();
	// 敵にダメージ追加
	void TakeDamage();

	// ゲッター
	float GetRadius()override { return m_enemyRadius; }
	float GetRotation() { return m_bsst.rot; }
	bool GetbMoveFlg() { return m_bMoveFlg; }
	C_Enemy_HPCircle* GetEnemyHpCircle() { return &m_enemyhpCircle; }
	C_Enemy_Circle* GetEnemyFrameCircle() { return &m_enemyframeCircle; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	C_Enemy_SquareFrame* GetEnemySquareFrame() { return &m_enemySquareFrame; }
	float GetEBulletSpdScl() { return m_ebulletSpdScl; }

	// セッター
	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }
	void SetbMoveFlg(float a_bMoveFlg) { m_bMoveFlg = a_bMoveFlg; }

private:

	static const int squareParticleNum = 30;
	static const int hitParticleNum = 40;

	// テクスチャ
	KdTexture enemyTex;
	KdTexture hpCircleTex;
	KdTexture frameCircleTex;
	KdTexture ebulletTex;
	KdTexture squareframeTex;

	// ステートマシン
	C_StateMachine<C_Enemy> m_stateMachine;

	// 敵のHP円
	C_Enemy_HPCircle m_enemyhpCircle;

	// 敵のHP円(フレーム)
	C_Enemy_Circle m_enemyframeCircle;

	// 弾インスタンス(敵)
	C_Bullet m_bullet[ebulletNum];

	// 敵パーティクル
	C_Enemy_SquareParticle m_enemysquareParticle[squareParticleNum];

	// 敵パーティクル(HIT時)
	C_Enemy_SquareParticle m_enemyhitParticle[hitParticleNum];

	// 敵四角形フレーム
	C_Enemy_SquareFrame m_enemySquareFrame;

	std::shared_ptr<C_Sun> m_sun = nullptr;

	const float m_enemyRadius = EnemyHpCircleScl * BIT512 * 0.5f;
	float m_enemyHitpoint;		// 敵のHP
	float m_damagePoint;		// ダメージ量
	float m_autoRecoveryRate;	// 自然回復量
	float m_deg;				// 角度
	float m_movDeg;				// 移動量(角度)
	float m_circleRadius;		// 円の半径
	float m_ebulletSpdScl;		// 敵の弾のスピード倍率
	bool		  m_bMoveFlg;		// 動いているかフラグ
	bool		  m_isRisingScl;	// 敵のの拡大率増減フラグ
	float         m_deltaScl;		// 敵の拡大率増減量
	float         m_maxDeltaScl;		// 最大敵の拡大率
	float         m_minDeltaScl;		// 最小敵の拡大率
	bool          m_sclInitFlg;		// 拡大率初期化フラグ
};
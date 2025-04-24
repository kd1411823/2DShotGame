#pragma once
#include "GameObjectBase.h"
#include "Enemy_HPCircle.h"
#include "Enemy_Circle.h"
#include "StateMachine.h"
#include "Bullet.h"

class C_Enemy :public C_GameObject
{
public:

	C_Enemy();
	virtual ~C_Enemy();

	
	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	// 敵の弾とプレイヤーの円と当たり判定
	void EnemyBulletPlayerCircleHit();
	// 敵にダメージ追加
	void TakeDamage();

	float GetRadius()override { return m_enemyRadius; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	float GetEBulletSpdScl() { return m_ebulletSpdScl; }

	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }


private:

	// テクスチャ
	KdTexture enemyTex;
	KdTexture hpCircleTex;
	KdTexture frameCircleTex;
	KdTexture ebulletTex;

	// ステートマシン
	C_StateMachine<C_Enemy> m_stateMachine;

	// 敵のHP円
	C_Enemy_HPCircle m_enemyhpCircle;

	// 敵のHP円(フレーム)
	C_Enemy_Circle m_enemyframeCircle;

	// 弾インスタンス(敵)
	C_Bullet m_bullet[ebulletNum];

	const float m_enemyRadius = EnemyHpCircleScl * BIT512 * 0.5f;
	float m_enemyHitpoint;		// 敵のHP
	float m_damagePoint;		// ダメージ量
	float m_autoRecoveryRate;	// 自然回復量
	float m_deg;				// 角度
	float m_movDeg;				// 移動量(角度)
	float m_circleRadius;		// 円の半径
	float m_ebulletSpdScl;		// 敵の弾のスピード倍率
};
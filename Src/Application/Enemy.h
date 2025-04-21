#pragma once
#include "GameObjectBase.h"
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

	float GetRadius()override { return m_enemyRadius; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	float GetEBulletSpdScl() { return m_ebulletSpdScl; }

	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }



private:

	// テクスチャ
	KdTexture ebulletTex;

	// ステートマシン
	C_StateMachine<C_Enemy> m_stateMachine;
	// 弾インスタンス(敵)
	C_Bullet m_bullet[ebulletNum];

	const float m_enemyRadius = 12.0f;
	float m_deg;				// 角度
	float m_movDeg;				// 移動量(角度)
	float m_circleRadius;		// 円の半径
	float m_ebulletSpdScl;		// 敵の弾のスピード倍率
};
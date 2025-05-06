#pragma once
#include "GameObjectBase.h"

class C_Sun;

class C_Drop_Bullet :public C_GameObject
{
public:

	C_Drop_Bullet(){}
	~C_Drop_Bullet(){}

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action(float a_circleRadius);
	void CountHIT();

	void SetHitCount(int a_hitCount) { m_hitCount = a_hitCount; }

	Math::Vector2 GetPos()override { return m_bsst.pos; }
	bool GetAlive()override { return m_bsst.alive; }
	const float GetDropBulletRadius(){ return m_dropBulletRadius; }

private:

	std::shared_ptr<C_Sun> m_sun = nullptr;

	int		m_no; // 弾の番号(No.)
 	const float   m_dropBulletRadius = BIT256 * m_bsst.scl.x * 0.5f;  // 弾(取得オブジェクト)の半径
	int    m_hitCount;// 弾をいくつ持っているカウント(当たったカウント)

};
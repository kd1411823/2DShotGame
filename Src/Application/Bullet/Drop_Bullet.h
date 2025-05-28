#pragma once
#include "../GameSystem/GameObjectBase.h"

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

	// いくつ弾を取得したか、カウントする
	void CountHIT();

	// ゲッター
	Math::Vector2 GetPos()override { return m_bsst.pos; }
	bool GetAlive()override { return m_bsst.alive; }
	const float GetDropBulletRadius(){ return m_dropBulletRadius; }
	std::shared_ptr<C_Sun> GetSun() { return m_sun; }


private:

	std::shared_ptr<C_Sun> m_sun = nullptr;

	int		m_no; // 弾の番号(No.)
 	const float   m_dropBulletRadius = BIT256 * m_bsst.scl.x * 0.5f;  // 弾(取得オブジェクト)の半径

};
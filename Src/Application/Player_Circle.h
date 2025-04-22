#pragma once
#include "GameObjectBase.h"

class C_Player_Circle :public C_GameObject
{
public:

	C_Player_Circle(){}
	virtual ~C_Player_Circle(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void SetPlayerLife(ePlayerLife a_playerLife) { m_playerLife = a_playerLife; }

	ePlayerLife GetPlayerLife() { return m_playerLife; }
	float GetCircleRadius() { return m_circleRadius; }
	float GetPlayerCircleScl() { return m_playerCircleScl; }

private:

	ePlayerLife m_playerLife; // プレイヤーのライフ
	float m_circleRadius; // 半径
	float m_playerCircleScl;  // プレイヤー円の大きさ

};
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


private:

	ePlayerLife m_playerLife; // プレイヤーのライフ
	float m_playerCircleScl;  // プレイヤー円の大きさ

};
#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Enemy_Circle :public C_GameObject
{
public:

	C_Enemy_Circle(){}
	~C_Enemy_Circle(){}

	void Init()override;
	void Draw(bool a_alive);
	void Update(Math::Vector2 a_pos,bool a_alive);
	void Action(bool a_alive);

	void SetHitFlg(bool a_hitFlg) { m_hitFlg = a_hitFlg; }

private:

	bool m_hitFlg; // ’e‚ª“–‚½‚Á‚Ä‚¢‚é‚©ƒtƒ‰ƒO

};
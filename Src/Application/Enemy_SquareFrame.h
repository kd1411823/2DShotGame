#pragma once
#include "GameObjectBase.h"

class C_Enemy_SquareFrame :public C_GameObject
{
public:

	C_Enemy_SquareFrame();
	~C_Enemy_SquareFrame();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action(Math::Vector2 a_pos);

	void SetStopFlg(bool a_stopFlg) { m_stopFlg = a_stopFlg; }

private:

	float m_frameScl;// ƒtƒŒ[ƒ€Šg‘å—¦
	float m_maxScl; // Å‘åŠg‘å—¦
	bool  m_stopFlg; // ~‚Ü‚Á‚Ä‚¢‚é‚©ƒtƒ‰ƒO
};

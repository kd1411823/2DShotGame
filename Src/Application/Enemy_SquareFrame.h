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

	float m_frameScl;// �t���[���g�嗦
	float m_maxScl; // �ő�g�嗦
	bool  m_stopFlg; // �~�܂��Ă��邩�t���O
};

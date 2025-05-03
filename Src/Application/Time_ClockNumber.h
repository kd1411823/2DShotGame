#pragma once
#include "GameObjectBase.h"

class C_Time_ClockNumber :public C_GameObject
{
public:

	C_Time_ClockNumber();
	~C_Time_ClockNumber();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;

	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

private:

	int m_no; // タイマー数字ナンバー
	int m_rctX; // 切り取り座標X
	int m_digitsNumber; // 桁数字
	float m_numberDistance; // 数字間隔

};


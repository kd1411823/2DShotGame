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
	void DecreaseScale();
	void DecreaseAlpha();

	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

	Math::Vector2 GetScl() { return m_bsst.scl; }

private:

	int m_no; // タイマー数字ナンバー
	int m_rctX; // 切り取り座標X
	int m_digitsNumber; // 桁数字
	float m_numberDistance; // 数字間隔
	float m_baseScl; // 数字の拡大率
	float m_deltaScl;		// 数字の拡大率増減量
	float m_maxScl;		// 最大数字の拡大率
	float m_deltaAlpha;		// 数字のalpha値増減量
	int   m_preTimer;// 前のタイマー情報を保存する変数
};


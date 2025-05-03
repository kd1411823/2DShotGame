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
	void ScaleManager();


	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

private:

	int m_no; // タイマー数字ナンバー
	int m_rctX; // 切り取り座標X
	int m_digitsNumber; // 桁数字
	float m_numberDistance; // 数字間隔
	float m_numberScl; // 数字の拡大率
	bool  m_isRisingScl;	// 数字の拡大率増減フラグ
	float m_deltaScl;		// 数字の拡大率増減量
	float m_deltaMax;	// max - 基準値　
	float m_deltaMin;	// min - 基準値　
	float m_maxDeltaScl;		// 最大数字の拡大率
	float m_minDeltaScl;		// 最小数字の拡大率
};


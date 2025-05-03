#pragma once
#include "GameObjectBase.h"

class C_Score_TextNumber :public C_GameObject
{
public:

	C_Score_TextNumber();
	~C_Score_TextNumber();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;
	void AddDrawScore(); // スコアを加算する演出(見た目)
	void ScaleManager(); // 拡大率処理
	void AddTimeScore(); // タイム分スコア加算

	void SetNumberDistance(float a_numberDistance) { m_numberDistance = a_numberDistance; }
	void SetNumberScl(float a_numberScl) { m_numberScl = a_numberScl; }

	float GetNumberDistance() { return m_numberDistance; }
	float GetNumberScl() { return m_numberScl; }

private:
	
	int m_no; // オブジェクトナンバー
	int m_rctX; // 切り取り座標X
	float m_numberDistance; // 数字間隔
	int m_digitsNumber; // 桁数字
	float m_numberScl; // 数字の大きさ
	float m_addDrawScore; // スコアを加算する演出用のスコアを入れる変数
	float m_addSpeed; // スコアを加算するスピード
	bool  m_isRisingScl;	// 数字の拡大率増減フラグ
	float m_deltaScl;		// 数字の拡大率増減量
	float m_deltaMax;	// max - 基準値　
	float m_deltaMin;	// min - 基準値　
	float m_maxDeltaScl;		// 最大数字の拡大率
	float m_minDeltaScl;		// 最小数字の拡大率
	int   m_addTimeScoreCount; // タイム分スコア加算処理カウント
	Math::Vector2 m_resultTimeClockCirclePos; // リザルト時のタイム円の座標

};


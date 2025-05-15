#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_Score_Result :public C_GameObject
{
public:

	C_Score_Result() {}
	~C_Score_Result() {}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha値処理
	void TimeUpText();
	void ToTitle();

	bool GetTextDrawFlg() { return m_textDrawFlg; }

private:

	bool m_keyFlg; // キーフラグ
	bool m_decreaseAlphaFlg; // フェードアウトフラグ
	bool m_stringDrawFlg; // 文字列描画フラグ
	bool  m_isRisingAlpha;	// alpha値増減フラグ
	float m_deltaAlpha;		// alpha値増減量
	float m_stringAlpha; // 文字のalpha値
	int   m_textDrawCount; // TimeUpText描画カウント
	bool  m_textDrawFlg; // TimeUpText描画フラグ
	float m_strScl; // TimeUptextの拡大率
	float m_minStrScl;// TimeUptextの最小拡大率
	float m_strAlpha; // TimeUptextのalpha値
};
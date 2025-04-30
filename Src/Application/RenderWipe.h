#pragma once
#include "GameObjectBase.h"

class C_RenderWipe :public C_GameObject
{
public:

	void InitWipe();
	void DrawWipe();
	void UpdateWipe();
	void ActionWipe();

	void SetShakeTime(int a_shakeTime) { m_shakeTime = a_shakeTime; }

	int GetShakeTime() { return m_shakeTime; }

private:

	float m_deg; // sinカーブ用角度
	float m_shakeSpeed; // 揺らすスピード
	float m_shakeWid;	// 揺らす幅
	int   m_shakeTime; // 揺らす時間

};
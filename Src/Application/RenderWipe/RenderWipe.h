#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_RenderWipe :public C_GameObject
{
public:

	void InitWipe(float a_alpha = 0.0f);
	void DrawWipe();
	void UpdateWipe();
	void ActionWipe();
	void AddAlpha(float a_deltaAlpha = 0.005f);
	void DecreaseAlpha(float a_deltaAlpha = 0.005f);

	void SetShakeTime(int a_shakeTime) { m_shakeTime = a_shakeTime; }

	float GetAlpha() { return m_bsst.draw.clr.A(); }
	int GetShakeTime() { return m_shakeTime; }

private:

	float m_deg; // sin�J�[�u�p�p�x
	float m_shakeSpeed; // �h�炷�X�s�[�h
	float m_shakeWid;	// �h�炷��
	int   m_shakeTime; // �h�炷����
	float m_deltaAlpha; // alpha�l���Z��
};
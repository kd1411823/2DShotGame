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

	float m_deg; // sin�J�[�u�p�p�x
	float m_shakeSpeed; // �h�炷�X�s�[�h
	float m_shakeWid;	// �h�炷��
	int   m_shakeTime; // �h�炷����

};
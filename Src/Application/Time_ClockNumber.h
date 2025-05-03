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

	int m_no; // �^�C�}�[�����i���o�[
	int m_rctX; // �؂�����WX
	int m_digitsNumber; // ������
	float m_numberDistance; // �����Ԋu
	float m_numberScl; // �����̊g�嗦
	bool  m_isRisingScl;	// �����̊g�嗦�����t���O
	float m_deltaScl;		// �����̊g�嗦������
	float m_deltaMax;	// max - ��l�@
	float m_deltaMin;	// min - ��l�@
	float m_maxDeltaScl;		// �ő吔���̊g�嗦
	float m_minDeltaScl;		// �ŏ������̊g�嗦
};


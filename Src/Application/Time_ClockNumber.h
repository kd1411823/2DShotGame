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

	int m_no; // �^�C�}�[�����i���o�[
	int m_rctX; // �؂�����WX
	int m_digitsNumber; // ������
	float m_numberDistance; // �����Ԋu
	float m_baseScl; // �����̊g�嗦
	float m_deltaScl;		// �����̊g�嗦������
	float m_maxScl;		// �ő吔���̊g�嗦
	float m_deltaAlpha;		// ������alpha�l������
	int   m_preTimer;// �O�̃^�C�}�[����ۑ�����ϐ�
};


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
	void AddDrawScore(); // �X�R�A�����Z���鉉�o(������)
	void ScaleManager(); // �g�嗦����
	void AddTimeScore(); // �^�C�����X�R�A���Z

	void SetNumberDistance(float a_numberDistance) { m_numberDistance = a_numberDistance; }
	void SetNumberScl(float a_numberScl) { m_numberScl = a_numberScl; }

	float GetNumberDistance() { return m_numberDistance; }
	float GetNumberScl() { return m_numberScl; }

private:
	
	int m_no; // �I�u�W�F�N�g�i���o�[
	int m_rctX; // �؂�����WX
	float m_numberDistance; // �����Ԋu
	int m_digitsNumber; // ������
	float m_numberScl; // �����̑傫��
	float m_addDrawScore; // �X�R�A�����Z���鉉�o�p�̃X�R�A������ϐ�
	float m_addSpeed; // �X�R�A�����Z����X�s�[�h
	bool  m_isRisingScl;	// �����̊g�嗦�����t���O
	float m_deltaScl;		// �����̊g�嗦������
	float m_deltaMax;	// max - ��l�@
	float m_deltaMin;	// min - ��l�@
	float m_maxDeltaScl;		// �ő吔���̊g�嗦
	float m_minDeltaScl;		// �ŏ������̊g�嗦
	int   m_addTimeScoreCount; // �^�C�����X�R�A���Z�����J�E���g
	Math::Vector2 m_resultTimeClockCirclePos; // ���U���g���̃^�C���~�̍��W

};


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
};


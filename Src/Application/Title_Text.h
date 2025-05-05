#pragma once
#include "GameObjectBase.h"

class C_Title_Text :public C_GameObject
{
public:

	C_Title_Text();
	~C_Title_Text();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha�l����

private:

	int m_no; // �I�u�W�F�N�g�i���o�[
	int m_rctX; // �؂�����WX
	int m_widRctX; // �؂����X
	bool  m_isRisingAlpha;	// alpha�l�����t���O
	float m_deltaAlpha;		// alpha�l������
};
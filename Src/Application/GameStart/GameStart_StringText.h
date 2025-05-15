#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_GameStart_StringText :public C_GameObject
{
public:

	C_GameStart_StringText();
	~C_GameStart_StringText();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha�l����


private:

	int m_no; // �I�u�W�F�N�g�i���o�[
	int m_rctX; // �؂�����WX
	int m_rctWidX; // �؂����X
	bool  m_isRisingAlpha;	// alpha�l�����t���O
	float m_deltaAlpha;		// alpha�l������
};
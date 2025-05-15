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
	void AlphaManager(); // alpha�l����
	void TimeUpText();
	void ToTitle();

	bool GetTextDrawFlg() { return m_textDrawFlg; }

private:

	bool m_keyFlg; // �L�[�t���O
	bool m_decreaseAlphaFlg; // �t�F�[�h�A�E�g�t���O
	bool m_stringDrawFlg; // ������`��t���O
	bool  m_isRisingAlpha;	// alpha�l�����t���O
	float m_deltaAlpha;		// alpha�l������
	float m_stringAlpha; // ������alpha�l
	int   m_textDrawCount; // TimeUpText�`��J�E���g
	bool  m_textDrawFlg; // TimeUpText�`��t���O
	float m_strScl; // TimeUptext�̊g�嗦
	float m_minStrScl;// TimeUptext�̍ŏ��g�嗦
	float m_strAlpha; // TimeUptext��alpha�l
};
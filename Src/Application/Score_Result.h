#pragma once
#include "GameObjectBase.h"

class C_Score_Result :public C_GameObject
{
public:

	C_Score_Result() {}
	~C_Score_Result() {}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void ToTitle();

private:

	bool m_keyFlg; // �L�[�t���O
	bool m_decreaseAlphaFlg; // �t�F�[�h�A�E�g�t���O

};
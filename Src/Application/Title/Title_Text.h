#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Title_Text :public C_GameObject
{
public:

	C_Title_Text();
	~C_Title_Text();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha�l����

private:

	bool  m_isRisingAlpha;	// alpha�l�����t���O
	float m_deltaAlpha;		// alpha�l������
	float m_textAlpha;		// textalpha�l
};
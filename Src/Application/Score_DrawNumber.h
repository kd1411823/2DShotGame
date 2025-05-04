#pragma once
#include "GameObjectBase.h"

class C_Score_DrawNumber :public C_GameObject
{
public:

	C_Score_DrawNumber();
	~C_Score_DrawNumber();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;
	void AddAlpha();
	void DecreaseAlpha();

private:

	int m_no; // •`‰æ—p”š‚ÌNo
	float m_numberDistance; // •`‰æ—p”šŠÔŠu
	float m_deltaAlpha; // alpha’l‰ÁZ—Ê

};
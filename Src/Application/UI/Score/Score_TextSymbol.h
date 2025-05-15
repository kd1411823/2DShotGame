#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_Score_TextSymbol :public C_GameObject
{
public:

	C_Score_TextSymbol();
	~C_Score_TextSymbol();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AddAlpha();
	void DecreaseAlpha();


private:

	KdTexture symbolTex;

	Bsst m_plusBsst;

	float m_deltaAlpha; // alpha’l‰ÁŽZ—Ê
};
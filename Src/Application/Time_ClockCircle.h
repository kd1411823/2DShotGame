#pragma once
#include "GameObjectBase.h"

class C_Time_ClockCircle :public C_GameObject
{
public:

	C_Time_ClockCircle();
	~C_Time_ClockCircle();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

private:

	KdTexture clockCircleTex;
};


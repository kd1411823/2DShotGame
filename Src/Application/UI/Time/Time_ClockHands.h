#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_Time_ClockHands :public C_GameObject
{
public:

	C_Time_ClockHands();
	~C_Time_ClockHands();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;


private:

	KdTexture clockHandsTex;

};


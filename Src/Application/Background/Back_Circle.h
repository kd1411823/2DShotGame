#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Back_Circle :public C_GameObject
{
public:

	C_Back_Circle(){}
	virtual ~C_Back_Circle(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;


private:

};

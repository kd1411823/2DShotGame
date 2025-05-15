#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Background :public C_GameObject
{
public:

	C_Background(){}
	~C_Background(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;



private:

};
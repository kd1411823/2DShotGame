#pragma once
#include "GameObjectBase.h"

class C_Title_Background :public C_GameObject
{
public:

	C_Title_Background();
	~C_Title_Background();


	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

private:

};
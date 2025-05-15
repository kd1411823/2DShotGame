#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Title_BackCircle :public C_GameObject
{
public:

	C_Title_BackCircle();
	~C_Title_BackCircle();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

private:

};
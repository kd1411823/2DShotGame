#pragma once
#include "GameObjectBase.h"

class C_GameStart_Number :public C_GameObject
{
public:

	C_GameStart_Number();
	~C_GameStart_Number();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

private:

};
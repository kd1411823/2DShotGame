#pragma once
#include "GameObjectBase.h"

class C_GameStart_StringText :public C_GameObject
{
public:

	C_GameStart_StringText();
	~C_GameStart_StringText();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;



private:

};
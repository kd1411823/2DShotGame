#pragma once
#include "GameObjectBase.h"

class C_Sun :public C_GameObject
{
public:

	C_Sun();
	~C_Sun();

	void Init();
	void Draw();
	void Update(Math::Vector2 a_pos,Math::Vector2 a_scl,Math::Color a_clr);

private:

	KdTexture sunTex;
};



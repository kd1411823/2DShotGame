#pragma once
#include "GameObjectBase.h"

class C_Enemy_HPCircle :public C_GameObject
{
public:

	C_Enemy_HPCircle(){}
	~C_Enemy_HPCircle(){}

	void Init()override;
	void Draw(bool a_alive);
	void Update(bool a_alive,Math::Vector2 a_pos);
	void Action(bool a_alive,float a_hpPoint);

	

private:

};
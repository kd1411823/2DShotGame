#pragma once
#include "GameObjectBase.h"

class C_Enemy_Circle :public C_GameObject
{
public:

	C_Enemy_Circle(){}
	virtual ~C_Enemy_Circle(){}

	void Init()override;
	void Draw(bool a_alive);
	void Update(Math::Vector2 a_pos,bool a_alive);
	void Action(bool a_alive);


private:



};
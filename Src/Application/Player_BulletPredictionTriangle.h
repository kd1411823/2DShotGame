#pragma once
#include "GameObjectBase.h"

class C_Player_BulletPredictionTriangle :public C_GameObject
{
public:

	C_Player_BulletPredictionTriangle(){}
	~C_Player_BulletPredictionTriangle(){}

	void Init();
	void Draw();
	void Update();
	void Action(Math::Vector2 a_pos, float a_rot, float a_deg, float a_circleRadius);


private:


};
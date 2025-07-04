#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Sun;

class C_Player_BulletPredictionTriangle :public C_GameObject
{
public:

	C_Player_BulletPredictionTriangle(){}
	~C_Player_BulletPredictionTriangle(){}

	void Init();
	void Draw();
	void Update();
	void Action(Math::Vector2 a_pos, float a_rot, float a_deg, float a_circleRadius);

	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }
	std::shared_ptr<C_Sun> GetSun() { return m_sun; }


private:

	std::shared_ptr<C_Sun> m_sun = nullptr; 
};
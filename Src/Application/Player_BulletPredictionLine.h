#pragma once
#include "GameObjectBase.h"

class C_Sun;

class C_Player_BulletPredictionLine :public C_GameObject
{
public:

	C_Player_BulletPredictionLine(){}
	~C_Player_BulletPredictionLine(){}

	void Init(int a_no);
	void Draw();
	void Update(Math::Vector2 a_pos);
	void Action(Math::Vector2 a_pos,float a_rot,float a_deg,float a_circleRadius);

	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

	std::shared_ptr<C_Sun> GetSun() { return m_sun; }
	

private:

	int m_no;	// 予測ラインのナンバー

	std::shared_ptr<C_Sun> m_sun = nullptr;
};
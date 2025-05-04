#pragma once
#include "GameObjectBase.h"

class C_Time_ClockCircle :public C_GameObject
{
public:

	C_Time_ClockCircle();
	~C_Time_ClockCircle();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha値処理
	void DecreaseAlpha();

	void SetPos(Math::Vector2 a_pos) { m_bsst.pos = a_pos; }
	void SetMov(Math::Vector2 a_mov) { m_bsst.mov = a_mov; }
	void SetMovX(float a_movX) { m_bsst.mov.x = a_movX; }
	void SetMovY(float a_movY) { m_bsst.mov.y = a_movY; }
	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }

	Math::Vector2 GetPos() { return m_bsst.pos; }
	Math::Vector2 GetMov() { return m_bsst.mov; }
	float GetAlpha() { return m_bsst.draw.clr.A();}

private:

	KdTexture clockCircleTex;

	bool  m_isRisingAlpha;	// 数字のalpha値増減フラグ
	float m_deltaAlpha;		// 数字のalpha値増減量
};


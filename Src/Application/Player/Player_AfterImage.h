#pragma once
#include "../Particle/ParticleBase.h"

class C_Player_AfterImage :public C_ParticleBase
{
public:

	C_Player_AfterImage();
	~C_Player_AfterImage();

	void Init()override;
	void Draw()override;
	void Update(Math::Vector2 a_pos = { 0, 0 }, bool a_bMoveFlg = true)override;

	bool GetAlive() { return m_particle.alive; }

private:

};
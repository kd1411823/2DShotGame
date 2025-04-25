#pragma once
#include "ParticleBase.h"

class C_Player_TriangleParticle :public C_ParticleBase
{
public:

	void Init()override;
	void Draw()override;
	void Update(Math::Vector2 a_pos = { 0, 0 }, bool a_bMoveFlg = true)override;

	bool GetAlive() { return m_particle.alive; }

private:

};
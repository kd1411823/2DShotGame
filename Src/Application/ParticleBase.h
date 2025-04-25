#pragma once
#include "Systm.h"

class Scene;

class C_ParticleBase
{
public:

	C_ParticleBase(){}
	virtual ~C_ParticleBase(){}

	virtual void Init(){}
	virtual void Draw(){}
	virtual void Update(Math::Vector2 a_pos , bool a_bMoveFlg) {}
	void Emit(Math::Vector2 a_pos, Math::Vector2 a_mov, Math::Vector2 a_scl, float a_rot, bool a_alive,
		int a_lifespan, bool a_repeat, Math::Rectangle a_rct,Math::Color a_clr);

	//0.0Å`1.0ÇÃóêêîÇãÅÇﬂÇÈ
	float Rnd();

	void SetP0wner(Scene* a_p0wner) { m_p0wner = a_p0wner; }
	void SetTex(KdTexture* a_pTex) { m_particle.draw.pTex = a_pTex; }

protected:

	Scene* m_p0wner = nullptr;

	ParticleSt m_particle;
};
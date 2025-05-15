#include "ParticleBase.h"

void C_ParticleBase::Emit(Math::Vector2 a_pos,
						  Math::Vector2 a_mov,
						  Math::Vector2 a_scl,
						  float a_rot,
						  bool a_alive,
						  int a_lifespan,
						  bool a_repeat,
						  Math::Rectangle a_rct,
						  Math::Color a_clr)
{
	m_particle.pos = a_pos;
	m_particle.mov = a_mov;
	m_particle.scl = a_scl;
	m_particle.rot = a_rot;
	m_particle.alive = a_alive;
	m_particle.lifespan = a_lifespan;
	m_particle.repeat = a_repeat;
	m_particle.draw.rct = a_rct;
	m_particle.draw.clr = a_clr;
}

float C_ParticleBase::Rnd()
{
	return rand() / (float)RAND_MAX;
}

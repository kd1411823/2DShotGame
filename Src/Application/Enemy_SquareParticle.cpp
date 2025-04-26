#include "Enemy_SquareParticle.h"
#include "Scene.h"

void C_Enemy_SquareParticle::Init()
{
}

void C_Enemy_SquareParticle::Draw()
{
	if (m_particle.lifespan <= 0)return;
	SHADER.m_spriteShader.SetMatrix(m_particle.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_particle.draw.pTex, 0, 0, &m_particle.draw.rct, &m_particle.draw.clr);

}

void C_Enemy_SquareParticle::Update(Math::Vector2 a_pos, bool a_bMoveFlg)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_particle.lifespan--;

	if (m_particle.lifespan <= 0)
	{
		m_particle.alive = false;
		if (!m_particle.repeat)return;

		if (a_bMoveFlg || m_particle.alive)
		{
			Emit(a_pos,
				{ Rnd() * 4 - 2 ,Rnd() * 4 - 2 },
				{ Rnd() * 0.4f - 0.2f ,Rnd() * 0.4f - 0.2f },
				(float)systm->RndBtwn(0, 360),
				true,
				Rnd() * 20 + 10,
				true,
				{ 0,0,BIT256,BIT256 },
				{ Rnd(),1.0f ,Rnd(), 1.3f }
			);
		}
		else
		{
			Emit(a_pos,
				{ Rnd() * 4 - 2 ,Rnd() * 4 - 2 },
				{ Rnd() * 0.4f - 0.2f ,Rnd() * 0.4f - 0.2f },
				(float)systm->RndBtwn(0, 360),
				true,
				Rnd() * 10 + 10,
				false,
				{ 0,0,BIT256,BIT256 },
				{ Rnd(),1.0f ,Rnd(), 1.3f }
			);
		}
	}



	m_particle.scl.x *= 0.92f;
	m_particle.scl.y *= 0.92f;

	m_particle.pos += m_particle.mov;

	m_particle.mat = systm->CreateMat(m_particle.scl, m_particle.rot, m_particle.pos);

}

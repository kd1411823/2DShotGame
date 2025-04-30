#include "Player_TriangleParticle.h"
#include "Scene.h"

void C_Player_TriangleParticle::Init()
{
	
	
}

void C_Player_TriangleParticle::Draw()
{
	if (m_particle.lifespan <= 0)return;
	SHADER.m_spriteShader.SetMatrix(m_particle.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_particle.draw.pTex, 0, 0, &m_particle.draw.rct, &m_particle.draw.clr);

}

void C_Player_TriangleParticle::Update(Math::Vector2 a_pos, bool a_bMoveFlg)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player* player = m_p0wner->GetPlayer();
	

	m_particle.lifespan--;

	if (m_particle.lifespan <= 0)
	{
		m_particle.alive = false;
		if (!m_particle.repeat)return;

		if (a_bMoveFlg || m_particle.alive)
		{
			float _rnd = Rnd() * 0.3f - 0.15f;
			Emit(a_pos,
				{ Rnd() * 4 - 2 ,Rnd() * 4 - 2 },
				{ _rnd ,_rnd },
				player->GetRot(),
				true,
				Rnd() * 20 + 10,
				true,
				{ 0,0,BIT256,BIT256 },
				{ GREEN, 0.8f }
			);
		}
		else
		{
			float _rnd = Rnd() * 0.2f - 0.1f;
			Emit(a_pos,
				{ Rnd() * 4 - 2 ,Rnd() * 4 - 2 },
				{ _rnd ,_rnd },
				player->GetRot(),
				true,
				Rnd() * 10 + 5,
				false,
				{ 0,0,BIT256,BIT256 },
				{ GREEN, 0.7f }
			);
		}
	}


	//m_particle.draw.clr.R(m_particle.draw.clr.R() * 1.16f);
	m_particle.draw.clr.A(m_particle.draw.clr.A() * 0.97f);

	m_particle.scl.x *= 0.95f;
	m_particle.scl.y *= 0.95f;

	m_particle.pos += m_particle.mov;

	m_particle.mat = systm->CreateMat(m_particle.scl, m_particle.rot, m_particle.pos);
}

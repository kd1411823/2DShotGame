#include "Player_AfterImage.h"
#include "../Scene/Scene.h"

C_Player_AfterImage::C_Player_AfterImage()
{
}

C_Player_AfterImage::~C_Player_AfterImage()
{
}

void C_Player_AfterImage::Init()
{
}

void C_Player_AfterImage::Draw()
{
	if (m_particle.lifespan <= 0)return;
	SHADER.m_spriteShader.SetMatrix(m_particle.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_particle.draw.pTex, 0, 0, &m_particle.draw.rct, &m_particle.draw.clr);

}

void C_Player_AfterImage::Update(Math::Vector2 a_pos, bool a_bMoveFlg)
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
			Emit(a_pos,
				{ player->GetMov().x ,player->GetMov().y },
				{ player->GetScl().x,player->GetScl().y },
				player->GetRot(),
				true,
				30,
				true,
				{ 0,0,BIT256,BIT256 },
				{ GREEN, 0.8f }
			);
		}
		else
		{
			Emit(a_pos,
				{ player->GetMov().x ,player->GetMov().y },
				{ player->GetScl().x,player->GetScl().y },
				player->GetRot(),
				true,
				10,
				false,
				{ 0,0,BIT256,BIT256 },
				{ GREEN, 0.8f }
			);
		}
	}


	
	m_particle.draw.clr.A(m_particle.draw.clr.A() * 0.98f);

	m_particle.pos += m_particle.mov;

	m_particle.mat = systm->CreateMat(m_particle.scl, m_particle.rot, m_particle.pos);
}

#include "Enemy_HPCircle.h"
#include "Scene.h"

void C_Enemy_HPCircle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { EnemyHpCircleScl,EnemyHpCircleScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, 512, 512 };
	m_bsst.draw.clr = {1.0f,0.0f,0.0f,0.4f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy_HPCircle::Draw(bool a_alive)
{
	if (!a_alive)return;
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Enemy_HPCircle::Update(bool a_alive, Math::Vector2 a_pos)
{
	if (!a_alive)return;
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos = a_pos;

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy_HPCircle::Action(bool a_alive, float a_hpPoint)
{
	const float ratio = ((EnemyHp  - a_hpPoint) / EnemyHp);
	
	m_bsst.scl.x =  EnemyHpCircleScl * ratio;
	m_bsst.scl.y =  EnemyHpCircleScl * ratio;

}

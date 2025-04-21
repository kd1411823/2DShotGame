#include "Player_Circle.h"
#include "Scene.h"

void C_Player_Circle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_playerLife      = TwoLife; // プレイヤーのライフ
	m_playerCircleScl = TwoLifescl;  // プレイヤー円の大きさ

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_playerCircleScl,m_playerCircleScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, ScrnWid, ScrnWid };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_Circle::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Player_Circle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.scl = { m_playerCircleScl,m_playerCircleScl };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_Circle::Action()
{
	C_Player* player = m_p0wner->GetPlayer();

	//m_playerLife = ThreeLife;

	switch (m_playerLife)
	{
	case ZeroLife:
		m_playerCircleScl = ZeroLifescl;
		player->SetCircleRadius(0.0f);
		break;
	case OneLife:
		m_playerCircleScl = OneLifescl;
		player->SetCircleRadius(85.0f);
		break;
	case TwoLife:
		m_playerCircleScl = TwoLifescl;
		player->SetCircleRadius(170.0f);
		break;
	case ThreeLife:
		m_playerCircleScl = ThreeLifescl;
		player->SetCircleRadius(240.0f);
		break;
	case FourLife:
		m_playerCircleScl = FourLifescl;
		player->SetCircleRadius(305.0f);
		break;
	}
	
}

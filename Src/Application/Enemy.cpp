#include "Enemy.h"
#include "Enemy_StandState.h"
#include "Scene.h"

void C_Enemy::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	// 初期化時にインスタンスのポインタを渡す
	m_stateMachine.Start(this);

	// 初期状態のステートをセット
	m_stateMachine.ChangeState<C_Enemy_StandState>();

	m_circleRadius = 305.0f;		// 円の半径
	m_deg = systm->RndBtwn(0,360);		// 角度
	m_movDeg = 0;				// 移動量(角度)

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.5f,0.5f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT64, BIT64 };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Draw()
{
	if (!m_bsst.alive)return;
	
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	
}

void C_Enemy::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_deg += m_movDeg;

	m_movDeg = 0;

	m_stateMachine.Update();

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Enemy::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();


	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
}

#include "RenderWipe.h"
#include "Scene.h"

void C_RenderWipe::InitWipe()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_deg = 0; // sinカーブ用角度
	m_shakeSpeed = 60.0f; // 揺らすスピード
	m_shakeWid = 5.0f;	// 揺らす幅
	m_shakeTime = 0; // 揺らす時間

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, ScrnWid, ScrnHgt };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_RenderWipe::DrawWipe()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_RenderWipe::UpdateWipe()
{
	C_Systm* systm = m_p0wner->GetSystm();

	if (m_shakeTime <= 0)
	{
		m_bsst.pos = initPos;
	}

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_RenderWipe::ActionWipe()
{
	// 時間が0になったら揺らさない(実行しない)
	if (m_shakeTime <= 0)return;

	// 時間反映
	m_shakeTime--;

	// スピード反映(加算)
	m_deg += m_shakeSpeed;

	if (m_deg < 0)
	{
		m_deg += 360;
	}

	// sinカーブで揺らす
	m_bsst.pos.x = cos(DirectX::XMConvertToRadians(m_deg)) * m_shakeWid;
	m_bsst.pos.y = sin(DirectX::XMConvertToRadians(m_deg)) * m_shakeWid;
}

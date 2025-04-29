#include "RenderWipe.h"
#include "Scene.h"

void C_RenderWipe::InitWipe()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_deg = 0; // sin�J�[�u�p�p�x
	m_shakeSpeed = 60.0f; // �h�炷�X�s�[�h
	m_shakeWid = 5.0f;	// �h�炷��
	m_shakeTime = 0; // �h�炷����

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
	// ���Ԃ�0�ɂȂ�����h�炳�Ȃ�(���s���Ȃ�)
	if (m_shakeTime <= 0)return;

	// ���Ԕ��f
	m_shakeTime--;

	// �X�s�[�h���f(���Z)
	m_deg += m_shakeSpeed;

	if (m_deg < 0)
	{
		m_deg += 360;
	}

	// sin�J�[�u�ŗh�炷
	m_bsst.pos.x = cos(DirectX::XMConvertToRadians(m_deg)) * m_shakeWid;
	m_bsst.pos.y = sin(DirectX::XMConvertToRadians(m_deg)) * m_shakeWid;
}

#include "ControlText.h"
#include "Scene.h"

void C_ControlText::Init(eKeyType a_type)
{
	C_Systm* systm = m_p0wner->GetSystm();
	
	m_keyType = a_type; // キータイプ
	m_baseScl = 1.0f;  // 通常の拡大率
	m_minScl = 0.8f; // 最小の拡大率
	m_minAlpha = 0.5f; // 最小のalpha値

	switch (a_type)
	{
	case Spaccekey:
		m_bsst.pos = { -550,-300 };
		m_bsst.draw.rct = { BIT108 * 0, 0, BIT108, BIT40 };
		break;
	case Dkey:
		m_bsst.pos = { 450, -300 };
		m_bsst.draw.rct = { BIT32 * 1, 0, BIT32, BIT40 };
		break;
	case Akey:
		m_bsst.pos = { 400, -300 };
		m_bsst.draw.rct = { BIT32 * 0, 0, BIT32, BIT40 };
		break;
	case Downkey:
		m_bsst.pos = { -400,-300 };
		m_bsst.draw.rct = { BIT32 * 4, 0, BIT32, BIT40 };
		break;
	case Rightkey:
		m_bsst.pos = { 600, -300 };
		m_bsst.draw.rct = { BIT32 * 2, 0, BIT32, BIT40 };
		break;
	case Leftkey:
		m_bsst.pos = { 550, -300 };
		m_bsst.draw.rct = { BIT32 * 3, 0, BIT32, BIT40 };
		break;
	}


	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);

}

void C_ControlText::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();


	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
	

	switch (m_keyType)
	{
	case Spaccekey:
		systm->DrawStringGg({ m_bsst.pos.x + 80 , m_bsst.pos.y }, { 1.0f,1.0f }, L"or");
		break;
	case Dkey:
		systm->DrawStringGg({ m_bsst.pos.x + 5 , m_bsst.pos.y + 50}, { 1.0f,1.0f }, L"move");
		systm->DrawStringGg({ m_bsst.pos.x + 35 , m_bsst.pos.y }, { 1.0f,1.0f }, L"or");
		break;
	case Akey:
		break;
	case Downkey:
		break;
	case Rightkey:
		break;
	case Leftkey:
		break;
	}

	


}

void C_ControlText::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_ControlText::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();
	

	switch (m_keyType)
	{
	case Spaccekey:
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			MinManager();
			
		}
		else
		{
			BaseSt();
		}
		break;
	case Dkey:
		if (GetAsyncKeyState('D') & 0x8000)
		{
			MinManager();
		}
		else
		{
			BaseSt();
		}
		break;
	case Akey:
		if (GetAsyncKeyState('A') & 0x8000)
		{
			MinManager();
		}
		else
		{
			BaseSt();
		}
		break;
	case Downkey:
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			MinManager();
			
		}
		else
		{
			BaseSt();
		}
		break;
	case Rightkey:
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			MinManager();
		}
		else
		{
			BaseSt();
		}
		break;
	case Leftkey:
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			MinManager();
		}
		else
		{
			BaseSt();
		}
		break;
	}



}

void C_ControlText::MinManager()
{
	m_bsst.scl = { m_minScl ,m_minScl };
	m_bsst.draw.clr.A(m_minAlpha);
}

void C_ControlText::BaseSt()
{
	m_bsst.scl = { m_baseScl ,m_baseScl };
	m_bsst.draw.clr.A(1.0f);
}

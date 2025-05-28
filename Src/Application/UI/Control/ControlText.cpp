#include "ControlText.h"
#include "../../Scene/Scene.h"

void C_ControlText::Init(eKeyType a_type)
{
	C_Systm* systm = m_p0wner->GetSystm();
	
	m_keyType  = a_type; // キータイプ
	m_baseScl  = 1.0f;	 // 通常の拡大率
	m_minScl   = 0.8f;	 // 最小の拡大率
	m_minAlpha = 0.5f;	 // 最小のalpha値

	// オブジェクトの種類によって座標と切り取り範囲を変化させる
	switch (a_type)
	{
	case Spaccekey:
		m_bsst.pos = { -465,-210 };
		m_bsst.draw.rct = { BIT108 * 0, 0, BIT108, BIT40 };
		break;
	case Dkey:
		m_bsst.pos = { 580, -300 };
		m_bsst.draw.rct = { BIT32 * 1, 0, BIT32, BIT40 };

		m_bsst2.pos = { -350, -300 };
		m_bsst2.draw.rct = { BIT32 * 1, 0, BIT32, BIT40 };
		break;
	case Akey:
		m_bsst.pos = { 530, -300 };
		m_bsst.draw.rct = { BIT32 * 0, 0, BIT32, BIT40 };

		m_bsst2.pos = { -400, -300 };
		m_bsst2.draw.rct = { BIT32 * 0, 0, BIT32, BIT40 };
		break;
	case Downkey:
		m_bsst.draw.rct = { BIT32 * 4, 0, BIT32, BIT40 };
		break;
	case Rightkey:
		m_bsst.pos = { 400, -300 };
		m_bsst.draw.rct = { BIT32 * 2, 0, BIT32, BIT40 };

		m_bsst2.pos = { -530, -300 };
		m_bsst2.draw.rct = { BIT32 * 2, 0, BIT32, BIT40 };
		break;
	case Leftkey:
		m_bsst.pos = { 350, -300 };
		m_bsst.draw.rct = { BIT32 * 3, 0, BIT32, BIT40 };

		m_bsst2.pos = { -580, -300 };
		m_bsst2.draw.rct = { BIT32 * 3, 0, BIT32, BIT40 };
		break;
	}


	m_bsst.mov      = { 0,0 };
	m_bsst.scl      = { m_baseScl,m_baseScl };
	m_bsst.rot      = 0;
	m_bsst.alive    = true;
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);

	m_bsst2.mov = { 0,0 };
	m_bsst2.scl = { m_baseScl,m_baseScl };
	m_bsst2.rot = 0;
	m_bsst2.alive = true;
	m_bsst2.draw.clr = { WHITE ,1.0f };
	m_bsst2.mat = systm->CreateMat(m_bsst2.scl, m_bsst2.rot, m_bsst2.pos);
}

void C_ControlText::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player* player = m_p0wner->GetPlayer();

	// オブジェクトの種類によって描画する文字を変化させる
	switch (m_keyType)
	{
	case Spaccekey:
		SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
		if (!player->GetDrawBulletPredictionFlg())
		{
			systm->DrawStringGg({ -535 , -150 }, { 1.0f,1.0f }, L"charge");
		}
		else
		{
			systm->DrawStringGg({ -505 , -150 }, { 1.0f,1.0f }, L"shot");
		}
		systm->DrawStringGg({ -465, -260 }, { 1.0f,1.0f }, L"+");
		break;
	case Dkey:
		SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

		SHADER.m_spriteShader.SetMatrix(m_bsst2.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst2.draw.pTex, 0, 0, &m_bsst2.draw.rct, &m_bsst2.draw.clr);
		systm->DrawStringGg( { 420 , -240 }, { 1.0f,1.0f }, L"move");
		break;
	case Akey:
		SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

		SHADER.m_spriteShader.SetMatrix(m_bsst2.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst2.draw.pTex, 0, 0, &m_bsst2.draw.rct, &m_bsst2.draw.clr);
		systm->DrawStringGg({ 450 , -300 }, { 1.0f,1.0f }, L"or");
		systm->DrawStringGg({ -480 , -300 }, { 1.0f,1.0f }, L"or");
		break;
	case Downkey:
		break;
	case Rightkey:
		SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

		SHADER.m_spriteShader.SetMatrix(m_bsst2.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst2.draw.pTex, 0, 0, &m_bsst2.draw.rct, &m_bsst2.draw.clr);
		break;
	case Leftkey:
		SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

		SHADER.m_spriteShader.SetMatrix(m_bsst2.mat.compmat);
		SHADER.m_spriteShader.DrawTex(m_bsst2.draw.pTex, 0, 0, &m_bsst2.draw.rct, &m_bsst2.draw.clr);
		break;
	}
}

void C_ControlText::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;
	m_bsst2.pos += m_bsst2.mov;

	m_bsst.mov = { 0,0 };
	m_bsst2.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
	m_bsst2.mat = systm->CreateMat(m_bsst2.scl, m_bsst2.rot, m_bsst2.pos);
}

void C_ControlText::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();
	
	// キー判定により大きさや色を変更する
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

	m_bsst2.scl = { m_minScl ,m_minScl };
	m_bsst2.draw.clr.A(m_minAlpha);
}

void C_ControlText::BaseSt()
{
	m_bsst.scl = { m_baseScl ,m_baseScl };
	m_bsst.draw.clr.A(1.0f);

	m_bsst2.scl = { m_baseScl ,m_baseScl };
	m_bsst2.draw.clr.A(1.0f);
}

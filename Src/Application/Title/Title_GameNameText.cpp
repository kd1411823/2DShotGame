#include "Title_GameNameText.h"
#include "../Particle/Sun.h"
#include "../Scene/Scene.h"

C_Title_GameNameText::C_Title_GameNameText()
{
}

C_Title_GameNameText::~C_Title_GameNameText()
{
}

void C_Title_GameNameText::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	m_no = a_no; // オブジェクトナンバー

	m_rctX = BIT340 * m_no; // 切り取り座標X

	if (m_no == 0)
	{
		m_bsst.draw.clr = { GREEN ,1.0f };
	}
	else if (m_no == 1)
	{
		m_bsst.draw.clr = { RED ,1.0f };
	}

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, BIT340, BIT240 };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Title_GameNameText::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_sun->Draw();

	systm->DrawStringGg({ -100 , 150 }, { 2.7f,2.7f }, L"axis", { GREEN , 1.0f } ,0.0f,25.0f);
	systm->DrawStringGg({ -135 , 20 }, { 2.7f,2.7f }, L"break", { RED , 1.0f },0.0f,25.0f);
}

void C_Title_GameNameText::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_sun->Update(m_bsst.pos, { 8.0f,1.0f }, { m_bsst.draw.clr.R(),m_bsst.draw.clr.G(),m_bsst.draw.clr.B(), 0.65f});

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Title_GameNameText::Action()
{

	m_bsst.draw.rct = { m_rctX, 0, BIT340, BIT240 };

	m_bsst.pos.y = m_no * -130 + 150;
	
}

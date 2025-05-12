#include "Title_Text.h"
#include "Scene.h"

C_Title_Text::C_Title_Text()
{
}

C_Title_Text::~C_Title_Text()
{
}

void C_Title_Text::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_isRisingAlpha = false;	// alpha値増減フラグ
	m_deltaAlpha = 0.02f; // alpha値加算量
	m_textAlpha = 1.0f;
}

void C_Title_Text::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();
	systm->DrawStringGg({ -150 , -100 }, { 1.0f,1.0f }, L"press"	  ,{ GREEN,m_textAlpha }    );
	systm->DrawStringGg({ -150 , -100 }, { 1.0f,1.0f }, L"      enter",{ RED  ,m_textAlpha });
}

void C_Title_Text::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();
	
}

void C_Title_Text::Action()
{
	AlphaManager();
}

void C_Title_Text::AlphaManager()
{
	if (m_textAlpha >= 1.0f)
	{
		m_isRisingAlpha = false;
	}

	if (m_textAlpha <= 0.3f)
	{
		m_isRisingAlpha = true;
	}

	if (m_isRisingAlpha)
	{
		m_textAlpha += m_deltaAlpha;
	}
	else
	{
		m_textAlpha -= m_deltaAlpha;
	}
}



#pragma once
#include "GameObjectBase.h"
#include "Title_GameNameText.h"
#include "Title_Background.h"
#include "Title_BackCircle.h"

class C_TitleManager :public C_GameObject
{
public:

	C_TitleManager();
	~C_TitleManager();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void ToGame();


	C_Title_GameNameText* GetTitleGameNameText(int a_no) { return &m_title_gamenametext[a_no]; }
	C_Title_Background* GetTitleBackground() { return &m_title_background; }
	C_Title_BackCircle* GetTitleBackCircle() { return &m_title_backcircle; }

private:

	KdTexture titlegamenameTex;
	KdTexture titlebackgroundTex;
	KdTexture titlebackcircleTex;

	C_Title_GameNameText m_title_gamenametext[gameNameText];
	C_Title_Background m_title_background;
	C_Title_BackCircle m_title_backcircle;

};
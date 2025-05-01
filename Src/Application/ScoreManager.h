#pragma once
#include "GameObjectBase.h"
#include "Score_Circle.h"
#include "Score_TextString.h"
#include "Score_TextNumber.h"

class C_ScoreManager :public C_GameObject
{
public:

	C_ScoreManager();
	~C_ScoreManager();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AddScore();
	void DecreaseScore();

	C_Score_Circle* GetScoreCircle() { return &m_scorecircle; }
	C_Score_TextString* GetScoreTextString() { return &m_scoretextstring; }
	C_Score_TextNumber* GetScoreTextNumber(int a_no) { return &m_scoretextnumber[a_no]; }
	float GetScore() { return m_score; }

private:

	KdTexture scoretextnumberTex;

	C_Score_Circle m_scorecircle;
	C_Score_TextString m_scoretextstring;
	C_Score_TextNumber m_scoretextnumber[scoreDigits];

	float m_score; // ÉXÉRÉA

};


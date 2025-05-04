#pragma once
#include "GameObjectBase.h"
#include "Score_Circle.h"
#include "Score_TextString.h"
#include "Score_TextNumber.h"
#include "Score_DrawNumber.h"
#include "Score_TextSymbol.h"
#include "Score_Result.h"

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
	C_Score_DrawNumber* GetScoreDrawNumber(int a_no) { return &m_scoredrawnumber[a_no]; }
	C_Score_TextSymbol* GetScoreTextSymbol() { return &m_scoretextsymbol; }
	C_Score_Result* GetScoreResult() { return &m_scoreresult; }
	float GetScore() { return m_score; }

private:

	KdTexture scoretextnumberTex;

	C_Score_Circle m_scorecircle;
	C_Score_TextString m_scoretextstring;
	C_Score_TextNumber m_scoretextnumber[scoreDigits];
	C_Score_DrawNumber m_scoredrawnumber[scoreDrawDigits];
	C_Score_TextSymbol m_scoretextsymbol;
	C_Score_Result m_scoreresult;

	float m_score; // ÉXÉRÉA

};


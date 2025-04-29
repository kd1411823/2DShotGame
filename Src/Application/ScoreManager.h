#pragma once
#include "GameObjectBase.h"
#include "Score_Circle.h"
#include "Score_TextString.h"

class C_ScoreManager :public C_GameObject
{
public:

	C_ScoreManager(){}
	~C_ScoreManager(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AddScore();
	void DecreaseScore();

	C_Score_Circle* GetScoreCircle() { return &m_scorecircle; }
	C_Score_TextString* GetScoreTextString() { return &m_scoretextstring; }
	float GetScore() { return m_score; }

private:

	C_Score_Circle m_scorecircle;
	C_Score_TextString m_scoretextstring;
	

	float m_score; // ÉXÉRÉA

};


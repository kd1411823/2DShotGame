#pragma once
#include "GameObjectBase.h"

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


private:

	int m_score; // ÉXÉRÉA

};


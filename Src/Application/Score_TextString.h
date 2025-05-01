#pragma once
#include "GameObjectBase.h"

class C_Score_TextString :public C_GameObject
{
public:

	C_Score_TextString();
	~C_Score_TextString();


	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	
	void SetScoreTextScl(float a_scoreTextScl) { m_scoreTextScl = a_scoreTextScl; }

private:

	KdTexture scoretextstringTex;

	float m_scoreTextScl; // ƒXƒRƒA•¶Žš—ñ‚ÌŠg‘å—¦
};


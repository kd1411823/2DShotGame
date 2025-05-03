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
	
	

	void SetScl(Math::Vector2 a_scl) { m_bsst.scl = a_scl; }
	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }
	void SetScoreTextScl(float a_scoreTextScl) { m_scoreTextScl = a_scoreTextScl; }

	Math::Vector2 GetScl() { return m_bsst.scl; }


private:

	KdTexture scoretextstringTex;

	float m_scoreTextScl; // ƒXƒRƒA•¶Žš—ñ‚ÌŠg‘å—¦
};


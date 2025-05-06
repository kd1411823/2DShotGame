#pragma once
#include "GameObjectBase.h"

class C_GameStart_Number :public C_GameObject
{
public:

	C_GameStart_Number();
	~C_GameStart_Number();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void ScaleManger();
	void AddAlpha();

private:

	KdTexture startTex;

	int m_digitsNumber; // Œ…”š
	int m_rctX; // Ø‚èæ‚èÀ•WX
	float m_deltaScale;// Šg‘å—¦‘Œ¸—Ê
	float m_baseScale; // Œ³‚ÌŠg‘å—¦
	float m_maxScale;// Å‘åŠg‘å—¦
	float m_deltaAlpha; // alpha’l‘Œ¸—Ê
};
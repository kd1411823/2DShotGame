#pragma once
#include "../GameSystem/GameObjectBase.h"

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


	int m_digitsNumber; // 
	int m_rctX; // ΨθζθΐWX
	float m_deltaScale;// gε¦ΈΚ
	float m_baseScale; // ³Μgε¦
	float m_maxScale;// Εεgε¦
	float m_deltaAlpha; // alphalΈΚ
};
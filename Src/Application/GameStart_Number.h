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

	int m_digitsNumber; // ������
	int m_rctX; // �؂�����WX
	float m_deltaScale;// �g�嗦������
	float m_baseScale; // ���̊g�嗦
	float m_maxScale;// �ő�g�嗦
	float m_deltaAlpha; // alpha�l������
};
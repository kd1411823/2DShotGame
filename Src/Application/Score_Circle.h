#pragma once
#include "GameObjectBase.h"

class C_Score_Circle :public C_GameObject
{
public:

	C_Score_Circle();
	~C_Score_Circle();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action(int a_score);

	void SetTargetScore(float a_targetScore) { m_targetScore = a_targetScore; }
	void SetGetScore(float a_getScore) { m_getScore = a_getScore; }
	void SetLoadBulletFlg(bool a_loadBulletFlg) { m_loadBulletFlg = a_loadBulletFlg; }

	float GetTargetScore() { return m_targetScore; }
	bool  GetLoadBulletFlg() { return m_loadBulletFlg; }

private:

	KdTexture scorecircleTex;

	int m_rctY; // �摜�؂�����WY

	float m_targetScore; // ���ɖڎw���X�R�A
	float m_getScore; // �擾�X�R�A��
	bool  m_loadBulletFlg; // �e���`���[�W���Ă��邩�t���O
};


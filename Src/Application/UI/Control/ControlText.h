#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_ControlText :public C_GameObject
{
public:

	C_ControlText(){}
	~C_ControlText(){}

	void Init(eKeyType a_type);
	void Draw()override;
	void Update()override;
	void Action()override;

	// �g�嗦��������
	void MinManager();
	// ���̑傫����F�ɖ߂�
	void BaseSt();

	void SetTwoTex(KdTexture* a_ptex) { m_bsst.draw.pTex = a_ptex, m_bsst2.draw.pTex = a_ptex; }

private:

	Bsst m_bsst2;
	eKeyType m_keyType; // �L�[�^�C�v
	float m_baseScl;	// �ʏ�̊g�嗦
	float m_minScl;		// �ŏ��̊g�嗦
	float m_minAlpha;	// �ŏ���alpha�l
};
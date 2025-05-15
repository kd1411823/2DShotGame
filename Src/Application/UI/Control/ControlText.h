#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_ControlText :public C_GameObject
{
public:


	void Init(eKeyType a_type);
	void Draw()override;
	void Update()override;
	void Action()override;
	void MinManager();
	void BaseSt();

private:

	eKeyType m_keyType; // �L�[�^�C�v
	float m_baseScl;  // �ʏ�̊g�嗦
	float m_minScl; // �ŏ��̊g�嗦
	float m_minAlpha; // �ŏ���alpha�l
};
#pragma once
#include "GameObjectBase.h"
#include "StateMachine.h"

class C_Enemy :public C_GameObject
{
public:

	C_Enemy(){}
	virtual ~C_Enemy(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	float GetRadius()override { return m_enemyRadius; }

	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }

private:

	// �X�e�[�g�}�V��
	C_StateMachine<C_Enemy> m_stateMachine;

	const float m_enemyRadius = 12.0f;
	float m_deg;				// �p�x
	float m_movDeg;				// �ړ���(�p�x)
	float m_circleRadius;		// �~�̔��a
};
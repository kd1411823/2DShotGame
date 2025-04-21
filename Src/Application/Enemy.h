#pragma once
#include "GameObjectBase.h"
#include "StateMachine.h"
#include "Bullet.h"

class C_Enemy :public C_GameObject
{
public:

	C_Enemy();
	virtual ~C_Enemy();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	float GetRadius()override { return m_enemyRadius; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }

	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }



private:

	// �e�N�X�`��
	KdTexture ebulletTex;

	// �X�e�[�g�}�V��
	C_StateMachine<C_Enemy> m_stateMachine;
	// �e�C���X�^���X(�G)
	C_Bullet m_bullet[ebulletNum];

	const float m_enemyRadius = 12.0f;
	float m_deg;				// �p�x
	float m_movDeg;				// �ړ���(�p�x)
	float m_circleRadius;		// �~�̔��a
};
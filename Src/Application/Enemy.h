#pragma once
#include "GameObjectBase.h"
#include "Enemy_HPCircle.h"
#include "Enemy_Circle.h"
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

	// �G�̒e�ƃv���C���[�̉~�Ɠ����蔻��
	void EnemyBulletPlayerCircleHit();
	// �G�Ƀ_���[�W�ǉ�
	void TakeDamage();

	float GetRadius()override { return m_enemyRadius; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	float GetEBulletSpdScl() { return m_ebulletSpdScl; }

	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }


private:

	// �e�N�X�`��
	KdTexture enemyTex;
	KdTexture hpCircleTex;
	KdTexture frameCircleTex;
	KdTexture ebulletTex;

	// �X�e�[�g�}�V��
	C_StateMachine<C_Enemy> m_stateMachine;

	// �G��HP�~
	C_Enemy_HPCircle m_enemyhpCircle;

	// �G��HP�~(�t���[��)
	C_Enemy_Circle m_enemyframeCircle;

	// �e�C���X�^���X(�G)
	C_Bullet m_bullet[ebulletNum];

	const float m_enemyRadius = EnemyHpCircleScl * BIT512 * 0.5f;
	float m_enemyHitpoint;		// �G��HP
	float m_damagePoint;		// �_���[�W��
	float m_autoRecoveryRate;	// ���R�񕜗�
	float m_deg;				// �p�x
	float m_movDeg;				// �ړ���(�p�x)
	float m_circleRadius;		// �~�̔��a
	float m_ebulletSpdScl;		// �G�̒e�̃X�s�[�h�{��
};
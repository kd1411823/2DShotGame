#pragma once
#include "../GameSystem/GameObjectBase.h"
#include "Enemy_SquareParticle.h"
#include "Enemy_SquareFrame.h"
#include "Enemy_HPCircle.h"
#include "Enemy_Circle.h"
#include "../GameSystem/StateMachine.h"
#include "../Bullet/Bullet.h"

class C_Sun;

class C_Enemy :public C_GameObject
{
public:

	C_Enemy();
	~C_Enemy();

	
	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void ScaleManager();
	// �G�̒e�ƃv���C���[�̉~�Ɠ����蔻��
	void EnemyBulletPlayerCircleHit();
	// �G�Ƀ_���[�W�ǉ�
	void TakeDamage();

	// �Q�b�^�[
	float GetRadius()override { return m_enemyRadius; }
	float GetRotation() { return m_bsst.rot; }
	bool GetbMoveFlg() { return m_bMoveFlg; }
	C_Enemy_HPCircle* GetEnemyHpCircle() { return &m_enemyhpCircle; }
	C_Enemy_Circle* GetEnemyFrameCircle() { return &m_enemyframeCircle; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	C_Enemy_SquareFrame* GetEnemySquareFrame() { return &m_enemySquareFrame; }
	float GetEBulletSpdScl() { return m_ebulletSpdScl; }

	// �Z�b�^�[
	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }
	void SetbMoveFlg(float a_bMoveFlg) { m_bMoveFlg = a_bMoveFlg; }

private:

	static const int squareParticleNum = 30;
	static const int hitParticleNum = 40;

	// �e�N�X�`��
	KdTexture enemyTex;
	KdTexture hpCircleTex;
	KdTexture frameCircleTex;
	KdTexture ebulletTex;
	KdTexture squareframeTex;

	// �X�e�[�g�}�V��
	C_StateMachine<C_Enemy> m_stateMachine;

	// �G��HP�~
	C_Enemy_HPCircle m_enemyhpCircle;

	// �G��HP�~(�t���[��)
	C_Enemy_Circle m_enemyframeCircle;

	// �e�C���X�^���X(�G)
	C_Bullet m_bullet[ebulletNum];

	// �G�p�[�e�B�N��
	C_Enemy_SquareParticle m_enemysquareParticle[squareParticleNum];

	// �G�p�[�e�B�N��(HIT��)
	C_Enemy_SquareParticle m_enemyhitParticle[hitParticleNum];

	// �G�l�p�`�t���[��
	C_Enemy_SquareFrame m_enemySquareFrame;

	std::shared_ptr<C_Sun> m_sun = nullptr;

	const float m_enemyRadius = EnemyHpCircleScl * BIT512 * 0.5f;
	float m_enemyHitpoint;		// �G��HP
	float m_damagePoint;		// �_���[�W��
	float m_autoRecoveryRate;	// ���R�񕜗�
	float m_deg;				// �p�x
	float m_movDeg;				// �ړ���(�p�x)
	float m_circleRadius;		// �~�̔��a
	float m_ebulletSpdScl;		// �G�̒e�̃X�s�[�h�{��
	bool		  m_bMoveFlg;		// �����Ă��邩�t���O
	bool		  m_isRisingScl;	// �G�̂̊g�嗦�����t���O
	float         m_deltaScl;		// �G�̊g�嗦������
	float         m_maxDeltaScl;		// �ő�G�̊g�嗦
	float         m_minDeltaScl;		// �ŏ��G�̊g�嗦
	bool          m_sclInitFlg;		// �g�嗦�������t���O
};
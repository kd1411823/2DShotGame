#pragma once
#include "GameObjectBase.h"
#include "Player_TriangleParticle.h"
#include "Player_BulletPredictionLine.h"
#include "Player_BulletPredictionTriangle.h"
#include "Player_AfterImage.h"
#include "Bullet.h"
#include "Drop_Bullet.h"
#include "StateMachine.h"

class C_Sun;

class C_Player :public C_GameObject
{
public:

	C_Player();
	~C_Player();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void ScaleManager();
	void Mouse();
	void LoadBullet();

	// �Z�b�^�[
	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }
	void SetbMoveFlg(bool a_bMoveFlg) { m_bMoveFlg = a_bMoveFlg; }
	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }
	void SetPlayerSpeed(float a_playerSpeed) { m_playerSpeed = a_playerSpeed; }
	void SetCircleRadius(float a_circleRadius) { m_circleRadius = a_circleRadius; }
	void SetDrawBulletPredictionFlg(bool a_drawBulletPredictionFlg) { m_drawBulletPredictionFlg = a_drawBulletPredictionFlg; }
	void SetDropHitCount(int a_dropHitCount) { m_dropHitCount = a_dropHitCount; }
	void SetAfterImageTimer(int a_afterImageTimer) { m_afterImageTimer = a_afterImageTimer; }

	// �Q�b�^�[
	Math::Vector2 GetPos()override { return m_bsst.pos; }
	Math::Vector2 GetMov() { return m_bsst.mov; }
	Math::Vector2 GetScl() { return m_bsst.scl; }
	float GetRot() { return m_bsst.rot; }
	float GetRadius()override { return m_playerRadius; }
	float GetPlayerSpeed() { return m_playerSpeed; }
	float GetCircleRadius() { return m_circleRadius; }
	bool  GetDrawBulletPredictionFlg() { return m_drawBulletPredictionFlg; }
	int   GetDropHitCount() { return m_dropHitCount; }
	int   GetAfterImageTimer() { return m_afterImageTimer; }
	C_Bullet* GetBullet(int a_no) { return &m_bullet[a_no]; }
	C_Drop_Bullet* GetDropBullet(int a_no) { return &m_drop_bullet[a_no]; }
	C_Player_BulletPredictionLine* GetPlayerBulletPredictionLine(int a_no) { return &m_player_bulletpredictionline[a_no]; }
	C_Player_BulletPredictionTriangle* GetPlayerBulletPredictionTriangle() { return &m_player_bulletpredictiontriangle; }
	C_Player_AfterImage* GetPlayerAfterImage(int a_no) { return &m_player_afterimage[a_no]; }
	std::shared_ptr<C_Sun> GetSun() { return m_sun; }

private:

	static const int triangleParticleNum = 10;

	KdTexture playerTex;
	KdTexture bulletTex;
	KdTexture dropbulletTex;
	KdTexture triangleTex;
	KdTexture bulletpredictionlineTex;
	KdTexture bulletpredictionTriTex;

	// �X�e�[�g�}�V��
	C_StateMachine<C_Player> m_stateMachine;

	// �e�̃C���X�^���X���쐬
	C_Bullet m_bullet[BulletNum];
	C_Drop_Bullet m_drop_bullet[DropBulletNum];
	C_Player_BulletPredictionLine m_player_bulletpredictionline[pBulletLineNum];
	C_Player_BulletPredictionTriangle m_player_bulletpredictiontriangle;

	// �v���C���[�̎O�p�`�p�[�e�B�N��
	C_Player_TriangleParticle m_player_triangleParticle[triangleParticleNum];

	C_Player_AfterImage m_player_afterimage[afterImageNum];

	std::shared_ptr<C_Sun> m_sun = nullptr;

	POINT		  m_pMousePos;		// POINT�^�}�E�X���W
	Math::Vector2 m_vMousePos;		// vector2�^�}�E�X���W
	bool		  m_bMoveFlg;		// �����Ă��邩�t���O
	float		  m_deg;			// �p�x
	float         m_movDeg;			// �v���C���[�̈ړ���(deg)
	float		  m_playerRadius;	// �v���C���[�̔��a
	float		  m_playerSpeed;	// �v���C���[�̃X�s�[�h
	float		  m_circleRadius;	// �v���C���[�~�̔��a
	bool		  m_drawBulletPredictionFlg;  // �v���C���[�̒e�\���`��t���O
	bool		  m_isRisingScl;	// �v���C���[�̊g�嗦�����t���O
	float         m_deltaScl;		// �v���C���[�̊g�嗦������
	float         m_maxDeltaScl;		// �ő�v���C���[�̊g�嗦
	float         m_minDeltaScl;		// �ŏ��v���C���[�̊g�嗦
	bool          m_sclInitFlg;		// �g�嗦�������t���O
	int           m_dropHitCount;// �e�����������Ă���J�E���g(���������J�E���g)
	int           m_afterImageTimer; // �c���^�C�}�[
};

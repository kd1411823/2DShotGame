#pragma once
#include "../GameSystem/GameObjectBase.h"
#include "Player_TriangleParticle.h"
#include "Player_BulletPredictionLine.h"
#include "Player_BulletPredictionTriangle.h"
#include "Player_AfterImage.h"
#include "../Bullet/Bullet.h"
#include "../Bullet/Drop_Bullet.h"
#include "../GameSystem/StateMachine.h"

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

	// セッター
	void SetClr(Math::Color a_clr) { m_bsst.draw.clr = a_clr; }
	void SetbMoveFlg(bool a_bMoveFlg) { m_bMoveFlg = a_bMoveFlg; }
	void SetMovDeg(float a_movDeg) { m_movDeg = a_movDeg; }
	void SetPlayerSpeed(float a_playerSpeed) { m_playerSpeed = a_playerSpeed; }
	void SetCircleRadius(float a_circleRadius) { m_circleRadius = a_circleRadius; }
	void SetDrawBulletPredictionFlg(bool a_drawBulletPredictionFlg) { m_drawBulletPredictionFlg = a_drawBulletPredictionFlg; }
	void SetDropHitCount(int a_dropHitCount) { m_dropHitCount = a_dropHitCount; }
	void SetAfterImageTimer(int a_afterImageTimer) { m_afterImageTimer = a_afterImageTimer; }

	// ゲッター
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

	// ステートマシン
	C_StateMachine<C_Player> m_stateMachine;

	// 弾のインスタンスを作成
	C_Bullet m_bullet[BulletNum];
	C_Drop_Bullet m_drop_bullet[DropBulletNum];
	C_Player_BulletPredictionLine m_player_bulletpredictionline[pBulletLineNum];
	C_Player_BulletPredictionTriangle m_player_bulletpredictiontriangle;

	// プレイヤーの三角形パーティクル
	C_Player_TriangleParticle m_player_triangleParticle[triangleParticleNum];

	C_Player_AfterImage m_player_afterimage[afterImageNum];

	std::shared_ptr<C_Sun> m_sun = nullptr;

	POINT		  m_pMousePos;		// POINT型マウス座標
	Math::Vector2 m_vMousePos;		// vector2型マウス座標
	bool		  m_bMoveFlg;		// 動いているかフラグ
	float		  m_deg;			// 角度
	float         m_movDeg;			// プレイヤーの移動量(deg)
	float		  m_playerRadius;	// プレイヤーの半径
	float		  m_playerSpeed;	// プレイヤーのスピード
	float		  m_circleRadius;	// プレイヤー円の半径
	bool		  m_drawBulletPredictionFlg;  // プレイヤーの弾予測描画フラグ
	bool		  m_isRisingScl;	// プレイヤーの拡大率増減フラグ
	float         m_deltaScl;		// プレイヤーの拡大率増減量
	float         m_maxDeltaScl;		// 最大プレイヤーの拡大率
	float         m_minDeltaScl;		// 最小プレイヤーの拡大率
	bool          m_sclInitFlg;		// 拡大率初期化フラグ
	int           m_dropHitCount;// 弾をいくつ持っているカウント(当たったカウント)
	int           m_afterImageTimer; // 残像タイマー
};

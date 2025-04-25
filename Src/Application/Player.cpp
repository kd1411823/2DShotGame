#include "main.h"
#include "Player.h"
#include "Scene.h"
#include "Player_StandState.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{
	bulletTex.Release();
	dropbulletTex.Release();
	triangleTex.Release();
}

void C_Player::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	// 弾画像
	bulletTex.Load("Texture/bullet.png");
	dropbulletTex.Load("Texture/dropbullet.png");
	triangleTex.Load("Texture/player.png");

	// 初期化時にインスタンスのポインタを渡す
	m_stateMachine.Start(this);

	// 初期状態のステートをセット
	m_stateMachine.ChangeState<C_Player_StandState>();

	for (int i = 0;i < triangleParticleNum; i++)
	{
		m_player_triangleParticle[i].SetTex(&triangleTex);
		m_player_triangleParticle[i].Init();
	}
	// 弾
	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Init();
		m_bullet[i].SetTex(&bulletTex);
	}

	// 弾(取得オブジェクト)
	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Init(i);
		m_drop_bullet[i].SetTex(&dropbulletTex);
	}

	// メンバ変数
	m_pMousePos = systm->GetMousePos(m_pMousePos);					// POINT型マウス座標
	m_vMousePos = { (float)m_pMousePos.x,(float)m_pMousePos.y };	// vector2型マウス座標
	m_bMoveFlg = false;												// 動いているかフラグ
	m_deg = 0;														// 角度
	m_movDeg = 0;													// プレイヤーの移動量(deg)
	m_playerRadius= 25.0f;// プレイヤーの半径
	m_playerSpeed = 2.0f;// プレイヤーのスピード
	m_circleRadius= 0.0f;// プレイヤー円の半径

	// プレイヤーのステータス
	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.15f,0.15f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = {0, 0, BIT256, BIT256 };
	m_bsst.draw.clr = GREEN;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player::Draw()
{
	for (int i = 0;i < DropBulletNum;i++)m_drop_bullet[i].Draw();

	for (int i = 0; i < BulletNum;i++)m_bullet[i].Draw();
	C_Sun* m_sun = m_p0wner->GetSun();
	m_sun->Draw();
	D3D.SetBlendState(BlendMode::Alpha);

	for (int i = 0;i < triangleParticleNum; i++)
	{
		m_player_triangleParticle[i].Draw();
	}

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Player::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Sun* m_sun = m_p0wner->GetSun();

	LoadBullet();
	
	//ScaleManager();

	m_bsst.pos += m_bsst.mov;

	m_deg += m_movDeg;

	if (m_deg < 0)m_deg += 360;

	m_bsst.mov = { 0,0 };

	m_movDeg = 0;

	m_bMoveFlg = false;

	m_stateMachine.Update();
		
	if (m_bMoveFlg)
	{
		for (int i = 0;i < triangleParticleNum; i++)
		{
			if (!m_player_triangleParticle[i].GetAlive())
			{
				m_player_triangleParticle[i].Emit(
					{ 0, 0 },
					{ 0 ,0 },
					{ 0.0f ,0.0f },
					0.0f,
					true,
					0,
					true,
					{ 0,0,0,0 },
					{ 0.0f,0.0f,0.0f,0.0f }
				);
			}
		}
	}

	
	for (int i = 0;i < triangleParticleNum; i++)
	{
		m_player_triangleParticle[i].Update(m_bsst.pos,m_bMoveFlg);
	}


	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Update();
	}

	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Update();
	}

	m_sun->Update(m_bsst.pos, { 0.6f,0.6f }, GREEN);

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();

	Mouse();

	m_bsst.rot = systm->GetDeg(initPos, m_bsst.pos) - 90.0f;

	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;

	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Action();
	}
	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Action(m_circleRadius);
	}
}

void C_Player::Animation()
{

}

void C_Player::ScaleManager()
{
	if (m_bMoveFlg)
	{
		if (m_bsst.scl.x <= 0.15f)
		{
			m_bsst.scl.x += 0.002f;
		}
		else
		{
			m_bsst.scl.x -= 0.002f;
		}

		if (m_bsst.scl.y >= 0.15f)
		{
			m_bsst.scl.y -= 0.002f;
		}
		else
		{
			m_bsst.scl.y += 0.002f;
		}

	}



	

}

void C_Player::Mouse()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_pMousePos = systm->GetMousePos(m_pMousePos);					// POINT型マウス座標
	m_vMousePos = { (float)m_pMousePos.x,(float)m_pMousePos.y };	// vector2型マウス座標
}

void C_Player::LoadBullet()
{
	for (int i = 0; i < BulletNum;i++)
	{
		for (int j = 0;j < DropBulletNum;j++)
		{
			if (i == j && !m_drop_bullet[j].GetAlive())
			{
				m_bullet[i].SetLoadOkFlg(true);
			}
		}
	}

}


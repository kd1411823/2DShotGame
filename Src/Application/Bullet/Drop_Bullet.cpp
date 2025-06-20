#include "Drop_Bullet.h"
#include "../Particle/Sun.h"
#include "../Scene/Scene.h"

void C_Drop_Bullet::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	// メンバ変数
	m_no = a_no;
	
	// オブジェクトのステータス
	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.04f,0.04f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT256, BIT256 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Drop_Bullet::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (playercircle->GetPlayerLife() == FourLife)return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Drop_Bullet::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_sun->Update(m_bsst.pos, { 0.3f,0.3f }, { GREEN ,1.0f });

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Drop_Bullet::Action(float a_circleRadius)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player* player = m_p0wner->GetPlayer();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	
	if (playercircle->GetPlayerLife() == FourLife)return;

	// 弾の間隔
	const int degDis = 360 / DropBulletNum;

	// プレイヤー円からの距離
	static const float _playerCircleDistance = 10.0f;

	// 弾(取得オブジェクト)を円状に並べる
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + _playerCircleDistance);
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + _playerCircleDistance);

	// 弾(取得オブジェクト)を取得していたらAlpha値を下げる
	if (!m_bsst.alive)m_bsst.draw.clr.A(0.0f);
	else m_bsst.draw.clr = { GREEN ,1.0f };
}

void C_Drop_Bullet::CountHIT()
{
	C_Sound* sound = m_p0wner->GetSound();
	C_Player* player = m_p0wner->GetPlayer();

	m_bsst.alive = false;

	// カウントする
	player->SetDropHitCount(player->GetDropHitCount() + 1);

	// カウントによって音を変化させる
	if (player->GetDropHitCount() >= 1 && player->GetDropHitCount() <= 3)
	{
		sound->GetOneGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 4 && player->GetDropHitCount() <= 6)
	{
		sound->GetTwoGetBulletSe().inst->Play();
	}
	else if(player->GetDropHitCount() >= 7 && player->GetDropHitCount() <= 9)
	{
		sound->GetThreeGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 10 && player->GetDropHitCount() <= 12)
	{
		sound->GetFourGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 13)
	{
		sound->GetFiveGetBulletSe().inst->Play();
	}
}

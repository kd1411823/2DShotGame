#include "Drop_Bullet.h"
#include "Sun.h"
#include "Scene.h"

void C_Drop_Bullet::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_sun = std::make_shared<C_Sun>();
	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	m_no = a_no;
	
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

	D3D.SetBlendState(BlendMode::Add);
	if (m_bsst.alive) 
	{
		m_sun->Draw();
	}
	D3D.SetBlendState(BlendMode::Alpha);

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

	// �e�̊Ԋu
	const int degDis = 360 / DropBulletNum;

	// �v���C���[�~����̋���
	static const float _playerCircleDistance = 10.0f;

	// �e(�擾�I�u�W�F�N�g)���~��ɕ��ׂ�
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + _playerCircleDistance);
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + _playerCircleDistance);

	// �e(�擾�I�u�W�F�N�g)���擾���Ă�����Alpha�l��������
	if (!m_bsst.alive)m_bsst.draw.clr.A(0.0f);
	else m_bsst.draw.clr = { GREEN ,1.0f };
	
	
}

void C_Drop_Bullet::CountHIT()
{
	C_Sound* sound = m_p0wner->GetSound();
	C_Player* player = m_p0wner->GetPlayer();

	m_bsst.alive = false;

	player->SetDropHitCount(player->GetDropHitCount() + 1);

	printf("count%d\n",player->GetDropHitCount());

	if (player->GetDropHitCount() >= 0 && player->GetDropHitCount() <= 2)
	{
		sound->GetOneGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 3 && player->GetDropHitCount() <= 4)
	{
		sound->GetTwoGetBulletSe().inst->Play();
	}
	else if(player->GetDropHitCount() >= 4 && player->GetDropHitCount() <= 5)
	{
		sound->GetThreeGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 5 && player->GetDropHitCount() <= 6)
	{
		sound->GetFourGetBulletSe().inst->Play();
	}
	else if (player->GetDropHitCount() >= 7)
	{
		sound->GetFiveGetBulletSe().inst->Play();
	}
}

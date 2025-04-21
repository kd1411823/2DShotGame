#include "Drop_Bullet.h"
#include "Scene.h"

void C_Drop_Bullet::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	//m_dropBulletRadius = 5;  // �e(�擾�I�u�W�F�N�g)�̔��a

	m_no = a_no;
	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 0.4f,0.4f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, BIT18, BIT64 };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Drop_Bullet::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Drop_Bullet::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Drop_Bullet::Action(float a_circleRadius)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player* player = m_p0wner->GetPlayer();
	
	// �e�̊Ԋu
	const int degDis = 360 / DropBulletNum;

	// �e(�擾�I�u�W�F�N�g)���~��ɕ��ׂ�
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + m_dropBulletRadius);
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_no * degDis)) * (a_circleRadius + m_dropBulletRadius);

	// �e(�擾�I�u�W�F�N�g)���擾���Ă�����Alpha�l��������
	if (!m_bsst.alive)m_bsst.draw.clr.A(0.2f);
	else m_bsst.draw.clr = WHITE;
	
}

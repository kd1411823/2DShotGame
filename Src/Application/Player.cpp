#include "main.h"
#include "Player.h"
#include "Scene.h"
#include "Player_StandState.h"
#include "Sun.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{
	playerTex.Release();
	bulletTex.Release();
	dropbulletTex.Release();
	triangleTex.Release();
	bulletpredictionlineTex.Release();
	bulletpredictionTriTex.Release();
}

void C_Player::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	// �e�摜
	playerTex.Load("Texture/player.png");
	bulletTex.Load("Texture/bullet.png");
	dropbulletTex.Load("Texture/dropbullet.png");
	triangleTex.Load("Texture/player.png");
	bulletpredictionlineTex.Load("Texture/bulletPredictionLine.png");
	bulletpredictionTriTex.Load("Texture/bulletPredictionTri.png");

	// ���������ɃC���X�^���X�̃|�C���^��n��
	m_stateMachine.Start(this);

	// ������Ԃ̃X�e�[�g���Z�b�g
	m_stateMachine.ChangeState<C_Player_StandState>();

	m_sun = std::make_shared<C_Sun>();

	m_sun->SetP0wner(m_p0wner);
	m_sun->Init();

	for (int i = 0;i < triangleParticleNum; i++)
	{
		m_player_triangleParticle[i].SetTex(&triangleTex);
		m_player_triangleParticle[i].SetP0wner(m_p0wner);
		m_player_triangleParticle[i].Init();
	}

	for (int i = 0;i < afterImageNum; i++)
	{
		m_player_afterimage[i].SetP0wner(m_p0wner);
		m_player_afterimage[i].SetTex(&playerTex);
		m_player_afterimage[i].Init();
	}

	// �e
	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].SetP0wner(m_p0wner);
		m_bullet[i].SetTex(&bulletTex);
		m_bullet[i].Init();
	}

	// �e(�擾�I�u�W�F�N�g)
	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].SetP0wner(m_p0wner);
		m_drop_bullet[i].SetTex(&dropbulletTex);
		m_drop_bullet[i].Init(i);
	}

	for (int i = 0;i < pBulletLineNum;i++)
	{
		m_player_bulletpredictionline[i].SetP0wner(m_p0wner);
		m_player_bulletpredictionline[i].SetTex(&bulletpredictionlineTex);
		m_player_bulletpredictionline[i].Init(i);
	}

	m_player_bulletpredictiontriangle.SetP0wner(m_p0wner);
	m_player_bulletpredictiontriangle.SetTex(&bulletpredictionTriTex);
	m_player_bulletpredictiontriangle.Init();

	m_bsst.draw.pTex = &playerTex;

	// �����o�ϐ�
	m_pMousePos = systm->GetMousePos(m_pMousePos);					// POINT�^�}�E�X���W
	m_vMousePos = { (float)m_pMousePos.x,(float)m_pMousePos.y };	// vector2�^�}�E�X���W
	m_bMoveFlg = false;												// �����Ă��邩�t���O
	m_deg = 0;														// �p�x
	m_movDeg = 0;													// �v���C���[�̈ړ���(deg)
	m_playerRadius= 25.0f;// �v���C���[�̔��a
	m_playerSpeed = 2.0f;// �v���C���[�̃X�s�[�h
	m_circleRadius= 0.0f;// �v���C���[�~�̔��a
	m_drawBulletPredictionFlg = false;  // �v���C���[�̒e�\���`��t���O
	m_isRisingScl = false;	// �v���C���[�̊g�嗦�����t���O
	m_deltaScl    = 0.007f;		// �v���C���[�̊g�嗦������
	m_maxDeltaScl = 0.0f;		// �ő�v���C���[�̊g�嗦
	m_minDeltaScl = 0.0f;		// �ŏ��v���C���[�̊g�嗦
	m_sclInitFlg  = false;		// �g�嗦�������t���O
	m_dropHitCount = 0;// �e�����������Ă���J�E���g(���������J�E���g)
	m_afterImageTimer = 0; // �c���^�C�}�[

	// �v���C���[�̃X�e�[�^�X
	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { PlayerBaseScl,PlayerBaseScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = {0, 0, BIT256, BIT256 };
	m_bsst.draw.clr = { GREEN ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player::Draw()
{
	C_Systm* systm = m_p0wner->GetSystm();

	//D3D.SetBlendState(BlendMode::Alpha);
	
	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Draw();
	}

	
	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Draw();
	}


	//D3D.SetBlendState(BlendMode::Add);

	//m_sun->Draw();

	

	for (int i = 0;i < afterImageNum; i++)
	{
		m_player_afterimage[i].Draw();
	}

	for (int i = 0;i < triangleParticleNum; i++)
	{
		m_player_triangleParticle[i].Draw();
	}

	
	if (m_drawBulletPredictionFlg)
	{
		systm->DrawStringGg({ -560 , -240 }, { 1.0f,1.0f }, L"shot");

		for (int i = 0;i < pBulletLineNum;i++)
		{
			m_player_bulletpredictionline[i].Draw();
		}
		m_player_bulletpredictiontriangle.Draw();
	}
	


	

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

	//D3D.SetBlendState(BlendMode::Add);

}

void C_Player::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	LoadBullet();
	
	ScaleManager();

	m_bsst.pos += m_bsst.mov;

	m_deg += m_movDeg;

	if (m_deg < 0)m_deg += 360;

	m_bsst.mov = { 0,0 };

	m_movDeg = 0;

	m_bMoveFlg = false;

	m_stateMachine.Update();

	m_sun->Update(m_bsst.pos, { 1.3f,1.3f }, { GREEN ,1.0f });
		
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

	for (int i = 0;i < afterImageNum;i++)
	{
		m_player_afterimage[i].Update(m_bsst.pos, m_bMoveFlg);
	}

	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Update();
	}

	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Update();
	}

	
	for (int i = 0;i < pBulletLineNum;i++)
	{
		m_player_bulletpredictionline[i].Update(m_bsst.pos);
	}

	m_player_bulletpredictiontriangle.Update();
	

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player::Action()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_afterImageTimer++;

	Mouse();

	m_bsst.rot = systm->GetDeg(initPos, m_bsst.pos) - 90.0f;

	m_bsst.pos.x = cos(systm->CnvrtToRadians(m_deg)) * m_circleRadius;
	m_bsst.pos.y = sin(systm->CnvrtToRadians(m_deg)) * m_circleRadius;

	for (int i = 0; i < BulletNum;i++)
	{
		m_bullet[i].Action({ 0.05f,0.13f }, { GREEN, 1.0f},{ 0, 0, BIT256, BIT256});
	}
	for (int i = 0;i < DropBulletNum;i++)
	{
		m_drop_bullet[i].Action(m_circleRadius);
	}

	
	for (int i = 0;i < pBulletLineNum;i++)
	{
		m_player_bulletpredictionline[i].Action(m_bsst.pos, m_bsst.rot, m_deg, m_circleRadius);
	}
	
	m_player_bulletpredictiontriangle.Action(m_bsst.pos, m_bsst.rot, m_deg, m_circleRadius);

}

void C_Player::ScaleManager()
{
	
	if (m_bMoveFlg)
	{
		m_maxDeltaScl = PlayerBaseScl + 0.03f;
		m_minDeltaScl = PlayerBaseScl - 0.03f;
		m_sclInitFlg = false;
	}
	else
	{
		if (!m_sclInitFlg)
		{
			m_maxDeltaScl = PlayerBaseScl + 0.01f;
			m_minDeltaScl = PlayerBaseScl - 0.01f;
			m_sclInitFlg = true;
		}
		
		if (m_maxDeltaScl > PlayerBaseScl)
		{
			m_maxDeltaScl -= 0.0008f;
		}
		else
		{
			m_maxDeltaScl = PlayerBaseScl;
		}
		
		if (m_minDeltaScl < PlayerBaseScl)
		{
			m_minDeltaScl += 0.0008f;
		}
		else
		{
			m_minDeltaScl = PlayerBaseScl;
		}
	}


	if (m_bsst.scl.x >= m_maxDeltaScl && m_bsst.scl.y <= m_minDeltaScl )
	{
		m_isRisingScl = false;
	}

	if (m_bsst.scl.x <= m_minDeltaScl && m_bsst.scl.y >= m_maxDeltaScl)
	{
		m_isRisingScl = true;
	}
		
	if (m_maxDeltaScl != PlayerBaseScl && m_minDeltaScl != PlayerBaseScl)
	{
		if (m_isRisingScl)
		{
			m_bsst.scl.x += m_deltaScl;
			m_bsst.scl.y -= m_deltaScl;
		}
		else
		{
			m_bsst.scl.x -= m_deltaScl;
			m_bsst.scl.y += m_deltaScl;
		}
	}
}

void C_Player::Mouse()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_pMousePos = systm->GetMousePos(m_pMousePos);					// POINT�^�}�E�X���W
	m_vMousePos = { (float)m_pMousePos.x,(float)m_pMousePos.y };	// vector2�^�}�E�X���W
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


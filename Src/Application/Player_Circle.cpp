#include "Player_Circle.h"
#include "Scene.h"

void C_Player_Circle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_playerLife      = OneLife; // プレイヤーのライフ
	m_playerCircleScl = OneLifescl;  // プレイヤー円の大きさ
	m_circleRadius = OneRadius;
	m_bulletPredictionLineDeleteNo = 0;//  弾予測線オブジェクトをどこのナンバー以降消すか

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_playerCircleScl,m_playerCircleScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0, 0, ScrnWid, ScrnWid };
	m_bsst.draw.clr = WHITE;
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_Circle::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);
}

void C_Player_Circle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.scl = { m_playerCircleScl,m_playerCircleScl };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_Circle::Action()
{
	C_Player* player = m_p0wner->GetPlayer();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();

	switch (m_playerLife)
	{
	case ZeroLife:
		m_playerCircleScl = ZeroLifescl;
		player->SetCircleRadius(ZeroRadius);
		m_circleRadius = ZeroRadius; 
		break;
	case OneLife:
		m_playerCircleScl = OneLifescl;
		player->SetCircleRadius(OneRadius);
		m_circleRadius = OneRadius; 
		m_bulletPredictionLineDeleteNo = 6;
		scorecircle->SetGetScore(0.0f);
		scorecircle->SetTargetScore(oneTargetScore);
		break;
	case TwoLife:
		m_playerCircleScl = TwoLifescl;
		player->SetCircleRadius(TwoRadius);
		m_circleRadius = TwoRadius; 
		m_bulletPredictionLineDeleteNo = 8;
		scorecircle->SetGetScore(oneTargetScore);
		scorecircle->SetTargetScore(twoTargetScore);
		break;
	case ThreeLife:
		m_playerCircleScl = ThreeLifescl;
		player->SetCircleRadius(ThreeRadius);
		m_circleRadius = ThreeRadius;
		m_bulletPredictionLineDeleteNo = 10;
		scorecircle->SetGetScore(twoTargetScore);
		scorecircle->SetTargetScore(threeTargetScore);
		break;
	case FourLife:
		m_playerCircleScl = FourLifescl;
		player->SetCircleRadius(FourRadius);
		//scorecircle->SetGetScore(threeTargetScore);
		m_circleRadius = FourRadius; 
		break;
	}
	
	printf("life %d\n", m_playerLife);

}



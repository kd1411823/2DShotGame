#include "Player_Circle.h"
#include "Scene.h"

void C_Player_Circle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_playerLife      = OneLife; // プレイヤーのライフ
	m_circleRadius = OneRadius;
	m_bulletPredictionLineDeleteNo = 0;//  弾予測線オブジェクトをどこのナンバー以降消すか
	m_rctX = ScrnHgt * 3;							// 切り取り座標X

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, ScrnHgt, ScrnHgt };
	m_bsst.draw.clr = { WHITE ,1.0f };
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

	m_bsst.scl = { 1.0f,1.0f };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Player_Circle::Action()
{
	C_Player* player = m_p0wner->GetPlayer();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Score_TextNumber* scoretextnumber[scoreDigits];
	for (int i = 0;i < scoreDigits;i++)
	{
		scoretextnumber[i] = scoremanager->GetScoreTextNumber(i);
	}

	m_bsst.draw.rct = { m_rctX, 0, ScrnHgt, ScrnHgt };

	switch (m_playerLife)
	{
	case OneLife:
		m_rctX = ScrnHgt * 3;
		scorecircle->SetScoreScl(OneScorescl);
		player->SetCircleRadius(OneRadius);
		m_circleRadius = OneRadius;
		scoretextstring->SetScoreTextScl(OnescoreTextScl);
		m_bulletPredictionLineDeleteNo = 8;
		scorecircle->SetGetScore(0.0f);
		scorecircle->SetTargetScore(oneTargetScore);
		break;
	case TwoLife:
		m_rctX = ScrnHgt * 2;
		scorecircle->SetScoreScl(TwoScorescl);
		player->SetCircleRadius(TwoRadius);
		m_circleRadius = TwoRadius; 
		scoretextstring->SetScoreTextScl(TwoscoreTextScl);
		m_bulletPredictionLineDeleteNo = 10;
		scorecircle->SetGetScore(oneTargetScore);
		scorecircle->SetTargetScore(twoTargetScore);
		break;
	case ThreeLife:
		m_rctX = ScrnHgt * 1;
		scorecircle->SetScoreScl(ThreeScorescl);
		player->SetCircleRadius(ThreeRadius);
		m_circleRadius = ThreeRadius;
		scoretextstring->SetScoreTextScl(ThreescoreTextScl);
		m_bulletPredictionLineDeleteNo = 12;
		scorecircle->SetGetScore(twoTargetScore);
		scorecircle->SetTargetScore(threeTargetScore);
		break;
	case FourLife:
		m_rctX = ScrnHgt * 0;
		player->SetCircleRadius(FourRadius);
		scoretextstring->SetScoreTextScl(FourscoreTextScl);
		m_circleRadius = FourRadius; 
		break;
	}
	

}



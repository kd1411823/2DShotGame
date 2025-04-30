#include "Score_Circle.h"
#include "Scene.h"

C_Score_Circle::C_Score_Circle()
{
}

C_Score_Circle::~C_Score_Circle()
{
	scorecircleTex.Release();
}

void C_Score_Circle::Init()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	m_rctY = 0; // 画像切り取り座標Y
	m_targetScore = 0; // 次に目指すスコア
	m_getScore = 0; // 取得スコア分
	m_loadBulletFlg = false; // 弾をチャージしているかフラグ
	m_scoreScl = OneScorescl; // スコアサークル拡大率

	scorecircleTex.Load("Texture/scorecircle.png");

	m_bsst.draw.pTex = &scorecircleTex;

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { m_scoreScl,m_scoreScl };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { 0,  ScrnHgt, ScrnHgt,  -m_rctY };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_Circle::Draw()
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	if (playercircle->GetPlayerLife() == FourLife)return;

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_Score_Circle::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_Circle::Action(int a_score)
{
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

	// スコアに応じて切り取り座標Yを変える
	m_rctY = ScrnHgt *  (((float)a_score - m_getScore) / (m_targetScore - m_getScore));

	// 切り取り座標Yに応じて座標をずらす
	m_bsst.pos.y = (- ScrnHgt * m_scoreScl * 0.5f) + (m_rctY * m_scoreScl * 0.5f);

	m_bsst.scl = { m_scoreScl,m_scoreScl };

	// 切り取り座標を超えないように補正
	if (m_rctY > ScrnHgt)
	{
		m_rctY = ScrnHgt;
	}

	// 切り取り座標反映
	m_bsst.draw.rct = { 0,  ScrnHgt, ScrnHgt, - m_rctY };

	if (m_loadBulletFlg)
	{
		m_bsst.draw.clr.A(0.3f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}
}

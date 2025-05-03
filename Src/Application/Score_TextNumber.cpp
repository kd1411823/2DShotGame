#include "Score_TextNumber.h"
#include "Scene.h"

C_Score_TextNumber::C_Score_TextNumber()
{

}

C_Score_TextNumber::~C_Score_TextNumber()
{

}

void C_Score_TextNumber::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();

	m_no = a_no; // オブジェクトナンバー
	m_rctX = BIT24 * 0; // 切り取り座標X
	m_numberDistance = OneNumDistance; // 数字間隔
	m_digitsNumber = 0; // 桁数字
	m_numberScl = OneNumScl; // 数字の大きさ
	m_addDrawScore = 0.0f; // スコアを加算する演出用のスコアを入れる変数
	m_addSpeed = 10.0f; // スコアを加算するスピード
	m_isRisingScl = false;	// プレイヤーの拡大率増減フラグ
	m_deltaScl = 0.1f;		// プレイヤーの拡大率増減量
	m_deltaMax = 0.4f;	// max - 基準値　
	m_deltaMin = 0.4f;	// min - 基準値　
	m_maxDeltaScl = m_numberScl + m_deltaMax;		// 最大プレイヤーの拡大率
	m_minDeltaScl = m_numberScl - m_deltaMin;		// 最小プレイヤーの拡大率
	m_addTimeScoreCount = 0; // タイム分スコア加算処理カウン
	m_resultTimeClockCirclePos = { -170 ,0 }; // リザルト時のタイム円の座標

	m_bsst.pos = { 0,0 };
	m_bsst.mov = { 0,0 };
	m_bsst.scl = { 1.0f,1.0f };
	m_bsst.rot = 0;
	m_bsst.alive = true;
	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };
	m_bsst.draw.clr = { WHITE ,1.0f };
	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextNumber::Draw()
{

	SHADER.m_spriteShader.SetMatrix(m_bsst.mat.compmat);
	SHADER.m_spriteShader.DrawTex(m_bsst.draw.pTex, 0, 0, &m_bsst.draw.rct, &m_bsst.draw.clr);

}

void C_Score_TextNumber::Update()
{
	C_Systm* systm = m_p0wner->GetSystm();


	m_bsst.pos += m_bsst.mov;

	m_bsst.mov = { 0,0 };

	m_bsst.mat = systm->CreateMat(m_bsst.scl, m_bsst.rot, m_bsst.pos);
}

void C_Score_TextNumber::Action()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	
	if (playercircle->GetPlayerLife() == FourLife)return;

	if (scorecircle->GetLoadBulletFlg())
	{
		m_bsst.draw.clr.A(0.2f);
	}
	else
	{
		m_bsst.draw.clr.A(1.0f);
	}

	
	// Noの座標の中心部分にずらす
	m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
	m_bsst.pos.y = - m_numberDistance;

	scoretextstring->SetPos({ 0, m_bsst.pos.y + m_numberDistance * 2 });

	switch (m_no)
	{
	case 0:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 1000) % 10;
		break;
	case 1:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 100) % 10;
		break;
	case 2:
		m_digitsNumber = (((int)std::floor(scoremanager->GetScore())) / 10) % 10;
		break;
	case 3:
		m_digitsNumber = ((int)std::floor(scoremanager->GetScore())) % 10;
		break;
	}


	m_bsst.scl = { m_numberScl, m_numberScl };

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

}

void C_Score_TextNumber::AddDrawScore()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	
	
	if (m_addDrawScore < scoremanager->GetScore())
	{
		m_addDrawScore += m_addSpeed;
		m_deltaScl = 0.1f;
		ScaleManager();
		scoretextstring->SetPos({ 0, m_bsst.pos.y + m_numberDistance * 2 });
		scoretextstring->SetScl(m_bsst.scl * 0.65f);
		m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
		m_bsst.pos.y = -m_numberDistance;
	}
	else
	{
		if (timemanager->GetIsTimeLeftFlg())
		{
			scoretextstring->SetScl({ FourscoreTextScl ,FourscoreTextScl});
			m_bsst.scl = { m_numberScl, m_numberScl };
			AddTimeScore();
		}
		else
		{
			m_addDrawScore = scoremanager->GetScore();
			m_bsst.draw.clr = { GREEN,1.0f };
			scoretextstring->SetClr({ GREEN,1.0f });
			m_deltaScl = 0.02f;
			m_deltaMax = 0.2f;
			m_deltaMin = 0.2f;
			ScaleManager();
			scoretextstring->SetScl(m_bsst.scl * 0.65f);
			
		}
	}

	

	switch (m_no)
	{
	case 0:
		m_digitsNumber = (((int)std::floor(m_addDrawScore))/ 1000) % 10;
		break;
	case 1:
		m_digitsNumber = (((int)std::floor(m_addDrawScore)) / 100) % 10;
		break;
	case 2:
		m_digitsNumber = (((int)std::floor(m_addDrawScore)) / 10) % 10;
		break;
	case 3:
		m_digitsNumber = ((int)std::floor(m_addDrawScore)) % 10;
		break;
	}

	m_bsst.draw.clr.A(1.0f);

	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

	
}

void C_Score_TextNumber::ScaleManager()
{

	m_maxDeltaScl = m_numberScl + m_deltaMax;		// 最大プレイヤーの拡大率
	m_minDeltaScl = m_numberScl - m_deltaMin;		// 最小プレイヤーの拡大率

	if (m_bsst.scl.x >= m_maxDeltaScl && m_bsst.scl.y >= m_maxDeltaScl)
	{
		m_isRisingScl = false;
	}

	if (m_bsst.scl.x <= m_minDeltaScl && m_bsst.scl.y <= m_minDeltaScl)
	{
		m_isRisingScl = true;
	}

	if (m_isRisingScl)
	{
		m_bsst.scl.x += m_deltaScl;
		m_bsst.scl.y += m_deltaScl;
	}
	else
	{
		m_bsst.scl.x -= m_deltaScl;
		m_bsst.scl.y -= m_deltaScl;
	}

}

void C_Score_TextNumber::AddTimeScore()
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Time_ClockCircle* timeclockcircle = timemanager->GetTimeClockCircle();

	m_addTimeScoreCount++;

	
	if (m_addTimeScoreCount >= 60 && m_addTimeScoreCount < 120)
	{
		if (m_bsst.pos.y > -160)
		{
			m_bsst.mov.y = -4.0f;
		}
		if (scoretextstring->GetPos().y < 160)
		{
			scoretextstring->SetMovY(4.0f);
		}
	}
	else if (m_addTimeScoreCount > 121 && m_addTimeScoreCount < 300)
	{
		const float _deg = systm->GetDeg(m_resultTimeClockCirclePos, timeclockcircle->GetPos());
		const float _moveSpeed = 10.0f;

		if (timeclockcircle->GetPos().x > m_resultTimeClockCirclePos.x && 
			timeclockcircle->GetPos().y > m_resultTimeClockCirclePos.y)
		{
			timeclockcircle->SetMov({ cos(systm->CnvrtToRadians(_deg)) * _moveSpeed,
									  sin(systm->CnvrtToRadians(_deg)) * _moveSpeed });
		}
		
	}
	printf("cnt %d\n", m_addTimeScoreCount);
}






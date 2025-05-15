#include "Score_TextNumber.h"
#include "../../Scene/Scene.h"

C_Score_TextNumber::C_Score_TextNumber()
{

}

C_Score_TextNumber::~C_Score_TextNumber()
{

}

void C_Score_TextNumber::Init(int a_no)
{
	C_Systm* systm = m_p0wner->GetSystm();
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();

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
	m_resultTimeClockCirclePos = { -190 ,0 }; // リザルト時のタイム円の座標
	m_drawMaxScore = false; // 最大スコア到達フラグ
	m_preScore = scoremanager->GetScore(); // 前のスコア情報を保存する変数
	m_preLife = playercircle->GetPlayerLife(); // 前のライフレベルを保存する変数
	m_scaleCap = 1.5f; // Max拡大率

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
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Result* scoreresult = scoremanager->GetScoreResult();

	if (scoreresult->GetTextDrawFlg())return;

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

	if (m_preLife != playercircle->GetPlayerLife())
	{
		m_bsst.scl = { m_numberScl * m_scaleCap, m_numberScl * m_scaleCap };
	}

	m_preLife = playercircle->GetPlayerLife();

	if (m_preScore != scoremanager->GetScore())
	{
		m_bsst.scl = { m_numberScl * m_scaleCap, m_numberScl * m_scaleCap };
	}

	m_preScore = scoremanager->GetScore();

	if (scorecircle->GetLoadBulletFlg())
	{
		m_bsst.draw.clr.A(0.4f);
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


	m_rctX = BIT24 * m_digitsNumber;

	m_bsst.draw.rct = { m_rctX, 0, BIT24 , BIT24 };

	DecreaseScale();
}

void C_Score_TextNumber::AddDrawScore()
{
	C_ScoreManager* scoremanager = m_p0wner->GetScoreManager();
	C_Score_Circle* scorecircle = scoremanager->GetScoreCircle();
	C_Score_TextString* scoretextstring = scoremanager->GetScoreTextString();
	C_Score_Result* scoreresult = scoremanager->GetScoreResult();
	C_TimeManager* timemanager = m_p0wner->GetTimeManager();
	C_Player_Circle* playercircle = m_p0wner->GetPlayer_Circle();
	C_Sound* sound = m_p0wner->GetSound();

	// スコア加算演出
	if (m_addDrawScore < scoremanager->GetScore())
	{
		if (scoremanager->GetScore() >= 1000)
		{
			m_addSpeed = 10.0f;
		}
		else
		{
			m_addSpeed = 3.0f;
		}
		m_addDrawScore += m_addSpeed;
		sound->GetAddScoreSe().inst->Play();
		m_deltaScl = 0.1f;
		m_deltaMax = 0.4f;
		m_deltaMin = 0.4f;
		ScaleManager();
		scoretextstring->SetPos({ 0, m_bsst.pos.y + m_numberDistance * 2 });
		scoretextstring->SetScl(m_bsst.scl * 0.65f);
		m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
		m_bsst.pos.y = - m_numberDistance;
	}
	else // 加算し終わったらタイムが残っているか判別する
	{
		// タイムが残っていたらスコア加算する
		if (timemanager->GetIsTimeLeftFlg())
		{	
			AddTimeScore();
		}
		else 
		{
			m_bsst.pos.x = (m_no * m_numberDistance) - (((m_numberDistance * 2) + (m_numberDistance * 1)) * 0.5f);
			m_bsst.pos.y = -m_numberDistance;
			m_addDrawScore = scoremanager->GetScore();
			m_bsst.draw.clr = { GREEN,1.0f };
			scoretextstring->SetClr({ GREEN,1.0f });
			m_deltaScl = 0.02f;
			m_deltaMax = 0.2f;
			m_deltaMin = 0.2f;
			ScaleManager();
			scoretextstring->SetScl(m_bsst.scl * 0.65f);
			scoreresult->ToTitle();
			printf("%.2f\n", m_numberScl);
		}
	}

	
	if (!m_drawMaxScore)
	{
		switch (m_no)
		{
		case 0:
			m_digitsNumber = (((int)std::floor(m_addDrawScore)) / 1000) % 10;
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
	}
	else
	{
		m_digitsNumber = 9;
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

void C_Score_TextNumber::DecreaseScale()
{
	if (m_bsst.scl.x > m_numberScl)
	{
		m_bsst.scl.x -= m_deltaScl;
	}

	if (m_bsst.scl.y > m_numberScl)
	{
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
	C_Time_ClockNumber* timeclocknumber[timeDigits];
	for (int i = 0;i < timeDigits;i++)
	{
		timeclocknumber[i] = timemanager->GetTimeClockNumber(i);
	}
	C_Score_DrawNumber* scoredrawnumber[scoreDrawDigits];
	for (int i = 0; i < scoreDrawDigits;i++)
	{
		scoredrawnumber[i] = scoremanager->GetScoreDrawNumber(i);
	}
	C_Score_TextSymbol* scoretextsymbol = scoremanager->GetScoreTextSymbol();
	C_Score_Result* scoreresult = scoremanager->GetScoreResult();
	C_Sound* sound = m_p0wner->GetSound();


	if (m_addDrawScore < INT_MAX)
	{
		m_addTimeScoreCount++;
	}

	if (m_addTimeScoreCount < 30)
	{
		m_addDrawScore = scoremanager->GetScore();
	}
	
	if (m_addTimeScoreCount >= 60 && m_addTimeScoreCount < 120)
	{
		scoretextstring->SetScl({ FourscoreTextScl ,FourscoreTextScl });
		m_bsst.scl = { m_numberScl, m_numberScl };
		if (m_bsst.pos.y > -160)
		{
			m_bsst.mov.y = -4.0f;
		}
		if (scoretextstring->GetPos().y < 160)
		{
			scoretextstring->SetMovY(4.0f);
		}
	}
	else if (m_addTimeScoreCount > 121 && m_addTimeScoreCount < 240)
	{
		const float _deg = systm->GetDeg(m_resultTimeClockCirclePos, timeclockcircle->GetPos());
		const float _moveSpeed = 10.0f;

		scoretextstring->SetScl({ FourscoreTextScl ,FourscoreTextScl });
		m_bsst.scl = { m_numberScl, m_numberScl };

		if (timeclockcircle->GetPos().x > m_resultTimeClockCirclePos.x && 
			timeclockcircle->GetPos().y > m_resultTimeClockCirclePos.y)
		{
			timeclockcircle->SetMov({ cos(systm->CnvrtToRadians(_deg)) * _moveSpeed,
									  sin(systm->CnvrtToRadians(_deg)) * _moveSpeed });
		}
		else
		{
			scoretextsymbol->AddAlpha();
			for (int i = 0; i < scoreDrawDigits;i++)
			{
				scoredrawnumber[i]->AddAlpha();
			}
		}
		
	}
	else if (m_addTimeScoreCount > 241)
	{
		if (scoremanager->GetScore() + (timemanager->GetTimer() * timeScore) > m_addDrawScore)
		{
			m_addDrawScore += m_addSpeed;
			sound->GetAddScoreSe().inst->Play();
			if (m_addDrawScore >= 9999)
			{
				m_drawMaxScore = true;
			}
			m_deltaScl = 0.1f;
			m_deltaMax = 0.4f;
			m_deltaMin = 0.4f;
			ScaleManager();
		}
		else
		{
			m_addDrawScore = scoremanager->GetScore() + (timemanager->GetTimer() * timeScore);
			m_bsst.draw.clr = { GREEN,1.0f };
			scoretextstring->SetClr({ GREEN,1.0f });
			m_deltaScl = 0.02f;
			m_deltaMax = 0.2f;
			m_deltaMin = 0.2f;
			ScaleManager();
			scoretextstring->SetScl(m_bsst.scl * 0.65f);
			scoretextsymbol->DecreaseAlpha();
			for (int i = 0; i < scoreDrawDigits;i++)
			{
				scoredrawnumber[i]->DecreaseAlpha();
			}
			timeclockcircle->DecreaseAlpha();
			for (int i = 0;i < timeDigits;i++)
			{
				timeclocknumber[i]->DecreaseAlpha();
			}
			if (timeclockcircle->GetAlpha() <= 0.0f)
			{
				if (m_bsst.pos.y < - m_numberDistance)
				{
					m_bsst.mov.y = 4.0f;
				}
				if (scoretextstring->GetPos().y > m_bsst.pos.y + m_numberDistance * 2)
				{
					scoretextstring->SetMovY(-4.0f);
				}

				if(m_bsst.pos.y >= -m_numberDistance && scoretextstring->GetPos().y <= m_bsst.pos.y + m_numberDistance * 2)
				{ 
					scoreresult->ToTitle();
				}
			}

		}
		

	}
}






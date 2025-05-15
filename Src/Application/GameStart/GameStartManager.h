#pragma once
#include "../GameSystem/GameObjectBase.h"
#include "GameStart_Number.h"
#include "../UI/Control/ControlText.h"

class C_GameStartManager :public C_GameObject
{
public:

	C_GameStartManager();
	~C_GameStartManager();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void StartGameCount();
	void TutorialSkip();
	void AlphaManager(); // alpha値処理

	void SetGameStartFlg(bool a_gameStartFlg) { m_gameStartFlg = a_gameStartFlg; }
	void SetRenderSwitchFlg(bool a_renderSwitchFlg) { m_renderSwitchFlg = a_renderSwitchFlg; }

	C_GameStart_Number* GetGameStartNumber() { return &m_gamestart_number; }

	bool GetGameStartFlg() { return m_gameStartFlg; }
	float GetStartCountFrame() { return m_startCountFrame; }
	int  GetStartCountTime() { return m_startCountTime; }
	bool GetStartCountFlg() { return m_startCountFlg; }
	bool GetRenderSwitchFlg() { return m_renderSwitchFlg; }

private:

	KdTexture gamestartnumberTex;
	KdTexture gamestartstringTex;
	KdTexture keyTex;
	KdTexture spaceTex;


	C_GameStart_Number m_gamestart_number;

	C_ControlText m_control_key[KeyNum];

	bool m_gameStartFlg; // ゲームスタートフラグ
	int m_startCountFrame; // スタートまでのカウントフレーム
	int m_startCountTime; // スタートまでのタイマー
	bool m_startCountFlg; // スタートカウントを開始するフラグ
	bool m_addAlphaFlg; // alpha値を上げるか？フラグ
	bool m_decreaseAlphaFlg; // alpha値を下げているフラグ
	bool  m_isRisingAlpha;	// alpha値増減フラグ
	float m_deltaAlpha;		// alpha値増減量
	float m_stringAlpha; // 文字のalpha値
	bool  m_renderSwitchFlg;// レンダーターゲット切り替え
};
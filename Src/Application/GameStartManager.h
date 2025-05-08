#pragma once
#include "GameObjectBase.h"
#include "GameStart_Number.h"
#include "ControlText.h"

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

	void SetGameStartFlg(bool a_gameStartFlg) { m_gameStartFlg = a_gameStartFlg; }
	
	C_GameStart_Number* GetGameStartNumber() { return &m_gamestart_number; }

	bool GetGameStartFlg() { return m_gameStartFlg; }
	int  GetStartCountTime() { return m_startCountTime; }
	bool GetStartCountFlg() { return m_startCountFlg; }

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

};
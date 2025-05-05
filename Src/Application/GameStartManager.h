#pragma once
#include "GameObjectBase.h"

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

	bool GetGameStartFlg() { return m_gameStartFlg; }

private:

	bool m_gameStartFlg; // ゲームスタートフラグ
	int m_startCount; // スタートまでのカウント
	bool m_addAlphaFlg; // alpha値を上げるか？フラグ
	bool m_decreaseAlphaFlg; // alpha値を下げているフラグ
};
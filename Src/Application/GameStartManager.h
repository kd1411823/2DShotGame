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

	bool m_gameStartFlg; // �Q�[���X�^�[�g�t���O
	int m_startCount; // �X�^�[�g�܂ł̃J�E���g
	bool m_addAlphaFlg; // alpha�l���グ�邩�H�t���O
	bool m_decreaseAlphaFlg; // alpha�l�������Ă���t���O
};
#pragma once
#include "GameObjectBase.h"
#include "GameStart_Number.h"

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

	C_GameStart_Number m_gamestart_number;


	bool m_gameStartFlg; // �Q�[���X�^�[�g�t���O
	int m_startCountFrame; // �X�^�[�g�܂ł̃J�E���g�t���[��
	int m_startCountTime; // �X�^�[�g�܂ł̃^�C�}�[
	bool m_startCountFlg; // �X�^�[�g�J�E���g���J�n����t���O
	bool m_addAlphaFlg; // alpha�l���グ�邩�H�t���O
	bool m_decreaseAlphaFlg; // alpha�l�������Ă���t���O
};
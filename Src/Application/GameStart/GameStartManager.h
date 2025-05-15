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
	void AlphaManager(); // alpha�l����

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

	bool m_gameStartFlg; // �Q�[���X�^�[�g�t���O
	int m_startCountFrame; // �X�^�[�g�܂ł̃J�E���g�t���[��
	int m_startCountTime; // �X�^�[�g�܂ł̃^�C�}�[
	bool m_startCountFlg; // �X�^�[�g�J�E���g���J�n����t���O
	bool m_addAlphaFlg; // alpha�l���グ�邩�H�t���O
	bool m_decreaseAlphaFlg; // alpha�l�������Ă���t���O
	bool  m_isRisingAlpha;	// alpha�l�����t���O
	float m_deltaAlpha;		// alpha�l������
	float m_stringAlpha; // ������alpha�l
	bool  m_renderSwitchFlg;// �����_�[�^�[�Q�b�g�؂�ւ�
};
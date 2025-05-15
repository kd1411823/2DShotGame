#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Player_Circle :public C_GameObject
{
public:

	C_Player_Circle(){}
	~C_Player_Circle(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void SetPlayerLife(ePlayerLife a_playerLife) { m_playerLife = a_playerLife; }
	void SetRenderSwitchFlg(bool a_renderSwitchFlg) { m_renderSwitchFlg = a_renderSwitchFlg; }


	ePlayerLife GetPlayerLife() { return m_playerLife; }
	float GetCircleRadius() { return m_circleRadius; }
	int   GetBulletPredictionLineDeleteNo() { return m_bulletPredictionLineDeleteNo; }
	bool  GetRenderSwitchFlg() { return m_renderSwitchFlg; }

private:

	ePlayerLife m_playerLife; // �v���C���[�̃��C�t
	float m_circleRadius; // ���a
	int   m_bulletPredictionLineDeleteNo;// �e�\�����I�u�W�F�N�g���ǂ��̃i���o�[�ȍ~������
	int   m_rctX;        // �؂�����WX
	bool  m_renderSwitchFlg; // �����_�[�^�[�Q�b�g�؂�ւ��t���O
};
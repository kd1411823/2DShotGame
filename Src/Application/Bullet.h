#pragma once
#include "GameObjectBase.h"

class C_Bullet :public C_GameObject
{
public:

	C_Bullet(){}
	virtual ~C_Bullet(){}

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;

	void ShotBullet(Math::Vector2 a_pos,float a_deg,float a_spdScl = 1.0f);
	void IsEndPoint();

	// �Q�b�^�[
	Math::Vector2 GetPos()override { return m_bsst.pos; }
	bool GetAlive()override { return m_bsst.alive; }
	float GetRadius()override { return m_bulletRadius; }
	bool GetLoadOkFlg() { return m_loadOkFlg; }


	// �Z�b�^�[
	void SetLoadOkFlg(bool a_loadOkFlg) { m_loadOkFlg = a_loadOkFlg; }

private:

	const float m_bulletRadius = 12.0f; // �e�̔��a
	const float m_bulletSpd = 35.0f;	// �e�̃X�s�[�h
	bool m_loadOkFlg;	// ���U�t���O
};

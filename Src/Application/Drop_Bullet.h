#pragma once
#include "GameObjectBase.h"

class C_Drop_Bullet :public C_GameObject
{
public:

	C_Drop_Bullet(){}
	~C_Drop_Bullet(){}

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action(float a_circleRadius);

	Math::Vector2 GetPos()override { return m_bsst.pos; }
	bool GetAlive()override { return m_bsst.alive; }
	const float GetDropBulletRadius(){ return m_dropBulletRadius; }

private:

	int		m_no; // �e�̔ԍ�(No.)
 	const float   m_dropBulletRadius = 10;  // �e(�擾�I�u�W�F�N�g)�̔��a
};
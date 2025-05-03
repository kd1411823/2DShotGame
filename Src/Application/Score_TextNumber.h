#pragma once
#include "GameObjectBase.h"

class C_Score_TextNumber :public C_GameObject
{
public:

	C_Score_TextNumber();
	~C_Score_TextNumber();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;

	void SetNumberDistance(float a_numberDistance) { m_numberDistance = a_numberDistance; }
	void SetNumberScl(float a_numberScl) { m_numberScl = a_numberScl; }

	float GetNumberDistance() { return m_numberDistance; }
	float GetNumberScl() { return m_numberScl; }

private:
	
	int m_no; // オブジェクトナンバー
	int m_rctX; // 切り取り座標X
	float m_numberDistance; // 数字間隔
	int m_digitsNumber; // 桁数字
	float m_numberScl; // 数字の大きさ
};


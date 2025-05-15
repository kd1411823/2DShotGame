#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_GameStart_StringText :public C_GameObject
{
public:

	C_GameStart_StringText();
	~C_GameStart_StringText();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha値処理


private:

	int m_no; // オブジェクトナンバー
	int m_rctX; // 切り取り座標X
	int m_rctWidX; // 切り取り量X
	bool  m_isRisingAlpha;	// alpha値増減フラグ
	float m_deltaAlpha;		// alpha値増減量
};
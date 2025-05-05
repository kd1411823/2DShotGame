#pragma once
#include "GameObjectBase.h"

class C_Title_GameNameText :public C_GameObject
{
public:

	C_Title_GameNameText();
	~C_Title_GameNameText();

	void Init(int a_no);
	void Draw()override;
	void Update()override;
	void Action()override;

private:

	int m_no; // オブジェクトナンバー
	int m_rctX; // 切り取り座標X
};
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

	int m_no; // �I�u�W�F�N�g�i���o�[
	int m_rctX; // �؂�����WX
};
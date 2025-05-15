#pragma once
#include "../GameSystem/GameObjectBase.h"

class C_Title_Text :public C_GameObject
{
public:

	C_Title_Text();
	~C_Title_Text();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void AlphaManager(); // alpha値処理

private:

	bool  m_isRisingAlpha;	// alpha値増減フラグ
	float m_deltaAlpha;		// alpha値増減量
	float m_textAlpha;		// textalpha値
};
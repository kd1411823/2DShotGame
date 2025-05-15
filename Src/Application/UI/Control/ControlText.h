#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_ControlText :public C_GameObject
{
public:


	void Init(eKeyType a_type);
	void Draw()override;
	void Update()override;
	void Action()override;
	void MinManager();
	void BaseSt();

private:

	eKeyType m_keyType; // キータイプ
	float m_baseScl;  // 通常の拡大率
	float m_minScl; // 最小の拡大率
	float m_minAlpha; // 最小のalpha値
};
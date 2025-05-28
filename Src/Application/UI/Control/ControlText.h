#pragma once
#include "../../GameSystem/GameObjectBase.h"

class C_ControlText :public C_GameObject
{
public:

	C_ControlText(){}
	~C_ControlText(){}

	void Init(eKeyType a_type);
	void Draw()override;
	void Update()override;
	void Action()override;

	// 拡大率を下げる
	void MinManager();
	// 元の大きさや色に戻す
	void BaseSt();

	void SetTwoTex(KdTexture* a_ptex) { m_bsst.draw.pTex = a_ptex, m_bsst2.draw.pTex = a_ptex; }

private:

	Bsst m_bsst2;
	eKeyType m_keyType; // キータイプ
	float m_baseScl;	// 通常の拡大率
	float m_minScl;		// 最小の拡大率
	float m_minAlpha;	// 最小のalpha値
};
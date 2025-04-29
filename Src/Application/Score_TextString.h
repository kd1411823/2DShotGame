#pragma once
#include "GameObjectBase.h"

class C_Sun;

class C_Score_TextString :public C_GameObject
{
public:

	C_Score_TextString();
	~C_Score_TextString();


	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	

private:

	KdTexture scoretextstringTex;

	std::shared_ptr<C_Sun> m_sun = nullptr;
};


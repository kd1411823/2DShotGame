#pragma once
#include"Systm.h"

class Scene;

class C_GameObject
{
public:

	C_GameObject():m_p0wner(nullptr){}
	virtual ~C_GameObject(){}


	virtual void Init(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Action(){}
	virtual void Animation(){}

	void SetP0wner(Scene* a_p0wner) { m_p0wner = a_p0wner; }
	void SetTex(KdTexture* a_pTex) { m_bsst.draw.pTex = a_pTex; }

	Scene* GetPowner() { return m_p0wner; }
	virtual Math::Vector2 GetPos() { return m_bsst.pos; }
	virtual bool GetAlive() { return m_bsst.alive; }
	virtual float GetRadius() { return 24.0f; }

	void SetAlive(bool a_alive) { m_bsst.alive = a_alive; }
	void Hit() { m_bsst.alive = false; }

protected:

	Scene* m_p0wner;

	Bsst m_bsst;

};